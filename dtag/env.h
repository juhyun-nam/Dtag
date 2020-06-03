/// \file env.h
/// \brief enviroment
/// \author juhyun-nam

#ifndef DTAG_ENV_H_
#define DTAG_ENV_H_

namespace dtag {

class Env {
 public:
  Env() = default;

  static const char* TagFilePath() { return ".tag"; }

 private:
  char* tag_file_;
};

}  // namespace dtag

#endif  // DTAG_ENV_H_
