inputArray = ['a','b','c']

def permutation(inputArray):

	if(len(inputArray) == 1):
		return [inputArray]

	finalList = []	

	for element in inputArray:
		
		remainingElements = [i for i in inputArray if i!=element]
		results = permutation(remainingElements)
		print results
		for i in results:
			finalList.append([element] + i)

	return finalList
permutation(inputArray)
	# print(x)