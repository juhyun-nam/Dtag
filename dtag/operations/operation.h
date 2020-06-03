/// \file operation.h
/// \brief operation interface
/// \author juhyun-nam

#ifndef DTAG_OPERATIONS_OPERATION_H_
#define DTAG_OPERATIONS_OPERATION_H_

#include <string>
#include <vector>

namespace dtag {
namespace op {

class Operation {
 public:
  Operation() = default;
  virtual ~Operation() = default;
  using arg_t = std::vector<std::string>;
  virtual std::string Process(const arg_t&) = 0;
};

}  // namespace op
}  // namespace dtag

#endif  // DTAG_OPERATIONS_OPERATION_H_
