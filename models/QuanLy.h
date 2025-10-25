#ifndef QUANLI_H
#define QUANLI_H

#include "User.h"
#include "NhanSu.h"
#include "PhucVu.h"
#include "NhanVienBep.h"
#include <vector>
#include <string>
#include <sstream>
#include <optional>

struct MonAn {
    std::string tenMon;
    double gia;
};

class QuanLi : public User {
private:
    std::string maQuanLi_;
    double luong_{};
    std::vector<NhanSu> danhSachNhanSu_;
    std::vector<MonAn> menu_;
    double doanhThu_{};

public:
    // ===== Constructor & Destructor =====
    QuanLi() = default;
    QuanLi(std::string ma, std::string ten, std::string sdt, std::string gt, double luong);
    virtual ~QuanLi() = default;

    // ===== Getter / Setter =====
    const std::string& getMaQuanLi() const;
    void setMaQuanLi(const std::string& ma);

    double getLuong() const;
    void setLuong(double luong);

    double getDoanhThu() const;
    void setDoanhThu(double doanhThu);

    // ===== Nghiệp vụ quản lý nhân sự =====
    void themNhanSu(const NhanSu& ns);
    void xoaNhanSu(const std::string& maNhanVien);
    std::optional<NhanSu> timNhanSu(const std::string& maNhanVien) const;
    std::string xemDanhSachNhanSu() const;

    // ===== Quản lý menu =====
    void themMonAn(const MonAn& mon);
    void xoaMonAn(const std::string& tenMon);
    std::string xemMenu() const;

    // ===== Doanh thu =====
    void congDoanhThu(double soTien);
    void resetDoanhThu();

    // ===== Xuất dữ liệu =====
    std::string toJSON() const;
    std::string getRole() const;
};

#endif
