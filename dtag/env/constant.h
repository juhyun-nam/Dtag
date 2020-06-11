/// \file constant.h
/// \brief enviroment constant
/// \author juhyun-nam

#ifndef DTAG_ENV_CONSTANT_H_
#define DTAG_ENV_CONSTANT_H_

#include <cstddef>  // for size_t

namespace dtag {
namespace env {

static constexpr std::size_t kMaxPathLength = 128;
static constexpr std::size_t kMaxTagLength = 128;
static constexpr std::size_t kMaxLineLength = kMaxPathLength + kMaxTagLength;

}  // namespace env
}  // namespace dtag
#endif  // DTAG_ENV_CONSTANT_H_