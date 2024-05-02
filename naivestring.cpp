#include <iostream>
#include <string.h>
using namespace std;

int match(string s,string t){
    int n=s.length();
    int m=t.length();
    for (int i=0;i<=n-m;i++){
        int j;
        for(j=0;j<m;j++){
            if (s[i+j]!=t[j])
                break;
        }
        if (j==m){
            return i;
        }
    }
    return -1;
}
int main() {
    string txt1 = "AABAACAADAABAABA";
    string pat1 = "AABA";
    cout << "Example 1: " << endl;
    cout<<match(txt1, pat1)<<endl;
    
    string txt2 = "agd";
    string pat2 = "g";
    cout << "\nExample 2: " << endl;
    cout<<match(txt2,pat2)<<endl;

    return 0;
}