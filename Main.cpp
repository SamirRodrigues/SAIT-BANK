// #include <iostream>
// #include <list>
#include "src/Bank.cpp"

void CadastrarConta(Bank *bank)
{
  int accountType;
  float initialBalance;

  std::cout << "Escolha o Tipo de Conta" << std::endl;
  std::cout << "1- Conta Comum" << std::endl;
  std::cout << "2- Conta Bonus" << std::endl;
  std::cout << "3- Conta Poupança" << std::endl;

  std::cin >> accountType;

  if(accountType != 2){
    std::cout << "Qual o saldo inicial?" << std::endl;

    std::cin >> initialBalance;

  }

  int accountNumber;

  std::cout << "Digite o Número da Conta" << std::endl;
  std::cin >> accountNumber;
  
  if(accountType == 1)
  {
    std::cout << "Qual o saldo inicial da Conta?" << std::endl;
    std::cin >> initialBalance;
        
  }
  
  bank->AddAccount(accountNumber, accountType, initialBalance);
  std::cout << "Conta Cadastrada Com Sucesso!" << std::endl;
}

void ConsultarSaldo(Bank *bank)
{
  int accountNumber;
  std::cout << "Digite o Número da Conta" << std::endl;
  std::cin >> accountNumber;
  std::cout << "Saldo na conta " << accountNumber << ": " << bank->GetBalance(accountNumber);
}

void Creditar(Bank *bank)
{
  int accountNumber;
  int value;
  std::cout << "Digite o Número da Conta" << std::endl;
  std::cin >> accountNumber;
  std::cout << "Digite o valor a ser Creditado na conta " << accountNumber << ":" << std::endl;
  std::cin >> value;
  bank->CreditAccount(accountNumber, value);
  std::cout << value << " Creditado com sucesso";
}

void Debitar(Bank *bank)
{
  int accountNumber;
  int value;
  std::cout << "Digite o Número da Conta" << std::endl;
  std::cin >> accountNumber;
  std::cout << "Digite o valor a ser Debitado na conta " << accountNumber << ":" << std::endl;
  std::cin >> value;
  bank->DebitAccount(accountNumber, value);
}

void Transferencia(Bank *bank)
{
  int accountNumberOne;
  int accountNumberTwo;
  int value;
  std::cout << "Digite o Número da Conta de Origem" << std::endl;
  std::cin >> accountNumberOne;
  std::cout << "Digite o Número da Conta de Destino" << std::endl;
  std::cin >> accountNumberTwo;
  std::cout << "Digite o valor a ser Transferido entre as contas:" << std::endl;
  std::cin >> value;
  if (bank->Transfer(accountNumberOne, accountNumberTwo, value))
  {
    std::cout << "Transferencia realizada" << std::endl;
  }
  else
  {
    std::cout << "Transferencia falhou" << std::endl;
  }
}

void RenderJuros(Bank *bank){
  int accountNumber;
  float value;
  std::cout << "Digite o Número da Conta" << std::endl;
  std::cin >> accountNumber;
  std::cout << "Digite a taxa de juros para ser calculado a conta " << accountNumber << ":" << std::endl;
  std::cin >> value;
  bank->ApplyYield(accountNumber, value);
}

int main()
{

  int choice = 1;
  Bank bank;
  while (choice != 0)
  {
    std::cout << std::endl
              << std::endl;
    std::cout << "Menu" << std::endl;
    std::cout << "0- Sair" << std::endl;
    std::cout << "1- Cadastrar Conta" << std::endl;
    std::cout << "2- Consultar Saldo" << std::endl;
    std::cout << "3- Creditar valor da Conta" << std::endl;
    std::cout << "4- Debitar valor da Conta" << std::endl;
    std::cout << "5- Realizar transferencia" << std::endl;
    std::cout << "6- Render Juros" << std::endl;

    std::cin >> choice;

    switch (choice)
    {
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
    case 6:
      RenderJuros(&bank);
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