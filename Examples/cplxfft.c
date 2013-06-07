/*
 ============================================================================
 Name        : cfft2.c
 Author      : Rafat Hussain
 Version     :
 Copyright   : 
 Description : Complex FFT/IFFT Test Program
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "hsfft.h"


int main() {

  int N = 48;
  int i,out;
  // Initialize Data and FFT/IFFT Objects
  fft_data* inp = (fft_data*) malloc (sizeof(fft_data) * N);
  fft_data* oup = (fft_data*) malloc (sizeof(fft_data) * N);
  fft_object obj = fft_init(N,1);
  fft_object iobj = fft_init(N,-1);

  for (i = 0; i < N; i++) {
    inp[i].re = i;
    inp[i].im = 0;
  }

  // Perform FFT
   	
  fft_exec(obj,inp,oup);
  printf(" FFT Results \n");
  printf(" \n Real Imaginary \n");
  for(i = 0; i < N; i++) {
    printf("%f %f \n",oup[i].re,oup[i].im);
  }
  
  // Perform IFFT
  fft_exec(iobj,oup,inp);
  printf(" IFFT Results \n");
  printf(" \n Real Imaginary \n");
  for(i = 0; i < N; i++) {
    printf("%f %f \n",inp[i].re/N,inp[i].im/N);
  }
  
  //Free Data and Objects

  free(inp);
  free(oup);
  
  free_fft(obj);
  free_fft(iobj);

  return 0;


}

