#! /bin/zsh
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
..