#ifndef RANDOM_RANDOM_HPP_
#define RANDOM_RANDOM_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <chrono>
#include <future> 
#include <random>
#include <numeric>

#ifndef REAL
#define REAL double
#endif

void randMatrix(double *A, int row, int col);

void randMatrix(double **A, int row, int col);

void randVector(double *A, int size);

void displayMatrix(double **M, int row, int col);

void displayMatrix(double *M, int row, int col);

void displayVector(double *A, int size);

#endif
