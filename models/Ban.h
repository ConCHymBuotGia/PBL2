#ifndef BAN_H
#define BAN_H
#include <string>
using namespace std;

class Ban {
private:
    string maBan_{};         // Mã bàn (ví dụ: B01, B02)
    int sucChua_{0};         // Số lượng khách tối đa
    bool dangPhucVu_{false}; // true nếu đang có khách
    string khuVuc_{};        // Khu vực (A, B, ngoài trời, tầng 2,...)

public:
    // Hàm dựng / hủy
    Ban() = default;
    virtual ~Ban() = default;

    Ban(string ma, int sucChua, string khuVuc = "A", bool phucVu = false)
        : maBan_(move(ma)), sucChua_(sucChua),
          dangPhucVu_(phucVu), khuVuc_(move(khuVuc)) {}

    // Getter / Setter
    const string& getMaBan() const { return maBan_; }
    void setMaBan(const string& ma) { maBan_ = ma; }

    int getSucChua() const { return sucChua_; }
    void setSucChua(int sc) { sucChua_ = sc; }

    bool getDangPhucVu() const { return dangPhucVu_; }
    void setDangPhucVu(bool tt) { dangPhucVu_ = tt; }

    const string& getKhuVuc() const { return khuVuc_; }
    void setKhuVuc(const string& kv) { khuVuc_ = kv; }
};
#endif
