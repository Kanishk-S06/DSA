#include <iostream>
#include <string>
#include <algorithm>
#include <cfloat>
using namespace std;

#define mk_pair pair<double,double>

mk_pair intersection_for(mk_pair x,mk_pair y,mk_pair z,mk_pair w){
    double a1=y.second-x.second;
    double b1=x.first-y.first;
    double c1=a1*(x.first)+b1*(x.second);

    double a2=w.second-z.second;
    double b2=z.first-w.first;
    double c2=a2*(z.first)+b2*(z.second);

    double det=a1*b2-a2*b1;
    if (det==0){
        return mk_pair(FLT_MAX,FLT_MAX);
    }
    else{
        double x1=(b2*c1-b1*c2)/det;
        double x2=(a1*c2-a2*c1)/det;
        return mk_pair(x1,x2);
    }
}


int main(){
   mk_pair q = make_pair(2, 1);
   mk_pair r = make_pair(2, 7);
   mk_pair s = make_pair(4, 4);
   mk_pair t = make_pair(6, 4);
   mk_pair inter = intersection_for(q, r, s, t);
   if (inter.first == FLT_MAX && inter.second==FLT_MAX) {
      cout << "The given lines AB and CD are parallel.\n";
   } else {
      cout << "The intersection of the given lines AB and CD is: ";
      cout<<inter.first<<" "<<inter.second<<endl;
   }
   return 0;

}

