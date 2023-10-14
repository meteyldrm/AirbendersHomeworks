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
//endregion

//region Homework Impl
void box_homework(){
    while (true){
        //The console output doesn't match the strings here because of the use of MinGW. Non-issue.
        print("");
        print("Set the number of candles to <1 to quit");
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
//endregion

int main() {
    box_homework();
}