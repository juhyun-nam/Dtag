/// \file add.h
/// \brief operation add
/// \author juhyun-nam

#ifndef DTAG_TAG_OPERATIONS_ADD_H_
#define DTAG_TAG_OPERATIONS_ADD_H_

#include <string>

#include "dtag/operations/operation.h"
namespace dtag {
namespace env {
class Enviroment;
}  // namespace env
}  // namespace dtag

namespace dtag {
namespace op {

class Add : public Operation {
 public:
  explicit Add(const env::Enviroment&);
  virtual ~Add() = default;

  void Process(const std::string&) override;

 private:
  const env::Enviroment& env_;
};

}  // namespace op
}  // namespace dtag
#endif  // DTAG_TAG_OPERATIONS_ADD_H_
