#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin>>m>>n;
    int rec;
    rec = m*n;
    int domin = 2;
    int num = rec/domin;
    cout<<num;
    return 0;
}