#include <gmpxx.h>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

// 使用 GMP 的概率素性测试判断一个数是否为素数
bool is_prime(const mpz_class &num, int reps = 50) {
    return mpz_probab_prime_p(num.get_mpz_t(), reps) != 0;
}

int main() {
    // 参数设置：c 取值范围，n 取值范围（r 固定为 2）
    int c_min = 2, c_max = 100;        // c 是比较小的数字
    int n_min = 240, n_max =260 ;      // n 的范围，可根据需要调整
    size_t min_bits = 250;            // 只考虑至少 256 位的候选数（也可改为 324、500 等）
    size_t max_bits = 256;   

    // 创建 "result" 目录（如果不存在）
    fs::create_directories("result");

    // 定义输出文件路径
    std::ofstream outfile("result/primes.txt", std::ios::app);
    if (!outfile) {
        std::cerr << "无法打开输出文件 result/primes.txt" << std::endl;
        return 1;
    }

    // 遍历所有 c 和 n 的组合，r 固定为 2
    for (int c = c_min; c <= c_max; c++) {
        for (int n = n_min; n <= n_max; n++) {
            mpz_class candidate;
            mpz_class two_pow_n;

            // 计算 2^n
            mpz_ui_pow_ui(two_pow_n.get_mpz_t(), 2, n);

            // 构造候选数：p = c * 2^n - 1
            candidate = mpz_class(c) * two_pow_n - 1;

            if (candidate <= 1)
                continue;

            // 获取候选数的二进制位数
            size_t bits = mpz_sizeinbase(candidate.get_mpz_t(), 2);
            if (bits < min_bits || bits > max_bits)
                continue;

            // 进行概率素性检测
            if (is_prime(candidate)) {
                std::cout << "找到素数 (" << bits << " 位): "
                          << candidate.get_str() << " = " << c
                          << " * 2^" << n << " - 1" << std::endl;
                outfile << "找到素数 (" << bits << " 位): "
                        << candidate.get_str() << " = " << c
                        << " * 2^" << n << " - 1" << std::endl;
            }
        }
    }

    outfile.close();
    return 0;
}

