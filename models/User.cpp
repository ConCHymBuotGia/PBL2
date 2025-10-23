#include "User.h"
#include <sstream>   // để ghép chuỗi bằng ostringstream

// =============================
// Trả về thông tin người dùng dạng chuỗi
// =============================
std::string User::xemThongTin() const {
    std::ostringstream os;
    os << "===== THONG TIN NGUOI DUNG =====\n";
    os << "Ho ten        : " << hoTen_ << "\n";
    os << "So dien thoai : " << sdt_ << "\n";
    os << "Gioi tinh     : " << gioiTinh_ << "\n";
    os << "================================";
    return os.str();
}
