; USBL first-stage stub, VA 0x2FFE4000 (file 0x54-0x3C0)
2FFE4000  push     {r0, r1, r2, r3, r4, r5}
2FFE4004  b        #0x2ffe4144
2FFE4008  andeq    r0, r0, r0
2FFE400C  andeq    r0, r0, r0
2FFE4010  andeq    r0, r0, r0
2FFE4014  andeq    r0, r0, r0
2FFE4018  andeq    r0, r0, r0
2FFE401C  andeq    r0, r0, r0
2FFE4020  andeq    r0, r0, r0
2FFE4024  andeq    r0, r0, r0
2FFE4028  andeq    r0, r0, r0
2FFE402C  andeq    r0, r0, r0
2FFE4030  andeq    r0, r0, r0
2FFE4034  andeq    r0, r0, r0
2FFE4038  andeq    r0, r0, r0
2FFE403C  andeq    r0, r0, r0
2FFE4040  andeq    r0, r0, r0
2FFE4044  andeq    r0, r0, r0
2FFE4048  andeq    r0, r0, r0
2FFE404C  andeq    r0, r0, r0
2FFE4050  andeq    r0, r0, r0
2FFE4054  andeq    r0, r0, r0
2FFE4058  andeq    r0, r0, r0
2FFE405C  andeq    r0, r0, r0
2FFE4060  andeq    r0, r0, r0
2FFE4064  andeq    r0, r0, r0
2FFE4068  andeq    r0, r0, r0
2FFE406C  andeq    r0, r0, r0
2FFE4070  andeq    r0, r0, r0
2FFE4074  andeq    r0, r0, r0
2FFE4078  andeq    r0, r0, r0
2FFE407C  andeq    r0, r0, r0
2FFE4080  andeq    r0, r0, r0
2FFE4084  andeq    r0, r0, r0
2FFE4088  andeq    r0, r0, r0
2FFE408C  andeq    r0, r0, r0
2FFE4090  andeq    r0, r0, r0
2FFE4094  andeq    r0, r0, r0
2FFE4098  andeq    r0, r0, r0
2FFE409C  andeq    r0, r0, r0
2FFE40A0  andeq    r0, r0, r0
2FFE40A4  andeq    r0, r0, r0
2FFE40A8  andeq    r0, r0, r0
2FFE40AC  andeq    r0, r0, r0
2FFE40B0  andeq    r0, r0, r0
2FFE40B4  andeq    r0, r0, r0
2FFE40B8  andeq    r0, r0, r0
2FFE40BC  andeq    r0, r0, r0
2FFE40C0  andeq    r0, r0, r0
2FFE40C4  andeq    r0, r0, r0
2FFE40C8  andeq    r0, r0, r0
2FFE40CC  andeq    r0, r0, r0
2FFE40D0  andeq    r0, r0, r0
2FFE40D4  andeq    r0, r0, r0
2FFE40D8  andeq    r0, r0, r0
2FFE40DC  andeq    r0, r0, r0
2FFE40E0  andeq    r0, r0, r0
2FFE40E4  andeq    r0, r0, r0
2FFE40E8  andeq    r0, r0, r0
2FFE40EC  andeq    r0, r0, r0
2FFE40F0  andeq    r0, r0, r0
2FFE40F4  andeq    r0, r0, r0
2FFE40F8  andeq    r0, r0, r0
2FFE40FC  andeq    r0, r0, r0
2FFE4100  andeq    r0, r0, r0
2FFE4104  andeq    r0, r0, r0
2FFE4108  andeq    r0, r0, r0
2FFE410C  andeq    r0, r0, r0
2FFE4110  ldmdbvc  r0!, {r0, r1, r6, r8, sb, sl, fp, sp, lr} ^
2FFE4114  stmdavs  r7!, {r1, r4, r5, r6, r8, fp, sp, lr} ^
2FFE4118  eorslo   r2, r2, r4, ror r0
2FFE411C  eorlo    r3, sp, #48, #16
2FFE4120  eorshs   r3, r0, r0, lsr r2
2FFE4124  strbpl   r5, [r1, -r8, asr #10]
2FFE4128  strtpl   r4, [r0], #-0x945
2FFE412C  cdpmi    p3, #4, c4, c8, c5, #2
2FFE4130  strbmi   r4, [pc, -pc, asr #24]
2FFE4134  subshs   r4, r3, sb, asr #10
2FFE4138  stchs    p15, c4, [lr], #-0x10c
2FFE413C  ldrbmi   r4, [r4], #-0xc20
2FFE4140  andeq    r0, r0, lr, lsr #32
2FFE4144  mov      r1, #0x90000000
2FFE4148  ldr      r2, [r1, #0x38]
2FFE414C  mvn      r3, #0x20000
2FFE4150  and      r2, r2, r3
2FFE4154  str      r2, [r1, #0x38]
2FFE4158  ldr      r1, [pc, #0x1d4]
2FFE415C  mov      r2, #0x1d
2FFE4160  str      r2, [r1, #0x810]
2FFE4164  ldr      r2, [pc, #0x1cc]
2FFE4168  str      r2, [r1, #0x430]
2FFE416C  ldr      r2, [pc, #0x1c4]
2FFE4170  str      r2, [r1, #0x434]
2FFE4174  ldr      r2, [pc, #0x1bc]
2FFE4178  str      r2, [r1, #0x440]
2FFE417C  ldr      r2, [pc, #0x1b4]
2FFE4180  str      r2, [r1, #0x444]
2FFE4184  ldr      r2, [pc, #0x1ac]
2FFE4188  str      r2, [r1, #0x448]
2FFE418C  ldr      r2, [pc, #0x1a4]
2FFE4190  str      r2, [r1, #0x44c]
2FFE4194  ldr      r2, [pc, #0x19c]
2FFE4198  str      r2, [r1, #0x450]
2FFE419C  ldr      r2, [pc, #0x194]
2FFE41A0  str      r2, [r1, #0x454]
2FFE41A4  ldr      r2, [pc, #0x18c]
2FFE41A8  str      r2, [r1, #0x458]
2FFE41AC  ldr      r2, [pc, #0x184]
2FFE41B0  str      r2, [r1, #0x45c]
2FFE41B4  ldr      r2, [pc, #0x17c]
2FFE41B8  str      r2, [r1, #0x460]
2FFE41BC  ldr      r2, [pc, #0x174]
2FFE41C0  str      r2, [r1, #0x464]
2FFE41C4  ldr      r2, [pc, #0x170]
2FFE41C8  str      r2, [r1, #0x430]
2FFE41CC  ldr      r2, [pc, #0x168]
2FFE41D0  str      r2, [r1, #0x434]
2FFE41D4  ldr      r2, [pc, #0x160]
2FFE41D8  str      r2, [r1, #0x440]
2FFE41DC  ldr      r2, [pc, #0x158]
2FFE41E0  str      r2, [r1, #0x444]
2FFE41E4  ldr      r2, [pc, #0x150]
2FFE41E8  str      r2, [r1, #0x448]
2FFE41EC  ldr      r2, [pc, #0x148]
2FFE41F0  str      r2, [r1, #0x44c]
2FFE41F4  ldr      r2, [pc, #0x140]
2FFE41F8  str      r2, [r1, #0x450]
2FFE41FC  ldr      r2, [pc, #0x138]
2FFE4200  str      r2, [r1, #0x454]
2FFE4204  ldr      r2, [pc, #0x130]
2FFE4208  str      r2, [r1, #0x458]
2FFE420C  ldr      r2, [pc, #0x128]
2FFE4210  str      r2, [r1, #0x45c]
2FFE4214  ldr      r2, [pc, #0x120]
2FFE4218  str      r2, [r1, #0x460]
2FFE421C  ldr      r2, [pc, #0x118]
2FFE4220  str      r2, [r1, #0x464]
2FFE4224  ldr      r2, [pc, #0x114]
2FFE4228  str      r2, [r1, #0x58]
2FFE422C  mov      r2, #0
2FFE4230  str      r2, [r1, #4]
2FFE4234  ldr      r2, [r1, #0x808]
2FFE4238  and      r2, r2, #0x80000000
2FFE423C  cmp      r2, #0x80000000
2FFE4240  bne      #0x2ffe4234
2FFE4244  mov      r2, #0x6b
2FFE4248  str      r2, [r1, #0x804]
2FFE424C  mov      r2, #0x40000000
2FFE4250  str      r2, [r1, #0x800]
2FFE4254  ldr      r2, [r1, #0x808]
2FFE4258  and      r2, r2, #0x80000000
2FFE425C  cmp      r2, #0x80000000
2FFE4260  bne      #0x2ffe4254
2FFE4264  ldr      r3, [pc, #0xd8]
2FFE4268  subs     r3, r3, #1
2FFE426C  cmp      r3, #0
2FFE4270  bne      #0x2ffe4268
2FFE4274  mov      r2, #0x32
2FFE4278  str      r2, [r1, #0x14]
2FFE427C  mov      r2, #0
2FFE4280  str      r2, [r1, #0x18]
2FFE4284  ldr      r2, [pc, #0xbc]
2FFE4288  str      r2, [r1, #0x1c]
2FFE428C  ldr      r2, [pc, #0xb8]
2FFE4290  str      r2, [r1, #0x20]
2FFE4294  mov      r2, #0x22
2FFE4298  str      r2, [r1, #0x2c]
2FFE429C  mov      r2, #0x22
2FFE42A0  str      r2, [r1, #0x30]
2FFE42A4  mov      r2, #0x22
2FFE42A8  str      r2, [r1, #0x34]
2FFE42AC  mov      r2, #0x22
2FFE42B0  str      r2, [r1, #0x38]
2FFE42B4  mov      r2, #0x30000000
2FFE42B8  str      r2, [r1, #0x40]
2FFE42BC  ldr      r2, [pc, #0x8c]
2FFE42C0  str      r2, [r1, #0x50]
2FFE42C4  ldr      r2, [pc, #0x88]
2FFE42C8  str      r2, [r1, #0x54]
2FFE42CC  ldr      r2, [pc, #0x84]
2FFE42D0  str      r2, [r1, #0x58]
2FFE42D4  ldr      r2, [pc, #0x80]
2FFE42D8  str      r2, [r1, #0x5c]
2FFE42DC  ldr      r2, [pc, #0x7c]
2FFE42E0  str      r2, [r1, #0xac]
2FFE42E4  mov      r2, #1
2FFE42E8  str      r2, [r1, #8]
2FFE42EC  ldr      r2, [r1]
2FFE42F0  and      r2, r2, #8
2FFE42F4  cmp      r2, #8
2FFE42F8  beq      #0x2ffe42ec
2FFE42FC  ldr      r2, [pc, #0x60]
2FFE4300  str      r2, [r1, #0x20]
2FFE4304  mov      r2, #1
2FFE4308  str      r2, [r1, #0xf8]
2FFE430C  mov      r1, #0x90000000
2FFE4310  mov      r2, #0x30000000
2FFE4314  str      r2, [r1, #0x470]
2FFE4318  ldr      r2, [pc, #0x48]
2FFE431C  str      r2, [r1, #0x474]
2FFE4320  ldr      r2, [r1, #0x400]
2FFE4324  orr      r2, r2, #1
2FFE4328  str      r2, [r1, #0x400]
2FFE432C  pop      {r0, r1, r2, r3, r4, r5}
2FFE4330  mov      pc, lr
2FFE4334  andls    r0, r2, r0
2FFE4338  andeq    r1, r0, r6
2FFE433C  andeq    r1, r0, r3
2FFE4340  ldrbvc   lr, [r1, -r0]!
2FFE4344  andeq    r4, r0, r0, lsr #28
2FFE4348  mvnhs    r0, r0, lsl r1
2FFE434C  andlo    r5, r0, r0, lsl #6
2FFE4350  movths   r0, #0x4c08
2FFE4354  mrceq    p3, #1, r1, c2, c8, #0
2FFE4358  eorshs   r0, r0, #0x49
