/// \file search.h
/// \brief search operation
/// \author juhyun-nam

#ifndef DTAG_OPERATIONS_SEARCH_H_
#define DTAG_OPERATIONS_SEARCH_H_

#include <string>
#include "dtag/operations/operation.h"

namespace dtag {
namespace op {

class Search : public Operation {
 public:
  Search() = default;
  std::string Process(const arg_t&) override;
};
}  // namespace op
}  // namespace dtag

#endif  // DTAG_OPERATIONS_SEARCH_H_