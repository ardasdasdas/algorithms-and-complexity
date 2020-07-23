#pragma once
#include<string>
#include<fstream>
#include<algorithm>
using namespace std;
/*
*	@brief			: This function converts a character to integer.
*	@param			: Function has a parameter in char form.
*	@return			: Function returns a  integer.
*/
int fromCharacterToInteger(char character)//function of converting character to integer.
{
	return character % 48;//0 of integer is 48 in ascii table.
}
/*
*	@brief			: This function sums.
*	@param			: Function has two parameter in string form.
*	@return			: Function returns a string.
*/
string addition(string number1, string number2)
{
	int length = max(number1.length(), number2.length());
	int sum_col;
	string addition;
	int sumOfDigits;
	int plus = 0;
	while (number1.length() < length)
		number1.insert(0, "0");

	while (number2.length() < length)
		number2.insert(0, "0");

	for (int i = length - 1; i >= 0; i--) {
		sumOfDigits = fromCharacterToInteger(number1[i]) + fromCharacterToInteger(number2[i]) + plus;//use the function of from_character_to_number
		plus = 0;// reset the plus

		if (sumOfDigits > 9 && i != 0)
		{
			plus = 1;
			sumOfDigits %= 10;
		}
		//if sum of 2 integer is with 2 digits, print only units digit and add one to the next number.

		addition.insert(0, to_string(sumOfDigits));
	}
	return addition;
}
/*
*	@brief			: This operator function subtracts.
*	@param			: Function has two parameter in string form.
*	@return			: Function returns a string.
*/
string operator-(string number1, string number2) {
	int length = max(number1.length(), number2.length());
	int difference = 0;
	int differenceOfDigits;
	string subtraction;

	while (number1.length() < length)
		number1.insert(0, "0");

	while (number2.length() < length)
		number2.insert(0, "0");

	for (int i = length - 1; i >= 0; i--) {
		differenceOfDigits = fromCharacterToInteger(number1[i]) - fromCharacterToInteger(number2[i]) + difference;
		difference = 0;//reset the difference

		if (differenceOfDigits < 0)
		{
			differenceOfDigits += 10;
			difference = -1;
		}
		//if difference of 2 integer is smaller than 0, add 10 diggerence of digits, print only units digit and add 1 to the next number.

		subtraction.insert(0, to_string(differenceOfDigits));
	}
	return subtraction;
}
/*
*	@brief			: This function does fast divide and conquer multiplication.
*	@param			: Function has four parameter. Parameters of first three are in string form. The last one is in integer form.
*/
void multiply(string firstNumber, string secondNumber, string& result, int N) {
	string C, D, E;
	int l1 = firstNumber.length(), l2 = secondNumber.length();
	if (l1 > l2) {
		for (int i = 0; i < l1 - l2; i++)
			secondNumber = "0" + secondNumber;
		N = l1;
	}
	else
	{
		for (int i = 0; i < l2 - l1; i++)
			firstNumber = "0" + firstNumber;
		N = l2;
	}
	if (N == 1) {
		result = to_string((fromCharacterToInteger(firstNumber[0])) * (fromCharacterToInteger(secondNumber[0])));
		return;
	}
	string WmstSgnfcntDgtsOfFrstNmbr, XlstSgnfcntDgtsOfFrstNmbr = "", YmstSgnfcntDgtsOfScndNmbr = "", ZlstSgnfcntDgtsOfScndNmbr = "";

	WmstSgnfcntDgtsOfFrstNmbr = firstNumber.substr(0, floor(N / 2));
	XlstSgnfcntDgtsOfFrstNmbr = firstNumber.substr(ceil(N / 2), N);
	YmstSgnfcntDgtsOfScndNmbr = secondNumber.substr(0, floor(N / 2));
	ZlstSgnfcntDgtsOfScndNmbr = secondNumber.substr(ceil(N / 2), N);

	multiply(WmstSgnfcntDgtsOfFrstNmbr, YmstSgnfcntDgtsOfScndNmbr, C, ceil(N / 2));
	multiply(XlstSgnfcntDgtsOfFrstNmbr, ZlstSgnfcntDgtsOfScndNmbr, D, ceil(N / 2));
	multiply(addition(WmstSgnfcntDgtsOfFrstNmbr, XlstSgnfcntDgtsOfFrstNmbr), addition(YmstSgnfcntDgtsOfScndNmbr, ZlstSgnfcntDgtsOfScndNmbr), E, ceil(N / 2));
	E = E - C - D;
	for (int i = 0; i < 2 * ceil(N / 2.); i++) {
		C.append("0");
	}
	for (int i = 0; i < ceil(N / 2.); i++) {
		E.append("0");
	}
	result = addition(C, addition(D, E));
}
/*
*	@brief			: This function read values from a file.
*	@param			: Function has two parameter. First is string form, second is integer form.
*	@return			: Function returns a string.
*/
string fileReader(string fileName, int N) {
	char digit;
	string number = "";
	ifstream file;
	file.open(fileName, ios::in);
	if (file.is_open()) {
		for (int i = 0; i < N; i++) {
			file >> digit;
			number.insert(i, to_string(digit - '0'));
		}
		file.close();
		return number;
	}
	else {
		cout << fileName << " couldn't open!" << endl;
		return "";
	}
}
/*
*	@brief			: This function read values from a file.
*	@param			: Function has two parameter in string form.
*/
void fileWriter(string fileName, string result) {
	ofstream file;
	file.open(fileName, ios::out);
	if (file.is_open()) {
		file << result;
		file.close();
	}
	else {
		cout << fileName << " couldn't open!" << endl;
		return;
	}
}
