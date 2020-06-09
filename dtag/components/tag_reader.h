/// \file tag_reader.h
/// \brief tag file reader
/// \author juhyun-nam

#ifndef DTAG_COMPONENTS_TAG_READER_H_
#define DTAG_COMPONENTS_TAG_READER_H_

#include <fstream>
#include <string>

namespace dtag {
namespace component {

class TagReader {
 public:
  explicit TagReader(const std::string& tag_file);
  virtual ~TagReader();

  bool ReadLine();
  std::ifstream::pos_type GetPathPos(const std::string& path);
  const std::string& path() const;
  const std::string& tag() const;
  void Close();

 private:
  std::ifstream ifs_;
  std::string path_buf_{};
  std::string tag_buf_{};
};
}  // namespace component
}  // namespace dtag
#endif  // DTAG_COMPONENTS_TAG_READER_H_
