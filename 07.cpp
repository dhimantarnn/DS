// using stacks convert infinix to post and prefix expression

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infinix_to_postfix(string s)
{
    stack<char> st;
    string res;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
        {
            res += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && prec(st.top()) > prec(s[i]))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    return res;
}

string infinix_to_prefix(string s)
{

    int n = s.length();
    for (int i = 0; i < n / 2; i++)
    {
        swap(s[i], s[n - i - 1]);
    }

    s = infinix_to_postfix(s);

    for (int i = 0; i < n / 2; i++)
    {
        swap(s[i], s[n - i - 1]);
    }

    return s;
}

int main()
{
    // string str = "a*b+c*d";
    string str;
    cout << "Enter an infix expression: " << endl;
    cin >> str;
    cout << "\nPostfix:\n"
         << infinix_to_postfix(str) << endl;
    cout << "\nPrefix:\n"
         << infinix_to_prefix(str) << endl;
    return 0;
}