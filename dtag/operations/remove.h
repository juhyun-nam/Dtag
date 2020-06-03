/// \file remove.h
/// \brief remove operation
/// \author juhyun-nam

#ifndef DTAG_OPERATIONS_REMOVE_H_
#define DTAG_OPERATIONS_REMOVE_H_

#include <string>

#include "dtag/operations/operation.h"

namespace dtag {
namespace op {

class Remove : public Operation {
 public:
  Remove() = default;
  std::string Process(const arg_t&) override;
};
}  // namespace op
}  // namespace dtag

#endif  // DTAG_OPERATIONS_REMOVE_H_