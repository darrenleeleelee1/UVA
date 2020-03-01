#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a, b;
	int sum1, sum2;
	while(cin >> a >> b){
		if(a == -1 && b == -1) break;
		if(a > b){
			int temp = a;
			a = b;
			b = temp;
		}
		sum1 = b - a;
		sum2 = a + 100 - b;
		if(sum1 <= sum2) cout << sum1 << endl;
		else cout << sum2 << endl;
	}
	return 0;
}