Giải thuật (hay còn gọi là thuật toán - tiếng Anh là Algorithms) là một tập hợp hữu hạn các chỉ thị để được thực thi theo một thứ tự nào đó để thu được kết quả mong muốn. Nói chung thì giải thuật là độc lập với các ngôn ngữ lập trình, tức là một giải thuật có thể được triển khai trong nhiều ngôn ngữ lập trình khác nhau.

Dưới đây là một số giải thuật quan trọng:

Giải thuật Tìm kiếm: Giải thuật để tìm kiếm một phần tử trong một cấu trúc dữ liệu.

Giải thuật Sắp xếp: Giải thuật để sắp xếp các phần tử theo thứ tự nào đó.

Giải thuật Chèn: Giải thuật để chèn phần từ vào trong một cấu trúc dữ liệu.

Giải thuật Cập nhật: Giải thuật để cập nhật (hay update) một phần tử đã tồn tại trong một cấu trúc dữ liệu.

Giải thuật Xóa: Giải thuật để xóa một phần tử đang tồn tại từ một cấu trúc dữ liệu.

Phân tích tiệm cận trong Cấu trúc dữ liệu và Giải thuật

=> Phân tích thời gian chạy để đánh giá một thuật toán
=> Ước lượng thời gian chạy trong các bước tính toán
Ví dụ, thời gian chạy của một phép tính nào đó được ước lượng là một hàm f(n) và với một phép tính khác là hàm g(n2). Điều này có nghĩa là thời gian chạy của phép tính đầu tiên sẽ tăng tuyến tính với sự tăng lên của n và thời gian chạy của phép tính thứ hai sẽ tăng theo hàm mũ khi n tăng lên. Tương tự, khi n là khá nhỏ thì thời gian chạy của hai phép tính là gần như nhau.

3 Loại
Tốt, Trung Bình, Xấu nhất

Big Oh Notation, Ο trong Cấu trúc dữ liệu và giải thuật

-   Biểu thị độ phức tạp của thuật toán trong trường hợp xấu nhất (tiệm cận trên)
    `Ο(f(n)) = { g(n) : nếu tồn tại c > 0 và n0 sao cho g(n) ≤ c.f(n) với mọi n > n0. }`

Omega Notation Ω(n)

-   Biểu thị độ phức tạp của thuật toán trong trường hợp tốt nhất(tiệm cận dưới)
    `Ω(f(n)) ≥ { g(n) : nếu tồn tại c > 0 và n0 sao cho g(n) ≤ c.f(n) với mọi n > n0. }`

Theta Notation, θ trong Cấu trúc dữ liệu và giải thuật

The θ(n) là cách để biểu diễn cả tiệm cận trên và tiệm cận dưới của thời gian chạy của một giải thuật.

Giải thuật tham lam (Greedy Algorithm)

-   Tham lam (hay tham ăn) là một trong những phương pháp phổ biến nhất để thiết kế giải thuật. Nếu bạn đã đọc truyện dân gian thì sẽ có câu chuyện như thế này: trên một mâm cỗ có nhiều món ăn, món nào ngon nhất ta sẽ ăn trước, ăn hết món đó ta sẽ chuyển sang món ngon thứ hai, và chuyển tiếp sang món thứ ba, …

Giải thuật chia để trị (divide and conquer)

Phương pháp chia để trị (Divide and Conquer) là một phương pháp quan trọng trong việc thiết kế các giải thuật.

Ý tưởng của phương pháp này khá đơn giản và rất dễ hiểu: Khi cần giải quyết một bài toán,ta sẽ tiến hành chia bài toán đó thành các bài toán con nhỏ hơn. Tiếp tục chia cho đến khicác bài toán nhỏ này không thể chia thêm nữa, khi đó ta sẽ giải quyết các bài toán nhỏ nhấtnày và cuối cùng kết hợp giải pháp của tất cả các bài toán nhỏ để tìm ra giải pháp của bàitoán ban đầu.

Giải thuật Qui hoạch động (Dynamic Programming) là gì ?
=> Overlapping Sub-problems

Giải thuật chia để trị (Divide and Conquer) là kết hợp lời giải của các bài toán con để tìm ra lời giải của bài toán ban đầu.

Giải thuật Qui hoạch động sử dụng kết quả của bài toán con và sau đó cố gắng tối ưu bài toán lớn hơn. Giải thuật Qui hoạch động sử dụng phương pháp lưu trữ (Memoization) để ghi nhớ kết quả của các bài toán con đã được giải.

Ví dụ giải thuật Qui hoạch động
Dưới đây là một số bài toán có thể được giải bởi sử dụng giải thuật Qui hoạch động:

Dãy Fibonacci
Bài toán tháp Hà Nội (Tower of Hanoi)
Bài toán ba lô

Giải thuật Qui hoạch động có thể được sử dụng trong cả hai phương pháp Phân tích (Top-down) và Qui nạp (Bottom-up).

Giải thuật Định lý thợ (Master Theorem) là gì ?

Chúng ta sử dụng Định lý thợ (Master Theorem) để giải các công thức đệ quy dạng sau một cách hiệu quả :
