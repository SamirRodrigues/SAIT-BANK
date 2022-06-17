
#include <iostream>

class Account
{
private:
  int number;
  float balance;

public:
  Account()
  {
    number = 0;
    balance = 0.0f;
  }

  Account(int acountNumber, float initialBalance)
  {
    number = acountNumber;
    balance = initialBalance;
  }

  int GetNumber()
  {
    return number;
  }

  float GetBalance()
  {
    return balance;
  }

  void Credit(int amount)
  {
    balance += amount;
  }

  void Debit(int amount)
  {
    balance -= amount;
  }
};
