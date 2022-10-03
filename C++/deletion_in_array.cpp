#include <iostream>
using namespace std;

// When Value is given instead of position
int main()
{
    int size;
    cout << "enter the size of the array you want to create " << endl;
    cin >> size;
    int i, index, n;
    int a[size];
    cout << "enter the values of your array " << endl;
    for (i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    cout << "enter the number you want to delete in the array" << endl;
    cin >> n;
    for (i = 0; i < size; i++)
    {
        if (a[i] == n)
        {
            cout << "Data found at " << i + 1 << " position" << endl;
            break;
        }
    }
    if (i == size)
    {
        cout << " Can't delete ! Entered Data is not present in the array" << endl;
        exit(0);
    }
    index = i;
    for (i = index; i < size - 1; i++)
    {
        a[i] = a[i + 1];
    }
    size--;
    cout << "Array after deletimg the data" << endl;
    for (i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}