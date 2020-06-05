/// \file tag_writer.cc
/// \brief tag file writer
/// \author juhyun-nam

#include "dtag/components/tag_writer.h"

#include <fstream>

#include "dtag/env.h"

namespace dtag {
namespace component {
TagWriter::TagWriter() : ofs_(Env::TagFile(), std::ios::out) {
  if (!ofs_) {
    throw "CAN NOT OPEN TAG FILE";
  }
}
void TagWriter::SetPos(std::ofstream::pos_type pos) { ofs_.seekp(pos); }
void TagWriter::Write(const std::string& tags) { ofs_.write(tags.data(), tags.length()); }

}  // namespace component
}  // namespace dtag
