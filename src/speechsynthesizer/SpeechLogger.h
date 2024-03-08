#ifndef SpeechLogger_h
#define SpeechLogger_h

#include "speechsynthesizer/SpeechSynthesizer.h"

namespace LUS {
class SpeechLogger : public SpeechSynthesizer {
  public:
    SpeechLogger();

    void Speak(const char* text, const char* language);
    void Speak(std::string text, const char* language);

  protected:
    bool DoInit(void);
    void DoUninitialize(void);
};
} // namespace LUS

#endif /* SpeechLogger_h */
