/// \file recent_writer.cc
/// \brief recent file manager
/// \author juhyun-nam

#include "dtag/components/recent_writer.h"

#include <fstream>

namespace dtag {
namespace component {

RecentWriter::RecentWriter(const std::string& file_path)
    : ofs_(file_path, std::ios::trunc) {
  if (!ofs_) {
    throw std::runtime_error("CAN NOT OPEN RECENT FILE");
  }
}

RecentWriter::~RecentWriter() {
  if (ofs_.is_open()) {
    ofs_.close();
  }
}

void RecentWriter::Close() {
  ofs_.close();
}

void RecentWriter::Update(const std::string& str) {
  ofs_.write(str.data(), str.length());
}

}  // namespace component
}  // namespace dtag
