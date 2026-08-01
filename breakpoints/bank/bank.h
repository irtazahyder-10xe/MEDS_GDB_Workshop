typedef struct {
  const char* username;
  int amt;
} user;

void new_user(const char* username, const int amt);
void print_all_users(void);
void add_deposit(const char* username, int amt);
void account_info(const char* username);
int total_for(const char* username);
