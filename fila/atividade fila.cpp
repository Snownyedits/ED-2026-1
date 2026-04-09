#include <iostream> // Feito por Pedro Gabriel Ferreira Costa e Pablo dos Santos Martins
using namespace std;

// Classe do nó
class No {
public:
    int valor;
    No* prox;

    No(int v) {
        valor = v;
        prox = NULL;
    }
};

// Classe da fila
class Fila {
private:
    No* inicio;
    No* fim;

public:
    Fila() {
        inicio = NULL;
        fim = NULL;
    }

    void enfileirar(int valor) {
        No* novo = new No(valor);

        if (fim == NULL) {
            inicio = fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
    }

void imprimir() {
    cout <<endl;
    No* atual = inicio;
    bool primeiro = true;

    while (atual != NULL) {
        if (!primeiro) cout << " ";
        cout << atual->valor;
        atual = atual->prox;
        primeiro = false;
    }
}

    No* getInicio() {
        return inicio;
    }
};

// Mesclar filas
Fila mesclar(Fila &a, Fila &b) {
    Fila resultado;

    No* pa = a.getInicio();
    No* pb = b.getInicio();

    while (pa != NULL and pb != NULL) {
        if (pa->valor <= pb->valor) {
            resultado.enfileirar(pa->valor);
            pa = pa->prox;
        } else {
            resultado.enfileirar(pb->valor);
            pb = pb->prox;
        }
    }

    while (pa != NULL) {
        resultado.enfileirar(pa->valor);
        pa = pa->prox;
    }

    while (pb != NULL) {
        resultado.enfileirar(pb->valor);
        pb = pb->prox;
    }

    return resultado;
}

int main() {
    Fila filaA, filaB;
    char comando;
    bool executando = true;

    while (true) {
    cin >> comando;

    if (comando == 't') {
        cout<<endl;
        return 0;
    }

    if (comando == 'i') {
        char fila;
        int valor;
        cin >> fila >> valor;

        if (fila == 'a') filaA.enfileirar(valor);
        else if (fila == 'b') filaB.enfileirar(valor);

    } else if (comando == 'e') {
        char fila;
        cin >> fila;

        if (fila == 'a') filaA.imprimir();
        else if (fila == 'b') filaB.imprimir();

    } else if (comando == 'm') {
        Fila temp = mesclar(filaA, filaB);
        temp.imprimir();
    }
}

    return 0;
}