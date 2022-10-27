/*
    Postfix to Infix Expression
*/

#include <bits/stdc++.h>
using namespace std;

bool isOperator(char x)
{
    switch (x)
    {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}

string getInfix(string exp)
{
    stack<string> s;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (isOperator(exp[i]))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op2 + exp[i] +
                   op1 + ")");
        }

        else
        {
            string op(1, exp[i]);
            s.push(op);
        }
    }

    return s.top();
}

int main()
{
    string exp = "ab*c+";
    cout << getInfix(exp);
    return 0;
}