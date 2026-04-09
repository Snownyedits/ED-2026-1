#ifndef EFEITOS_H
#define EFEITOS_H

#include <iostream>
#include <string>
#include <thread> // Necessário para o sleep (pausa)
#include <chrono> // Necessário para definir o tempo (ms)

using namespace std;

// Função que recebe o texto e o tempo de espera entre letras
void digitar(string texto, int velocidade = 50) {
    for (char c : texto) {
        cout << c << flush; // O 'flush' força o caractere a aparecer na tela NA HORA
        
        // Faz o programa "dormir" por X milissegundos
        this_thread::sleep_for(chrono::milliseconds(velocidade));
    }
    cout << endl; // Pula linha no final
}

#endif