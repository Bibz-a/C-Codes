#include <iostream>
using namespace std;


void countsort(int arr[], int n){   
    int k = arr[0]; //how many values in count array 
    for(int i = 0; i < n ; i++){
        k = max(k, arr[i]);
    }

    int count[k+1] = {0}; 
    for(int i = 0; i<n;i++){
        count[arr[i]]++; //count each elements 
    }


    for(int i = 1; i<=k;i++){
        count[i] += count[i-1]; //calculating cumulative position
    }

    int output[n] = {0};

    for(int i = n -1; i>=0;i--){
        output[--count[arr[i]]] = arr[i];
    }

    for(int i = 0; i<n;i++){
        arr[i] = output[i];
    }
}


void countSortByDigit(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[--count[digit]] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        maxVal = max(maxVal, arr[i]);
    }

    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countSortByDigit(arr, n, exp);
    }
}

int main() {
    cout<<"-------------------COUNT-----------"<<endl;
    int arr[9] = {1,3,2,3,4,3,1,6,2};
    countsort(arr, 9);
    for(int i = 0; i < 9; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"-------------------RADIX-----------"<<endl;
    radixSort(arr,9);
    for(int i = 0; i < 9; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}