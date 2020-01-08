#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int count, temp = 0, n[3], sum = 0, max = -1;
	cin >> count;
	for (int time = 0; time < count; ++time){
		for (int i = 0; i < 3; ++i){
			cin >> n[i];
			if(n[i] > temp) {
				max = i;
				temp = n[i];
			} 

		}
		for (int i = 0; i < 3; ++i){
			if(i == max) sum -= n[i];
			else sum += n[i];
		}
		if(sum > 0) cout << "OK" << endl;
		else cout << "Wrong!!" << endl;
		sum = 0;
		temp = 0;
		max = -1;
	}
	return 0;
}