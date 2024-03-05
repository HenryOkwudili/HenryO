#include <iostream>

using namespace std;
int main()
{
	char arr[] = {'a', 'e', 'i', 'o', 'u'};
	char arr2[] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
	cout<<"Enter character to check if it is vowel or consonant: "<<endl;
	int I;
	char cons;
	cin>>cons;
	for(I=0; I<1 ; I++){
	if (cons!=arr[I]&&cons==arr2[I]){
		cout<<"consonant"<<endl;
		}
	else if (cons==arr[I]&&cons!=arr2[I]) {
		cout<<"vowel"<<endl;
	}
		
	}
	
	return 0;
}
