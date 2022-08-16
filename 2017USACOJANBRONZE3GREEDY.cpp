#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <bits/stdc++.h>

#include <cmath>
//I DID IT MYSELF!!!!WOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
int ans;
int a[11][11];
using namespace std;

int n=0;
void output(){
    cout<<("\n");
for(int i=0;i<n;i++){

    for(int j=0;j<n;j++){

        cout<<a[i][j]<<" ";
    }
    cout<<"\n";
}
}
bool check(){
for(int i=0;i<n;i++){
    for(int j =0;j<n;j++){

        if(a[i][j]==1){

            return false;
        }
    }

}

return true;
}
void rectangletip (int i,int j){


    if(a[i][j]==1){
               ans++;
        for(int g=0;g<=i;g++){
            for(int e=0;e<=j;e++){
                if(a[g][e]==0){
                     a[g][e]=1;

                }else if( a[g][e]==1){
                 a[g][e]=0;

              //   output();
                }

            }

        }

    }


}





int main() {
    int amount;
    freopen("cowtip.in", "r", stdin);

    freopen("cowtip.out", "w", stdout);



    cin>>n;

    for(int i=0;i<n;i++){
            string inpute;
    cin>>inpute;


    for(int j=0;j<inpute.size();j++){
            a[i][j]=inpute[j]-'0';
//'0' => 48
//'1' => 49  chars are represented by a number, so thats why subtracting removes it!

    }
  //  output();
    }

    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){


              rectangletip(i,j);
              //output();


        }
       // cout<<"\n";

    }
    cout<<ans;




}
