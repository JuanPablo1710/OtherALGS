#include <iostream>
#include <cmath>
using namespace std;

int cnt_dig(int n){
  int ret = 0;

  while(n){
    ret += n%10;
    n/=10;
  }

  return ret;
}

bool es_primo(int n){
	int sq = sqrt(n);

	for(int i = 2; i <= sq; i++) if(n % i == 0){
		return false;
	}

	return true;
}

int sig_primo(int n){
	n++;
	while(true)
		if(es_primo(n)) return n;
		else n++;
}

int main(){

	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	
	int n, actpr = 2, exp;
	cin >> n;

	long long sm = 0, smn = cnt_dig(n);
	
	while(n != 1){

		exp = 0;

		while(n % actpr == 0){
			n /= actpr;
			exp++;
		}

		if(exp){
      sm += cnt_dig(actpr)*exp;
    }

		actpr = sig_primo(actpr);
	}

	if(sm == smn) cout << 1;
	else cout << 0;

	return 0;
}
