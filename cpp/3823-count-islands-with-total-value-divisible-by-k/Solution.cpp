class Solution {
public:
    //Approach : DFS + Flood Fill + Island Sum

    //Time Complexity = O(m * n) =>
    /* 1. Grid Traversal: Nested loops traverse all m × n cells → O(m × n).
    2. DFS Traversal: Each land cell is visited at most once because visited cells are marked as 0 → O(m × n).
    3. Four Directions: Each cell explores 4 directions (constant work) → O(1) per cell.
    4. Divisibility Check: sum % k == 0 takes O(1) per island.
    */

    //Space Complexity = O(m * n) =>
    /* 1. DFS Recursion Stack: In the worst case, all m × n cells form one connected island, requiring up to O(m × n) recursive calls.
    2. Visited Array: Not required because visited cells are directly marked as 0 in the original grid → O(1) extra space.
    3. Variables: m, n, count, sum, i, and j require constant space → O(1).
    */


    //Step-2: Define DFS
    long long DFS(vector<vector<int>>& grid, int i, int j){

        int m = grid.size();
        int n = grid[0].size();

        //2.a) Check if current cell is out of bound
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0){
            return 0;
        }

        //2.b)otherwise , store current cell in sum
        long long sum = grid[i][j];

        //2.c) mark current cell visited
        grid[i][j] = 0;

        //Step-3: Explore all 4 directions
        sum += DFS(grid, i-1, j); //up
        sum += DFS(grid, i+1, j); //down
        sum += DFS(grid, i, j-1); //left
        sum += DFS(grid, i, j+1); //right

        //3.b)
        return sum;

    }
    int countIslands(vector<vector<int>>& grid, int k) {
        
        //Step-1: Initialize variables
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        //Step-4: Traverse the grid
        for(int i = 0; i < m; i++){

            for(int j = 0; j < n; j++){

                if(grid[i][j] > 0){

                    long long islandSum = DFS(grid, i, j);
            
                    if(islandSum % k == 0){
                        count++;
                    }
                }
            }
        }

        //Step-5: Return the result output
        return count;

    }
};