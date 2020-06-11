/// \file dtag.cc
/// \brief dtag main
/// \author juhyun-nam

#include <cassert>    // for assert
#include <cstdlib>    // for exit, EXIT_FAILURE
#include <iostream>   // for operator<<, endl, basic_ostream
#include <stdexcept>  // for exception
#include <string>     // for string

#include "dtag/env/concrete_env.h"
#include "dtag/operations/factory.h"
#include "dtag/option/argument.h"  // for Argument
#include "dtag/option/parser.h"    // for Parse

int main(int argc, char** argv) {
  try {
    auto arg = dtag::option::Parse(argc, argv);

    dtag::env::ConcreteEnv env;
    dtag::op::Factory factory(env);
    auto op = factory.MakeOperation(arg.op);
    op->Process(arg.input);

  } catch (const std::exception& e) {
    std::perror(e.what());
    std::exit(EXIT_FAILURE);
  }
  return 0;
}
