#ifndef NHANSU_H
#define NHANSU_H

#include "User.h"
#include <string>
#include <sstream>
#include <utility>

class NhanSu : public User {
protected:
    std::string maNhanVien_{};
    std::string taiKhoan_{};
    std::string matKhau_{};
    double luong_{0.0};
    std::string caLam_{};
    bool trangThaiDangNhap_{false};  // phục vụ cho giao diện (đăng nhập thành công hay chưa)

public:
    // ===== Constructor & Destructor =====
    NhanSu() = default;
    virtual ~NhanSu() = default;

    NhanSu(std::string maNV, std::string ten, std::string sdt, std::string gt,
           std::string tk, std::string mk, double luong, std::string ca)
        : User(std::move(ten), std::move(sdt), std::move(gt)),
          maNhanVien_(std::move(maNV)),
          taiKhoan_(std::move(tk)),
          matKhau_(std::move(mk)),
          luong_(luong),
          caLam_(std::move(ca)) {}

    // ===== Getter & Setter =====
    const std::string& getMaNhanVien() const { return maNhanVien_; }
    void setMaNhanVien(const std::string& ma) { maNhanVien_ = ma; }

    const std::string& getTaiKhoan() const { return taiKhoan_; }
    void setTaiKhoan(const std::string& tk) { taiKhoan_ = tk; }

    const std::string& getMatKhau() const { return matKhau_; }
    void setMatKhau(const std::string& mk) { matKhau_ = mk; }

    double getLuong() const { return luong_; }
    void setLuong(double luong) { luong_ = luong; }

    const std::string& getCaLam() const { return caLam_; }
    void setCaLam(const std::string& ca) { caLam_ = ca; }

    bool getTrangThaiDangNhap() const { return trangThaiDangNhap_; }

    // ===== Logic nghiệp vụ =====
    virtual bool dangNhap(const std::string& tk, const std::string& mk) {
        bool hopLe = (tk == taiKhoan_ && mk == matKhau_);
        trangThaiDangNhap_ = hopLe;
        return hopLe;
    }

    virtual void dangXuat() {
        trangThaiDangNhap_ = false;
    }

    // ===== Trả về thông tin dạng chuỗi (cho giao diện SDL2 sử dụng) =====
    virtual std::string toString() const {
        std::ostringstream os;
        os << "Nhan su: " << hoTen_ << " (" << maNhanVien_ << ")\n"
           << "Ca lam: " << caLam_ << "\n"
           << "Luong: " << luong_;
        return os.str();
    }

    // ===== Trả về cấu trúc dữ liệu dạng JSON (dễ kết nối UI hoặc file JSON) =====
    virtual std::string toJSON() const {
        std::ostringstream os;
        os << "{"
           << "\"maNhanVien\":\"" << maNhanVien_ << "\","
           << "\"hoTen\":\"" << hoTen_ << "\","
           << "\"sdt\":\"" << sdt_ << "\","
           << "\"gioiTinh\":\"" << gioiTinh_ << "\","
           << "\"taiKhoan\":\"" << taiKhoan_ << "\","
           << "\"luong\":" << luong_ << ","
           << "\"caLam\":\"" << caLam_ << "\""
           << "}";
        return os.str();
    }

    virtual std::string getRole() const { return "Nhan su"; }
};

#endif
