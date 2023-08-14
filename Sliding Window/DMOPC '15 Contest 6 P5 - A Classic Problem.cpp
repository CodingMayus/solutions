// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx =3e6+5;
ll  a[mx];
//structure my problemso that i can find all possible subarrays from a given index from left to right
//for instance adding the distance ( j- i )+1 considers all the possible subarrays that contain the index j, the rightmost value.
//we know this can work between the distances i - j, because if the max and min make the difference less than k, then any other combination of values should uphold the conditions.

//In essence, a mixture of sliding window and two pointers

int main() {
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	deque<ll>maxer;
	deque<ll>miner;
	ll ans=0;
	for(int l=1,r=1;r<=n;r++){
			while(!maxer.empty()&&a[maxer.back()]<a[r]){
				maxer.pop_back();
			}while(!miner.empty()&&a[miner.back()]>a[r]){
				miner.pop_back();
			}
			maxer.push_back(r);
			miner.push_back(r);

	//if greater than k--> make sure it is less than k by appending the left values 
	//if they are not the min/max/irrelevant values, removing them is of no cost.
	//if they are --> make impact.
	//once this is done we know the resulting subarray i-j follows the conditions meaning all subarrays
	//between i-j work
	while(a[maxer.front()]-a[miner.front()]>k){
				if(maxer.front()==l){
					maxer.pop_front();
				}if(miner.front()==l){
					miner.pop_front();
				}
				l++;
				//to go throughout the array until the conditions r better.
	}	
	ans+=r-l+1;
	//number of subarrays that is in l-r

	}cout<<ans<<endl;}
