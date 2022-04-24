int calculateCost(vector<vector<int>> o, vector<vector<int>> c) {
    int cost = 0;
    for(int x = 0; x < c.size(); x++) {
        for(int y = 0; y < c.size(); y++) {
            cost += abs(c[x][y] - o[x][y]);
        }
    }
    return cost;
}



int formingMagicSquare(vector<vector<int>> s) {
    // the sum has to be 15 -, | , / , \
    // set the center to 5 if not
    int minCost = INT32_MAX;
    vector<vector<int>> original(s);
    if (s[1][1] != 5) {
        s[1][1] = 5;
    }
    
    // (1,9) , (3,7) cannot be on the diagonal -> 4 * 2 possible solutions
    int row = 0, col = 0;
    
    vector<int> corners {4,6,2,8};
    for(int i = 0; i < corners.size(); i++) {
        // set the first diagonal      
        s[0][0] = corners[i];
        s[2][2] = 10 - corners[i];
        
        s[0][2] = corners[(i + 2) % corners.size()];
        s[2][0] = 10 - corners[(i + 2) % corners.size()];
        
        s[0][1] = 15 - s[0][0] - s[0][2];
        s[1][0] = 15 - s[0][0] - s[2][0];
        s[1][2] = 15 - s[0][2] - s[2][2];
        s[2][1] = 15 - s[2][0] - s[2][2];
        
        int cost = calculateCost(original, s);
        minCost = cost < minCost ? cost: minCost;
        
        s[0][2] = 10 - corners[(i + 2) % corners.size()];
        s[2][0] = corners[(i + 2) % corners.size()];
        
        s[0][1] = 15 - s[0][0] - s[0][2];
        s[1][0] = 15 - s[0][0] - s[2][0];
        s[1][2] = 15 - s[0][2] - s[2][2];
        s[2][1] = 15 - s[2][0] - s[2][2];
        
        cost = calculateCost(original, s);
        minCost = cost < minCost ? cost: minCost;
    }
    
    return minCost;
}
