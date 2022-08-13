#include <bits/stdc++.h>
using namespace std;
struct rect{

int x1;
int y1;
int x2;
int y2;
int area(){

return (x2-x1)*(y2-y1);
}
};
int intersect(rect g, rect e){
    int overlapX = max (min(g.x2,e.x2)-max(g.x1,e.x1),0);
    int overLapY = max((min(g.y2,e.y2)-max(g.y1,e.y1)),0);
    return overlapX * overLapY;



}

int main() {
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);
	rect a,b,bill;
	cin>>a.x1>>a.y1>>a.x2>>a.y2;
	cin>>b.x1>>b.y1>>b.x2>>b.y2;
	cin>>bill.x1>>bill.y1>>bill.x2>>bill.y2;
	cout<<a.area()+b.area()-intersect(a,bill)-intersect(b,bill);



}
