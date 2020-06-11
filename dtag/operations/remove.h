/// \file remove
/// \brief operation remove
/// \author juhyun-nam

#ifndef DTAG_TAG_OPERATIONS_REMOVE_H_
#define DTAG_TAG_OPERATIONS_REMOVE_H_

#include <string>

#include "dtag/operations/operation.h"
namespace dtag {
namespace env {
class Enviroment;
}  // namespace env
}  // namespace dtag

namespace dtag {
namespace op {

class Remove : public Operation {
 public:
  explicit Remove(const env::Enviroment&);
  virtual ~Remove() = default;

  void Process(const std::string&) override;

 private:
  const env::Enviroment& env_;
};

}  // namespace op
}  // namespace dtag
#endif  // DTAG_TAG_OPERATIONS_REMOVE_H_
