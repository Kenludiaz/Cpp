#include <iostream>
#include <string>
#include <set>
#include <list>

using namespace std;

// bool isUnique(string s) {
//     set <char> myString;
//     for (auto itr = s.begin(); itr != s.end(); itr++) {
//         auto var = myString.insert((*itr));
//         if (!var.second) {
//             return false;
//         }
//     }
//     return true;
// }

bool removeDupes(list<int> myList) {
    set <int> mySet;
    list<int>::iterator Itr;
    for (Itr = myList.begin(); Itr != myList.end(); Itr++) {
        auto myVal = mySet.insert(Itr);
        if (myVal.second == false) {
            myList.erase(Itr);
        }
    }
}

int main(int argc, char ** argv) {
    // Question 1:

    // Ex: solosasy

    // cout << isUnique(argv[1]) << std::endl;
}