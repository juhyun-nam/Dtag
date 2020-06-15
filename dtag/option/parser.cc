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

  if (argc == 1) {
    op = op::Type::kHELP;
    return Argument{op, aux, input};
  }
  auto arg = argv[1];
  if (std::strcmp(arg, "show") == 0) {
    op = op::Type::kSHOW;
  } else if (std::strcmp(arg, "clear") == 0) {
    op = op::Type::kCLEAR;
  } else if (std::strcmp(arg, "remove") == 0) {
    op = op::Type::kREMOVE;
  } else if (std::strcmp(arg, "recent") == 0) {
    op = op::Type::kRECENT;
  } else if (std::strcmp(arg, "add") == 0) {
    op = op::Type::kADD;
  } else if (std::strcmp(arg, "search") == 0) {
    op = op::Type::kSEARCH;
    if (argc != 3)
      op = op::Type::kHELP;
  } else {
    op = op::Type::kHELP;
    return Argument{op, aux, input};
  }

  if (argc >= 3) {
    input = argv[2];
  }

  return Argument{op, aux, input};
}  // namespace option

}  // namespace option
}  // namespace dtag
