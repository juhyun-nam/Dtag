/// \file op_factory.h
/// \brief operation factory
/// \author juhyun-nam

#ifndef DTAG_OPERATIONS_FACTORY_H_
#define DTAG_OPERATIONS_FACTORY_H_

#include <memory>

#include "dtag/operations/operation.h"
#include "dtag/operations/type.h"
namespace dtag {
namespace env {
class Enviroment;
}  // namespace env
}  // namespace dtag

namespace dtag {
namespace op {

class Factory {
 public:
  explicit Factory(const env::Enviroment&);
  std::unique_ptr<Operation> MakeOperation(Type);

 private:
  const env::Enviroment& env_;
};

}  // namespace op
}  // namespace dtag
#endif  // DTAG_OPERATIONS_FACTORY_H_
