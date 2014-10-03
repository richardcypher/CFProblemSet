#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int n,maxscore;
    cin >>n;
    std::map<string, int> rounds;
    string* names = new string[n];
    int* scores = new int[n];
    for (int i = 0 ;i < n;i++) {
        string name;
        int score;
        cin>>name>>score;
        names[i] = name;
        if(rounds.find(name) == rounds.end())
        	rounds[name] = score;
        else
        	rounds[name] += score;
        scores[i] = rounds[name];
    }
    maxscore = 0;
    std::map<string, int>::iterator it = rounds.begin();
    for (; it != rounds.end();it++)
        if (it->second > maxscore)
            maxscore = it->second;
    for (int i = 0 ;i < n; i++) {
        if (rounds[names[i]] == maxscore && scores[i]>= maxscore) {
                cout<<names[i]<<endl;
                return 0;
        }
    }
    return 0;
}