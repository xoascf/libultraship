#pragma once

//#undef _DLL

#include <string>

#include <stdint.h>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
#include <unordered_set>
#include <mutex>
#include <StormLib.h>

#include "resource/Resource.h"
#include "resource/archive/Archive.h"

namespace Ship {
struct File;

class OtrArchive : virtual public Archive {
  public:
    OtrArchive(const std::string& archivePath);
    ~OtrArchive();

    bool Open();
    bool Close();

  protected:
    std::shared_ptr<Ship::File> LoadFileRaw(const std::string& filePath);
    std::shared_ptr<Ship::File> LoadFileRaw(uint64_t hash);

  private:
    HANDLE mHandle;
};
} // namespace Ship
