/// \file op_factory.cc
/// \brief operation factory
/// \author juhyun-nam

#include "dtag/operations/factory.h"

#include <stdexcept>

#include "dtag/operations/add.h"
#include "dtag/operations/clear.h"
#include "dtag/operations/help.h"
#include "dtag/operations/recent.h"
#include "dtag/operations/remove.h"
#include "dtag/operations/search.h"
#include "dtag/operations/show.h"

namespace dtag {
namespace op {

Factory::Factory(const env::Enviroment& env) : env_(env) {}

std::unique_ptr<Operation> Factory::MakeOperation(Type type) {
  std::unique_ptr<Operation> ptr;
  switch (type) {
    case Type::kADD:
      ptr = std::make_unique<Add>(env_);
      break;
    case Type::kCLEAR:
      ptr = std::make_unique<Clear>(env_);
      break;
    case Type::kHELP:
      ptr = std::make_unique<Help>();
      break;
    case Type::kRECENT:
      ptr = std::make_unique<Recent>(env_);
      break;
    case Type::kREMOVE:
      ptr = std::make_unique<Remove>(env_);
      break;
    case Type::kSEARCH:
      ptr = std::make_unique<Search>(env_);
      break;
    case Type::kSHOW:
      ptr = std::make_unique<Show>(env_);
      break;
    default:
      throw std::runtime_error("SOMETHING IS WRONG");
  }
  return ptr;
}

}  // namespace op
}  // namespace dtag