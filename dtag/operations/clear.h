/// \file clear.h
/// \brief operation clear
/// \author juhyun-nam

#ifndef DTAG_TAG_OPERATIONS_CLEAR_H_
#define DTAG_TAG_OPERATIONS_CLEAR_H_

#include <string>

#include "dtag/operations/operation.h"
namespace dtag {
namespace env {
class Enviroment;
}  // namespace env
}  // namespace dtag

namespace dtag {
namespace op {

class Clear : public Operation {
 public:
  explicit Clear(const env::Enviroment& env);
  virtual ~Clear() = default;

  void Process(const std::string&) override;

 private:
  const env::Enviroment& env_;
};

}  // namespace op
}  // namespace dtag
#endif  // DTAG_TAG_OPERATIONS_CLEAR_H_
