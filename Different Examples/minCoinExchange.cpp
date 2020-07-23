#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// returns the minimum number of coins necessary to represent the amount
int MinCoinExchange(vector<int>& coins, int& amount, vector<int>& exchange) {
    int i = coins.size() - 1;
    int noCoins = 0;
    sort(coins.begin(), coins.end());
    while (amount != 0) {
        if (amount >= coins[i]) {
            noCoins++;
            amount -= coins[i];
            exchange.push_back(coins[i]);
            continue;
        }
        else
            i--;
    }
    return noCoins;
}

int main() {
    vector<int> coins = { 5, 1, 25, 10 };
    vector<int> exchange;
  
    int amount = 68;// 2*25 + 1*10 + 1*5 + 3*1 = 68
  
    int noCoins = MinCoinExchange(coins, amount, exchange);
    cout << "Minimum coin exchance is: " << noCoins << endl;
    cout << "The coins are: " << endl;
    for (vector<int>::iterator iter = exchange.begin(); iter != exchange.end(); iter++) {
        cout << *iter << " ";
    }
    return 0;
}