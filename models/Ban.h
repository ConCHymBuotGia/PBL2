#ifndef BAN_H
#define BAN_H

#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

struct MonGoi {
    std::string tenMon;
    double gia;
    int soLuong;
};

class Ban {
private:
    std::string maBan_;
    int soLuongKhach_{0};
    std::string trangThai_;          // "Trống", "Đang phục vụ", "Đã thanh toán"
    std::string maNhanVienPhucVu_;
    std::vector<MonGoi> donHang_;

public:
    // ===== Constructor =====
    Ban() = default;
    Ban(std::string maBan, std::string trangThai = "Trống");

    // ===== Getter & Setter =====
    const std::string& getMaBan() const;
    void setMaBan(const std::string& maBan);

    const std::string& getTrangThai() const;
    void setTrangThai(const std::string& tt);

    int getSoLuongKhach() const;
    void setSoLuongKhach(int soLuong);

    const std::string& getMaNhanVienPhucVu() const;
    void setMaNhanVienPhucVu(const std::string& maNV);

    const std::vector<MonGoi>& getDonHang() const;

    // ===== Nghiệp vụ =====
    void datBan(int soLuong, const std::string& maNhanVien);
    void themMon(const MonGoi& mon);
    std::string xemDonHang() const;
    double tinhTongTien() const;
    void thanhToan();
    std::string toJSON() const;
};

#endif
