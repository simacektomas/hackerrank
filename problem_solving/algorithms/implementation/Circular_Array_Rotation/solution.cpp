vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {
    vector<int> b(a), r;
    for(int i = k; i < a.size() + k; i++) {
        b[i % a.size()] = a[(i-k) % a.size()];
    }
    
    for(int query: queries)
        r.push_back(b[query]);
    return r;
}
