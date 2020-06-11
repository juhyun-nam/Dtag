/// \file recent.cc
/// \brief operation recent
/// \author juhyun-nam

#include "dtag/operations/recent.h"

#include <fstream>
#include <iostream>   // for ifstream, endl, basic_ios, basic_ostream
#include <stdexcept>  // for runtime_error
#include <string>     // for getline, operator<<, string

#include "dtag/env/enviroment.h"  // for env::Enviroment

namespace dtag {
namespace op {

Recent::Recent(const env::Enviroment& env) : env_(env) {}

void Recent::Process(const std::string&) {
  std::ifstream ifs_(env_.RecentFile());
  if (!ifs_) {
    throw std::runtime_error("CAN NOT OPEN RECENT FILE");
  }
  std::string buf{};
  std::getline(ifs_, buf);
  if (buf.empty()) {
    throw std::runtime_error("THERE IS NO RECENT ITEM");
  }
  std::cout << buf << std::endl;
}

}  // namespace op
}  // namespace dtag
