#include "MonAn.h"
#include <utility>
#include <sstream>

// ===== Constructor =====
MonAn::MonAn(std::string ma, std::string ten, std::string loai, double gia, int soLuong, bool trangThai)
    : maMon_(std::move(ma)),
      tenMon_(std::move(ten)),
      loaiMon_(std::move(loai)),
      gia_(gia),
      soLuongTon_(soLuong),
      trangThai_(trangThai) {}

// ===== Getter / Setter =====
const std::string& MonAn::getMaMon() const { return maMon_; }
const std::string& MonAn::getTenMon() const { return tenMon_; }
const std::string& MonAn::getLoaiMon() const { return loaiMon_; }
double MonAn::getGia() const { return gia_; }
bool MonAn::getTrangThai() const { return trangThai_; }
int MonAn::getSoLuongTon() const { return soLuongTon_; }

void MonAn::setTenMon(const std::string& ten) { tenMon_ = ten; }
void MonAn::setLoaiMon(const std::string& loai) { loaiMon_ = loai; }
void MonAn::setGia(double g) { gia_ = g; }
void MonAn::setTrangThai(bool tt) { trangThai_ = tt; }
void MonAn::setSoLuongTon(int sl) { soLuongTon_ = sl; }

// ===== Nghiệp vụ =====
void MonAn::capNhatSoLuong(int slThayDoi) {
    soLuongTon_ += slThayDoi;
    if (soLuongTon_ <= 0) {
        soLuongTon_ = 0;
        trangThai_ = false;
    }
}

void MonAn::danhDauHetHang() {
    trangThai_ = false;
}

void MonAn::danhDauConHang() {
    trangThai_ = true;
}

// ===== Xem thông tin =====
std::string MonAn::xemThongTin() const {
    std::ostringstream os;
    os << "Mã món: " << maMon_ << "\n"
       << "Tên món: " << tenMon_ << "\n"
       << "Loại món: " << loaiMon_ << "\n"
       << "Giá: " << std::fixed << std::setprecision(0) << gia_ << " VND\n"
       << "Số lượng tồn: " << soLuongTon_ << "\n"
       << "Trạng thái: " << (trangThai_ ? "Còn bán" : "Hết hàng");
    return os.str();
}

// ===== JSON xuất ra =====
std::string MonAn::toJSON() const {
    std::ostringstream os;
    os << "{"
       << "\"maMon\":\"" << maMon_ << "\","
       << "\"tenMon\":\"" << tenMon_ << "\","
       << "\"loaiMon\":\"" << loaiMon_ << "\","
       << "\"gia\":" << gia_ << ","
       << "\"soLuongTon\":" << soLuongTon_ << ","
       << "\"trangThai\":" << (trangThai_ ? "true" : "false")
       << "}";
    return os.str();
}
