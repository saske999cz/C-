#include <bits/stdc++.h>
using namespace std;
#define float_vec vector<float>
//to multiply two given matrix
vector<float_vec > multiply(vector<float_vec > A, vector<float_vec > B, int N) {
   vector<float_vec > C(N, float_vec(N, 0));
   for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
         for (int k = 0; k < N; ++k)
            C[i][j] += A[i][k] * B[k][j];
   return C;
}
//to calculate power of matrix
vector<float_vec > matrix_power(vector<float_vec > M, int p, int n) {
   vector<float_vec > A(n, float_vec(n, 0));
   for (int i = 0; i < n; ++i)
      A[i][i] = 1;
   while (p) {
      if (p % 2)
         A = multiply(A, M, n);
      M = multiply(M, M, n);
      p /= 2;
   }
   return A;
}
//to calculate probability of reaching from initial to final
float calc_prob(vector<float_vec > M, int N, int F, int S, int T) {
   vector<float_vec > matrix_t = matrix_power(M, T, N);
   return matrix_t[F - 1][S - 1];
}
int main() {
   vector<float_vec > G{
      { 0, 0.08, 0, 0, 0, 0 },
      { 0.33, 0, 0, 0, 0, 0.62 },
      { 0, 0.06, 0, 0, 0, 0 },
      { 0.77, 0, 0.63, 0, 0, 0 },
      { 0, 0, 0, 0.65, 0, 0.38 },
      { 0, 0.85, 0.37, 0.35, 1.0, 0 }
   };
   //number of available states
   int N = 6;
   int S = 4, F = 2, T = 100;
   cout << "Probability of reaching: " << F << " in time " << T << " after starting from: " << S << " is " << calc_prob(G, N, F, S, T);
   return 0;
}