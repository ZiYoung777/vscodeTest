#include<vector>
#include<iostream>

using namespace std;

void quicksort(vector<int> &input,int start,int end);

void quicksort(vector<int> &input){
    quicksort(input,0,(int)input.size()-1);
}

void quicksort(vector<int> &input,int start,int end){
    if(start>=end)
    return;

    swap(input[start],input[rand()%(end-start+1)+start]);

    int k=input[start];
    int l=start+1,r=end;
    while(1){
        while(l<=end&&input[l]<=k)    ++l;
        while(r>start&&input[r]>k)    --r;
        if(l>r)
        break;
        swap(input[l],input[r]);
        ++l;
        --r;
    }
    swap(input[start],input[r]);
    quicksort(input,start,r-1);
    quicksort(input,r+1,end);
}

int main(){
    vector<int> vec({8,7,5,6,9,5,5,5,98,26});
    quicksort(vec);
    return 0;
}