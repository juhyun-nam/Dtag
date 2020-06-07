/// \file show.cc
/// \brief operation show
/// \author juhyun-nam

#include "dtag/operations/show.h"

#include <iostream>
#include <string>

#include "dtag/components/tag_reader.h"
#include "dtag/env.h"

namespace dtag {
namespace op {

void Show(const std::string&, AuxType) {
  std::string path = Env::CurrentDirectory();
  component::TagReader reader{};
  bool match_found = false;
  while (reader.ReadLine()) {
    if (path == reader.path()) {
      match_found = true;
      break;
    }
  }
  if (!match_found) {
    std::cerr << "TAG NOT FOUND IN THIS DIRECTORY" << std::endl;
    return;
  }
  std::cout << reader.tag() << std::endl;
}

}  // namespace op
}  // namespace dtag
