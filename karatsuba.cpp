#include <iostream>
#include <string>
#include <math.h>
using namespace std;

long karatsuba(long a, long b) {
    if (a<10 || b< 10)
        return a*b;
    int n = max(to_string(a).size(), to_string(b).size()) / 2;
    long p = a / pow(10, n);
    long q = a % (long)pow(10, n);
    long r = b / pow(10, n);
    long s = b % (long)pow(10, n);
    long pr = karatsuba(p,r);
    long qs = karatsuba(q,s);
    long prqs = karatsuba((p+q),(r+s)) - pr - qs;
    return (pr * pow(10, 2 * n) + prqs * pow(10, n) + qs);
}

int main() {
    long a;
    long b;
    cin>>a;
    cin>>b;
    cout << karatsuba(a, b) << endl;
    return 0;
}
