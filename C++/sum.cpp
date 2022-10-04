#include <iostream>
using namespace std;
int main()
{
int n, number, sum;
cin>>n;
sum = 0;
number = 1;
do
{
    sum+=number;
    number++;
}
while (number<=n);
{
    cout<<sum;
}

return 0;
}
