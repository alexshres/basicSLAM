#include "image.h"
#include <iostream>
#include <vector>

Image::Image(): rows(0), columns(0), channels(0)
{}

Image::Image(cv::Mat img)
{
    cv::Mat float_img;
    img.convertTo(float_img, CV_32F);

    rows = img.rows;
    columns = img.cols;
    channels = img.channels();

    size = rows*columns*channels;
    data = vector(size, 0);


    for (int h=0; h<rows; ++h) {
        for (int w=0; w<columns; ++w) {
            for (int n=0; n<channels; ++n) 
                data[(h*columns+w)*channels + n] = img.ptr<float>(h)[w*channels+n];
        }
    }
}


std::ostream& operator<<(std::ostream& os, const Image& im)
{
    for (int i=0; i<im.size; ++i)
        os << im.data[i] << " ";

    return os;
}
