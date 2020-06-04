/// \file env.h
/// \brief enviroment
/// \author juhyun-nam

#ifndef DTAG_ENV_H_
#define DTAG_ENV_H_

#include <cstdio>
#include <unistd.h>

namespace dtag {

class Env {
 public:
  Env() = default;

  static const char* TagFile() { return "tag"; }
  static const std::size_t kMaxLineLength = 128;
  static const std::string CurrentDirectory() {
    return get_current_dir_name();
  }

 private:
  char* tag_file_;
};

}  // namespace dtag

#endif  // DTAG_ENV_H_
