class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int cnt = 0;
        while(J.empty() == false) {
            char tmp = J.back();
            for(auto itr = S.begin(); itr != S.end(); ++itr)
                if(J.back() == *itr)
                    cnt++;
            J.pop_back();
        }
        return cnt;
    }
};
