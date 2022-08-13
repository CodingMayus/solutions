#include <iostream>
#include "bits/stdc++.h"
using namespace std;
//use big font looks more satifisying to write in :D
//You are allowed to index strings in c++
//https://aryansh.gitbook.io/informatics-notes/usaco-specific/preparing-for-contests
int n;
int ans =-1;
vector<bool>visited(102);
vector<int>adj[102];

//https://codeforces.com/blog/entry/98621


void setIO(string name=""){ // FastIO See General -> Input/Output
	ios_base::sync_with_stdio(0); cin.tie(0);
	if((int)name.size() > 0){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}
void dfs(int start){
visited[start]=true;

for(auto neighbors: adj[start]){

    if(!visited[neighbors]){

        dfs(neighbors);
    }
}



}


bool Allvisited(){

for(int i=1;i<n+1;i++){
if(!visited[i]){
    return false;
}
}

return true;

}

int main() {
 setIO("factory");

  cin>>n;


for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    adj[b].push_back(a);

}
for(int i=1;i<n+1;i++){


fill(begin(visited),end(visited),false);
dfs(i);
    if(Allvisited()){
        cout<<i;
        return 0;

    }}

    cout<<-1;
    return 0;


}






