#include <iostream>
#include <string>

using namespace std;
int main(){
    char s[3],t[3];
    cin>>s>>t;
    string way = "";
    int steps = 0;
    for (int i = s[0], j = s[1]; i != t[0] || j != t[1];) {
        if (i > t[0]) {
            way += "L";
            --i;
        }
        else if (i < t[0]){
            way += "R";
            ++i;
        }
        if(j > t[1]) {
            way += "D";
            j--;
        }
        else if (j < t[1]){
            way += "U";
            j++;
        }
        way += "\n";
        steps++;
    }
    cout<<steps<<endl<<way;
}