package BubbleSort;

import java.util.Arrays;

public class BubbleSortCode {
    public static void main(String[] args) {
        int[] arr = {23,65,33,-1,34,0,12,8,20};
        bubbleSort(arr);
        System.out.println(Arrays.toString(arr));
    }
    static void bubbleSort(int[] arr){
        boolean swapped;
        // run the steps n-1 times
        for (int i = 0; i < arr.length; i++) {
            swapped = false;
            // for each step, max item will come at the last respective index
            for(int j = 1; j < arr.length - i; j++){
                // swap if the item is smaller than the previous item
                if(arr[j] < arr[j-1]){
                    // swap
                    int temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                    swapped = true;
                }
            }
            // if you did not swap for a particular value of i, it means the array is sorted hence stop the program
            if(!swapped){
                break;
            }
        }
    }
}

/*
Bubble sort is also called as
(1). Sinking Sort
(2). Exchange Sort

Time Complexity
(1). Best Case :- O(n)
(2). Worst Case :- O(n^2)

Bubble sort is stable
*/
