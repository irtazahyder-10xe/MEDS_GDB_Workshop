#include "bank.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define USER_COUNT 10

user list[USER_COUNT];
int user_count;

static bool compare_username(const char *u1, const char *u2)
{
  return strcmp(u1, u2);
}

void new_user(const char* username, const int amt)
{
  if (user_count == USER_COUNT) {
    printf("Cannot add more than 10 users!\n");
    return;
  }

  list[user_count].username = username;
  list[++user_count].amt = amt;
}

void print_all_users(void)
{
  for (size_t i = 0; i < user_count; i++) {
    printf("%10s: %3d\n", list[i].username, list[i].amt);
  }
}

void add_deposit(const char* username, const int amt)
{
  for (int i = 0; i < user_count; i++) {
    if (compare_username(list[i].username, username))
      list[i].amt += amt;
  }
  printf("User %s not found\n", username);
}

void account_info(const char* username)
{
  user* u;
  for(size_t i = 0; i < user_count; i++) {
    if (compare_username(list[i].username, username))
      u = &list[i];
  }
  printf("Username: %s, Amt: %d\n", u->username, u->amt);
}

int total_for(const char* username)
{
  int total = 0;
  for(size_t i = 0; i < user_count; i++) {
    if (compare_username(list[i].username, username))
      total = list[i].amt;
  }
  return total;
}
