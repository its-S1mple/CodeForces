def valid_string(string):
    n=len(string)
    
    if(n>10):
        print(f"{string[0]}{n-2}{string[n-1]}")
    else:
        print(f"{string}")
        
n=int(input())
l1=[]

for i in range(n):
    l1.append(input())
    
for i in range(n):
    valid_string(l1[i])

