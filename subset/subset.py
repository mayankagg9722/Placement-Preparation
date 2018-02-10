def subsetprint(n,l):
	if(len(l)==len([1,2,3])):
		return

	for k,kk in enumerate(n):
		l.append(kk)
		print(l)
		subsetprint(n[k+1:],l)
		l.pop()

n=[1,2,3]
l=[]
subsetprint(n,l)