#include <stdio.h>

int incr(int t[8]){
	int i = 7;
	
	while(i > 0){
		if(t[i] == 0){
			t[i] = 1;
			return 0;	
		}else{
			t[i] = 0;
			i--;
		}
	}

	return 0;
}
