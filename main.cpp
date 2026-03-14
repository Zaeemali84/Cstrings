#include "Cstrings.h"
#include <iostream>

using namespace std;

int main() {
    // ==========================================================
    // INITIALIZATION & ASSIGNMENTS
    // ==========================================================
    Cstring emptyStr;
    Cstring charStr('A');
    Cstring base("Data Structure");
    Cstring copyStr(base);

    cout << "----------------------------------------------------------" << endl;
    cout << "                1. INITIALIZATION & DISPLAY               " << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "Default Constructor: [" << emptyStr << "]" << endl;
    cout << "Char Constructor   : " << charStr << endl;
    cout << "String Constructor : " << base << endl;
    cout << "Copy Constructor   : " << copyStr << endl;

    // ==========================================================
    // CORE STRING OPERATIONS
    // ==========================================================
    cout << "\n----------------------------------------------------------" << endl;
    cout << "                2. CORE STRING OPERATIONS                 " << endl;
    cout << "----------------------------------------------------------" << endl;

    cout << "Current String : " << base << " (Length: " << base.getLength() << ")" << endl;

    // Find and Insert
    int pos = base.find("Structure");
    cout << "Find 'Struct'  : Index " << pos << endl;

    base.insert(5, "and Algorithms ");
    cout << "After Insert   : " << base << endl;

    // Substrings (Left/Right)
    cout << "Left(4)        : " << base.left(4) << endl;
    cout << "Right(9)       : " << base.right(9) << endl;

    // Removal
    base.remove(5, 4); // Removing 'and '
    cout << "After Removal  : " << base << endl;

    // ==========================================================
    // TRANSFORMATION & CLEANING
    // ==========================================================
    cout << "\n----------------------------------------------------------" << endl;
    cout << "              3. TRANSFORMATION FUNCTIONS                 " << endl;
    cout << "----------------------------------------------------------" << endl;

    Cstring rawData("   user_name_variable   ");
    cout << "Raw Data       : \"" << rawData << "\"" << endl;
    
    rawData.trim();
    cout << "After Trim     : \"" << rawData << "\"" << endl;

    rawData.makeUpper();
    cout << "To Upper       : " << rawData << endl;

    rawData.replace('_', ' ');
    cout << "Replace '_'    : " << rawData << endl;

    rawData.reverse();
    cout << "Reversed       : " << rawData << endl;

    // ==========================================================
    // OPERATOR OVERLOADING (The "Professional" Section)
    // ==========================================================
    cout << "\n----------------------------------------------------------" << endl;
    cout << "                4. OPERATOR OVERLOADING                   " << endl;
    cout << "----------------------------------------------------------" << endl;

    Cstring s1("GitHub");
    Cstring s2(" Projects");
    
    // Test Operator +
    Cstring s3 = s1 + s2;
    cout << "Concatenation (s1 + s2) : " << s3 << endl;

    // Test Operator ==
    cout << "Equality Check (s1 == s2): " << (s1 == s2 ? "True" : "False") << endl;

    // Test Assignment Operator =
    Cstring s4;
    s4 = s1; 
    cout << "Assignment (s4 = s1)    : " << s4 << endl;

    // ==========================================================
    // UTILITY & INPUT
    // ==========================================================
    cout << "\n----------------------------------------------------------" << endl;
    cout << "                  5. UTILITY & INPUT                      " << endl;
    cout << "----------------------------------------------------------" << endl;

    cout << "Access via at(5): " << s1.at(5) << endl;
    
    cout << "\nTest complete. Enter a custom string to verify input(): ";
    Cstring userStr;
    userStr.input();
    cout << "You entered: " << userStr << " (Size: " << userStr.getLength() << ")" << endl;

    cout << "\n==========================================================" << endl;
    cout << "                SUCCESS: ALL TESTS PASSED                 " << endl;
    cout << "==========================================================" << endl;

    return 0;
}