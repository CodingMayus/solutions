/*

Matthew Yu
Offline Query + Value BIT
	*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 2e5+5;
struct que{
	int k,l,r,origpos;
	ll ans;
};
ll bit[mx];
bool visited[mx];
ll answer[mx];
vector<pair<ll,ll>>values;
//val, origpos
vector<que>queries;
	int n,q;

bool comp(que X, que Y){

			return X.k<Y.k;

}
bool comp2(que X, que Y){
	return X.origpos<Y.origpos;
}
int lsb(int x){
	return x&-x;
}
void update(int pos,int val){
	while(pos<=n){
		bit[pos]+=val;
		pos+=lsb(pos);
	}
}
ll query(int pos){
ll  res=0;
	while(pos>0){
		res+=bit[pos];
		pos-=lsb(pos);
	}
	return res;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		int val;
		cin>>val;
		update(i,val);
		values.push_back({val,i});
	}
for(int i=1;i<=q;i++){
	
			int l,r,k;
		cin>>l>>r>>k;
		queries.push_back({k,l,r,i,0});

	}
	sort(queries.begin(),queries.end(),comp);
	sort(values.begin(),values.end());
		int j =0;
	for(int i=0;i<q;i++){
		int l = queries[i].l;
		int r = queries[i].r;
		int k = queries[i].k;
//	cout<<l<<" "<<r<<" "<<k<<" ";
	// for(int i=l;i<=r;i++){
	// //	cout<<values[i-1]<<" ";
	// 	if(values[i-1]<k&&!visited[i]){
	// 		update(i,-2*values[i-1]);
	// 		visited[i]=true;
	// 	}
	// }
	//too slow ^
	
	//Note that by sorting k, all values that were smaller than 
	//before k, should be negative.
	//it doesn't matter if its not in the range.
	//as the future ks that are in the range will be able to use
	//the negative values.
	//although it looks like a nested loop, the j will go up to run
	//in total n times, as it goes along the sorteed values.
	while(j<n&&values[j].first<k){
		update(values[j].second,-(2*values[j].first));
		j++;
	}
	//all values samller than k are negative
		queries[i].ans=query(r)-query(l-1);
		answer[queries[i].origpos]=queries[i].ans;
	}
	sort(queries.begin(),queries.end(),comp2);

	for(int i=1;i<=q;i++){
		cout<<answer[i]<<"\n";
	}
	}
