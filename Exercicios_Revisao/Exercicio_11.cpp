/*   11. Escrever um algoritmo que lê uma matriz M(5,5) e cria 2 vetores SL(5) e SC(5) 
    que contenham, respectivamente, as somas das linhas e das colunas de M. Escrever a matriz 
    e os vetores criados.
*/

#include <stdio.h>
#include <stdlib.h>


main()
{
	int l, c, M[5][5], SL[5], SC[5];

	
    for (l=0; l<5; l++)
        {
        SL[l] = 0;
        for (c=0; c<5; c++)
	        {
            printf("Digite o valor para a linha %d coluna %d ", l, c);
            scanf ("%d", &M[l][c]);
            SL[l] = SL[l] + M[l][c];     
	        }
        }



    for (c=0; c<5; c++) 
        {
        SC[c] = 0;
        for (l=0; l<5; l++)
	         { 
             SC[c] = SC[c] + M[l][c];     
             }
         }

    for (c=0; c<5; c++)
        {
        printf ("A soma da linha %d eh: %d\n",c,SL[c]);
        printf ("A soma da coluna %d eh: %d\n",c,SC[c]);
        }          
    system("pause");    
}          
