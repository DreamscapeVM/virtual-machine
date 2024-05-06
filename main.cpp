#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> stack;

  while (true) {
    string line;
    getline(cin, line);

    if (line == "quit") {
      break;
    }

    if (line == "push") {
      int value;
      cin >> value;
      stack.push_back(value);
    } else if (line == "pop") {
      if (stack.empty()) {
        cout << "Stack is empty" << endl;
        continue;
      }

      int value = stack.back();
      stack.pop_back();
      cout << value << endl;
    } else if (line == "add") {
      if (stack.size() < 2) {
        cout << "Stack is too small" << endl;
        continue;
      }

      int value1 = stack.back();
      stack.pop_back();
      int value2 = stack.back();
      stack.pop_back();

      stack.push_back(value1 + value2);
    } else if (line == "sub") {
      if (stack.size() < 2) {
        cout << "Stack is too small" << endl;
        continue;
      }

      int value1 = stack.back();
      stack.pop_back();
      int value2 = stack.back();
      stack.pop_back();

      stack.push_back(value1 - value2);
    } else if (line == "mul") {
      if (stack.size() < 2) {
        cout << "Stack is too small" << endl;
        continue;
      }

      int value1 = stack.back();
      stack.pop_back();
      int value2 = stack.back();
      stack.pop_back();

      stack.push_back(value1 * value2);
    } else if (line == "div") {
      if (stack.size() < 2) {
        cout << "Stack is too small" << endl;
        continue;
      }

      int value1 = stack.back();
      stack.pop_back();
      int value2 = stack.back();
      stack.pop_back();

      stack.push_back(value1 / value2);
    } else if (line == "if") {
      if (stack.empty()) {
        cout << "Stack is empty" << endl;
        continue;
      }

      int condition = stack.back();
      stack.pop_back();

      if (condition != 0) {
        // 다음 줄을 실행합니다.
        getline(cin, line);

        if (line == "else") {
          // 'else' 블록을 건너뛴다.
          getline(cin, line);
        } else {
          // 'else' 블록이 아닌 경우, 코드를 실행합니다.
          while (line != "end" && !cin.eof()) {
            // 코드 실행
            getline(cin, line);
          }
        }
      }
    } else if (line == "end") {
      // 'if' 블록 종료
    } else {
      cout << "Invalid command" << endl;
    }
  }

  return 0;
}