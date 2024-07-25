.globl start
start:
        li a0, 2    // O_RDWR
        la a1, 1    // console
        li a2, 0
        li a7, SYS_dev
        ecall	# dev(O_RDWR, CONSOLE, 0);
        
        li a0, 0
        li a7, SYS_dup
        ecall	# dup(0);  // stdout

        li a0, 0
        li a7, SYS_dup
        ecall	# dup(0);  // stderr