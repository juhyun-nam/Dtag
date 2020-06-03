/// \file help.h
/// \brief help operation
/// \author juhyun-nam

#ifndef DTAG_OPERATIONS_HELP_H_
#define DTAG_OPERATIONS_HELP_H_

#include <string>
#include "dtag/operations/operation.h"

namespace dtag {
namespace op {

class Help : public Operation {
 public:
  Help() = default;
  std::string Process(const arg_t&) override;
  static const std::string kHelpText;
};
}  // namespace op
}  // namespace dtag

#endif  // DTAG_OPERATIONS_HELP_H_