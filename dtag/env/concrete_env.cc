/// \file concrete_env.cc
/// \brief enviroment concrete class
/// \author juhyun-nam

#include "dtag/env/concrete_env.h"

#include <unistd.h>  // for get_current_dir_name

#include <cstdio>     // for rename
#include <cstdlib>    // for getenv
#include <stdexcept>  // for runtime_error

namespace dtag {
namespace env {

const std::string ConcreteEnv::kTagReadFile =
    std::string(std::getenv("HOME")) + "/.local/share/dtag/tag";

const std::string ConcreteEnv::kTagWriteFile =
    std::string(std::getenv("HOME")) + "/.local/share/dtag/tag.swp";

const std::string ConcreteEnv::kRecentFile =
    std::string(std::getenv("HOME")) + "/.local/share/dtag/recent";

const std::string ConcreteEnv::kCurrentDir =
    std::string(get_current_dir_name());

void ConcreteEnv::OverwriteTagFile() const {
  if (std::rename(TagWriteFile().data(), TagReadFile().data())) {
    throw std::runtime_error("CAN NOT RENAME TAG FILE");
  }
}

}  // namespace env
}  // namespace dtag