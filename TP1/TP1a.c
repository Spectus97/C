#include <stdio.h>

int main(void)
{
	int i;
	int x = 1;
	for(i = 0; i < 10; i++){
		printf("2 puissance %d = %d \n", i,x);
		x = x*2;
	}
	return 0;
}
