#include <bits/stdc++.h>
using namespace std;
int capacity[4];
int amount[4];
void pour(int a,int b){
int pouramount = min({amount[a],capacity[b]-amount[b]});


amount[a]-=pouramount;
amount[b]+=pouramount;


}
int main() {
	freopen("mixmilk.in", "r", stdin);
	freopen("mixmilk.out", "w", stdout);

	for(int i=0;i<3;i++){
        cin>>capacity[i];
       cin>> amount[i];
	}
	for(int i=0;i<100;i++){

       int pourfrom = i%3;
       int pourto = (i+1)%3;

        pour(pourfrom,pourto);


	}

	for(int i=0;i<3;i++){
        cout<<amount[i]<<"\n";
	}

}
