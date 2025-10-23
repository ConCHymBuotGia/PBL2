#include "KhachHang.h"
#include <iomanip>
using namespace std;

// =============================
// Trả về thông tin khách hàng (string)
// =============================
string KhachHang::xemThongTin() const {
    ostringstream os;
    os << "========== THONG TIN KHACH HANG ==========\n";
    os << "Ho ten: " << hoTen_ << "\n";
    os << "So dien thoai: " << sdt_ << "\n";
    os << "Gioi tinh: " << gioiTinh_ << "\n";
    os << "Ma khach hang: " << maKhachHang_ << "\n";
    os << "Diem tieu dung: " << diemTieuDung_ << "\n";
    os << "Hang thanh vien: " << hangThanhVien_ << "\n";
    os << "==========================================";
    return os.str();
}

// =============================
// Trả về menu món ăn (vector<string>)
// =============================
vector<string> KhachHang::getMenu() const {
    return {
        "1. Pho bo dac biet - 45.000 VND",
        "2. Com tam suon bi cha - 40.000 VND",
        "3. Bun bo Hue - 35.000 VND",
        "4. Tra sua tran chau - 30.000 VND",
        "5. Cafe den da - 25.000 VND"
    };
}

// =============================
// Tạo nội dung hóa đơn (string)
// =============================
string KhachHang::taoHoaDon(double tongTien) const {
    ostringstream os;
    os << fixed << setprecision(0);
    os << "=========== HOA DON THANH TOAN ===========\n";
    os << "Tong tien: " << tongTien << " VND\n";
    os << "Diem tieu dung hien co: " << diemTieuDung_ << "\n";
    os << "So tien phai thanh toan: " << tongTien << " VND\n";
    os << "==========================================\n";
    os << "Cam on quy khach da su dung dich vu!";
    return os.str();
}
