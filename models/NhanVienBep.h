#ifndef NHANVIENBEP_H
#define NHANVIENBEP_H

#include "User.h"
#include <string>
#include <vector>
#include <sstream>

struct DonBep {
    std::string maDon;
    std::vector<std::string> danhSachMon;
    std::string trangThai; // "Chờ nấu", "Đang nấu", "Hoàn thành"
};

class NhanVienBep : public User {
private:
    std::string maBep_;
    std::string caLam_;
    double luong_{};
    bool trangThaiLamViec_{false};

    std::vector<DonBep> danhSachDonDangNau_;

public:
    // ===== Constructor & Destructor =====
    NhanVienBep() = default;
    NhanVienBep(std::string ma, std::string ten, std::string sdt, std::string gt,
                std::string ca, double luong);
    virtual ~NhanVienBep() = default;

    // ===== Getter / Setter =====
    const std::string& getMaBep() const;
    void setMaBep(const std::string& ma);

    const std::string& getCaLam() const;
    void setCaLam(const std::string& ca);

    double getLuong() const;
    void setLuong(double luong);

    bool getTrangThaiLamViec() const;
    void setTrangThaiLamViec(bool trangThai);

    // ===== Nghiệp vụ =====
    void batDauCa();
    void ketThucCa();

    void nhanOrder(const DonBep& don);
    void batDauNau(const std::string& maDon);
    void hoanThanhMon(const std::string& maDon);

    std::string xemDanhSachDon() const;
    std::string toJSON() const;
    std::string getRole() const;
};

#endif
