#include <iostream>
#include <sstream> 
#include <math.h>     

using namespace std;

double calc(double num1, double num2, char oper) {
	/*cout << oper;
	if (oper == 43) {
		return (num1 + num2);
	}
	else if (oper == 45) {
		return (num1 - num2);
	}
	else if (oper == 47) {
		return (num1 / num2);
	}
	else if (oper == 42) {
		return (num1 * num2);
	}
	else 	
		return pow(num1, num2);*/

	switch (oper)
	{
	case '+':
		return num1 + num2;
	case '-':
		return num1 - num2;
	case '*':
		return num1 * num2;
	case '/':
		return num1 / num2;
	case '^':
		return pow(num1, num2);
	default:
		// If the operator is other than +, -, *, / or "^", error message is shown
		std::cout << "Error! operator is not correct";
		return 0;
	}
}

int main(int argc, char** argv)
{
	if (argc == 1) {
		std::cout << "Basic calculator that current handles the operators +, -, *, and /." << "\n";
		std::cout << "Spaces must be between operators and operands." << "\n";
		std::cout << "Order of operations is not currently supported.";
		std::cout << "The carot (^) for powers must be passed with quotes.";
	} else {

		double num1 = 0;
		double num2;
		char oper;

		stringstream ss(argv[1]);
		ss >> num1;

		for (int i = 2; i < argc; ++i) {
			if (((int)*argv[i] >= 48 and (int)*argv[i] <= 57) or (int)*argv[i] == 46) {
				stringstream ss(argv[i]);
				ss >> num2;
				num1 = calc(num1, num2, oper);
			} else 
				oper = *argv[i];
		}
		std::cout << num1;
	}
	
	return 0;
}

