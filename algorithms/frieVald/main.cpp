#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> matMul(vector<vector<int>> &A, vector<vector<int>> &B){

    if(A[0].size() != B.size()){
        cout << "Matrix multiplication not possible" << endl;
        return {};
    }
    int n = A.size();
    int m = A[0].size();
    int p = B[0].size();

    vector<vector<int>> result(n, vector<int>(p, 0)); // Initialize result matrix with zeros

    for(int i = 0; i < n; i++){
        for(int j = 0; j < p; j++){
            for(int k = 0; k < m; k++){
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

bool compareMat(vector<vector<int>> &A, vector<vector<int>> &B){

    if(A.size() != B.size() || A[0].size() != B[0].size()){
        return false;
    }

    int n = A.size();
    int m = A[0].size();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i][j] != B[i][j]){
                return false;
            }
        }
    }

    return true;
}

bool frieVald(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C){

    int n = A.size();
    int k = 4;

    for (int i = 0; i <k; i++){
        vector<vector<int>> r(1,vector<int>(n));

        for(int j = 0; j < n; j ++)
            r[0][j] = rand() % 2; 

        vector<vector<int>> b_r = matMul(r,B);
        vector<vector<int>> u = matMul(b_r,A);

        vector<vector<int>> v = matMul(r, C);

        if(compareMat(u,v) == false){
            return false;
        }

    }
    return true;
}

int main(){
    srand(time(0)); //For every different seed value used in a call to srand, the pseudo-random number generator can be expected to generate a different succession of results in the subsequent calls to rand.

    vector<vector<int>> A = {{0,1},{1,2}};
    vector<vector<int>> B = {{1,0},{0,1}};
    vector<vector<int>> C = {{0,1},{1,2}};
    
    if(frieVald(A,B,C)){
        cout << "True! A . B == C" << endl;
    }else{
        cout << "False! A . B is not equal to C" << endl;
    }

    return 0;
}

/*
this algo is a type of monte carlo algorithm, which checks if the matMul of two n * n matrices (A and B) is equal to a third n*n matrix C. The probability of a wrong answer is 1/2^k
PS: the rand() fn is not as random as i'd like*/