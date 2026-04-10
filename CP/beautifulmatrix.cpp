#include <iostream>
using namespace std;

int main() {
    int arr[5][5];
    int j = 1;
    for(int i = 1;i<=5;i++){
        cin>>arr[i][j]>>arr[i][j+1]>>arr[i][j+2]>>arr[i][j+3]>>arr[i][j+4];
    }
    int row;
    int col;
    for(int i = 1; i<=5;i++){
        for(int j = 1; j<=5 ; j++){
            if(arr[i][j]==1){
                row = i;
                col = j;
            }
        }
    }
    int rmoves = 0;
    if(row != 3){
       while(row!=3){
        if(row<3){
            row++;
            rmoves++;
        }
        else{
            row--;
            rmoves++;
        }
       }
    }
    int cmoves = 0;
    if(col != 3){
        while(col!=3){
        if(col<3){
            col++;
            cmoves++;
        }
        else{
            col--;
            cmoves++;
        }
       }
    }

    int total = cmoves + rmoves;
    cout<<total;
    return 0;
}