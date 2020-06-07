/// \file add.cc
/// \brief operation add
/// \author juhyun-nam

#include "dtag/operations/add.h"

#include <iostream>

#include "dtag/components/tag_reader.h"
#include "dtag/components/tag_writer.h"
#include "dtag/env.h"

namespace dtag {
namespace op {

void Add(const std::string& tag, AuxType) {
  std::string path = Env::CurrentDirectory();
  component::TagReader reader{};
  component::TagWriter writer{};
  bool match_found = false;

  while (reader.ReadLine()) {
    writer.WriteLine(reader.path());
    if (path == reader.path()) {
      match_found = true;
      auto pos = reader.tag().find(tag);
      if (std::string::npos == pos) {
        writer.WriteLine(reader.tag() + tag + " ");
      }
    } else {
      writer.WriteLine(reader.tag());
    }
  }

  if (!match_found) {
    writer.WriteLine(path);
    writer.WriteLine(" " + tag + " ");
  }

  std::cout << "tag: " << tag << " added in path: " << path << std::endl;
}

}  // namespace op
}  // namespace dtag