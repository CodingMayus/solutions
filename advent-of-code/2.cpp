// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
int green=0,red=0,blue=0,cnt=0;
bool flag = false;

bool check(){
//cout<<green<<" "<<red<<" "<<blue<<"\n";
	if(green<=13&&red<=12&&blue<=14){
		//cout<<cnt<<endl;
		return true;
	}
	return false;
}
int main() {
int temp=0;
int ans=0;
while(true){
// 	string game;
// 	string id;
// 	int valid=stoi(id[0]);
// string type;
string value;
cin>>value;
string type;
cin>>type;
if(cnt==100){	
break;
}
if(value=="Game"){
	if(!flag&&cnt!=0){
		//all of row is good.	
			ans+=cnt;
	}
	flag= false;
	cnt++;
	continue;
}
int intval = stoi(value);
if(type=="green,"){
green+=intval;
}
if(type=="red,"){
red+=intval;
}
if(type=="blue,"){
blue+=intval;
}
if(type=="green"||type=="green;"){
	green+=intval;
if(!check()){
flag = true;
}
green+=intval;
green=0;
red=0;
blue=0;
}
if(type=="red"||type=="red;"){
	red+=intval;
;
if(!check()){
	flag = true;
}
green=0;
red=0;
blue=0;
}
if(type=="blue"||type=="blue;"){
	blue+=intval;
	if(!check()){
		flag = true;

	}
green=0;
red=0;
blue=0;
}

// if(check()){
// 	ans+=100;
// }

}
cout<<ans<<"\n";

}