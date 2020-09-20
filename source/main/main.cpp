#include <iostream>

#include <baselib/baselib.h>

#include <fiblib/CTFibonacci.h>
#include <fiblib/Fibonacci.h>

#include <opencv2/opencv.hpp>
#include <opencv2/cudaimgproc.hpp>
#include "opencv2/cudawarping.hpp"


using namespace cv;
using namespace std;


int main(int argc, char *argv[]) {
    baselib::projectInfo();

    // Calculate and print fibonacci number
    printf("Fibonacci library \n");
    printf("CTFibonacci(6) =  %d \n", fiblib::CTFibonacci<6>::value);
    printf("Fibonacci(8)   = %d \n", fiblib::Fibonacci()(8));

    string picture = "data/nole-fed.jpg";
    Mat inImage;
    Mat outImage;
    inImage = imread(picture, 1);
    if (!inImage.data) {
        printf("No image data \n");
        return -1;
    }
    cuda::GpuMat gpuInImage;
    cuda::GpuMat gpuOutImage;

    printf("OpenCV with Cuda Test begins. \n");
    for (int i = 0; i < 100; i++) {
        gpuInImage.upload(inImage);
        cuda::resize(gpuInImage, gpuOutImage, Size(4096, 4096));
        gpuOutImage.download(outImage);
        printf("Resizing image, iteration: %d \n", i + 1);
    }

    imwrite("data/nole-fed-resized.jpg", outImage);
    printf("Done, resized image written in data folder.");

    return 0;

};