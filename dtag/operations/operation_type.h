/// \file operation_type.h
/// \brief operation type
/// \author juhyun-nam

#ifndef DTAG_OPERATIONS_OPERATION_TYPE_H_
#define DTAG_OPERATIONS_OPERATION_TYPE_H_

namespace dtag {
namespace op {

enum class OperationType {
  kNONE,
  kADD,
  kCLEAR,
  kHELP,
  kSEARCH,
  kSHOW,
  kREMOVE
};

}  // namespace op
}  // namespace dtag

#endif  // DTAG_OPERATIONS_OPERATION_TYPE_H_
