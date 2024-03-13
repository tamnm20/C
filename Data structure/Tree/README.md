# Tree

## 1. Lý thuyết về cây nhị phân

Cây nhị phân là một cấu trúc bao gồm các Node, trong đó mỗi Node bao gồm 3 thành phần sau:

- Data element: Lưu giữ giá trị 1 phần tử với kiểu dữ liệu bất kỳ
- Left pointer: Con trỏ trỏ tới cây nhị phân bên trái của Node
- Right pointer: Con trỏ trỏ tới cây nhị phân bên phải của Node

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
