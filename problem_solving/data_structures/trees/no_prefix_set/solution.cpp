int letter2Index (char letter) { return (int) letter - (int) 'a';}

struct Node {
    bool word = false;
    int childs = 0;
    Node * children[10];
};

void noPrefix(vector<string> words) {
    Node * root = new Node();
    Node * current = root;
        
    for(const string & word: words) {
        for(const char & c: word) {
            
            if(!current->children[letter2Index(c)]) {
                current->childs++;
                current->children[letter2Index(c)] = new Node();
            }
            current = current->children[letter2Index(c)];
            if (current->word) {
                   cout << "BAD SET" << endl;
                   cout << word << endl;
                   return;
            } 
        }
        if(!current->childs) {
            cout << "BAD SET" << endl;
            cout << word << endl;
            return;
        }
        current->word = true;
        current = root;
    }
    cout << "GOOD SET" << endl;    
}
