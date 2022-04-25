string organizingContainers(vector<vector<int>> container) {
    vector<int> ballonTypeSum; 
    vector<int> containerSum; 
    
    for (vector<int> & c: container) {
        // calculate sums for each container;
        int sum = 0;
        for(int i: c) sum += i;
        containerSum.insert(lower_bound(containerSum.begin(), containerSum.end(), sum), sum);
    }
    
    for (int i = 0; i < container.size(); i++) {
        // calculate sums for each container;
        int sum = 0;
        for(int y = 0; y < container.size(); y++) sum += container[y][i];
        ballonTypeSum.insert(lower_bound(ballonTypeSum.begin(), ballonTypeSum.end(), sum), sum);
    }
    
    //sort(ballonTypeSum.begin(), ballonTypeSum.end());
    //sort(containerSum.begin(), containerSum.end());
    
    for(int i = 0; i < container.size(); i++)
        if(ballonTypeSum[i] != containerSum[i]) return "Impossible";
    return "Possible";
}
