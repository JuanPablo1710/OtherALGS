#include <iostream>
#include <cmath>
using namespace std;

bool es_primo(int n){
	int sq = sqrt(n);

	if(n%2 == 2) return false;
	for(int i = 3; i <= sq; i+=2) if(n % i == 0) return false;

	return true;
}

int sig_primo(int n){
	n++;
	while(true)
		if(es_primo(n)) return n;
		else n++;
}

int main(){
	
	int n, actpr = 2, exp;
	cin >> n;
	
	while(n != 1){

		exp = 0;

		while(n % actpr == 0){
			n /= actpr;
			exp++;
		}

		if(exp) cout << actpr << " " << exp << '\n';

		actpr = sig_primo(actpr);
	}

	return 0;
}
