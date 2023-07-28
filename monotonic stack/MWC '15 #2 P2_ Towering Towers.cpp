// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
//typical monostack problem.
//nearest greatest one.
#define pb push_back
#define p push
vector<int>h;
stack<pair<int,int>>mono;
const int mx = 1e6+5;
int a[mx];
int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
int temp;
cin>>temp;
h.pb(temp);

	}
	mono.p({INT_MAX,-1});
	for(int i=0;i<n;i++){
		while(!mono.empty()&&mono.top().first<=h[i]){
			mono.pop();
		}
		if(!mono.empty()&&mono.top().first>h[i]){
			a[i]=mono.top().second;
		}
		mono.p({h[i],i});
	}
	for(int i=0;i<n;i++){
		int start;
		if(a[i]<0){
			cout<<i<<" ";
		}else{

				cout<<i-a[i]<<" ";
		}

	}
}