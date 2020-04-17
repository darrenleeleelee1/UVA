#include <bits/stdc++.h>
using namespace std;
#define MAXN 550
struct Coordinate
{
	int x, y;
	double angle = 1e9;
	int d;
	void printNode(){
		printf("%d %d\n", x, y);
	}
	bool operator<(const Coordinate other){
		if(angle == 1e9) return ((y < other.y) || (y == other.y) && (x < other.x));
		else return (angle < other.angle || (angle == other.angle) && (d < other.d));
	}
};
int ZCrossProduct(Coordinate src1, Coordinate src2, Coordinate src3)
{
	Coordinate vector1, vector2;
	vector1.x = src2.x - src1.x;
	vector1.y = src2.y - src1.y;
	vector2.x = src3.x - src2.x;
	vector2.y = src3.y - src2.y;
	return (vector1.x * vector2 .y) - (vector1.y * vector2.x);
}
int dist(Coordinate o, Coordinate c)
{
	return (c.x - o.x) * (c.x - o.x) + (c.y - o.y) * (c.y - o.y);
}
Coordinate cor[MAXN];
int main(int argc, char const *argv[])
{
	int T; 
	while (scanf("%d", &T) != EOF){  					
		printf("%d\n", T);								
		int n;
		while(T--){
			scanf("%d", &n);							
			for(int i = 0; i < n; i++)
				cor[i].angle = 1e9;
			vector<Coordinate> v;
			for(int i = 0; i < n; i++){
				scanf("%d %d", &cor[i].x, &cor[i].y);
			}
			sort(cor, cor + n);
			cor[0].angle = 0;

			for(int i = 1; i < n; i++){
				cor[i].angle = atan2(cor[i].y - cor[0].y, cor[i].x - cor[0].x);
				cor[i].d = dist(cor[0], cor[i]);
			}
			sort(cor + 1, cor + n);
			v.push_back(cor[0]);
			v.push_back(cor[1]);
			for(int i = 2; i < n; i++){
				while(ZCrossProduct(v[v.size()-2], v[v.size()-1], cor[i]) <= 0 && v.size() != 1){
					v.pop_back();
				}
				v.push_back(cor[i]);
			}
			v.push_back(cor[0]);

			printf("%d\n", v.size());	
			for(auto k : v){
				k.printNode();
			}
			
			if(T != 0) {
				scanf("%d", &n);
				printf("-1\n");
			}
		}
	}
	return 0;
}
