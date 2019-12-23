#include <iostream>
#include <vector>
#include <cmath>
#include <random>

using namespace std;

template<class T>
void quickSort(T a[], int start, int end, default_random_engine e) {
    if(start == end) return;
    
    //int pivot = e() % (end - start + 1) + start;
    int pivot = end;
    T p = a[pivot];
    swap(a[pivot], a[end]);
    int i = start, j = start;
    for(; i < end; ++i) {
        if(a[i] < p) {
            swap(a[i], a[j]);
            ++j;
        }
    }
    swap(a[j], a[end]);
    quickSort(a, start, j-1, e);
    quickSort(a, j+1, end, e);
    
}

int main(){
    
    int range = pow(10, 5);
    int a[range];
    for(int i = 0; i < range; ++i) {
        a[i] = range - i;
    }
    //int p = findPivot<int>(a, 0, range);
    //cout << "Pivot index: " << p << endl;
    default_random_engine e;
    quickSort(a, 0, range-1, e);
    for(auto & e : a)
        cout << " " << e;
    cout << endl;
    return 0;
}
