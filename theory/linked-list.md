Một Danh sách liên kết (Linked List) là một dãy các cấu trúc dữ liệu được kết nối với nhau thông qua các liên kết (link). Hiểu một cách đơn giản thì Danh sách liên kết là một cấu trúc dữ liệu bao gồm một nhóm các nút (node) tạo thành một chuỗi. Mỗi nút gồm dữ liệu ở nút đó và tham chiếu đến nút kế tiếp trong chuỗi.

Link (liên kết): mỗi link của một Danh sách liên kết có thể lưu giữ một dữ liệu được gọi là một phần tử.

Next: Mỗi liên kết của một Danh sách liên kết chứa một link tới next link được gọi là Next.

First: một Danh sách liên kết bao gồm các link kết nối tới first link được gọi là First.

Danh sách liên kết đơn (Simple Linked List): chỉ duyệt các phần tử theo chiều về trước.

Danh sách liên kết đôi (Doubly Linked List): các phần tử có thể được duyệt theo chiều về trước hoặc về sau.

Danh sách liên kết vòng (Circular Linked List): phần tử cuối cùng chứa link của phần tử đầu tiên như là next và phần tử đầu tiên có link tới phần tử cuối cùng như là prev.

https://topdev.vn/blog/danh-sach-lien-ket-don-trong-c/

-   Là một danh sách chứa các node tạo thành nhóm các node liên kết với nhau, mỗi node có dữ liệu và tham số trỏ đến node tiếp theo
-   Singly linked list danh sách liên kết một chiều
    vd muốn duyệt node cuối thì phải bắt đầu từ node đầu tiên cho đến cuối
