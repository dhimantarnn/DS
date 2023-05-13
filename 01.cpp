// WAP for removing duplicate values from an array

#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter a range: ";
    cin >> n;

    int arr[n], j = 0;
    srand((unsigned)time(NULL));

    // creating array
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 5;
    }

    // displaying array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }

    cout << endl;

    // sorting array
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }

    // deleting duplicates
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            arr[j] = arr[i];
            cout << arr[j] << ", ";
            j++;
        }
    }

    return 0;
}