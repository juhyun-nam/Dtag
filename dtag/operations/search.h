/// \file search.h
/// \brief operation search
/// \author juhyun-nam

#ifndef DTAG_TAG_OPERATIONS_SEARCH_H_
#define DTAG_TAG_OPERATIONS_SEARCH_H_

#include <string>

#include "dtag/operations/operation.h"
namespace dtag {
namespace env {
class Enviroment;
}  // namespace env
}  // namespace dtag

namespace dtag {
namespace op {

class Search : public Operation {
 public:
  explicit Search(const env::Enviroment&);
  virtual ~Search() = default;

  void Process(const std::string&) override;

 private:
  const env::Enviroment& env_;
};

}  // namespace op
}  // namespace dtag
#endif  // DTAG_TAG_OPERATIONS_SEARCH_H_
