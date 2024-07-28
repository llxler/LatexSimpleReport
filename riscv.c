#define PTE_V (1L << 0)  // valid
#define PTE_R (1L << 1)  // read
#define PTE_W (1L << 2)  // write
#define PTE_X (1L << 3)  // execute
#define PTE_U (1L << 4)  // 1 -> user can access