// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
int n,m;
typedef long long ll;
const int MOD = 1e9 +7;
const int mx = 1<<10+5;
const int INF = 1e3+5;
//today profile dp
//state: # of ways to fill up a i j rectangle with a mask arrangment.
//first k columns with an arrangment of 1010111
//unoptimized i.e.  Didnt precalculate the boolean comp --> So that we dont need to recheck.
ll dp[mx][INF];
int  comp(ll x,ll xp){

	//see if its compliable.
	//1) i can only be 1 if the previous isn't --> with first condition thus we can consider only the subsets of ( if the previous was 10011) then 01100 whhhhhhhhhhhhhhhhhhhhhhhhhhhha heeee
	//2) if two consutetive 0's --> vertical piece is possible.
	//else if just 1 the current has to be a 1
	// for(int i=0;i<n;i++){
	// 	//go through each bit
	// if((1&(x>>i))&&(1&(xp>>i))){
	// 	//not possible.
	// 	return 0;
	// }
	
	// }
	//now consider the second condition.
		int  left = (~x)&(~xp);	
	//values remaining are the 0s in both x and x`.
	int last =-1;
	//--> least signficiant bit (rightmost bit) in the segment.
	//-1 means no segment being tracked 
	for(int k=0;k<n;k++){
		if(1&(left>>k)){
				if(last==-1){
					last=k;
				}
		}else{ 
			if(last!=-1){
		int length = k-last;
		if(length%2!=0){
			return 0;
		}
			}
		last=-1;
			//if even length segment we know its possible for vertical..
			//if its odd its not.
		}
	}
	//what if the segment runs throughout without actually stopping
	if(last!=-1){
		//check

		int length = n-last;
		if(length%2!=0){
			return 0;
		}
	}
	return 1;
}
//with a width of 1-10, it is evident that 1<<10 is not that big, indicating that it is possible to stack
//the following in a nested loops.  Influencing our solution
int main() {
cin>>n>>m;	
dp[0][1]=1;
for(int i=2;i<=m+1;i++){
		for(int k=0;k<(1<<n);k++){
			//only try the subsets of ~(X)in regards to the first condition.
			//g is because just doing ~(X) --> means that the leading 0s will yield 1s.  
			//such AND function removes the unnecessary 0s.
			int lol = (~k)&((1<<n)-1);
			for(int g=lol;g;g=(g-1)&lol){
				dp[k][i]=(MOD+dp[k][i]+dp[g][i-1]*comp(k,g))%MOD;
				// dp[k][i]=dp[k][i]+dp[g][i-1];
			}
			dp[k][i]=(dp[k][i]+MOD+dp[0][i-1]*comp(k,0))%MOD; //our previous for loop doesnt go over mask 0, so we have to check it mannually
            dp[k][i]%=MOD;
		}
		 
}
cout<<dp[0][m+1]%MOD;
// for(int i=0;i<=(1<<n);i++){
// 	for(int j=1;j<=m;j++){
// 		cout<<dp[i][j]<<" ";
// 	}cout<<"\n";
// }
}
