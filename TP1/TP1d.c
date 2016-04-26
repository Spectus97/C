#include <stdio.h>

int incr(int t[8]){
	int i = 0;
	
	for(i = 0; i < 8;i++){
		if(t[i] == 0){
			t[i] = 1;
			return -1;	
		}else{
			t[i] = 0;
		}
	}

	return 0;
}
