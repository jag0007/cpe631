#include <stdlib.h>
#include <stdio.h>

void createSquareMatrix(double* matrix, int dim) {
  for (int i = 0; i < dim * dim; i++) {
    double random = (((double) rand()) / RAND_MAX) * 1000 - 500;
    matrix[i] = random;
  }
}

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Wrong number of arguments\n");
  }

  int N = atoi(argv[1]);

  double* A = (double*) malloc(sizeof(double) * N * N);
  createSquareMatrix(A, N);
  double* B = (double*) malloc(sizeof(double) * N * N);
  createSquareMatrix(B, N);
  double* C = (double*) malloc(sizeof(double) * N * N); 
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int value = 0;
      for (int k = 0; k < N; k++) {
        value += A[i*N + k] * B[k*N + j];
      }
      C[i*N + j] = value;
    }
  }

  FILE *file;
  file = fopen("out.dat", "wb");
  fwrite(C, sizeof(double), N*N, file); 
  fclose(file);
}