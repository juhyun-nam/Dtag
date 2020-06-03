/// \file op_factory.h
/// \brief operation factory
/// \author juhyun-nam

#ifndef DTAG_OPERATIONS_OP_FACTORY_H_
#define DTAG_OPERATIONS_OP_FACTORY_H_
#include <memory>

#include "dtag/operations/aux_type.h"
#include "dtag/operations/operation.h"
#include "dtag/operations/operation_type.h"

namespace dtag {
namespace op {

std::unique_ptr<Operation> GetOperation(OperationType, AuxType);

}  // namespace op
}  // namespace dtag

#endif  // DTAG_OPERATIONS_OP_FACTORY_H_