/// \file tag_manager.h
/// \brief tag manager
/// \author juhyun-nam

#ifndef DTAG_TAG_MANAGER_H_
#define DTAG_TAG_MANAGER_H_

#include <fstream>
#include <string>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include "dtag/env.h"
#include "dtag/tag.h"

namespace dtag {

class TagManager {
 public:
  static TagManager& GetInstance();

  std::string GetTag();
  std::string GetTag(std::string path);

 private:
  TagManager();
  std::fstream fs_;
  // boost::archive::text_oarchive oa_;
  // boost::archive::text_iarchive ia_;
};

}  // namespace dtag

#endif  // DTAG_TAG_MANAGER_H_
