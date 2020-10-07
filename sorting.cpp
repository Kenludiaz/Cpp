#include <iostream>
#include <vector>

using namespace std;
void mergeSort(std::vector <int> arr);
void mergeHalves(vector <int> leftArr)

int main() {
    std::vector <int> arr = {2, 3, 1, 8, 4, 9, 7};



}

void mergeSort(std::vector <int> arr) {
    size_t size = arr.size();
    size_t mid = size/2;
    vector<int> leftArr;
    vector<int> rightArr;

    for (int itr = 0; itr < mid; itr++) {
        leftArr.push_back(arr.at(itr));
    }
    for (int itr = mid; itr < size; itr++) {
        rightArr.push_back(arr.at(itr));
    }

    mergeSort(leftArr);
    mergeSort(rightArr);
    mergeHalves(leftArr, rightArr);
}

void mergeHalve() {

}