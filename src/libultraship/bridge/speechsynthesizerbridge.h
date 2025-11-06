#ifndef speechsynthesizerbridge_h
#define speechsynthesizerbridge_h

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

bool SpeechSynthesizerInit(void);
void SpeechSynthesizerUninitialize(void);

void SpeechSynthesizerSpeak(const char* text, const char* language);

#ifdef __cplusplus
};
#include <string>
void SpeechSynthesizerSpeak(std::string text, const char* language);
#endif

#endif /* speechsynthesizerbridge_h */
