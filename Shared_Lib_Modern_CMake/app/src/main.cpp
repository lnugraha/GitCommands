#include <iostream>
#include <gsl/gsl_blas.h>

#include "DenseMatrix.hpp"
#include "Random.hpp"

int main(int argc, char *argv[]){
  static const int SIZE = 5;
  int side = SIZE*SIZE;
  
  REAL *A = (REAL*)calloc(side, sizeof(REAL));
  REAL *B = (REAL*)calloc(side, sizeof(REAL)); 
  REAL *C = (REAL*)calloc(side, sizeof(REAL));  
  REAL *C_GSL = (REAL*)calloc(side, sizeof(REAL));  

  gsl_matrix_view A_gsl = gsl_matrix_view_array(A, SIZE, SIZE);
  gsl_matrix_view B_gsl = gsl_matrix_view_array(B, SIZE, SIZE);
  gsl_matrix_view C_gsl = gsl_matrix_view_array(C_GSL, SIZE, SIZE);

  std::cout << "Matrix A: " << std::endl;
  randMatrix(A, SIZE, SIZE);
  displayMatrix(A, SIZE, SIZE);
  
  std::cout << "\n";

  std::cout << "Matrix B: " << std::endl;
  randMatrix(B, SIZE, SIZE);
  displayMatrix(B, SIZE, SIZE);

  std::cout << "\n";
  
  std::cout << "Matrix C = A*B " << std::endl;
  dgemm(A, SIZE, SIZE, B, SIZE, SIZE, C);
  displayMatrix(C, SIZE, SIZE);

  gsl_blas_dgemm(CblasNoTrans, CblasNoTrans, 1.0, &A_gsl.matrix, &B_gsl.matrix,
  0.0, &C_gsl.matrix);
  
  std::cout << "GSL Results: " << std::endl;
  for (int i=0; i<SIZE; ++i){
    for (int j=0; j<SIZE; ++j){
      printf("%.2f ", C_GSL[ i*SIZE+j ] );
    }
    printf("\n");
  }

  return 0;
}
