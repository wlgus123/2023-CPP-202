// C
#include <stdio.h>
#include <string.h>

// C++
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	char str1[50] = "Hello";
	char str2[50] = "World";

	// 문자열비교 (인자의 순서와 반환값이 헷갈려)
	int result = strcmp(str1, str2);

	if (result == 0) {
		printf("str1 == str2");
	}
	else if (result == -1) {
		printf("str1 < str2");
	}
	else if (result == 1) {
		printf("str1 > str2");
	}
	

	return 0;
}