// Source: https://usaco.guide/general/io
#include "bits/stdc++.h"

#include <iostream>
#include <iomanip>

//initalizing arrays globballly or initalizing manualing is hwo
//to get rid of grabage values in array
using namespace std;
int n, m;
int main() {
     double temp=1;
     cin>>n>>m;

     double ae[n];
    for(int i=0;i<n;i++){
        ae[i]=0.0;

    }
    
  
    for(int i=0;i<m;i++){
        int position;
        double percent;
        cin>>position>>percent;
        percent = percent/100;
        position--;

double lost= temp * percent;
temp = temp - lost;
        ae[position]= ae[position] + lost;
        


        

    }

    for(int i=0;i<n;i++){

        cout<<fixed<< setprecision(6) << ae[i];;
        cout<<"\n";

    }
}
