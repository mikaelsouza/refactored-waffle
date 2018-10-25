#include <iostream>

using namespace std;

int main() {
    int stack = 0;
    int diamonds = 0;
    int entries;
    string input_text;

    cin >> entries;

    while (entries > 0) {
        cin >> input_text;
        for (auto letter : input_text) {
            if (letter == '<') stack += 1;
            if (letter == '>' and stack > 0) {
                stack -= 1;
                diamonds += 1;
            }
        }
        cout << diamonds << endl;
        stack = diamonds = 0;
        entries -= 1;
    }
}