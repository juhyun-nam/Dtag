/// \file dtag.cc
/// \brief dtag main
/// \author juhyun-nam

#include <cstdio>     // for perror
#include <cstdlib>    // for exit, EXIT_FAILURE
#include <memory>     // for unique_ptr
#include <stdexcept>  // for exception

#include "dtag/env/concrete_env.h"      // for ConcreteEnv
#include "dtag/operations/factory.h"    // for Factory
#include "dtag/operations/operation.h"  // for Operation
#include "dtag/option/argument.h"       // for Argument
#include "dtag/option/parser.h"         // for Parse

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
