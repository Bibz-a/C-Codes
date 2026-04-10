#include <iostream>
using namespace std;
#include <stack>
#include <string>

string bubblesort(string a){
    int l = a.length();
    for(int i = 0 ; i < l - 1; i++){
        for(int j = 0; j < l - i - 1; j++){

            if(a[j]>a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
    return a;
}
void removedupes(string a){
    a = bubblesort(a);
    stack<char> s1;
    int l = a.length();
    for(int i = 0; i<l; i++){
        if(s1.empty()){
            s1.push(a[i]);
        }
        else{
            char c = s1.top();
        if(c != a[i]){
            s1.push(a[i]);
        }
        }
        
    }
    string out = "";
    while(!s1.empty()){
        out = out + s1.top();
        s1.pop();
    }
    out = bubblesort(out);
    cout<<out;
}
int main() {
    string a = "cbacdcbc";
    removedupes(a);


    return 0;
}