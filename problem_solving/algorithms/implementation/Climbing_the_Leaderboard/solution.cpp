vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    unordered_map<int, int> m;
    vector<int> result;
    
    int ranks = 0;
    for(int rank: ranked) {
        if (m.find(rank) == m.end()) {
            m[rank] = 1;
            ranks++;
        }                
    }

    int current_rank = ranked.size() - 1;
    int prev_rank = 0; 
    for(int play: player) {
        while(play >= ranked[current_rank] && current_rank >= 0) {
            if (ranked[current_rank] != prev_rank) ranks--;
            prev_rank = ranked[current_rank];
            current_rank--;
        }
        if(current_rank == - 1 ) result.push_back(1);
        else result.push_back(ranks + 1);
    }
    return result;
}
