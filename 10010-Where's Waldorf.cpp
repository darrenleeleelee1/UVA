#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int count, n, m, k;
    int resultX, resultY;
    string temp;
    cin >> count;
    for (int times = 0; times < count; times++)
    {
        if(times != 0) cout << endl;
        cin >> n >> m;
        cin.ignore();
        string str[n];
        for (int i = 0; i < n; i++)
        {
            getline(cin, str[i]);
        }
        for (size_t i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if(str[i][j] >= 'a' && str[i][j] <= 'z'){
                    str[i][j] -= 32;
                }
            }
        }
        cin >> k;
        cin.ignore();
        for (int i = 0; i < k; i++)
        {
            bool isFind = false;
            getline(cin, temp);
            for(int j = 0; j < temp.length(); j++) if(temp[j] >= 'a' && temp[j] <= 'z') temp[j] -= 32;
            for (int j = 0; j < n; j++)
            {
                
                for (int k = 0; k < m; k++)
                {
                    if(str[j][k] == temp[0] && !isFind) {
                        resultX = j + 1;
                        resultY = k + 1;
                        if(temp.length() == 1) isFind = true;
                        else
                        {
                            int counter = 0;
                            //right
                            for(int h = 1; h < temp.length(); h++){
                                counter++;
                                if(k + h >= m) break; 
                                if(temp[h] != str[j][k+h]) break;
                                if(counter == temp.length()-1) isFind = true;
                                //cout << str[j][k+h] << isFind;
                            }
                            counter = 0;
                            //down
                            for(int h = 1; h < temp.length(); h++){
                                counter++;
                                if(j + h >= n) break; 
                                if(temp[h] != str[j+h][k]) break;
                                if(counter == temp.length()-1) isFind = true;
                                //cout << str[j+h][k];
                            }
                            counter = 0;
                            //left
                            for(int h = 1; h < temp.length(); h++){
                                counter++;
                                if(k - h < 0) break; 
                                if(temp[h] != str[j][k-h]) break;
                                if(counter == temp.length()-1) isFind = true;
                                //cout << str[j][k-h] << isFind;
                            }
                            counter = 0;
                            //up
                            for(int h = 1; h < temp.length(); h++){
                                counter++;
                                if(j - h < 0) break; 
                                if(temp[h] != str[j-h][k]) break;
                                if(counter == temp.length()-1) isFind = true;
                                //cout << str[j-h][k] << isFind;
                            }
                            counter = 0;
                            //up+right
                            for(int h = 1; h < temp.length(); h++){
                                counter++;
                                if(k + h >= m || j - h < 0) break; 
                                if(temp[h] != str[j-h][k+h]) break;
                                if(counter == temp.length()-1) isFind = true;
                                //cout << str[j-h][k+h] << isFind;
                            }
                            counter = 0;
                            //down+right
                            for(int h = 1; h < temp.length(); h++){
                                counter++;
                                if(k + h >= m || j + h >= n) break; 
                                if(temp[h] != str[j+h][k+h]) break;
                                if(counter == temp.length()-1) isFind = true;
                                //cout << str[j+h][k+h] << isFind;
                            }
                            counter = 0;
                            //up+left
                            for(int h = 1; h < temp.length(); h++){
                                counter++;
                                if(k - h < 0 || j - h < 0) break; 
                                if(temp[h] != str[j-h][k-h]) break;
                                if(counter == temp.length()-1) isFind = true;
                                //cout << str[j-h][k-h] << isFind;
                            }
                            counter = 0;
                            //down+left
                            for(int h = 1; h < temp.length(); h++){
                                counter++;
                                if(k - h < 0 || j + h >= n) break; 
                                if(temp[h] != str[j+h][k-h]) break;
                                if(counter == temp.length()-1) isFind = true;
                                //cout << str[j+h][k-h] << isFind;

                            }
                        }
                    }
                }      
            }
            cout << resultX << " " << resultY << endl;
        }
            
    }
        
    return 0;
}
