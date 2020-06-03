/// \file parser.cc
/// \brief main's option argument parser
/// \author juhyun-nam

#include "dtag/option/parser.h"
#include <cstring>

namespace dtag {
namespace option {

Argument Parse(int argc, char** argv) {
  using op::AuxType;
  using op::OperationType;
  if (1 == argc) {
    return Argument{OperationType::kHELP, op::AuxType::kNONE, {}};
  }
  OperationType op{};
  AuxType aux{};
  auto* arg = argv[1];
  if (0 == std::strcmp(arg, "help")) {
    op = OperationType::kHELP;
  } else if (0 == std::strcmp(arg, "show")) {
    op = OperationType::kSHOW;
  }

  return Argument{op, aux, {}};
}

}  // namespace option
}  // namespace dtag
