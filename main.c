#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tamanho 10

typedef struct pilha {
    int topo;
    int item[tamanho];
} Pilha;

int inicializa (Pilha *p) {
    (*p).topo = -1;
    return 0;
}

int estado (Pilha p) {
    if (p.topo == -1) {
        return 0; // lista vazia
    } else {
        if (p.topo == tamanho-1) {
            return 1; // pilha cheia
        } else {
            return 2; // pilha com espaço para armazenamento
        }
    }
}

// PUSH
int empilha (Pilha *p, int x) {
    int erro = estado(*p);
    if ((erro == 0) || (erro == 2)) {
        (*p).topo++;
        (*p).item[(*p).topo] = x; // empilhamento feito

        return 0;
    } else {
        return 1; // impossível empilhar
    }
}

// POP
int desempilha (Pilha *p) {
    int erro = estado(*p);
    if (erro != 0) {
        (*p).topo--; // desempilhamento feito

        return 0;
    } else {
        return 1; // impossível desempilhar
    }
}

int lista(Pilha p) {
    int i, erro;
    erro = estado(p);

    if ((erro == 1) || (erro == 2)) {
        for (i = 0; i <= p.topo; i++)
            printf("%d\\ ", p.item[i]);
        printf(" (Topo)\n");

        return 0;
    } else {
        return 1; // impossível listar
    }
}

int obeter_topo (Pilha p, int *dado) {
    int i;

    if (p.topo == -1)
        return 1; // pilha vazia
    else {
        *dado = p.item[p.topo];
        return 0;
    }
}

int main()
{
    int dado, erro;
    Pilha p1;


    inicializa(&p1);

    empilha(&p1, 12);
    empilha(&p1, 54);
    lista(p1);
    obeter_topo(p1, &dado);
    printf("\nValor do topo: %d\n\n", dado);

    empilha(&p1, 948);
    lista(p1);
    obeter_topo(p1, &dado);
    printf("\nValor do topo: %d\n\n", dado);

    desempilha(&p1);
    desempilha(&p1);
    lista(p1);
    obeter_topo(p1, &dado);
    printf("\nValor do topo: %d\n\n", dado);

    empilha(&p1, 34453);
    empilha(&p1, 888);
    empilha(&p1, 5456);
    empilha(&p1, 1);
    lista(p1);

    empilha(&p1, 12);
    empilha(&p1, 45);
    empilha(&p1, 77);
    empilha(&p1, 99);
    empilha(&p1, 2022);
    empilha(&p1, 2045); // elemento não adicionado, pois pilha já está cheia cheia
    lista(p1);

    return 0;
}
