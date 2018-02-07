def finleftString(mystr,ii):
	leftString=[]
	for k in mystr:
		if k!=mystr[ii]:
			leftString.append(k)
	return leftString
def anagram(mystr):
	
	if(len(mystr)==1):
		return [mystr]

	finalList=[]


	for ii,i in enumerate(mystr):
		leftString=finleftString(mystr,ii)
		newStr=anagram(leftString)
		for j in newStr:
			finalList.append([i]+j)
	return finalList

finalList=anagram(list("abc"));

for i in finalList:
	print i