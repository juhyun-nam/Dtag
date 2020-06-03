/// \file tag_manager.cc
/// \brief tag manager
/// \author juhyun-nam

#include "dtag/tag_manager.h"

#include <fstream>
#include <iostream>

#include "dtag/env.h"
#include "dtag/tag.h"

namespace dtag {

TagManager& TagManager::GetInstance() {
  static TagManager instance{};
  return instance;
}
std::string TagManager::GetTag() {
  Tag tag;
  fs_ >> tag.tag;
  return tag.tag;
}
std::string GetTag(std::string path) {}
TagManager::TagManager()
    : fs_(Env::TagFilePath(), std::ios::binary | std::ios::trunc | std::ios::in | std::ios::out) {
  if (!fs_) {
    std::cout << "failed to open" << Env::TagFilePath();
  }
}

}  // namespace dtag
