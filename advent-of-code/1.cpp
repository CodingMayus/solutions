// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
int main() {
	int ans =0;
		int en;
		string val;
		int i =1000;
		while(i--){
			bool st = false;
				cin>>val;
			
				for(int i=0;i<val.length();i++){
					char g= val[i];
					int nom = g;
					if(nom>=49&&nom<=57){
							if(!st){
								st= true;
								ans+=10*(nom-48);
							}
							en = nom-48;
					}
				}
				ans+=en;
				cout<<ans<<"\n";

		}

}
