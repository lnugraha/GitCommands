#include <mkl.h>
#include <mkl_dfti.h>
#include <iostream>

int main(int argc, char *argv[]){

  float _Complex data[20][40];
  MKL_LONG status;
  DFTI_DESCRIPTOR_HANDLE desc_handle_dim1 = NULL;
  DFTI_DESCRIPTOR_HANDLE desc_handle_dim2 = NULL;

  status = DftiCreateDescriptor(&desc_handle_dim1, DFTI_SINGLE, DFTI_COMPLEX, 
    1, 20);

  status = DftiCreateDescriptor(&desc_handle_dim2, DFTI_SINGLE, DFTI_COMPLEX, 
    1, 40);

  MKL_LONG stride[2] = {0, 40};
  status = DftiSetValue(desc_handle_dim1, DFTI_NUMBER_OF_TRANSFORMS, 40);
  status = DftiSetValue(desc_handle_dim1, DFTI_INPUT_DISTANCE, 1);
  status = DftiSetValue(desc_handle_dim1, DFTI_OUTPUT_DISTANCE, 1);
  status = DftiSetValue(desc_handle_dim1, DFTI_INPUT_STRIDES, stride);
  status = DftiSetValue(desc_handle_dim1, DFTI_OUTPUT_STRIDES, stride);
  status = DftiCommitDescriptor(desc_handle_dim1);
  status = DftiComputeForward(desc_handle_dim1, data);
  status = DftiFreeDescriptor(&desc_handle_dim1);

  return 0;
}
