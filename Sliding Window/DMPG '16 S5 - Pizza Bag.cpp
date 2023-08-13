/*

Matthew Yu
	*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 1e5 +5;
ll a[2*mx],prefix[2*mx];
int main() {
int n,k;
cin>>n>>k;
for(int i=1;i<=n;i++){
cin>>a[i];
a[i+n]=a[i];
}
// for(int i=1;i<=2*n;i++){
// 	//cout<<a[i]<<endl;
// }
for(int i=1;i<=2*n;i++){
		prefix[i]=prefix[i-1]+a[i];
	//	cout<<prefix[i]<<endl;
		//cout<<prefix[i]<<"\n";
}
ll ans=-INT_MAX;
deque<ll>poop;
for(int i=1;i<=k;i++){
	while(!poop.empty()&&prefix[poop.back()]<prefix[i]){
		poop.pop_back();
	}
	poop.push_back(i);
}
for(int i=k+1;i<=2*n;i++){
ans=max(ans,prefix[poop.front()]-prefix[i-k-1]);
//cout<<poop.front()<<"\n";
if(!poop.empty()&&poop.front()<=i-k){
	poop.pop_front();
}
while(!poop.empty()&&prefix[poop.back()]-prefix[i-k]<prefix[i]-prefix[i-k]){
poop.pop_back();
}
poop.push_back(i);
}
ans=max(ans,prefix[poop.front()]-prefix[2*n-k]);

cout<<ans<<"\n";
//sliding window

}
