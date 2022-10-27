/*
    Prefix to Postfix Expression
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

string postToPre(string s)
{
    stack<string> st;
    int length = s.length();
    for (int i = length - 1; i >= 0; i--)
    {
        if (isOperator(s[i]))
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            string temp = op1 + op2 + s[i];

            st.push(temp);
        }
        else
        {
            st.push(string(1, s[i]));
        }
    }
    return st.top();
}

int main()
{
    string s;
    cout << "Enter the Postfix Expression : ";
    cin >> s;
    cout << "Prefix Expression : " << postToPre(s);
    return 0;
}