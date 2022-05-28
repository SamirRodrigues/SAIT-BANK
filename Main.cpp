#include <iostream>
#include <list>
#include "Bank.cpp"

void CadastrarConta(Bank * bank){
  int accountNumber;
  std::cout << "Digite o Número da Conta" << std::endl;
  std::cin >> accountNumber;
  bank->AddAccount(accountNumber);
  std::cout << "Conta Cadastrada Com Sucesso!" << std::endl;
}

void ConsultarSaldo(Bank * bank){
  int accountNumber;
  std::cout << "Digite o Número da Conta" << std::endl;
  std::cin >> accountNumber;
  std::cout << bank->GetBalance(accountNumber) << std::endl;
}

void Creditar(Bank * bank){
  int accountNumber;
  int value;
  std::cout << "Digite o Número da Conta" << std::endl;
  std::cin >> accountNumber;
  std::cout << "Digite o valor a ser Creditado na conta " << accountNumber << ":"<< std::endl;
  std::cin >> value;
  bank->CreditAccount(accountNumber,value);
  std::cout << bank->accounts.front().balance;
  // std::cout << bank->GetBalance(accountNumber);
}

void Debitar(Bank * bank){
  int accountNumber;
  int value;
  std::cout << "Digite o Número da Conta" << std::endl;
  std::cin >> accountNumber;
  std::cout << "Digite o valor a ser Debitado na conta " << accountNumber << ":"<< std::endl;
  std::cin >> value;
  bank->DebitAccount(accountNumber,value);
  }

void Transferencia(Bank * bank){
  int accountNumberOne;
  int accountNumberTwo;
  int value;
  std::cout << "Digite o Número da Conta de Origem" << std::endl;
  std::cin >> accountNumberOne;
  std::cout << "Digite o Número da Conta de Destino" << std::endl;
  std::cin >> accountNumberTwo;
  std::cout << "Digite o valor a ser Transferido entre as contas:"<< std::endl;
  std::cin >> value;
  if(bank->Transfer(accountNumberOne, accountNumberTwo, value)){
      std::cout << "Transferencia realizada"<< std::endl;
  }
  else{
          std::cout << "Transferencia falhou"<< std::endl;
  }
}

int main(){

  int choice = 1;
  Bank bank;
  while(choice != 0){
    std::cout << "Menu" << std::endl;
    std::cout << "0- Sair" << std::endl;
    std::cout << "1- Cadastrar Conta" << std::endl;
    std::cout << "2- Consultar Saldo" << std::endl;
    std::cout << "3- Creditar valor da Conta" << std::endl;
    std::cout << "4- Debitar valor da Conta" << std::endl;
    std::cout << "5- Realizar transferencia" << std::endl;
    std::cin >> choice;

    switch(choice){
      case 0:
        std::cout << " Saindo ... " << std::endl;
        break;
      case 1:
        CadastrarConta(&bank);
        break;
      case 2:
        ConsultarSaldo(&bank);
        break;
      case 3:
        Creditar(&bank);
        break;
      case 4:
        Debitar(&bank);
        break;
      case 5:
        Transferencia(&bank);
        break;
     default:
        std::cout << std::endl;
        std::cout << ">> Digite um valor válido <<" << std::endl;
        std::cout << std::endl;
        break;
    }
  }

  return 0;
}