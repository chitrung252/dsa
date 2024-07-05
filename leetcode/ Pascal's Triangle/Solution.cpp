class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        result.push_back(std::vector<int>());
        result[0].push_back(1);
        for (int i = 1; i < numRows; i++) {
            result.push_back(std::vector<int>());
            for (int j = 0; j < i + 1; j++) {
                //                    if(i + 1 > 2){
                //                        if(j > 0 && j < i){
                //                            result[i].push_back(result[i - 1][j - 1] + result[i - 1][j]);
                //                        }else{
                //                            result[i].push_back(1);
                //                        }
                //                    }else{
                //                       result[i].push_back(1);
                //                    }

                if (j > 0 && j < i) {
                    result[i].push_back(result[i - 1][j - 1] + result[i - 1][j]);
                } else {
                    result[i].push_back(1);
                }
            }
        }

        return result;
    }
};