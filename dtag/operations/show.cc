/// \file show.cc
/// \brief operation show
/// \author juhyun-nam

#include "dtag/operations/show.h"

#include <iostream>
#include <string>

#include "dtag/components/tag_reader.h"
#include "dtag/env/enviroment.h"

namespace dtag {
namespace op {

Show::Show(const env::Enviroment& env) : env_(env) {}

void Show::Process(const std::string&) {
  auto cur_dir = env_.CurrentDirectory();
  component::TagReader reader(env_.TagReadFile());
  bool match_found = false;

  while (reader.ReadLine()) {
    if (cur_dir == reader.path()) {
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
