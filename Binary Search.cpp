int binary_search(vector<int> &n, int target){
        int mn = 0, mx = n.size()-1, guess = (mn+mx)/2;

        while(mn <= mx){
            guess = (mn+mx)/2;
            if(n[guess] == target) return guess;
            if(n[guess] < target) mn = guess + 1;
            else mx = guess - 1;
        } 

        return -1;
    }
