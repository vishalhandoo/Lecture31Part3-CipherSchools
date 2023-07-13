#include<bits/stdc++.h>
using namespace std;


void merge(int *arr,int start , int end){
    int mid = (start+end)/2;
    int len1,len2;
    len1=mid-start+1;
    len2=end-mid;

    int* arr1 = new int[len1];
    int* arr2 = new int[len2];

    int arr_index=start;
    int i;
    for(i = 0 ; i < len1 ;i++){
        arr1[i]=arr[arr_index];
        arr_index++;
    }
    for(i = 0 ; i < len2 ;i++){
        arr2[i]=arr[arr_index];
        arr_index++;
    }

    int index_1,index_2;
    index_1=0;
    index_2=0;
    arr_index=start;
    while(index_1<len1&&index_2<len2){
        if(arr[index_1]<arr2[index_2]){
            arr[arr_index]=arr1[index_1];
            index_1++;
            arr_index++;
        }
        else{
             arr[arr_index]=arr2[index_2];
            index_2++;
            arr_index++;
        }
    }
    while(index_1<len1){
        arr[arr_index]=arr1[index_1];
            index_1++;
            arr_index++;
    }
    while(index_2<len2){
            arr[arr_index]=arr2[index_2];
            index_2++;
            arr_index++;
    }

}


void mergeSort(int *arr, int start , int end){
    

    int mid;
    mid = (start+end)/2;
    if(start>=end){
        return;
    }
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,end);


}


int main(){
    int arr[5]={1,5,10,4,3};
    int size=5;
    mergeSort(arr,0,4);
    
    for(int i = 0 ; i < size ;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}