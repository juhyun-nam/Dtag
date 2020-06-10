/// \file parser.cc
/// \brief main's option argument parser
/// \author juhyun-nam
#include "dtag/option/parser.h"

#include <cstring>  // for strcmp
#include <string>   // for string

#include "dtag/aux_type.h"        // for AuxType
#include "dtag/operation_type.h"  // for OperationType, kHELP, kADD, kCLEAR
namespace dtag {
namespace option {

Argument Parse(int argc, char** argv) {
  using op::AuxType;
  using op::OperationType;

  OperationType op{};
  AuxType aux{};
  std::string input{};

  if (1 == argc) {
    op = OperationType::kHELP;
    return Argument{op, aux, input};
  }
  auto arg = argv[1];
  if (0 == std::strcmp(arg, "show")) {
    op = OperationType::kSHOW;
  } else if (0 == std::strcmp(arg, "clear")) {
    op = OperationType::kCLEAR;
  } else if (0 == std::strcmp(arg, "remove")) {
    op = OperationType::kREMOVE;
  } else if (0 == std::strcmp(arg, "recent")) {
    op = OperationType::kRECENT;
  } else if (0 == std::strcmp(arg, "add")) {
    op = OperationType::kADD;
  } else if (0 == std::strcmp(arg, "search")) {
    op = OperationType::kSEARCH;
    if (3 != argc)
      op = OperationType::kHELP;
  } else {
    op = OperationType::kHELP;
    return Argument{op, aux, input};
  }

  if (3 <= argc) {
    input = argv[2];
  }

  return Argument{op, aux, input};
}  // namespace option

}  // namespace option
}  // namespace dtag
