#include "public/bridge/speechsynthesizerbridge.h"
#include "Context.h"
#include "speechsynthesizer/SpeechSynthesizer.h"

extern "C" {

bool SpeechSynthesizerInit(void) {
    auto speechSynthesizer = Ship::Context::GetInstance()->GetSpeechSynthesizer();
    if (speechSynthesizer == nullptr) {
        return false;
    }

    if (speechSynthesizer->Init()) {
        return true;
    }

    return false;
}

void SpeechSynthesizerUninitialize(void) {
    auto speechSynthesizer = Ship::Context::GetInstance()->GetSpeechSynthesizer();
    if (speechSynthesizer == nullptr) {
        return;
    }

    speechSynthesizer->Uninitialize();
}

void SpeechSynthesizerSpeak(const char* text, const char* language) {
    auto speechSynthesizer = Ship::Context::GetInstance()->GetSpeechSynthesizer();
    if (speechSynthesizer == nullptr) {
        return;
    }

    speechSynthesizer->Speak(text, language);
}
}

void SpeechSynthesizerSpeak(std::string text, const char* language) {
    auto speechSynthesizer = Ship::Context::GetInstance()->GetSpeechSynthesizer();
    if (speechSynthesizer == nullptr) {
        return;
    }

    speechSynthesizer->Speak(text, language);
}
