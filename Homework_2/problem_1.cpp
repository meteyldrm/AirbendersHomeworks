#include <iostream>
#include <string>
#include <format>
#include <cmath>
#include <vector>
using namespace std;

int prime;

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
int get_order(int p, int m){
    int order = 0;
    int order_value = p;
    for (int i = 1; i < p; ++i) {
        int value = (int)pow(m, i) % p;
        if(order_value > value){
            order_value = value;
            order = i;
        }
    }
    return order;
}

vector<int> calculate_orders(int p){
    vector<int> orders;
    for (int i = 1; i < p; ++i) {
        orders.push_back(get_order(p, i));
    }
    return orders;
}
//endregion

//region Homework Impl
void order_homework(){
    while (true){
        //The console output doesn't match the strings here because of the use of MinGW. Non-issue.
        print("");
        print("Set the prime to <1 to quit");
        print("Prints from the 1st order to p");
        input(&prime, "Input the prime to calculate the order for: ");
        if(prime <= 0){
            break;
        }

        print(format("Orders for {}:", prime));
        vector<int> orders = calculate_orders(prime);
        int c = 1;
        for (int x: orders) {
            cout << to_string(c++) << ") " << to_string(x) << endl;
        }
    }
}
//endregion

int main() {
    order_homework();
}