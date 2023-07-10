#include <bits/stdc++.h>
using namespace std;

struct TNodeData{
	int i, j;
};

struct TNode{
	TNodeData data;
	TNode *next;

	TNode(){
		next = NULL;
	}
};

struct TList{
	TNode *begin;
	TNode *end;

	TList(){
		begin = end = NULL;
	}

	~TList(){
		while(begin != NULL) remove();
	}

	void insert(TNodeData d){
		TNode *t = new TNode;

		t->data = d;

		if(begin == NULL){
			begin = end = t;
			return;
		}

		end->next = t;
		end = t;
	}

	void remove(){
		if(begin == NULL) return;

		TNode *t = begin;
		begin = begin->next;
		delete t;
	}

	TNode *front(){
		return begin;
	}

	bool empty(){
		return begin == NULL;
	}
};

int main() {

	std::cin.tie(nullptr);
  	std::ios_base::sync_with_stdio(false);

	int a = 0, b = 0;

	TList cola;
	cola.insert({a, b});
	TNode *p;  

	while(!cola.empty()){
		p = cola.front();

		TNodeData h = p->data;

		cola.remove();
	}

	return 0;
}
