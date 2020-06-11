/// \file parser.cc
/// \brief main's option argument parser
/// \author juhyun-nam

#include "dtag/option/parser.h"

#include <cstring>  // for strcmp
#include <string>   // for string

#include "dtag/operations/type.h"  // for OperationType, kHELP, kADD, kCLEAR
#include "dtag/option/aux_type.h"  // for AuxType

namespace dtag {
namespace option {

Argument Parse(int argc, char** argv) {
  using op::AuxType;

  op::Type op{};
  AuxType aux{};
  std::string input{};

  if (1 == argc) {
    op = op::Type::kHELP;
    return Argument{op, aux, input};
  }
  auto arg = argv[1];
  if (0 == std::strcmp(arg, "show")) {
    op = op::Type::kSHOW;
  } else if (0 == std::strcmp(arg, "clear")) {
    op = op::Type::kCLEAR;
  } else if (0 == std::strcmp(arg, "remove")) {
    op = op::Type::kREMOVE;
  } else if (0 == std::strcmp(arg, "recent")) {
    op = op::Type::kRECENT;
  } else if (0 == std::strcmp(arg, "add")) {
    op = op::Type::kADD;
  } else if (0 == std::strcmp(arg, "search")) {
    op = op::Type::kSEARCH;
    if (3 != argc)
      op = op::Type::kHELP;
  } else {
    op = op::Type::kHELP;
    return Argument{op, aux, input};
  }

  if (3 <= argc) {
    input = argv[2];
  }

  return Argument{op, aux, input};
}  // namespace option

}  // namespace option
}  // namespace dtag
