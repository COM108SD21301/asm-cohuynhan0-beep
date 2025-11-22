#include <stdio.h> 
#include <math.h>
#include <stdlib.h>

int main() {
    int luaChon;
    
    do {
        printf("\nChao mung ban den voi ASM cua toi");
        printf("\nNhap 1: Lua chon chuc nang So nguyen");
        printf("\nNhap 2: Lua chon chuc nang tim UCLN va BCNN");
        printf("\nNhap 3: Lua chon chuc nang Tinh tien quan Karaoke");
        printf("\nNhap 4: Lua chon chuc nang Tinh tien dien");
        printf("\nNhap 0: Thoat chuong trinh");
        printf("\nMoi ban nhap lua chon: ");
        scanf("%d", &luaChon);
        
        switch(luaChon) {
           case 1:{
    printf("Ban chon CN1\n");
    float x;
    printf("Moi ban nhap so x: ");
    scanf("%f", &x);

    // Kiểm tra số nguyên
    if (x == (int)x) {
        int n = (int)x;  
        printf("%d la so nguyen\n", n);

        // Kiểm tra số chính phương
        int r = sqrt(n);
        if (r*r == n)
            printf("%d la so chinh phuong\n", n);
        else
            printf("%d khong phai so chinh phuong\n", n);

        // --- Kiểm tra số nguyên tố ---
        if (n < 2) {
            printf("%d khong phai so nguyen to\n", n);
        } else {
            int isPrime = 1;
            for (int i = 2; i <= sqrt(n); i++) {
                if (n % i == 0) {
                    isPrime = 0;
                    break;
                }
            }
            if (isPrime)
                printf("%d la so nguyen to\n", n);
            else
                printf("%d khong phai so nguyen to\n", n);
        }
        // ------------------------------

    } else {
        printf("%.2f la so thuc\n", x);
    }
    break;
}


            case 2: {
                printf("Ban chon CN2\n");
                break;
            }
            case 3: {
                printf("Ban chon CN3\n");
                break;
            }
            case 4: {
                printf("Ban chon CN4\n");
                break;
            }
            case 0: {
                printf("Thoat chuong trinh!\n");
                break;
            }
            default: {
                printf("\nLua chon khong hop le!\n");
                break;
            }
        }
        
        if(luaChon != 0) {
            system("pause");
        }
        
    } while(luaChon != 0);
    
    return 0;
}