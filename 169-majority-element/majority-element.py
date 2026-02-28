class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        ans = 0
        n = len(nums)
        hmap={}
        for i in range(len(nums)):
           hmap[nums[i]] =hmap.get(nums[i], 0) + 1
        for key, value in hmap.items():
            if value > n//2:
                return key
        return -1
        

            
        
        