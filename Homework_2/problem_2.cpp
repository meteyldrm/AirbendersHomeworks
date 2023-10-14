#include <iostream>
#include <string>
#include <format>
#include <regex>
using namespace std;

string word;

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

void input(string* variable, string prompt){ // NOLINT(*-non-const-parameter)
    print(&prompt, false);
    getline(cin, *variable);
}
//endregion

//region Calculator Impl
bool is_palindrome(string s){
    //s.length = 6 -> [0,2] R E D D E R
    //s.length = 5 -> [0,1] K A Y A K
    for (int i = 0; i < s.length()/2; ++i) {
        if(s[i] != s[s.length()-1-i]){
            return false;
        }
    }
    return true;
}
//endregion

//region Homework Impl
void palindrome_homework(){
    bool again = false;
    while (true){
        //The console output doesn't match the strings here because of the use of MinGW. Non-issue.
        print("");
        if(again){
            input(&word, "Do you want to check another string? (y/n): ");
            if(word == "n"){
                break;
            }
        } else {
            print(R"(Set the string to "q" or "quit" to quit)");
            again = true;
        }

        input(&word, "Input palindrome candidate: ");
        if(word == "q" || word == "quit"){
            break;
        }

        string sanitized_word = regex_replace(word, regex("[^a-zA-Z]"), "");
        transform(sanitized_word.begin(), sanitized_word.end(), sanitized_word.begin(), ::tolower);

        if(is_palindrome(sanitized_word)){
            print(format("The word {} is a palindrome.", sanitized_word));
        } else {
            print(format("The word {} is NOT a palindrome.", sanitized_word));
        };

    }
}
//endregion

int main() {
    palindrome_homework();
}