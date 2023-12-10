#include <bits/stdc++.h>
using namespace std;
//traverse, once met an number, loop around it and if found a
//special character add to special parts!
int sum =0;
struct number{
int st,len,row,val;
};
char arr[1000][1000];
vector<number>numbers;
int main() {
    string number="";
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            arr[i][j]='.';
        }
    }
    for(int i=1;i<=140;i++){
        int st=1,len=0;
        string input;
        cin>>input;
        for(int j=1;j<=input.length();j++){
            char g= input[j-1];
            arr[i][j]=g;
        if(g-'0'>=0&&g-'0'<10){
        //  cout<<g<<"\n";
            number+=g;
            len++;
        }else{
            //cout<<"hello";
                if(len==0){
                    st=j+1;
                    len=0;
                    continue;
                }
                //cout<<number<<"\n";
                int value = stoi(number);
                numbers.push_back({st,len,i,value});
                number="";
                st=j+1;
                len=0;
        }
        }
        if(len!=0){
               int value = stoi(number);
                numbers.push_back({st,len,i,value});
                number="";

        }
    }


for(auto [a,b,c,d]:numbers){
    bool flag = false;

//check top
for(int i=a-1;i<=a+b;i++){
    if(!(arr[c-1][i]-'0'>=0&&arr[c-1][i]-'0'<10)&&!(arr[c-1][i]-'0'==-2)){
//it does not equal a number or a period, it has to be a symbol.
    flag = true;
    }
}

//check bottom
for(int i=a-1;i<=a+b;i++){
  if(!(arr[c+1][i]-'0'>=0&&arr[c+1][i]-'0'<10)&&!(arr[c+1][i]-'0'==-2)){
//it does not equal a number or a period, it has to be a symbol.
//cout<<"yipee";
    flag = true;
    }
}

//left vertical
for(int i=c-1;i<=c+1;i++){
  if(!(arr[i][a-1]-'0'>=0&&arr[i][a-1]-'0'<10)&&!(arr[i][a-1]-'0'==-2)){
//it does not equal a number or a period, it has to be a symbol.
    flag = true;
    }

}
//right vertical
for(int i=c-1;i<=c+1;i++){
  if(!(arr[i][a+b]-'0'>=0&&arr[i][a+b]-'0'<10)&&!(arr[i][a+b]-'0'==-2)){
//it does not equal a number or a period, it has to be a symbol.
    flag = true;
    }


}
if(flag == true){
      cout<<d<<"\n";
    sum+=d;
}
    
    }
    cout<<sum<<"\n";
}
