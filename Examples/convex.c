/*
 ============================================================================
 Name        : cfft2.c
 Author      : Rafat Hussain
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "conv.h"


int main() {

  int N = 77;
  int L = 65;
  int M = N+L-1;
  int i,out;
  
  /*This program performs convolution using two methods
   * The first one is direct method and it doesn't require either FFT
   * or creation of a convolution object
   * 
   * The second method is FFT based and needs creation of FFT object.
   * The second method typically out-performs the first one if the convolution
   * size is > 100. This number is not set in stone and may vary based on
   * the computer achitecture and other factors.
   * 
   */
  
  //Initialize data and convoluton object
  
  double* inp1 = (double*) malloc (sizeof(double) * N);
  double* inp2 = (double*) malloc (sizeof(double) * L);
  double* oup = (double*) malloc (sizeof(double) * M);
  double* oup2 = (double*) malloc (sizeof(double) * M);
  
  conv_object obj = conv_init(N,L);
  
  
  for (i = 0; i < N; i++) {
    inp1[i] = i+1;
  }
  
  for (i = 0; i < L; i++) {
    inp2[i] = 2.0*i+1;
  }
  // Perfor Direct Convolution
  
  conv_direct(inp1,N,inp2,L,oup);
 
  // Perform FFT Convolution
  conv_fft(obj,inp1,inp2,oup2);
  
  
  for(i = 0; i < M; i++) {
    printf("%lf %lf \n",oup[i],oup2[i]);
  }
  
  // Free Data and Convolution Object
  
  free(inp1);
  free(inp2);
  free(oup);
  free(oup2);
  free_conv(obj);
  
  return 0;


}

