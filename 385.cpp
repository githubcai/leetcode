/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        NestedInteger ret;
        if(s[0] != '['){
            stringstream ss;
            ss << s;
            int temp;
            ss >> temp;
            ret.setInteger(temp);
        }else{
            int size = s.size(), cnt = 0;
            if(size > 2){
                vector<string> vec;
                string temp;
                for(int i = 1; i < size; ++i){
                    if(cnt == 0 && (s[i] == ',' || s[i] == ']')){
                        vec.push_back(temp);
                        temp = "";
                    }else{
                        if(s[i] == '['){
                            cnt += 1;
                        }else if(s[i] == ']'){
                            cnt -= 1;
                        }
                        temp += string(1, s[i]);
                    }
                }
                for(int i = 0; i < vec.size(); ++i) ret.add(deserialize(vec[i]));
            }
        }
        return ret;
    }
};
