
class Solution {
public:
    vector<vector<bool>> visit;
    vector<vector<int>> direction{
            {0,  1},
            {0,  -1},
            {1,  0},
            {-1, 0}
    };
    int res = INT_MAX / 2;

    int minimumEffortPath(vector<vector<int>> &heights) {
        int n = heights.size();
        int m = heights[0].size();
        visit.assign(n, vector(m, false));
        dfs(0, 0, heights, 0);
        return res;
    }

    void dfs(int i, int j, vector<vector<int>> &heights, int max_num) {
        if (visit[i][j] || max_num >= res) return;
        if (i == heights.size() - 1 && j == heights[0].size() - 1) {
            res = min(res, max_num);
            return;
        }
        visit[i][j] = true;

        for (auto &dir : direction) {
            int x = dir[0] + i;
            int y = dir[1] + j;
            if (x < 0 || y < 0 || x == heights.size() || y == heights[0].size()) {
                continue;
            }
            dfs(x, y, heights, max(max_num, abs(heights[i][j] - heights[x][y])));
        }

        visit[i][j] = false;
    }
};