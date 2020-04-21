#include <iostream>

#include "DenseMatrix.hpp"
#include "Random.hpp"

#include <mkl.h>

int main(int argc, char *argv[]){
  const int SIZE = 5;
  int side = SIZE*SIZE;
  
  REAL *A = (REAL*)calloc(side, sizeof(REAL));
  REAL *B = (REAL*)calloc(side, sizeof(REAL)); 
  REAL *C = (REAL*)calloc(side, sizeof(REAL));  

  REAL *A_mkl, *B_mkl, *C_mkl;
  A_mkl = (REAL*)mkl_malloc( SIZE*SIZE*sizeof(REAL), 64 );
  B_mkl = (REAL*)mkl_malloc( SIZE*SIZE*sizeof(REAL), 64 );
  C_mkl = (REAL*)mkl_malloc( SIZE*SIZE*sizeof(REAL), 64 );

  randMatrix(A, SIZE, SIZE);
  randMatrix(B, SIZE, SIZE);

  randMatrix(A_mkl, SIZE, SIZE);
  randMatrix(B_mkl, SIZE, SIZE);
  cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, SIZE, SIZE, SIZE, 1.0,
    A_mkl, SIZE, B_mkl, SIZE, 1.0, C_mkl, SIZE);

  std::cout << "Matrix A: " << std::endl;
  displayMatrix(A, SIZE, SIZE);
  
  std::cout << "\n";

  std::cout << "Matrix B: " << std::endl;
  displayMatrix(B, SIZE, SIZE);

  std::cout << "\n";
  
  std::cout << "Matrix C = A*B " << std::endl;
  dgemm(A, SIZE, SIZE, B, SIZE, SIZE, C);
  displayMatrix(C, SIZE, SIZE);

  std::cout << "\n";
  
  std::cout << "Matrix MKL A: " << std::endl;
  displayMatrix(A_mkl, SIZE, SIZE);
  
  std::cout << "\n";

  std::cout << "Matrix MKL B: " << std::endl;
  displayMatrix(B_mkl, SIZE, SIZE);

  std::cout << "\n";

  std::cout << "Matrix MKL C = MKL A * KML B " << std::endl;
  displayMatrix(C_mkl, SIZE, SIZE);

  return 0;
}
