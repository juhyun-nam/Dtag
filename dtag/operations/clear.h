/// \file clear.h
/// \brief clear operation
/// \author juhyun-nam

#ifndef DTAG_OPERATIONS_CLEAR_H_
#define DTAG_OPERATIONS_CLEAR_H_

#include <string>

#include "dtag/operations/operation.h"

namespace dtag {
namespace op {

class Clear : public Operation {
 public:
  Clear() = default;
  std::string Process(const arg_t&) override;
};
}  // namespace op
}  // namespace dtag

#endif  // DTAG_OPERATIONS_CLEAR_H_