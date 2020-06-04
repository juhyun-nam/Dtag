/// \file tag_reader.cc
/// \brief tag file reader
/// \author juhyun-nam

#include "dtag/components/tag_reader.h"

#include "dtag/env.h"

namespace dtag {
namespace component {

TagReader::TagReader() : ifs_(Env::TagFile()) {
  if (!ifs_) {
    throw "CAN NOT OPEN TAG FILE";
  }
  path_buf_.reserve(Env::kMaxPathLength);
  tag_buf_.reserve(Env::kMaxTagLength);
}

bool TagReader::ReadLine() {
  auto path = Env::CurrentDirectory();
  auto len = path.length();
  bool read_success = true;
  read_success = read_success && std::getline(ifs_, path_buf_);
  read_success = read_success && std::getline(ifs_, tag_buf_);
  return read_success;
}
const std::string& TagReader::path() const { return path_buf_; }
const std::string& TagReader::tag() const { return tag_buf_; }

}  // namespace component
}  // namespace dtag
