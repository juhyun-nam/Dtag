/// \file search.cc
/// \brief operation search
/// \author juhyun-nam

#include <iostream>
#include <string>
#include <vector>

#include "dtag/aux_type.h"
#include "dtag/components/tag_reader.h"

namespace dtag {
namespace op {

void Search(const std::string& tag, AuxType) {
  component::TagReader reader{};
  bool match_found = false;
  while (reader.ReadLine()) {
    if (std::string::npos != reader.tag().find(tag)) {
      std::cout << reader.path() << '\n' << "  " << reader.tag() << std::endl;
      match_found = true;
    }
  }
  if (!match_found) {
    std::cout << "tag (" << tag << ") NOT FOUNDED" << std::endl;
  }
}

}  // namespace op
}  // namespace dtag
