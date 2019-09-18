class Solution {
public:
    int hammingDistance(int x, int y) {
       int D=0;
        int tmp= x ^ y;
    while (tmp!=0) {
        D+= (tmp & 1);
        tmp = tmp>>1;
    }
        return D;
    }

};
