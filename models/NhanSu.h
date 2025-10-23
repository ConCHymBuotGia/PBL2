#ifndef NHANSU_H
#define NHANSU_H
#include "User.h"
using namespace std;

class NhanSu : public User {
protected:
    string maNhanVien_{};
    string taiKhoan_{};
    string matKhau_{};
    double luong_{0};
    string caLam_{};

public:
    NhanSu() = default;
    virtual ~NhanSu() = default;

    NhanSu(string ten, string sdt, string gt,
           string maNV, string tk)
        : User(move(ten), move(sdt), move(gt)),
          maNhanVien_(move(maNV)), taiKhoan_(move(tk)) {}

    // Getter / Setter
    const string& getMaNhanVien() const { return maNhanVien_; }
    void setMaNhanVien(const string& maNV) { maNhanVien_ = maNV; }

    const string& getTaiKhoan() const { return taiKhoan_; }
    void setTaiKhoan(const string& tk) { taiKhoan_ = tk; }

    const string& getCaLam() const { return caLam_; }
    void setCaLam(const string& ca) { caLam_ = ca; }

    double getLuong() const { return luong_; }
    void setLuong(double luong) { luong_ = luong; }
};
#endif
