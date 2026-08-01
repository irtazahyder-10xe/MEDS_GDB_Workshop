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
  printf("Total for Eve: %d\na"   , total_for("eve"));

}

void add_users()
{
  new_user("Alice", 10.0);
  new_user("Bob", 5.0);
  new_user("alice", 5.0);
  new_user("Eve", 5.0);
  new_user("bob", 5.0);
  new_user("Alice", 5.0);
  new_user("Cindy", 15.0);
  new_user("eve", 25.0);
  new_user("Bob", 5.0);
  new_user("cindy", 15.0);
  new_user("Bob", 5.0);
  new_user("eve", 5.0);
}
