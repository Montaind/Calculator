#include <iostream>
#include <stack>
#include <string>
using namespace std;



int main()
{
	setlocale(LC_ALL, "RUS");
	stack<char> st;

	bool first = false;
	bool first_end = false;
	bool second = false;
	char action = 0;
	double first_n;
	double second_n;
	double first_buffer = 0;
	double second_buffer = 0;
	double result;
	string str;

	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			if (first_end) {
				second = true;
				second_n = str[i] - 48;
				second_buffer = (second_buffer * 10) + second_n;
			}
			else {
				first = true;
				first_n = str[i] - 48;
				first_buffer = (first_buffer * 10) + first_n;
			}

		}
		else
		if (str[i] == '+') {
			first_end = true;
			action = '+';
		}
		else
		if (str[i] == '-') {
			first_end = true;
			action = '-';
		}
		else 
		if (str[i] == '*') {
			first_end = true;
			action = '*';
		}
		else if (str[i] == '/') {
			first_end = true;
			action = '/';
		}
	}
	if (first && action && second) {
		if (action == '+') {
			result = first_buffer + second_buffer;
		}
		else if (action == '-') {
			result = first_buffer - second_buffer;
		}
		else if (action == '*') {
			result = first_buffer * second_buffer;
		}
		else if (action == '/') {
			result = first_buffer / second_buffer;
		}
	}
	cout << result;
}