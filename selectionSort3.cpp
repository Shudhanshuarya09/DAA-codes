#include <iostream> 
#include <vector>
using namespace std;
void selectionSort(vector<int>& arr) { 
int n = arr.size();
for (int i = 0; i < n - 1; ++i) { 
int minIndex = i;
for (int j = i + 1; j < n; ++j) { 
if (arr[j] < arr[minIndex]) {
minIndex = j;
}
}
swap(arr[i], arr[minIndex]);
}
}
int main() {
vector<int> arr = {23, 34, 15, 43, 2};
cout<<" Shudhanshu arya GCS —>2140155"<<endl;
cout << "Original array: "; 
for (int num : arr) {
cout << num << " ";
}
cout << endl; 
selectionSort(arr);
cout << "Sorted array: "; 
for (int num : arr) {
cout << num << " ";
}
cout << endl;
return 0;
}
