/**********************************************

Escreva uma fun��o que recebe um inteiro N e
retorna o somat�rio de todos os n�meros entre 0
e N

**********************************************/

#include <stdio.h>
#include <stdlib.h>

int soma(int num)
{
    if(num == 1)
        return 1;
    else
        return (num + soma(num-1) );
}

int main(){
	int num;
    printf("Digite numero positivo: ");
    scanf("%d", &num);
 
    printf("Soma: %d\n", soma(num));
    
    system("pause");
    return 0;
}
