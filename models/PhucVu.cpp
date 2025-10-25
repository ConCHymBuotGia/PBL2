#include "PhucVu.h"
#include <sstream>
#include <utility>

// ===== Constructor =====
PhucVu::PhucVu(std::string ma, std::string ten, std::string sdt, std::string gt,
               std::string ca, double luong)
    : User(std::move(ten), std::move(sdt), std::move(gt)),
      maPhucVu_(std::move(ma)), caLam_(std::move(ca)), luong_(luong) {}

// ===== Getter / Setter =====
const std::string& PhucVu::getMaPhucVu() const { return maPhucVu_; }
void PhucVu::setMaPhucVu(const std::string& ma) { maPhucVu_ = ma; }

const std::string& PhucVu::getCaLam() const { return caLam_; }
void PhucVu::setCaLam(const std::string& ca) { caLam_ = ca; }

double PhucVu::getLuong() const { return luong_; }
void PhucVu::setLuong(double luong) { luong_ = luong; }

bool PhucVu::getTrangThaiLamViec() const { return trangThaiLamViec_; }
void PhucVu::setTrangThaiLamViec(bool trangThai) { trangThaiLamViec_ = trangThai; }

// ===== Nghiệp vụ =====
void PhucVu::batDauCa() { trangThaiLamViec_ = true; }
void PhucVu::ketThucCa() { trangThaiLamViec_ = false; }

void PhucVu::nhanOrder(const DonHang& don) {
    danhSachDonPhuTrach_.push_back(don);
}

void PhucVu::guiOrderToBep(const std::string& maDon) {
    for (auto& don : danhSachDonPhuTrach_) {
        if (don.maDon == maDon) {
            don.trangThai = "Đang chuẩn bị";
            break;
        }
    }
}

void PhucVu::nhanMon(const std::string& maDon) {
    for (auto& don : danhSachDonPhuTrach_) {
        if (don.maDon == maDon) {
            don.trangThai = "Hoàn tất";
            break;
        }
    }
}

void PhucVu::phucVuKhach(const std::string& maDon) {
    for (auto& don : danhSachDonPhuTrach_) {
        if (don.maDon == maDon) {
            don.trangThai = "Đã phục vụ";
            break;
        }
    }
}

void PhucVu::thanhToan(const std::string& maDon) {
    for (auto it = danhSachDonPhuTrach_.begin(); it != danhSachDonPhuTrach_.end(); ++it) {
        if (it->maDon == maDon) {
            danhSachDonPhuTrach_.erase(it);
            break;
        }
    }
}

// ===== Xem danh sách đơn hàng =====
std::string PhucVu::xemDanhSachDon() const {
    std::ostringstream os;
    os << "Danh sach don phuc vu (" << danhSachDonPhuTrach_.size() << "):\n";
    for (const auto& don : danhSachDonPhuTrach_) {
        os << "- Don #" << don.maDon << " (" << don.trangThai << ") - Khach: " << don.tenKhach << "\n";
    }
    return os.str();
}

// ===== Xuất JSON =====
std::string PhucVu::toJSON() const {
    std::ostringstream os;
    os << "{"
       << "\"maPhucVu\":\"" << maPhucVu_ << "\","
       << "\"hoTen\":\"" << hoTen_ << "\","
       << "\"sdt\":\"" << sdt_ << "\","
       << "\"gioiTinh\":\"" << gioiTinh_ << "\","
       << "\"caLam\":\"" << caLam_ << "\","
       << "\"luong\":" << luong_ << ","
       << "\"trangThaiLamViec\":" << (trangThaiLamViec_ ? "true" : "false") << ",";
    os << "\"donHang\":[";
    for (size_t i = 0; i < danhSachDonPhuTrach_.size(); ++i) {
        const auto& d = danhSachDonPhuTrach_[i];
        os << "{"
           << "\"maDon\":\"" << d.maDon << "\","
           << "\"tenKhach\":\"" << d.tenKhach << "\","
           << "\"trangThai\":\"" << d.trangThai << "\""
           << "}";
        if (i + 1 < danhSachDonPhuTrach_.size()) os << ",";
    }
    os << "]}";
    return os.str();
}

// ===== Loại người dùng =====
std::string PhucVu::getRole() const { return "Phuc vu"; }
