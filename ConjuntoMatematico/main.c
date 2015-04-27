#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"

//Esta Área pode ser personalizada de acordo com a sua escolha, dependendo somente
//se deseja no terminal ou com interface gráfica.
int main(){
    BOOL cont = FALSE;
    CONJUNTO conj1, conj2;
    ELEMENTO *elem = malloc(sizeof(ELEMENTO));
    int escolha = 0, valor = 0;

    alocaConjunto(&conj1);
    alocaConjunto(&conj2);
    elem->ant = NULL;
    elem->prox = NULL;

    do{
        printf("Sistema de Calculo de Conjuntos Matematicos Inteiros\r\n\r\n"
               "0 - Sair do Programa\r\n"
               "1 - Para Inserir Elemento nos Conjunto 1\r\n"
               "2 - Para Inserir Elemento nos Conjunto 2\r\n"
               "3 - Para Remover Elemento nos Conjunto 1\r\n"
               "4 - Para Remover Elemento nos Conjunto 2\r\n"
               "5 - Imprimir o Conjunto 1\r\n"
               "6 - Imprimir o Conjunto 2\r\n"
               "7 - Calcular e imprimir a Uniao entre os conjuntos\r\n"
               "8 - Calcular e imprimir a Interseccao entre os conjuntos\r\n"
               "9 - Calcular e imprimir a Diferenca entre os conjuntos\r\n"
               "10 - Calcular e imprimir se o Conjunto 1 esta contido no Conjunto 2\r\n"
               "11 - Calcular e imprimir se o Conjunto 2 esta contido no Conjunto 1\r\n"
               "12 - Calcular e imprimir se os Conjuntos são Iguais\r\n"
               "13 - Calcular e imprimir se um dado elemento pertence ao Conjunto 1\r\n"
               "14 - Calcular e imprimir se um dado elemento pertence ao Conjunto 2\r\nDigite: ");
        scanf("%d", &escolha);
        switch(escolha){
        case 1:
            printf("Digite o Elemento: ");
            scanf("%d", &valor);
            insereElemConjunto(&conj1, valor);
            break;
        case 2:
            printf("Digite o Elemento: ");
            scanf("%d", &valor);
            insereElemConjunto(&conj2, valor);
            break;
        case 3:
            printf("Digite o Elemento: ");
            scanf("%d", &valor);
            removeElemConjunto(&conj1, valor);
            break;
        case 4:
            printf("Digite o Elemento: ");
            scanf("%d", &valor);
            removeElemConjunto(&conj2, valor);
            break;
        case 5:
            imprimeConjunto(&conj1, 1);
            break;
        case 6:
            imprimeConjunto(&conj2, 2);
            break;
        case 7:
            imprimeConjunto(uneConjuntos(conj1, conj2), 3);
            break;
        case 8:
            imprimeConjunto(interseccaoConjuntos(conj1, conj2), 3);
            break;
        case 9:
            imprimeConjunto(diferencaConjuntos(conj1, conj2), 3);
            break;
        case 10:
            cont = contidoNoConjunto(conj2, conj1);
            switch(cont){
            case FALSE:
                printf("Conjunto 1 nao esta contido em 2!\r\n");
                break;
            case TRUE:
                printf("Conjunto 1 esta contido em 2!\r\n");
                break;
            }
            break;
        case 11:
            cont = contidoNoConjunto(conj1, conj2);
            switch(cont){
            case FALSE:
                printf("Conjunto 2 nao esta contido em 1!\r\n");
                break;
            case TRUE:
                printf("Conjunto 2 esta contido em 1!\r\n");
                break;
            }
            break;
        case 12:
            cont = igualConjunto(conj1, conj2);
            switch(cont){
            case FALSE:
                printf("Conjunto 1 nao e igual a 2!\r\n");
                break;
            case TRUE:
                printf("Conjunto 1 e igual a 2!\r\n");
                break;
            }
            break;
        case 13:
            printf("Digite o Elemento: ");
            scanf("%d", &valor);
            elem->valor = valor;
            cont = elemPertenceConjunto(conj1, *elem);
            switch(cont){
            case FALSE:
                printf("Elemento %d nao pertence ao Conjunto 1!\r\n", elem->valor);
                break;
            case TRUE:
                printf("Elemento %d pertence ao Conjunto 1!\r\n", elem->valor);
                break;
            }
            break;
        case 14:
            printf("Digite o Elemento: ");
            scanf("%d", &valor);
            elem->valor = valor;
            cont = elemPertenceConjunto(conj2, *elem);
            switch(cont){
            case FALSE:
                printf("Elemento %d nao pertence ao Conjunto 2!\r\n", elem->valor);
                break;
            case TRUE:
                printf("Elemento %d pertence ao Conjunto 2!\r\n", elem->valor);
                break;
            }
            break;
        }
    }while(escolha!=0);

    return 0;
}
