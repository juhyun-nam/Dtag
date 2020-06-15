/// \file op_factory.h
/// \brief operation factory
/// \author juhyun-nam

#ifndef DTAG_OPERATIONS_FACTORY_H_
#define DTAG_OPERATIONS_FACTORY_H_

#include <memory>  // for shared_ptr

#include "dtag/operations/type.h"  // for Type
namespace dtag {
namespace env {
class Enviroment;
}
}  // namespace dtag
namespace dtag {
namespace op {
class Operation;
}
}  // namespace dtag

namespace dtag {
namespace op {

class Factory {
 public:
  explicit Factory(const env::Enviroment&);
  std::shared_ptr<Operation> MakeOperation(Type);

 private:
  const env::Enviroment& env_;
};

}  // namespace op
}  // namespace dtag
#endif  // DTAG_OPERATIONS_FACTORY_H_
