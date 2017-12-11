#include <stdio.h>
#include <ruby.h>
#include <cuda_runtime.h>

void my_kernel_launch();

VALUE 
print_from_kernel(VALUE obj)
{
  my_kernel_launch();
  return Qnil;
}

VALUE
printGPUinfo(VALUE obj)
{
    return Qnil;
}

//VALUE 
//printGPUinfo(VALUE obj)
//{
//  int devID, count = 0;
//  cudaDeviceProp props;
//  
//  cudaGetDeviceCount(&count);
//  if(count == 0){
//    printf("CUDA Device Not Found.\n");
//    return Qnil;
//  }
//  for(devID = 0; devID < count; devID++){
//    if(cudaGetDevice(&devID) == cudaSuccess && cudaGetDeviceProperties(&props, devID) == cudaSuccess){
//      printf("GPU %d: \"%s\" with Compute %d.%d capability\n",
//             devID, props.name, props.major, props.minor);
//    }else{
//      printf("Getting CUDA Device %d info failed.\n", devID);
//    }
//  }
//  cudaDeviceReset();
//  return Qnil;
//}

void
Init_culib(){
  VALUE mCulib = rb_define_module("Culib");
  rb_define_singleton_method(mCulib, "print_from_kernel", RUBY_METHOD_FUNC(print_from_kernel), 0);
  rb_define_singleton_method(mCulib, "printGPUinfo", RUBY_METHOD_FUNC(printGPUinfo), 0);
}
