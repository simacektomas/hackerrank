def maxSubarray(arr):
    # Write your code here
    subArray = [0] * len(arr)
    subSequence = [0] * len(arr)
    tempArray = subArray[0] = subSequence [0] = arr[0]
    for i in range(1, len(arr)):
        if subSequence[i-1] < 0: 
            subSequence[i] = arr[i] if arr[i] > subSequence[i-1] else subSequence[i-1]       
        else:
            if subSequence[i-1] + arr[i] > subSequence[i-1]:
                subSequence[i] = subSequence[i-1] + arr[i]
            else: 
                subSequence[i] = subSequence[i-1]
        
        tempArray += arr[i]      
        if tempArray < arr[i]: tempArray = arr[i]  
        
        if tempArray < 0:
            tempArray = arr[i]

        subArray[i] = tempArray if tempArray > subArray[i-1] else subArray[i-1]
    
    return (subArray[-1], subSequence[-1])
