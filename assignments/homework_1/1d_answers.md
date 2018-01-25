1) n = -3  
//a[1] = -3

2) n = 2   
//only a[1] and a[4] cause n to be incremented

3) n = 7
//the initial value of a[2], 6, was incremented by 1 and reassigned to a[2]

4) n = 2
//n will increment when a number is repeated later in the array, so values -3 and 6 both add 1 to n

5) n = 1
//a[3] = 0, 0 + 1 = 1

6) n = -3
//a[4] = -3

7) n = -2
//a[4] = -3, -3 + 1 = -2

8) n = 22
//a[4] = -3, a[1] = 25, -3 + 25 = 22

9) a = {25, -3, 6, 0, 1, 6};
//a[3] = 0, 0 + 1 = 1, this value gets reassigned to a[4]

10) a = {25, -3, 6, -6, -3, 6}
//a[3] = 0, a[4] = -3, 0 + -3 * 2 = -6, which gets reassigned to a[3]


