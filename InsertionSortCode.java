package InsertionSort;

import java.util.Arrays;

public class InsertionSortCode {
    public static void main(String[] args) {
        int[] arr = {-96,1,-96,0,65,-9,36,-4};
        insertionSort(arr);
        System.out.println(Arrays.toString(arr));
    }
    static void insertionSort(int[] arr){
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = i + 1; j > 0 ; j--) {
                if(arr[j] < arr[j-1]){
                    swap(arr,j,j-1);
                }else{
                    break;
                }
            }
        }
    }
    static void swap(int[] arr, int first, int second){
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
}

/*
Time Complexity
(1). Best Case :- O(n)
(2). Worst Case :- O(n^2)

-> Insertion sort is stable
-> Insertion sort partially sorts the array
-> Insertion sort is adaptive 
(steps get reduced if array is already sorted) 
(compared to bubble sort, comparisons are less in insertion sort, 
though both have worst case time complexity O(n^2), 
hence insertion sort is optimized version than bubble sort)
*/
