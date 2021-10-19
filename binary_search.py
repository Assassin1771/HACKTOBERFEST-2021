arr=[1,5,2,6,58,3,56,856,4,32,54,2,246,5,2,5,63,53,2]

low=0
high=int(len(arr)-1)

#print(len(arr))
#print(mid)

x=int(input("Which element do you need to find?"))
print(high)
while(low<=high):
    mid=(low+high)//2
    if(arr[mid]==x):
        print("Element found at: " +str(mid))
        break
    elif(arr[mid]>x):
        low=0
        high=mid-1
    elif(arr[mid<x]):
        low=mid+1
    #mid=(low+high)/2