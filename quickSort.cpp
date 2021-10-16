#include <iostream>
#include <stdlib.h>

using namespace std;

void swapEle(int * arr,int a,int b)
{
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

int pivotPos(int * arr,int min,int max)
{
	int piv = arr[max];
	int lastMin = min;

	for(int i = min;i<=max;i++)
		if(arr[i]<=piv)
		{
			swapEle(arr,i,lastMin);
			if(i!=max)
				lastMin ++;
		}
	return lastMin;
}

void quickSort(int * arr,int min,int max)
{
	if(min<max)
	{
		int pivI = pivotPos(arr,min,max);
		quickSort(arr,min,pivI-1);
		quickSort(arr,pivI+1,max);
	}

}

int main()
{
	int arr [5] = {6,2,9,1,4};
	quickSort(arr,0,(sizeof(arr)/4)-1);
	for(int i = 0;i<sizeof(arr)/4;i++)
		cout<<arr[i]<<" ";
}

