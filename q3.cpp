#include <iostream>
#include <stack>
#include <string>
Using namespace std;
int getPrecedence(char ch) {
    if (ch == '^') {
        return 3;
    }
    else if (ch == '*' || ch == '/') {
        return 2;
    }
    else if (ch == '+' || ch == '-') {
        return 1;
    }
    return 0;
}

string infixToPostfix(const string& infixExpression) {
string postfixExpression;
stack<char> operatorStack;

    for (char ch : infixExpression) {
        if (isalnum(ch)) {
            postfixExpression += ch;
        }
        else if (ch == '(') {
            operatorStack.push(ch);
        }
        else if (ch == ')') { 
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfixExpression += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop();
        }
        else {
            while (!operatorStack.empty() && getPrecedence(ch) <= getPrecedence(operatorStack.top())) {
                postfixExpression += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(ch);
        }
    }

    while (!operatorStack.empty()) {
        postfixExpression += operatorStack.top();
        operatorStack.pop();
    }

    return postfixExpression;
}

int main() {
    string infixExpression = "5+3*(2-1)";
    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Infix Expression: " << infixExpression << std::endl;
    cout << "Postfix Expression: " << postfixExpression << std::endl;

    return 0;
}
