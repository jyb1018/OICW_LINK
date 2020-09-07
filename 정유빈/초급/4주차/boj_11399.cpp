#include <iostream>
#include <algorithm>

int arr[1000];

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for(int i = 0; i<N; i++)
        cin >> arr[i];
    sort(arr, arr+N);
    int allsum = 0;
    int sum = 0;
    for(int i = 0; i<N; i++)
        allsum += (sum += arr[i]);
    
    cout << allsum;
}
