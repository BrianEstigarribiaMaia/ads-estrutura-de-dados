/*   12. Dadas duas matrizes numéricas A, 5x5, e B, 5x5 criar e imprimir a matriz 
     S, soma de A e B.
*/

#include <stdio.h>
#include <stdlib.h>


main()
{
	int l, c, A[5][5], B[5][5], S[5][5];

	
    for (l=0; l<5; l++)
        for (c=0; c<5; c++)
	        {
            printf("Digite o valor para a Matriz A para a linha %d coluna %d ", l, c);
            scanf ("%d", &A[l][c]);
            printf("Digite o valor para a Matriz B para a linha %d coluna %d ", l, c);
            scanf ("%d", &B[l][c]);
            S[l][c] = A[l][c] + B[l][c];     
	        }


    for (l=0; l<5; l++)
        for (c=0; c<5; c++)
	        {
            printf("O valor da Matriz S na linha %d coluna %d eh: %d\n", l, c, S[l][c]); 
            }
        
    system("pause");    
}          
