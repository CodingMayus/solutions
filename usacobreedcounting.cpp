#include <iostream>
#include "bits/stdc++.h"
using namespace std;
   int n,q;

   vector<int>test;
int main() {

    vector<int>a(100001);
    vector<int>prefixa(100002);
    vector<int>prefixb(100002);
    vector<int>prefixc(100002);
    vector<int>b(100001);
    vector<int>c(100001);
    freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);

    cin>>n>>q;
    for(int i=1;i<n+1;i++){

            int input;
    cin>>input;
    if(input==1){
        a[i]=1;

    }if(input==2){
        b[i]=1;
    }if(input == 3){
        c[i]=1;
    }


    }

    for(int i=1;i<n+1;i++){
        prefixa[i]=prefixa[i-1]+a[i];
        prefixb[i]=prefixb[i-1]+b[i];
        prefixc[i]= prefixc[i-1]+c[i];
    }
    for(int i=0;i<q;i++){
        int a,b;

        cin>>a>>b;

        cout<<prefixa[b]-prefixa[a-1]<<" ";
        cout<<prefixb[b]-prefixb[a-1]<<" ";
        cout<<prefixc[b]-prefixc[a-1]<<"\n";


    }



}
