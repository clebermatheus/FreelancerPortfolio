#ifndef _CONJUNTO_H_
#define _CONJUNTO_H_

typedef struct _elemento{
    int valor;
    struct _elemento *ant, *prox;
}ELEMENTO;

typedef struct _listaConj{
    ELEMENTO *inicio, *fim;
    int tam;
}CONJUNTO;

//typedef struct _conjunto{
//    LISTACONJ conj[2];
//}CONJUNTO;

////Funções da Lista
//void alocaLista(LISTACONJ *lista);
//void imprimeLista(LISTACONJ *lista);
//void insereElemLista(LISTACONJ *lista, ELEMENTO elem);
//void removeElemLista(LISTACONJ *lista, ELEMENTO elem);

//Funções do Conjunto
void alocaConjunto(CONJUNTO *conj);
void imprimeConjunto(CONJUNTO *conj);
void insereElemConjunto(CONJUNTO conj, int valor);
void removeElemConjunto(CONJUNTO conj, int valor);

/*  Conj1 = Conjunto Principal
*   Conj2 = Conjunto Secundário */
CONJUNTO uneConjuntos(CONJUNTO conj1, CONJUNTO conj2);
CONJUNTO interseccaoConjuntos(CONJUNTO conj1, CONJUNTO conj2);
CONJUNTO diferencaConjuntos(CONJUNTO conj1, CONJUNTO conj2);
int contidoNoConjunto(CONJUNTO conj1, CONJUNTO conj2);
int igualConjunto(CONJUNTO conj1, CONJUNTO conj2);
int elemPertenceConjunto(CONJUNTO conj1, ELEMENTO elem);

#endif // _CONJUNTO_H_
