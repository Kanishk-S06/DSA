#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
#define N 6	
struct Activity{
    int start,finish;
};
bool sort_Activity(Activity s1,Activity s2){
    return (s1.finish<s2.finish);
}

void ActivityP(Activity arr[],int n){
    sort(arr,arr+n,sort_Activity);
    int j=0;
    cout<<"("<<arr[0].start<<", "<<arr[0].finish<<")"<<endl;
    for (int i=1;i<n;i++){
        if (arr[i].start>arr[j].finish){
            cout<<"("<<arr[i].start<<", "<<arr[i].finish<<")"<<endl;
            j=i;
        }
    }
}

int main() {
    Activity arr[N];
	for(int i=0; i<=N-1; i++)
	{
		cout<<"Enter the start and end time of "<<i+1<<" activity \n";
		cin>>arr[i].start>>arr[i].finish;
    }
    ActivityP(arr,N);
    return 0;
}
