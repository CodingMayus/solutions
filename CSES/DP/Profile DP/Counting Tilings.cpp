// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
int n,m;
typedef long long ll;
const int MOD = 1e9 +7;
const int mx = 1<<10+5;
const int INF = 1e3+5;
//today profile dp
//state: # of ways to fill up first i-1 columns with a mask arrangment ( protruding tiles from column i-1) on i.
//first k columns with an arrangment of 1010111
//optimized i.e.   precalculate the boolean comp --> So that we dont need to recheck at its iteration.
//Unoptimized: https://cses.fi/paste/d3bef8c631c7b29d6879ac/
ll dp[mx][INF];
bool comp[mx][mx];
//with a width of 1-10, it is evident that 1<<10 is not that big, indicating that it is possible to stack
//the following in a nested loops.  Influencing our solution
int main() {
cin>>n>>m;	
dp[0][1]=1;
//precompute values so that you dont need to calculate them again in
//O((2^n*n))time,--> around 10^7  gud
for(int i=0;i<(1<<n);i++){
	for(int j=0;j<(1<<n);j++){
		bool check = 1;
		//1-->true
		//0-->false
		int left = ~(i)&~(j);
	//remaining 1s are the inactive bits --> tbh unnecessary but conventient.
		int last =-1;
		//if not -1 --> tracking a segment length --> if odd unable to fill/ if even --> able
		//if -1 --> currenting not tracking segment
		for(int g = 0;g<n;g++){
				if((left>>g)&1){
						if(last==-1){
							last =g;
						}
				}else{
					//if -1 originally then there is no segment
					if(last!=-1){
						int length = g-last;
						if(length%2==0)
				{	
					check &= 1;
	//if its still true then lket it continue to be
	//if not, it doesnt update!

				}	else{
				check =0;
			}					
					}
					last =-1;
					//reset to find next segment.
				}
		}
		//if never encounter a 0 in the "left" mask, then we have to check for that.
		if(last !=-1){
			int length = n-last;
			if(length%2==0){
				check&=1;
				
						//even length
			}else{
				check =0;
			}
		}
		comp[i][j]=check;
	}

}
for(int i=2;i<=m+1;i++){
		for(int k=0;k<(1<<n);k++){
			//only try the subsets of ~(X)in regards to the first condition.
			//g is because just doing ~(X) --> means that the leading 0s will yield 1s.  
			//such AND function removes the unnecessary 0s.
			int lol = (~k)&((1<<n)-1);
			//it is clear that comp[i][j]=comp[j][i].  ordering legit no matter.
			for(int g=lol;g;g=(g-1)&lol){
				dp[k][i]=(MOD+dp[k][i]+dp[g][i-1]*comp[k][g])%MOD;
				// dp[k][i]=dp[k][i]+dp[g][i-1];
			}
			dp[k][i]=(dp[k][i]+MOD+dp[0][i-1]*comp[k][0])%MOD; //our previous for loop doesnt go over mask 0, so we have to check it mannually
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
