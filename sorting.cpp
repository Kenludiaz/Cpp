#include <iostream>
#include <vector>

using namespace std;
void mergeHalves(vector <int> const & leftArr, vector <int> const & rightArr,
 vector <int>& arr);
void mergeSort(std::vector <int> &arr);

int main() {
    std::vector <int> arr = {2, 3, 1, 8, 4, 9, 7};

    mergeSort(arr);
    for (auto const &it : arr)
    {
        std::cout << it << " " << endl;
    }

}


void mergeHalves(vector <int> const & leftArr, vector <int> const & rightArr,
 vector <int>& arr) {
    size_t i = 0, k = 0, j = 0;
    // WHILE ARR IS NOT FILLED
    while ( k < arr.size()) 
    {   
        if ( i >= leftArr.size() || rightArr[j] < leftArr[k])
        {
            arr[k] = rightArr[j];
            j++, k++;
        } 
        else if (j >= rightArr.size() || leftArr[i] < rightArr[j])
        {
            arr[k] = leftArr[i];
            i++, k++;
        }

        
    }
}
void mergeSort(std::vector <int> &arr) {
    size_t size = arr.size();
    size_t mid = size/2;
    if (size < 2)
    {
        return;
    }

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
    mergeHalves(leftArr, rightArr, arr);
}