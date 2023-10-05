// Source: https://usaco.guide/general/io
//Find k-th largest
//the Get function returns the i-th smallest value.
//thus to find the i-th largest --> numofvals - i+1
#include <bits/stdc++.h>
using namespace std;
const int MPOW = 1<<20+5;
const int mx = (1<<27)+100;
int bit[mx];
unordered_map<int,int>which;
//key is the rating
//val is the identification
//Works because all ratings are independent
//No need to coordinate compress (note mxval goes only up to 10^8)
//which fits in 1gb 
const int mx2 =1e6+5;
int a[mx2];
//ind => identifier
//val is the value;
int lsb(int x){
	return x &-x;
}
void  update(int pos, int val){

	while(pos<=mx){
		bit[pos]+=val;
		pos+=lsb(pos);

	}

}
int n;
//ultimately consider the property of BIT
//specifically the powers of 2 positions.
//in these positions they highlight all the elements from st to the power.
//we find the biggest power of 2 smaller than value.
//such that the # of elements from such is less than the k-th .
//then continue doing this until i becomes 0.
//This value will only be right under the actual value --> signifying
//the ret+1.
//this works cause any # can be represented in binary.
//so it is known that it is definitely possible to find the k-th largest
//element.
	    int get(int x)
    {
        int sum=0;
        int ret=0; // Number of element in array, for which the sum is equal to sum
        for(int i=1<<27;ret+(i)<mx;i>>=1) // Loop through the powers of two, starting with the highest possible
        {
			if(i==0){break;}
            if(sum+bit[ret+(i)]<x){ // Trying to expand the current prefix
			    sum+=bit[ret+(i)],
                ret+=i;
			//	cout<<ret<<"\n";
			}
        }
        return ret+1;
    }
	int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin>>n;
	int numcnt=0;
	for(int i=1;i<=n;i++){
char type;
cin>>type;
if(type=='N'){
	int identify,val;
	cin>>identify>>val;
	which[val]=identify;
	a[identify]=val;
	numcnt++;
	update(val,1);
}
if(type=='M'){
	int pos;
	int val;
	cin>>pos>>val;
	which[val]=pos;
	update(a[pos],-1);
	a[pos]=val;
	update(a[pos],1);
}
if(type=='Q'){
	int v;
	cin>>v;
//cout<<get(v)<<"\n";
	cout<<which[get(numcnt-v+1)]<<"\n";
}
// sort(rates.begin(),rates.end(),comp);


	}}
