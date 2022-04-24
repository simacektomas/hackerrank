string kangaroo(int x1, int v1, int x2, int v2) {    
    int * higher = x1 > x2 ? &x1: &x2;
    int * lower = x1 > x2 ? &x2: &x1;
    
    while(*lower < *higher) {
        x1 += v1;
        x2 += v2;
    } 
    return *lower == *higher ? "YES": "NO";
}
