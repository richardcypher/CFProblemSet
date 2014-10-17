#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>

using namespace std;

struct cell{
    std::map<string, bool> ways_exist;
    std::vector<string> ways;
    std::vector<int> numberof2;
    std::vector<int> numberof5;
    int lnumber;
};

int getBaseInNumber(int num, int base) {
    int n = 0;
    while (num % base == 0) {
        num /= base;
        n++;
    }
    return n;
}

int getMin(int a, int b) {
    return a > b ? b:a;
}

int main() {
    int n;
    cin>>n;
    int **matrix = (int**)malloc(n * sizeof(int));
    cell** cells = new cell*[n];
    for (int i = 0; i < n; i++){
        cells[i] = new cell[n];
        matrix[i] = (int *)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>matrix[i][j];
        }
    }
    for(int i = 0; i < n;i++ ){
        if (i == 0){
            cells[i][0].numberof2.push_back(getBaseInNumber(matrix[i][0],2));
            cells[i][0].numberof5.push_back(getBaseInNumber(matrix[i][0],5));
            cells[i][0].ways_exist[""] = true;
            cells[i][0].ways.push_back("");
        }
        else {
            cells[i][0].numberof2.push_back(getBaseInNumber(matrix[i][0],2) + cells[i - 1][0].numberof2[0]);
            cells[i][0].numberof5.push_back(getBaseInNumber(matrix[i][0],5) + cells[i - 1][0].numberof5[0]);
            cells[0][i].numberof2.push_back(getBaseInNumber(matrix[0][i],2) + cells[0][i -1].numberof2[0]);
            cells[0][i].numberof5.push_back(getBaseInNumber(matrix[0][i],5) + cells[0][i - 1].numberof5[0]);
            cells[i][0].ways_exist[cells[i - 1][0].ways[0] + "D"] = true;
            cells[0][i].ways_exist[cells[0][i - 1].ways[0] + "R"] = true;
            cells[i][0].ways.push_back(cells[i - 1][0].ways[0] + "D");
            cells[0][i].ways.push_back(cells[0][i - 1].ways[0] + "R");
        }
        cells[i][0].lnumber = getMin(cells[i][0].numberof2[0],cells[i][0].numberof5[0]);
        cells[0][i].lnumber = getMin(cells[0][i].numberof2[0],cells[0][i].numberof5[0]);
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            int num2 = getBaseInNumber(matrix[i][j],2),num5 = getBaseInNumber(matrix[i][j],5);
            int least_number = -1;
            cout<<cells[i - 1][j].ways.size()<<","<<cells[i][j - 1].ways.size()<<"\t";
            for(int k1 = 0; k1 < cells[i - 1][j].ways.size(); k1++) {
                for (int k2 = 0; k2 < cells[i][j - 1].ways.size(); k2++) {
                    int up2 = cells[i -1][j].numberof2[k1],
                        up5 = cells[i -1][j].numberof5[k1],
                        left2 = cells[i][j -1].numberof2[k2],
                        left5 = cells[i][j - 1].numberof5[k2],
                        upleast = getMin(up2+num2,up5 + num5),
                        leftleast = getMin(left2 + num2, left5 + num5);
                    if (k1 == 0 && k2 == 0)
                        least_number = upleast;
                    if ( (upleast< leftleast) && (cells[i][j].ways_exist.find(cells[i - 1][j].ways[k1] + "D") ==  cells[i][j].ways_exist.end()) 
                            && (upleast <= least_number)){
                        cells[i][j].lnumber = upleast;
                        least_number = upleast;
                        cells[i][j].numberof2.push_back(up2 + num2);
                        cells[i][j].numberof5.push_back(up5 + num5);
                        cells[i][j].ways.push_back(cells[i - 1][j].ways[k1] + "D");
                        cells[i][j].ways_exist[cells[i - 1][j].ways[k1] + "D"]  = true;
                    }
                    else if((upleast > leftleast)&& (cells[i][j].ways_exist.find(cells[i][j - 1].ways[k2] + "R") == cells[i][j].ways_exist.end())
                            && (leftleast <= least_number)) {
                        cells[i][j].lnumber = leftleast;
                        least_number = leftleast;
                        cells[i][j].numberof2.push_back(left2 + num2);
                        cells[i][j].numberof5.push_back(left5 + num5);
                        cells[i][j].ways.push_back(cells[i][j - 1].ways[k2] + "R");
                        cells[i][j].ways_exist[cells[i][j - 1].ways[k2] + "R"]  = true;
                    }
                    else if(upleast == leftleast && upleast <= least_number){
                        least_number = upleast;
                        if(up2 != left2 && up5 != left5) {
                            if (cells[i][j].ways_exist.find(cells[i - 1][j].ways[k1] + "D") == cells[i][j].ways_exist.end() ) {
                                cells[i][j].lnumber = upleast;
                                cells[i][j].numberof2.push_back(up2 + num2);
                                cells[i][j].numberof5.push_back(up5 + num5);
                                cells[i][j].ways.push_back(cells[i - 1][j].ways[k1] + "D");
                                cells[i][j].ways_exist[cells[i - 1][j].ways[k1] + "D"]  = true;
                            }
                            if(cells[i][j].ways_exist.find(cells[i][j - 1].ways[k2] + "R") == cells[i][j].ways_exist.end()) {
                                cells[i][j].lnumber = leftleast;
                                cells[i][j].numberof2.push_back(left2 + num2);
                                cells[i][j].numberof5.push_back(left5 + num5);
                                cells[i][j].ways.push_back(cells[i][j - 1].ways[k2] + "R");
                                cells[i][j].ways_exist[cells[i][j - 1].ways[k2] + "R"]  = true;
                            }
                        }
                        else if ((up2 == left2 && up5 < left5) || (up5 == left5 && up2 < left2) ){
                            if (cells[i][j].ways_exist.find(cells[i - 1][j].ways[k1] + "D") == cells[i][j].ways_exist.end() ) {
                                cells[i][j].lnumber = upleast;
                                cells[i][j].numberof2.push_back(up2 + num2);
                                cells[i][j].numberof5.push_back(up5 + num5);
                                cells[i][j].ways.push_back(cells[i - 1][j].ways[k1] + "D");
                                cells[i][j].ways_exist[cells[i - 1][j].ways[k1] + "D"]  = true;
                            }
                        }
                        else if((up2 == left2 && up5 >= left5) || (up5 == left5 && up2 >= left2) ){
                            if(cells[i][j].ways_exist.find(cells[i][j - 1].ways[k2] + "R") == cells[i][j].ways_exist.end()) {
                                cells[i][j].lnumber = leftleast;
                                cells[i][j].numberof2.push_back(left2 + num2);
                                cells[i][j].numberof5.push_back(left5 + num5);
                                cells[i][j].ways.push_back(cells[i][j - 1].ways[k2] + "R");
                                cells[i][j].ways_exist[cells[i][j - 1].ways[k2] + "R"]  = true;
                            }
                        }
                    }
                }
            }
        }
        cout<<endl;
    }
    cout<<cells[n - 1][n - 1].lnumber<<endl;
    cout<<cells[n - 1][n - 1].ways[0]<<endl;
    for (int i = 0 ; i < n; i++) {
        free(matrix[i]);
        delete []cells[i];
    }
    delete []cells;
    return 0;
}