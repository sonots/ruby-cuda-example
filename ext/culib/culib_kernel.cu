#include <stdio.h>
#include <cuda_runtime.h>

__global__ 
void my_kernel(int *ptr, int val, size_t N)
{
    for (size_t i = blockIdx.x * blockDim.x + threadIdx.x; i < N; i += blockDim.x * gridDim.x) {
        ptr[i] = val;
    }
}

extern "C"
void my_kernel_launch()
{
  int N = 8;
  int *a;
  cudaMallocManaged((void**)&a, sizeof(int)*N);

  //*a = 11;
  //for (int i = 0; i < N; i++)
  //  printf("%d ", a[i]);
  //printf("\n");
  //cudaMemset(a, 0, N*sizeof(int));
  //for (int i = 0; i < N; i++)
  //  printf("%d ", a[i]);
  //printf("\n");
  //for (int i = 0; i < N; i++)
  //  a[i] += 1;
  //for (int i = 0; i < N; i++)
  //  printf("%d ", a[i]);
  //printf("\n");

  my_kernel<<<2,2>>>(a, 10, N);
  cudaDeviceSynchronize();
  for (int i = 0; i < N; i++)
    printf("%d ", a[i]);
  printf("\n");
}

