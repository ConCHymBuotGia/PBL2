#ifndef PHUCVU_H
#define PHUCVU_H

#include "User.h"
#include <string>
#include <vector>
#include <sstream>

struct DonHang {
    std::string maDon;
    std::string tenKhach;
    std::vector<std::string> danhSachMon;
    std::string trangThai; // "Đang chuẩn bị", "Hoàn tất", "Đã phục vụ"
};

class PhucVu : public User {
private:
    std::string maPhucVu_;
    std::string caLam_;
    double luong_{};
    bool trangThaiLamViec_{false};

    std::vector<DonHang> danhSachDonPhuTrach_;

public:
    // ===== Constructor =====
    PhucVu() = default;
    PhucVu(std::string ma, std::string ten, std::string sdt, std::string gt,
           std::string ca, double luong);

    // ===== Getter / Setter =====
    const std::string& getMaPhucVu() const;
    void setMaPhucVu(const std::string& ma);

    const std::string& getCaLam() const;
    void setCaLam(const std::string& ca);

    double getLuong() const;
    void setLuong(double luong);

    bool getTrangThaiLamViec() const;
    void setTrangThaiLamViec(bool trangThai);

    // ===== Nghiệp vụ =====
    void batDauCa();
    void ketThucCa();

    void nhanOrder(const DonHang& don);
    void guiOrderToBep(const std::string& maDon);
    void nhanMon(const std::string& maDon);
    void phucVuKhach(const std::string& maDon);
    void thanhToan(const std::string& maDon);

    std::string xemDanhSachDon() const;
    std::string toJSON() const;
    std::string getRole() const;
};

#endif
