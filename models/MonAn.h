#ifndef MONAN_H
#define MONAN_H
#include <string>
using namespace std;

class MonAn {
private:
    string maMon_{};        // Mã định danh món ăn
    string tenMon_{};       // Tên hiển thị
    string loaiMon_{};      // Loại (đồ ăn, nước uống, combo,...)
    double gia_{};          // Giá tiền
    bool conBan_{true};     // Trạng thái còn bán hay ngừng bán

public:
    // Hàm dựng / hủy
    MonAn() = default;
    virtual ~MonAn() = default;

    MonAn(string ma, string ten, string loai, double gia, bool conBan = true)
        : maMon_(move(ma)), tenMon_(move(ten)), loaiMon_(move(loai)),
          gia_(gia), conBan_(conBan) {}

    // Getter / Setter
    const string& getMaMon() const { return maMon_; }
    void setMaMon(const string& ma) { maMon_ = ma; }

    const string& getTenMon() const { return tenMon_; }
    void setTenMon(const string& ten) { tenMon_ = ten; }

    const string& getLoaiMon() const { return loaiMon_; }
    void setLoaiMon(const string& loai) { loaiMon_ = loai; }

    double getGia() const { return gia_; }
    void setGia(double gia) { gia_ = gia; }

    bool getConBan() const { return conBan_; }
    void setConBan(bool trangThai) { conBan_ = trangThai; }
};
#endif
