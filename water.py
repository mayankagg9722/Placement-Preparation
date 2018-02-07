k=6
w=[]
for i in range(1,k+1):
	a=[0]*i
	w.append(a)

def fill_water(w,k,i,p):

	if(k>1):
		w[i][p]=1
		fill_water(w,((k-1.0)/2.0),i+1,p)
		fill_water(w,((k-1.0)/2.0),i+1,p+1)
	else:
		w[i][p]=w[i][p]+k
		rem=w[i][p]-1
		if(w[i][p]>1):
			w[i][p]=1
			fill_water(w,(rem/2.0),i+1,p)
			fill_water(w,(rem/2.0),i+1,p+1)


fill_water(w,k,0,0)
print(w)