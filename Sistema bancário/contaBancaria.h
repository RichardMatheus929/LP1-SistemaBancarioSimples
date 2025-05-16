#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

#include <string>
#include "cliente.h"
using namespace std;

class ContaBancaria {

private:
    int numeroConta;
    double saldoConta;
    Cliente cliente;

public:

    ContaBancaria(int numeroConta, Cliente cliente, double saldoInicial = 0);

    void depositar(double valorDeposito);
    bool sacar(double valor); // Lembrar de verificar se há saldo suficiente
    void transferir(double valor, ContaBancaria& conta);
    void transferir(double valor, ContaBancaria& conta1, ContaBancaria& conta2);
    void exibirSaldo();
    void exibirInformacoes();

};

#endif
