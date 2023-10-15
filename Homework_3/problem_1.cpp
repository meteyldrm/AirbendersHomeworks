#include <iostream>
#include <string>
#include <format>
#include <cmath>
#include <vector>
using namespace std;

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
template <typename T>
T get_second_largest(vector<T> list){
    T largest;
    T second;
    bool check_equal = true;
    for (int i = 0; i < list.size(); ++i) {
        if(i == 0){
            largest = list[i];
            second = list[i];
        }

        //If the entire list has the same number repeating, this will always remain true
        if(check_equal){
            check_equal = list[i] == largest;
        }

        if(list[i] <= largest){
            second = largest;
            largest = list[i];
        }
    }

    //If the equality checks lasted until the end, it means that the whole list is one number repeating
    if(check_equal){
        return 1;
    } else {
        return second;
    }
}

template <typename T>
T get_second_largest(int list_size, T *list){
    T largest;
    T second;
    bool check_equal = true;
    for (int i = 0; i < list_size; ++i) {
        if(i == 0){
            largest = list[i];
            second = list[i];
        }

        //If the entire list has the same number repeating, this will always remain true
        if(check_equal){
            check_equal = list[i] == largest;
        }

        if(list[i] >= largest){
            second = largest;
            largest = list[i];
        }
    }

    //If the equality checks lasted until the end, it means that the whole list is one number repeating
    if(check_equal){
        return 1;
    } else {
        return second;
    }
}
//endregion

//region Homework Impl
void product_homework(){
    print("Well, this one doesn't have a loop. Modify the code to change the product price array/vector.");
    //float x[] = {2.6, 2.4, 1.3, 3.4, 0.9, 0.95};
    int x[] = {2,54,43637,23,3214,342346};
    cout << "The second largest value is: " << to_string(get_second_largest(sizeof(x)/sizeof(x[0]), x));
}
//endregion

int main() {
    product_homework();
}