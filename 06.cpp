// write a generic class and use it for match parenthesis.

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool is_valid(string x)
{
    stack<char> s;
    int n = x.size();
    bool ans = true;

    for (int i = 0; i < n; i++)
    {
        if (x[i] == '{' or x[i] == '[' or x[i] == '(')
            s.push(x[i]);

        else if (x[i] == '}')
        {
            if (!s.empty() and s.top() == '{')
            {
                s.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }

        else if (x[i] == ']')
        {
            if (!s.empty() and s.top() == '[')
            {
                s.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }

        else if (x[i] == ')')
        {
            if (!s.empty() and s.top() == '(')
            {
                s.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
    }

    if (!s.empty())
    {
        return false;
    }
    else
    {
        return ans;
    }
}

int main()
{
    string a;
    cout << "Type a string:" << endl;
    getline(cin, a);

    if (is_valid(a))
    {
        cout << "Parenthesis are balanced." << endl;
    }
    else
    {
        cout << "Parenthesis not balanced." << endl;
    }
}