/*
	Exemplo de uso de ponteiros com uma função de troca entre valores
*/

#include <stdio.h>
#include <stdlib.h>

void Swap(int *a, int *b){
	 int temp = *a;
	 *a = *b;
	 *b = temp;
}

int main(){
	 int num1 = 100;
	 int num2 = 200;
	 
	 Swap(&num1,&num2);
	 
	 printf("agora eles valem %d %d",num1,num2);

	 system("pause");
	 return 0;	 
}
