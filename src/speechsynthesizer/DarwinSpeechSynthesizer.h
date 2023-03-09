//
//  DarwinSpeechSynthesizer.h
//  libultraship
//
//  Created by David Chavez on 22.11.22.
//

#ifndef DarwinSpeechSynthesizer_h
#define DarwinSpeechSynthesizer_h

#include <string>
#include "SpeechSynthesizer.h"

namespace Ship {
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
} // namespace Ship

#endif /* DarwinSpeechSynthesizer_h */
