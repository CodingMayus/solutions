// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
const int mx = 1e4;
//2d range queries
//loooks to mean normal 2d range queries will segment fault due to 1e4 by 1e4,
//works in ide so i didnt question
//but its important to keep in case for other problems that might work.
//I dont see a good explanation anywhere.
int diff[mx][mx];
int main() {
	int n,m;
	cin>>n>>m;
	//1--> white
	//0 --> dark
	for(int i=0;i<m;i++){
		int x,y,w,h;
		cin>>x>>y>>w>>h;
		// x++;
		// y++;
		// w++;
		// h++;
			diff[x+1][y+1]++;
			diff[x+1][y+h+1]--;
			diff[x+w+1][y+1]--;
			diff[x+w + 1][y+h + 1] ++;


	}
	// 	for(int i=0;i<=n;i++){
	// 	for(int j=0;j<=n;j++){
	// 		cout<<diff[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }


	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			diff[i][j]=diff[i][j]+diff[i-1][j]+diff[i][j-1]-diff[i-1][j-1];
		//	diff[i][j]=diff[i][j]%2;
			// if(diff[i][j]<0){
			// 	diff[i][j]=0;
			// }
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(diff[i][j]%2==0){
				diff[i][j]=0;
			}else{
				diff[i][j]=1;
			}
			diff[i][j]=diff[i][j]+diff[i-1][j]+diff[i][j-1]-diff[i-1][j-1];
		//	diff[i][j]=diff[i][j]%2;
			// if(diff[i][j]<0){
			// 	diff[i][j]=0;
			// }
		}
	}
	// 	for(int i=0;i<=n;i++){
	// 	for(int j=0;j<=n;j++){
	// 		cout<<diff[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }


	cout<<diff[n][n]<<endl;
	}
