#include "calcsum.h"
 
int main()
{
	int a, b, res;
	fscanf(stdin, "%d %d", &a, &b);
	res = calc_sum(a ,b);
	printf("%d\n", res);
	return 0;
}
