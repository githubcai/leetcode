class Solution {
    void dfs(unordered_map<string, vector<string>> &ref, vector<string> &resList, int index, int dist, const string &endWord, vector<vector<string>> &ret){
        if(index == dist){
            if(resList[index] == endWord) ret.push_back(resList);
            return;
        }
        string temp = resList[index];
        for(int i = 0; i < ref[temp].size(); ++i){
            resList[index + 1] = ref[temp][i];
            dfs(ref, resList, index + 1, dist, endWord, ret);
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int ind, dist = 0;
        vector<vector<string>> ret;
        int vis[wordList.size()];
        for(int i = 0; i < wordList.size(); ++i) vis[i] = INT_MAX;
        for(ind = 0; ind < wordList.size(); ++ind){
            if(wordList[ind] == beginWord) vis[ind] = 1;
            if(wordList[ind] == endWord) break;
        }
        if(ind >= wordList.size()) return ret;
        queue<pair<string, int>> que;
        que.push(make_pair(beginWord, 1));
        unordered_map<string, vector<string>> ref;
        bool flag = false;
        while(!que.empty() && !flag){
            int size = que.size();
            for(int i = 0; i < size; ++i){
                pair<string, int> now = que.front();
                que.pop();
                if(ref.find(now.first) == ref.end()) ref[now.first] = vector<string>();
                for(ind = 0; ind < wordList.size(); ++ind){
                    if(vis[ind] >= now.second + 1){
                        int cnt = 0;
                        for(int i = 0; i < wordList[ind].size(); ++i){
                            if(wordList[ind][i] != now.first[i]) cnt += 1;
                            if(cnt > 1) break;
                        }
                        if(cnt > 1) continue;
                        ref[now.first].push_back(wordList[ind]);
                        if(wordList[ind] == endWord){
                            dist = now.second + 1;
                            flag = true;
                            break;
                        }
                        if(vis[ind] == INT_MAX)que.push(make_pair(wordList[ind], now.second + 1));
                        vis[ind] = now.second + 1;
                    }
                }
            }
        }
        if(flag){
            vector<string> resList(dist);
            resList[0] = beginWord;
            dfs(ref, resList, 0, dist - 1, endWord, ret);
        }
        return ret;
    }
};
