#include "Random.hpp"

void randMatrix(double *A, int row, int col){
  srand((long)time(NULL));
  for (int i=0; i<row; ++i){
    for (int j=0; j<col; ++j){
      int idx = i*col + j;
      A[idx] = rand()/(double)RAND_MAX;
    }
  }
}

void randMatrix(double **A, int row, int col){
  srand((long)time(NULL));
  for (int i=0; i<row; ++i)
  {
    for (int j=0; j<col; ++j) A[i][j] = rand()/(double)RAND_MAX;
  }
}

void randVector(double *A, int size){
  srand((long)time(NULL));
  for (int i=0; i<size; ++i) A[i] = rand()/(double)RAND_MAX;
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

