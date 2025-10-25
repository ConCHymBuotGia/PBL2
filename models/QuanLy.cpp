#include "QuanLy.h"
#include <sstream>
#include <iomanip>
#include <algorithm>

QuanLi::QuanLi(std::string ma, std::string ten, std::string sdt, std::string gt, double luong)
    : User(std::move(ten), std::move(sdt), std::move(gt)),
      maQuanLi_(std::move(ma)), luong_(luong) {}

// ===== Getter & Setter =====
const std::string& QuanLi::getMaQuanLi() const { return maQuanLi_; }
void QuanLi::setMaQuanLi(const std::string& ma) { maQuanLi_ = ma; }

double QuanLi::getLuong() const { return luong_; }
void QuanLi::setLuong(double luong) { luong_ = luong; }

double QuanLi::getDoanhThu() const { return doanhThu_; }
void QuanLi::setDoanhThu(double doanhThu) { doanhThu_ = doanhThu; }

// ===== Nhân sự =====
void QuanLi::themNhanSu(const NhanSu& ns) {
    danhSachNhanSu_.push_back(ns);
}

void QuanLi::xoaNhanSu(const std::string& maNhanVien) {
    danhSachNhanSu_.erase(
        std::remove_if(danhSachNhanSu_.begin(), danhSachNhanSu_.end(),
                       [&](const NhanSu& n) { return n.getMaNhanVien() == maNhanVien; }),
        danhSachNhanSu_.end());
}

std::optional<NhanSu> QuanLi::timNhanSu(const std::string& maNhanVien) const {
    for (const auto& n : danhSachNhanSu_) {
        if (n.getMaNhanVien() == maNhanVien)
            return n;
    }
    return std::nullopt;
}

std::string QuanLi::xemDanhSachNhanSu() const {
    std::ostringstream os;
    os << "Danh sach nhan su (" << danhSachNhanSu_.size() << "):\n";
    for (const auto& n : danhSachNhanSu_) {
        os << "- " << n.getMaNhanVien() << " | " << n.getHoTen() << " | " << n.getGioiTinh() << "\n";
    }
    return os.str();
}

// ===== Menu =====
void QuanLi::themMonAn(const MonAn& mon) {
    menu_.push_back(mon);
}

void QuanLi::xoaMonAn(const std::string& tenMon) {
    menu_.erase(
        std::remove_if(menu_.begin(), menu_.end(),
                       [&](const MonAn& m) { return m.tenMon == tenMon; }),
        menu_.end());
}

std::string QuanLi::xemMenu() const {
    std::ostringstream os;
    os << "Menu hien tai (" << menu_.size() << " mon):\n";
    os << std::fixed << std::setprecision(0);
    for (const auto& m : menu_) {
        os << "- " << m.tenMon << " : " << m.gia << " VND\n";
    }
    return os.str();
}

// ===== Doanh thu =====
void QuanLi::congDoanhThu(double soTien) { doanhThu_ += soTien; }
void QuanLi::resetDoanhThu() { doanhThu_ = 0; }

// ===== JSON xuất ra cho UI =====
std::string QuanLi::toJSON() const {
    std::ostringstream os;
    os << "{"
       << "\"maQuanLi\":\"" << maQuanLi_ << "\","
       << "\"hoTen\":\"" << hoTen_ << "\","
       << "\"sdt\":\"" << sdt_ << "\","
       << "\"gioiTinh\":\"" << gioiTinh_ << "\","
       << "\"luong\":" << luong_ << ","
       << "\"doanhThu\":" << doanhThu_ << ",";

    // JSON nhân sự
    os << "\"nhanSu\":[";
    for (size_t i = 0; i < danhSachNhanSu_.size(); ++i) {
        const auto& n = danhSachNhanSu_[i];
        os << "{"
           << "\"maNhanVien\":\"" << n.getMaNhanVien() << "\","
           << "\"hoTen\":\"" << n.getHoTen() << "\","
           << "\"gioiTinh\":\"" << n.getGioiTinh() << "\"}";
        if (i + 1 < danhSachNhanSu_.size()) os << ",";
    }
    os << "],";

    // JSON menu
    os << "\"menu\":[";
    for (size_t i = 0; i < menu_.size(); ++i) {
        const auto& m = menu_[i];
        os << "{"
           << "\"tenMon\":\"" << m.tenMon << "\","
           << "\"gia\":" << m.gia << "}";
        if (i + 1 < menu_.size()) os << ",";
    }
    os << "]}";
    return os.str();
}

// ===== Vai trò =====
std::string QuanLi::getRole() const {
    return "Quan li cua hang";
}
