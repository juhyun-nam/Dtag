/// \file parser.h
/// \brief main's option argument parser
/// \author juhyun-nam

#ifndef OPTION_PARSER_H_
#define OPTION_PARSER_H_

#include "dtag/option/argument.h"

namespace dtag {
namespace option {

Argument Parse(int argc, char** argv);
}  // namespace option
}  // namespace dtag

#endif  // OPTION_PARSER_H_
