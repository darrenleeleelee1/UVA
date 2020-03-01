#include <iostream>
#include <algorithm>
using namespace std;
int letter[26];
void initialize(){
    for (int i = 0; i < 26; i++)
    {
        letter[i] = 0;
    }
    
}
int main(int argc, char const *argv[])
{
    int count;
    int casess = 1;
    string str;
    while(cin >> count){
        cin.ignore();
        int ctr = 0;
        for (int times = 0; times < count; times++)
        {
            bool isCool = true;
            getline(cin, str);
            initialize();
            for (int i = 0; i < str.length(); i++)
            {
                int index = int(str[i])-97;
                letter[index]++;
            }
            sort(letter, letter + 26);
            reverse(letter, letter + 26);
           
            
            for (int i = 0; i < 26; i++)
            {
                if(letter[i] == 0){ 
                    if(i <= 1) isCool = false;
                    break;
                }
                if(letter[i] == letter[i-1]){
                    isCool = false;
                }
            }
            if(isCool) ctr++;
        }
        cout << "Case " << casess++ << ": " << ctr << endl;
    }
    return 0;
}
