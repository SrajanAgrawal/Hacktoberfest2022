#include <iostream>
using namespace std;
 

{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}
 

int main()
{
    int num = 5;
    cout << "Factorial of "
         << num << " is " << factorial(num) << endl;
    return 0;
}
