def subsets(str,s):
	if (len(s)==len("ABC")):
		return

	for i,ii in enumerate(str):
		s.append(ii)
		print (s)
		subsets(str[i+1:],s)
		s.pop()

subsets("ABC",[])

