#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int count;
	cin >> count;
	cin.ignore();
	for (int time = 0; time < count; ++time)
	{
		int arrcounter[26], max = -1;
		string str;
		getline(cin, str);
		for (int i = 0; i < 26; ++i)
	        arrcounter[i] = 0;

		for (int i = 0; i < str.length(); ++i){
			for (int j = 0; j < 26; ++j){
				if(str[i] == char(65 + j)) arrcounter[j]++;
				else if(str[i] == char(97 + j)) arrcounter[j]++;
				if(arrcounter[j] > max) max = arrcounter[j];
			}
		}
		for (int i = 0; i < 26; ++i)
			if(arrcounter[i] == max) cout << char(97 + i);
		cout << endl;
	}
	return 0;
}