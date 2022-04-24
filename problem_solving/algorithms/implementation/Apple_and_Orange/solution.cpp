void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
    
    int apple_count = 0, orange_count = 0;
    for(int apple: apples) {
        int apple_location = apple + a;
        if(apple_location >= s && apple_location <= t) apple_count ++;
    }
    
    for(int orange: oranges) {
        int orange_location = orange + b;
        if(orange_location >= s && orange_location <= t ) orange_count++;
    }
    
    cout << apple_count << endl << orange_count << endl;
}
