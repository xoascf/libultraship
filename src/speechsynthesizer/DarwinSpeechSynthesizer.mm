#include "speechsynthesizer/DarwinSpeechSynthesizer.h"
#import <AVFoundation/AVFoundation.h>

namespace LUS {
DarwinSpeechSynthesizer::DarwinSpeechSynthesizer() {}

bool DarwinSpeechSynthesizer::DoInit() {
    mSynthesizer = (__bridge_retained void*)[[AVSpeechSynthesizer alloc] init];
    return true;
}

void DarwinSpeechSynthesizer::DoUninitialize() {
    [(__bridge AVSpeechSynthesizer *)mSynthesizer stopSpeakingAtBoundary:AVSpeechBoundaryImmediate];
    mSynthesizer = nil;
}

void DarwinSpeechSynthesizer::Speak(const char* text, const char* language) {
    AVSpeechUtterance *utterance = [AVSpeechUtterance speechUtteranceWithString:@(text)];
    [utterance setVoice:[AVSpeechSynthesisVoice voiceWithLanguage:@(language)]];

    if (@available(macOS 11.0, *)) {
        [utterance setPrefersAssistiveTechnologySettings:YES];
    }

    [(__bridge AVSpeechSynthesizer *)mSynthesizer stopSpeakingAtBoundary:AVSpeechBoundaryImmediate];
    [(__bridge AVSpeechSynthesizer *)mSynthesizer speakUtterance:utterance];
}

void DarwinSpeechSynthesizer::Speak(std::string text, const char* language) {
    AVSpeechUtterance *utterance = [AVSpeechUtterance speechUtteranceWithString:[NSString stringWithUTF8String:text.c_str()]];
    [utterance setVoice:[AVSpeechSynthesisVoice voiceWithLanguage:@(language)]];

    if (@available(macOS 11.0, *)) {
        [utterance setPrefersAssistiveTechnologySettings:YES];
    }

    [(__bridge AVSpeechSynthesizer *)mSynthesizer stopSpeakingAtBoundary:AVSpeechBoundaryImmediate];
    [(__bridge AVSpeechSynthesizer *)mSynthesizer speakUtterance:utterance];
}
}
