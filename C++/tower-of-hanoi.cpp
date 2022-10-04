#include<iostream>
using namespace std;

void toh(int n,int a,int b,int c)
{
    if(n>0)
    {
        toh(n-1,a,c,b);
        printf("moving from %d to %d\n",a,c);
        toh(n-1,b,a,c);
    }
}

int main()
{
    // this is an example of toh
    toh(6,1,2,3);
    return 0;
}
