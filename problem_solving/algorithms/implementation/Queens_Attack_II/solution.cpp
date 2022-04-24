size_t key(int i,int j) {
    return (size_t) i << 32 | (unsigned int) j;
}

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int cl, cr, rt, rd;
    cl = c_q - 1;
    cr = n - c_q;
    rt = n - r_q;
    rd = r_q - 1;
    
    int total = rt + cr + rd + cl + min(cl, rt) + min(cr, rt) + min(cr, rd) + min(cl, rd);
    
    unordered_map<size_t, int> m;
    for(vector<int> obstacle: obstacles) {
        m[key(obstacle[0], obstacle[1])] = 1;
    }
    
    int blocked = 0;
    for(int i = c_q - 1; i > 0; i--) {
        // queen to left
        if (m.find(key(r_q, i)) != m .end()) {
            blocked = i;
            break;
        }
    }
    total -= blocked;
    blocked = 0;
    
    for(int i = r_q + 1; i <= n; i++) {
        // queen to top
        if (m.find(key(i, c_q)) != m .end()) {
            blocked = n - i + 1;
            break;
        }
    }
    cout << blocked << endl;
    total -= blocked;
    blocked = 0;
    for(int i = c_q + 1; i <= n; i++) {
        // queen to right
        if (m.find(key(r_q, i)) != m .end()) {
            blocked = n - i + 1;
            break;
        }
    }
    total -= blocked;
    blocked = 0;
    
    for(int i = r_q - 1; i > 0; i--) {
        // queen to bottom
        if (m.find(key(i, c_q)) != m .end()) {
            blocked = i;
            break;
        }
    }
    total -= blocked;
    blocked = 0;
    
    for(int i = 1; i < min(rt, cl); i++) {
        // top left diagonal
        if (m.find(key(r_q + i, c_q - i)) != m.end()) {
            blocked = min(rt, cl) - i + 1;
            break;
        }
    }
    total -= blocked;
    blocked = 0;
    
    for(int i = 1; i < min(rt, cr); i++) {
        // top rigth diagonal
        if (m.find(key(r_q + i, c_q + i)) != m.end()) {
            blocked = min(rt, cr) - i + 1;
            break;
        }
    }
    total -= blocked;
    blocked = 0;
    
    for(int i = 1; i < min(rd, cr); i++) {
        // bottom left diagonal
        if (m.find(key(r_q - i, c_q + i)) != m.end()) {
            blocked = min(rd, cr) - i + 1;
            break;
        }
    }
    total -= blocked;
    blocked = 0;
    
    for(int i = 1; i < min(rd, cl); i++) {
        // bottom left diagonal
        if (m.find(key(r_q - i, c_q - i)) != m.end()) {
            blocked = min(rd, cl) - i + 1;
            break;
        }
    }
    total -= blocked;
    blocked = 0;
    return total;
}
