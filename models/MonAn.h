#ifndef MONAN_H
#define MONAN_H

#include <string>
#include <sstream>
#include <iomanip>

class MonAn {
private:
    std::string maMon_;
    std::string tenMon_;
    std::string loaiMon_;
    double gia_{};
    bool trangThai_{true};     // true = còn bán, false = ngừng bán
    int soLuongTon_{};

public:
    // ===== Constructor =====
    MonAn() = default;
    MonAn(std::string ma, std::string ten, std::string loai, double gia, int soLuong, bool trangThai = true);

    // ===== Getter / Setter =====
    const std::string& getMaMon() const;
    const std::string& getTenMon() const;
    const std::string& getLoaiMon() const;
    double getGia() const;
    bool getTrangThai() const;
    int getSoLuongTon() const;

    void setTenMon(const std::string& ten);
    void setLoaiMon(const std::string& loai);
    void setGia(double g);
    void setTrangThai(bool tt);
    void setSoLuongTon(int sl);

    // ===== Nghiệp vụ =====
    void capNhatSoLuong(int slThayDoi);   // + hoặc - số lượng
    void danhDauHetHang();
    void danhDauConHang();
    std::string xemThongTin() const;
    std::string toJSON() const;
};

#endif
