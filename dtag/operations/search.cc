/// \file search.cc
/// \brief operation search
/// \author juhyun-nam

#include "dtag/operations/search.h"

#include <iostream>  // for operator<<, basic_ostream, endl
#include <string>    // for operator<<, char_traits, string

#include "dtag/aux_type.h"               // for AuxType
#include "dtag/components/tag_reader.h"  // for TagReader
#include "dtag/env.h"                    // for Env

namespace dtag {
namespace op {

void Search(const std::string& tag, AuxType) {
  component::TagReader reader(Env::TagFile());
  bool match_found = false;
  while (reader.ReadLine()) {
    if (std::string::npos != reader.tag().find(tag)) {
      std::cout << reader.path() << '\n' << " " << reader.tag() << std::endl;
      match_found = true;
    }
  }
  if (!match_found) {
    std::cout << "tag (" << tag << ") NOT FOUNDED" << std::endl;
  }
}

}  // namespace op
}  // namespace dtag
