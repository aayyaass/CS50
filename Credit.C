#include <cs50.h>
#include <stdio.h>

unsigned long long int pten(unsigned int pwr);
unsigned long long int lngth(unsigned long long dgt);
unsigned int bgnWITH (int ndgts, unsigned long long num);

int main(void){
//PT 1 OF TAKE DIG
    unsigned long long int ccn = get_long_long("Credit Card Number: ");
    unsigned long long int z;
    int store, store2 = 0;
    int i;
    for(i = 1; i<lngth(ccn);i+=2){
        z = (ccn % pten(i+1)) - (ccn % pten(i));
        z = z / pten(i);
        z = z * 2;
            if(z > 9){
            z = 1 + (z % 10);}
            //printf("%llu\n",z);
        store = store + z;
}
    //printf("%i\n",store);
//PT 2 OF TAKE DIG
    for(i= 2; i<lngth(ccn);i+=2){
        z = (ccn % pten(i+1)) - (ccn % pten(i));
        z = z / pten(i);
        //printf("%llu\n",z);
        store2 = store2 + z;
    }
    store2 = store2 + (ccn % 10);
    //printf("%i\n",store2);

//PT 3 ADD AND VERIFY END NUM
    int sum = store + store2;
    if (sum % 10 == 0){
        if (bgnWITH(2,ccn) >=51 && bgnWITH(2,ccn) <= 55){
            printf("MASTERCARD\n");
        } else if (bgnWITH(2,ccn) == 34 || bgnWITH(2,ccn) == 37){
            printf("AMEX\n");
        } else if (bgnWITH(1,ccn) == 4){
            printf("VISA\n");
        }
        else{
            printf("INVALID\n");
        }
    }
    else {
        printf("INVALID\n");
    }
    return 0;
}

// IMPLEMENTED CODES
unsigned long long int pten(unsigned int pwr){
    unsigned long long x = 1;
    for (int i=0; i<pwr;i++){
        x = x * 10; }
    return x;
}
unsigned long long int lngth (unsigned long long dgts){
    int cnt = 0;
    while (dgts > 0 ){
        dgts = dgts/10;
        cnt ++;
    }
    return cnt;
}
unsigned int bgnWITH (int ndgts, unsigned long long num){
    int f2d;
    f2d = (num - (num % pten(lngth(num)-ndgts)))/pten(lngth(num)-ndgts);
    return f2d;
}

// 123
// 100 (123%1000) - (123%100)    100/100
// 20  (123 %100) - (123%10)      20/10
// 3 - 123 %10                     3/1
