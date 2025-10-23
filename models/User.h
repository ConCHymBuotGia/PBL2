#ifndef USER_H
#define USER_H

#include <string>
#include <sstream>   // dùng cho ostringstream

class User {
protected:
    std::string hoTen_{};
    std::string sdt_{};
    std::string gioiTinh_{};

public:
    // ===== Constructor & Destructor =====
    User() = default;
    virtual ~User() = default;

    User(std::string ten, std::string sdt, std::string gt)
        : hoTen_(std::move(ten)), sdt_(std::move(sdt)), gioiTinh_(std::move(gt)) {}

    // ===== Getter & Setter =====
    const std::string& getHoTen() const { return hoTen_; }
    void setHoTen(const std::string& hoTen) { hoTen_ = hoTen; }

    const std::string& getSdt() const { return sdt_; }
    void setSdt(const std::string& sdt) { sdt_ = sdt; }

    const std::string& getGioiTinh() const { return gioiTinh_; }
    void setGioiTinh(const std::string& gt) { gioiTinh_ = gt; }

    // ===== Hàm ảo trả về thông tin dưới dạng chuỗi =====
    // -> để UI hoặc console đều có thể sử dụng dễ dàng
    virtual std::string xemThongTin() const {
        std::ostringstream os;
        os << "Ho ten: " << hoTen_ << "\n";
        os << "So dien thoai: " << sdt_ << "\n";
        os << "Gioi tinh: " << gioiTinh_;
        return os.str();
    }
};

#endif
