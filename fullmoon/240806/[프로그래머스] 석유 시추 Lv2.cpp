#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Oil {
  int y, x;  
};

int N, M;
int gain[502];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void findOil(vector<vector<int>> &land, int y, int x) {
    int s = x, e = x;
    int cnt = 0;
    
    queue<Oil> q;
    q.push({ y, x });
    while(!q.empty()) {
        Oil now = q.front();
        q.pop();
        if(e < now.x) e = now.x;
        else if(s > now.x) s = now.x;
        cnt++;
        
        for(int i = 0; i < 4; ++i) {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(!land[ny][nx]) continue;
            land[ny][nx] = 0;
            q.push({ ny, nx });
        }
    }
    gain[s] += cnt;
    gain[e + 1] -= cnt;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    N = land.size();
    M = land[0].size();
    int cnt = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(!land[i][j]) continue;
            land[i][j] = 0;
            findOil(land, i, j);
        }
    }
    for(int i = 0; i < M; ++i) {
        gain[i + 1] += gain[i];
        if(answer < gain[i]) answer = gain[i];
    }
    return answer;
}
