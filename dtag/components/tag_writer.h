/// \file tag_writer.h
/// \brief tag file writer
/// \author juhyun-nam

#ifndef DTAG_COMPONENTS_TAG_WRITER_H_
#define DTAG_COMPONENTS_TAG_WRITER_H_

#include <fstream>

class TagWriter {
 public:
  TagWriter() = default;
 private:
  std::ofstream ifs_;
};
#endif  // DTAG_COMPONENTS_TAG_WRITER_H_