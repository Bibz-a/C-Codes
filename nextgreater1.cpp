#include <iostream>
using namespace std;
#include <vector>
#include <stack>
vector<int> nge(vector<int> v1){
    stack<int> s1;
    int length = v1.size();
    vector<int> v2;
    for(int i = length-1; i>=0; i--){
        while(!s1.empty( )&& s1.top()<v1[i]){
            s1.pop();
        }
        if(s1.empty()){
            v2.push_back(-1);
        }
        else{
            v2.push_back(s1.top());
        }
        s1.push(v1[i]);
    }
    for(int value: v2){
            cout<<value<<" ";
        }
        cout<<endl;
    return v2;
}
int main() {
    vector<int> v1 = {6,8,0,1,3};
    vector<int>v2;
    v2 = nge(v1);
    return 0;
}
