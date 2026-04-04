class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        
        if(dead.count("0000")) return -1;

        queue<string> q;
        q.push("0000");

        unordered_set<string> visited;
        visited.insert("0000");

        int steps = 0;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                string curr = q.front();
                q.pop();

                if(curr == target) return steps;

                for(int i = 0; i < 4; i++){
                    string up = curr;
                    string down = curr;

                    // rotate up
                    up[i] = (curr[i] == '9') ? '0' : curr[i] + 1;

                    // rotate down
                    down[i] = (curr[i] == '0') ? '9' : curr[i] - 1;

                    if(!dead.count(up) && !visited.count(up)){
                        q.push(up);
                        visited.insert(up);
                    }

                    if(!dead.count(down) && !visited.count(down)){
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};