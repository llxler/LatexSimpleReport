        li a7, SYS_fork
        ecall
        bne a0, zero, after_brk
        la a0, brk
        la a1, argv_brk
        li a7, SYS_exec
        ecall
after_brk:
        li a0, 0
        li a7, SYS_wait
        ecall
