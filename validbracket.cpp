#include <iostream>
using namespace std;
#include <stack>

bool validbracket(string x){
    stack<char> s1;
    int len = x.length();
    for(int i = 0;i<len; i++){
        if(x[i] == '(' || x[i] == '{' || x[i] == '['){
            s1.push(x[i]);
        }
        else if (x[i] == ')' || x[i] == '}' || x[i] == ']'){
            if (s1.empty()) return false;
            char c = x[i];
            char top = s1.top();
             if ((c == ')' && top == '(') ||
                (c == '}' && top == '{') ||
                (c == ']' && top == '[')) {
                s1.pop();
            } else {
                return false;
            }
        }
    }
    return s1.empty();
}
int main() {
    
    string x = "[]";
    if(validbracket(x) == 1){
        cout<<"yeah";
    }
    else{
        cout<<"no";
    }
    return 0;
}