#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;

int dx[] = {0, -1, 0, 1, 0, 0};
int dy[] = {-1, 0, 1, 0, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};
int map[101][101][101];

void bfs(int h, int n, int m, queue<tuple<int,int,int>> &q){
  int cnt = 0;
  int current = q.size(), post = 0;
  while (!q.empty()){
    int a = get<0>(q.front()), b = get<1>(q.front()), c = get<2>(q.front());
    q.pop();

    for (int i = 0; i < 6; i++){
      int x = a + dx[i], y = b + dy[i], z = c + dz[i];
      if (x > 0 && x <= h && y > 0 && y <= n && z > 0 && z <= m){
        if (map[x][y][z] == 0){
          q.push(make_tuple(x,y,z));
          map[x][y][z] = 1;
          post++;
        }
      }
    }

    current--;
    if (current == 0) {
      current = post;
      post = 0;
      cnt++;
    }
  }

  for (int i = 1; i <= h; i++){
    for (int j = 1; j <= n; j++){
      for (int k = 1; k <= m; k++){
        if (map[i][j][k] == 0) {
          cout << -1 << endl;
          return;
        }
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

  int n, m, h;
  queue<tuple<int,int,int>> q;
  cin >> m >> n >> h;
  for (int i = 1; i <= h; i++){
    for (int j = 1; j <= n; j++){
      for (int k = 1; k <= m; k++){
        cin >> map[i][j][k];
        if (map[i][j][k] == 1) q.push(make_tuple(i,j,k));
      }
    }
  }
  bfs(h,n,m,q);
  return 0;
}
