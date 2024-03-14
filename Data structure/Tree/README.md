# Tree

## 1. Lý thuyết về cây nhị phân

Tree là một cấu trúc dữ liệu tương tự như một linked list nhưng thay vì mỗi node chỉ đơn giản chỉ đến node tiếp theo theo kiểu tuyến tính, ở tree mỗi node trỏ đến một số node khác. Tree là một ví dụ về cấu trúc dữ liệu phi tuyến. Cấu trúc cây là một cách thể hiện bản chất thứ bậc của cấu trúc dưới dạng đồ họa.

## 2. Các thuật ngữ sử dụng trong cấu trúc Cây

- Root: Node tổ tiên của cây. Là Node mà không có cha
- Child: Là Node con của một Node cụ thể nào đó
- Parent: Ngược lại của Child
- Siblings: Các Node có cùng một cha
- Descendant: Node có thể truy cập bằng cách duyệt từ cha tới con
- Ancestor: Node có thể truy cập bằng cách duyệt từ con đến cha
- Leaf: Node không có Child
- Internal node: Node có ít nhất 1 Child
- External node: Node không có Child

![alt](1.png)
- Một edge(cạnh) đề cập đến liên kết từ cha đến con (tất cả các liên kết trong hình).
- Root của cây là node không có bố mẹ. Có thể có nhiều nhất một node gốc trong một cây (node A trong ví dụ trên).
- Một edge(cạnh) đề cập đến liên kết từ cha đến con (tất cả các liên kết trong hình).
- Một node không có node con được gọi là leaf node (E, J, K, H và I).
- Những node con có cùng node cha được gọi là siblings(anh chị em ruột - B, C, D là siblings của A và E, F là anh chị em của B).
- Một node p là ancestor(tổ tiên) của node q nếu tồn tại một đường đi từ gốc đến q và p xuất hiện trên đường đi. Node q được gọi là descendant(con cháu) của p. Ví dụ, A, C và G là tổ tiên của K.
- Tập hợp tất cả các node ở một độ sâu nhất định được gọi là level của cây (B, C và D là cùng một mức). Nút Root ở mức không.
- Độ sâu của node là độ dài của đường đi từ gốc đến node (độ sâu của G là 2, A - C - G).
- Chiều cao của một node là độ dài của đường đi từ nút đó đến nút sâu nhất. Chiều cao của cây là chiều dài của đường đi từ root đến node sâu nhất trong cây. Một cây chỉ có một node (gốc) có chiều cao bằng không. Trong ví dụ trước, chiều cao của B là 2 (B - F - J).
- Chiều cao của cây là chiều cao lớn nhất trong số tất cả các nút trong cây và chiều sâu của cây là chiều sâu lớn nhất trong số tất cả các nút trong cây. Đối với một cây nhất định, chiều sâu và chiều cao trả về cùng một giá trị. Nhưng đối với các node riêng lẻ, chúng ta có thể nhận được các kết quả khác nhau.
![alt](2.png)
- Kích thước của một node là số lượng nút con mà nó có bao gồm cả chính nó (kích thước của cây con C là 3).
- Nếu mọi node trong cây chỉ có một node con (trừ các nút lá) thì ta gọi các cây như vậy là cây xiên(skew trees). Nếu mọi node chỉ có con trái thì chúng ta gọi chúng là cây xiên trái(left skew trees). Tương tự, nếu mọi node chỉ có con bên phải thì chúng ta gọi chúng là cây xiên bên phải(right skew trees).
![alt](3.png)

## 3. Binary Trees

Một cây được gọi là cây nhị phân(binary tree) nếu mỗi nút không có con nào, một con hoặc hai con. Cây rỗng cũng là một cây nhị phân hợp lệ. Chúng ta có thể hình dung cây nhị phân bao gồm một gốc và hai cây nhị phân rời rạc, được gọi là cây con trái và phải của gốc.

Cây nhị phân là một cấu trúc bao gồm các Node, trong đó mỗi Node bao gồm 3 thành phần sau:

- Data element: Lưu giữ giá trị 1 phần tử với kiểu dữ liệu bất kỳ
- Left pointer: Con trỏ trỏ tới cây nhị phân bên trái của Node
- Right pointer: Con trỏ trỏ tới cây nhị phân bên phải của Node


## 4. Cây tìm kiếm nhị phân(TA: Binary Search Tree – viết tắt: BST) – là một cây nhị phân và có thêm các ràng buộc sau đây:

- Giá trị của tất cả các Node ở cây con bên trái phải <= giá trị của Node gốc.
- Giá trị của tất cả các Node ở cây con bên phải phải > giá trị của Node gốc.
- Tất cả các cây con(bao gồm bên trái và phải) cũng đều phải đảm bảo 2 tính chất trên.

Cây tìm kiếm nhị phân là một cấu trúc dữ liệu hiệu quả cho phép chúng ta xây dựng nên một danh sách mà dữ liệu trên đó được sắp xếp:

Nó được gọi là cây nhị phân vì mỗi Node của cây chỉ có tối đa hai con
Nó được gọi là cây tìm kiếm nhị phân vì nó có thể được sử dụng để tìm kiếm sự hiện diện của một phần tử trong thời gian O(log (n)).

2. Tìm kiếm trên BST
Việc tìm kiếm cũng tương tự như việc thêm phần tử vào BST. Ta có quy trình như sau:

Nếu Node hiện tại có giá trị = giá trị cần tìm, trả về true và kết thúc.
Nếu Node hiện tại có giá trị > giá trị cần tìm, gọi đệ quy tìm ở cây con bên trái.
Nếu Node hiện tại có giá trị < giá trị cần tìm, gọi đệ quy tìm ở cây con bên phải
Nếu tìm đến hết cây(Node đó = NULL) mà không xảy ra (1), trả về false và kết thúc.

2.1 Lấy giá trị con trái nhất
Rất đơi giản, duyệt theo con trỏ trỏ đến cây con bên trái tới chừng nào không còn con bên trái nữa thì đó là con trái nhất rồi.

Hàm này sẽ được chúng ta sử dụng trong việc xóa một Node có giá trị chỉ định trên BST ở mục tiếp theo

3. Duyệt cây tìm kiếm nhị phân

Ở mục này mình sẽ trình bày về 3 cách duyệt cây tìm kiếm nhị phân. Chúng ta sẽ đi vào chi tiết từng cách nhé. Thứ tự duyệt được đặt tên phụ thuộc vào vị trí của Node root trong quá trình duyệt:

PreOrder: Node -> Left -> Right
InOrder: Left -> Node -> Right
PostOrder: Left -> Right -> Node
Thực ra 3 phần tử Left, Right, Node có tất cả 6 hoán vị cơ. Còn 3 cái nữa các bạn tự cài nhé.