#include <iostream>
using namespace std;

class Noh{
    public:
        int valor;
        Noh* proximo;

        //Construtor
        Noh(int v){
            valor = v;
            proximo = nullptr;
        }
};

class Fila{
    private:
        Noh* frente;
        Noh* tras;
    public:
        Fila(){
            frente = nullptr;
            tras = nullptr;
        }

        bool vazia(){
            if(frente == nullptr){
                return true;
            }
            else{
                return false;
            }
        }

}