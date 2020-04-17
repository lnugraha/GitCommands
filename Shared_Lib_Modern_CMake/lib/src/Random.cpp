#include "Random.hpp"

void randMatrix(double *A, int row, int col){
  // srand((long)time(0));
  std::random_device seed;
  std::mt19937 engine(seed());
  std::uniform_real_distribution<double> dist(0.0, 1.0);
  
  for (int i=0; i<row; ++i){
    for (int j=0; j<col; ++j){
      int idx = i*col + j;
      A[idx] = dist(engine); // rand()/(double)RAND_MAX;
    }
  }
}

void randMatrix(double **A, int row, int col){
  // srand((long)time(NULL));
  std::random_device seed;
  std::mt19937 engine(seed());
  std::uniform_int_distribution<double> dist(0.0, 1.0);
  
  for (int i=0; i<row; ++i){
    for (int j=0; j<col; ++j){
      A[i][j] = dist(engine); // rand()/(double)RAND_MAX;
    } // END-FOR j
  } // END-FOR i
}

void randVector(double *A, int size){
  // srand((long)time(NULL));
  std::random_device seed;
  std::mt19937 engine(seed());
  std::uniform_int_distribution<double> dist(0.0, 1.0);
  
  for (int i=0; i<size; ++i) A[i] = dist(engine); // rand()/(double)RAND_MAX;
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

