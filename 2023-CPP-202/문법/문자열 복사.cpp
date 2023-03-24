#include <stdio.h>

int main(void)
{
	char str1[30] = "";
	char str2[30] = "Jiwoo";

	for (int i = 0; str2[i] != '\0'; i++) {
		str1[i] = str2[i];
	}

	printf("%s \n", str1);

	return 0;
}