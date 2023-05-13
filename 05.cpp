// write a generic class and use it for reverse string.

#include <iostream>
#include <string>
#include <stack>
using namespace std;

void rev(string &x)
{
    stack<char> s;
    int n = x.size();

    for (int i = 0; i < n; i++)
    {
        s.push(x[i]);
    }

    for (int i = 0; i < n; i++)
    {
        x[i] = s.top();
        s.pop();
    }
}

int main()
{
    string a;
    cout << "Type a string:" << endl;
    getline(cin, a);
    rev(a);
    cout << a << endl;
    return 0;
}