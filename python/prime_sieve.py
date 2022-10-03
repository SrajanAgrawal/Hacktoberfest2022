
def prime_sieve(n):
    prime=primes=[]
    for i in range(n+1):
        prime.append(i)
    prime[0]=0
    prime[1]=0
    p=2
    while(p*p<=n):
        if p!=0:
            for i in range(p*2,n+1,p):
                prime[i]=0
        p+=1

    for k in range(2,n+1):
        if prime[k]!=0:
            primes.append(k)
            print(k,end=" ")
    print()
    print(primes)
#__main__(): 
n=int(input())
prime_sieve(n)