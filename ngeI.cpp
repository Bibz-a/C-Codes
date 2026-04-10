#include <iostream>
using namespace std;
#include <stack>
#include <vector>


int main() {
    vector<int> arr = {1,6,5,12,0};
    vector<int> arr2 = {6,5,1};
    int count = 0;
    int i = 0;
    int n = arr.size();
    stack<int> s1;
    vector<int> ans(n, -1);

    for(int i = arr.size()-1; i>-1; i--){
        while(!s1.empty() && arr[i]>=s1.top()){
            s1.pop();
        }
        if(s1.empty()){
            ans[i] = -1;
        }

        else{
            ans[i] = s1.top();
        }

        s1.push(arr[i]);
    }
    cout << "NGE for arr: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << "->" << ans[i] << "  ";
    cout << endl;

    vector<int> final;
    for (int val : arr2) {
        for (int j = 0; j < n; j++) {
            if (arr[j] == val) {
                final.push_back(ans[j]);
                break;
            }
        }
    }

    cout << "NGE for arr2: ";
    for (int i = 0; i < arr2.size(); i++)
        cout << arr2[i] << "->" << final[i] << "  ";
    cout << endl;
    return 0;
}