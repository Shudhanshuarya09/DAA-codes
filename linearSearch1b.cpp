#include <iostream> 
#include <vector>
using namespace std;
int linearSearch(vector<int>& arr, int low, int high, int target) { 
if (low > high)
return -1;
else if (arr[low] == target) 
return low;
else
return linearSearch(arr, low + 1, high, target);
}
int main() {
vector<int> arr = {3, 6, 8, 2, 5, 1, 7, 9, 4}; 
int target = 7;
int result = linearSearch(arr, 0, arr.size() - 1, target); 
cout<<" Shudhanshu arya GCS —>2140155"<<endl;
if (result != -1)
cout << "index: " << result << endl;
else
cout << "Element not found" << endl;
return 0;
}
