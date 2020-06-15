/// \file op_factory.cc
/// \brief operation factory
/// \author juhyun-nam

#include "dtag/operations/factory.h"

#include <memory>
#include <stdexcept>  // for runtime_error

#include "dtag/operations/add.h"        // for Add
#include "dtag/operations/clear.h"      // for Clear
#include "dtag/operations/help.h"       // for Help
#include "dtag/operations/operation.h"  // for Operation
#include "dtag/operations/recent.h"     // for Recent
#include "dtag/operations/remove.h"     // for Remove
#include "dtag/operations/search.h"     // for Search
#include "dtag/operations/show.h"       // for Show

namespace dtag {
namespace op {

Factory::Factory(const env::Enviroment& env) : env_(env) {}

std::shared_ptr<Operation> Factory::MakeOperation(Type type) {
  std::shared_ptr<Operation> ptr;
  switch (type) {
    case Type::kADD:
      ptr = std::make_shared<Add>(env_);
      break;
    case Type::kCLEAR:
      ptr = std::make_shared<Clear>(env_);
      break;
    case Type::kHELP:
      ptr = std::make_shared<Help>();
      break;
    case Type::kRECENT:
      ptr = std::make_shared<Recent>(env_);
      break;
    case Type::kREMOVE:
      ptr = std::make_shared<Remove>(env_);
      break;
    case Type::kSEARCH:
      ptr = std::make_shared<Search>(env_);
      break;
    case Type::kSHOW:
      ptr = std::make_shared<Show>(env_);
      break;
    default:
      throw std::runtime_error("SOMETHING IS WRONG");
  }
  return ptr;
}

}  // namespace op
}  // namespace dtag