def sort(nums):
    for i in range(len(nums)-1):
        t=i+1
        while True:
            temp = nums[i]
            count=0
            while t<len(nums):
                if temp>nums[t]:
                    nums[i],nums[t]=nums[t],nums[i]
                    count +=1
                    break
                else:
                    t+=1
            if count==0:
                break
            t+=1
    return nums