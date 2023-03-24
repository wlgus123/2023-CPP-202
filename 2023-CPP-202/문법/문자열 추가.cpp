// C
#include <stdio.h>
#include <string.h>

// C++
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	char str1[30] = "Jiwoo";
	char str2[30] = "Rock";

	const int s1_len = strlen(str1);
	const int s2_len = strlen(str2);

	for (int i = s1_len; i < s1_len + s2_len; i++) {
		str1[i] = str2[i - s1_len];
	}
	str1[s1_len + s2_len] = '\0';
	
	printf("%s \n", str1);
	
	return 0;
}