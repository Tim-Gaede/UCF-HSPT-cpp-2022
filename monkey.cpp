// Solution written by: Sathvik Kuthuru
#include <bits/stdc++.h>

using namespace std;

// Maximum possible grid size
const int MAXN = 1000;
// Direction arrays to help us traverse the 4 adjacent directions
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

// The number of rows and columns respectively
int n, m, totalMonkeys;
// A grid of max size to take in input
int grid[MAXN][MAXN];

/*
    A cell is only valid if:
        -It is inside the bounds of the grid
        -Hasn't been visited yet
        -The strength of the machete can cut down the tree on that cell
*/
bool validCell(int y, int x, vector<vector<bool>> &v, int maxStrength) {
    return y >= 0 && x >= 0 && y < n && x < m && !v[y][x] && grid[y][x] <= maxStrength;
}

// When visiting a cell, we will mark it as visited and place it in our bfs queue
void visitCell(int y, int x, vector<vector<bool>> &v, deque<pair<int, int>> &q) {
    v[y][x] = true;
    q.emplace_back(y, x);
}

// A helper function which visit a cell only if it is valid
void tryCell(int y, int x, vector<vector<bool>> &v, deque<pair<int, int>> &q, int maxStrength) {
    if(validCell(y, x, v, maxStrength)) visitCell(y, x, v, q);
}

// Given the current strength of our machete, check if all monkeys can escape
bool checkEscape(int maxStrength) {
    /*
        Checking if all the monkeys can reach an edge cell in our grid
        is equivalent to checking if we can start at every edge cell and try to reach
        all the monkeys.

        We could try a bfs from every edge cell and check at the end if every monkey
        is visited. However this could be O((n + m) * nm) in worst case. Instead we can
        do a multi-source bfs where we add every edge cell to our queue at the start. This way,
        we only have to do one bfs which will be O(nm).

        Lastly, our maxStrength parameter restricts us to only moving to cells that require
        a chopping strength <= maxStrength
    */

    // 2D visited array, initially every cell is unvisited
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    // Our queue for the bfs will store both row and column locations
    deque<pair<int, int>> bfsQueue;

    // Initially add only the edge cells to our queue, avoiding adding the corners twice
    for(int i = 0; i < n; i++) {
        tryCell(i, 0, visited, bfsQueue, maxStrength);
        tryCell(i, m - 1, visited, bfsQueue, maxStrength);
    }
    for(int i = 1; i < m - 1; i++) {
        tryCell(0, i, visited, bfsQueue, maxStrength);
        tryCell(0, n - 1, visited, bfsQueue, maxStrength);
    }

    // Counter to keep track of how many monkeys our bfs found
    int visitedMonkeys = 0;

    // Do the multi-source bfs
    while(!bfsQueue.empty()) {
        // Pop the current location from the queue
        auto curr = bfsQueue.front(); bfsQueue.pop_front();
        // Increment our counter if we found a monkey
        visitedMonkeys += !grid[curr.first][curr.second];
        // Loop through all 4 directions
        for(int i = 0; i < 4; i++) {
            // dy[i] and dx[i] helps us move to the adjacent cell in direction i
            tryCell(curr.first + dy[i], curr.second + dx[i], visited, bfsQueue, maxStrength);
        }
    }

    // After the bfs is finished, check that all the monkeys have been visited (escaped)
    return visitedMonkeys == totalMonkeys;
}

void solve() {
    // Scan in size of the grid and grid itself
    cin >> n >> m;
    totalMonkeys = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char digit;
            cin >> digit;
            grid[i][j] = digit - '0';
            if(grid[i][j] == 0) totalMonkeys++;
        }
    }

    /*
        We can try looping through every possible machete strength from
        least to greatest. If all our monkeys can escape at the current
        strength, then we can print it out as our minimum answer

        Note: A strength of 9 will always allow all the monkeys to escape
    */
    for(int strength = 1; strength <= 9; strength++) {
        if(checkEscape(strength)) {
            cout << strength << '\n';
            return;
        }
    }
}

int main() {
    // Scan in the number of scenarios and solve for each one
    int testCases;
    cin >> testCases;

    for(int tc = 0; tc < testCases; tc++) solve();

    return 0;
}
