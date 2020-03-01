#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int count;
	int size;
	cin >> count;
	char garbage;
	for (int times = 1; times <= count; ++times)
	{
		cin >> garbage >> garbage >> size;
		size *= size;
		long long int arr[size];
		for (int i = 0; i < size; ++i)
		{
			cin >> arr[i];
		}
		bool isSymmetric = true;
		if(size % 2 != 0) {
			if(arr[size/2] < 0) isSymmetric = false;
		}
		for (int i = 0; i < (size / 2); ++i)
		{
			if(arr[i] != arr[size-1-i]){ 
				isSymmetric = false;
				break;
			}
		}
		/*
		cout << size << endl;
		for (int i = 0; i < size; ++i)
		{
			cout << arr[i] << " ";
			if(i % 3 == 2)cout << endl;
		}
		*/
		
		if(isSymmetric)cout << "Test #" << times << ": " << "Symmetric." << endl;
		else cout << "Test #" << times << ": " << "Non-symmetric." << endl;
		
		//cout << arr[size/2] << endl;
	}
	return 0;
}