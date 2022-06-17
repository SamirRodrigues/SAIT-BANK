// #include <iostream>
#include "Account.cpp"

class BonusAccount : Account
{
protected:
  int points;
  // int accountType;

public:
  BonusAccount() : Account()
  {
  }
  BonusAccount(int accountNumber) : Account(accountNumber)
  {
    points = 10;
    // accountType = 2;
  }
  ~BonusAccount()
  {
  }
  void AddPoints(int pointsAmount)
  {
    points += pointsAmount;
  }
  // int GetType() const{
  // return accountType;
  // }
  int GetPoints() const
  {
    return points;
  }
};