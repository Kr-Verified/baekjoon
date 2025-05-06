def merge_sort(a, p, r):
    if (p < r):
        q = (p + r) // 2
        merge_sort(a, p, q)
        merge_sort(a, q + 1, r)
        merge(a, p, q, r)
def merge(a, p, q, r):
    i, j, tmp= p, q+1, []
    while i <= q and j <= r:
        if a[i] <= a[j]:
            tmp.append(a[i])
            i+=1
        else:
            tmp.append(a[j])
            j+=1
    while (i <= q):
        tmp.append(a[i])
        i+=1
    while (j <= r):
        tmp.append(a[j])
        j+=1
    i, t = p, 0
    while (i <= r):
        a[i] = tmp[t]
        global k, cnt
        if cnt==k-1:
            print(a[i])
        cnt+=1
        i+=1
        t+=1 

cnt = 0
n, k = map(int, input().split())
a = list(map(int, input().split()))
merge_sort(a, 0, len(a)-1)
if cnt<k:
    print(-1)