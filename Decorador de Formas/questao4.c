#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Faça um algoritmo que leia três notas de um aluno, calcule e escreva a média final deste aluno. Considerar que a média é ponderada e que o peso das notas é 2, 3 e 5. Fórmula para o cálculo da média final é: */

int main()
{
    int nota1,nota2,nota3,media;
    printf("Digite as notas do aluno nas 3 questões");
    scanf("%d", &nota1 );
    scanf("%d", &nota2 );
    scanf("%d", &nota3 );
    media = (nota1 *2 + nota2 *3 + nota3 *5)/10;
    printf("A média final obtida na prova foi = %d", media);

    return 0;
}