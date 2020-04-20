#include <bits/stdc++.h>
using namespace std;
map<string, int> intMonth;
void initMonth()
{
	intMonth["January"] = 1;
	intMonth["February"] = 2;
	intMonth["March"] = 3;
	intMonth["April"] = 4;
	intMonth["May"] = 5;
	intMonth["June"] = 6;
	intMonth["July"] = 7;
	intMonth["August"] = 8;
	intMonth["September"] = 9;
	intMonth["October"] = 10;
	intMonth["November"] = 11;
	intMonth["December"] = 12;
}
int main(int argc, char const *argv[])
{
	initMonth();
	int n; cin >> n;
	string sm, em, temp;
	int sd, sy, ed, ey;
	int cases = 1;
	while(n--){
		cin >> sm >> sd >> temp >> sy;
		cin >> em >> ed >> temp >> ey;
		if(intMonth[sm] <= 2) sy--;
		if(intMonth[em] <= 2) ey--;
		if(intMonth[em] == 2 && ed == 29) ey++;
		int anss = (sy / 4) - (sy / 100) + (sy / 400);
		int anse = (ey / 4) - (ey / 100) + (ey / 400);
		
		printf("Case %d: %d\n", cases++, anse - anss);
	}
	return 0;
}