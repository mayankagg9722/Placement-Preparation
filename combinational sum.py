#COMBINATION SUM

import sys

# arrayElements = input("Enter arrayElements: ").split()
# arrayElements = [int(i) for i in arrayElements]

# finalSum = int(input("Enter finalSum: "))

arrayElements = [2,4,6,8]
finalSum = 8

def combinationSum(tempArray):

	if(sum(tempArray) > finalSum):
			return

	if(sum(tempArray) == finalSum):
			print(tempArray)

	if(len(tempArray) == len(arrayElements)):
			return

	for element in arrayElements:

		tempArray.append(element)
		combinationSum(tempArray)
		tempArray.pop()

combinationSum([])