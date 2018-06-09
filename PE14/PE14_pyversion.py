def collatz(num):
        seq = 0
        while num != 1:
                if num % 2 == 0:
                        num = num/2
                elif num % 2 == 1:
                        num = (num * 3) + 1
                seq+=1
        return seq


BigNum=0
Larg = 0


if __name__== '__main__':
        
        for i in range(1000000,2,-1):
                ret = collatz(i)
                if(ret > Larg):
                        Larg = ret
                        BigNum = i
        print(BigNum)
