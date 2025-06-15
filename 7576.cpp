#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;


void bfs(int n, int m, int map[][1001], queue<pair<int,int>> &q){
  int cnt = 0;
  int current = q.size(), post = 0;
  while (!q.empty()){
    int a = q.front().first, b = q.front().second;
    q.pop();

    if (a-1 > 0 && map[a-1][b] == 0){
      q.push(make_pair(a-1,b));
      map[a-1][b] = 1;
      post++;
      
    }
    if (a+1 <= n && map[a+1][b] == 0) {
      q.push(make_pair(a+1,b));
      map[a+1][b] = 1;
      post++;
      
    }
    if (b-1 > 0 && map[a][b-1] == 0) {
      q.push(make_pair(a,b-1));
      map[a][b-1] = 1;
      post++;
      
    }
    if (b+1 <= m && map[a][b+1] == 0) {
      q.push(make_pair(a,b+1));
      map[a][b+1] = 1;
      post++;
      
    }

    current--;
    if (current == 0) {
      current = post;
      post = 0;
      cnt++;
    }
  }
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      if (map[i][j] == 0) {
        cout << -1 << endl;
        return;
      }
    }
  }
  cout << cnt-1 << endl;
  return;
}
int main(){
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  int n, m;
  int map[1001][1001]; 
  queue<pair<int,int>> q;
  cin >> m >> n;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      cin >> map[i][j];
      if (map[i][j] == 1) q.push(make_pair(i,j));
    }
  }
  bfs(n,m,map,q);
  return 0;
}
