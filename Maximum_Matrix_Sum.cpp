class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        long long sum = 0;
        int negCnt = 0;
        int minAbs = INT_MAX;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int ele = matrix[i][j];
                if(ele < 0){
                    negCnt++;
                }

                sum = sum + llabs(ele);
                minAbs = min(minAbs, abs(ele));
            }
        }

        if(negCnt%2 == 1){
            sum = sum - 2*minAbs;
        }

        return sum;
    }
};
