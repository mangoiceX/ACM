s1 = "COFFEE"
s2 = "CHICKEN"
T = int(input())
for i in range(0,T):
    n,k = list(map(int, input().split()))
    if n == 2:
        s3 = s2
    if n == 1:
        s3 = s1
    for j in range(3,n+1):
        s3 = s1 + s2
        s1 = s2
        s2 = s3
        if len(s3) > 1e9:
            print("nihao")
            break
    for j in range(k-1,min(k-1+10,len(s3))):
         print(s3[j],end="")
    print()
    s1 = "COFFEE"
    s2 = "CHICKEN"
    s3 = ""
