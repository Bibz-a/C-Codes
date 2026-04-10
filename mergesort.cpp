#include <iostream>
using namespace std;
#include <vector>
void merge(vector<int> &arr, int start,int mid, int end){
    vector<int> temp;
    int i = start; //O(n)
    int j = mid + 1;

    while(i<mid+1 && j < end + 1){
        if(arr[i]<arr[j]){
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

    for(int idx = 0; idx < temp.size(); idx++){
        arr[idx + start]  = temp[idx];
    }
}
void mergesort(vector<int> &arr, int start, int end){
    if(start<end){
        int mid = start + (end - start)/2;
        //call for left
        mergesort(arr, start, mid);
        //call for right
        mergesort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }

    
}


int main() {
    vector<int> arr = {17, 31, 35, 8, 32, 17};
    mergesort(arr, 0, arr.size()-1);
    for(int a : arr){
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}
