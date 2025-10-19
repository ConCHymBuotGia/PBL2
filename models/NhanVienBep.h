#ifndef NHANVIENBEP_H
#define NHANVIENBEP_H
#include "NhanSu.h"
using namespace std;

class NhanVienBep : public NhanSu {
public:
    NhanVienBep() = default;
    ~NhanVienBep() override = default;

    NhanVienBep(string ten, string sdt, string gt,
                string maNV, string tk)
        : NhanSu(move(ten), move(sdt), move(gt),
                 move(maNV), move(tk)) {}

    // Các hành động riêng của nhân viên bếp
    void capNhatTrangThaiMon() {}
    void xemDanhSachMonDangNau() {}
};
#endif
