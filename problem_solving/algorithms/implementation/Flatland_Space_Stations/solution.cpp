// Complete the flatlandSpaceStations function below.
int flatlandSpaceStations(int n, vector<int> c) {
    
    sort(c.begin(), c.end()); // O(n*log(n))
    
    int maxDistance = INT32_MIN;
    int distance = 0;

    if (c[0] > maxDistance) maxDistance = c[0];

    for(int i = 1; i < c.size(); i++) { // O(n)
        distance = floor((c[i] - c[i-1])/2); 
        if (distance > maxDistance) maxDistance = distance;
    }
    
    if (n-1  - c[c.size()-1] > maxDistance) maxDistance = n-1  - c[c.size()-1];

    return maxDistance;
}
