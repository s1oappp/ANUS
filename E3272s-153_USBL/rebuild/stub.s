; Стаб первого уровня: файл 0x054-0x3BF, исполняется в IRAM 0x2FFE4000.
; Настраивает DDR-контроллер 0x90020000 и системный блок 0x90000000, возвращает управление.

    push {r0, r1, r2, r3, r4, r5}                  @ 2FFE4000
    b #0x2ffe4144                                  @ 2FFE4004 ; -> 0x2FFE4144
    andeq r0, r0, r0                               @ 2FFE4008
    andeq r0, r0, r0                               @ 2FFE400C
    andeq r0, r0, r0                               @ 2FFE4010
    andeq r0, r0, r0                               @ 2FFE4014
    andeq r0, r0, r0                               @ 2FFE4018
    andeq r0, r0, r0                               @ 2FFE401C
    andeq r0, r0, r0                               @ 2FFE4020
    andeq r0, r0, r0                               @ 2FFE4024
    andeq r0, r0, r0                               @ 2FFE4028
    andeq r0, r0, r0                               @ 2FFE402C
    andeq r0, r0, r0                               @ 2FFE4030
    andeq r0, r0, r0                               @ 2FFE4034
    andeq r0, r0, r0                               @ 2FFE4038
    andeq r0, r0, r0                               @ 2FFE403C
    andeq r0, r0, r0                               @ 2FFE4040
    andeq r0, r0, r0                               @ 2FFE4044
    andeq r0, r0, r0                               @ 2FFE4048
    andeq r0, r0, r0                               @ 2FFE404C
    andeq r0, r0, r0                               @ 2FFE4050
    andeq r0, r0, r0                               @ 2FFE4054
    andeq r0, r0, r0                               @ 2FFE4058
    andeq r0, r0, r0                               @ 2FFE405C
    andeq r0, r0, r0                               @ 2FFE4060
    andeq r0, r0, r0                               @ 2FFE4064
    andeq r0, r0, r0                               @ 2FFE4068
    andeq r0, r0, r0                               @ 2FFE406C
    andeq r0, r0, r0                               @ 2FFE4070
    andeq r0, r0, r0                               @ 2FFE4074
    andeq r0, r0, r0                               @ 2FFE4078
    andeq r0, r0, r0                               @ 2FFE407C
    andeq r0, r0, r0                               @ 2FFE4080
    andeq r0, r0, r0                               @ 2FFE4084
    andeq r0, r0, r0                               @ 2FFE4088
    andeq r0, r0, r0                               @ 2FFE408C
    andeq r0, r0, r0                               @ 2FFE4090
    andeq r0, r0, r0                               @ 2FFE4094
    andeq r0, r0, r0                               @ 2FFE4098
    andeq r0, r0, r0                               @ 2FFE409C
    andeq r0, r0, r0                               @ 2FFE40A0
    andeq r0, r0, r0                               @ 2FFE40A4
    andeq r0, r0, r0                               @ 2FFE40A8
    andeq r0, r0, r0                               @ 2FFE40AC
    andeq r0, r0, r0                               @ 2FFE40B0
    andeq r0, r0, r0                               @ 2FFE40B4
    andeq r0, r0, r0                               @ 2FFE40B8
    andeq r0, r0, r0                               @ 2FFE40BC
    andeq r0, r0, r0                               @ 2FFE40C0
    andeq r0, r0, r0                               @ 2FFE40C4
    andeq r0, r0, r0                               @ 2FFE40C8
    andeq r0, r0, r0                               @ 2FFE40CC
    andeq r0, r0, r0                               @ 2FFE40D0
    andeq r0, r0, r0                               @ 2FFE40D4
    andeq r0, r0, r0                               @ 2FFE40D8
    andeq r0, r0, r0                               @ 2FFE40DC
    andeq r0, r0, r0                               @ 2FFE40E0
    andeq r0, r0, r0                               @ 2FFE40E4
    andeq r0, r0, r0                               @ 2FFE40E8
    andeq r0, r0, r0                               @ 2FFE40EC
    andeq r0, r0, r0                               @ 2FFE40F0
    andeq r0, r0, r0                               @ 2FFE40F4
    andeq r0, r0, r0                               @ 2FFE40F8
    andeq r0, r0, r0                               @ 2FFE40FC
    andeq r0, r0, r0                               @ 2FFE4100
    andeq r0, r0, r0                               @ 2FFE4104
    andeq r0, r0, r0                               @ 2FFE4108
    andeq r0, r0, r0                               @ 2FFE410C
    .word 0x79706F43                              @ 2FFE4110
    .word 0x68676972                              @ 2FFE4114
    eorslo r2, r2, r4, ror r0                      @ 2FFE4118
    eorlo r3, sp, #48, #16                         @ 2FFE411C
    eorshs r3, r0, r0, lsr r2                      @ 2FFE4120
    strbpl r5, [r1, -r8, asr #10]                  @ 2FFE4124
    strtpl r4, [r0], #-0x945                       @ 2FFE4128
    cdpmi p3, #4, c4, c8, c5, #2                   @ 2FFE412C
    strbmi r4, [pc, -pc, asr #24]                  @ 2FFE4130
    subshs r4, r3, sb, asr #10                     @ 2FFE4134
    stchs p15, c4, [lr], #-0x10c                   @ 2FFE4138
    .word 0x44544C20                              @ 2FFE413C
    andeq r0, r0, lr, lsr #32                      @ 2FFE4140
    mov r1, #0x90000000                            @ 2FFE4144
    ldr r2, [r1, #0x38]                            @ 2FFE4148
    mvn r3, #0x20000                               @ 2FFE414C
    and r2, r2, r3                                 @ 2FFE4150
    str r2, [r1, #0x38]                            @ 2FFE4154
    ldr r1, [pc, #0x1d4]                           @ 2FFE4158
    mov r2, #0x1d                                  @ 2FFE415C
    .word 0xE5812810                              @ 2FFE4160
    ldr r2, [pc, #0x1cc]                           @ 2FFE4164
    str r2, [r1, #0x430]                           @ 2FFE4168
    .word 0xE59F21C4                              @ 2FFE416C
    str r2, [r1, #0x434]                           @ 2FFE4170
    .word 0xE59F21BC                              @ 2FFE4174
    str r2, [r1, #0x440]                           @ 2FFE4178
    .word 0xE59F21B4                              @ 2FFE417C
    str r2, [r1, #0x444]                           @ 2FFE4180
    .word 0xE59F21AC                              @ 2FFE4184
    str r2, [r1, #0x448]                           @ 2FFE4188
    .word 0xE59F21A4                              @ 2FFE418C
    str r2, [r1, #0x44c]                           @ 2FFE4190
    .word 0xE59F219C                              @ 2FFE4194
    str r2, [r1, #0x450]                           @ 2FFE4198
    .word 0xE59F2194                              @ 2FFE419C
    str r2, [r1, #0x454]                           @ 2FFE41A0
    .word 0xE59F218C                              @ 2FFE41A4
    str r2, [r1, #0x458]                           @ 2FFE41A8
    .word 0xE59F2184                              @ 2FFE41AC
    str r2, [r1, #0x45c]                           @ 2FFE41B0
    .word 0xE59F217C                              @ 2FFE41B4
    str r2, [r1, #0x460]                           @ 2FFE41B8
    .word 0xE59F2174                              @ 2FFE41BC
    str r2, [r1, #0x464]                           @ 2FFE41C0
    .word 0xE59F2170                              @ 2FFE41C4
    str r2, [r1, #0x430]                           @ 2FFE41C8
    .word 0xE59F2168                              @ 2FFE41CC
    str r2, [r1, #0x434]                           @ 2FFE41D0
    .word 0xE59F2160                              @ 2FFE41D4
    str r2, [r1, #0x440]                           @ 2FFE41D8
    .word 0xE59F2158                              @ 2FFE41DC
    str r2, [r1, #0x444]                           @ 2FFE41E0
    .word 0xE59F2150                              @ 2FFE41E4
    str r2, [r1, #0x448]                           @ 2FFE41E8
    .word 0xE59F2148                              @ 2FFE41EC
    str r2, [r1, #0x44c]                           @ 2FFE41F0
    .word 0xE59F2140                              @ 2FFE41F4
    str r2, [r1, #0x450]                           @ 2FFE41F8
    .word 0xE59F2138                              @ 2FFE41FC
    str r2, [r1, #0x454]                           @ 2FFE4200
    .word 0xE59F2130                              @ 2FFE4204
    str r2, [r1, #0x458]                           @ 2FFE4208
    .word 0xE59F2128                              @ 2FFE420C
    str r2, [r1, #0x45c]                           @ 2FFE4210
    .word 0xE59F2120                              @ 2FFE4214
    str r2, [r1, #0x460]                           @ 2FFE4218
    .word 0xE59F2118                              @ 2FFE421C
    str r2, [r1, #0x464]                           @ 2FFE4220
    .word 0xE59F2114                              @ 2FFE4224
    str r2, [r1, #0x58]                            @ 2FFE4228
    .word 0xE3A02000                              @ 2FFE422C
    str r2, [r1, #4]                               @ 2FFE4230
    ldr r2, [r1, #0x808]                           @ 2FFE4234
    and r2, r2, #0x80000000                        @ 2FFE4238
    cmp r2, #0x80000000                            @ 2FFE423C
    bne #0x2ffe4234                                @ 2FFE4240 ; -> 0x2FFE4234
    mov r2, #0x6b                                  @ 2FFE4244
    str r2, [r1, #0x804]                           @ 2FFE4248
    mov r2, #0x40000000                            @ 2FFE424C
    str r2, [r1, #0x800]                           @ 2FFE4250
    ldr r2, [r1, #0x808]                           @ 2FFE4254
    and r2, r2, #0x80000000                        @ 2FFE4258
    cmp r2, #0x80000000                            @ 2FFE425C
    bne #0x2ffe4254                                @ 2FFE4260 ; -> 0x2FFE4254
    ldr r3, [pc, #0xd8]                            @ 2FFE4264
    subs r3, r3, #1                                @ 2FFE4268
    .word 0xE3530000                              @ 2FFE426C
    bne #0x2ffe4268                                @ 2FFE4270 ; -> 0x2FFE4268
    mov r2, #0x32                                  @ 2FFE4274
    str r2, [r1, #0x14]                            @ 2FFE4278
    mov r2, #0                                     @ 2FFE427C
    str r2, [r1, #0x18]                            @ 2FFE4280
    ldr r2, [pc, #0xbc]                            @ 2FFE4284
    str r2, [r1, #0x1c]                            @ 2FFE4288
    .word 0xE59F20B8                              @ 2FFE428C
    str r2, [r1, #0x20]                            @ 2FFE4290
    .word 0xE3A02022                              @ 2FFE4294
    str r2, [r1, #0x2c]                            @ 2FFE4298
    mov r2, #0x22                                  @ 2FFE429C
    str r2, [r1, #0x30]                            @ 2FFE42A0
    mov r2, #0x22                                  @ 2FFE42A4
    str r2, [r1, #0x34]                            @ 2FFE42A8
    mov r2, #0x22                                  @ 2FFE42AC
    str r2, [r1, #0x38]                            @ 2FFE42B0
    mov r2, #0x30000000                            @ 2FFE42B4
    str r2, [r1, #0x40]                            @ 2FFE42B8
    ldr r2, [pc, #0x8c]                            @ 2FFE42BC
    str r2, [r1, #0x50]                            @ 2FFE42C0
    .word 0xE59F2088                              @ 2FFE42C4
    str r2, [r1, #0x54]                            @ 2FFE42C8
    .word 0xE59F2084                              @ 2FFE42CC
    str r2, [r1, #0x58]                            @ 2FFE42D0
    .word 0xE59F2080                              @ 2FFE42D4
    str r2, [r1, #0x5c]                            @ 2FFE42D8
    .word 0xE59F207C                              @ 2FFE42DC
    str r2, [r1, #0xac]                            @ 2FFE42E0
    .word 0xE3A02001                              @ 2FFE42E4
    str r2, [r1, #8]                               @ 2FFE42E8
    ldr r2, [r1]                                   @ 2FFE42EC
    and r2, r2, #8                                 @ 2FFE42F0
    cmp r2, #8                                     @ 2FFE42F4
    beq #0x2ffe42ec                                @ 2FFE42F8 ; -> 0x2FFE42EC
    ldr r2, [pc, #0x60]                            @ 2FFE42FC
    str r2, [r1, #0x20]                            @ 2FFE4300
    .word 0xE3A02001                              @ 2FFE4304
    str r2, [r1, #0xf8]                            @ 2FFE4308
    mov r1, #0x90000000                            @ 2FFE430C
    mov r2, #0x30000000                            @ 2FFE4310
    str r2, [r1, #0x470]                           @ 2FFE4314
    ldr r2, [pc, #0x48]                            @ 2FFE4318
    str r2, [r1, #0x474]                           @ 2FFE431C
    .word 0xE5912400                              @ 2FFE4320
    orr r2, r2, #1                                 @ 2FFE4324
    str r2, [r1, #0x400]                           @ 2FFE4328
    pop {r0, r1, r2, r3, r4, r5}                   @ 2FFE432C
    mov pc, lr                                     @ 2FFE4330
    andls r0, r2, r0                               @ 2FFE4334
    andeq r1, r0, r6                               @ 2FFE4338
    andeq r1, r0, r3                               @ 2FFE433C
    ldrbvc lr, [r1, -r0]!                          @ 2FFE4340
    andeq r4, r0, r0, lsr #28                      @ 2FFE4344
    mvnhs r0, r0, lsl r1                           @ 2FFE4348
    andlo r5, r0, r0, lsl #6                       @ 2FFE434C
    movths r0, #0x4c08                             @ 2FFE4350
    mrceq p3, #1, r1, c2, c8, #0                   @ 2FFE4354
    eorshs r0, r0, #0x49                           @ 2FFE4358
    .word 0xFFC00022                              @ 2FFE435C
    svceq #0x103                                   @ 2FFE4360
    andlo r5, r0, r0, lsl #14                      @ 2FFE4364
    svclo #0xf00000                                @ 2FFE4368
