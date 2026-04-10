#include <iostream>
using namespace std;
string square(int x, int y, int z, int w)
{
    if(x == y && x == w && y == z){
        return "YES";
    }
    else{
        return "NO";
    }
}
int main() {
    int n;
    cin>>n;
    int x,y,z,w;
    for(int i=0; i < n; i++){
        cin>>x>>y>>z>>w;
        cout<<square(x,y,z,w)<<endl;
    }
    return 0;
}