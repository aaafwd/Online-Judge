/* @JUDGE_ID: 19899RK 110 C++ "By Anadan" */
// Meta-Loopless Sorts
// Accepted (0.000 seconds using as much as 392 kbytes)

#include <stdio.h>
#include <string.h>

#include <algorithm>

int N;
char vars_printed[32];
char spaces_buffer[128];
char if_then_buffer[] = "if a < b then";
char else_then_buffer[] = "else if a < b then";

void gen_program(const int i, const int spaces) {
  if (i == N) {
    spaces_buffer[spaces] = 0;
    fputs(spaces_buffer, stdout);
    spaces_buffer[spaces] = ' ';
    fputs("writeln(", stdout);
    fputs(vars_printed, stdout);
    puts(")");
    return;
  }

  // "if a < b then"
  spaces_buffer[spaces] = 0;
  fputs(spaces_buffer, stdout);
  spaces_buffer[spaces] = ' ';
  if_then_buffer[3] = vars_printed[2 * i - 2];
  if_then_buffer[7] = vars_printed[2 * i];
  puts(if_then_buffer);

  gen_program(i + 1, spaces + 2);
  std::swap(vars_printed[2 * i - 2], vars_printed[2 * i]);

  for (int j = i - 1; j > 0; --j) {
    // "else if a < b then";
    spaces_buffer[spaces] = 0;
    fputs(spaces_buffer, stdout);
    spaces_buffer[spaces] = ' ';
    else_then_buffer[8] = vars_printed[2*j - 2];
    else_then_buffer[12] = vars_printed[2*j];
    puts(else_then_buffer);

    gen_program(i + 1, spaces + 2);
    std::swap(vars_printed[2 * j - 2], vars_printed[2 * j]);
  }

  spaces_buffer[spaces] = 0;
  fputs(spaces_buffer, stdout);
  spaces_buffer[spaces] = ' ';
  puts("else");
  gen_program(i + 1, spaces + 2);

  for (int j = 0; j + 1 < N; ++j) {
    if (vars_printed[2 * j] < vars_printed[2 * j + 2]) break;
    std::swap(vars_printed[2 * j], vars_printed[2 * j + 2]);
  }
}

int main() {
  int set, i;

  memset(spaces_buffer, ' ', sizeof(spaces_buffer));
  scanf("%d", &set);
  while (set--) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
      vars_printed[2 * i] = 'a' + i;
      vars_printed[2 * i + 1] = ',';
    }
    vars_printed[2 * N - 1] = 0;

    puts("program sort(input,output);\nvar");
    fputs(vars_printed, stdout);
    printf(" : integer;\nbegin\n  readln(");
    fputs(vars_printed, stdout);
    puts(");");

    if (N == 1) {
      puts("  writeln(a)");
    } else {
      gen_program(1, 2);
    }

    puts("end.");
    if (set) putchar('\n');
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
