/*
*	@authors		: Muzaffer Arda Uslu - 152120171007		&&		Gokhan Samet Albayrak - 152120171017
*	@brief			: This code is written to calculate to two long integer multiplication with divide & conquer algorithm.
*					  https://github.com/ardasdasdas/algorithms-and-complexity
*/
#include<iostream>
#include"mathFunctions.h"
using namespace std;
int main() {
	int N;
	string number1, number2, fileName, result;

	cout << "Enter N: ";
	cin >> N;

	cout << "Enter the first file name: ";
	cin >> fileName;
	number1 = fileReader(fileName, N);

	cout << "Enter the second file name: ";
	cin >> fileName;
	number2 = fileReader(fileName, N);

	multiply(number1, number2, result, N);

	fileWriter("result.txt", result);

	system("pause");
}