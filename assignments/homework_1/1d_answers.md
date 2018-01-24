1)n = -3  //a[1] = -3

2)n = 2   //only a[1] and a[4] cause n to be incremented

3)

  int n;
  for (int i=0; i<6; i++) {
    a[i] = a[i]+1;
  }
  n = a[2];
n = 
4)

  int n = 0;
  for (int i=0; i<5; i++) {
    for (int j=i+1; j<6; j++) {
      if (a[i] == a[j]) {
         n++;
      }
    }
  }
n = 
5)

n = a[3]+1;
n = 
6)

n = a[3+1];
n = 
7)

n = a[3+1]+1;
n = 
8)

n = a[3+1]+a[1];
n = 
9)

What does the array look like after the following:

a[3+1] = a[3]+1;
a = 
10)

a[3] = a[3]+a[1+3]*2;
a = 
