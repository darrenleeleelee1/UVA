#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int count, n, temp, garbage;
	cin >> count;
	for (int time = 1; time <= count; ++time)
	{
		cin >> n;
		cout << "Case " << time << ": ";
		for (int i = 0; i < n; ++i){
			if(i == n / 2) {
				cin >> temp;
				cout << temp;
			}
			else cin >> garbage;

		}
		cout << endl;
	}
	return 0;
}