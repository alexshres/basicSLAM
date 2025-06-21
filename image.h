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
        
        friend std::ostream& operator<<(std::ostream& os, const Image& im); 

};
