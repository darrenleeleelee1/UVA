#include <iostream>
using namespace std;
void initialize(bool letterG[], bool letterA[], int count){
    for (int i = 0; i < count; i++)
    {
        letterA[i] = false;
    }   
    for(int i = 0; i < 26; i++){
        letterG[i] = false;
    }
}
int main(int argc, char const *argv[])
{
    int round;
    string strA, strG;
    while(cin >> round){
        if(round == -1) break;
        cout << "Round " << round << endl;
        cin.ignore();
        cin >> strA >> strG;
        int counterS = 0;
        
        bool letterG[26], letterA[strA.length()], corect, isCount;
        initialize(letterG, letterA, strA.length());
        for (int i = 0; i < strG.length(); i++)
        {
            int cNumber = int(strG[i])-97;
            if(letterG[cNumber]) continue;
            corect = true;
            isCount = true;
            for (int j = 0; j < strA.length(); j++)
            {
                if(strG[i] == strA[j]){ 
                    letterA[j] = true;
                    isCount = false;
                }

            }
            letterG[cNumber] = true;
            
            if(isCount) counterS++;
            for (int j = 0; j < strA.length(); j++)
            {
                if(!letterA[j]) corect = false;
            }
            if(corect){
                cout << "You win." << endl;
                break;
            }
            if(counterS == 7){
                cout << "You lose." << endl;
                corect = true;
                break;
            }
        }
        if(!corect){
            cout << "You chickened out." << endl;
        }
    
        
    }
    return 0;
}
