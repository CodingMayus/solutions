// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
const int mx = 1e6+5;
int jump[mx],dp[mx];
vector<int> minn;
//from i - i+d the min value

//utilize a sliding window in order to accomodate the range of d to get within
//necessary time constraints.
int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
int n,d;
cin>>n>>d;
for(int i=1;i<=n;i++){
	
cin>>jump[i];
if(i!=1&&i<=d){
	dp[i]=jump[i]+jump[1];
	}
}
dp[1]=jump[1];
deque<int>LOL;
for(int i=1;i<=d;i++){
if(i!=1)dp[i]=jump[i]+jump[1];


while(!LOL.empty()&&dp[LOL.back()]>dp[i]){
	LOL.pop_back();
}
LOL.push_back(i);
}
// if(!LOL.empty()){
// minn.push_back(jump[LOL.front()]);
// }
// for(int i=d+1;i<=n;i++){
// 		minn.push_back(LOL.front());
// 	// cout<<jump[LOL.front()]<<endl;
// 	if(!LOL.empty()&&LOL.front()<=i-d){
// 	LOL.pop_front();
// }
// 	while(!LOL.empty()&&jump[LOL.back()]>jump[i]){
// 		LOL.pop_back();
// 	}
// 	LOL.push_back(i);
// }
// minn.push_back(LOL.front());

// for(auto ele: minn){
// 	cout<<ele<<endl;
// }

for(int i=d+1;i<=n;i++){
int minval = dp[LOL.front()];
dp[i]=jump[i]+minval;
if(!LOL.empty()&&LOL.front()<=i-d){
	LOL.pop_front();
}
while(!LOL.empty()&&dp[LOL.back()]>dp[i]){
	LOL.pop_back();
}
LOL.push_back(i);
}
// for(int i=1;i<=n;i++){
// 	cout<<dp[i]<<endl;
// }
cout<<dp[n]<<"\n";
}