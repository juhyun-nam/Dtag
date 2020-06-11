/// \file recent.h
/// \brief operation recent
/// \author juhyun-nam

#ifndef DTAG_TAG_OPERATIONS_RECENT_H_
#define DTAG_TAG_OPERATIONS_RECENT_H_

#include <string>

#include "dtag/operations/operation.h"
namespace dtag {
namespace env {
class Enviroment;
}  // namespace env
}  // namespace dtag

namespace dtag {
namespace op {

class Recent : public Operation {
 public:
  explicit Recent(const env::Enviroment&);
  virtual ~Recent() = default;

  void Process(const std::string&) override;

 private:
  const env::Enviroment& env_;
};

}  // namespace op
}  // namespace dtag
#endif  // DTAG_TAG_OPERATIONS_RECENT_H_
