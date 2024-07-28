// 用于内核上下文切换时保存的寄存器
struct context {
    uint64 ra; // 返回地址寄存器
    uint64 sp; // 栈指针寄存器

    // 被调用者保存的寄存器
    uint64 s0;
    uint64 s1;
    uint64 s2;
    uint64 s3;
    uint64 s4;
    uint64 s5;
    uint64 s6;
    uint64 s7;
    uint64 s8;
    uint64 s9;
    uint64 s10;
    uint64 s11;
};