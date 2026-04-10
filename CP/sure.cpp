#include <iostream>
using namespace std;
int sure(int x, int y, int z){
    int sum = x + y + z;
    if(sum >=2){
        return 1;
    }
    else{
        return 0;
    }
}
int main() {
    int n, x,y,z;
    cin>>n;
    int solve = 0;
    for(int i = 0 ; i < n; i++){
        cin>>x>>y>>z;
        solve = solve + sure(x, y, z);
    }
    cout<<solve;
    return 0;
}