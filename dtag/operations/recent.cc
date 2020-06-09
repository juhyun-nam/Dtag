/// \file recent.cc
/// \brief operation recent
/// \author juhyun-nam

#include "dtag/operations/recent.h"

#include <fstream>
#include <iostream>
#include <string>

#include "dtag/aux_type.h"
#include "dtag/components/recent_writer.h"
#include "dtag/env.h"

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
