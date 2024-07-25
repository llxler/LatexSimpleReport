    .align 4
    .section .data
    .global initcode
    .global initcode_size
initcode:
    #.incbin "../xv6-user/initcode"
    .incbin "../xv6-user/init-for-test"
codeend:

initcode_size:
    .long codeend-initcode
