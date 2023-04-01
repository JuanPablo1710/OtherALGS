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

	int lson(int i){ return i*2 + 1; }
	int rson(int i){ return i*2 + 2; }

	int operator[](int i){ return data[i]; }

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

	void pop(){
		data[0] = data[index-1];
		index--;

		int tempinx = 0, hijo1 = lson(tempinx), hijo2 = rson(tempinx), maxp = -1;

		while(true){

			maxp = tempinx;

			if(hijo1 < index && data[hijo1] > data[maxp]) maxp = hijo1;
			if(hijo2 < index && data[hijo2] > data[maxp]) maxp = hijo2;

			if(maxp != tempinx) swap(data[maxp], data[tempinx]);
			else break;

			tempinx = maxp;
			hijo1 = lson(tempinx);
			hijo2 = rson(tempinx);
		}
	}

};

int main() {
	
	int n, k; 
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
