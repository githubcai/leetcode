class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ind;
        for(ind = 0; ind < wordList.size(); ++ind){
            if(wordList[ind] == endWord) break;
        }
        if(ind >= wordList.size()) return 0;
        queue<pair<string, int>> que;
        que.push(make_pair(beginWord, 1));
        while(!que.empty()){
            pair<string, int> now = que.front();
            que.pop();
            string first = now.first;
            for(ind = 0; ind < wordList.size(); ++ind){
                if(wordList[ind] != ""){
                    int cnt = 0;
                    for(int i = 0; i < wordList[ind].size(); ++i){
                        if(wordList[ind][i] != first[i]) cnt += 1;
                        if(cnt > 1) break;
                    }
                    if(cnt > 1) continue;
                    if(wordList[ind] == endWord) return now.second + 1;
                    que.push(make_pair(wordList[ind], now.second + 1));
                    wordList[ind] = "";
                }
            }
        }
        return 0;
    }
};
