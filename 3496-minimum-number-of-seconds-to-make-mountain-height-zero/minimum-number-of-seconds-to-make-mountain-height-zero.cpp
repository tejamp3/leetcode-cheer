class Solution {
public:
#define ll long long
    int n ;

    bool is_valid(int mountainHeight, vector<int>& workerTimes,ll mins){

        ll total_ht = 0;
       
       for(int i=0;i<n;i++){

         // quadratic formula
         // h(h+1)/2 * workertime <= mins
         
          ll x = (2LL * mins) / workerTimes[i]; 
          ll height = (sqrt(1 + 4*x) - 1) / 2;
          total_ht += height;
        // total height accumulation like, how much workers did work to reduce the height

          if(total_ht >= mountainHeight) return true;
       }

       return false;
    }


    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        n = workerTimes.size();

        ll ans = 0;
        // max time of the largest mini is the min workerTime * (sum upto mountain height)
        ll l = 1;
        ll r = 1LL * (*min_element(workerTimes.begin(),workerTimes.end())) * 
                 mountainHeight * (mountainHeight + 1) / 2;

        
        while(l <= r){ // binary search on answers(time)

            ll mid = (l+r)>>1;

            if(is_valid(mountainHeight, workerTimes, mid)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
    }
};