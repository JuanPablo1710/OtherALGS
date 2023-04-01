#include <bits/stdc++.h>
using namespace std;

typedef struct THeap{
	int data[10000];
	int index;

	THeap(){ index = 0; }

	int size(){ return index; }

	bool empty(){ return index == 0; }

	int top(){ return data[0]; }

	void print(){for(int i = 0; i < index; i++) cout << data[i] << " "; }

	int parent(int i){ return (i -1) / 2; }

	void push(int x){

		int tempinx = index, pindex = parent(tempinx);
		data[index] = x; 

		while(tempinx > 0 && data[tempinx] > data[pindex]){

			swap(data[tempinx], data[pindex]);

			tempinx = pindex;
			pindex = parent(tempinx);
		}

		index++;
	}
};

int main() {
	
	int n; 
	cin >> n;

	THeap tree;

	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		tree.push(x);
	}

	tree.print();

	return 0;
}
