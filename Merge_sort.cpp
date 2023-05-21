#include <bits/stdc++.h>
using namespace std;

int arr[100], aux[100];

void mergesort(int arr[], int l, int r){
	if(l == r) return;

	int mit = (l+r)/2;

	mergesort(arr, l, mit);
	mergesort(arr, mit+1, r);

	int itlft = l, itrg = mit+1, mxlft = mit, mxrg = r, itaux = l;

	while(itlft <= mxlft && itrg <= mxrg){
		if(arr[itlft] < arr[itrg]) aux[itaux++] = arr[itlft++];
		else aux[itaux++] = arr[itrg++];
	}

	while(itlft <= mxlft) aux[itaux++] = arr[itlft++];
	while(itrg <= mxrg) aux[itaux++] = arr[itrg++];

	for(int i = l; i <= r; i++) arr[i] = aux[i];
}

int main() {
	
	int n; cin >> n;

	for(int i = 0; i < n; i++) cin >> arr[i];

	mergesort(arr, 0, n-1);

	for(int i = 0; i < n; i++) cout << arr[i] << " ";

	return 0;
}
