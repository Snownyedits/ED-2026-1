#include <iostream>
using namespace std;

class Noh {
    public:
        int valor;
        Noh* proximo; 

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

        //insere no fim(push)
        void enfileirar(int v){
            if(!vazia() && tras->valor == v){
                return;
            }
            //1. Criar o novo nó na memória
            Noh* novo = new Noh(v);
            //2. Verificar se a fila está vazia
            if(vazia()){
            //Lógica : se vazio, frente/trás apontam pra ele
                frente = novo;
                tras = novo;
            }
            else{
            //Se não, tras->proximo aponta pro novo e atualiza o tras.
                tras->proximo = novo;
                tras = novo;
            }

        }

        //Remove do início(Pop)
        int desenfileirar(){
            if(vazia()){
                return -1;
            }
            //Guarda o valor que está saindo para retornar depois
            int valorSaindo = frente->valor;
            //Cria um ponteiro temporário para o nó que vai ser deletado
            Noh* temp = frente;
            //Mover a frente da fila para o próximo nó
            frente = frente->proximo;
            //Caso a fila tenha ficado vazia, o tras agora também deve ser null
            if(frente == nullptr){
                tras = nullptr;
            }

            //Deleta o nó da memória para evitar Memory Leak
            delete temp;
            
            return valorSaindo;
        }
        //Checa se está vazia
        bool vazia(){
            //Se a frente for NULL (nullptr), significa que não há nenhum nó na fila
            if(frente == nullptr){
                return true;
            }
            else{
                return false;
            }
        }

        //Apenas o primeiro valor sem remover (front)
        int espiar(){
            if(!vazia()){
                return frente->valor;
                
            }
        return -1;
        }
};

int main(){
    Fila fila1, fila2, resultado;
    int n1, n2, valor;

    //Leitura da fila 1
    cin >> n1;
    for(int i = 0; i < n1; i++){
        cin >> valor;
        fila1.enfileirar(valor);
    }

    //Leitura da fila 2
    cin >> n2;
    for(int i = 0; i < n2; i++){
        cin >> valor;
        fila2.enfileirar(valor);
    }

    //
    while(!fila1.vazia() || !fila2.vazia()){
        int valorEscolhido;
        //Caso 1: A Fila acabou, então só resta tirar da fila 2
        if(fila1.vazia()){
            valorEscolhido = fila2.desenfileirar();
        }
        else if(fila2.vazia()){
            valorEscolhido = fila1.desenfileirar();
        }
        else{
            int v1 = fila1.espiar();
            int v2 = fila2.espiar();

            if(v1 < v2){
                valorEscolhido = fila1.desenfileirar();
            }
            else if(v2 < v1){
                valorEscolhido = fila2.desenfileirar();
            }
            else{
                //valores iguais : tira de ambas, mas só usa um
                valorEscolhido = fila1.desenfileirar();
                fila2.desenfileirar();
            }
        }
        resultado.enfileirar(valorEscolhido);
    }

    // Impressão dos resultados
    bool primeiro = true;
    while(!resultado.vazia()){
        if(!primeiro){
            cout << " ";
        }
        cout << resultado.desenfileirar(); 
        primeiro = false;
    }
    cout << endl;
    return 0;
}
