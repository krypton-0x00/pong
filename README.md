

# 🏓 Pong in C++ (Raylib)

A simple Pong game built in **C++** using the **Raylib** framework.

---

## ▶️ How to Build & Run

### **1. Install Raylib**

#### **Linux**

```
sudo pacman -S raylib        # Arch / Manjaro / EndeavourOS
sudo apt install libraylib-dev  # Ubuntu / Debian
```

#### **Windows**

Download Raylib from:
[https://www.raylib.com/](https://www.raylib.com/)

---

### **2. Build the project**

```
mkdir build
cd build
cmake ..
make
```

---

### **3. Run the game**

```
./pong
```

---

## 🎮 Controls

| Action            | Key       |
| ----------------- | --------- |
| Left Paddle Up    | **W**     |
| Left Paddle Down  | **S**     |
| Right Paddle Up   | **↑**     |
| Right Paddle Down | **↓**     |
| Restart after win | **Space** |

---

## 📁 Project Structure

```
.
├── src/
│   ├── main.cpp
│   ├── ball.cpp
│   ├── paddle.cpp
│   ├── ball.h
│   ├── paddle.h
├── CMakeLists.txt
└── README.md
```


