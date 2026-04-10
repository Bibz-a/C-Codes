#include <iostream>
#include <string>
using namespace std;
string check(string t, string s){
    if(t.length()!=s.length()){
        return "NO";
    }
    bool ok = 0;
    char a;
    for(int i = 0; i<s.length(); i++){
        a = s[i];
        int scount = 0;
        for(int k = 0; k<s.length(); k++){
            if(a == s[k]){
                scount++;
            }
        }
        ok = 0;
        int tcount = 0;
        for(int m = 0; m<s.length(); m++){
                if(a == t[m]){
                    tcount++;
            }
        }
        for(int j = 0; j<s.length(); j++){
            if(a == t[j]){
                ok = 1;

                if(tcount != scount){
                    ok = 0;
                }
            }
        }

        if(ok == 0){
            return "NO";
        }
    }
    return "YES";
}
int main() {
    int q;
    int n;
    string s;
    string t;
    
    cin>>q;
    for(int i = 0; i < q; i++){
        cin>>n>>t>>s;
        cout<<check(s, t)<<endl;
    }
    return 0;
}