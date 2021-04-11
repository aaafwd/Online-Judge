/* @JUDGE_ID: 19899RK 284 C++ "By Anadan" */
// Logic
// Accepted (0.000 seconds with low memory spent)

#include <cassert>
#include <cstdio>
#include <vector>

struct Cell {
  char op;
  std::vector<int> inputs;
  int value;
  int eval_gen;
};
std::vector<Cell> cells;
std::vector<int> input_ids;
std::vector<int> output_ids;

int Evaluate(const int id, const int eval_gen) {
  Cell& cell = cells[id];
  if (cell.eval_gen == eval_gen) return cell.value;
  cell.eval_gen = eval_gen;
  if (cell.op == 'o') {
    cell.value = Evaluate(cell.inputs[0], eval_gen);
  } else if (cell.op == '!') {
    cell.value = Evaluate(cell.inputs[0], eval_gen) ^ 1;
  } else if (cell.op == '&') {
    cell.value =
        Evaluate(cell.inputs[0], eval_gen) & Evaluate(cell.inputs[1], eval_gen);
  } else if (cell.op == '|') {
    cell.value =
        Evaluate(cell.inputs[0], eval_gen) | Evaluate(cell.inputs[1], eval_gen);
  } else {
    assert(0);
  }
  return cell.value;
}

int main() {
  char buffer[128];
  int test_cases, test_values;
  std::scanf("%d\n", &test_cases);
  input_ids.reserve(100);
  output_ids.reserve(100);
  while (test_cases--) {
    cells.clear();
    cells.resize(100);
    input_ids.clear();
    output_ids.clear();
    while (std::scanf("%s", buffer) == 1 && buffer[0] != 'e') {
      const int id = (buffer[0] - '0') * 10 + (buffer[1] - '0');
      const char op = buffer[2];
      cells[id].op = op;
      cells[id].eval_gen = 0;
      if (op == 'i') {
        input_ids.push_back(id);
      } else if (op == 'o') {
        output_ids.push_back(id);
      }
      while (std::scanf("%s", buffer) == 1 && buffer[0] != '.') {
        const int out_id = (buffer[0] - '0') * 10 + (buffer[1] - '0');
        cells[out_id].inputs.push_back(id);
      }
    }
    std::scanf("%d", &test_values);
    for (int eval_gen = 1; eval_gen <= test_values; ++eval_gen) {
      std::scanf("%s", buffer);
      for (int i = 0; i < input_ids.size(); ++i) {
        const int index = input_ids[i];
        cells[index].value = buffer[i] - '0';
        cells[index].eval_gen = eval_gen;
      }
      char* p = buffer;
      for (int i = 0; i < output_ids.size(); ++i) {
        const int index = output_ids[i];
        *p++ = '0' + Evaluate(index, eval_gen);
      }
      *p = 0;
      std::puts(buffer);
    }
    std::putchar('\n');
  }
}
/* @END_OF_SOURCE_CODE */
