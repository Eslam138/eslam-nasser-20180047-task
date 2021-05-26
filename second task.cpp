#include <iostream>
using namespace std;
int max(int x, int y) {
   return (x > y) ? x : y;
}
int knapSack(int W, int price[], int value[], int num) {
    
   int i, wt;
   int K[num + 1][W + 1];
   for (i = 0; i <= num; i++) {
      for (wt = 0; wt <= W; wt++) {
         if (i == 0 || wt == 0)
         K[i][wt] = 0;
         else if (price[i - 1] <= wt)
            K[i][wt] = max(value[i - 1] + K[i - 1][wt - price[i - 1]], K[i - 1][wt]);
         else
        K[i][wt] = K[i - 1][wt];
      }
   }
   return K[num][W];
}
int main() {
   
   int n, W;
   n=8;
   string devices[8] = {"Gaming ","PC", " Apple Watch", "Iphone 12", "DVD-Set","Samsung Galaxy S12+","Apple Mac Box Air","Mac Pro"};
   int price[8]= {8, 3, 5, 1, 4, 20, 7, 22};
   int value[8]= {14, 5, 8, 3, 6, 28, 10, 27};
    W=30;
   cout << knapSack(W,price, value, n);
   return 0;
}