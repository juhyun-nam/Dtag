/// \file add.h
/// \brief add operation
/// \author juhyun-nam

#ifndef DTAG_OPERATIONS_ADD_H_
#define DTAG_OPERATIONS_ADD_H_

#include <string>
#include "dtag/operations/operation.h"

namespace dtag {
namespace op {

class Add : public Operation {
 public:
  Add() = default;
  std::string Process(const arg_t&) override;
};
}  // namespace op
}  // namespace dtag

#endif  // DTAG_OPERATIONS_ADD_H_