#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int count;
	cin >> count;
	for (int time = 1; time <= count; ++time)
	{
		int n, lctr = 0, hctr = 0;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
			if(i > 0){
				if(arr[i] > arr[i-1]) hctr++;
				else if(arr[i] < arr[i-1]) lctr++;
			}
		}
		cout << "Case " << time << ": " << hctr << " " << lctr << endl;
	}
	return 0;
}