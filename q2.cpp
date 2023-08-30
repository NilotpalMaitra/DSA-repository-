
#include <iostream>
#include <stack>
#include <string>
Using namespace std;

int evaluatePostfixExpression(const string& postfixExpression) {
    stack<int> operandStack;

    for (char ch : postfixExpression) {
        if (isdigit(ch)) {
            operandStack.push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            int result;
            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }
            operandStack.push(result);
        }
    }

    return operandStack.top();
}

int main() {
    string postfixExpression = "82+4*";
    int result = evaluatePostfixExpression(postfixExpression);
    cout << "Result: " << result << std::endl;

    return 0;
}

