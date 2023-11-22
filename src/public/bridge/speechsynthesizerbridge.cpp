#include "public/bridge/speechsynthesizerbridge.h"
#include "Context.h"
#include "window/Window.h"

extern "C" {

bool SpeechSynthesizerInit(void) {
    auto speechSynthesizer = LUS::Context::GetInstance()->GetSpeechSynthesizer();
    if (speechSynthesizer == nullptr) {
        return false;
    }

    if (speechSynthesizer->Init()) {
        return true;
    }

    return false;
}

void SpeechSynthesizerUninitialize(void) {
    auto speechSynthesizer = LUS::Context::GetInstance()->GetSpeechSynthesizer();
    if (speechSynthesizer == nullptr) {
        return;
    }

    speechSynthesizer->Uninitialize();
}

void SpeechSynthesizerSpeak(const char* text, const char* language) {
    auto speechSynthesizer = LUS::Context::GetInstance()->GetSpeechSynthesizer();
    if (speechSynthesizer == nullptr) {
        return;
    }

    speechSynthesizer->Speak(text, language);
}
}

void SpeechSynthesizerSpeak(std::string text, const char* language) {
    auto speechSynthesizer = LUS::Context::GetInstance()->GetSpeechSynthesizer();
    if (speechSynthesizer == nullptr) {
        return;
    }

    speechSynthesizer->Speak(text, language);
}
