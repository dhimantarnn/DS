// factorial uising stack

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    stack<int> s;

    s.push(1);

    for (int i = 2; i <= n; ++i)
    {
        s.push(s.top() * i);
    }

    cout << "Factorial: " << s.top() << endl;
    return 0;
}