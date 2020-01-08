#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int count;
	cin >> count;
	cin.ignore();
	for (int time = 0; time < count; ++time)
	{
		int sum = 0, temp, counter = 0, block = 0;
		string str;
		getline(cin, str);
		for (int i = 0; i < str.length(); ++i)
		{
			if((i - block)% 2 == 0) {
				temp = (2 * (int(str[i]) - 48));
				sum += temp / 10 + temp % 10;
				counter++;
			}
			else{ 
				sum += (int(str[i]) - 48);
				counter++;
			}
			if(counter == 4) {
				++i;
				counter = 0;
				block++;
			}
		}
		if(sum % 10 == 0) cout << "Valid" << endl;
		else cout << "Invalid" << endl;
	}
	return 0;
}