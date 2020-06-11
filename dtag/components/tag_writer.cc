/// \file tag_writer.cc
/// \brief tag file writer
/// \author juhyun-nam

#include "dtag/components/tag_writer.h"

#include <fstream>    // for ofstream, basic_ios, basic_ostream::put, basic_...
#include <stdexcept>  // for runtime_error

namespace dtag {
namespace component {

TagWriter::TagWriter(const std::string& out_file)
    : ofs_(out_file, std::ios::trunc) {
  if (!ofs_) {
    throw std::runtime_error("CAN NOT OPEN TAG TEMPORARY FILE");
  }
}
TagWriter::~TagWriter() {
  if (ofs_.is_open()) {
    ofs_.close();
  }
}
void TagWriter::Close() {
  ofs_.close();
}
void TagWriter::SetPos(std::ofstream::pos_type pos) {
  ofs_.seekp(pos);
}
void TagWriter::Write(const std::string& str) {
  ofs_.write(str.data(), str.length());
}
void TagWriter::WriteLine(const std::string& str) {
  Write(str);
  Put('\n');
}
void TagWriter::Put(char c) {
  ofs_.put(c);
}

}  // namespace component
}  // namespace dtag
