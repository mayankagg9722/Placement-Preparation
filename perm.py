def permut(s,i,j):
	if(i==j):
		print s
		return
	for k in range(i,j+1):
		s[k],s[j]=s[j],s[k]
		permut(s,i+1,j)
		s[k],s[j]=s[j],s[k]	

s='abc'
size=len(s)
permut(list(s),0,size-1)