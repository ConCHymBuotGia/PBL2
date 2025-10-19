#ifndef USER_H
#define USER_H
#include <string>
#include<iostream>

class User {
    //Cac Thuoc Tinh cua Doi Tuong
    protected:
    std::string hoTen_{};
    std::string sdt_{};
    std::string gioiTinh_{};
    public:
    // Cac ham dung, huy
    User() = default;
    virtual ~User() = default;
     User(std::string ten, std::string sdt, std::string gt)
        : hoTen_(std::move(ten)), sdt_(std::move(sdt)), gioiTinh_(std::move(gt)) {}
    // Su dung cac getter de qua ben UI de in ra hon
    const std::string& getHoTen() const { return hoTen_; }
    void setHoTen(const std::string& hoTen) { hoTen_ = hoTen; }
};
#endif