#include <iostream>
#include <string>
#include <format>
#include <vector>
using namespace std;

int row_count;
int column_count;
vector<vector<int>> matrix1;
vector<vector<int>> matrix2;

//region Helpers
void print(string* text, bool newline = true){
    cout << *text;
    if(newline){
        cout << endl;
    }
}

void print(const string& text, bool newline = true){
    cout << text;
    if(newline){
        cout << endl;
    }
}

void input(int* variable, string prompt){ // NOLINT(*-non-const-parameter)
    print(&prompt, false);
    cin >> *variable;
}

void input(int* variable1, int* variable2, string prompt){ // NOLINT(*-non-const-parameter)
    print(&prompt, false);
    cin >> *variable1 >> *variable2;
}

void input(float* variable, string prompt){ // NOLINT(*-non-const-parameter)
    print(&prompt, false);
    cin >> *variable;
}
//endregion

//region Matrix Adapter
int get_matrix_value(vector<vector<int>>* matrix, int row, int column){
    return matrix->at(row-1).at(column-1);
}

void set_matrix_value(vector<vector<int>>* matrix, int row, int column, int value){
    if(matrix->size() < row){
        vector<int> temp_vector;
        for (int i = 0; i < column; ++i) {
            temp_vector.push_back(0);
        }
        matrix->push_back(temp_vector);
    }
    matrix->at(row-1).assign(column-1, value);
}

void print_matrix(vector<vector<int>>* matrix){
    for (const vector<int>& v:*matrix) {
        for (int i: v){
            cout << to_string(i) << " ";
        }
        cout << endl;
    }
}
//endregion

//region Homework Impl
bool check_matrix_full(vector<vector<int>>* var){
    if(var->size() == column_count){
        if(var->back().size() == row_count){
            return true;
        }
    }
    return false;
}

void matrix_homework(){
    while (true){
        //The console output doesn't match the strings here because of the use of MinGW. Non-issue.
        print("");
        input(&row_count, &column_count, "Type the number of rows, and the number of columns separated by \" \":");
        print("Entering values for the first matrix");
        while (!check_matrix_full(&matrix1)){
            //FIXME: Why are i and j not changing?
            for (int i = 1; i < column_count; ++i) {
                for (int j = 1; j < row_count; ++j) {
                    int temp;
                    cin >> temp;
                    set_matrix_value(&matrix1, j, i, temp);
                }
            }
        }
        print("Entering values for the second matrix");
        while (!check_matrix_full(&matrix2)){
            for (int i = 1; i < column_count; ++i) {
                for (int j = 1; j < row_count; ++j) {
                    int temp;
                    cin >> temp;
                    set_matrix_value(&matrix2, j, i, temp);
                }
            }
        }
        print("Matrix values:");
        cout << endl << endl;
        print_matrix(&matrix1);
    }
}
//endregion

int main() {
    matrix_homework();
}