class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        if(size == 0) return -1;
        for(int i = 0; i < size; ++i) gas[i] -= cost[i];
        if(size == 1){
            if(gas[0] < 0) return -1;
            return 0;
        }
        int first = 0, last = size - 1;
        while(first < last){
            if(gas[first] >= 0){
                first += 1;
                gas[first] += gas[first - 1];
            }else{
                while(first < last && gas[first] < 0){
                    gas[first] += gas[last];
                    last -= 1;
                }
                if(gas[first] < 0) return -1;
                if(first < last){
                    first += 1;
                    gas[first] += gas[first - 1];
                }
            }
        }
        if(gas[first] < 0) return -1;
        return (last + 1) % size;
    }
};
