string biggerIsGreater(string w) {
    int suffixStarts = 0;
    for(int i = 1; i < w.size(); i++) if(w[i] > w[i-1]) suffixStarts = i;
    if(suffixStarts == 0) return "no answer";
    
    int swapIndex, pivot = suffixStarts - 1;
    for(int i = w.size()-1; i >= suffixStarts; i--) {
        if (w[i] > w[pivot]) {
            swapIndex = i;
            break;
        }
    }
    
    char tmp = w[pivot];
    w[pivot] = w[swapIndex];
    w[swapIndex] = tmp;
    
    for(int l = suffixStarts, r = w.size() - 1; l < r; l++, r-- ) {
        char tmp = w[l];
        w[l] = w[r];
        w[r] = tmp;
    }
    
    return w;
}
