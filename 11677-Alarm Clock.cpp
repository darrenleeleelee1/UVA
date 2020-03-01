#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int h1, m1, h2, m2;
    int result;
    while (cin >> h1 >> m1 >> h2 >> m2)
    {
        result = 0;
        if(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0) break;
        if(h1 < h2){
            result = (h2 - h1) * 60;
            result += m2 - m1;
        }
        else if(h1 > h2){
            result = ((24 - h1) + h2) * 60;
            result += m2 - m1; 
        }
        else if(h1 == h2){
            if(m1 < m2){
                result = m2 - m1;
            }
            if(m1 > m2){
                result = ((24 - h1) + h2) * 60;
                result += m2 - m1;
            }
        }
        cout << result << endl;
    }
    
    
    return 0;
}
