struct {
    struct spinlock lock;
    struct run *freelist;
    uint64 npage;
} kmem;