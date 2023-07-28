// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  p push
const int mx = 3e5 +5;
/*
Matthew Yu
Essentially just monostacking one way 
then the other in order to get all cases.
--> when a given position is the bigger of a range.
--> when a given position is the lesser of a range.
*/
ll distance=0;
int a[mx],ans[mx];
int ans2[mx];
stack<pair<int,int>>mono;
void cleare(){
while (!mono.empty()) {
        mono.pop();
    }
}
int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	cin>>a[i];
	}
	mono.p({INT_MAX,-1});
	for(int i=0;i<n;i++){
		while(!mono.empty()&&mono.top().first<=a[i])mono.pop();
		if(!mono.empty()&&mono.top().first>a[i]){
			ans[i]=mono.top().second;
		}
		mono.p({a[i],i});
	}
	cleare();
	mono.p({INT_MAX,-1});
	reverse(a,a+n);
	for(int i=0;i<n;i++){
		while(!mono.empty()&&mono.top().first<=a[i])mono.pop();
		if(!mono.empty()&&mono.top().first>a[i]){
		ans2[i]=mono.top().second;
		}
		mono.p({a[i],i});
		
			}
			// for(int i=0;i<n;i++){
			// 	cout<<ans[i]<<" ";
			// }
			// cout<<endl;
			// for(int i=0;i<n;i++){
			// 	cout<<ans2[i]<<" ";
			// }
ll res =0;
for(int i=0;i<n;i++){
	int start = ans[i];
	if(start==-1)continue;
	if(i-start+1==2){
		continue;
	}else{

		res+= i-start+1;
	}
}
for(int i=0;i<n;i++){
	int start = ans2[i];
	if(start==-1)continue;
	if(i-start+1==2){
		continue;
	}else{

		res+= i-start+1;
	}
}
res+= 2*(n-1);
cout<<res<<"\n";
	}

	
