line = input().split()
x = int(line[0])
y = int(line[1])
counter = 0
while x>0 and y>0:
    if x%y == 0 or y%x == 0:
        if x ==1 or y == 1:
            counter += int(max(x,y)/min(x,y) - 1)
            print(counter)
            break
        else:
            print("impossible")
            break
    else:
        if x>y:
            counter += int(x / y)
            x = x%y
        elif y>x:
            counter += int(y / x)
            y = y % x
#
# def divider(x, y, c):
#     if x == y and x != 1:
#         return -1
#     if x % y == 0:
#         c += int(x / y - 1)
#         return c
#     else:
#         c += int(x / y)
#         divider(y, x % y, c)
#
# counter=0
# if y > x:
#     print(divider(y, x, int(counter) ) )
# else:
#     print(divider(x, y, int(counter) ) )
#     print(counter)
# counter=0
# while(x>0 and y>0):
#     if x == y and x!=1:
#         print("impossible")
#         break
#     if x%y == 0:
#         counter += int(x/y -1)
#     else:
#         counter += int(x/y)
#         x = x % y
#         temp=x
#         x=y
#         y=temp
# print(counter)
#
# while(x!=y and x>0 and y>0):
#
#     if x%y == 0 or y%x==0:
#        print("impossible")
#        break
#     if x%y ==1 or y%x == 1:
#         if x>y:
#             counter+= int(x/y)
#             x=1
#         elif y>x:
#             counter += int(y / x)
#             y = 1
#     if x>y:
#         x=x-y
#     elif y>x:
#         y=y-x
#     counter+=1
#     if x==1 or y==1:
#        counter+=abs(x-y)
#        print(counter)
#        break
