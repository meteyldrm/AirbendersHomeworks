#include <iostream>
#include <string>
#include <format>
#include <cmath>
using namespace std;

//region BOX
const int STANDARD_BOX_SIZE = 9;

int n_count;
int m_count;
//endregion

//region TRIANGLE
const float TILE_COST = 0.8;

float side_1;
float side_2;
float side_3;
//endregion

int assignment;

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

void input(float* variable, string prompt){ // NOLINT(*-non-const-parameter)
    print(&prompt, false);
    cin >> *variable;
}
//endregion

//region Calculator Impl
void calculate_boxes(int n, int m){ // NOLINT(*-non-const-parameter)
    int n_div = n / STANDARD_BOX_SIZE;
    int n_mod = n % STANDARD_BOX_SIZE;
    //print("Standard size fills " + to_string(n_div) + " boxes with " + to_string(n_mod) + " leftovers.",true);
    print(format("Standard size fills {} boxes with {} leftovers.", n_div, n_mod));

    int m_div = n / m;
    int m_mod = n % m;
    //print("Non-standard size fills " + to_string(m_div) + " boxes with " + to_string(m_mod) + " leftovers.",true);
    print(format("Non-standard size fills {} boxes with {} leftovers.", m_div, m_mod));
}

float calculate_triangle(float s1, float s2, float s3){ // NOLINT(*-non-const-parameter)
    float semi = (s1 + s2 + s3)/2;
    float area = sqrt(semi * (abs(semi - s1) * abs(semi - s2) * abs(semi - s3)));
    return area * TILE_COST;
}
//endregion

//region Homework Impl
void box_homework(){
    while (true){
        //The console output doesn't match the strings here because of the use of MinGW. Non-issue.
        print("");
        print("Set the number of candles to <1 to return to assignments");
        input(&n_count, "Input the number of candles: ");
        if(n_count <= 0){
            break;
        }

        input(&m_count, "Input custom box size: ");
        if(m_count <= 0){
            print("m is <1. Please enter positive values.");
            continue;
        }

        calculate_boxes(n_count, m_count);
    }
}

void triangle_homework(){
    while (true){
        //The console output doesn't match the strings here because of the use of MinGW. Non-issue.
        print("");
        print("Set one side of the triangle to <1 to return to assignments");
        print("You can type float values, indicate decimal with \".\"");
        print("Input the sides of the triangle separated by a space: ", false);
        cin >> side_1 >> side_2 >> side_3;
        if(side_1 <= 0 || side_2 <= 0 || side_3 <= 0){
            break;
        }

        print(format("The total cost of the installation is {:.1f}$.", calculate_triangle(side_1, side_2, side_3)));
    }
}
//endregion

int main() {
    while (true){
        print("");
        print("Set assignment to <1 to quit");
        print("Type 1 for box, 2 for triangle");
        input(&assignment, "Which assignment do you want to run?");
        switch (assignment) {
            case 1:
                box_homework();
                break;
            case 2:
                triangle_homework();
                break;
            default:
                return 0;
        }
    }
}