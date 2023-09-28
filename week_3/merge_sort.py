
from random import shuffle



def main():
    l=list(range(0,10))
    shuffle(l)
    sorted_l = merge_sort(l)
    print(sorted_l)



    
def merge_sort(l):
    if len(l) == 1:
        return l
    else:
        left = merge_sort(half(l,0))
        right = merge_sort(half(l,1))
        return merge(left,right)

def half(l,part):
    # works :)
    length = len(l)
    if part == 0:
        return l[:length//2]
    else:
        return l[length//2:]

def merge(left,right):
    # should return lenth of final list
    l=[]
    rl,ll = len(right),len(left)
    for lefti in range(ll):
        for righti in range(rl):
            if left[lefti] < right[righti]:
                l.append(left[lefti])
                break
            l.append(right[righti])

    return l




if __name__ =="__main__":
    main()