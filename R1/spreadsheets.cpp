#include <iostream>
#include <sstream>
#include <string.h>
#include  <cmath>
#include <stdlib.h>
using namespace std;

int main() {
    long n;
    cin>>n;
    string strs[n], transf[n];
    const char* delim = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (long i = 0; i < n; ++i)
    {
        cin>>strs[i];
        char * tmp = new char[strs[i].length() + 1];
        strcpy(tmp, strs[i].c_str());
        char* item;
        item = strtok(tmp, delim);
        char *token1 = new char[strlen(item)],  *token2 = new char[strlen(item)];
        int nums = 0;
        while(item)  {
            if (nums == 0) {
                strcpy(token1, item);
                nums ++;
            }
            else {
                strcpy(token2, item);
                nums++;
            }
            item = strtok(NULL, delim);
        }
        if (nums == 1) {
            transf[i] = "R";
            size_t found = strs[i].find(token1);
            transf[i] += token1;
            transf[i] += "C";
            string col_str = strs[i].substr(0, found);
            long col = 0;
            long base = 1;
            for (long j = col_str.length() - 1; j >= 0; j--) {
                col += (col_str[j] - 64 ) *  base;
                base *=  26;
            }
            ostringstream os;
            os << col;
            transf[i] += os.str();
        }
        else {
            transf[i] = token1;
            long col = strtol(token2, NULL, 10);
            char tmp = col % 26 == 0 ?  (col % 26 + 90) : (col % 26 + 64);
            col -= (col%26 == 0) ? 26 : 0;
            transf[i].insert(0, 1, tmp);
            col = col / 26;
            while (col != 0) {
                tmp = (col % 26  == 0) ? 90 : (col % 26 + 64);
                col -= (col %26 == 0) ? 26 : 0;
                col = col / 26;
                transf[i].insert(0, 1, tmp);
            }
        }
    }
    for (long   i = 0; i < n; ++i)
    {
        cout<<transf[i]<<endl;
    }
}