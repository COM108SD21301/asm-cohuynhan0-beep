#include <stdio.h>
#include <math.h>
#include <string.h>

// --- 1. DINH NGHIA HANG SO VA CAU TRUC ---
#define MAX_SV 100

struct SinhVien {
    char hoTen[50];
    float diem;
    char hocLuc[20];
};

// --- 2. NGUYEN MAU HAM (PROTOTYPES) ---
// Ham tien ich
void xoaBoNhoDem();
void xuLyTiepTuc();
int timUCLN(int a, int b);

// Ham chuc nang chinh
void kiemTraSoNguyen();      // CN 1
void tinhUCLN_BCNN();        // CN 2
void tinhTienKaraoke();      // CN 3
void tinhTienDien();         // CN 4
void tinhLaiSuatVay();       // CN 6
void xepHangSinhVien();      // CN 8
void tinhToanPhanSo();       // CN 10

// --- 3. HAM MAIN ---
int main() {
    int luaChon;
    
    do {
        printf("\n================ MENU CHUONG TRINH ================\n");
        printf("1.  Kiem tra so nguyen\n");
        printf("2.  Tinh UCLN va BCNN\n");
        printf("3.  Tinh tien Karaoke\n");
        printf("4.  Tinh tien dien\n");
        printf("6.  Tinh lai suat vay ngan hang\n");
        printf("8.  Xep hang hoc luc sinh vien\n");
        printf("10. Tinh toan phan so\n");
        printf("0.  Thoat chuong trinh\n");
        printf("===================================================\n");
        printf("Moi ban chon chuc nang: ");
        
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:  kiemTraSoNguyen(); break;
            case 2:  tinhUCLN_BCNN(); break;
            case 3:  tinhTienKaraoke(); break;
            case 4:  tinhTienDien(); break;
            case 6:  tinhLaiSuatVay(); break;
            case 8:  xepHangSinhVien(); break;
            case 10: tinhToanPhanSo(); break;
            case 0:  
                printf("Tam biet! Hen gap lai.\n"); 
                return 0;
            default: 
                printf("Chuc nang khong ton tai! Moi chon lai.\n");
        }

        if (luaChon != 0) {
            xuLyTiepTuc();
        }

    } while (1);
    
    return 0;
}

// --- 4. HAM TIEN ICH ---

// Xoa sach ky tu thua (Enter) trong bo nho dem
void xoaBoNhoDem() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Dung man hinh cho nguoi dung xem ket qua
void xuLyTiepTuc() {
    printf("\n----------------------------------------------");
    printf("\nBam ENTER de ve Menu (hoac bam 0 de thoat): ");
    
    xoaBoNhoDem(); // Don rac truoc khi cho nhap
    
    char lenh = getchar(); // Cho nhap phim
    if (lenh == '0') {
        printf("Tam biet! Hen gap lai.\n");
        exit(0);
    }
}

int timUCLN(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (a == 0 && b == 0) return 1; // Tranh chia cho 0
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// --- 5. DINH NGHIA CAC CHUC NANG ---

// CN 1: Kiem tra so nguyen
void kiemTraSoNguyen() {
    int n;
    printf("\n--- 1. KIEM TRA SO NGUYEN ---\n");
    printf("Nhap so nguyen n: ");
    scanf("%d", &n);

    // Kiem tra SNT
    int laSNT = 1;
    if (n < 2) laSNT = 0;
    else {
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) { laSNT = 0; break; }
        }
    }
    printf(laSNT ? "-> %d la so nguyen to.\n" : "-> %d khong phai so nguyen to.\n", n);

    // Kiem tra so chinh phuong
    int can = sqrt(n);
    printf((can * can == n) ? "-> %d la so chinh phuong.\n" : "-> %d khong phai so chinh phuong.\n", n);
}

// CN 2: UCLN & BCNN
void tinhUCLN_BCNN() {
    int a, b;
    printf("\n--- 2. UCLN va BCNN ---\n");
    printf("Nhap a, b: ");
    scanf("%d%d", &a, &b);
    
    int ucln = timUCLN(a, b);
    long long bcnn = (long long)a * b / ucln; 
    
    printf("UCLN: %d\n", ucln);
    printf("BCNN: %lld\n", abs(bcnn));
}

// CN 3: Karaoke
void tinhTienKaraoke() {
    int vao, ra;
    printf("\n--- 3. TINH TIEN KARAOKE ---\n");
    do {
        printf("Nhap gio vao (12-22), gio ra (13-23): ");
        scanf("%d%d", &vao, &ra);
        if (vao >= 12 && ra <= 23 && ra > vao) break;
        printf("Gio khong hop le, vui long nhap lai!\n");
    } while (1);

    int gioHat = ra - vao;
    float tien;
    
    if (gioHat <= 3) 
        tien = gioHat * 150000;
    else 
        tien = 3 * 150000 + (gioHat - 3) * 150000 * 0.7;

    if (vao >= 14 && vao <= 17) {
        tien *= 0.9;
        printf("-> Duoc giam gia 10%% (Gio vang)!\n");
    }
    printf("Tong tien: %.0f VND\n", tien);
}

