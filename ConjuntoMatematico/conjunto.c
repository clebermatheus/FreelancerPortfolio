#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"

void alocaConjunto(CONJUNTO *conj){
    conj->tam = 100;
    conj->inicio = NULL;
    conj->fim = NULL;
}

void imprimeConjunto(CONJUNTO *conj, int i){
    ELEMENTO *temp = conj->inicio;

    printf("Conjunto %d: {", i);
    while(temp->prox!=NULL){
        printf("%d", temp->valor);
        if(temp!=conj->fim){
            printf(", ");
        }
        temp = temp->prox;
    }
    printf("%d}\r\n\r\n", conj->fim->valor);
}

void insereElemConjunto(CONJUNTO *conj, int valor){
    ELEMENTO *elem = malloc(sizeof(ELEMENTO));

    elem->valor = valor;
    elem->ant = NULL;
    elem->prox = NULL;

    if(conj->inicio==NULL){
        conj->inicio = elem;
        conj->fim = elem;
    }
    else{
        ELEMENTO *temp = conj->inicio;
        while(temp->prox!=NULL && elem->valor!=temp->valor){
            if(elem->valor==temp->valor){
                return;
            }
            temp = temp->prox;
        }
        if(elem->valor!=temp->valor){
            if(temp->prox!=NULL){
                temp->prox->ant = elem;
                elem->prox = temp->prox;
            }
            else{
                conj->fim = elem;
            }
            temp->prox = elem;
            elem->ant = temp;
        }
    }
}

void removePrimeiroElemConjunto(CONJUNTO *conj){
    ELEMENTO *inicio = conj->inicio;

    conj->inicio->prox->ant = NULL;
    conj->inicio = conj->inicio->prox;

    free(inicio);
    inicio = NULL;
}

void removeElemConjunto(CONJUNTO *conj, int valor){
    ELEMENTO *temp = conj->inicio;

    while(temp->valor!=valor && temp->prox!=NULL){
        temp = temp->prox;
    }
    if(temp->valor==valor){
        if(temp->ant!=NULL){
            temp->ant->prox = temp->prox;
        }
        temp->prox->ant = temp->ant;
        if(temp==conj->inicio){
            conj->inicio = conj->inicio->prox;
        }
        if(temp==conj->fim){
            conj->fim = conj->fim->ant;
        }
        free(temp);
        temp = NULL;
    }
}

CONJUNTO *uneConjuntos(CONJUNTO conj1, CONJUNTO conj2){
    CONJUNTO uniao;
    ELEMENTO *temp = conj1.inicio;

    alocaConjunto(&uniao);
    while(temp!=NULL){
        insereElemConjunto(&uniao, temp->valor);
        temp = temp->prox;
    }
    temp = conj2.inicio;
    while(temp!=NULL){
        insereElemConjunto(&uniao, temp->valor);
        temp = temp->prox;
    }

    return &uniao;
}

CONJUNTO *interseccaoConjuntos(CONJUNTO conj1, CONJUNTO conj2){
    CONJUNTO interseccao;
    ELEMENTO *temp1 = conj1.inicio, *temp2 = conj2.inicio;

    alocaConjunto(&interseccao);
    while(temp1!=NULL){
        while(temp2!=NULL){
            if(temp1->valor==temp2->valor){
                insereElemConjunto(&interseccao, temp1->valor);
                break;
            }
            temp2 = temp2->prox;
        }
        temp1 = temp1->prox;
    }

    return &interseccao;
}

CONJUNTO *diferencaConjuntos(CONJUNTO conj1, CONJUNTO conj2){
    CONJUNTO diferenca;
    ELEMENTO *temp1 = conj1.inicio, *temp2;

    alocaConjunto(&diferenca);
    while(temp1!=NULL){
        insereElemConjunto(&diferenca, temp1->valor);
        temp1 = temp1->prox;
    }
    temp1 = conj1.inicio;
    while(temp1!=NULL){
        temp2 = conj2.inicio;
        while(temp2!=NULL){
            if(temp1->valor==temp2->valor){
                removeElemConjunto(&diferenca, temp1->valor);
                break;
            }
            temp2 = temp2->prox;
        }
        temp1 = temp1->prox;
    }

    return &diferenca;
}

BOOL contidoNoConjunto(CONJUNTO conj1, CONJUNTO conj2){
    BOOL isContido = FALSE;
    int i = 0, cont = 0;
    ELEMENTO *temp1 = conj1.inicio, *temp2 = conj2.inicio;

    while(temp2->prox!=NULL){
        i++;
        while(temp1->prox!=NULL){
            if(temp1->valor==temp2->valor){
                cont++;
            }
            temp1 = temp1->prox;
        }
        temp2 = temp2->prox;
    }
    if(cont==i){
        isContido = TRUE;
    }

    return isContido;
}

BOOL igualConjunto(CONJUNTO conj1, CONJUNTO conj2){
    BOOL isIgual = FALSE;
    int i = 0, cont = 0;
    ELEMENTO *temp1 = conj1.inicio, *temp2 = conj2.inicio;

    while(temp1->prox!=NULL){
        i++;
        while(temp2->prox!=NULL){
            if(temp1->valor==temp2->valor){
                cont++;
            }
            temp2 = temp2->prox;
        }
        temp1 = temp1->prox;
    }
    if(cont==i){
        isIgual = TRUE;
    }

    return isIgual;
}

BOOL elemPertenceConjunto(CONJUNTO conj1, ELEMENTO elem){
    BOOL isPertence = FALSE;
    ELEMENTO *temp = conj1.inicio;

    while(temp->prox!=NULL){
        if(temp->valor==elem.valor){
            isPertence = TRUE;
            break;
        }
        temp = temp->prox;
    }

    return isPertence;
}
