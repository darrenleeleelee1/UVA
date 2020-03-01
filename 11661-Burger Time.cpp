#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int count;
	while(cin >> count){
		if(count == 0) break;
		cin.ignore();
		string str;
		int r = 0, d = 0;
		bool z = false;
		getline(cin, str);
		for (int i = 0; i < count; ++i){
			if(str[i] == 'R') r++;
			else if(str[i] == 'D') d++;
			else if(str[i] == 'Z') z = true; 
		}
		if(z) {
			cout << "0" << endl;
			continue;
		}
		int arrR[r], arrD[d];
		r = 0;
		d = 0;
		for (int i = 0; i < count; ++i)
		{
			if(str[i] == 'R') {
				arrR[r] = i;
				r++;
			}
			else if(str[i] == 'D') {
				arrD[d] = i;
				d++;
			}
		}
		int temp, min = 2000000;
		for (int i = 0; i < r; ++i){
			for (int j = 0; j < d; ++j){
				if(arrR[i] >= arrD[j])	temp = arrR[i] - arrD[j];
				else temp = arrD[j] - arrR[i];
				if(temp < min) min = temp;
			}
		}
		for (int i = 0; i < d; ++i){
			for (int j = 0; j < r; ++j){
				if(arrD[i] >= arrR[j])	temp = arrD[i] - arrR[j];
				else temp = arrR[j] - arrD[i];
				if(temp < min) min = temp;
			}
		}
		if(min == 2000000) cout << "0" << endl;
		else cout << min << endl;
	}
	return 0;
}