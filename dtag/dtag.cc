/// \file dtag.cc
/// \brief dtag main
/// \author juhyun-nam

#include <unistd.h>

#include <iostream>

#include "dtag/operations/op_factory.h"
#include "dtag/option/parser.h"

int main(int argc, char** argv) {
  auto argument = dtag::option::Parse(argc, argv);
  auto op = dtag::op::GetOperation(argument.op, argument.aux);
  std::cout << op->Process(argument.input) << std::endl;
  return 0;
}
