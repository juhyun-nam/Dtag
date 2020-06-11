/// \file argument.h
/// \brief argument
/// \author juhyun-nam

#ifndef DTAG_OPTION_ARGUMENT_H_
#define DTAG_OPTION_ARGUMENT_H_

#include <string>

#include "dtag/operations/type.h"
#include "dtag/option/aux_type.h"

namespace dtag {
namespace option {

struct Argument {
  op::Type op;
  op::AuxType aux;
  std::string input;
};

}  // namespace option
}  // namespace dtag
#endif  // DTAG_OPTION_ARGUMENT_H_
