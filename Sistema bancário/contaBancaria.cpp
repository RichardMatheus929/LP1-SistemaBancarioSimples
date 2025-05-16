#include "contaBancaria.h"

#include <iostream>
#include <iomanip>
using namespace std;

// Contrutor
ContaBancaria::ContaBancaria(int numeroConta, Cliente cliente, double saldoInicial) {
    this->numeroConta = numeroConta;
    this->cliente = cliente;
    if (saldoInicial > 0) { // Só adiciona saldo inicial se ele for maior que 0
        this->saldoConta = saldoInicial;
    }
    else {
        this->saldoConta = 0;
    }
};

void ContaBancaria::depositar(double valorDeposito) {
    this->saldoConta += valorDeposito;
};

// O retorno booleano permite eu usar essa função na funcionalidade de transferir
// Talvez sacar não seja o melhor nome mas irei manter para não prejudicar a correção da atv.
bool ContaBancaria::sacar(double valor) {
    if (valor > this->saldoConta) {
        cout << "Você não tem saldo";
        return false;
    }
    else {
        this->saldoConta = this->saldoConta - valor;
        return true;
    }
};

void ContaBancaria::transferir(double valor, ContaBancaria& conta) {
    if (this->sacar(valor)){
        conta.depositar(valor);
    }

    cout << "Transferido " << valor << " para a conta " << conta.numeroConta << endl;
};

void ContaBancaria::transferir(double valor, ContaBancaria& conta1, ContaBancaria& conta2) {

    valor = valor / 2; // Assim eu divido o valor de transferência para as duas contas

    if (this->sacar(valor)) {
        conta1.depositar(valor);
    }

    if (this->sacar(valor)) {
        conta2.depositar(valor);
    }

    cout << "Transferido " << valor << " para as contas (" << conta1.numeroConta << "," << conta2.numeroConta << ")" << endl;
};

void ContaBancaria::exibirSaldo() {
    cout << "O saldo do cliente " << this->cliente.getNome() << " é: " << this->saldoConta << endl;
};

void ContaBancaria::exibirInformacoes() {
    cout << "Nome do cliente: " << this->cliente.getNome() << endl;
    cout << "CPF do cliente: " << this->cliente.getCpf() << endl;
    cout << "Numero da conta: " << this->numeroConta << endl;
    cout << "Saldo da conta: " << this->saldoConta << endl;
    cout << "-----------------------" << endl; // Pra ficar uma visu melhor
};
