#include "mathops/mathops.hpp"
#include <iostream>
#include <cmath>

int main(int argc, char *argv[]){

  REAL x, y, z;
  x = 2.5;
  y = 2.0;
  z = sum(x, y);
  std::cout << z << std::endl;
  return 0;
}
