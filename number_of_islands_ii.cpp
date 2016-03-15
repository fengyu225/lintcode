/*
Given a n,m which means the row and column of the 2D matrix and an array of pair A( size k). Originally, the 2D matrix is all 0 which means there is only sea in the matrix. The list pair has k operator and each operator has two integer A[i].x, A[i].y means that you can change the grid matrix[A[i].x][A[i].y] from sea to island. Return how many island are there in the matrix after each operator.

Given n = 3, m = 3, array of pair A = [(0,0),(0,1),(2,2),(2,1)].

return [1,1,2,2].
*/

#include "header.h"

vector<int> numIslands2(int n, int m, vector<Point>& operators) {
    vector<int> res;
    return res;
}

int main(){
    vector<Point> operators = {
        {0, 0},
        {0, 1},
        {2, 2},
        {2, 1}
    };    
    vector<int> res = numIslands2(3, 3, operators);
    print_vector<int>(res);
    return 0;
}