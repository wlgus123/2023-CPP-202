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

	const int s1_l = strlen(str1);
	const int s2_l = strlen(str2);

	// s1_1과 s2_l 중 최소값
	const int l = s1_l < s2_l ? s1_l : s2_l;

	int i = 0;
	while (i < l) {
		if (str1[i] > str2[i]) {
			printf("str1 > str2");
			break;
		}
		else if (str1[i] < str2[i]) {
			printf("str1 < str2");
			break;
		}
		i++;
	}
	if (i == l) {
		if (s1_l > s2_l) {
			printf("str1 > str2");
		}
		else if (s1_l < s2_l) {
			printf("str1 < str2");
		}
		else {
			printf("str1 == str2");
		}
	}
	

	return 0;
}