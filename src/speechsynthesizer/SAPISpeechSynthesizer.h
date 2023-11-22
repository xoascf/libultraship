#ifndef SAPISpeechSynthesizer_h
#define SAPISpeechSynthesizer_h

#include "speechsynthesizer/SpeechSynthesizer.h"
#include <stdio.h>
#include <string>

namespace LUS {
class SAPISpeechSynthesizer : public SpeechSynthesizer {
  public:
    SAPISpeechSynthesizer();

    void Speak(const char* text, const char* language);
    void Speak(std::string text, const char* language);

  protected:
    bool DoInit(void);
    void DoUninitialize(void);
};
} // namespace LUS

#endif /* SAPISpeechSynthesizer_h */
