#include<iostream>
using namespace std;

//First way of doing the factorial of a given number 

int fact(int n)
{
    if (n==0 || n==1)
        return 1;
    else
      return n*(fact(n-1));
}

int main()
{    
    int n;
    cout << "Enter the number for factorial::";
    cin>>n;
    
    cout<<fact(n);
}

//Second way to do the same thing in c++
int factorial(int n){
    if(n==1){
        return 1;
    }
    return n*factorial(n-1);
}
int main(){
    int n;
    cin>>n;
    cout<<factorial(n)<<endl;

    return 0;

}
