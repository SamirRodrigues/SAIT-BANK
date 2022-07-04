#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../bank.cpp"

TEST_CASE("testando Account.cpp"){
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
