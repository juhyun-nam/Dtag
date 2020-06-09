/// \file recent_writer.h
/// \brief recent file manager
/// \author juhyun-nam

#ifndef DTAG_COMPONENTS_RECENT_WRITER_H_
#define DTAG_COMPONENTS_RECENT_WRITER_H_

#include <fstream>
#include <string>

namespace dtag {
namespace component {
class RecentWriter {
 public:
  explicit RecentWriter(const std::string& file_path);
  virtual ~RecentWriter();

  void Update(const std::string& path);
  void Close();

 private:
  std::ofstream ofs_;
};
}  // namespace component
}  // namespace dtag
#endif  // DTAG_COMPONENTS_RECENT_WRITER_H_