/* 3.	Implementar uma função que calcule a média ponderada de duas notas. 
Essa função deve obedecer ao protótipo:

void media_pond (float n1, float p1, float n2, float p2, float *media); */


#include <stdio.h>
#include <stdlib.h>

void media_pond(float n1, float p1,float n2, float p2,float* media)
     {
     *media =((n1*p1)+(n2*p2))/(p1+p2);
     }     


main()
  {       
  float p1,n1,p2,n2, media;

  printf("Informe a primeira nota\n ");
  scanf("%f",&n1);
  printf("Informe o primeiro peso\n ");
  scanf("%f",&p1);
  printf("Informe a segunda nota\n ");
  scanf("%f",&n2);
  printf("Informe o segundo peso\n ");
  scanf("%f",&p2);
 
  
  media_pond(n1, p1, n2, p2, &media);

  printf("A media ponderada eh %f \n", media);
  system("pause");
  }
