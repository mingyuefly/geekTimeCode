//
//  main.cpp
//  binarySearch
//
//  Created by gmy on 2023/5/27.
//

#include <iostream>
#include <vector>

using namespace std;

class BinarySearch {
public:
    BinarySearch() {
        
    }
    ~BinarySearch() {
        cout << "~BinarySearch()" << endl;
    }
    int seartch(int k, vector<int> & array) {
        if (array.size() == 0) {
            return -1;
        }
        int l = 0;
        int r = (int)array.size() - 1;
        
        while (l <= r) { // 注意是<=
            int mid = l + (r - l)/ 2;
            if (array[mid] > k) {
                r = mid - 1;
            } else if (array[mid] < k) {
                l = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
private:
    
};

int main(int argc, const char * argv[]) {
    
    BinarySearch binarySearch;
    vector<int> arr = {1, 3, 4, 7, 8, 22, 31, 45, 65, 99, 123};
    cout << binarySearch.seartch(4, arr) << endl;
    cout << binarySearch.seartch(5, arr) << endl;
    cout << binarySearch.seartch(8, arr) << endl;
    cout << binarySearch.seartch(10, arr) << endl;
    
    return 0;
}
