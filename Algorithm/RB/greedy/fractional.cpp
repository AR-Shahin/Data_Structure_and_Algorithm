#include<bits/stdc++.h>
using namespace std;

struct item{
    double w , p , u;
};

bool compare(item a ,item b){
    return a.u > b.u;
}

int main(){

    int n,W;
    cin>>n>>W;
    item arr[n];
    for (int i =0;i<n;i++){
        cin>>arr[i].w >> arr[i].p;
        arr[i].u = arr[i].p / arr[i].w;
    }

/*
    for(int i =0;i<n;i++){
        cout<<arr[i].w <<" "<<arr[i].p<<" " <<arr[i].u<<endl;
    }
    */

    sort(&arr[0],&arr[n],compare);

    int P = 0;

    for(int i =0;i<n;i++){
        cout<<arr[i].u<< " ";
    }
    cout<<endl;
    for(int i =0;i<n;i++){
        if(W > arr[i].w){
            P = P +  arr[i].p;
            W = W -  arr[i].w;
        }else{
            P = P + W * arr[i].u;
            W = 0;
        }
    }

    cout<<"Total Profit = "<<P;
    return 0;
}

