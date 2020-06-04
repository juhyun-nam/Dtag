/// \file argument.h
/// \brief argument
/// \author juhyun-nam

#ifndef DTAG_ARGUMENT_OPERATION_H_
#define DTAG_ARGUMENT_OPERATION_H_

#include <string>
#include <vector>

#include "dtag/aux_type.h"
#include "dtag/operation_type.h"

namespace dtag {
namespace option {

struct Argument {
  op::OperationType op;
  op::AuxType aux;
  std::string input;
};

}  // namespace option
}  // namespace dtag
#endif  // DTAG_ARGUMENT_OPERATION_H_
