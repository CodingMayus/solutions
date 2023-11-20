// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 2e5+5;
vector<ll>adj[mx];
ll values[mx];
ll start[mx],endd[mx],bit[mx];
bool visited[mx];
int timer =1;
	int n,q;

ll lsb(int x){return x&-x;}



void update(int pos,int x){
//	cout<<pos<<" "<<x<<"\n";
	while(pos<=mx){
		bit[pos]+=x;
	pos+=lsb(pos);
	}
}

long long query(int pos){
	long long res =0;
	while(pos>0){
		res+= bit[pos];
		pos-=lsb(pos);
	}
	return res;
}




void dfs(int prev, int cur){	
start[cur]=timer++;
update(start[cur],values[cur]); //
for(auto neighbour: adj[cur]){
	if(neighbour!=prev){
		dfs(cur,neighbour);
	}
}
endd[cur]=timer-1;
}
int main() {

	cin>>n>>q;

	for(int i=1;i<=n;i++) cin>>values[i];	
	for(int i=1;i<=n-1;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(-1,1);



// for(int i=1;i<=n;i++){

// cout<<start[i]<<' ';
// }
// cout<<endl;
// for(int i=1;i<=n;i++){
// 	cout<<endd[i]<<' ';
// }


	for(int i=1;i<=q;i++){
int type;
cin>>type;
if(type ==1){
int s,x;
cin>>s>>x;
update(start[s],-values[s]);
update(start[s],x);
values[s]=x;
}
if(type == 2){
int s;
cin>>s;

cout<<query(endd[s])-query(start[s]-1)<<"\n";
}
	}
}
