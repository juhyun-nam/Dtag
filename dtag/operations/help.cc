/// \file help.cc
/// \brief help operation
/// \author juhyun-nam

#include "dtag/operations/help.h"

namespace dtag {
namespace op {

const std::string Help::kHelpText = "This is help text";
std::string Help::Process(const arg_t&) {
  return kHelpText;
}

}  // namespace op
}  // namespace dtag
