class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        int h = board.size();
        int w = board[0].size();

        map<char, int> hashmap;

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (board[i][j] != '.') {
                    auto it = hashmap.find(board[i][j]);
                    if (it != hashmap.end()) {
                        return false;
                    }
                    hashmap[board[i][j]] = 1;
                }
            }
            hashmap.clear();
        }

        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < h; ++j) {
                if (board[j][i] != '.') {
                    auto it = hashmap.find(board[j][i]);
                    if (it != hashmap.end()) {
                        return false;
                    }
                    hashmap[board[j][i]] = 1;
                }
            }
            hashmap.clear();
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                map<char, int> m;
                for (int x = i; x < i + 3; x++) {
                    for (int y = j; y < j + 3; y++) {
                        if (board[x][y] != '.') {
                            if (m[board[x][y]] == 0) {
                                m[board[x][y]]++;
                            } else {
                                return false;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};