#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	int count;
	double c, d, f, result;
	cin >> count;
	for (int time = 0; time < count; ++time){
		cin >> c >> d;
		f = ((9 * c / 5) + 32);
		f += d;
		result = ((f - 32) * 5 / 9);
		//cout << c << " " << d << " " << f << endl << endl;
		cout << "Case " << time + 1 << ": ";
		printf("%.2lf\n", result);
	}
	return 0;
}