#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int n,maxscore;
    string winner;
    cin >>n;
    map<string,int> rounds;
    maxscore = -1000;
    winner = "nobody";
    for (int i = 0 ;i <n;i++) {
        string round;
        istringstream is(round);
        string name;
        int score;
        is>>name>>score;
        if (rounds.find (name) != rounds.end())
            rounds[name] += score;
        else
            rounds[name] = score;
        if (rounds[name] > maxscore)
        {
            maxscore = rounds[name];
            winner = name;
        }
    }
    cout<<winner<<endl;
    return 0;
}