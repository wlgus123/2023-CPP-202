#include <stdio.h>

int main(void)
{
	for (int i = 2; i <= 9; i++)
	{
		printf("%d X 1 = %d\n", i, i * 1);
		printf("%d X 2 = %d\n", i, i * 2);
		printf("%d X 3 = %d\n", i, i * 3);
		printf("%d X 4 = %d\n", i, i * 4);
		printf("%d X 5 = %d\n", i, i * 5);
		printf("%d X 6 = %d\n", i, i * 6);
		printf("%d X 7 = %d\n", i, i * 7);
		printf("%d X 8 = %d\n", i, i * 8);
		printf("%d X 9 = %d\n", i, i * 9);
	}

	return 0;
}