#ifndef _CONJUNTO_H_
#define _CONJUNTO_H_

typedef enum _bool{
    FALSE,
    TRUE
}BOOL;

typedef struct _elemento{
    int valor;
    struct _elemento *ant, *prox;
}ELEMENTO;

typedef struct _listaConj{
    ELEMENTO *inicio, *fim;
    int tam;
}CONJUNTO;

//Funções do Conjunto
void alocaConjunto(CONJUNTO *conj);
void imprimeConjunto(CONJUNTO *conj, int i);
void insereElemConjunto(CONJUNTO *conj, int valor);
void removePrimeiroElemConjunto(CONJUNTO *conj);
void removeElemConjunto(CONJUNTO *conj, int valor);

/*  Conj1 = Conjunto Principal
*   Conj2 = Conjunto Secundário */
CONJUNTO *uneConjuntos(CONJUNTO conj1, CONJUNTO conj2);
CONJUNTO *interseccaoConjuntos(CONJUNTO conj1, CONJUNTO conj2);
CONJUNTO *diferencaConjuntos(CONJUNTO conj1, CONJUNTO conj2);
BOOL contidoNoConjunto(CONJUNTO conj1, CONJUNTO conj2);
BOOL igualConjunto(CONJUNTO conj1, CONJUNTO conj2);
BOOL elemPertenceConjunto(CONJUNTO conj1, ELEMENTO elem);

#endif // _CONJUNTO_H_
