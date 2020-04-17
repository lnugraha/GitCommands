#include "Random.hpp"

template<typename T>
static T randReal(T min=0.0, T max=1.0){
  std::random_device seed;
  std::mt19937 engine(seed());
  std::uniform_real_distribution<T> dist(min, max);
  return dist(engine);
}


void randMatrix(double *A, int row, int col){
  for (int i=0; i<row; ++i){
    for (int j=0; j<col; ++j){
      int idx = i*col + j;
      A[idx] = randReal<double>();
    }
  }
}

void randMatrix(double **A, int row, int col){
  for (int i=0; i<row; ++i){
    for (int j=0; j<col; ++j){ A[i][j] = randReal<double>();
    } // END-FOR j
  } // END-FOR i
}

void randVector(double *A, int size){
  for (int i=0; i<size; ++i) A[i] = randReal<double>(); 
}

void displayMatrix(double **M, int row, int col){
  for (int i=0; i<row; ++i){
    for (int j=0; j<col; ++j) printf("%.2f ", M[i][j]);
    printf("\n");
  }
}

void displayMatrix(double *M, int row, int col){
  for (int i=0; i<row; ++i){
    for (int j=0; j<col; ++j){
      int idx = i*col + j;
      printf("%.2f ", M[idx]);
    }
    printf("\n");
  }
}

void displayVector(double *A, int size){
  for (int i=0; i<size; ++i) printf("%.2f \n", A[i]);
}

