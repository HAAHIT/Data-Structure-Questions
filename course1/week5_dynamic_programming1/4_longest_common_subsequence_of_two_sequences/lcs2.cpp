#include <iostream>
#include <vector>

using std::vector;

int lcs2(vector<int> &x, vector<int> &y) {
  //write your code here
  int m = x.size();
  int n = y.size();
  int dp[m+1][n+1];
  for (int i = 0; i < m+1; i++) {
    for (int j = 0; j < n+1; j++) {
      dp[i][j]=0;
    }
  }
  for(int i=0;i<=m;i++){
      dp[i][0] = 0;
  }
  for(int j=0;j<=m;j++){
      dp[0][j] = 0;
  }
  for(int i=1;i<=m;i++){
      for(int j=1;j<=n;j++){
          if(x[i-1] == y[j-1]){
              dp[i][j] = dp[i-1][j-1]+1;
          }
          else{
              dp[i][j] = std::max(dp[i][j-1],dp[i-1][j]);
          }
      }
  }
  return dp[m][n];
  //return std::min(std::min(a.size(), b.size()), c.size());
}

int main() {
  size_t n=0;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m=0;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
