#include <iostream>
#include <list>
#include "Account.cpp"

class Bank
{
private:
public:
  std::list<Account> accounts;
  Account accountNULL;
  Bank()
  {
  }

  void AddAccount(int accountNumber, float initialBalance)
  {
    Account account(accountNumber, initialBalance);
    accounts.push_back(account);
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
  }

  void DebitAccount(int accountNumber, int value)
  {
    std::list<Account>::iterator account;
    account = FindAccount(accountNumber);

    if (value < 0)
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

    if (accountCredit->GetNumber() == accountNULL.GetNumber() || accountDebit->GetNumber() == accountNULL.GetNumber())
    {
      std::cout << "Conta Não Cadastrada!" << std::endl;
      return false;
    }

    accountDebit->Debit(amount);
    accountCredit->Credit(amount);

    return true;
  }
};