#include "NhanVienBep.h"
#include <sstream>
#include <utility>

// ===== Constructor =====
NhanVienBep::NhanVienBep(std::string ma, std::string ten, std::string sdt, std::string gt,
                         std::string ca, double luong)
    : User(std::move(ten), std::move(sdt), std::move(gt)),
      maBep_(std::move(ma)), caLam_(std::move(ca)), luong_(luong) {}

// ===== Getter & Setter =====
const std::string& NhanVienBep::getMaBep() const { return maBep_; }
void NhanVienBep::setMaBep(const std::string& ma) { maBep_ = ma; }

const std::string& NhanVienBep::getCaLam() const { return caLam_; }
void NhanVienBep::setCaLam(const std::string& ca) { caLam_ = ca; }

double NhanVienBep::getLuong() const { return luong_; }
void NhanVienBep::setLuong(double luong) { luong_ = luong; }

bool NhanVienBep::getTrangThaiLamViec() const { return trangThaiLamViec_; }
void NhanVienBep::setTrangThaiLamViec(bool trangThai) { trangThaiLamViec_ = trangThai; }

// ===== Nghiệp vụ =====
void NhanVienBep::batDauCa() { trangThaiLamViec_ = true; }
void NhanVienBep::ketThucCa() { trangThaiLamViec_ = false; }

void NhanVienBep::nhanOrder(const DonBep& don) {
    danhSachDonDangNau_.push_back(don);
}

void NhanVienBep::batDauNau(const std::string& maDon) {
    for (auto& don : danhSachDonDangNau_) {
        if (don.maDon == maDon) {
            don.trangThai = "Đang nấu";
            break;
        }
    }
}

void NhanVienBep::hoanThanhMon(const std::string& maDon) {
    for (auto& don : danhSachDonDangNau_) {
        if (don.maDon == maDon) {
            don.trangThai = "Hoàn thành";
            break;
        }
    }
}

// ===== Hiển thị danh sách đơn =====
std::string NhanVienBep::xemDanhSachDon() const {
    std::ostringstream os;
    os << "Don hang trong bep (" << danhSachDonDangNau_.size() << "):\n";
    for (const auto& don : danhSachDonDangNau_) {
        os << "- Don #" << don.maDon << " (" << don.trangThai << ")\n";
    }
    return os.str();
}

// ===== Xuất JSON =====
std::string NhanVienBep::toJSON() const {
    std::ostringstream os;
    os << "{"
       << "\"maBep\":\"" << maBep_ << "\","
       << "\"hoTen\":\"" << hoTen_ << "\","
       << "\"sdt\":\"" << sdt_ << "\","
       << "\"gioiTinh\":\"" << gioiTinh_ << "\","
       << "\"caLam\":\"" << caLam_ << "\","
       << "\"luong\":" << luong_ << ","
       << "\"trangThaiLamViec\":" << (trangThaiLamViec_ ? "true" : "false") << ",";
    os << "\"donHang\":[";
    for (size_t i = 0; i < danhSachDonDangNau_.size(); ++i) {
        const auto& d = danhSachDonDangNau_[i];
        os << "{"
           << "\"maDon\":\"" << d.maDon << "\","
           << "\"trangThai\":\"" << d.trangThai << "\""
           << "}";
        if (i + 1 < danhSachDonDangNau_.size()) os << ",";
    }
    os << "]}";
    return os.str();
}

// ===== Vai trò =====
std::string NhanVienBep::getRole() const {
    return "Nhan vien bep";
}
