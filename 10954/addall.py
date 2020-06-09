import sys

while True:
    line=sys.stdin.readline()
    line=sys.stdin.readline()
    lineint=[int(i) for i in line.rstrip().split(" ")]
    curr_sum=lineint[0]
    cost=0
    for x in range(1, len(lineint)):
        curr_sum+=lineint[x]
        cost+=curr_sum
    print(cost)
    print(curr_sum)
    print(sorted(lineint))
    break
    
