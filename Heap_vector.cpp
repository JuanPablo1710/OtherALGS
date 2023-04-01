#include <bits/stdc++.h>
using namespace std;

typedef struct THeap{
	
	vector<int> data;

	int size(){ return data.size(); }

	bool empty(){ return data.empty(); }

	void print(){
		for(int i = 0; i < data.size(); i++) cout << data[i] << " ";
	}

	int parent(int i){ return (i -1) / 2; }

	void push(int x){

		data.push_back(x);
		int tempinx = data.size()-1, pindex = parent(tempinx);

		while(tempinx > 0 && data[tempinx] > data[pindex]){

			swap(data[tempinx], data[pindex]);

			tempinx = pindex;
			pindex = parent(tempinx);
		}
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
