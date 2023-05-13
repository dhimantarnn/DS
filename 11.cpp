// reverse words of string using stack

#include <iostream>
#include <stack>
#include <string>

using namespace std;

void rev_by_stack(string str)
{
    stack<string> st;
    int n = str.length();

    for (int i = 0; i < n; i++)
    {
        string word = "";

        while (str[i] != ' ' && i < n)
        {
            word += str[i];
            i++;
        }

        st.push(word);
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;
}

int main()
{
    string a;
    cout << "Enter a string: " << endl;
    getline(cin, a);
    rev_by_stack(a);
    return 0;
}