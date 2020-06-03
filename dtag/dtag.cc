/// \file dtag.cc
/// \brief dtag main
/// \author juhyun-nam

#include <unistd.h>

#include <iostream>

#include "option/parser.h"

int main(int argc, char** argv) {
  int arg = 0;
  while ((arg = getopt(argc, argv, "a"))) {
    switch (arg) {
      case 'a':
        std::cout << "optoin a" << std::endl;
        break;
    }
  }
  return 0;
}
