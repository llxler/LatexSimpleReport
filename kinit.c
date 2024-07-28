void kinit() {
    initlock(&kmem.lock, "kmem");      // 初始化 kmem 锁
    kmem.npage = 0;                    // 初始化空闲页面计数
    kmem.freelist = 0;                 // 初始化空闲页面列表
    freerange(kernel_end, (void *)PHYSTOP); // 释放从 kernel_end 到 PHYSTOP 范围内的页面
#ifdef DEBUG
    printf("kernel_end: %p, phystop: %p\nkinit\n", kernel_end, (void *)PHYSTOP); // 如果启用了 DEBUG 模式，打印调试信息
#endif
}