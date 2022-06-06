#include <iostream>

class Account
{
  protected:
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
      balance = 0.0f;
    }
    ~Account(){}

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

    virtual int GetType() ;
    virtual void AddPoints(int pointsAmount) ;
    virtual int GetPoints();
};
