#include "speechsynthesizer/SAPISpeechSynthesizer.h"
#include <sapi.h>
#include <thread>
#include <string>
#include <spdlog/fmt/fmt.h>
#include <atlbase.h>
#include <atlconv.h>

ISpVoice* mVoice = NULL;

namespace LUS {
SAPISpeechSynthesizer::SAPISpeechSynthesizer() {
}

bool SAPISpeechSynthesizer::DoInit() {
    CoInitializeEx(NULL, COINIT_MULTITHREADED);
    HRESULT CoInitializeEx(LPVOID pvReserved, DWORD dwCoInit);
    CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void**)&mVoice);
    return true;
}

void SAPISpeechSynthesizer::DoUninitialize() {
    mVoice->Release();
    mVoice = NULL;
    CoUninitialize();
}

std::string GetSpeak(const std::string& text, const char* language) {
    return fmt::format(
        "<speak version='1.0' xmlns='http://www.w3.org/2001/10/synthesis' xml:lang='{}'>{}</speak>", language, text);
}

void Speak(LPCWSTR wtext) {
    mVoice->Speak(wtext, SPF_IS_XML | SPF_ASYNC | SPF_PURGEBEFORESPEAK, NULL);
}

void SpeakThreadTask(const char* text, const char* language) {
    std::string speak = GetSpeak(text, language);
    const char* cstr = speak.c_str();
    const int w = 512;
    int* wp = const_cast<int*>(&w);
    *wp = strlen(cstr);
    wchar_t wtext[w];
    mbstowcs(wtext, cstr, strlen(cstr) + 1);
    Speak(wtext);
}

void SpeakStrThreadTask(std::string text, const char* language) {
    std::string speak = GetSpeak(text, language);
    ATL::CA2W pszWide(speak.c_str(), CP_UTF8);
    Speak(pszWide);
}

void SAPISpeechSynthesizer::Speak(const char* text, const char* language) {
    std::thread t1(SpeakThreadTask, text, language);
    t1.detach();
}

void SAPISpeechSynthesizer::Speak(std::string text, const char* language) {
    std::thread t2(SpeakStrThreadTask, text, language);
    t2.detach();
}
} // namespace LUS
