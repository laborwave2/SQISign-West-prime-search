# SQISign-West-prime-search

**SQISign-West-prime-search** 是一个用于搜索形如 `p = c · 2^n - 1` 的素数的轻量级命令行工具，基于 C++ 实现，依赖 GMP 多精度库，并通过 CMake 构建，兼容 Ubuntu / WSL 环境。

---

## 📚 Required Libraries

在 Ubuntu / WSL 下，请先安装依赖：

```bash
sudo apt-get update
sudo apt-get install g++         # 或 clang
sudo apt-get install cmake
sudo apt-get install libgmp-dev
```

---

## ⚙️ Installation & Compilation

推荐在 Linux 或 WSL 环境中使用以下命令完成项目克隆与编译：

```bash
git clone https://github.com/laborwave2/SQISign-West-prime-search.git
cd SQISign-West-prime-search
mkdir build
cd build
cmake ..
make
```

编译完成后，可执行文件 `SQISign-West-prime-search` 位于 `build/` 目录中，运行方法：

```bash
./SQISign-West-prime-search
```

---

## 🚀 Usage

程序默认会在指定范围内搜索满足位数要求的素数，并将结果写入：

```
build/result/primes.txt
```

你可以修改 `main.cpp` 中的参数来调整搜索范围和最小位数：

```cpp
int c_min       = 2;
int c_max       = 100;
int n_min       = 240;
int n_max       = 260;
size_t min_bits = 256;
```

---

## 🗂️ Project Structure

```plaintext
SQISign-West-prime-search/
├── main.cpp
├── CMakeLists.txt
├── README.md
├── LICENSE
└── build/
    ├── SQISign-West-prime-search     # 可执行文件
    └── result/
        └── primes.txt                # 搜索结果
```

---


