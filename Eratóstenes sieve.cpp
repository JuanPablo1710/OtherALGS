#include <bits/stdc++.h>
using namespace std;

int MAX_N = 10000001;
vector<bool> sieve(MAX_N, true);

void fil_sieve(){
	sieve[1] = false;

	for(int i = 2; i < MAX_N; i++){
		if(sieve[i]){
			for(int j = i+i; j < MAX_N; j+=i) sieve[j] = false;
		}
	}
}

int main(){

	std::cin.tie(nullptr);
  	std::ios_base::sync_with_stdio(false);

	fill_sieve();

	return 0;
}
