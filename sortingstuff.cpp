#include <iostream>
#include <vector>
using namespace std;
//best o(n)  avg/worst O(n^2)
void bubble(int arr[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(arr[j+1]>arr[j]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]=temp;
            } 
        }
    }
}

//best o(n)  avg/worst O(n^2)
void insertion(int arr[], int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i-1;
            while(j>=0 && arr[j] > key){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;

    }
}
//best worst avg all n^2
void selectionsort(int arr[], int n){
     for(int i = 0 ; i < n-1;i++){
        int minindex = i;

        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[minindex]){
                minindex = j;
            }
        }
        swap(arr[i], arr[minindex]);
     }
}


void countingSort(int arr[], int n, int maxVal){
    int count[maxVal + 1] = {0};

    // Count occurrences
    for(int i = 0; i < n; i++){
        count[arr[i]]++;
    }

    // Rebuild sorted array
    int index = 0;
    for(int i = 0; i <= maxVal; i++){
        while(count[i] > 0){
            arr[index] = i;
            index++;
            count[i]--;
        }
    }
}


int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while(true){
        while(i <= high && arr[i] <= pivot)
            i++;

        while(arr[j] > pivot)
            j--;

        if(i >= j)
            break;

        swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);  // put pivot in correct place
    return j;
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi = partition(arr, low, high);
         quickSort(arr, low, pi - 1);
         quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int mid, int start, int end){
    vector<int> temp;
    int i = start;
    int j = mid + 1;

    while(i<=mid && j <= end){
        if(arr[i]<= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }

    int m = 0;
  for(int k = 0; k < temp.size(); k++){
    arr[start+k] = temp[k];
}
}
void mergesort(int arr[], int start, int end){
    if(start>=end){
        return;
    }
    int mid = start + (end - start)/2;

    mergesort(arr, start, mid);
    mergesort(arr, mid+1, end);

    merge(arr, mid, start, end);
}

int main(){
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = 7;

    countingSort(arr, n, 8);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
