#include "cliente.h"

Cliente::Cliente() {
    this->nome = "";
    this->cpf = "";
}

Cliente::Cliente(string nome, string cpf) {
    this->nome = nome;
    this->cpf = cpf;
}

string Cliente::getNome() {
    return this->nome;
}

string Cliente::getCpf() {
    return this->cpf;
}



