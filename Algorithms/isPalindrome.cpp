
using namespace std;

bool isPalindrome(string str) {
    string revString = "";
    for(int i = str.length() - 1; i >= 0; i--) {
        revString += str[i];
    }
    return str == revString;
}