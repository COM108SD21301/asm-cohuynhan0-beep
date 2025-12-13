#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

void flushStdin(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void choNhapEnter() {
    printf("\nNhan ENTER de quay lai menu...");
    // Chỉ chờ một lần ENTER
    flushStdin();
    printf("\n");
}
int timUCLN(int a, int b) {
    // Euclid, xử lý trường hợp cả hai bằng 0
    a = abs(a);
    b = abs(b);
    if (a == 0 && b == 0) return 0;
    // Note: abs(INT_MIN) có thể overflow, tuy nhiên với input bình thường (mẫu số, v.v.) ít khi gặp.
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
struct SinhVien {
    char hoTen[50];
    float diem;
    char hocLuc[20];
};
void chucNang1() {
    double num;
    printf("\n=================== 1. KIEM TRA SO NGUYEN ===================\n");
    printf("Nhap mot so: ");

    if (scanf("%lf", &num) != 1) {
        printf("Nhap khong hop le!\n");
        flushStdin();
        return;
    }
    flushStdin();

    if (floor(num) == num) { // la so nguyen
        long long x = (long long)num;
        printf("-> %lld la so nguyen.\n", x);

        if (x >= 2) {
            long long limit = (long long) sqrt((double)x);
            int dem = 0;
            for (long long i = 2; i <= limit; i++) {
                if (x % i == 0) { dem = 1; break; }
            }
            if (dem == 0) printf("-> %lld la so nguyen to.\n", x);
            else printf("-> %lld khong phai so nguyen to.\n", x);
        } else {
            printf("-> %lld khong phai so nguyen to.\n", x);
        }

        if (x >= 0) {
            long long can = (long long) sqrt((double)x);
            if (can * can == x) printf("-> %lld la so chinh phuong.\n", x);
            else printf("-> %lld khong phai so chinh phuong.\n", x);
        } else {
            printf("-> %lld khong phai so chinh phuong (so am).\n", x);
        }
    } else {
        printf("-> %.6f khong phai la so nguyen.\n", num);
    }
}
void chucNang2() {
    int a, b;
    printf("\n=================== 2. UCLN va BCNN ===================\n");
    printf("Nhap a, b: ");

    if (scanf("%d%d", &a, &b) != 2) {
        printf("Nhap khong hop le!\n");
        flushStdin();
        return;
    }
    flushStdin();

    if (a <= 0 || b <= 0) {
        printf("Nhap so duong!\n");
        return;
    }

    int x = a, y = b;
    int ucln = timUCLN(x, y);
    if (ucln == 0) {
        printf("UCLN khong xac dinh (0).\n");
        return;
    }

    long long bcnn = ((long long)x * (long long)y) / ucln;
    printf("UCLN: %d\n", ucln);
    printf("BCNN: %lld\n", bcnn);
}
void chucNang3() {
    int gioVao, gioRa, tg;
    double tienHat;

    printf("\n=================== 3. TINH TIEN KARAOKE ===================\n");

    // Kiểm tra trả về của scanf để tránh loop vô hạn khi nhập sai
    do {
        printf("Moi nhap gio Vao hat (12-22): ");
if (scanf("%d", &gioVao) != 1) { printf("Nhap khong hop le!\n"); flushStdin(); gioVao = -1; continue; }
        printf("Moi nhap gio Ra hat (13-23): ");
        if (scanf("%d", &gioRa) != 1) { printf("Nhap khong hop le!\n"); flushStdin(); gioRa = -1; continue; }
        flushStdin();
    } while(gioVao < 12 || gioVao > 22 || gioRa < 13 || gioRa > 23 || gioRa <= gioVao);

    tg = gioRa - gioVao;

    if (tg < 3) tienHat = 150000.0 * tg;
    else tienHat = 150000.0 * 3 + (tg - 3) * 150000.0 * 0.7;

    if (gioVao >= 14 && gioVao <= 17) {
        tienHat *= 0.9;
        printf("-> Duoc giam 10%% (gio thap diem 14h-17h)\n");
    }

    printf("-> So gio hat: %d gio\n", tg);
    printf("Tong tien phai tra: %.0f VND\n", tienHat);
}
void chucNang4() {
    double kwh, tien = 0;
    printf("\n=================== 4. TINH TIEN DIEN ===================\n");
    printf("Nhap so kWh dien: ");

    if (scanf("%lf", &kwh) != 1) {
        printf("Nhap khong hop le!\n");
        flushStdin();
        return;
    }
    flushStdin();

    if (kwh < 0) {
        printf("So kWh khong hop le!\n");
        return;
    }

    if (kwh <= 50) tien = kwh * 1.678;
    else if (kwh <= 100) tien = 50 * 1.678 + (kwh - 50) * 1.734;
    else if (kwh <= 200) tien = 50 * 1.678 + 50 * 1.734 + (kwh - 100) * 2.014;
    else if (kwh <= 300) tien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + (kwh - 200) * 2.536;
    else if (kwh <= 400) tien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + 100 * 2.536 + (kwh - 300) * 2.834;
    else tien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + 100 * 2.536 + 100 * 2.834 + (kwh - 400) * 2.927;

    // Giả sử các đơn vị là nghìn đồng, nhân 1000 để in VND
    printf("Tien dien: %.0f VND\n", tien * 1000.0);
}
void chucNang6() {
    double khoanVay;
    printf("\n=================== 6. LAI SUAT VAY (12 THANG) ===================\n");
    printf("Nhap so tien vay: ");

    if (scanf("%lf", &khoanVay) != 1 || khoanVay <= 0) {
        printf("So tien khong hop le!\n");
        flushStdin();
        return;
    }
    flushStdin();

    double gocPhaiTra = khoanVay / 12.0;
    double laiSuat = 0.05;

    printf("\n%-5s %-15s %-15s %-15s %-15s\n", 
           "Ky", "Lai", "Goc", "Tong", "Con lai");

    for (int i = 1; i <= 12 && khoanVay > 0.000001; i++) {
        double laiPhaiTra = khoanVay * laiSuat;
        double gocThucTe = gocPhaiTra;

        if (gocThucTe > khoanVay) {
            gocThucTe = khoanVay;
        }

        double tongPhaiTra = laiPhaiTra + gocThucTe;
        khoanVay -= gocThucTe;

        double conLai = khoanVay < 0 ? 0 : khoanVay;
        // In với 2 chữ số thập phân cho rõ ràng
        printf("%-5d %-15.2f %-15.2f %-15.2f %-15.2f\n",
               i, laiPhaiTra, gocThucTe, tongPhaiTra, conLai);
    }
}
void chucNang8() {
    int n;
    printf("\n=================== 8. XEP HANG SINH VIEN ===================\n");
    printf("Nhap so luong SV (toi da 100): ");

    if (scanf("%d", &n) != 1) {
printf("Nhap khong hop le!\n");
        flushStdin();
        return;
    }
    flushStdin();

    if (n <= 0 || n > 100) {
        printf("So luong SV khong hop le! (1-100)\n");
        return;
    }

    struct SinhVien sv[100];

    for (int i = 0; i < n; i++) {
        printf("\n--- Nhap SV %d ---\n", i + 1);

        printf("Ten: ");
        if (fgets(sv[i].hoTen, sizeof(sv[i].hoTen), stdin) == NULL) {
            printf("Loi khi nhap ten!\n");
            sv[i].hoTen[0] = '\0';
        } else {
            sv[i].hoTen[strcspn(sv[i].hoTen, "\n")] = '\0';
        }

        printf("Diem: ");
        if (scanf("%f", &sv[i].diem) != 1 || sv[i].diem < 0.0f || sv[i].diem > 10.0f) {
            printf("Diem khong hop le! (0-10)\n");
            flushStdin();
            i--; // Nhập lại sinh viên này
            continue;
        }
        flushStdin();

        if (sv[i].diem >= 9.0f) strcpy(sv[i].hocLuc, "Xuat sac");
        else if (sv[i].diem >= 8.0f) strcpy(sv[i].hocLuc, "Gioi");
        else if (sv[i].diem >= 6.5f) strcpy(sv[i].hocLuc, "Kha");
        else if (sv[i].diem >= 5.0f) strcpy(sv[i].hocLuc, "TB");
        else strcpy(sv[i].hocLuc, "Yeu");
    }

    // Sap xep giam dan
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sv[i].diem < sv[j].diem) {
                struct SinhVien t = sv[i];
                sv[i] = sv[j];
                sv[j] = t;
            }
        }
    }

    printf("\n%-30s %-10s %-10s\n", "Ten", "Diem", "Hoc Luc");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-30s %-10.1f %-10s\n", sv[i].hoTen, sv[i].diem, sv[i].hocLuc);
    }
}
void chucNang10() {
    int tu1, mau1, tu2, mau2;
    printf("\n=================== 10. TINH TOAN PHAN SO ===================\n");

    // NHẬP PHÂN SỐ 1
    printf("Nhap phan so 1 (tu mau): ");
    if (scanf("%d%d", &tu1, &mau1) != 2) {
        printf("Nhap khong hop le!\n");
        flushStdin();
        return;
    }
    flushStdin();

    // NHẬP PHÂN SỐ 2
    printf("Nhap phan so 2 (tu mau): ");
    if (scanf("%d%d", &tu2, &mau2) != 2) {
        printf("Nhap khong hop le!\n");
        flushStdin();
        return;
    }
    flushStdin();

    // KIỂM TRA MẪU SỐ
    if (mau1 == 0 || mau2 == 0) {
        printf("Mau so phai khac 0!\n");
        return;
    }

    int tu, mau, u;

    // Tổng
    tu = tu1 * mau2 + tu2 * mau1;
    mau = mau1 * mau2;
    if (tu == 0) {
        printf("Tong: 0/1\n");
    } else {
        u = timUCLN(tu, mau);
        if (mau < 0) { mau = -mau; tu = -tu; } // chuẩn hóa dấu
        printf("Tong: %d/%d\n", tu / u, mau / u);
    }

    // Hiệu
    tu = tu1 * mau2 - tu2 * mau1;
    mau = mau1 * mau2;
    if (tu == 0) {
        printf("Hieu: 0/1\n");
    } else {
        u = timUCLN(tu, mau);
        if (mau < 0) { mau = -mau; tu = -tu; }
        printf("Hieu: %d/%d\n", tu / u, mau / u);
    }

    // Tich
tu = tu1 * tu2;
    mau = mau1 * mau2;
    if (tu == 0) {
        printf("Tich: 0/1\n");
    } else {
        u = timUCLN(tu, mau);
        if (mau < 0) { mau = -mau; tu = -tu; }
        printf("Tich: %d/%d\n", tu / u, mau / u);
    }

    // Thuong
    if (tu2 == 0) {
        printf("Khong the chia!\n");
    } else {
        tu = tu1 * mau2;
        mau = mau1 * tu2;
        if (tu == 0) {
            printf("Thuong: 0/1\n");
        } else {
            u = timUCLN(tu, mau);
            if (mau < 0) { mau = -mau; tu = -tu; }
            printf("Thuong: %d/%d\n", tu / u, mau / u);
        }
    }
}

