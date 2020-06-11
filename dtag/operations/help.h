/// \file help.h
/// \brief operation help
/// \author juhyun-nam

#ifndef DTAG_TAG_OPERATIONS_HELP_H_
#define DTAG_TAG_OPERATIONS_HELP_H_

#include <string>

#include "dtag/operations/operation.h"

namespace dtag {
namespace op {

class Help : public Operation {
 public:
  Help() = default;
  virtual ~Help() = default;

  void Process(const std::string&) override;
};

}  // namespace op
}  // namespace dtag
#endif  // DTAG_TAG_OPERATIONS_HELP_H_
