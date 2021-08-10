#include <vector>
#include <iostream>
using namespace std;

void _mergesort(vector<int>& vec){
    
}


int main()
{
    vector<int> vec({95, 85, 12, 52, 64, 74, 105, 502, 4, 7, 6, 1, 74, 60, 141, 19, 34, 45, 59});
    _mergesort(vec);
    for (auto num : vec)
        cout << num << " ";
    return 0;
}