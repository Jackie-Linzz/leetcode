#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template<class T>
void sort(T a[], int start, int num);

template<class T>
void bubbleSort(T a[], int start, int num) {
    T temp;
    for(int i = 1; i < num; ++i)
        for(int j = start; j < start+num-i; ++j) {
            if(a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
}

template<class T>
void mergeSort(T a[], int start, int num) {
    if(num <= 1) return;
    int num1 = num >> 1;
    int num2 = num - num1;
    sort(a, start, num1);
    sort(a, start+num1, num2);
    T temp[num];
    int i = start, j = start + num1, k = 0;
    while(i < start + num1 && j < start + num) {
        if(a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while(i < start + num1) temp[k++] = a[i++];
    while(j < start + num) temp[k++] = a[j++];
    for(i = 0; i < num; ++i)
        a[start + i] = temp[i];
}

template<class T>
int findPivot(T a[], int start, int num) {
    
    int p_num = 3;
    if(num > 1000) {
        p_num = 9;
    } else if (num > 500) {
        p_num = 5;
    } else {
        p_num = 3;
    }
    if(num < 8) {
        return start + num - 1;
    }
    
    T b[p_num];
    int bi[p_num];
    int step = num / p_num;
    for(int i = 0; i < p_num; ++i) {
        bi[i] = start + i * step;
        b[i] = a[start + i * step];
    }
    
    for(int i = 1; i < p_num; ++i)
        for(int j = 0; j < p_num-i; ++j) {
            if(b[j] > b[j+1]) {
                T temp = b[j];
                b[j] = b[j+1];
                b[j+1] = temp;

                int t = bi[j];
                bi[j] = bi[j+1];
                bi[j+1] = t;
                
            }
        }
    int index = p_num >> 1;
    int p = bi[index];
    if(p < start || p >=start+num) cout << "start: " << start << endl << "num: " << num << endl;
    return p;
}

template<class T>
void quickSort(T a[], int start, int num) {
    if(num <= 1) return;
    
    int end = start + num;
    int p = findPivot<T>(a, start, num);
    T pivot = a[p];
    //swap a[p] and a[end-1]
    if(p != end-1) {
        T t = a[end-1];
        a[end-1] = a[p];
        a[p] = t;
    }
    
    int i = start, j = start;
    for(; i < end; ++i) {
        if(a[i] < pivot) {
            T t = a[j];
            a[j] = a[i];
            a[i] = t;
            ++j;
        }
    }
    //swap a[j] a[end-1]
    T t = a[j];
    a[j] = a[end-1];
    a[end-1] = t;
    
    sort<T>(a, start, j - start);
    sort<T>(a, j + 1, end - j - 1);
}


template<class T>
void sort(T a[], int start, int num) {
    if(num > pow(10, 5)) quickSort(a, start, num);
    else if(num > 5) mergeSort(a, start, num);
    else bubbleSort(a, start, num);
}


int main(){
    
    int range = pow(10, 6);
    int a[range];
    for(int i = 0; i < range; ++i) {
        a[i] = range - i;
    }
    //int p = findPivot<int>(a, 0, range);
    //cout << "Pivot index: " << p << endl;
    sort(a, 0, range);
    for(auto & e : a)
        cout << " " << e;
    cout << endl;
    return 0;
}
