#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    char arr[101];
    while(cin >> n){
        if(n == 0) break;
        cin.ignore();
        int counter = 0;
        do{
            cin >> arr[counter];
            counter++;            
        }while(cin.peek()!= '\n');
        n = (counter/n);
        for (int i = n - 1; i < counter; i += n){
            for (int j = 0; j < n; ++j){
                cout << arr[i - j];
            }
        }
        cout << endl;
    }

    return 0;
}