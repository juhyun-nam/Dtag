/// \file tag_reader.cc
/// \brief tag file reader
/// \author juhyun-nam

#include "dtag/components/tag_reader.h"

#include <stdexcept>

#include "dtag/env/constant.h"

namespace dtag {
namespace component {

TagReader::TagReader(const std::string& tag_file) : ifs_(tag_file) {
  if (!ifs_) {
    throw std::runtime_error("CAN NOT OPEN TAG FILE");
  }
  path_buf_.reserve(env::kMaxPathLength);
  tag_buf_.reserve(env::kMaxTagLength);
}
TagReader::~TagReader() {
  if (ifs_.is_open()) {
    ifs_.close();
  }
}
void TagReader::Close() {
  ifs_.close();
}

bool TagReader::ReadLine() {
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
