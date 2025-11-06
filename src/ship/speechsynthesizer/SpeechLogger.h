#ifndef SpeechLogger_h
#define SpeechLogger_h

#include "ship/speechsynthesizer/SpeechSynthesizer.h"

namespace Ship {
class SpeechLogger : public SpeechSynthesizer {
  public:
    SpeechLogger();

    void Speak(const char* text, const char* language);
    void Speak(std::string text, const char* language);

  protected:
    bool DoInit(void);
    void DoUninitialize(void);
};
} // namespace Ship

#endif /* SpeechLogger_h */
