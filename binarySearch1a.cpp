#include <iostream> 
#include <vector>
using namespace std;
int binarySearch(vector<int>& arr, int low, int high, int target) { 
if (high >= low) {
int mid = low + (high - low) / 2; 
if (arr[mid] == target)
return mid;
if (arr[mid] > target)
return binarySearch(arr, low, mid - 1, target); 
return binarySearch(arr, mid + 1, high, target);
}
return -1;
}

int main() {
vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
int target = 5;
int result = binarySearch(arr, 0, arr.size() - 1, target); 
cout<<"Shudhanshu arya GCS —>214015"<<endl;
if (result != -1)
cout << "index : " << result << endl;
else
cout << "Element not found" << endl;
return 0;
}
