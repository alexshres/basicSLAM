#include <iostream>
#include <vector>
#include <cstdlib>


typedef std::vector<int> vectori;
typedef std::vector<float> vectorf;
typedef std::vector<double> vectord;

// 1-D Convolution function
vectorf conv1d(const vectorf& kernel, const vectorf& data, int padding=0, int stride=1);



int main()
{
	vectorf kernel3 = {1, 1, 1};
	vectorf kernel5 = {1, 1, 1, 1, 1};

	vectorf data = {1, 2, 3, 4, 5, 6, 7};

	vectorf result3 = conv1d(kernel3, data);
	vectorf result5 = conv1d(kernel5, data);
	vectorf exp_result3 = {6, 9, 12, 15, 18};
	vectorf exp_result5 = {15, 20, 25};

	std::cout << "Kernel of size 3:\n";

	for (auto i: kernel3)
		std::cout << i << " ";
	std::cout << "\n";


	std::cout << "Kernel of size 5:\n";

	for (auto i: kernel5)
		std::cout << i << " ";
	std::cout << "\n";


	std::cout << "Data:\n";

	for (auto i: data)
		std::cout << i << " ";
	std::cout << "\n";


	std::cout << "Result with kernel of size 3:\n";

	for (auto i: result3)
		std::cout << i << " ";
	std::cout << "\n";


	std::cout << "Expected result with kernel of size 3:\n";

	for (auto i: exp_result3)
		std::cout << i << " ";
	std::cout << "\n";


	std::cout << "Result with kernel of size 5:\n";

	for (auto i: result5)
		std::cout << i << " ";
	std::cout << "\n";


	std::cout << "Expected result with kernel of size 5:\n";

	for (auto i: exp_result5)
		std::cout << i << " ";
	std::cout << "\n";

	return 0;
}



vectorf conv1d(const vectorf& kernel, const vectorf& data, int padding, int stride)
{
	if (kernel.size()%2==0) {
		std::cerr << "Kernel size must be odd" << std::endl;
		std::exit(-1);
	}

	// Output shape is (input_size + 2*padding - kernel_size)/stride + 1
	int output_shape = (data.size() + 2*padding - kernel.size())/stride + 1;
	vectorf result(output_shape, 0.0);

	int data_idx = kernel.size()/2;
	int k_idx = data_idx;

	/*
	 * INCLUDING PADDING
	 * For padding i think it's just data_idx is initialized to kernel.size()/2 - padding ?
	 * could have if data_idx < 0 or data_idx >= data.size() then a = 1 and a_not = 1-a and 
	 * do some multiplication like a*expression + a_not*expression for data[data_idx]
	 *
	 */

	// LOGIC ONLY FOR DEFAULT padding=0 AND stride=1
	for (int i=0; i<output_shape; ++i) {
		for (int k=-k_idx; k<k_idx+1; ++k) 
			result[i] += kernel[k_idx + k]*data[data_idx+k];
		++data_idx;
	}
	
	return result;
}
