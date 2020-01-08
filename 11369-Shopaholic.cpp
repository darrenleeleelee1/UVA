#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int count;
	cin >> count;
	for (int time = 0; time < count; ++time)
	{
		int nitems;
		cin >> nitems;
		int arr[nitems];
		long long int sum = 0;
		for (int i = 0; i < nitems; ++i){
			cin >> arr[i];
		}
		sort(arr, arr + nitems);
		reverse(arr, arr + nitems);
		/*for (int i = 0; i < nitems - 1; ++i){
			for (int j = i + 1; j < nitems; ++j){
				if(arr[i] < arr[j]){
					swap(arr[i], arr[j]);
				}	
			}
		}*/


		for (int i = 0; i < nitems; ++i){
			if((i + 1) % 3 == 0) sum += arr[i];
			else continue;
		}
		/*for (int i = 0; i < nitems; ++i){
			cout << arr[i] << " ";
		}*/
		cout << sum << endl;
	}
	return 0;
}