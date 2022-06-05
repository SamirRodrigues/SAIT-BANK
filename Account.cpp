
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

  Account(int acountNumber)
  {
    number = acountNumber;
    balance = 5.0f;
  }

  int GetNumber()
  {
    return number;
  }

  float GetBalance()
  {
    std::cout << balance << std::endl;
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
