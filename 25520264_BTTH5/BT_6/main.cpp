#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include "KhachHang.h"

int main() {
    std::ifstream fileIn("XYZ.INP");
    if (!fileIn.is_open()) {
        std::cerr << "Khong the mo file XYZ.INP!" << std::endl;
        return 1;
    }

    int x, y, z;
    if (!(fileIn >> x >> y >> z)) {
        std::cerr << "File INP khong dung dinh dang!" << std::endl;
        return 1;
    }

    std::vector<KhachHang*> danhSachKhachHang;

    // 1. Đọc danh sách Khách hàng Loại A
    for (int i = 0; i < x; ++i) {
        KhachHang* kh = new KhachHangA();
        kh->docFile(fileIn);
        danhSachKhachHang.push_back(kh);
    }

    // 2. Đọc danh sách Khách hàng Loại B
    for (int i = 0; i < y; ++i) {
        KhachHang* kh = new KhachHangB();
        kh->docFile(fileIn);
        danhSachKhachHang.push_back(kh);
    }

    // 3. Đọc danh sách Khách hàng Loại C
    for (int i = 0; i < z; ++i) {
        KhachHang* kh = new KhachHangC();
        kh->docFile(fileIn);
        danhSachKhachHang.push_back(kh);
    }

    fileIn.close();

    // Mở file và ghi kết quả ra XYZ.OUT
    std::ofstream fileOut("XYZ.OUT");
    if (!fileOut.is_open()) {
        std::cerr << "Khong the mo file XYZ.OUT de ghi!" << std::endl;
        for (KhachHang* kh : danhSachKhachHang) delete kh;
        return 1;
    }

    // DÒNG ĐẦU TIÊN: Xuất thông số x y z theo đúng ảnh mẫu đề bài yêu cầu
    fileOut << x << " " << y << " " << z << "\n";

    double tongSoTienCongTyThuDuoc = 0.0;

    // Định dạng số thực không hiển thị dạng E (Ví dụ: xuất 1100000 chứ không xuất 1.1e+06)
    // Nếu đề bài yêu cầu số nguyên tròn thì để setprecision(0), còn số thập phân thì để setprecision(2)
    fileOut << std::fixed << std::setprecision(0);

    // Xuất thông tin từng khách hàng xen kẽ: Tên -> Số tiền phải trả
    for (KhachHang* kh : danhSachKhachHang) {
        double soTienPhaiTra = kh->tinhSoTienPhaiTra();
        tongSoTienCongTyThuDuoc += soTienPhaiTra;

        fileOut << kh->getTenKhachHang() << "\n";
        fileOut << soTienPhaiTra << "\n";
    }

    // DÒNG CUỐI CÙNG: Tổng số tiền công ty thu được
    fileOut << tongSoTienCongTyThuDuoc << "\n";

    fileOut.close();

    // Giải phóng bộ nhớ
    for (KhachHang* kh : danhSachKhachHang) {
        delete kh;
    }
    danhSachKhachHang.clear();

    std::cout << "Da thuc hien xong! Vui long kiem tra file XYZ.OUT." << std::endl;
    return 0;
}
