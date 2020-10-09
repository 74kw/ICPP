#include <iostream>
 // argument count a argument values
int main(int argc, char** argv) {
	int printCount;
	std::cout << "Choose count to print: ";
	std::cin >> printCount;
	std::cout << std::endl;
	for (int i = 0; i < argc; i++) {

		std::cout << argv[i] << std::endl;
	}
	return 0;
	
}
