#include "image.h"
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

int main() {

    std::vector<float> square_vec{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    std::vector<float> cube_vec{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};

    int sq_rows = 3;
    int sq_channels = 0;

    int cube_rows = 2;
    int cube_channels = 2;

    cv::Mat sq{square_vec, false};
    cv::Mat cube{cube_vec, false};

    sq = sq.reshape(sq_channels, sq_rows);
	cube = cube.reshape(cube_channels, cube_rows);

    std::cout << "Number of rows: " << sq.rows 
              << "\nNumber of columns: " << sq.cols
              << "\nNumber of channels: " << sq.channels() 
              << std::endl;

    std::cout << "Original Matrix:\n" << sq << std::endl;

    Image img_sq(sq);

    std::cout << "Image class square:\n";
    std::cout << img_sq << std::endl;

    std::cout << "Number of rows: " << cube.rows 
              << "\nNumber of columns: " << cube.cols
              << "\nNumber of channels: " << cube.channels() 
              << std::endl;

    std::cout << "Original Matrix:\n" << cube << std::endl;

    Image img_cube(cube);

    std::cout << "Image class cube:\n";
    std::cout << img_cube << std::endl;

    return 0;
}


