/// \file clear.cc
/// \brief operation clear
/// \author juhyun-nam

#include "dtag/operations/clear.h"

#include <iostream>

#include "dtag/components/tag_reader.h"
#include "dtag/components/tag_writer.h"
#include "dtag/env.h"

namespace dtag {
namespace op {

void Clear(const std::string&, AuxType) {
  std::string path = Env::CurrentDirectory();
  component::TagReader reader(Env::TagFile());
  component::TagWriter writer(Env::TagTempFile());
  bool match_found = false;

  while (reader.ReadLine()) {
    if (path == reader.path()) {
      match_found = true;
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

  reader.Close();
  writer.Close();
  Env::OverwriteTagFile();
}

}  // namespace op
}  // namespace dtag