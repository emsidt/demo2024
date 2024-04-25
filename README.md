# GAME CARO

Bài tập lớn

## MÔ TẢ

Họ và tên : Trịnh Bình Dương

Lớp : K68CC - UET

Mã SV : 23020035

Lớp học phần : LTNC-INT 2215_50

## GIỚI THIỆU GAME

- Đây là trò chơi dựa trên tựa game nổi tiếng TikTacToe

## Video hướng dẫn chơi và giới thiệu game

- Youtube :

## MỤC LỤC

1. [ Cách cài đặt game](#1-cách-cài-đặt-game)

2. [ Hướng dẫn chơi game](#2-hướng-dẫn-chơi-game)

3. [ Các hàm được sử dụng](#3-các-hàm-được-sử-dụng)

4. [ Nguồn tham khảo](#4-nguồn-tham-khảo)

##  NỘI DUNG

### 1. Cách cài đặt game

- Bước 1: Các bạn tải file zip ở [link này](https://github.com/emsidt/demo2024/releases/tag/caro)
  
- Bước 2 : Các bạn tiến hành giải nén và chọn vào file [**Caro.exe**](https://github.com/emsidt/demo2024/blob/master/Caro%201.0.exe) để bắt đầu chơi game

### 2. Hướng dẫn chơi game

- Các bạn sử dụng chuột để **click** vào bất kỳ ô nào mong muốn

- Giao diện chính của trò chơi:
  
  ![Màn hình chính](https://github.com/emsidt/demo2024/blob/master/image/mainmenu.png)
  
- Trò chơi sẽ có hai chế độ là đánh với người và đánh với máy

  1.1 Đánh với người
  - Click chuột vào ô **2 player** ở **Menu** để vào chế độ này
  
  - Ở chế độ này, hai người chơi lần lượt sử dụng chuột để đánh vào ô mình mong muốn. Chế độ mặc định của trò chơi là chế độ chặn hai đầu. Trò chơi kết thúc khi một trong hai người chơi đạt đượcc 5 ô liên tiếp ở hàng ngang, dọc, chéo.
  
  - Khi bắt đầu trò chơi, hệ thống sẽ hiển thị lượt của người chơi thứ nhất hoặc người chơi thứ hai.
  
  - Dưới đây là hình ảnh minh họa:
    
    ![2 người chơi](https://github.com/emsidt/demo2024/blob/master/image/play0.png)
    
  1.2 Đánh với máy
    - Click chuột vào ô **1 player** ở **Menu** để vào chế độ này
    
    - Ở chế độ này, máy sẽ mặc định là quân X và đi trước. Người chơi là quân O. Nhiệm vụ của người chơi là dành chiến thắng trước máy. Chế độ mặc định cũng là chế độ chặn hai đầu.
    
### 3. Các hàm được sử dụng

- Trong game này, em sử dụng các thư viện của SDL2 như âm thanh, hình ảnh.
  
- Tạo ra các đối tượng như **Media** để quản lý âm thanh, hình ảnh, đối tượng **Game** để quản lý trò chơi, đối tượng **Board** để quản lý các logic của trò chơi.

- Về phần tạo AI để đánh với người chơi, em sử dụng giải thuật leo đồi để tính điểm của các ô trống trong bàn cờ, từ đó tìm ra ô có điểm số cao nhất để thực hiện nước đi. Em khởi tạo hai mảng các điểm tấn công và phòng thủ dựa trên tổng số quân đồng minh và quân địch của các hàng ngang, dọc, chéo từ đó tính điểm của mỗi ô.

- Trò chơi có các chức năng cơ bản như **menu** chính, **chơi lại** chế độ vừa chơi, trở về màn hình chính và thoát chương trình.

### 4. Nguồn tham khảo

- Về phần hình ảnh em tự thiết kế trên [Canva](https://www.canva.com/), phần âm thanh em sử dụng tại trang [Pixabay](https://pixabay.com/vi/sound-effects/search/game/).

- Series hướng dẫn SDL2 của [Lazyfoo](https://pixabay.com/vi/sound-effects/search/game/).

-  Video về giải thuật leo đồi tại kênh [Super Man](https://www.youtube.com/watch?v=59EaoU-wHy8).

## ĐÓNG GÓP

Em xin cảm ơn các thầy đã hỗ trợ em:
- Thầy Lê Đức Trọng
- Thầy Trần Trường Thủy
## LỢI ÍCH ĐẠT ĐƯỢC
Việc tạo ra dự án này đã giúp em học hỏi được rất nhiều kỹ năng mới như:
- Biết cách sử dụng thư viện đồ họa **SDL2**
- Biết tách file tạo thành cấu trúc của 1 dự án.
- Biết sử dụng **Github**
- Biết thêm về **Class** và **Lập trình hướng đối tượng**

