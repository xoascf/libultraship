#ifndef DarwinSpeechSynthesizer_h
#define DarwinSpeechSynthesizer_h

#include "speechsynthesizer/SpeechSynthesizer.h"
#include <string>

namespace LUS {
class DarwinSpeechSynthesizer : public SpeechSynthesizer {
  public:
    DarwinSpeechSynthesizer();

    void Speak(const char* text, const char* language);
    void Speak(std::string text, const char* language);

  protected:
    bool DoInit(void);
    void DoUninitialize(void);

  private:
    void* mSynthesizer;
};
} // namespace LUS

#endif /* DarwinSpeechSynthesizer_h */
