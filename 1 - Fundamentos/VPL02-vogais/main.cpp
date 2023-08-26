#include <iostream>
#include <string>

using namespace std;

int main() {
    string user_input;
    int count_a = 0;
    int count_e = 0;
    int count_i = 0;
    int count_o = 0;
    int count_u = 0;

    //cout << "Please enter an word: " << endl;
    cin >> user_input;
    
    for (int i=0; i < user_input.length(); i++) {
        if (user_input[i] == 'A' or user_input[i] == 'a') count_a++;
        if (user_input[i] == 'E' or user_input[i] == 'e') count_e++;
        if (user_input[i] == 'I' or user_input[i] == 'i') count_i++;
        if (user_input[i] == 'O' or user_input[i] == 'o') count_o++;
        if (user_input[i] == 'U' or user_input[i] == 'u') count_u++;
    }
    
    if (count_a != 0) cout << "a " << count_a << endl;
    if (count_e != 0) cout << "e " << count_e << endl;
    if (count_i != 0) cout << "i " << count_i << endl;
    if (count_o != 0) cout << "o " << count_o << endl;
    if (count_u != 0) cout << "u " << count_u << endl;

}