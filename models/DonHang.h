#ifndef DONHANG_H
#define DONHANG_H

#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <ctime>

struct MonGoi {
    std::string tenMon;
    double gia;
    int soLuong;
};

class DonHang {
private:
    std::string maDonHang_;
    std::string maBan_;
    std::string maNhanVien_;
    std::string trangThai_;            // "Chờ xử lý", "Đang chế biến", "Hoàn tất", "Đã thanh toán"
    std::string thoiGianTao_;
    std::string thoiGianCapNhat_;
    std::vector<MonGoi> danhSachMon_;

    std::string getCurrentTime() const;

public:
    // ===== Constructor =====
    DonHang() = default;
    DonHang(std::string maDon, std::string maBan, std::string maNV);

    // ===== Getter / Setter =====
    const std::string& getMaDonHang() const;
    const std::string& getMaBan() const;
    const std::string& getMaNhanVien() const;
    const std::string& getTrangThai() const;
    const std::vector<MonGoi>& getDanhSachMon() const;

    void setTrangThai(const std::string& tt);

    // ===== Nghiệp vụ =====
    void themMon(const MonGoi& mon);
    void xoaMon(const std::string& tenMon);
    void capNhatMon(const std::string& tenMon, int soLuong);
    double tinhTongTien() const;
    void capNhatTrangThai(const std::string& tt);
    std::string xemChiTiet() const;
    std::string toJSON() const;
};

#endif
