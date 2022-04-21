void decode_huff(node * root, string s) {
    if (!root) return;
    node* current = root;
    for (char c: s) {
        current = c == '0' ? current->left: current->right;        
        if (current && (!current->right) && (!current->left)) {
            // leaf
            cout << current->data;
            current = root;
        }        
    }
}
