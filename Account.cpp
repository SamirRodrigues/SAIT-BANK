#include <iostream>

class Account
{
  protected:
    int number;
    float balance;
    int points;
    int accountType;
  public:
    Account()
    {
      number = 0;
      balance = 0.0f;
    }

    Account(int accountNumber, int typeOfAccount)
    {
      number = accountNumber;
      balance = 0.0f;
      accountType = typeOfAccount;
      points = 0;
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

    void AddPoints(int pointsAmount){
      points += pointsAmount;
    }

    int GetPoints(){
      return points;
    }

    int GetType(){
      return accountType;
    }
};
