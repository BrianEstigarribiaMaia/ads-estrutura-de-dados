/* 4.	Faça um algoritmo que leia três notas de um número indeterminado de alunos. Calcule e mostre:
   a.	A média de cada aluno;
   b.	O total de alunos reprovados;
   c.	O total de alunos aprovados
   d.	A média da turma
   Obs.:	Considere média >= 6 aprovados e caso contrário reprovados. 
 */

#include <stdio.h>
#include <stdlib.h>

main()
{
   int qtd_alun=0, qtd_apr=0, qtd_repr=0;
   float n1, n2, n3, media_alun, media_ger;
   
   printf("Digite na nota 1 o valor -1 para sair do programa\n");
   
   printf("Digite a nota 1 do aluno\n");
   scanf("%f", &n1);
   
   while (n1!= -1) {
       printf("Digite a nota 2 do aluno\n");
       scanf("%f", &n2);
       printf("Digite a nota 3 do aluno\n");
       scanf("%f", &n3);
       media_alun = (n1+n2+n3)/3;
       if (media_alun >=6)
          qtd_apr++;
       else
           qtd_repr++;
       media_ger = media_ger + media_alun;
       qtd_alun++;
       printf("A media do aluno eh: %.2f \n", media_alun);
       
       printf("Digite a nota 1 do aluno\n");
       scanf("%f", &n1);
       }   
   printf("A quantidade de alunos aprovados eh: %d \n", qtd_apr);
   printf("A quantidade de alunos reprovados eh: %d \n", qtd_repr);
   printf("A media geral dos alunos eh: %.2f \n", media_ger/qtd_alun);
   system ("pause");
}
