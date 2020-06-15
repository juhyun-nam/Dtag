/// \file add.cc
/// \brief operation add
/// \author juhyun-nam

#include "dtag/operations/add.h"

#include <iostream>

#include "dtag/components/recent_writer.h"
#include "dtag/components/tag_reader.h"
#include "dtag/components/tag_writer.h"
#include "dtag/env/enviroment.h"

namespace dtag {
namespace op {

Add::Add(const env::Enviroment& env) : env_(env) {}

void Add::Process(const std::string& target_tag) {
  auto cur_dir = env_.CurrentDirectory();
  component::TagReader reader(env_.TagReadFile());
  component::TagWriter writer(env_.TagWriteFile());
  component::RecentWriter recent(env_.RecentFile());
  bool match_found = false;

  while (reader.ReadLine()) {
    writer.WriteLine(reader.path());
    if (cur_dir == reader.path()) {
      recent.Update(cur_dir);
      match_found = true;
      auto pos = reader.tag().find(target_tag);
      if (pos == std::string::npos) {
        writer.WriteLine(reader.tag() + target_tag + " ");
      }
    } else {
      writer.WriteLine(reader.tag());
    }
  }

  if (!match_found) {
    writer.WriteLine(cur_dir);
    writer.WriteLine(" " + target_tag + " ");
    recent.Update(cur_dir);
  }

  std::cout << "tag: " << target_tag
            << " added in current directory: " << cur_dir << std::endl;

  reader.Close();
  writer.Close();
  env_.OverwriteTagFile();
}

}  // namespace op
}  // namespace dtag