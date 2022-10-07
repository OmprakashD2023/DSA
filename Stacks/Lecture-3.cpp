/*
  Balanced Parenthesis Problem
*/

#include <bits/stdc++.h>
using namespace std;

bool matchParenthesis(char a, char b)
{
    return ((a == '(' && b == ')') || 
            (a == '[' && b == ']') ||
            (a == '{' && b == '}'));
}

bool isBalanced(string str){
    stack<char> s;
    for(auto x : str){
        if(x == '(' || x == '[' || x == '{')
            s.push(x);
        else{
            if(s.empty()==true)
                return false;
            if(matchParenthesis(s.top(),x)==false)
                return false;
            else
                s.pop();
        }
    }
    return s.empty();
}

int main(){
    string str;
    cout<<"Enter a parenthesis sequence : ";
    cin>>str;
    if(isBalanced(str))
        cout<<"Yes, it is a balanced sequence";
    else
        cout<<"No, it is not a balanced sequence";
    return 0;
}