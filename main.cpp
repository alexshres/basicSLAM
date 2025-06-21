#include "image.h"
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

int main() {

    std::vector<float> vec{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    int rows = 3;
    int channels = 0;

    cv::Mat m{vec, false};

    m = m.reshape(channels, rows);

    std::cout << "Number of rows: " << m.rows 
              << "\nNumber of columns: " << m.cols
              << "\nNumber of channels: " << m.channels() 
              << std::endl;


    std::cout << "Original Matrix:\n" << m << std::endl;

    Image img(m);

    std::cout << "Image class:\n";
    std::cout << img << std::endl;

    return 0;
}


