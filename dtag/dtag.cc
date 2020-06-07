/// \file dtag.cc
/// \brief dtag main
/// \author juhyun-nam

#include <array>
#include <cassert>
#include <iostream>
#include <string>

#include "dtag/aux_type.h"
#include "dtag/operation_type.h"
#include "dtag/operations/add.h"
#include "dtag/operations/clear.h"
#include "dtag/operations/help.h"
#include "dtag/operations/remove.h"
#include "dtag/operations/search.h"
#include "dtag/operations/show.h"
#include "dtag/option/argument.h"
#include "dtag/option/parser.h"

namespace {

using op_fn_t = void (*)(const std::string&, dtag::op::AuxType);
void None(const std::string&, dtag::op::AuxType) {
  assert(false);
}

std::array<op_fn_t, dtag::op::OperationType::kMAX> fn_array = {
    &None,           &dtag::op::Add,    &dtag::op::Clear,
    &dtag::op::Help, &dtag::op::Remove, &dtag::op::Search,
    &dtag::op::Show};

}  // namespace
int main(int argc, char** argv) {
  try {
    auto arg = dtag::option::Parse(argc, argv);
    (*(fn_array[arg.op]))(arg.input, arg.aux);
  } catch (const char* e) {
    std::cerr << e << std::endl;
    return 1;
  }
  return 0;
}
