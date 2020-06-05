/// \file tag_writer.h
/// \brief tag file writer
/// \author juhyun-nam

#ifndef DTAG_COMPONENTS_TAG_WRITER_H_
#define DTAG_COMPONENTS_TAG_WRITER_H_

#include <fstream>
#include <string>

namespace dtag {
namespace component {

class TagWriter {
 public:
  TagWriter();

  void SetPos(std::ofstream::pos_type);
  void Write(const std::string& tags);

 private:
  std::ofstream ofs_;
};

}  // namespace component
}  // namespace dtag

#endif  // DTAG_COMPONENTS_TAG_WRITER_H_
