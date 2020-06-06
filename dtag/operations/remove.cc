/// \file remove
/// \brief operation remove
/// \author juhyun-nam

#include "dtag/operations/remove.h"

#include <iostream>

#include "dtag/components/tag_reader.h"
#include "dtag/components/tag_writer.h"
#include "dtag/env.h"

namespace dtag {
namespace op {

void Remove(const std::string& tag, AuxType) {
  auto path = Env::CurrentDirectory();
  component::TagReader reader{};
  component::TagWriter writer{};
  bool match_found = false;

  while (reader.ReadLine()) {
    if (path == reader.path()) {
      match_found = true;
      auto file_tag = reader.tag();
      std::find(file_tag.begin(), file_tag.end(), tag);

    } else {
      writer.WriteLine(reader.path());
      writer.WriteLine(reader.tag());
    }
  }

  if (match_found) {
    std::cout << "tag of path: " << path << " wiped out" << std::endl;
  } else {
    std::cerr << "tag of path: " << path << " does not exist" << std::endl;
  }
}

}  // namespace op
}  // namespace dtag