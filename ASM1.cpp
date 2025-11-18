#include <stdio.h> 
#include <math.h>
#include <stdlib.h>

int main() {
    int luaChon;
    
    do {
        // Hiển thị menu
        printf("\nChao mung ban den voi ASM cua toi");
        printf("\nNhap 1: Lua chon chuc nang So nguyen");
        printf("\nNhap 2: Lua chon chuc nang tim UCLN va BCNN");
        printf("\nNhap 3: Lua chon chuc nang Tinh tien quan Karaoke");
        printf("\nNhap 4: Lua chon chuc nang Tinh tien dien");
        printf("\nNhap 0: Thoat chuong trinh");
        printf("\nMoi ban nhap lua chon: ");
        scanf("%d", &luaChon);
        
        // Xử lý lựa chọn
        switch(luaChon) {
            case 1: {
                printf("Ban chon CN1\n");
                
                float x;
                printf("Moi ban nhap so thuc x: ");
                scanf("%f", &x);
                
                // Kiểm tra x có phải số nguyên không
                if (x == (int)x) {
                    printf("%.1f la so nguyen\n", x);
                } else {
                    printf("%.1f la so thuc\n", x);
                }
                break;
            }
            case 2: {
                printf("Ban chon CN2\n");
                // Thêm code chức năng 2 ở đây
                break;
            }
            case 3: {
                printf("Ban chon CN3\n");
                // Thêm code chức năng 3 ở đây
                break;
            }
            case 4: {
                printf("Ban chon CN4\n");
                // Thêm code chức năng 4 ở đây
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
        
        // Dừng màn hình để xem kết quả (chỉ khi không phải là thoát)
        if(luaChon != 0) {
            system("pause"); // Hoặc có thể dùng getchar();
        }
        
    } while(luaChon != 0);
    
    return 0;
}