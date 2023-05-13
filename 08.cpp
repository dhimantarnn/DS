// evaluate a postfix expression

#include <iostream>
#include <stack>
#include <string>
#include <math.h>
using namespace std;

int postfix_evaluation(string x)
{
    stack<int> s;

    for (int i = 0; i < x.length(); i++)
    {
        if (x[i] >= '0' && x[i] <= '9')
        {
            s.push(x[i] - '0');
        }
        else
        {
            int op2 = s.top();
            s.pop();

            int op1 = s.top();
            s.pop();

            switch (x[i])
            {
            case '+':
                s.push(op1 + op2);
                break;
            case '-':
                s.push(op1 - op2);
                break;
            case '*':
                s.push(op1 * op2);
                break;
            case '/':
                s.push(op1 / op2);
                break;
            case '^':
                s.push(pow(op1, op2));
                break;

            default:
                break;
            }
        }
    }

    return s.top();
}

int main()
{
    // string a = "46+2/5*7+";
    string a;
    cout << "Enter a string" << endl;
    cin >> a;
    cout << postfix_evaluation(a);
    return 0;
}