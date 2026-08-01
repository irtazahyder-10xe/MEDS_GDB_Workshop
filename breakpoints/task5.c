#include <stdio.h>

#include "bank.h"

void add_users(void);

int main()
{
  add_users();

  printf("Alice info: ");
  account_info("Alice");
  printf("Steve info: ");
  account_info("Steve");

  printf("Total for Alice: %d\n"  , total_for("alice"));
  printf("Total for Bob: %d\n"    , total_for("Bob"));
  printf("Total for Cindy: %d\n"  , total_for("cindy"));
  printf("Total for Eve: %d\n"   , total_for("eve"));
  printf("Total for Evelyn: %d\n"   , total_for("evelyn"));
}

void add_users()
{
  add_deposit("Alice", 10.0);
  add_deposit("Bob", 5.0);
  add_deposit("alice", 5.0);
  add_deposit("Eve", 5.0);
  add_deposit("bob", 5.0);
  add_deposit("Alice", 5.0);
  add_deposit("Cindy", 15.0);
  add_deposit("evelyn", 10.0);
  add_deposit("eve", 25.0);
  add_deposit("Bob", 5.0);
  add_deposit("cindy", 15.0);
  add_deposit("Bob", 5.0);
  add_deposit("eve", 5.0);
  add_deposit("evelyn", 5.0);
}
