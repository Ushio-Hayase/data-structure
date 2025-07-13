#include <iostream>

#include "segment_tree.cpp"

using namespace std;

int main()
{
    int* arr = new int[10];
    for (int i = 1; i <= 10; ++i) arr[i - 1] = i;
    SegmentTree<int> st(arr, 10);

    cout << st.find(3, 5) << '\n';

    st.replace(4, 14);

    cout << st.find(3, 5) << '\n';
}