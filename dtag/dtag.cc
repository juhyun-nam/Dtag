/// \file dtag.cc
/// \brief dtag main
/// \author juhyun-nam

#include <unistd.h>

#include <array>
#include <string>

#include "dtag/operation_type.h"
#include "dtag/option/argument.h"
#include "dtag/option/parser.h"
#include "dtag/tag_manager.h"

namespace {
using dtag::TagManager;
std::array<void (TagManager::*)(const std::string&),
           dtag::op::OperationType::kMAX>
    fn_array = {&TagManager::None,    &TagManager::ShowTag,
                &TagManager::ShowTag, &TagManager::ShowTag,
                &TagManager::ShowTag, &TagManager::ShowTag,
                &TagManager::AddTag};
}  // namespace
int main(int argc, char** argv) {
  auto arg = dtag::option::Parse(argc, argv);
  TagManager tm{};
  (tm.*(fn_array[arg.op]))(arg.input);
  return 0;
}
