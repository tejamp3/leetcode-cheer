class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        ans=[]
        hmap = {}
        for i in range(len(nums)):
            hmap[nums[i]]=i
        for i in range (len(nums)):
            find =(target - nums[i])
            if find in hmap and hmap[find] != i:
                ans.append(i)
                ans.append(hmap[find])
                break
            
            
            
        
        return ans