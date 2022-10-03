//using int as a return type
package com.programs;

public class LinearSearch {

	public static void main(String[] args) {
		int[] arr= {1,3,4,6,8,2,34,6};
		for(int num:arr) {
			System.out.print(num+" ");
		}
		System.out.println();
		int valAt=linearSearch(arr,10);
		System.out.println("value found at index::"+valAt);
	}

    public static int linearSearch(int[] arr,int target) {
    	if(arr.length==0) {
    		return -1;
    	}
    	for(int index=0;index<arr.length;index++) {
    		if(arr[index]==target) {
    			return index;
    		}
    	}
    	return -1;
    }
}
	
