def permute(mystr,i,j):
	if(i==j):
		print(''.join(mystr))
		return

	for k in range(i,j+1):
		mystr[k] , mystr[j] = mystr[j] , mystr[k]
		print(k)
		print(mystr)
		permute(mystr,i+1,j)
		mystr[k] , mystr[j] = mystr[j] , mystr[k]

permute(list("ABC"),0,2)