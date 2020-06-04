/// \file help.cc
/// \brief operation help
/// \author juhyun-nam

#include "dtag/operations/help.h"

#include <iostream>

namespace dtag {
namespace op {

namespace {
constexpr char kHelpText[] = "This is Help Text";
}
void Help(const std::string&, AuxType) { std::cout << kHelpText << std::endl; }
}  // namespace op
}  // namespace dtag
