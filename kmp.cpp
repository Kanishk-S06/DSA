#include <iostream>
#include <string>
using namespace std;

void computelps(string p,int m,int lps[]){
    int len=0;
    int i=1;
    lps[0]=0;
    while(i<m){
        if (p[i]==p[len]){
            lps[i]=len+1;
            i++;
            len++;
        }
        else{
            if (len!=0){
                len=lps[len-1];
            }else{
                lps[i]=0;
                i++;
            }
        }
    }
}
void kmp(string s, string p) {
    int n = s.size();
    int m = p.size();
    int lps[m];
    int j = 0;
    int i = 0;
    computelps(p, m, lps);

    while (i < n) {
        if (p[j] == s[i]) {
            j++;
            i++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && p[j] != s[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}


int main() {
    string txt = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";
    cout << "Text: " << txt << endl;
    cout << "Pattern: " << pat << endl;
    kmp(txt, pat);
    return 0;
}
