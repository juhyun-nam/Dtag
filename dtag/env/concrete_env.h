/// \file concrete_env.h
/// \brief enviroment concrete class
/// \author juhyun-nam

#ifndef DTAG_ENV_CONCRETE_ENV_H_
#define DTAG_ENV_CONCRETE_ENV_H_

#include <string>  // for string

#include "dtag/env/enviroment.h"

namespace dtag {
namespace env {

class ConcreteEnv : public Enviroment {
 public:
  ConcreteEnv() = default;
  virtual ~ConcreteEnv() = default;

  const std::string& TagReadFile() const override { return kTagReadFile; }
  const std::string& TagWriteFile() const override { return kTagWriteFile; }
  const std::string& RecentFile() const override { return kRecentFile; }
  const std::string& CurrentDirectory() const override { return kCurrentDir; }

  void OverwriteTagFile() const override;

  static const std::string kTagReadFile;
  static const std::string kTagWriteFile;
  static const std::string kRecentFile;
  static const std::string kCurrentDir;
};

}  // namespace env
}  // namespace dtag

#endif  // DTAG_ENV_CONCRETE_ENV_H_
