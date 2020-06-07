/// \file env.h
/// \brief enviroment
/// \author juhyun-nam

#include "dtag/env.h"

#include <cstdlib>

namespace dtag {
const std::string Env::kTagFile =
    std::string(std::getenv("HOME")) + "/.local/share/dtag/tag";
const std::string Env::kTagTempFile =
    std::string(std::getenv("HOME")) + "/.local/share/dtag/tag.swp";
const std::string Env::kCurrentDir = std::string(get_current_dir_name());

}  // namespace dtag