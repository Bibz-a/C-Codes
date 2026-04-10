#include <iostream>
using namespace std;

int main() {
    string user;
    cin>>user;
    int s = 0;
    int m = 0;
    char arr[26];

    for(int i = 0; i < user.length(); i++){
           bool found = false;
           for(int k = 0; k < m; k++){
                if(arr[k]==user[i]){
                    found = true;
                    break;
                }
           }

           if(found == false){
            s++;
            arr[m]=user[i];
            m++;
           }
    }
    if(s%2 == 0){
        cout<<"CHAT WITH HER!";
    }
    else{
        cout<<"IGNORE HIM!";
    }
    return 0;
}