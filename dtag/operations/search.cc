/// \file search.cc
/// \brief operation search
/// \author juhyun-nam

#include "dtag/operations/search.h"

#include <iostream>  // for operator<<, basic_ostream, endl
#include <string>    // for operator<<, char_traits, string

#include "dtag/components/tag_reader.h"  // for TagReader
#include "dtag/env/enviroment.h"                    // for env::Enviroment

namespace dtag {
namespace op {

Search::Search(const env::Enviroment& env) : env_(env) {}

void Search::Process(const std::string& target_tag) {
  component::TagReader reader(env_.TagReadFile());
  bool match_found = false;
  while (reader.ReadLine()) {
    if (reader.tag().find(target_tag) != std::string::npos) {
      std::cout << reader.path() << '\n' << " " << reader.tag() << std::endl;
      match_found = true;
    }
  }
  if (!match_found) {
    std::cout << "tag: " << target_tag << " NOT FOUNDED" << std::endl;
  }
}

}  // namespace op
}  // namespace dtag
