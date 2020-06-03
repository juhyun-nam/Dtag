
#include "dtag/operations/op_factory.h"

#include <memory>

#include "dtag/operations/help.h"
#include "dtag/operations/show.h"

namespace dtag {
namespace op {

std::unique_ptr<Operation> GetOperation(OperationType op, AuxType aux) {
  switch (op) {
    case OperationType::kHELP:
      return std::make_unique<Help>();
    case OperationType::kSHOW:
      return std::make_unique<Show>(aux);
    case OperationType::kNONE:
    default:
      throw "notreable";
  }
}
}  // namespace op
}  // namespace dtag