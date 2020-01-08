#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int CaseCtr = 1;
	int count;
	cin >> count;
	for (int times = 0; times < count; ++times)	{
		int n;
		cin >> n;
		cin.ignore();
		char str[n];
		int k, fctr = 0, temp = 0, Sctr = 0;
		for (int i = 0; i < n; ++i){
			cin >> str[i];
			if(str[i] == '.') fctr++;
		} 
		if(fctr > 0){
			for (int i = 0; i < n; ++i){			
				if(str[i] == '.'){
					for (int time = 0; time < 2; ++time){
						if(i >= n) break;
						if(str[i] == '.') temp++;
						++i;
					}
					fctr = fctr - temp - 1;
					Sctr++;
				}
				else continue;
			}
		}
		cout << "Case " << CaseCtr++ << ": " << Sctr << endl; 
	}
	return 0;
}
