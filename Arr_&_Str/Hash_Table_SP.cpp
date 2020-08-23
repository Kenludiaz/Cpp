// #include <iostream>
// #include <list>
// #include <string>
// using namespace std;

// class HashTable {
//     private:
//         static const int hashGroups = 10;
//         list<pair<int,string>> table[hashGroups];

//     public:
//         bool isEmpty() const;
//         int hashFunction(int key);
//         void insertItem(int key, string value);
//         void removeItem(int key);
//         string searchTable(int key);
//         void printTable();
// };
// bool HashTable::isEmpty() const {
//     int sum = 0;
//     for (int i{}; i < hashGroups; i++) {
//         sum += table[i].size();
//     }
//     if (sum == 0) {
//         return true;
//     }
//     return false;
// }
// int HashTable::hashFunction(int key) {
//     return key % hashGroups;
// }

// void HashTable::insertItem(int key, string value) {
//     int hashValue = hashFunction(key);
//     auto& cell = table[hashValue];
//     auto bItr = begin(cell);
//     bool keyExists = false;
//     for (; bItr != end(cell); bItr++) {
//         if (bItr->first == key) {
//             keyExists = true;
//             bItr->second = value;
//             cout << "[Warning] Key exists. Value has been replaced" << "\n";
//             break;
//         }
//     }
//     if (!keyExists) {
//         cell.emplace_back(key,value);
//     }
//     return;
// }
// void HashTable::removeItem(int key) {
//     int hashValue = hashFunction(key);
//     auto& cell = table[hashValue];
//     auto bItr = begin(cell);
//     bool keyExists = false;
//     for (; bItr != end(cell); bItr++) {
//         if (bItr->first == key) {
//             keyExists = true;
//             bItr = cell.erase(bItr);
//             cout << "[INFO] Hey, Item removed." << "\n";
//             break;
//         }
//     }
//     if (!keyExists) {
//         cout << "[WARNING] Key not found.";
//     }
//     return;
// }

// void HashTable::printTable() {
//     for (int i{}; i < hashGroups; i++) {
//         if (table[i].size() == 0) continue;

//         auto bItr = table[i].begin();
//         for (; bItr != table[i].end(); bItr++) {
//             cout << "[INFO] Key: " << bItr->first << " Value: "
//             << bItr->second << "\n";
//         }
//     }
// }


// int main() {
//     HashTable HT;

//     if (HT.isEmpty()) {
//         cout << "Correct answer." << "\n";
//     }
//     else {
//         cout << "There's an issue" << "\n";
//     }
//     HT.insertItem(905,"Jim");
//     HT.insertItem(932,"Jon");
//     HT.insertItem(907,"Jam");
//     HT.insertItem(951,"Tom");
//     HT.insertItem(902,"Kun");
//     HT.insertItem(802,"Kan");
//     HT.insertItem(802,"Rick");
//     HT.insertItem(202,"Rob");
//     HT.insertItem(113,"Kancer");

//     HT.printTable();
//     HT.removeItem(113);
//     HT.removeItem(112);
//     if (HT.isEmpty()) {
//         cout << "Oh no, we need to check out our code" << "\n";
//     }
//     else {
//         cout << "Correct Answer! Good Job" << "\n";
//     }

// }


#include <iostream>
#include <list>
#include <string>
using namespace std;
// This code saves phone numbers into a Hash Table with a doubly linked list

class HashTable {
    private: 
        static const int hashGroups = 10;
        list< pair<int, string> > hashTable[hashGroups];
    public:
    bool isEmpty() const;
    int hashFunction(int key);
    void insertItem(int key, string name);
    void removeItem(int key);
    list< string > searchTable(int key);
    void printTable();
};

bool HashTable::isEmpty() const{
    int sum = 0;
    for (int i{}; i < hashGroups; i++) {
        sum += hashTable[i].size();
    }
    if (sum == 0) {
        return true;
    }
    return false;
}

int HashTable::hashFunction(int key) {
    return (key % hashGroups);
}

void HashTable::insertItem(int key, string name) {
    int hashValue = hashFunction(key);
    auto& cell = hashTable[hashValue];
    auto bItr = begin(cell);
    bool itExists = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            itExists = true;
            cout << "[WARINING] Key already exists. Value has been replaced" << "\n";
            bItr->second = name;
            return;
        }
    }
    cout << "Value Successfully Inserted. Good Job!" << "\n";
    cell.emplace_back(key, name);
}

void HashTable::removeItem(int key) {
    int hashValue = hashFunction(key);
    auto& cell = hashTable[hashValue];
    auto bItr = begin(cell);
    bool itExists = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            cout << "Key exists. Value has been removed" << "\n";
            bItr = cell.erase(bItr);
            itExists = true;
        }
    }
    if (!itExists) {
        cout << "Value does not exists" << "\n";
    }
}

void HashTable::printTable() {
    for (int i = 0; i < hashGroups; i++) {
        if (hashTable[i].size() == 0) continue;

        auto bItr = begin(hashTable[i]);
        for (; bItr != end(hashTable[i]); bItr++) {
            cout << "Key: " << bItr->first << " Value: " <<
            bItr->second;
        }
    }
    
}

list <string> HashTable::searchTable(int key) {
    list <string> searchTableResults;
    if (hashTable[key].size() == 0) {
        cout << "Sorry, no value exists in this key." << "\n";
        return searchTableResults;
    }
    auto bItr = begin(hashTable[key]);
    for (; bItr != end(hashTable[key]); bItr++) {
        cout << "[Search Table Results]Key: " << bItr->first << " Value: " <<
            bItr->second;
            searchTableResults.emplace_back(bItr->second);
    }
    return searchTableResults;
}

int main() {
        HashTable HT;

    if (HT.isEmpty()) {
        cout << "Correct answer." << "\n";
    }
    else {
        cout << "There's an issue" << "\n";
    }
    HT.insertItem(905,"Jim");
    HT.insertItem(932,"Jon");
    HT.insertItem(907,"Jam");
    HT.insertItem(951,"Tom");
    HT.insertItem(902,"Kun");
    HT.insertItem(802,"Kan");
    HT.insertItem(802,"Rick");
    HT.insertItem(202,"Rob");
    HT.insertItem(113,"Kancer");
    HT.searchTable(932);

    HT.printTable();
    HT.removeItem(113);
    HT.removeItem(112);
    if (HT.isEmpty()) {
        cout << "Oh no, we need to check out our code" << "\n";
    }
    else {
        cout << "Correct Answer! Good Job" << "\n";
    }
}