#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
using namespace std;

class Cliente {

private:
    string nome;
    string cpf;

public:
    Cliente(); // Contrutor padrão
    Cliente(string nome, string cpf);

    string getNome();
    string getCpf();
};

#endif
