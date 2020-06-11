/// \file remove
/// \brief operation remove
/// \author juhyun-nam

#include "dtag/operations/remove.h"

#include <iostream>  // for operator<<, basic_ostream, endl

#include "dtag/components/tag_reader.h"  // for TagReader
#include "dtag/components/tag_writer.h"  // for TagWriter
#include "dtag/env/enviroment.h"                    // for env::Enviroment

namespace dtag {
namespace op {

Remove::Remove(const env::Enviroment& env) : env_(env) {}

void Remove::Process(const std::string& target_tag) {
  auto cur_dir = env_.CurrentDirectory();
  component::TagReader reader(env_.TagReadFile());
  component::TagWriter writer(env_.TagWriteFile());
  bool match_found = false;

  while (reader.ReadLine()) {
    if (cur_dir == reader.path()) {
      auto file_tag = reader.tag();
      /// tag 전체와 같은 경우
      if (file_tag == " " + target_tag + " ") {
        break;
      }
      writer.WriteLine(reader.path());
      auto pos = file_tag.find(" " + target_tag + " ");
      if (std::string::npos != pos) {
        match_found = true;
        file_tag.erase(pos, pos + target_tag.length());
        writer.WriteLine(file_tag);
        break;
      }
    }
    writer.WriteLine(reader.tag());
  }

  if (match_found) {
    std::cout << "tag: " << target_tag << " removed" << std::endl;
  } else {
    std::cerr << "tag of path: " << cur_dir << " does not exist" << std::endl;
  }

  reader.Close();
  writer.Close();
  env_.OverwriteTagFile();
}

}  // namespace op
}  // namespace dtag