// ================= MAIN =================
int main() {
    int chon;

    do {
        printf("\n");
        printf("==========================================\n");
        printf("          MENU CHUONG TRINH\n");
        printf("==========================================\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Tinh UCLN va BCNN\n");
        printf("3. Tinh tien Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("6. Tinh lai suat vay\n");
        printf("8. Xep hang sinh vien\n");
        printf("10. Tinh toan phan so\n");
        printf("0. Thoat chuong trinh\n");
        printf("==========================================\n");
        printf("Moi ban nhap lua chon: ");

        if (scanf("%d", &chon) != 1) {
            printf("Lua chon khong hop le!\n");
            flushStdin();
            chon = -1;
            continue;
        }
        flushStdin();

        switch (chon) {
            case 1: chucNang1(); break;
            case 2: chucNang2(); break;
            case 3: chucNang3(); break;
            case 4: chucNang4(); break;
            case 6: chucNang6(); break;
            case 8: chucNang8(); break;
            case 10: chucNang10(); break;
            case 0:
                printf("\n==========================================\n");
                printf("           TAM BIET! HEN GAP LAI\n");
                printf("==========================================\n");
                return 0;
            default:
                printf("Lua chon sai! Hay chon 0, 1, 2, 3, 4, 6, 8 hoac 10.\n");
        }

        choNhapEnter();

    } while (1);

    return 0;
}