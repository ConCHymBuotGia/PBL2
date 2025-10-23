#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User {
    //Cac Thuoc Tinh cua Doi Tuong
    protected:
    string hoTen_{};
    string sdt_{};
    string gioiTinh_{};
    public:
    // Cac ham dung, huy
    User() = default;
    virtual ~User() = default;
     User(string ten, string sdt, string gt)
        : hoTen_(move(ten)), sdt_(move(sdt)), gioiTinh_(move(gt)) {}
    // Su dung cac getter de qua ben UI de in ra hon
    const string& getHoTen() const { return hoTen_; }
    void setHoTen(const string& hoTen) { hoTen_ = hoTen; }
    const string& getSdt() const { return sdt_; }
    void setSdt(const string& sdt) { sdt_ = sdt; }
    const string& getGioiTinh() const { return gioiTinh_; }
    void setGioiTinh(const string& gioiTinh) { gioiTinh_ = gioiTinh; }

};
#endif