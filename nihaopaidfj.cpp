#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
return (*(int *) b - *(int *) a);
}

int main ()
{
int n, m, data[50], max, i, left, count, set = 0, d[10];
while (scanf("%d%d", &m, &n) && m) {
for (i = 0; i < n; i++)
scanf("%d", data + i);
qsort(data, n, sizeof (int), comp);
left = 0;
count = 0;
for (max = m * n, i = 0; i < n && max > 0; max--) {
if (max == data[i]) {
i++;
if (left == 0)
count++;
else
left--;
}
else
left++;
}
d[set]=count;
set++;}
for(i=0;i<set;i++)
printf("Case %d: %d\n", i+1,d[i]);
return 0;
}
