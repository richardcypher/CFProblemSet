#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

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
    bool zero = false;
    int zero_x = -1,zero_y = -1;
    int **matrix = new int*[n];

    int *matrix_2 = new int[n];
    int *matrix_5 = new int[n];
    string *ways_2 = new string[n];
    string * ways_5 = new string[n];
    for (int i = 0; i < n; i++){
        matrix[i] = new int[n];
    }
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>matrix[i][j];
            if (matrix[i][j] == 0) {
                zero = true;
                zero_x = i;
                zero_y = j;
                matrix[i][j] = 10;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            if(i == 0 && j == 0) {
                matrix_2[0] = getBaseInNumber(matrix[i][0],2);
                matrix_5[0] = getBaseInNumber(matrix[i][0],5);
                ways_2[0] = "";
                ways_5[0] = "";
            }
            else if (i == 0 && j != 0) {
                matrix_2[j] = getBaseInNumber(matrix[0][j],2) + matrix_2[j -1];
                matrix_5[j] = getBaseInNumber(matrix[0][j],5) + matrix_5[j -1];       
                ways_2[j] = ways_2[j - 1] + "R";
                ways_5[j] = ways_5[j - 1] + "R";         
            }
            else if(i != 0 && j == 0) {
                matrix_2[0] = getBaseInNumber(matrix[i][0],2) + matrix_2[0];
                matrix_5[0] = getBaseInNumber(matrix[i][0],5) + matrix_5[0];
                ways_2[0] = ways_2[0] + "D";
                ways_5[0] = ways_5[0] + "D";
            }
            else {
                int num2 = getBaseInNumber(matrix[i][j],2),num5 = getBaseInNumber(matrix[i][j],5);
                if (matrix_2[j - 1] < matrix_2[j]) {
                    matrix_2[j] = matrix_2[j - 1] + num2;
                    ways_2[j] = ways_2[j - 1] + "R";
                }
                else {
                    matrix_2[j] = matrix_2[j] + num2;
                    ways_2[j] = ways_2[j] + "D";
                }
                if (matrix_5[j - 1] < matrix_5[j]) {
                    matrix_5[j] = matrix_5[j - 1] + num5;
                    ways_5[j] = ways_5[j - 1] + "R";
                }
                else {
                    matrix_5[j] = matrix_5[j] + num5;
                    ways_5[j] = ways_5[j] + "D";
                }
            }
        }
    }

    int least_number = getMin(matrix_5[n - 1], matrix_2[n - 1]);
    if(least_number == 0 || !zero) {
        cout<<least_number<<endl;
        if (matrix_2[n -1] < matrix_5[n - 1])
            cout<<ways_2[n -1]<<endl;
        else
            cout<<ways_5[n -1]<<endl;
    }
    else{
        cout<<1<<endl;
        for (int i = 0; i < zero_x; i++) 
            cout<<"D";
        for (int i = 0; i < zero_y; i++)
            cout<<"R";
        for (int i = zero_x + 1; i < n; i++)
            cout<<"D";
        for (int i = zero_y + 1; i < n; i++)
            cout<<"R";
        cout<<endl;
    }
    
    
    for (int i = 0 ; i < n; i++) {
        delete []matrix[i];
    }
    delete []matrix;
    delete []matrix_5;
    delete []matrix_2;
    delete []ways_2;
    delete []ways_5;
    return 0;
}