class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        //simple question of binary search, also the x coordinate has no signifance here
        double low = 0;
        double high = 2*1e9; //upper bound of all ys
        double mid;
        double ans = -1;
        double toparea;
        double bottomarea;
        double y;
        double length;

        while (low<=high){
            mid = low + (high-low)/2;
            //now we check if mid satisfies the condition
            double toparea = 0;
            double bottomarea = 0;
            for (auto &square : squares){
                y = square[1];
                length = square[2];
                if (y>=mid){ //square lies above mid
                    toparea += length*length;
                }
                else if ((y+length)<=mid){ //square lies below mid
                    bottomarea += length*length;
                }
                else{
                    //mid intersects the square
                    //height of bottom half would be (mid-y) top height would be (y+length-mid)
                    bottomarea += length*(mid-y);
                    toparea += length*(y+length-mid);
                }
            }
            if (bottomarea>=toparea){
                ans = mid;
                high = mid - 0.000001;
                //we look for a better answer below
            }
            else low = mid+0.000001;
        }
        return ans;

    }
};