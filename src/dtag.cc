
#include <iostream>
#include <unistd.h>
#include "option_parser.h"

int main(int argc, char** argv) {
  int arg = 0;
  while((arg = getopt(argc, argv, "a"))) {
    switch(arg) {
      case 'a':
      std::cout << "optoin a" << std::endl;
      break;
    }

  }
  return 0;
}