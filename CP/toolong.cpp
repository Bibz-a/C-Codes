#include <iostream>
using namespace std;
#include <string>

void toolong(string x){
    if(x.length() <= 10){
        cout<<x<<endl;
        return;
    }

    char f = x[0];
    char l = x[x.length()-1];
    int len = x.length() - 2;
    string out = f + to_string(len) + l;
    cout<<out<<endl;
}
int main() {
    int n;
    cin>>n;
    string word;
    for(int i = 0; i < n; i++){
        cin>>word;
        toolong(word);
    }
    return 0;
}