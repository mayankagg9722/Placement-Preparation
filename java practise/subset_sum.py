def subset_sum(a,sumn,i,l):
    if(i==l):
        print ("sum",sumn)
        return

    print ("ele",a[i])
    subset_sum(a,sumn+a[i],i+1,l)
    print ("prevsum",sumn)
    print ("prevelem",a[i])
    subset_sum(a,sumn,i+1,l)


a=[1,2,3]
subset_sum(a,0,0,len(a))
