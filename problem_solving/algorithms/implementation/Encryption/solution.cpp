string encryption(string s) {
    
    // wipe out spaces => l
    string l, r;
    for(char c: s) if(c != ' ') l += c;
    
    float sq = sqrt(l.size());
    int rows = floor(sq);
    int cols = ceil(sq);
    // r = sqrt(len(l))  floor(r) ceil(r)
    if (cols * rows < l.size()) rows++;
    
    vector<vector<char> *> matrix(rows);
    for(int i = 0; i < rows; i++)
        matrix[i] = new vector<char>(cols);
    
    for(int x = 0; x < rows; x++) 
        for(int y = 0; y < cols; y++) {
            if (y + (x * cols) >= l.size()) break;
            (*matrix[x])[y] = l[y + (x * cols)];
        }
    
    for(int y = 0; y < cols; y++) {
        for(int x = 0; x < rows; x++) {
            if (y + (x * cols) >= l.size()) break;
            r += (*matrix[x])[y];
        }
        r += " ";
    }
    return r;
}
