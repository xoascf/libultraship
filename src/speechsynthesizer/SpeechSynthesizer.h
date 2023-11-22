#ifndef SpeechSynthesizer_h
#define SpeechSynthesizer_h

#include <stdio.h>
#include <string>

namespace LUS {
class SpeechSynthesizer {
  public:
    SpeechSynthesizer();

    bool Init(void);
    void Uninitialize(void);
    virtual void Speak(const char* text, const char* language) = 0;
    virtual void Speak(std::string text, const char* language) = 0;

    bool IsInitialized(void);

  protected:
    virtual bool DoInit(void) = 0;
    virtual void DoUninitialize(void) = 0;

  private:
    bool mInitialized;
};
} // namespace LUS

#endif /* SpeechSynthesizer_h */

#ifdef _WIN32
#include "speechsynthesizer/SAPISpeechSynthesizer.h"
#elif defined(__APPLE__)
#include "speechsynthesizer/DarwinSpeechSynthesizer.h"
#endif
