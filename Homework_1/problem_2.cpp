#include <iostream>
#include <string>
#include <format>
#include <cmath>
using namespace std;

//region TRIANGLE
const float TILE_COST = 0.8;

float side_1;
float side_2;
float side_3;
//endregion

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
float calculate_triangle(float s1, float s2, float s3){ // NOLINT(*-non-const-parameter)
    float semi = (s1 + s2 + s3)/2;
    float area = sqrt(semi * (abs(semi - s1) * abs(semi - s2) * abs(semi - s3)));
    return area * TILE_COST;
}
//endregion

//region Homework Impl

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
    triangle_homework();
}