def printRepeating(arr, size):
     
    print("The repeating elements are: ")
     
    for i in range(0, size):
        print("index:",i)
        print("index element:",arr[i])
        print ("final element:",arr[abs(arr[i])])
        if arr[abs(arr[i])] >= 0:
            arr[abs(arr[i])] = -arr[abs(arr[i])]
        else: 
            print ("Ans:",abs(arr[i]), end = " ")
             
arr = [1, 2, 3, 1, 3, 6, 6]
arr_size = len(arr)
 
printRepeating(arr, arr_size)