/// \file show.cc
/// \brief show operation
/// \author juhyun-nam

#include "dtag/operations/show.h"

namespace dtag {
namespace op {

Show::Show(AuxType aux) : aux_(aux) {}
std::string Show::Process(const arg_t&) {
  return "tag1 tag2";
}

}  // namespace op
}  // namespace dtag