// CN 4: Tien dien
void tinhTienDien() {
    float kwh, tien;
    printf("\n--- 4. TINH TIEN DIEN ---\n");
    printf("Nhap so kWh: ");
    scanf("%f", &kwh);
    
    if (kwh < 0) { printf("So kWh khong hop le!\n"); return; }

    if (kwh <= 50)       tien = kwh * 1.678;
    else if (kwh <= 100) tien = 50 * 1.678 + (kwh - 50) * 1.734;
    else if (kwh <= 200) tien = 50 * 1.678 + 50 * 1.734 + (kwh - 100) * 2.014;
    else if (kwh <= 300) tien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + (kwh - 200) * 2.536;
    else if (kwh <= 400) tien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + 100 * 2.536 + (kwh - 300) * 2.834;
    else                 tien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + 100 * 2.536 + 100 * 2.834 + (kwh - 400) * 2.927;
    
    printf("Tien dien: %.0f VND\n", tien * 1000);
}

// CN 6: Lai suat vay
void tinhLaiSuatVay() {
    double vay;
    printf("\n--- 6. LAI SUAT VAY ---\n");
    printf("Nhap so tien vay: ");
    scanf("%lf", &vay);
    
    double goc = vay / 12.0;
    printf("\n%-5s %-15s %-15s %-15s %-15s\n", "Ky", "Lai", "Goc", "Tong", "Con lai");
    
    for (int i = 1; i <= 12; i++) {
        double lai = vay * 0.05;
        double tong = lai + goc;
        vay -= goc;
        if (vay < 0) vay = 0;
        printf("%-5d %-15.0f %-15.0f %-15.0f %-15.0f\n", i, lai, goc, tong, vay);
    }
}

// CN 8: Xep hang Sinh vien
void xepHangSinhVien() {
    int n;
    struct SinhVien sv[MAX_SV];
    printf("\n--- 8. XEP HANG SINH VIEN ---\n");
    printf("Nhap so luong SV: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nNhap SV thu %d:\n", i + 1);
        printf(" - Ten: ");
        xoaBoNhoDem(); // Xoa Enter thua truoc khi nhap chuoi
        
        // Dung fgets an toan hon gets
        fgets(sv[i].hoTen, sizeof(sv[i].hoTen), stdin);
        sv[i].hoTen[strcspn(sv[i].hoTen, "\n")] = 0; // Xoa ky tu xuong dong

        printf(" - Diem: ");
        scanf("%f", &sv[i].diem);

        // Xep loai
        if (sv[i].diem >= 9)      strcpy(sv[i].hocLuc, "Xuat sac");
        else if (sv[i].diem >= 8) strcpy(sv[i].hocLuc, "Gioi");
        else if (sv[i].diem >= 6.5) strcpy(sv[i].hocLuc, "Kha");
        else if (sv[i].diem >= 5) strcpy(sv[i].hocLuc, "Trung binh");
        else                      strcpy(sv[i].hocLuc, "Yeu");
    }

    // Sap xep noi bot
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sv[i].diem < sv[j].diem) {
                struct SinhVien tam = sv[i];
                sv[i] = sv[j];
                sv[j] = tam;
            }
        }
    }

    printf("\n%-20s %-10s %-15s\n", "HO TEN", "DIEM", "HOC LUC");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-20s %-10.1f %-15s\n", sv[i].hoTen, sv[i].diem, sv[i].hocLuc);
    }
}

// CN 10: Tinh phan so
void tinhToanPhanSo() {
    int t1, m1, t2, m2;
    printf("\n--- 10. TINH PHAN SO ---\n");
    printf("Nhap tu mau PS1: "); scanf("%d%d", &t1, &m1);
    printf("Nhap tu mau PS2: "); scanf("%d%d", &t2, &m2);

    if (m1 == 0 || m2 == 0) { 
        printf("Loi: Mau so phai khac 0!\n"); 
        return; 
    }

    int tu, mau, uc;
    
    // Helper lambda hoac macro cho viec rut gon va in
    // O day viet tuong minh cho de hieu
    
    // Tong
    tu = t1 * m2 + t2 * m1; mau = m1 * m2; uc = timUCLN(tu, mau);
    printf("Tong:   %d/%d\n", tu/uc, mau/uc);

    // Hieu
    tu = t1 * m2 - t2 * m1; mau = m1 * m2; uc = timUCLN(tu, mau);
    printf("Hieu:   %d/%d\n", tu/uc, mau/uc);

    // Tich
    tu = t1 * t2; mau = m1 * m2; uc = timUCLN(tu, mau);
    printf("Tich:   %d/%d\n", tu/uc, mau/uc);

    // Thuong
    if (t2 == 0) printf("Thuong: Khong chia duoc (tu so 2 = 0)!\n");
    else {
        tu = t1 * m2; mau = m1 * t2; uc = timUCLN(tu, mau);
        printf("Thuong: %d/%d\n", tu/uc, mau/uc);
    }
}