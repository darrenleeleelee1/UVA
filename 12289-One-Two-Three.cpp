#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int count;
	string one = "one";
	string two = "two";
	cin >> count;
	cin.ignore();
	for (int time = 0; time < count; ++time) {
		string str;
		int ctrO = 0, ctrT = 0;
		getline(cin, str);
		if (str.length() == 3){
			for (int i = 0; i < 3; ++i){
				if(str[i] == one[i]) ctrO++;
				else if(str[i] == two[i]) ctrT++;
			}
			if(ctrO >= 2) cout << "1" << endl;
			else if(ctrT >= 2) cout << "2" << endl;
		}
		else cout << "3" << endl;	
	}
	return 0;
}