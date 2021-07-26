/*   13. Faça um algoritmo que leia uma matriz de 20 X 15 de inteiros. 
     Calcule e mostre a soma das linhas pares da matriz.
*/

#include <stdio.h>
#include <stdlib.h>


main()
{
	int l, c, M[20][15], S[10];

	
    for (l=0; l<20; l++)
        {
        S[l] = 0;
        for (c=0; c<15; c++)
	        {
            printf("Digite o valor para a Matriz para a linha %d coluna %d ", l, c);
            scanf ("%d", &M[l][c]);
            if (l % 2 == 0)
               S[l] = S[l] + M[l][c];     
	        }
         }
         
    for (l=0; l<10; l++)
        {
        if (l % 2 == 0)      
           printf ("A soma da linha %d eh: %d\n",l,S[l]);
        }
        
    system("pause");    
}          
