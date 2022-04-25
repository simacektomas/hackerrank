string organizingContainers(vector<vector<int>> container) {
    multiset<int> ballonTypeSum; 
    multiset<int> containerSum; 
    
    for (vector<int> & c: container) {
        // calculate sums for each container;
        int sum = 0;
        for(int i: c) sum += i;
        containerSum.insert(sum);
    }
    
    for (int i = 0; i < container.size(); i++) {
        // calculate sums for each container;
        int sum = 0;
        for(int y = 0; y < container.size(); y++) sum += container[y][i];
        ballonTypeSum.insert(sum);
    }
    
    //sort(ballonTypeSum.begin(), ballonTypeSum.end());
    //sort(containerSum.begin(), containerSum.end());
    
    if(ballonTypeSum != containerSum) return "Impossible";
    return "Possible";
}
