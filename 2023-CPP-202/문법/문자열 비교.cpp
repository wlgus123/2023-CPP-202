// C
#include <stdio.h>
#include <string.h>

// C++
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str1 = "Hello";
	string str2 = "World";

	if (str1 == str2) {
		cout << "str1 == str2";
	}
	// str2가 str1보다 사전에 늦게나오는 경우
	else if (str1 < str2) {
		cout << "str1 < str2";
	}
	else {
		cout << "str1 > str2";
	}
	
	return 0;
}