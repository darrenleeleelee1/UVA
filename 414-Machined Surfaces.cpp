#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	int row;
	string arr[26];
	int countX[14];
	int max = -1, counter;
	while(cin >> row){
		cin.ignore();
		max = -1;
		if(row == 0) break;
		for (int i = 0; i < row; ++i)
		{
			getline(cin, arr[i]);
			countX[i] = 0;
		}
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < arr[i].length(); ++j)
			{
				if(arr[i][j] == 'X') countX[i]++;
			}
		}

		for (int i = 0; i < row; ++i)
		{
			if(countX[i] > max) max = countX[i];
		}
		counter = 0;
		for (int i = 0; i < row; ++i)
		{
			counter += countX[i] - max;
		}
		cout << abs(counter) << endl;
		
	}
	return 0;
}