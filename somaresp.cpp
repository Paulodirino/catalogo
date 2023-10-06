#include <iostream>

using namespace std;

struct No {

    int valor, posicao;
    No *prox;

    No() {
        valor = 0;
        prox = NULL;
    }

    No(int _valor, int _posicao) {
        valor = _valor;
        posicao = _posicao;
        prox = NULL;
    }

};

struct Lista {

    No *inicio, *fim;
    int n;

    Lista() {
        inicio = NULL;
        fim = NULL;
        n = 0;
    }

    bool vazia() {
        return inicio == NULL;
    }

    void inserirFinal(int valor, int posicao) {

        n++;
        No *novo = new No(valor, posicao);

        if (vazia()) {
            inicio = novo;
            fim = novo;
            return;
        }

        fim->prox = novo;
        fim = novo;

    }

    void imprimir() {

        No *aux = inicio;

        while (aux != NULL) {
            printf("%d ",aux->valor);
            aux = aux->prox;
        }

        printf("\n");

    }


    int retornaSoma() {
        int numero = 0;
        if (!vazia()) {

            int m = inicio->valor;
            int p = inicio->posicao;
            int valorCorreto[n],cont;
            No *aux = inicio;
            
            cont = 1;    
            while (aux != NULL) {
                valorCorreto[n - cont] = aux->valor;
                aux = aux->prox;
                cont++;
            }
                
            for (int i = 0; i < n; i++) {
                numero = (numero * 10) + valorCorreto[i];
            }
        
        }
        return numero;
    }


};

int somaLista(Lista l1, Lista l2){
    int tl1,tl2;
    tl1 = l1.retornaSoma();
    tl2 = l2.retornaSoma();
    int total = tl1 + tl2;
    return total;
}

int main() {

    Lista l1, l2 ,l3;

    int n, x;

    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        l1.inserirFinal(x, i);
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        l2.inserirFinal(x, i);
    }
    
    int valorSoma = somaLista(l1,l2);
    int arraySoma[n];
    
    int j = 0;
    for (int i = n; i > 0; i--) {
        arraySoma[i] = valorSoma % 10;
        l3.inserirFinal(arraySoma[i], j);
        j++;
        valorSoma /= 10;
    }

    l3.imprimir();
    
    return 0;
}
