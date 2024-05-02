#include <iostream>
#include <vector>
using namespace std;

struct point{
    int a;
    int b;
};
vector<point> sol;
int orientation(struct point p,struct point q,struct point r){
    int k=(r.a-q.a)*(q.b-p.b)-(q.a-p.a)*(r.b-q.b);
    if(k==0) return 0;
    return (k<0) ? 1 : 2;
}

void convexhull(point points[], int n) {
    if (n<3) return ;
    int l=0;
    for (int i=1;i<n;i++){
        if (points[l].a>points[i].a){
            l=i;
        }
    }
    int p=l;
    int q;
    do {
        sol.push_back(points[p]);
        q=(p+1)%n;
        for (int i=0;i<n;i++){
            if(orientation(points[p],points[i],points[q])==2){
                q=i;
            }
        }
        p=q;
    }while(p!=l);
}

int main()
{
    struct point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1},
                      {3, 0}, {0, 0}, {3, 3}};
    int n = sizeof(points)/sizeof(points[0]);
    convexhull(points, n);
    for (int i=0;i<sol.size();++i)
    	cout << "("<<sol[i].a<<","<<sol[i].b<<") ";
    cout << endl;
    return 0;
}
