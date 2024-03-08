#include "speechsynthesizer/SpeechLogger.h"
#include "libultraship/libultraship.h"

#include "spdlog/spdlog.h"

namespace LUS {
SpeechLogger::SpeechLogger() {
}

void SpeechLogger::Speak(const char* text, const char* language) {
    lusprintf(__FILE__, __LINE__, 2, "Spoken Text (%s): %s", language, text);
}

void SpeechLogger::Speak(std::string text, const char* language) {
    SPDLOG_INFO("Spoken Text ({}): {}", language, text);
}

bool SpeechLogger::DoInit() {
    return true;
}

void SpeechLogger::DoUninitialize() {
}

} // namespace LUS
