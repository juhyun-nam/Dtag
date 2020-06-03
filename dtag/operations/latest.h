/// \file latest.h
/// \brief latest operation
/// \author juhyun-nam

#ifndef DTAG_OPERATIONS_LATEST_H_
#define DTAG_OPERATIONS_LATEST_H_

#include <string>

#include "dtag/operations/operation.h"

namespace dtag {
namespace op {

class Latest : public Operation {
 public:
  Latest() = default;
  std::string Process(const arg_t&) override;
  static const std::string kHelpText;
};
}  // namespace op
}  // namespace dtag

#endif  // DTAG_OPERATIONS_LATEST_H_