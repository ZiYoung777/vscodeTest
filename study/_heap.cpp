#include<iostream>

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

heap::~heap(){
    delete[] heapPtr;
}

void heap::filterdown(int start){
    int cur=start;
    int next=2*cur+1;
    while(next<curSize){
        if(heapPtr[cur]<heapPtr[next]){
            swap(heapPtr[cur],heapPtr[next]);
            cur=next;
            next=2*cur+1;
        }
        else if(next+1<curSize && heapPtr[cur]<heapPtr[next+1]){
            swap(heapPtr[cur],heapPtr[next+1]);
            cur=next+1;
            next=2*cur+1;
        }
        else break;
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
    heap h(10);
    h.push(9);
    h.push(89);
    h.push(3);
    h.push(20);
    h.push(20);
    h.push(20);
    h.push(20);
    h.push(9);
    for(int i=0;i<8;++i){
        cout<<h.top()<<endl;
        h.pop();
    }
}