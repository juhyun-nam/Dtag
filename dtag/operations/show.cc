/// \file show.cc
/// \brief show operation
/// \author juhyun-nam

#include "dtag/operations/show.h"

#include "dtag/tag_manager.h"

namespace dtag {
namespace op {

Show::Show(AuxType aux) : aux_(aux) {}
std::string Show::Process(const arg_t&) {
  auto& tm = TagManager::GetInstance();
  return tm.GetTag();
}

}  // namespace op
}  // namespace dtag
