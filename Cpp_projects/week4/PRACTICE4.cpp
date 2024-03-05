#include <iostream>
using namespace std;

int main()
{
	int n;
	cout <<"Enter number of values: "<<endl;
	cin>>n;
	
	int arr[n];
	cout<<"Enter "<<n<<" elements: "<<endl;
	for (int i = 0; i < n; ++i) {
		cin>>arr[i];
	}
	
	int maxelement = arr[0];
	int minelement = arr[0];
	
	for (int i = 1; i < n; ++i)
	{
		if (arr[i] > maxelement)
		{
			maxelement = arr[i];
		}
		if (arr[i] < minelement) 
		{
			minelement = arr[i];
		}
	}
	
	cout<<"maximum element in the array: "<<maxelement<<endl;
	cout<<"Minimum element in the array: "<<minelement<<endl;
	
	return 0;
}
