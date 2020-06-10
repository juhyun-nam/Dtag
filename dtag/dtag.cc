/// \file dtag.cc
/// \brief dtag main
/// \author juhyun-nam

#include <array>      // for array
#include <cassert>    // for assert
#include <cstdlib>    // for exit, EXIT_FAILURE
#include <iostream>   // for operator<<, endl, basic_ostream
#include <stdexcept>  // for exception
#include <string>     // for string

#include "dtag/aux_type.h"           // for AuxType
#include "dtag/operation_type.h"     // for OperationType, kMAX
#include "dtag/operations/add.h"     // for Add
#include "dtag/operations/clear.h"   // for Clear
#include "dtag/operations/help.h"    // for Help
#include "dtag/operations/recent.h"  // for Recent
#include "dtag/operations/remove.h"  // for Remove
#include "dtag/operations/search.h"  // for Search
#include "dtag/operations/show.h"    // for Show
#include "dtag/option/argument.h"    // for Argument
#include "dtag/option/parser.h"      // for Parse

namespace {

using op_fn_t = void (*)(const std::string&, dtag::op::AuxType);
void None(const std::string&, dtag::op::AuxType) {
  assert(false);
}

std::array<op_fn_t, dtag::op::OperationType::kMAX> fn_array = {
    &None,
    &dtag::op::Add,
    &dtag::op::Clear,
    &dtag::op::Help,
    &dtag::op::Recent,
    &dtag::op::Remove,
    &dtag::op::Search,
    &dtag::op::Show};

}  // namespace
int main(int argc, char** argv) {
  try {
    auto arg = dtag::option::Parse(argc, argv);
    (*(fn_array[arg.op]))(arg.input, arg.aux);
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    std::exit(EXIT_FAILURE);
  }
  return 0;
}
