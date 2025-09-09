#include <iostream>
#include <string>
using namespace std;

int find_pattern(string text, string pattern) {
    int pos = text.find(pattern);
    if (pos != string::npos) {
        return pos;
    } else {
        return -1;
    }
}
void Patternbeginning() {
    int result = find_pattern("he is a player ", "h");
    if (result == 0) {  
        cout << "Test Case 1 Pattern_at_the_beginning: Passed" << endl;
    } else {
        cout << "Test Case 1 Pattern_at_the_beginning: Failed" << endl;
    }
}
void PatternEnd() {
    int result = find_pattern("Ali is a student of DSA", "DSA");
    if (result == 20) {  
        cout << "Test Case 2 Pattern_at_the_End: Passed" << endl;
    } else {
        cout << "Test Case 2 Pattern_at_the_End: Failed" << endl;
    }
}
void Patternnotpresent() {
    int result = find_pattern("I am not a student of DSA ", "XYZ");
    if (result == -1) {  
        cout << "Test Case 3 Pattern_not_present: Passed" << endl;
    } else {
        cout << "Test Case 3 Pattern_not_present: Failed" << endl;
    }
}
void Emptypattern() {
    int result = find_pattern("I am a student of DSA ", "");
    if (result == 0) {  
        cout << "Test Case 4 Empty_pattern: Passed" << endl;
    } else {
        cout << "Test Case 4 Empty_pattern: Failed" << endl;
    }
}

int main() {
    // Calling all the test cases
    Patternbeginning();
   PatternEnd();
    Patternnotpresent();
    Emptypattern();
    
    return 0;
}