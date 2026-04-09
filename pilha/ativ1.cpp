#include <iostream>
#include "efeitos.h"
using namespace std;

class Pilha{
    private:
        int topo;
        int* dados;
        int maximo;
    public:
        //O construtor, ele zera a pilha quando ela nasce
        Pilha(int n) {
            maximo = n;
            topo = -1;
            dados = new int[maximo];
        }

        ~Pilha(){
            delete[]dados;
        }

        void Push(int valor){
            if(topo < maximo - 1){
                topo++;
                dados[topo] = valor;
                cout << "Valor " << valor << " Inserido" << endl;
            }
            else{
                cout << "Pilha Cheia!" << endl;
            }
        }

        void Pop(){
            if(topo >= 0){
                cout << "Removendo: " << dados[topo] << endl;
                topo--;
            }
            else{
                cout << "Pilha Vazia" << endl;
            }
        }

        void ExibirTopo(){
            if(topo >= 0){
                cout << "Topo Atual: " << dados[topo] << endl;
            }
            else{
                cout << "Pilha Vazia." << endl;
            }
        }
        void ExibirPilha(){
            if(topo == -1){
                digitar("Pilha está vazia",10);
            }
            digitar("\n--- EXIBINDO A PILHA (topo para base) ---", 30);
            for(int i = topo; i >= 0; i--){
                string item = "[ " + to_string(dados[i]) + " ]";
                digitar(item,50);
            }
            digitar("---------------------------------------", 20);
        }
        bool estaCheia(){
            return topo == maximo - 1;
        }
};

int main(){
    int tamanhoDesejado;
    digitar("Bem-vindo ao Sistema de Pilha Dinâmica...");
    digitar("Qual o tamanho da pilha que deseja criar? ", 30);
    cin >> tamanhoDesejado;
    digitar("Criando espaço na memória...", 100);
    Pilha minhaPilha(tamanhoDesejado);
    digitar("Pilha pronta!", 20);
    int opcao;
    int valorDesejado;
    int tamanho;
    do{
        digitar("O que deseja fazer?", 10);
        digitar("1 - Empilhar (+)", 5);
        digitar("2 - Desempilhar (-)", 5);
        digitar("3- Acabou (Ver a Pilha e sair)", 5);
        digitar("Opção: ",5);
        cin >> opcao;

        if(opcao == 1){
            digitar("Digite valor que deseja empilhar:", 15);
            cin >> valorDesejado;
            minhaPilha.Push(valorDesejado);
            tamanho++;

            if(minhaPilha.estaCheia()){
                digitar("\nLimite atingido! Encerrando e mostrando a pilha...", 20);
                minhaPilha.ExibirPilha();
                return 0;
            }
        }
        else if(opcao == 2){
            digitar("Valor Desempilhado com sucesso!", 15);
            minhaPilha.Pop();
            tamanho--;
        }
        else if(opcao == 3){
            digitar("Aqui está a Pilha da forma que você pediu: ", 20);
            minhaPilha.ExibirPilha();
            }
        }
    while(opcao != 3);
        minhaPilha.ExibirTopo();
        digitar("Programa Encerrado.", 30);
    return 0;

}