class Solution {
public:

    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> edges;
        for(char c : words[0]){
            if(edges.find(c) == edges.end()){
                edges[c] = {};
            }
        }
        for(int i = 1; i < words.size(); i++){
            string w1 = words[i-1];
            string w2 = words[i];
            for(char c : w2){
                if(edges.find(c) == edges.end()){
                    edges[c] = {};
                }
            }
            bool prefix = true;
            for(int j = 0; j < min(w1.size(), w2.size()); j++){
                if(w1[j] != w2[j]){
                    edges[w2[j]].push_back(w1[j]);
                    prefix = false;
                    break;
                }
            }
            if(prefix && w1.size() > w2.size()){
                return "";
            }
        }
        unordered_map<char, int> indegree;
        string out;
        queue<char> q;
        for(auto [key, val] : edges){
            for(char c: val){
                indegree[c]++;
            }
        }

        for(auto [key, val] : edges){
            if(indegree[key] == 0){
                q.push(key);
            }
        }
    
        while (!q.empty()) {
            char top = q.front();
            q.pop();
            out = top + out;
            for (char next : edges[top]) {
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }
        if(!q.empty() || out.size() < edges.size()){
            return "";
        }
        return out;
    }
};
