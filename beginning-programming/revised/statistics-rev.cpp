// clang++ -std=c++11 -stdlib=libc++ statistics-rev.cpp -o stats
#include <iostream>
#include <cstdio>
#include <cmath>

#define REAL double
#define TOTAL 47

template<class T>
void calculateAll(const T* data, int n, T &mean, T &vari, T &skew);

int main(int argc, char *argv[]){
  FILE *inputfile = fopen("SYS.txt", "r");
  REAL *data;
  if ( !(data = (REAL *)calloc(sizeof(REAL), TOTAL)) ){
    std::cerr << "Memory allocation is unsuccessful\n";
    return 1;
  }
  
  for (int i=0; i<TOTAL; ++i) fscanf(inputfile, "%lf", &data[i]);
  
  REAL average, variance, skewness;
  calculateAll(data, TOTAL, average, variance, skewness);
  std::cout << "Average : " << average << std::endl; 
  std::cout << "Variance: " << variance << std::endl;
  std::cout << "Skewness: " << skewness << std::endl;
  
  free(data); data = nullptr;
  return 0;
}

template<class T>
void calculateAll(const T* data, int n, T &mean, T &vari, T &skew){
  T sum = 0.0;
  for (int i=0; i<n; ++i) sum += data[i];
  mean = sum/(REAL)n; // Mean value

  T temp_00 = 0.0;
  for (int i=0; i<n; ++i) temp_00 += (data[i]-mean)*(data[i]-mean);
  vari = temp_00/(REAL)(n-1); // Variance value

  T temp_01 = 0.0;
  for (int i=0; i<n; ++i){
    temp_01 += (data[i]-mean)*(data[i]-mean)*(data[i]-mean);
  }
  skew = temp_01/( (REAL)(n-1)*sqrt(vari*vari*vari) ); // Skewness value
}
