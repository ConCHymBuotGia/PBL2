#include "Ban.h"
#include <utility>
#include <sstream>
#include <iomanip>

// ===== Constructor =====
Ban::Ban(std::string maBan, std::string trangThai)
    : maBan_(std::move(maBan)), trangThai_(std::move(trangThai)) {}

// ===== Getter & Setter =====
const std::string& Ban::getMaBan() const { return maBan_; }
void Ban::setMaBan(const std::string& maBan) { maBan_ = maBan; }

const std::string& Ban::getTrangThai() const { return trangThai_; }
void Ban::setTrangThai(const std::string& tt) { trangThai_ = tt; }

int Ban::getSoLuongKhach() const { return soLuongKhach_; }
void Ban::setSoLuongKhach(int soLuong) { soLuongKhach_ = soLuong; }

const std::string& Ban::getMaNhanVienPhucVu() const { return maNhanVienPhucVu_; }
void Ban::setMaNhanVienPhucVu(const std::string& maNV) { maNhanVienPhucVu_ = maNV; }

const std::vector<MonGoi>& Ban::getDonHang() const { return donHang_; }

// ===== Nghiệp vụ =====
void Ban::datBan(int soLuong, const std::string& maNhanVien) {
    soLuongKhach_ = soLuong;
    maNhanVienPhucVu_ = maNhanVien;
    trangThai_ = "Đang phục vụ";
}

void Ban::themMon(const MonGoi& mon) {
    // Nếu món đã có thì cộng thêm số lượng
    for (auto& m : donHang_) {
        if (m.tenMon == mon.tenMon) {
            m.soLuong += mon.soLuong;
            return;
        }
    }
    donHang_.push_back(mon);
}

std::string Ban::xemDonHang() const {
    std::ostringstream os;
    os << "Đơn hàng bàn " << maBan_ << ":\n";
    os << std::fixed << std::setprecision(0);
    for (const auto& m : donHang_) {
        os << "- " << m.tenMon << " x" << m.soLuong << " = " << (m.gia * m.soLuong) << " VND\n";
    }
    os << "Tổng: " << tinhTongTien() << " VND";
    return os.str();
}

double Ban::tinhTongTien() const {
    double tong = 0;
    for (const auto& m : donHang_) {
        tong += m.gia * m.soLuong;
    }
    return tong;
}

void Ban::thanhToan() {
    donHang_.clear();
    soLuongKhach_ = 0;
    maNhanVienPhucVu_.clear();
    trangThai_ = "Trống";
}

// ===== Xuất JSON =====
std::string Ban::toJSON() const {
    std::ostringstream os;
    os << "{"
       << "\"maBan\":\"" << maBan_ << "\","
       << "\"trangThai\":\"" << trangThai_ << "\","
       << "\"soLuongKhach\":" << soLuongKhach_ << ","
       << "\"maNhanVienPhucVu\":\"" << maNhanVienPhucVu_ << "\","
       << "\"donHang\":[";
    for (size_t i = 0; i < donHang_.size(); ++i) {
        const auto& m = donHang_[i];
        os << "{"
           << "\"tenMon\":\"" << m.tenMon << "\","
           << "\"gia\":" << m.gia << ","
           << "\"soLuong\":" << m.soLuong
           << "}";
        if (i + 1 < donHang_.size()) os << ",";
    }
    os << "]}";
    return os.str();
}
