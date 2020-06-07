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
TagReader::~TagReader() {
  ifs_.close();
}

bool TagReader::ReadLine() {
  auto path = Env::CurrentDirectory();
  bool read_success = true;
  read_success = read_success && std::getline(ifs_, path_buf_);
  read_success = read_success && std::getline(ifs_, tag_buf_);
  return read_success;
}
std::ifstream::pos_type TagReader::GetPathPos(const std::string& path) {
  std::ifstream::pos_type pos(-1);
  ifs_.seekg(std::ifstream::pos_type(0));
  while (std::getline(ifs_, path_buf_)) {
    std::getline(ifs_, tag_buf_);
    if (path == path_buf_) {
      pos = ifs_.tellg();
      break;
    }
  }
  return pos;
}
const std::string& TagReader::path() const {
  return path_buf_;
}
const std::string& TagReader::tag() const {
  return tag_buf_;
}

}  // namespace component
}  // namespace dtag
