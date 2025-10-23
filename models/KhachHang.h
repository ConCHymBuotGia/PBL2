#ifndef KHACHHANG_H
#define KHACHHANG_H

#include "User.h"
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class KhachHang : public User {
private:
    string maKhachHang_;
    int diemTieuDung_{};
    string hangThanhVien_;

public:
    KhachHang() = default;

    KhachHang(string ten, string sdt, string gt,
              string maKH, int diem, string hang)
        : User(move(ten), move(sdt), move(gt)),
          maKhachHang_(move(maKH)),
          diemTieuDung_(diem),
          hangThanhVien_(move(hang)) {}

    ~KhachHang() override = default;

    // Getter / Setter
    const string& getMaKhachHang() const { return maKhachHang_; }
    void setMaKhachHang(const string& maKH) { maKhachHang_ = maKH; }

    int getDiemTieuDung() const { return diemTieuDung_; }
    void setDiemTieuDung(int diem) { diemTieuDung_ = diem; }

    const string& getHangThanhVien() const { return hangThanhVien_; }
    void setHangThanhVien(const string& hang) { hangThanhVien_ = hang; }

    // Các hàm xuất thông tin (UI-friendly)
    string xemThongTin() const override;  // ghi đè từ User
    vector<string> getMenu() const;
    string taoHoaDon(double tongTien) const;
};

#endif
