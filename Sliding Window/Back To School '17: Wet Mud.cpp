// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
deque<int>poop;
#define pb push_back
#define popb pop_back
#define popf pop_front
#define pf push_front
const int mx =1e5+5;

/*


Matthew Yu

Typical Implementation

*/
const int INF = INT_MAX;
vector<int>a(mx,INF),answer;

int main() {
int n,m,j;
cin>>n>>m>>j;
if(j==0&&n!=0){
	cout<<-1<<endl;
	return 0;
}
//sliding window of size j
//ending is -999999999999
//empty areas are 99999999999
//minimum deque
a[n+1]=-INF;
for(int i=0;i<m;i++){
	int p,t;
	cin>>p>>t;
	a[p]=t;
}

for(int i=1;i<=j;i++){
	
	while(!poop.empty()&&a[poop.back()]>a[i]){
		poop.popb();
	}
		poop.pb(i);
	
}
for(int i=j+1;i<=n;i++){
	answer.pb(a[poop.front()]);
	    if(!poop.empty()&&poop.front()==i-j){
            poop.pop_front();
        }
	while(!poop.empty()&&a[poop.back()]>a[i]){
		poop.popb();
	}
	        poop.push_back(i);

}
	answer.pb(a[poop.front()]);

// while(pos<=n){

// }
int ans=-INF;
for(auto element: answer){
	ans = max(ans, element);
//cout<<element<<endl;
}
if(ans == INT_MAX){
	cout<<-1<<endl;
}else if (ans==-INF){
	cout<<0<<endl;
}else{
	cout<<ans<<"\n";
}
}

	
