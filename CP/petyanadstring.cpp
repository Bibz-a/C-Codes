#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    cin>>a;
    string b;
    cin>>b;

    int out = 0;
    for(int i = 0 ; i<a.length(); i++){
        if(tolower(a[i])<tolower(b[i])){
            out = -1;
            break;
        }
        else if(tolower(b[i])<tolower(a[i])){
            out = 1;
            break;
        }
    }
    cout<<out;
    return 0;
}