# OpenCV with CUDA Application Template

### Overview 
This is a starter template for an OpenCV with CUDA application.
So by definition the prerequisite for usage is that you have an NVIDIA graphics card with CUDA support.
The backbone of the template is the [cmake-init Project Template ](https://github.com/cginternals/cmake-init).
Not much is added to this, just `ThirdParty.cmake` file that finds installed dependencies (OpenCV being the only
one for the moment) and a source file `source/main/main.cpp` that compiles to a target 
that tests if OpenCV actually uses CUDA.

### Building and installing OpenCV 
For maximum control over the CMake configuration options, it is suggested that you download OpenCV from the official
repo, check out the tag of your choice at and configure/build/install it following these steps:

`cd opencv`
`mkdir build`
`cd build`
run `configure_opencv.sh` script :
```
sudo cmake -DCMAKE_BUILD_TYPE=RELEASE \
-DCMAKE_C_COMPILER=/usr/bin/gcc-9 \
-DCMAKE_CXX_COMPILER=/usr/bin/g++-9 \
-DCMAKE_INSTALL_PREFIX=/usr/local \
-DWITH_CUDA=ON \
-DWITH_CUDDNN=ON \
-DOPENCV_DNN_CUDA=ON \
-DENABLE_FAST_MATH=1 \
-DCUDA_FAST_MATH=1 \
-DCUDA_ARCH_BIN=7.5 \
-DWITH_CUBLAS=1 \
-DCUDA_NVCC_EXECUTABLE=/opt/cuda/bin/nvcc \
-DBUILD_opencv_cudalegacy=OFF \
-DINSTALL_PYTHON_EXAMPLES=OFF \
-DOPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules \
-DBUILD_EXAMPLES=OFF \
-DBUILD_TESTS=OFF \
-DBUILD_INFO_SKIP_EXTRA_MODULES=OFF \
-DBUILD_opencv_cudacodec=ON \
```
Notes on this script:
- You need g++-9 to compile OpenCV with CUDA
- CUDA_ARCH_BIN  is a parameter that depends on your graphic card, you will find 
 it on the NVIDIA  site.
- CUDA needs to be installed in your system
- cudnn (Nvidia CUDA Deep Neural Network) needs to be installed in your system
- OPENCV_EXTRA_MODULES_PATH is the path to [opencv-contrib](https://github.com/opencv/opencv_contrib)
 (you must clone the repo and set the parameter to the local path)


After you have configured the project with cmake, find the number of your CPU cores with
`nproc` and use the number to build the project with make
`make -j24` (for a processor with 24 cores.)

Last, install OpenCV in your system with
`sudo make install`

With successful installation of the CUDA enabled OpenCV libraries, `find_package(OpenCV REQUIRED)` in
 `ThirdParty.cmake` file will find and link the OpenCV libraries to your project.
 You configure and build the application with CMake as usual.
 See `ADAPT.md` on how to adapt the template to your application.
 
Important: Your system must have a CUDA compatible Nvidia Driver installed and the version must be
compatible CUDA version. See resources for more info. 


### Resources 

- [NVIDIA CUDA Installation Guide for Linux](https://docs.nvidia.com/cuda/cuda-installation-guide-linux/index.html)
- [CUDA Compatibility](https://docs.nvidia.com/deploy/cuda-compatibility/index.html)
- [Compile OpenCV with Cuda from the source.](https://medium.com/@bnarasapur/compile-opencv-with-cuda-from-the-source-1b98e9108a59)
- [How to install OpenCV 4.2.0 with CUDA 10.1 on Ubuntu](https://medium.com/@sb.jaduniv/how-to-install-opencv-4-2-0-with-cuda-10-1-on-ubuntu-20-04-lts-focal-fossa-bdc034109df3)
- [Get started with OpenCV CUDA-cpp](https://gist.github.com/Unbinilium/5e36e79aa457c0f10cc91665005c3695)
- [GPU Accelearated Computer Vision](https://docs.opencv.org/2.4/modules/gpu/doc/gpu.html)

