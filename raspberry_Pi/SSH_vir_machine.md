# SSH từ windows đến máy ảo Linux

## Enable SSH trên máy ảo 

### 1. Kiểm tra SSH đã được cài đặt chưa: (nếu không chạy được thì có thể thay thế service bằng systemctl)

Mặc định, Raspbian (hệ điều hành phổ biến của Raspberry Pi) thường đã cài đặt SSH. Tuy nhiên, để chắc chắn, bạn có thể kiểm tra bằng lệnh:

`sudo service ssh status`

- Nếu SSH chưa được cài đặt, bạn có thể cài đặt nó bằng lệnh:

`sudo apt-get install openssh-server`

### 2. Bật dịch vụ SSH:

`sudo service ssh start`

### 3. Kiểm tra trạng thái của dịch vụ SSH:

`sudo service ssh status`

Nếu SSH đã được bật, bạn sẽ thấy một thông báo về trạng thái "active (running)".

### 4. (Tùy chọn) Cấu hình để tự động khởi động SSH khi hệ thống khởi động:

Sử dụng lệnh raspi-config:

`sudo raspi-config`

Sau đó, chọn "Interfacing Options" > "SSH" và chọn "Yes" để kích hoạt SSH. Reboot lại bằng `sudo Reboot` khi này Pi sẽ tự động bật SSH.

## Cấu hình trên VM Box

- Các bạn quay lại VMBox mở "Settings" -> "Network" -> "Port Forwarding".

- Sau đó Setup địa chỉ 

```
Host IP: Ip máy windows
Host Port: 22
Guest IP: IP máy ảo Linux
Guest Port: 22
```

## open SSH từ cmd của windows

### 1. Mở cmd với quyền admin

### 2. Dùng lệnh

`ssh username@(IP máy windows)`

ví dụ: tam@raspberry và ip máy windows là 192.168.22.12

`ssh tam@192.168.22.12`

### 3. Thông điệp

```
The authenticity of host '192.168.22.12 (192.168.22.12)' can't be established.
ECDSA key fingerprint is SHA256:xsdadhkasdhaslkdhasldjakd
Are you sure you want to continue connecting (yes/no/[fingerprint])? yes
Warning: Permanently added '192.168.22.12' (ECDSA) to the list of known hosts.
```
xuất hiện khi bạn kết nối đến một máy chủ thông qua SSH và máy chủ này không được nhận diện trong file known_hosts trên máy tính của bạn. File known_hosts chứa các khóa host của các máy chủ đã được xác nhận trước đó.

Nghĩa của thông điệp này là SSH client không nhận diện máy chủ mà bạn đang kết nối, và do đó, không thể xác nhận tính xác thực của máy chủ đó. Điều này có thể xảy ra trong các tình huống sau:

- Máy chủ mới: Bạn đang kết nối đến một máy chủ mới mà bạn chưa từng kết nối trước đó.

- Cài đặt lại hệ điều hành hoặc SSH: Nếu bạn đã cài đặt lại hệ điều hành hoặc SSH trên máy chủ, khóa host có thể đã thay đổi.

- Tấn công giả mạo: Có thể có sự thay đổi không mong muốn trên máy chủ hoặc có sự tấn công giả mạo.

Khi bạn gặp thông điệp này, bạn sẽ được hỏi liệu bạn có muốn tiếp tục kết nối không. Bạn sẽ thường được yêu cầu nhập `yes` để thêm khóa host của máy chủ mới vào file known_hosts

### 4. Nhập password
