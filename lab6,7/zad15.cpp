#include <iostream>
#include <string>

using namespace std;

const int N = 8;

int count_vowels(string name) {
    int counter = 0;
    for (int i = 0; i < name.size(); i++) {
        char x = name[i];
        if (x == 'a' || x == 'e' || x == 'o' || x == 'u' || x == 'y' || x == 'i') counter++;
    }
    return counter;
}

int sum_ASCII(string name) {
    int sum = 0;
    for (int i = 0; i < name.size(); i++) {
        sum += (int) name[i];
    }
    return sum;
}

bool can_build(string s1, string s2, string new_name, int index) {
    if (count_vowels(s1) == count_vowels(new_name) && sum_ASCII(s1) == sum_ASCII(new_name)) {
        cout << new_name << endl;
        return true;
    }
    if (index == s2.size()) return false;

    return wyrazy(s1, s2, new_name + s2[index], index + 1) || wyrazy(s1, s2, new_name, index + 1);
}

bool words(string s1, string s2) {
    string new_name = "";
    return can_build(s1, s2, new_name, 0);
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    return words(s1, s2);
}