#include <vector>
using namespace std;

bool isValidSubSequence(vector<int> array, vector<int> sequence) {
    int arrIdx = 0;
    int seqIdx = 0;
    while(arrIdx < array.size() && seqIdx < sequence.size()) {
        if(array[arrIdx] == sequence[seqIdx])
            seqIdx++;
        arrIdx++;
    }
    return seqIdx == sequence.size();
}