#include <bits/stdc++.h>
using namespace std;

int const MAX_N = 10000001;
int lim = sqrt(MAX_N);
bitset<MAX_N> sieve;

void fil_sieve(){
	sieve[0] = sieve[1] = false;

	for(int i = 2; i <= lim; i++){
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
