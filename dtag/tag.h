/// \file tag.h
/// \brief tag struct
/// \author juhyun-nam

#ifndef DTAG_TAG_H_
#define DTAG_TAG_H_

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <string>

namespace dtag {

struct Tag {
  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) {
    ar& path;
    ar& tag;
  }
  std::string path;
  std::string tag;
};

}  // namespace dtag

#endif  // DTAG_ENV_H_
