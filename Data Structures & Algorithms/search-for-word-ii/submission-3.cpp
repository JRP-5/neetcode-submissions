class Node {
public:
    bool end;
    vector<Node*> children;
    Node() {
        end = false;
        children = vector<Node*>(26, nullptr);
    }   
};
class Solution {
public:
    void insert(string word, Node* head){
        for(char c: word){
            if(c-'a'<0 || c-'a'>25){
                cout << c << endl;
                continue;
            }
            if(!head->children[c-'a']){
                head->children[c-'a'] = new Node();
            }
            head = head->children[c-'a'];
        }
        head->end = true;
    }
    void getWords(vector<vector<char>>& board, int x, int y, Node* start, vector<vector<bool>>& seen, string soFar, unordered_set<string>& ans){
        seen[x][y] = true;
        soFar += board[x][y];
        if(start->end){
            // cout << "ADD\n";
            ans.insert(soFar);
        }
        // cout << x << " " << y <<  " " << soFar << endl;
        if(x>0 && !seen[x-1][y] && start->children[board[x-1][y] - 'a']){
            getWords(board, x-1, y, start->children[board[x-1][y] - 'a'], seen, soFar, ans);
        }
        if(y>0 && !seen[x][y-1] && start->children[board[x][y-1] - 'a']) {
            getWords(board, x, y-1, start->children[board[x][y-1] - 'a'], seen, soFar, ans);
        }
        if(x<board.size()-1 && !seen[x+1][y] && start->children[board[x+1][y] - 'a']) {
            getWords(board, x+1, y, start->children[board[x+1][y] - 'a'], seen, soFar, ans);
        }
        if(y<board[0].size()-1 && !seen[x][y+1] && start->children[board[x][y+1] - 'a']) {
            getWords(board, x, y+1, start->children[board[x][y+1] - 'a'], seen, soFar, ans);
        }
        seen[x][y] = false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* head = new Node();
        for(string word : words){
            insert(word, head);
        }
        unordered_set<string> ans;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                vector<vector<bool>> seen(board.size(), vector<bool>(board[0].size(), false));
                if(head->children[board[i][j] - 'a']){
                    getWords(board, i, j, head->children[board[i][j] - 'a'], seen, "", ans); 
                }
            }
        }
        vector<string> out;
        out.insert(out.end(), ans.begin(), ans.end());
        return out;
    }

};
