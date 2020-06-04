/// \file tag_manager.cc
/// \brief tag manager
/// \author juhyun-nam

#include "dtag/tag_manager.h"

#include <cstring>
#include <fstream>
#include <iostream>

#include "dtag/env.h"
#include "dtag/tag.h"

namespace dtag {

TagManager::TagManager() : ifs_(Env::TagFile()) {
  if (!ifs_) {
    throw "CAN NOT OPEN TAG FILE";
  }
}
void TagManager::ShowTag(const std::string&) {
  auto path = Env::CurrentDirectory();
  auto len = path.length();
  char c[Env::kMaxLineLength];
  bool found = false;

  while (ifs_.getline(c, Env::kMaxLineLength, '\n')) {
    if (0 == strncmp(path.data(), c, len)) {
      found = true;
      break;
    }
  }
  assert(found);
  if (strlen(c) < len + 1) {
    return;
  }
  std::cout << c + (len + 1) << std::endl;
}
void TagManager::AddTag(const std::string& path) {}

}  // namespace dtag
