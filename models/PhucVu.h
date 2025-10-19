#ifndef PHUCVU_H
#define PHUCVU_H
#include "NhanSu.h"
using namespace std;

class PhucVu : public NhanSu {
public:
    PhucVu() = default;
    ~PhucVu() override = default;

    PhucVu(string ten, string sdt, string gt,
           string maNV, string tk)
        : NhanSu(move(ten), move(sdt), move(gt),
                 move(maNV), move(tk)) {}

    // Các hành động riêng của nhân viên phục vụ
    void taoDonHang() {}
    void guiOrderXuongBep() {}
    void inHoaDon() {}
};
#endif
