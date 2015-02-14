#include <stdio.h>

void function(int a, int b, int c)
{
	char buffer1[5] = {'A','A', 'A', 'A', 'A'};
	char buffer2[10] = { 'B','B','B','B','B','B','B','B','B','B'};
	int *ret;

	ret = buffer2 + 26;
	(*ret) += 8;
}

void main()
{
	int x = 0;
	function(1, 2, 3);
	x = 1;
	printf("%d\n",x);
}
