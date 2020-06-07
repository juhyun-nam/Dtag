/// \file env.h
/// \brief enviroment
/// \author juhyun-nam

#ifndef DTAG_ENV_H_
#define DTAG_ENV_H_

#include <unistd.h>

#include <cstdio>
#include <string>

namespace dtag {

class Env {
 public:
  Env() = default;

  static const std::string& TagFile() { return kTagFile; }
  static const std::string& TagTempFile() { return kTagTempFile; }
  static const std::string& CurrentDirectory() { return kCurrentDir; }
  static const std::string kTagFile;
  static const std::string kTagTempFile;
  static const std::string kCurrentDir;
  static const std::size_t kMaxPathLength = 128;
  static const std::size_t kMaxTagLength = 128;
  static const std::size_t kMaxLineLength = kMaxPathLength + kMaxTagLength;

 private:
  char* tag_file_;
};

}  // namespace dtag

#endif  // DTAG_ENV_H_
