#include "speechsynthesizer/SpeechSynthesizer.h"

namespace LUS {
SpeechSynthesizer::SpeechSynthesizer() : mInitialized(false){};

bool SpeechSynthesizer::Init(void) {
    if (mInitialized) {
        return true;
    }

    mInitialized = DoInit();
    return mInitialized;
}

void SpeechSynthesizer::Uninitialize(void) {
    if (!mInitialized) {
        return;
    }

    DoUninitialize();
    mInitialized = false;
}

bool SpeechSynthesizer::IsInitialized(void) {
    return mInitialized;
}

} // namespace LUS
