/* @JUDGE_ID: 19899RK 210 C++ "By Anadan" */
// Concurrency Simulator
// Accepted (0.030 seconds with low memory spent)

#include <cctype>
#include <cstdio>
#include <cstring>
#include <deque>
#include <string>
#include <vector>

struct Program {
  int id;
  int ptr;  // Instruction pointer.
  std::vector<std::string> statements;
};

std::deque<Program*> ready_queue;
std::deque<Program*> blocked_queue;
int variables[26];
int exec_time[5];
int time_quantum;
bool lock_claimed;

bool ExecuteCommand(const int id, const char* cmd, int* time_quota) {
  if (std::isspace(cmd[1]) || cmd[1] == '=') {
    char ch = cmd[0];
    int x = 0;
    for (int i = 2; cmd[i]; ++i) {
      if ('0' <= cmd[i] && cmd[i] <= '9') {
        x = 10 * x + (cmd[i] - '0');
      }
    }
    variables[ch - 'a'] = x;
    *time_quota -= exec_time[0];
  } else if (cmd[0] == 'p') {  // cmd = "print"
    for (int i = 6;; ++i) {
      if ('a' <= cmd[i] && cmd[i] <= 'z') {
        std::printf("%d: %d\n", id + 1, variables[cmd[i] - 'a']);
        *time_quota -= exec_time[1];
        break;
      }
    }
  } else if (cmd[0] == 'l') {  // cmd == "lock"
    if (lock_claimed) return false;
    lock_claimed = true;
    *time_quota -= exec_time[2];
  } else if (cmd[0] == 'u') {  // cmd == "unlock"
    lock_claimed = false;
    if (!blocked_queue.empty()) {
      ready_queue.push_front(blocked_queue.front());
      blocked_queue.pop_front();
    }
    *time_quota -= exec_time[3];
  } else {  // cmd == "end"
    *time_quota -= exec_time[4];
  }
  return true;
}

void RunSimulation() {
  while (!ready_queue.empty()) {
    Program& program = *ready_queue.front();
    ready_queue.pop_front();
    bool blocked = false;
    int time_quota = time_quantum;
    const int size = program.statements.size();
    const std::string* statement = program.statements.data() + program.ptr;
    while (time_quota > 0 && program.ptr < size) {
      if (ExecuteCommand(program.id, statement->c_str(), &time_quota)) {
        ++program.ptr;
        ++statement;
      } else {
        blocked = true;
        blocked_queue.push_back(&program);
        break;
      }
    }
    if (!blocked && program.ptr < size) {
      ready_queue.push_back(&program);
    }
  }
}

char* ltrim(char* str) {
  while (*str && std::isspace(*str)) ++str;
  return str;
}

int main() {
  std::vector<Program> programs;
  int N;
  int test_cases = 0;
  char buffer[1024 * 4];
  std::scanf("%d\n\n", &test_cases);
  while (test_cases--) {
    std::memset(variables, 0, sizeof(variables));
    programs.clear();
    ready_queue.clear();
    blocked_queue.clear();
    lock_claimed = false;
    std::scanf("%d %d %d %d %d %d %d\n", &N, &exec_time[0], &exec_time[1],
               &exec_time[2], &exec_time[3], &exec_time[4], &time_quantum);
    programs.reserve(N);
    for (int i = 0; i < N; ++i) {
      Program program;
      program.id = i;
      program.ptr = 0;
      program.statements.reserve(32);
      while (1) {
        std::fgets(buffer, sizeof(buffer), stdin);
        const char* p = ltrim(buffer);
        program.statements.push_back(std::string(p));
        if (p[0] == 'e' && p[1] == 'n') break;
      }
      programs.push_back(std::move(program));
    }
    for (int i = 0; i < N; ++i) {
      ready_queue.push_back(&programs[i]);
    }
    RunSimulation();
    if (test_cases) std::putchar('\n');
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
