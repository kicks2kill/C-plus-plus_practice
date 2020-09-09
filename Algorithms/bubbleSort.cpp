#include <vector>
using namespace std;

vector<int> bubleSort(vector<int> array);


vector<int> bubbleSort(vector<int> array) {
    if(array.empty()) {
        return {};
    }
    bool isSorted = false;
    int counter = 0;
    while(!isSorted) {
        isSorted = true;
        for(int i = 0; i < array.size() - 1 - counter; i++){
            if(array[i] > array[i + 1]) {
                swap(array[i],array[i+ 1]);
                isSorted = false;
            }
        }
        counter++;
    }
    return array;
}
