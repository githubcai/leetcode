/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
    int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a % b);
    }
public:
    int maxPoints(vector<Point>& points) {
        int size = points.size(), ret = 0;
        map<pair<int, int>, int> res;
        if(size <= 2) return size;
        for(int i = 0; i < size; ++i){
            res.clear();
            int duplicate = 1;
            for(int j = i + 1; j < size; ++j){
                if(points[i].x == points[j].x && points[i].y == points[j].y){
                    duplicate += 1;
                    continue;
                }
                int dy = points[i].y - points[j].y;
                int dx = points[i].x - points[j].x;
                int temp = gcd(dx, dy);
                res[make_pair<int, int>(dx / temp, dy / temp)] += 1;
            }
            if(duplicate > ret) ret = duplicate;
            for(auto i : res){
                if(duplicate + i.second > ret){
                    ret = duplicate + i.second;
                }
            }
        }
        return ret;
    }
};
