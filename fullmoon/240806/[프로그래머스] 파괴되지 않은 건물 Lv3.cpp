#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int N = board.size(), M = board[0].size();
    int sum[1002][1002] = { 0, };
    for(int i = 0; i < skill.size(); ++i) {
        if(skill[i][0] == 1) {
            sum[skill[i][1]][skill[i][2]] -= skill[i][5];
            sum[skill[i][1]][skill[i][4] + 1] += skill[i][5];
            sum[skill[i][3] + 1][skill[i][2]] += skill[i][5];
            sum[skill[i][3] + 1][skill[i][4] + 1] -= skill[i][5];
        }
        else {
            sum[skill[i][1]][skill[i][2]] += skill[i][5];
            sum[skill[i][1]][skill[i][4] + 1] -= skill[i][5];
            sum[skill[i][3] + 1][skill[i][2]] -= skill[i][5];
            sum[skill[i][3] + 1][skill[i][4] + 1] += skill[i][5];
        }
    }
    for(int r = 0; r < N; ++r) {
        for(int c = 0; c < M; ++c) {
            sum[r][c + 1] += sum[r][c];
        }
    }
    for(int c = 0; c < M; ++c) {
        for(int r = 0; r < N; ++r) {
            sum[r + 1][c] += sum[r][c];
        }
    }
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(board[i][j] + sum[i][j] > 0) {
                answer++;
            }
        }
    }
    return answer;
}
