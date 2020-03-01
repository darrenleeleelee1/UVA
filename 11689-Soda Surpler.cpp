#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int count;
	cin >> count;
	for (int time = 0; time < count; ++time)
	{
		int e, f, c, EmptyB, drink = 0;
		cin >> e >> f >> c;
		EmptyB = e + f;
		while(EmptyB >= c){
			//cout << EmptyB << " " << drink << endl;			
			drink += (EmptyB / c);
			EmptyB = (EmptyB / c) + (EmptyB % c);
		}
		cout << drink << endl;
	}
	return 0;
}