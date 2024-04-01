#include <iostream>
#include <algorithm>

using namespace std;

int mergeAndCount(int* arr, int left, int mid, int right) {  
    int count = 0, i = left, j = mid, k = 0, *temp = new int[right - left + 1];

    while (i <= mid - 1 && j <= right)
    {
        // If a number in left < the right -> just keep going...
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        } else {
            // Validity found!
            count = (count + mid - i) % 1000000007; // Because left had been sorted, so ... 
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid - 1)
    {
        temp[k++] = arr[i++];
    }
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }
    
    for (int i = left; i <= right; i++)
    {
        arr[i] = temp[i - left];
    }

    return count;
}

int merge(int arr[], int left, int right) {
    if (left == right)
    {
        return 0;
    }
    
    int mid = (left + right) / 2;

    // Example: 3, 1, 5 | 4, 2 => count part (1,3,5) + count part (2,4) + count between (1,3,5) and (2,4)
    return (merge(arr, left, mid) + (merge(arr, mid + 1, right) + mergeAndCount(arr, left, mid + 1, right)) % 1000000007) % 1000000007;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);

    int *arr, n;

    cin >> n;

    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    cout << merge(arr, 0, n - 1) << endl;

    return 0;
}