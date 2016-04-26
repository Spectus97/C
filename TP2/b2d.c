#include <stdio.h>

int main(void){
  b2d();

  return  0;
}

int b2d(){
  char valeur[20];
  do{
    printf("Entrez un nombre binaire : ");
    scanf("%s", valeur);
  }while(estBinaire(valeur));
  
    int i = sizeof(valeur);
    while(i > 0){
      if(valeur[i] == 1){
	printf("a");
      }else if(valeur[i] == 0){
	printf("b");
      }
      
      i--;
    }
    
    printf("Vous avez entrer : %s \n", valeur);
}

int estBinaire(char val[]){
  int i = 0;
  for(i=0; i < sizeof(val); i++){
    if(val[i] != "0" && val[i] != "1"){
      return 1;
    }
  }

  return 0;
}
