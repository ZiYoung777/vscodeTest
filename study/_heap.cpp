#include<iostream>
#include<vector>

using namespace std;
class heap{
public:
    int* heapPtr;
    int capacity;
    int curSize;

    void filterdown(int start);
    void filterup(int start);

public:
    heap();
    heap(int);
    heap(const vector<int>&);
    ~heap();

    int getIndex(int);
    void push(int);
    void pop();
    int top();
};

heap::heap(){
    new (this)heap(30);
}

heap::heap(int n){
    heapPtr=new int[n];
    curSize=0;
    capacity=n;
}

heap::heap(const vector<int>& vec){
    curSize=vec.size();
    capacity=2*curSize;
    heapPtr=new int[capacity];
    memcpy(heapPtr,&vec[0],curSize*sizeof(int));
    for(int i=(curSize+1)/2;i>=0;--i){
        filterdown(i);
    }
}

heap::~heap(){
    delete[] heapPtr;
}

void heap::filterdown(int start){
    int cur=start;
    int next=2*cur+1;
    while(next<curSize){
        if(next+1<curSize&&heapPtr[next]<heapPtr[next+1])
        ++next;
        if(heapPtr[cur]>heapPtr[next])  break;
        swap(heapPtr[cur],heapPtr[next]);
        cur=next;
        next=2*cur+1;
    }
}

void heap::filterup(int start){
    int cur=start;
    int father=(cur-1)/2;
    while(father>=0){
        if(heapPtr[cur]>heapPtr[father]){
            swap(heapPtr[cur],heapPtr[father]);
            cur=father;
            int father=(cur-1)/2;
        }
        else break;
    }
}

void heap::pop(){
    heapPtr[0]=heapPtr[curSize-1];
    --curSize;
    filterdown(0);
}

int heap::top(){
    return heapPtr[0];
}

void heap::push(int newVal){
    ++curSize;
    heapPtr[curSize-1]=newVal;
    filterup(curSize-1);
}


int main(){
    vector<int> vec({1,9,7,4,5,9,28,64,7});
    heap h(vec);
    cout<<h.curSize<<","<<h.capacity<<endl;
    for(int i=0;i<8;++i){
        cout<<h.top()<<endl;
        h.pop();
    }
}