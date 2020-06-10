/// \file recent.cc
/// \brief operation recent
/// \author juhyun-nam

#include "dtag/operations/recent.h"

#include <iostream>   // for ifstream, endl, basic_ios, basic_ostream
#include <stdexcept>  // for runtime_error
#include <string>     // for getline, operator<<, string
#include <fstream>

#include "dtag/aux_type.h"  // for AuxType
#include "dtag/env.h"       // for Env

namespace dtag {
namespace op {
void Recent(const std::string&, AuxType) {
  std::ifstream ifs_(Env::RecentFile());
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
