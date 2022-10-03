#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cout<<"Enter the size of array: ";
	cin>>n;
	int arr[n];
	cout<<"Enter a sorted array: ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Enter the number to be searched: ";
	cin>>m;
	if(!is_sorted(arr,arr+n)){
		cout<<"Given array is not sorted";
	}
	else{
		int index = -1;
		int low=0,high=n-1;
		while(low<=high){
			int mid = (low+high)/2;
			if(arr[mid]==m){
				index = mid;
				break;
			}
			else if(arr[mid]>m){
				high = mid-1;
			}
			else{
				low = mid+1;
			}
		}
		if(index==-1){
			cout<<"Value not found";
		}
		else{
			cout<<"Value found at index "<<index;
		}
	}
}
