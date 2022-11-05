/*
    Evaluation of Postfix Expression
*/

#include <bits/stdc++.h>
using namespace std;

int postfixEvaluation(string s)
{
    stack<int> st;

    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == ' ')
            continue; 

        if (isdigit(s[i]))
        {
            int num = 0;
            while (isdigit(s[i]))
            {
                num = num * 10 + (int)(s[i] - '0');
                i++;
            }
            i--;
            st.push(num);
        }
        
        else
        {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '^':
                st.push(pow(op1, op2));
                break;
            }
        }
    }

    return st.top();
}

int main()
{
    string s;
    cout << "Enter the Postfix Expression : ";
    getline(cin,s);
    cout << postfixEvaluation(s);
    return 0;
}