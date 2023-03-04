#include <stdio.h>
#include "sort.h"

void bubbleSort(int arr[] , int N){
        for(int i = 0 ; i < N-1 ; i++){
            for(int j = i+1 ; j < N ; j++){
                if(arr[i] > arr[j]){
                    int temp ; 
                    temp = arr[i]; 
                    arr[i] = arr[j]; 
                    arr[j] = temp; 
                }
            }
        }
}