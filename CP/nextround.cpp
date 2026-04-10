#include <iostream>
using namespace std;
//kth place se zyada score, as long positive
//n participants


int main() {
    int k, n;
    cin>>n>>k;
    int* arr = new int[n];
    for(int i = 0; i < n ; i++){
        cin>>arr[i];
    }
    int compare = arr[k-1];
    int count = 0;
    for(int i = 0 ; i < n; i++){
        if(arr[i]>=compare && arr[i]>0){
            count++;
        }
    }
    delete arr;
    cout<<count;
    return 0;
}