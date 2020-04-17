#include <iostream>

#include "DenseMatrix.hpp"
#include "Random.hpp"

int main(int argc, char *argv[]){
  const int SIZE = 5;
  int side = SIZE*SIZE;
  
  REAL *A = (REAL*)calloc(side, sizeof(REAL));
  REAL *B = (REAL*)calloc(side, sizeof(REAL)); 
  REAL *C = (REAL*)calloc(side, sizeof(REAL));  

  randMatrix(A, SIZE, SIZE);
  
  randMatrix(B, SIZE, SIZE);

  std::cout << "Matrix A: " << std::endl;
  displayMatrix(A, SIZE, SIZE);
  
  std::cout << "\n";

  std::cout << "Matrix B: " << std::endl;
  displayMatrix(B, SIZE, SIZE);

  std::cout << "\n";
  
  std::cout << "Matrix C = A*B " << std::endl;
  dgemm(A, SIZE, SIZE, B, SIZE, SIZE, C);
  displayMatrix(C, SIZE, SIZE);

  return 0;
}
