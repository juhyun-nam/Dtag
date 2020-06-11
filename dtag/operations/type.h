/// \file operation_type.h
/// \brief operation type
/// \author juhyun-nam

#ifndef DTAG_OPERATIONS_TYPE_H_
#define DTAG_OPERATIONS_TYPE_H_

namespace dtag {
namespace op {

enum class Type {
  kNONE,
  kADD,
  kCLEAR,
  kHELP,
  kRECENT,
  kREMOVE,
  kSEARCH,
  kSHOW,
  kMAX
};

}  // namespace op
}  // namespace dtag

#endif  // DTAG_OPERATIONS_TYPE_H_
