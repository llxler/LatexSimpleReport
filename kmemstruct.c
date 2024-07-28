struct {
    struct spinlock lock;    // 自旋锁
    struct run *freelist;    // 空闲页面链表
    uint64 npage;            // 空闲页面数量
} kmem;