class Solution {
public:
    int singleNumber(vector<int>& nums) {
    
        
            
         int result = 0;
        
        // We use the XOR (^) operator because:
        // 1. a ^ a = 0  (Duplicate numbers cancel each other out)
        // 2. a ^ 0 = a  (The unique number XORed with 0 remains itself)
        // 3. XOR is commutative: the order of numbers doesn't matter.
        for (int num : nums) {
            result ^= num;
        }
        
        return result;
    }
};                                                                                               
 