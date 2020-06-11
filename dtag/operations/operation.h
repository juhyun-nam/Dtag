/// \file operation.h
/// \brief operation interface
/// \author juhyun-nam

#ifndef DTAG_OPERATIONS_OPERATION_H_
#define DTAG_OPERATIONS_OPERATION_H_

#include <string>

namespace dtag {
namespace op {

class Operation {
 public:
  Operation() = default;
  virtual ~Operation() = default;
  virtual void Process(const std::string&) = 0;
};

}  // namespace op
}  // namespace dtag
#endif  // DTAG_OPERATIONS_OPERATION_H_
