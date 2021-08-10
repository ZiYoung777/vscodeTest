#include <vector>
#include <iostream>
using namespace std;

void _shellsort(vector<int>& vec){
    int N=vec.size();
    for(int gap=N/2;gap>0;gap/=2){
        for(int i=gap;i<N;++i){
            int temp=vec[i];
            int j=i-gap;
            while(j>=0 && temp<vec[j]){//插入排序的内层
                vec[j+gap]=vec[j];
                j-=gap;
            }
            vec[j+gap]=temp;
        }
    }
}

int main()
{
    vector<int> vec({95, 85, 12, 52, 64, 74, 105, 502, 4, 7, 6, 1, 74, 60, 141, 19, 34, 45, 59});
    _shellsort(vec);
    for (auto num : vec)
        cout << num << " ";
    return 0;
}