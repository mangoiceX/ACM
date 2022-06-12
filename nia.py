b = input("please enter a binary number:")
d=0;weight=2**(len(b)-1);
flag=0;
for j in range (0,len(b)):
    if b[j] != '0 'and b[j] != '1':
        print ("输入不合法，请重新输入。");
        flag=1;
        break;
if flag == 0:
    for i in range (0,len(b)):
        if b[i] == '1':
            d = d + weight;
        weight=weight//2;
    print(d)
