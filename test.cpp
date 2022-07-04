#define CATCH_CONFIG_MAIN

#include "test/catch.hpp"
#include "src/bank.cpp"

TEST_CASE("Testando Account.cpp"){
  Account a( 1, 1, 250.00f);
  Account b( 2, 2, 250.00f);
  Account c( 3, 3, 250.00f);

  SECTION("testando GetNumber()"){
    REQUIRE(a.GetNumber() == 1);
    REQUIRE(b.GetNumber() == 2);
    REQUIRE(c.GetNumber() == 3);
  }
  SECTION("testando GetBalance()"){
    REQUIRE(a.GetBalance() == 250.00f);
  }
  SECTION("testando Debit()"){
    a.Debit(100);
    REQUIRE(a.GetBalance() == 150.00f);
  }
  SECTION("testando Credit()"){
    a.Credit(200);
    REQUIRE(a.GetBalance() == 450.00f);
  }
  SECTION("testando Yield()"){
    c.Yield(20.0f);
    REQUIRE(c.GetBalance() == 300.00f);
  }
  SECTION("testando AddPoints()"){
    b.AddPoints(30);
    REQUIRE(b.GetPoints() == 30);
  }
  SECTION("testando AddPoints()"){
    REQUIRE(b.GetPoints() == 0);
  }
  SECTION("Testando Tipo de Conta"){
    REQUIRE(a.GetType() == 1);
    REQUIRE(b.GetType() == 2);
    REQUIRE(c.GetType() == 3);
  }
}

TEST_CASE("Testando Bank.cpp"){
  Bank bank;
  Account a( 1, 1, 250.00f);
  Account b( 2, 2, 350.00f);
  Account c( 3, 3, 450.00f);

  bank.accounts.push_back(a);
  bank.accounts.push_back(b);
  bank.accounts.push_back(c);

  SECTION("testando FindAccount()"){
    REQUIRE(bank.FindAccount(a.GetNumber())->GetBalance() == a.GetBalance());
    REQUIRE(bank.FindAccount(b.GetNumber())->GetBalance() == b.GetBalance());
    REQUIRE(bank.FindAccount(c.GetNumber())->GetBalance() == c.GetBalance());
  }
  SECTION("testando GetPoints()"){
    REQUIRE(bank.GetPoints(b.GetNumber()) == a.GetPoints());
  }
  SECTION("testando GetBalance()"){
    REQUIRE(bank.GetBalance(a.GetNumber()) == a.GetBalance());
  }
  SECTION("testando CreditAccount()"){
    bank.CreditAccount(a.GetNumber(), 200);
    REQUIRE(bank.GetBalance(a.GetNumber()) == a.GetBalance() + 200);
  }
  SECTION("testando DebitAccount()"){
    bank.DebitAccount(a.GetNumber(), 200);
    REQUIRE(bank.GetBalance(a.GetNumber()) == a.GetBalance() - 200);
  }
  SECTION("testando Transfer()"){
    bank.Transfer(a.GetNumber(), b.GetNumber(), 200);
    REQUIRE(bank.GetBalance(a.GetNumber()) == a.GetBalance() - 200);
    REQUIRE(bank.GetBalance(b.GetNumber()) == b.GetBalance() + 200);
  }
}
