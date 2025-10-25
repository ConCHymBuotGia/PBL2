#include "DonHang.h"
#include <utility>
#include <sstream>
#include <iomanip>

// ===== Lấy thời gian hiện tại =====
std::string DonHang::getCurrentTime() const {
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);
    char buf[20];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", ltm);
    return std::string(buf);
}

// ===== Constructor =====
DonHang::DonHang(std::string maDon, std::string maBan, std::string maNV)
    : maDonHang_(std::move(maDon)), maBan_(std::move(maBan)), maNhanVien_(std::move(maNV)),
      trangThai_("Chờ xử lý") {
    thoiGianTao_ = getCurrentTime();
    thoiGianCapNhat_ = thoiGianTao_;
}

// ===== Getter / Setter =====
const std::string& DonHang::getMaDonHang() const { return maDonHang_; }
const std::string& DonHang::getMaBan() const { return maBan_; }
const std::string& DonHang::getMaNhanVien() const { return maNhanVien_; }
const std::string& DonHang::getTrangThai() const { return trangThai_; }
const std::vector<MonGoi>& DonHang::getDanhSachMon() const { return danhSachMon_; }

void DonHang::setTrangThai(const std::string& tt) {
    trangThai_ = tt;
    thoiGianCapNhat_ = getCurrentTime();
}

// ===== Nghiệp vụ =====
void DonHang::themMon(const MonGoi& mon) {
    for (auto& m : danhSachMon_) {
        if (m.tenMon == mon.tenMon) {
            m.soLuong += mon.soLuong;
            thoiGianCapNhat_ = getCurrentTime();
            return;
        }
    }
    danhSachMon_.push_back(mon);
    thoiGianCapNhat_ = getCurrentTime();
}

void DonHang::xoaMon(const std::string& tenMon) {
    danhSachMon_.erase(
        std::remove_if(danhSachMon_.begin(), danhSachMon_.end(),
                       [&](const MonGoi& m) { return m.tenMon == tenMon; }),
        danhSachMon_.end());
    thoiGianCapNhat_ = getCurrentTime();
}

void DonHang::capNhatMon(const std::string& tenMon, int soLuong) {
    for (auto& m : danhSachMon_) {
        if (m.tenMon == tenMon) {
            m.soLuong = soLuong;
            thoiGianCapNhat_ = getCurrentTime();
            return;
        }
    }
}

double DonHang::tinhTongTien() const {
    double tong = 0;
    for (const auto& m : danhSachMon_) {
        tong += m.gia * m.soLuong;
    }
    return tong;
}

void DonHang::capNhatTrangThai(const std::string& tt) {
    trangThai_ = tt;
    thoiGianCapNhat_ = getCurrentTime();
}

std::string DonHang::xemChiTiet() const {
    std::ostringstream os;
    os << "Đơn hàng: " << maDonHang_ << "\n"
       << "Bàn: " << maBan_ << "\n"
       << "Nhân viên: " << maNhanVien_ << "\n"
       << "Trạng thái: " << trangThai_ << "\n"
       << "Thời gian tạo: " << thoiGianTao_ << "\n\n";

    os << "Danh sách món:\n";
    for (const auto& m : danhSachMon_) {
        os << "- " << m.tenMon << " x" << m.soLuong << " = "
           << (m.gia * m.soLuong) << " VND\n";
    }
    os << "Tổng cộng: " << tinhTongTien() << " VND\n";
    return os.str();
}

std::string DonHang::toJSON() const {
    std::ostringstream os;
    os << "{"
       << "\"maDonHang\":\"" << maDonHang_ << "\","
       << "\"maBan\":\"" << maBan_ << "\","
       << "\"maNhanVien\":\"" << maNhanVien_ << "\","
       << "\"trangThai\":\"" << trangThai_ << "\","
       << "\"thoiGianTao\":\"" << thoiGianTao_ << "\","
       << "\"thoiGianCapNhat\":\"" << thoiGianCapNhat_ << "\","
       << "\"danhSachMon\":[";
    for (size_t i = 0; i < danhSachMon_.size(); ++i) {
        const auto& m = danhSachMon_[i];
        os << "{"
           << "\"tenMon\":\"" << m.tenMon << "\","
           << "\"gia\":" << m.gia << ","
           << "\"soLuong\":" << m.soLuong
           << "}";
        if (i + 1 < danhSachMon_.size()) os << ",";
    }
    os << "]}";
    return os.str();
}
