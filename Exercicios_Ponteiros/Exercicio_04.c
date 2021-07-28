/*4.	Implementar uma função que calcule a soma e o produto de dois valores inteiros. 
Essa função deve obedecer ao protótipo:

void soma_prod (int a, int b, int *s, int *p); */

#include <stdio.h>
#include <stdlib.h>

void soma_prod(int a, int b ,int* s,int* p)
     {
     *s =a+b;
     *p=a*b;
     }     


main()
  {       
  int a,b,s,p;
  printf("Digite o primeiro numero inteiro\n");
  scanf("%d",&a);
  printf("Digite o segundo numero inteiro\n");
  scanf("%d",&b);
  
  soma_prod(a, b, &s, &p);

  printf("A soma dos numeros eh = %d\nO produto eh = %d\n", s, p);
  system("pause");
  }
