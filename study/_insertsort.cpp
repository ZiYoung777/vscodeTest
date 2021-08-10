#include <vector>
#include <iostream>
using namespace std;

void _insertsort(vector<int>& vec){
    int N=vec.size();
    for(int i=1;i<N;++i){
        int temp=vec[i];
        int j=i-1;
        while(j>=0&&vec[j]>temp){
            vec[j+1]=vec[j];
            --j;
        }
        vec[j+1]=temp;
    }
}

void _insertsort1(vector<int>& vec){
    int N=vec.size();
    for(int i=1;i<N;++i){
        int temp=vec[i];
        int j=i-1;        
        if(vec[j]<temp)
        continue;
        int left=0,right=i-1;
        while(left<right){
            int mid=(left+right)/2;
            if(vec[mid]>temp)
                right=mid;
            else
                left=mid+1;
        }
        while(j>=left){
            vec[j+1]=vec[j];
            --j;
        }
        vec[left]=temp;
    }
}

int main()
{
    vector<int> vec({95, 85, 12, 52, 64, 74, 105, 502, 4, 7, 6, 1, 74, 60, 141, 19, 34, 45, 59});
    _insertsort1(vec);
    for (auto num : vec)
        cout << num << " ";
    return 0;
}