/// \file show.cc
/// \brief operation show
/// \author juhyun-nam

#include <cassert>
#include <iostream>
#include <string>

#include "dtag/aux_type.h"
#include "dtag/components/tag_reader.h"

namespace dtag {
namespace op {

void Show(const std::string&, AuxType) {
  auto path = Env::CurrentDirectory();
  component::TagReader reader{};
  bool match_found = false;
  while (reader.ReadLine()) {
    if (path == reader.path()) {
      match_found = true;
      break;
    }
  }
  assert(match_found);
  std::cout << reader.tag() << std::endl;
}

}  // namespace op
}  // namespace dtag
