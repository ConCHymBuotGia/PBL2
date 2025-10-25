#include "NhanSu.h"
#include <utility>    // std::move
#include <sstream>    // std::ostringstream

// ===== Constructor =====
NhanSu::NhanSu(std::string maNV, std::string ten, std::string sdt, std::string gt,
               std::string tk, std::string mk, double luong, std::string ca)
    : User(std::move(ten), std::move(sdt), std::move(gt)),
      maNhanVien_(std::move(maNV)),
      taiKhoan_(std::move(tk)),
      matKhau_(std::move(mk)),
      luong_(luong),
      caLam_(std::move(ca)) {}

// ===== Getter & Setter =====
const std::string& NhanSu::getMaNhanVien() const { return maNhanVien_; }
void NhanSu::setMaNhanVien(const std::string& ma) { maNhanVien_ = ma; }

const std::string& NhanSu::getTaiKhoan() const { return taiKhoan_; }
void NhanSu::setTaiKhoan(const std::string& tk) { taiKhoan_ = tk; }

const std::string& NhanSu::getMatKhau() const { return matKhau_; }
void NhanSu::setMatKhau(const std::string& mk) { matKhau_ = mk; }

double NhanSu::getLuong() const { return luong_; }
void NhanSu::setLuong(double luong) { luong_ = luong; }

const std::string& NhanSu::getCaLam() const { return caLam_; }
void NhanSu::setCaLam(const std::string& ca) { caLam_ = ca; }

bool NhanSu::getTrangThaiDangNhap() const { return trangThaiDangNhap_; }

// ===== Logic nghiệp vụ =====
bool NhanSu::dangNhap(const std::string& tk, const std::string& mk) {
    bool hopLe = (tk == taiKhoan_ && mk == matKhau_);
    trangThaiDangNhap_ = hopLe;
    return hopLe;
}

void NhanSu::dangXuat() {
    trangThaiDangNhap_ = false;
}

// ===== Chuỗi thông tin hiển thị =====
std::string NhanSu::toString() const {
    std::ostringstream os;
    os << "Nhan su: " << hoTen_ << " (" << maNhanVien_ << ")\n"
       << "Ca lam: " << caLam_ << "\n"
       << "Luong: " << luong_;
    return os.str();
}

// ===== Chuỗi JSON (phục vụ lưu file hoặc UI) =====
std::string NhanSu::toJSON() const {
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

// ===== Trả về loại người dùng =====
std::string NhanSu::getRole() const {
    return "Nhan su";
}
