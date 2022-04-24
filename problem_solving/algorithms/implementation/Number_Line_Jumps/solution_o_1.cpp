string kangaroo(int x1, int v1, int x2, int v2) {    
    // O(1) SOLUTION (y*v1 + x1 == y*v2 + x2)
    return (v2 < v1 && (x2-x1)%(v1-v2) == 0) ? "YES": "NO";
}
