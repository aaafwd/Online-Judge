/* @JUDGE_ID: 19899RK 214 C++ "By Anadan" */
// Code Generation
// Accepted (0.000 seconds with low memory spent)

#include <algorithm>
#include <cstdio>
#include <vector>

// [0] -- register
// [1..9] -- tmp locations
// ['a'..'z'] && ['A'..'Z'] -- expression operands
std::vector<int> operands;
// Either -1, or such that: operands[reg_index] == 0.
int reg_index;
int last_tmp_location;
int min_expr_operand_index;

int PopOperand() {
  int op = operands.back();
  operands.pop_back();
  if (op == 0) reg_index = -1;
  return op;
}

void PushOperand(int op) {
  operands.push_back(op);
  if (op == 0) reg_index = operands.size() - 1;
}

void MaybePopTmpLocation(int op1, int op2 = -1) {
  if (op1 < op2) std::swap(op1, op2);
  if (op1 > 0 && last_tmp_location == op1) --last_tmp_location;
  if (op2 > 0 && last_tmp_location == op2) --last_tmp_location;
}

char* GetOperandName(int op, char* name) {
  if (('a' <= op && op <= 'z') || ('A' <= op && op <= 'Z')) {
    name[0] = op;
    name[1] = 0;
  } else {
    name[0] = '$';
    name[1] = '0' + (op - 1);
    name[2] = 0;
  }
  return name;
}

void MaybeStoreToTmpLocations() {
  char name[4];
  if (0 <= reg_index && reg_index < operands.size()) {
    const int tmp_loc = ++last_tmp_location;
    std::printf("ST %s\n", GetOperandName(tmp_loc, name));
    operands[reg_index] = tmp_loc;
    reg_index = -1;
  }
  if (min_expr_operand_index != -1) {
    for (int i = min_expr_operand_index; i < operands.size(); ++i) {
      const int op = operands[i];
      if (('a' <= op && op <= 'z') || ('A' <= op && op <= 'Z')) {
        const int tmp_loc = ++last_tmp_location;
        std::printf("L %c\nST %s\n", op, GetOperandName(tmp_loc, name));
        operands[i] = tmp_loc;
      }
    }
    min_expr_operand_index = -1;
  }
}

int main() {
  int ch;
  char str_op1[4], str_op2[4];
  bool has_output = false;
  while (1) {
    operands.clear();
    reg_index = -1;
    last_tmp_location = 0;
    min_expr_operand_index = -1;
    while ((ch = std::getchar()) != EOF && ch != '\n') {
      if (operands.empty()) {
        if (has_output) std::putchar('\n');
        has_output = true;
      }
      if (ch == '+' || ch == '*') {
        const char code = (ch == '+') ? 'A' : 'M';
        const int op2 = PopOperand();
        const int op1 = PopOperand();
        if (op1 == 0) {
          std::printf("%c %s\n", code, GetOperandName(op2, str_op2));
        } else if (op2 == 0) {
          std::printf("%c %s\n", code, GetOperandName(op1, str_op1));
        } else {
          MaybeStoreToTmpLocations();
          std::printf("L %s\n%c %s\n", GetOperandName(op1, str_op1), code,
                      GetOperandName(op2, str_op2));
        }
        MaybePopTmpLocation(op1, op2);
        PushOperand(0);
      } else if (ch == '-') {
        const int op2 = PopOperand();
        const int op1 = PopOperand();
        if (op1 == 0) {
          std::printf("S %s\n", GetOperandName(op2, str_op2));
        } else if (op2 == 0) {
          std::printf("N\nA %s\n", GetOperandName(op1, str_op1));
        } else {
          MaybeStoreToTmpLocations();
          std::printf("L %s\nS %s\n", GetOperandName(op1, str_op1),
                      GetOperandName(op2, str_op2));
        }
        MaybePopTmpLocation(op1, op2);
        PushOperand(0);
      } else if (ch == '/') {
        const int op2 = PopOperand();
        const int op1 = PopOperand();
        if (op1 == 0) {
          std::printf("D %s\n", GetOperandName(op2, str_op2));
        } else if (op2 == 0) {
          // REG := op1 / REG
          const int tmp_loc = ++last_tmp_location;
          const char* p = GetOperandName(tmp_loc, str_op2);
          std::printf("ST %s\nL %s\nD %s\n", p, GetOperandName(op1, str_op1),
                      p);
          --last_tmp_location;
        } else {
          MaybeStoreToTmpLocations();
          std::printf("L %s\nD %s\n", GetOperandName(op1, str_op1),
                      GetOperandName(op2, str_op2));
        }
        MaybePopTmpLocation(op1, op2);
        PushOperand(0);
      } else if (ch == '@') {
        const int op1 = PopOperand();
        if (op1 == 0) {
          std::printf("N\n");
        } else {
          MaybeStoreToTmpLocations();
          std::printf("L %s\nN\n", GetOperandName(op1, str_op1));
        }
        MaybePopTmpLocation(op1);
        PushOperand(0);
      } else {
        const int index = operands.size();
        PushOperand(ch);
        if (min_expr_operand_index == -1 || min_expr_operand_index > index) {
          min_expr_operand_index = index;
        }
      }
    }
    if (operands.empty()) break;
    if (operands.back() != 0) {
      std::printf("L %s\n", GetOperandName(operands.back(), str_op1));
    }
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
