// #include <iostream>
#include <list>
#include "Account.cpp"
// #include "BonusAccount.cpp"

class Bank
{
private:
public:
  std::list<Account> accounts;
  Account accountNULL;
  Bank()
  {  }
  ~Bank(){
  }
  void AddAccount(int accountNumber, int accountType, float initialBalance)
  {
    if(accountType != 1)
    {
        initialBalance = 0;
    }
      
    Account account(accountNumber, accountType, initialBalance);
   
    if(accountType == 2){
      int points = 10;
      account.AddPoints(points);
    }
    
    accounts.push_back(account);

    if (accountType != 2 )
    {
      accounts.push_back(savingAccount);
    }
    else
    {
      accounts.push_back(account);
    }
  }

  int GetPoints(int accountNumber)
  {
    std::list<Account>::iterator account;
    account = FindAccount(accountNumber);
    return account->GetPoints();
  }

  float GetBalance(int accountNumber)
  {
    std::list<Account>::iterator account;
    account = FindAccount(accountNumber);
    return account->GetBalance();
  }

  void CreditAccount(int accountNumber, int value)
  {
    std::list<Account>::iterator account;
    account = FindAccount(accountNumber);
    if (value < 0)
    {
      std::cout << "Valor informado não pode ser negativo, favor realizar operação novamente" << std::endl;
    }
    else
    {
      account->Credit(value);
    }

    if (account->GetType() == 2)
    {
      int points = value / 100;
      account->AddPoints(points);
    }
  }

  void DebitAccount(int accountNumber, int value)
  {
    std::list<Account>::iterator account;
    account = FindAccount(accountNumber);

    if (account->GetType() != 3 && value + (account->GetBalance()) < -1000 && value > 0)
    {
      account->Debit(value);
      std::cout << "Valor debitado com sucesso" << std::endl;
    }
    else if (value < 0)
    {
      std::cout << "Valor informado não pode ser negativo, favor realizar operação novamente" << std::endl;
    }
    else if (account->GetBalance() - value < 0)
    {
      std::cout << "Saldo em conta insuficiente para debitar este valor" << std::endl;
    }
    else
    {
      account->Debit(value);
      std::cout << "Valor debitado com sucesso" << std::endl;
    }
  }

  std::list<Account>::iterator FindAccount(int accountNumber)
  {
    std::list<Account>::iterator account_ptr;
    std::list<Account>::iterator it_begin = accounts.begin();
    std::list<Account>::iterator it_end = accounts.end();

    while (it_begin != it_end)
    {
      if (accountNumber == it_begin->GetNumber())
      {
        return it_begin;
      }
      it_begin++;
    }

    return it_end;
  }
  bool Transfer(int accountNumberDebit, int accountNumberCredit, int amount)
  {
    // account debit -> conta que será debitada
    std::list<Account>::iterator accountDebit = FindAccount(accountNumberDebit);
    // account credit -> conta que será creditada
    std::list<Account>::iterator accountCredit = FindAccount(accountNumberCredit);

    if (accountDebit->GetBalance() < amount)
    {
      std::cout << "A conta de origem não possui saldo suficiente, favor realizar operação com valor válido" << std::endl;
      return false;
    }

    if (accountCredit->GetNumber() == 0 || accountDebit->GetNumber() == 0)
    {
      std::cout << "Conta Não Cadastrada!" << std::endl;
      return false;
    }

    accountDebit->Debit(amount);
    accountCredit->Credit(amount);

    if(accountCredit->GetType() == 2){

      int points = amount / 150;
      accountCredit->AddPoints(points);
      
    }

    return true;
  }

  void ApplyYield(int accountNumber, float value)
  {
    std::list<Account>::iterator account;
    account = FindAccount(accountNumber);

    if (account->GetType() == 3)
    {
      account->Yield(value);
      std::cout << "Juros Aplicado com Sucesso" << std::endl;
    }
    else
    {
      std::cout << "É preciso Possuir uma Conta Poupança para Render Juros" << std::endl;
    }
  }
};