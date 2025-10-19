#ifndef QUANLY_H
#define QUANLY_H
#include "NhanSu.h"
using namespace std;

class QuanLy : public NhanSu {
public:
    QuanLy() = default;
    ~QuanLy() override = default;

    QuanLy(string ten, string sdt, string gt,
           string maNV, string tk)
        : NhanSu(move(ten), move(sdt), move(gt),
                 move(maNV), move(tk)) {}

    // Các hành động riêng của quản lý (logic xử lý nằm ở Service)
    void themNhanVien() {}
    void xoaMonAn() {}
    void baoCaoDoanhThu() {}
};
#endif
