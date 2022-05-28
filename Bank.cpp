#include <iostream>
#include <list>
#include "Account.cpp"

class Bank{
  private:
      
  public:
      std::list<Account> accounts;
      Account accountNULL;
    Bank(){;
    }

    void AddAccount(int accountNumber){
      Account account(accountNumber);
      accounts.push_back(account);
    }

    float GetBalance(int accountNumber){
      Account * account;
      account = FindAccount(accountNumber);
      return account->GetBalance();
    }

    void CreditAccount(int accountNumber, int value)
    {
      Account * account;
      account = FindAccount(accountNumber);
      account->Credit(value);
    }
    
    void DebitAccount(int accountNumber, int value)
    {
      Account * account;
      account = FindAccount(accountNumber);
      account->Debit(value);
    }
    

    Account *FindAccount(int accountNumber){
      Account *account_ptr;
      for(Account account : accounts){
        if(account.GetNumber() == accountNumber){
          account_ptr = &account;
          return account_ptr;
        }
      }
        return &accountNULL;
    }
    bool Transfer(int accountNumberCredit, int accountNumberDebit, int amount){
      Account * accountCredit = FindAccount(accountNumberCredit);
      Account * accountDebit = FindAccount(accountNumberDebit);

      if(accountCredit->GetNumber() == accountNULL.GetNumber() || accountDebit->GetNumber() == accountNULL.GetNumber()){
        std::cout << "Conta Não Cadastrada!" << std::endl;
        return false;
      }

      accountCredit->Credit(amount);
      accountDebit->Debit(amount);

      return true;

    }

};