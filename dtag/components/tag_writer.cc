/// \file tag_writer.cc
/// \brief tag file writer
/// \author juhyun-nam

#include "dtag/components/tag_writer.h"

#include <cstdio>
#include <fstream>
#include <iostream>

#include "dtag/env.h"

namespace dtag {
namespace component {
/// temp file을 만들고 마음껏 사용한다음 destructor에서 바꿔치기
TagWriter::TagWriter() : ofs_(Env::TagTempFile(), std::ios::trunc) {
  if (!ofs_) {
    throw "CAN NOT OPEN TAG TEMPORARY FILE";
  }
}
TagWriter::~TagWriter() {
  ofs_.close();
  if (std::rename(Env::TagTempFile().data(), Env::TagFile().data())) {
    std::cerr << "CAN NOT RENAME TAG FILE" << std::endl;
  }
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
