
/**
 * ����һ����СΪ m x n ���������� grid ����ʾһ�������������������?row��col �� color �������е�ÿ��ֵ��ʾ��λ�ô�����������ɫ��

��������������ɫ��ͬ���������ĸ�����������һ������������ʱ����������ͬһ ��ͨ���� ��

��ͨ�����ı߽� ��ָ��ͨ�����е������벻�ڷ����е���������ڣ��ĸ������ϣ�����������飬����������ı߽��ϣ���һ��/�л����һ��/�У�����������顣

����ʹ��ָ����ɫ?color Ϊ���а��������?grid[row][col] �� ��ͨ�����ı߽� ������ɫ�����������յ�����?grid ��

?

ʾ�� 1��

���룺grid = [[1,1],[1,2]], row = 0, col = 0, color = 3
�����[[3,3],[3,2]]
ʾ�� 2��

���룺grid = [[1,2,2],[2,3,2]], row = 0, col = 1, color = 3
�����[[1,3,3],[2,3,3]]
ʾ�� 3��

���룺grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1, color = 2
�����[[2,2,2],[2,1,2],[2,2,2]]

*/






typedef pair<int, int> pii;

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pii> borders;
        int originalColor = grid[row][col];
        visited[row][col] = true;
        dfs(grid, row, col, visited, borders, originalColor);
        for (auto & [x, y] : borders) {
            grid[x][y] = color;
        }
        return grid;
    }

    void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>> & visited, vector<pii> & borders, int originalColor) {
        int m = grid.size(), n = grid[0].size();
        bool isBorder = false;
        int direc[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int i = 0; i < 4; i++) {
            int nx = direc[i][0] + x, ny = direc[i][1] + y;
            if (!(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == originalColor)) {
                isBorder = true;
            } else if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                dfs(grid, nx, ny, visited, borders, originalColor);
            }                
        }
        if (isBorder) {
            borders.emplace_back(x, y);
        }
    }
};