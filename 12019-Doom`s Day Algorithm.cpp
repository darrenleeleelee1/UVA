#include <iostream>	
using namespace std;

int main(int argc, char const *argv[])
{	/* mod完 - 1 */
	int count;
	int DayofMon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	string week[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
	cin >> count;
	for (int time = 0; time < count; ++time)
	{	
		int m, d;
		cin >> m >> d;
		int sum = 0;
		for (int i = 0; i < m - 1; ++i)
			sum += DayofMon[i];
		sum += d;
		if(sum % 7 == 0) cout << week[6] << endl;
		else cout << week[sum % 7 - 1] << endl;

	}
	return 0;
}