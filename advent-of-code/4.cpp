// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
set<int>found;
bool iswinnum=true;
int ans=0;
int cnt=0;
int temp=1;
int main() {
while(true){
string input;
cin>>input;
if(cnt==213){
	break;
}
if(!iswinnum){
if(input=="Card"){
	if(cnt==0){
		continue;
	}
	cnt++;
	cout<<temp/2<<"\n";
	ans+=(temp)/2;
	temp=1;
	string uselessnom;
	cin>>uselessnom;
	found.clear();
	iswinnum=true;
	continue;
}
int val = stoi(input);
if(found.find(val)!=found.end()){
	temp=temp*2;
}
}else{
	if(cnt==0){
		string useless;
		cin>>useless;
		cnt++;
		continue;
	}
	if(input=="|"){
			iswinnum=false;
			continue;
	}
	int val = stoi(input);
	found.insert(val);
}
}
cout<<ans<<"\n";

}
