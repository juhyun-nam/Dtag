/// \file env.h
/// \brief enviroment interface
/// \author juhyun-nam

#ifndef DTAG_ENV_ENVIROMENT_H_
#define DTAG_ENV_ENVIROMENT_H_

#include <string>  // for string

namespace dtag {
namespace env {

class Enviroment {
 public:
  Enviroment() = default;
  virtual ~Enviroment() = default;

  virtual const std::string& TagReadFile() const = 0;
  virtual const std::string& TagWriteFile() const = 0;
  virtual const std::string& RecentFile() const = 0;
  virtual const std::string& CurrentDirectory() const = 0;
  virtual void OverwriteTagFile() const = 0;
};

}  // namespace env
}  // namespace dtag

#endif  // DTAG_ENV_ENVIROMENT_H_
