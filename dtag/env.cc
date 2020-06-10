/// \file env.h
/// \brief enviroment
/// \author juhyun-nam

#include "dtag/env.h"

#include <unistd.h>  // for get_current_dir_name

#include <cstdio>     // for rename
#include <cstdlib>    // for getenv
#include <stdexcept>  // for runtime_error

namespace dtag {
const std::string Env::kTagFile =
    std::string(std::getenv("HOME")) + "/.local/share/dtag/tag";
const std::string Env::kTagTempFile =
    std::string(std::getenv("HOME")) + "/.local/share/dtag/tag.swp";
const std::string Env::kRecentFile =
    std::string(std::getenv("HOME")) + "/.local/share/dtag/recent";
const std::string Env::kCurrentDir = std::string(get_current_dir_name());
void Env::OverwriteTagFile() {
  if (std::rename(TagTempFile().data(), TagFile().data())) {
    throw std::runtime_error("CAN NOT RENAME TAG FILE");
  }
}

}  // namespace dtag