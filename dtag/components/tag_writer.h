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
  explicit TagWriter(const std::string& out_file);
  virtual ~TagWriter();

  void Close();
  void SetPos(std::ofstream::pos_type);
  void Write(const std::string& str);
  void WriteLine(const std::string& str);
  void Put(char);

 private:
  std::ofstream ofs_;
};

}  // namespace component
}  // namespace dtag

#endif  // DTAG_COMPONENTS_TAG_WRITER_H_
