#include <iostream>
using namespace std;
void bit(string x1, int &x){
    if(x1[1]=='+'){
        x++;
    }
    else{
        x--;
    }
}

//mid ki value se determine karra
int main() {
    int n;
    int x = 0;
    string in;
    cin>>n;
    for(int i = 0; i < n ; i++){
        cin >> ws >> in;
        bit(in, x);
    }
    cout<<x;
    return 0;
}
