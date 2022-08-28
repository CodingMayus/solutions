#include <iostream>
#include "bits/stdc++.h"
using namespace std;
//use big font looks more satifisying to write in :D
//You are allowed to index strings in c++
//https://aryansh.gitbook.io/informatics-notes/usaco-specific/preparing-for-contests


//https://codeforces.com/blog/entry/98621
void setIO(string name=""){ // FastIO See General -> Input/Output
	ios_base::sync_with_stdio(0); cin.tie(0);
	if((int)name.size() > 0){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}
int n;
int swape;
vector<int>photo;
vector<int>sorted;
int main() {
  setIO("outofplace");
    cin>>n;

for(int i=0;i<n;i++){
        int input;
    cin>>input;
    photo.push_back(input);
    sorted.push_back(input);



}

sort(sorted.begin(),sorted.end());
for(int i=0;i<n;i++){

 if(sorted[i]!= photo[i]){

    swape++;
 }
}
cout<<swape-1;




}





;
