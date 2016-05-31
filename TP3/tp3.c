#include <stdio.h>
#include <ctype.h>

int main(void){
	
	printf("%d \n", length("test"));
	printf("%d \n", wc("test test test"));
}

int length(char s[]){
	int cpt = 0;
	while(s[cpt] != 0){
		cpt++;
	}	
	return cpt;
}

int wc(char s[]){
	int cpt = 0;
	int cpt2= 1;
	while(cpt < length(s)){
		if(cpt != 0 && isalnum(s[cpt]) != 0 && isalnum(s[cpt-1]) == 0){
			cpt2++;
		}
		cpt++;
	}
	return cpt2;
}

int scan_string(char s[MAX]){
	
}
