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

NSString* GetSpeak(const std::string& text, const char* language) {
    NSString *nsText = [[NSString alloc] initWithBytes:text.c_str() length:text.length() encoding:NSUTF8StringEncoding];
    return [NSString stringWithFormat:@"<speak version='1.0' xmlns='http://www.w3.org/2001/10/synthesis' xml:lang='%s'>%@</speak>", language, nsText];
}

void DarwinSpeechSynthesizer::Speak(std::string text, const char* language) {
    if (@available(macOS 13.0, *)) {
        AVSpeechUtterance *utterance = [AVSpeechUtterance speechUtteranceWithSSMLRepresentation:GetSpeak(text, language)];
        [utterance setVoice:[AVSpeechSynthesisVoice voiceWithLanguage:@(language)]];

        if (@available(macOS 11.0, *)) {
            [utterance setPrefersAssistiveTechnologySettings:YES];
        }

        [(__bridge AVSpeechSynthesizer *)mSynthesizer stopSpeakingAtBoundary:AVSpeechBoundaryImmediate];
        [(__bridge AVSpeechSynthesizer *)mSynthesizer speakUtterance:utterance];
    }
}
}