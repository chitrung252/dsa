Cấu trúc dữ liệu mảng là gì ?

Mảng (Array) là một trong các cấu trúc dữ liệu cũ và quan trọng nhất. Mảng có thể lưu giữ một số phần tử cố định và các phần tử này nền có cùng kiểu. Hầu hết các cấu trúc dữ liệu đều sử dụng mảng để triển khai giải thuật. Dưới đây là các khái niệm quan trọng liên quan tới Mảng.

Ưu điểm của mảng :
Truy câp phàn tử vơi thời gian hằng số O(1)
Sử dụng bộ nhớ hiệu quả
Tính cục bộ về bộ nhớ

Nhược điểm
Không thể thay đổi kích thước của mảng khi chương trình dang thực hiện

Mảng động
Mảng động (dynamic aray) : cấp phát bộ nhớ cho mảng một cách động trong quá trình chạy chương trình trong C là malloc và calloc, trong C++ là new

Sử dụng mảng động ta bắt đầu với mảng có 1 phàn tử, khi số lượng phàn tử vượt qua khả năng của ảng thì ta gấp đôi kích thước mảng cuc và copy phàn tử mảng cũ vào nửa đầu của mảng mới

Ưu điểm : tránh lãng phí bộ nhớ khi phải khai báo mảng có kích thước lớn ngay từ đầu

Nhược điểm: + phải thực hiện them thao tác copy phần tử mỗi khi thay đổi kích thước. + một số thời gian thực hiện thao tác không còn là hằng số nữa
