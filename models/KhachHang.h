#ifndef KHACHHANG_H
#define KHACHHANG_H
#include "User.h"
using namespace std;

class KhachHang : public User {
private:
    string maKhachHang_{};
    int diemTichLuy_{0};
    string hangThanhVien_{"Thuong"};

public:
    KhachHang() = default;
    virtual ~KhachHang() = default;

    KhachHang(string ten, string sdt, string gt, string maKH)
        : User(move(ten), move(sdt), move(gt)),
          maKhachHang_(move(maKH)) {}

    // Getter / Setter
    const string& getMaKhachHang() const { return maKhachHang_; }
    void setMaKhachHang(const string& maKH) { maKhachHang_ = maKH; }

    int getDiemTichLuy() const { return diemTichLuy_; }
    void setDiemTichLuy(int diem) { diemTichLuy_ = diem; }

    const string& getHangThanhVien() const { return hangThanhVien_; }
    void setHangThanhVien(const string& hang) { hangThanhVien_ = hang; }
};
#endif
