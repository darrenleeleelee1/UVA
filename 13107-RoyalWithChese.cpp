#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	
	string str;
	while(getline(cin, str)){
		bool arr[26];
		int numarr[26];
		int counter = 1;
		for (int i = 0; i < 26; ++i)
			arr[i] = false;
		for (int i = 0; i < str.length(); ++i){
			for (int j = 0; j < 26; ++j){
				if(str[i] == char(97 + j) && !arr[j] ) {
					arr[j] = true; 
					numarr[j] = counter++;
				}
			}
		}
		for (int i = 0; i < str.length(); ++i){
			for (int j = 0; j < 26; ++j){
				if(str[i] == char(97 + j)){
					if(numarr[j] == 5) cout << "2";
					else if(numarr[j] == 2) cout << "5";
					else if(numarr[j] == 9) cout << "6";
					else if(numarr[j] == 6) cout << "9";
					else if(numarr[j] == 15) cout << "12";
					else if(numarr[j] == 12) cout << "15";
					else if(numarr[j] == 19) cout << "16";
					else if(numarr[j] == 16) cout << "19";
					else if(numarr[j] == 20) cout << "50";
					else if(numarr[j] == 21) cout << "51";
					else if(numarr[j] == 22) cout << "55";
					else if(numarr[j] == 23) cout << "53";
					else if(numarr[j] == 24) cout << "54";
					else if(numarr[j] == 25) cout << "52";
					else if(numarr[j] == 26) cout << "59";
					else cout << numarr[j];
				}
			}
		}
		cout << endl;
	}
	return 0;
}