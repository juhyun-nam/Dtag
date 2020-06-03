/// \file show
/// \brief show operation
/// \author juhyun-nam

#ifndef DTAG_OPERATIONS_SHOW_H_
#define DTAG_OPERATIONS_SHOW_H_

#include <string>

#include "dtag/operations/aux_type.h"
#include "dtag/operations/operation.h"

namespace dtag {
namespace op {

class Show : public Operation {
 public:
  explicit Show(AuxType aux);
  std::string Process(const arg_t&);

 private:
  AuxType aux_{};
};
}  // namespace op
}  // namespace dtag
#endif  // DTAG_OPERATIONS_SHOW_H_
