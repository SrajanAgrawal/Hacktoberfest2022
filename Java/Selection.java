package Sorting;
import java.util.Arrays;
public class Selection {
    public static void main(String[] args) {

        int[] arr = {3,5,67,3,7,1};
        insertion(arr);
        System.out.println(Arrays.toString(arr));
        
    }

    static void selection(int[] arr){

        for (int i = 0; i < arr.length - 1; i++)  
        {  
            int index = i;  
            for (int j = i + 1; j < arr.length; j++){  
                if (arr[j] < arr[index]){  
                    index = j;//searching for lowest index  
                }  
            }  
            int smallerNumber = arr[index];   
            arr[index] = arr[i];  
            arr[i] = smallerNumber;  
        }  
}

    static void insertion(int[] arr){
        for(int i = 0; i < arr.length-1; i++){ 

            for(int j=i+1;j>0;j--){ 

                if(arr[j]<arr[j-1]){

                    int temp=arr[j];
                    arr[j]=arr[j-1];
                    arr[j-1]=temp;
                }
            }
        }


    }

}
