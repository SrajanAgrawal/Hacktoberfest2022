#include <bits/stdc++.h>
using namespace std;
 
// function to find the element
// occurring odd number of times
int getOddOccurrence(int arr[],int size)
{
     
    // Defining HashMap in C++
    unordered_map<int, int> hash;
 
    // Putting all elements into the HashMap
    for(int i = 0; i < size; i++)
    {
        hash[arr[i]]++;
    }
    // Iterate through HashMap to check an element
    // occurring odd number of times and return it
    for(auto i : hash)
    {
        if(i.second % 2 != 0)
        {
            return i.first;
        }
    }
    return -1;
}
 
int main()
{
    int arr[] = { 2, 3, 5, 4, 5, 2, 4,
                    3, 5, 2, 4, 4, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
     
    // Function calling
    cout << getOddOccurrence(arr, n);
 
    return 0;
}
