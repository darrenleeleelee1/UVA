#include <bits/stdc++.h>
using namespace std;
int xx1, xx2, yy1, yy2;
double width , height;
double getArea(int w)
{
	double lx = yy1 - w, ly = xx1 + w, rx = yy2 - w, ry = xx2 + w;
	bool Left = ly >= yy1 && ly <= yy2;
	bool Top = rx >= xx1 && rx <= xx2;
	bool Right = ry >= yy1 && ry <= yy2;
	bool Bottom = lx >= xx1 && lx <= xx2;
	if(Left && Top) return (yy2 - ly) * (rx - xx1) * 0.5;
	if(Left && Right) return ((yy2 - ly) + (yy2 - ry)) * (width) * 0.5;
	if(Bottom && Top) return ((lx - xx1) + (rx - xx1)) * (height) * 0.5;
	if(Bottom && Right) return height * width - (xx2 - lx) * (ry - yy1) * 0.5;
	return ly <= yy1 ? width * height : 0;
}
int main(int argc, char const *argv[])
{
	int T; cin >> T;
	int cas = 1;
	int w;
	while(T--){
		cin >> xx1 >> xx2 >> yy1 >> yy2 >> w;
		width = xx2 - xx1; height = yy2 - yy1;
		double a1 = getArea(w);
		double a2 = getArea(-w);
		printf("Case #%d: %.8lf\n", cas++, (a2 - a1) / (width * height));
	}
	return 0;
}