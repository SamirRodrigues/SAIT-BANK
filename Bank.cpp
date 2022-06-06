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

  void AddAccount(int accountNumber)
  {
    Account account(accountNumber);
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
    account->Credit(value);
  }

  void DebitAccount(int accountNumber, int value)
  {
    std::list<Account>::iterator account;
    account = FindAccount(accountNumber);
    account->Debit(value);
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
    std::list<Account>::iterator accountCredit = FindAccount(accountNumberCredit);
    std::list<Account>::iterator accountDebit = FindAccount(accountNumberDebit);

    if (accountCredit->GetNumber() == accountNULL.GetNumber() || accountDebit->GetNumber() == accountNULL.GetNumber())
    {
      std::cout << "Conta Não Cadastrada!" << std::endl;
      return false;
    }

    accountCredit->Credit(amount);
    accountDebit->Debit(amount);

    return true;
  }
};