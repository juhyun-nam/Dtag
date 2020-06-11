/// \file help.cc
/// \brief operation help
/// \author juhyun-nam

#include "dtag/operations/help.h"

#include <iostream>

namespace dtag {
namespace op {

namespace {
constexpr char kHelpText[] = "This is Help Text";
}  // namespace

void Help::Process(const std::string&) {
  std::cout << kHelpText << std::endl;
}

}  // namespace op
}  // namespace dtag
