/// \file clear.cc
/// \brief operation clear
/// \author juhyun-nam

#include "dtag/operations/clear.h"

#include <iostream>

#include "dtag/components/tag_reader.h"
#include "dtag/components/tag_writer.h"
#include "dtag/env/enviroment.h"

namespace dtag {
namespace op {

Clear::Clear(const env::Enviroment& env) : env_(env) {}

void Clear::Process(const std::string& target_path) {
  auto cur_dir = env_.CurrentDirectory();
  component::TagReader reader(env_.TagReadFile());
  component::TagWriter writer(env_.TagWriteFile());
  bool match_found = false;

  while (reader.ReadLine()) {
    if (target_path == reader.path()) {
      match_found = true;
    } else {
      writer.WriteLine(reader.path());
      writer.WriteLine(reader.tag());
    }
  }

  if (match_found) {
    std::cout << "tag of path: " << target_path << " wiped out" << std::endl;
  } else {
    std::cerr << "tag of path: " << target_path << " does not exist"
              << std::endl;
  }

  reader.Close();
  writer.Close();
  env_.OverwriteTagFile();
}

}  // namespace op
}  // namespace dtag