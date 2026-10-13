# Cây nhị phân liên kết (Linked Binary Tree) – Lab 3

## 1. Giới thiệu

Chương trình cài đặt cây nhị phân bằng **cấu trúc liên kết (Linked Binary Tree)** trong C++.

Mỗi nút được cấp phát động và liên kết với nút con trái, nút con phải thông qua con trỏ. Chương trình hỗ trợ nhập cây, tạo cây mẫu, duyệt cây, tìm kiếm nút, tìm đường đi, tính chiều cao, đếm lá và chạy cây quyết định.

## 2. Cấu trúc dữ liệu

### 2.1. Cấu trúc NodeTree

```cpp
struct NodeTree {
    int id;
    string content;
    NodeTree* left;
    NodeTree* right;
    int isLeaf;
};

NodeTree* root = nullptr;
int n = 0;
```

Trong đó:
- `id`: Mã định danh của nút.
- `content`: Nội dung của nút.
- `left`: Con trỏ trỏ đến nút con trái.
- `right`: Con trỏ trỏ đến nút con phải.
- `isLeaf`: Đánh dấu nút lá.
- `root`: Con trỏ trỏ đến nút gốc của cây.
- `n`: Số lượng nút trong cây.

### 2.2. Cách tổ chức cây

Cây được tổ chức bằng các con trỏ liên kết giữa các nút. Mỗi nút có thể có tối đa hai nút con là nút con trái và nút con phải.

Khác với cách cài đặt bằng mảng `NodeTree tree[100]`, chương trình sử dụng con trỏ `NodeTree*` và cấp phát bộ nhớ động để tạo các nút.

## 3. Các chức năng

Chương trình cung cấp các chức năng chính sau:

- Khởi tạo cây rỗng.
- Nhập cây từ bàn phím.
- Tạo cây mẫu có sẵn.
- In cây theo cấu trúc phân cấp.
- Duyệt cây theo thứ tự trước (Preorder).
- Duyệt cây theo thứ tự giữa (Inorder).
- Duyệt cây theo thứ tự sau (Postorder).
- Tìm kiếm nút theo mã hoặc nội dung.
- Tìm và hiển thị đường đi từ nút gốc đến nút cần tìm.
- Tính chiều cao của cây.
- Đếm số lượng nút lá.
- Chạy cây quyết định.
- Giải phóng bộ nhớ khi khởi tạo lại hoặc kết thúc chương trình.

## 4. Các hàm chính

| Hàm | Chức năng |
|---|---|
| `init()` | Khởi tạo cây rỗng và giải phóng cây cũ nếu có. |
| `deleteTree()` | Giải phóng bộ nhớ của các nút trong cây. |
| `updateLeafFlags()` | Cập nhật trạng thái nút lá. |
| `input()` | Nhập dữ liệu và xây dựng cây từ bàn phím. |
| `loadSampleTree()` | Tạo cây mẫu có sẵn. |
| `printTree()` | In cây theo cấu trúc phân cấp. |
| `preorder()` | Duyệt cây theo thứ tự trước. |
| `inorder()` | Duyệt cây theo thứ tự giữa. |
| `postorder()` | Duyệt cây theo thứ tự sau. |
| `findNode()` | Tìm nút theo mã hoặc nội dung. |
| `findPath()` | Tìm đường đi đến nút cần tìm. |
| `showPath()` | Hiển thị đường đi từ gốc đến nút cần tìm. |
| `height()` | Tính chiều cao của cây. |
| `countLeaves()` | Đếm số lượng nút lá. |
| `runDecisionTree()` | Chạy cây quyết định dựa trên lựa chọn của người dùng. |

## 5. Cách chạy chương trình

### 5.1. Biên dịch

Sử dụng trình biên dịch hỗ trợ C++11 trở lên.

```bash
g++ -std=c++11 main.cpp -o Lab3
```

### 5.2. Chạy chương trình

Trên Windows:

```bash
Lab3.exe
```

## 6. Kiểm thử

Các chức năng được kiểm thử với cây mẫu và cây do người dùng nhập.

| STT | Chức năng kiểm thử | Kết quả mong đợi |
|---|---|---|
| 1 | Khởi tạo cây | Cây rỗng, không có nút. |
| 2 | Tạo cây mẫu | Tạo thành công cây có 7 nút. |
| 3 | In cây | Hiển thị đúng cấu trúc cây. |
| 4 | Duyệt Preorder | Duyệt theo thứ tự gốc – trái – phải. |
| 5 | Duyệt Inorder | Duyệt theo thứ tự trái – gốc – phải. |
| 6 | Duyệt Postorder | Duyệt theo thứ tự trái – phải – gốc. |
| 7 | Tìm kiếm nút | Trả về nút nếu tìm thấy. |
| 8 | Tìm đường đi | Hiển thị đường đi từ gốc đến nút cần tìm. |
| 9 | Tính chiều cao | Cây mẫu có chiều cao bằng 3. |
| 10 | Đếm nút lá | Cây mẫu có 4 nút lá. |
| 11 | Chạy cây quyết định | Đưa ra kết quả dựa trên câu trả lời của người dùng. |
| 12 | Giải phóng bộ nhớ | Giải phóng các nút khi khởi tạo lại hoặc kết thúc chương trình. |

## 7. Ví dụ kết quả cây mẫu

Cây mẫu được xây dựng với nội dung như sau:

```text
                    [1] DTB < 2.0?
                   /             \
       [2] No >= 12 tin chi?     [3] DTB >= 3.2?
             /       \               /       \
           [4]       [5]            [6]       [7]
        Canh bao   Canh bao       De xuat   Theo doi
        hoc vu     hoc vu         khen      binh
        muc 2      muc 1          thuong    thuong
```

Các thông tin của cây mẫu:

- Tổng số nút: 7.
- Chiều cao của cây: 3.
- Số lượng nút lá: 4.
- Nút gốc có mã `1`.

## 8. Đặc điểm của chương trình

- Sử dụng cấu trúc liên kết thay cho mảng để lưu trữ các nút của cây.
- Sử dụng con trỏ để liên kết nút cha với nút con trái và nút con phải.
- Sử dụng cấp phát bộ nhớ động khi tạo nút.
- Hỗ trợ các thao tác cơ bản trên cây nhị phân.
- Sử dụng đệ quy trong các thao tác duyệt cây, tính chiều cao và đếm nút lá.
- Có chức năng giải phóng bộ nhớ nhằm tránh rò rỉ bộ nhớ.
- Giữ lại các chức năng chính của chương trình cây nhị phân ban đầu, đồng thời thay đổi cách tổ chức dữ liệu sang dạng liên kết.

## 9. Thông tin sinh viên

- **Họ và tên:** Phạm Tùng Lâm
- **Mã sinh viên:** A52505
- **Lớp:** TC3801
- **Học phần:** Cấu trúc dữ liệu và giải thuật
- **Bài thực hành:** Lab 3 – Cây nhị phân liên kết
