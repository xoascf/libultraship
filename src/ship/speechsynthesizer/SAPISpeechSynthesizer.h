#ifndef SAPISpeechSynthesizer_h
#define SAPISpeechSynthesizer_h

#include "ship/speechsynthesizer/SpeechSynthesizer.h"
#include <stdio.h>
#include <string>

namespace Ship {
class SAPISpeechSynthesizer : public SpeechSynthesizer {
  public:
    SAPISpeechSynthesizer();

    void Speak(const char* text, const char* language);
    void Speak(std::string text, const char* language);

  protected:
    bool DoInit(void);
    void DoUninitialize(void);
};
} // namespace Ship

#endif /* SAPISpeechSynthesizer_h */
