/// \file tag_manager.h
/// \brief tag manager
/// \author juhyun-nam

#ifndef DTAG_TAG_MANAGER_H_
#define DTAG_TAG_MANAGER_H_

#include <cassert>
#include <fstream>
#include <string>

#include "dtag/env.h"
#include "dtag/tag.h"

namespace dtag {

class TagManager {
 public:
  TagManager();

  void None(const std::string& path) { assert(false); }
  void ShowTag(const std::string&);
  void AddTag(const std::string&);

 private:
  std::ifstream ifs_;
  // boost::archive::text_oarchive oa_;
  // boost::archive::text_iarchive ia_;
};

}  // namespace dtag

#endif  // DTAG_TAG_MANAGER_H_
