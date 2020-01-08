#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int count;
	cin >> count;
	for (int times = 0; times < count; ++times)
	{
		cout << "Case " << times + 1 <<  ": ";
		int arr[3], max = 0;
		for(int i = 0; i < 3; i++){
			cin >> arr[i];
		}
		int temp;
		for(int i = 0; i < 2; i++){
			for(int j = i + 1; j < 3; j++){
				if(arr[i] > arr[j]){
					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
		temp = 0; 
		for (int i = 0; i < 3; ++i)
		{
			if(i == 2) temp -= arr[i];
			else temp += arr[i];
		}	
		if(temp > 0){
			if(arr[0] == arr[1]){
				if(arr[0] == arr[2]) cout << "Equilateral" << endl;
				else cout <<  "Isosceles" << endl;
			}
			else if(arr[1] == arr[2]) cout <<  "Isosceles" << endl;
			else cout << "Scalene" << endl;
		}
		else cout << "Invalid" << endl;
	}
	return 0;
}