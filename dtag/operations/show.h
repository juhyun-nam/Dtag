/// \file show.h
/// \brief operation show
/// \author juhyun-nam

#ifndef DTAG_TAG_OPERATIONS_SHOW_H_
#define DTAG_TAG_OPERATIONS_SHOW_H_

#include <string>

#include "dtag/operations/operation.h"
namespace dtag {
namespace env {
class Enviroment;
}  // namespace env
}  // namespace dtag

namespace dtag {
namespace op {

class Show : public Operation {
 public:
  Show(const env::Enviroment& env);
  virtual ~Show() = default;

  void Process(const std::string&) override;

 private:
  const env::Enviroment& env_;
};

}  // namespace op
}  // namespace dtag
#endif  // DTAG_TAG_OPERATIONS_SHOW_H_
