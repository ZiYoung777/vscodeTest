#include <vector>
#include <iostream>
using namespace std;

void _bubblesort(vector<int> &vec)
{
    int N = vec.size();
    for (int i = 0; i < N; ++i)
    {
        for (int j = N - 1; j > i; --j)
        {
            if (vec[j] < vec[j - 1])
                swap(vec[j], vec[j - 1]);
        }
    }
}

void _bubblesort1(vector<int> &vec)
{ //增加已排序标记，减少比较次数
    int N = vec.size();
    for (int i = 0; i < N; ++i)
    {
        bool flag = 1;
        for (int j = N - 1; j > i; --j)
        {
            if (vec[j] < vec[j - 1])
            {
                swap(vec[j], vec[j - 1]);
                flag = 0;
            }
        }
        if (flag)
            return;
    }
}

void _bubblesort2(vector<int> &vec)
{ //以上次最后一次交换的位置为终点
    int N = vec.size();
    int left = 0;
    for (int i = 0; i < N; ++i)
    {
        bool flag = 1;
        int temp;
        for (int j = N - 1; j > left; --j)
        {
            if (vec[j] < vec[j - 1])
            {
                swap(vec[j], vec[j - 1]);
                flag = 0;
                temp = j;
            }
        }
        if (flag)
            return;
        left=temp;
    }
}

void _bubblesort3(vector<int> &vec)
{ //双向循环
    int N = vec.size();
    int left = 0,right=N-1;
    while (left<right)
    {
        bool flag = 1;
        int templ,tempr;
        for (int j = left; j <right; ++j)
        {
            if (vec[j] > vec[j + 1])
            {
                swap(vec[j], vec[j + 1]);
                flag = 0;
                tempr = j;
            }
        }
        for (int j = right - 1; j > left; --j)
        {
            if (vec[j] < vec[j - 1])
            {
                swap(vec[j], vec[j - 1]);
                flag = 0;
                templ = j;
            }
        }
        if (flag)
            return;
        left=templ;
        right=tempr;
    }
}

int main()
{
    vector<int> vec({95, 85, 12, 52, 64, 74, 105, 502, 4, 7, 6, 1, 74, 60, 141, 19, 34, 45, 59});
    _bubblesort3(vec);
    for (auto num : vec)
        cout << num << " ";
    return 0;
}