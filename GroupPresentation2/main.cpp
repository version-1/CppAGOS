//
//  main.cpp
//  GroupPresentation2
//
//  Created by Administlator on 2020/07/15.
//  Copyright © 2020 Administlator. All rights reserved.
//

#include <iostream>
#include <climits>
using namespace std;

int partition(int arr[], int l, int r);

int kthSmallest(int arr[], int l, int r, int k)
{
    int pos = partition(arr, l, r);
    
    if (pos - l == k - 1)
        return arr[pos];
    if (pos - l > k - 1)
        return kthSmallest(arr, l, pos - 1, k);
    
    return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int main(int argc, const char * argv[]) {
    int arr[] = {1, 6, 8, 4, 3, 10, 7, 9, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]), k = 2;
    cout << "K'th smallest element is " << kthSmallest(arr, 0, n - 1, k);
    return 0;
}
