// clang++ -std=c++11 -stdlib=libc++ statistics-rev.cpp -o stats
#include <iostream>
#include <cstdio>
#include <cmath>

#define REAL double
#define TOTAL 47

template<typename T>
class Statistics{
  private:
    T mean, variance, skew;
  public:
    Statistics(){}
    ~Statistics(){}
    inline T getMean() const { return this->mean; }
    inline T getVariance() const { return this->variance; }
    inline T getSkewness() const { return this->skew; }
    void calculateAll(const T* data, int n);
};

int main(int argc, char *argv[]){
  FILE *inputfile = fopen("HR.txt", "r");
  REAL *data;
  if ( !(data = (REAL *)calloc(sizeof(REAL), TOTAL)) ){
    std::cerr << "Memory allocation is unsuccessful\n";
    return 1;
  }
  
  for (int i=0; i<TOTAL; ++i) fscanf(inputfile, "%lf", &data[i]);
  
  Statistics<REAL> TEST;
  TEST.calculateAll(data, TOTAL);
  
  std::cout << "Average : " << TEST.getMean() << std::endl; 
  std::cout << "Variance: " << TEST.getVariance() << std::endl;
  std::cout << "Skewness: " << TEST.getSkewness() << std::endl;
  
  free(data); data = nullptr;
  return 0;
}

template<typename T>
void Statistics<T>::calculateAll(const T* data, int n){
  T sum = 0.0;
  for (int i=0; i<n; ++i) sum += data[i];
  this->mean = sum/(REAL)n; // Mean value

  T temp_0 = 0.0;
  for (int i=0; i<n; ++i) temp_0 += (data[i]-this->mean)*(data[i]-this->mean);
  this->variance = temp_0/(REAL)(n-1); // Variance value

  T temp_1 = 0.0;
  for (int i=0; i<n; ++i){
    temp_1 += (data[i]-this->mean)*(data[i]-this->mean)*(data[i]-this->mean);
  }
  // Skewness value
  skew = temp_1/((REAL)(n-1)*sqrt(this->variance*this->variance*this->variance));
}
