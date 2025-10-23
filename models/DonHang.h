#ifndef DONHANG_H
#define DONHANG_H
#include <string>
#include <vector>
using namespace std;

// Món trong đơn hàng
struct MonTrongDon {
    string maMon_{};     // ID món
    int soLuong_{0};     // Số lượng
    double donGia_{0};   // Giá tại thời điểm đặt
    double thanhTien_{0}; // = soLuong * donGia

    MonTrongDon() = default;
    MonTrongDon(string ma, int sl, double gia)
        : maMon_(move(ma)), soLuong_(sl),
          donGia_(gia), thanhTien_(sl * gia) {}
};

// Đơn hàng chính
class DonHang {
private:
    string maDon_{};                 // Mã đơn hàng
    string maBan_{};                 // Mã bàn
    string maKhachHang_{};           // Nếu có
    vector<MonTrongDon> danhSachMon_{}; // Danh sách món
    bool daDong_{false};             // Đơn đã thanh toán chưa

public:
    // Hàm dựng / hủy
    DonHang() = default;
    virtual ~DonHang() = default;

    DonHang(string maDon, string maBan)
        : maDon_(move(maDon)), maBan_(move(maBan)) {}

    // Getter / Setter
    const string& getMaDon() const { return maDon_; }
    void setMaDon(const string& ma) { maDon_ = ma; }

    const string& getMaBan() const { return maBan_; }
    void setMaBan(const string& ma) { maBan_ = ma; }

    const string& getMaKhachHang() const { return maKhachHang_; }
    void setMaKhachHang(const string& maKH) { maKhachHang_ = maKH; }

    bool getDaDong() const { return daDong_; }
    void setDaDong(bool dong) { daDong_ = dong; }

    const vector<MonTrongDon>& getDanhSachMon() const { return danhSachMon_; }

    // Thêm món vào đơn
    void themMon(const string& maMon, int soLuong, double donGia) {
        danhSachMon_.emplace_back(maMon, soLuong, donGia);
    }

    // Tính tổng tiền
    double tinhTongTien() const {
        double tong = 0;
        for (const auto& m : danhSachMon_)
            tong += m.thanhTien_;
        return tong;
    }

    // Xóa món
    void xoaMon(const string& maMon) {
        danhSachMon_.erase(
            remove_if(danhSachMon_.begin(), danhSachMon_.end(),
                      [&](const MonTrongDon& m) { return m.maMon_ == maMon; }),
            danhSachMon_.end());
    }
};
#endif
