#pragma once

#include <cstdlib>
#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>

typedef std::vector<float> vector;

class Image {
    private:
        int rows;
        int columns;
        int channels;

        int size;

        vector data;

    public:
        Image();
        Image(cv::Mat img);

        /*
         * conv1d(vector, int) 
            * takes a kernel of type vector<float> 
            * int padding: 0 means output will have smaller dimensions 
            *              if size(kernel) > 1 
            * returns an Image type
         */
        Image conv1d(vector& kernel, int padding);
        
        friend std::ostream& operator<<(std::ostream& os, const Image& im); 

};
