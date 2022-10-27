/*
    Evaluation of Prefix Expression
*/

#include <bits/stdc++.h>
using namespace std;

double prefixEvaluation(string s)
{
    stack<double> st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
            continue;
        else if (isdigit(s[i]))
        {
            double num = 0, j = i;
            while (i < s.length() && isdigit(s[i]))
            {
                i--;
            }
            i++;
            for (int k = i; k <= j; k++)
            {
                num = num * 10 + double(s[k] - '0');
            }
            st.push(num);
        }
        else
        {
            double op1 = st.top();
            st.pop();
            double op2 = st.top();
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
    cout << "Enter the Prefix Expression : ";
    getline(cin,s);
    cout << prefixEvaluation(s);
    return 0;
}