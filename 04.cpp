// create a stack class.

#include <iostream>
using namespace std;
#define n 10

class stack
{
private:
    int *arr;
    int top;

public:
    stack()
    {
        arr = new int[n];
        top = -1;
    }

    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "Stack Overflow." << endl;
        }
        else
        {
            top++;
            arr[top] = x;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow." << endl;
            return;
        }
        else
        {
            top--;
        }
    }

    void Top()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << arr[top] << endl;
        }
    }

    bool empty()
    {
        return top == -1;
    }
};

int main()
{
    stack st;

    st.push(1);
    st.Top();
    st.push(2);
    st.Top();

    st.pop();
    st.Top();
    st.pop();
    st.Top();

    return 0;
}