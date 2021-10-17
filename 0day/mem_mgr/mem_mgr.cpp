#include <bitset>
#include <inc.h>

const unsigned char mem_mgr::SC_copy_size_pre[] = { 0x55, 0x48, 0x89, 0xE5, 0x48, 0x85, 0xC9, 0x48, 0xB8, 0x01, 0x00, 0x09, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x74, 0x46, 0x48, 0x85, 0xD2, 0x48, 0xB8, 0x01, 0x00, 0x09, 0x00, 0x01, 0x00, 0xFF, 0xFF, 0x74, 0x37, 0x48, 0xC7, 0xC0, 0x30, 0x00, 0x00, 0x00, 0x48, 0x85, 0xC2, 0x48, 0xB8, 0x02, 0x00, 0x09, 0x00, 0x01, 0x00, 0xFF, 0xFF, 0x74, 0x21, 0x48, 0x89, 0xC8, 0x48, 0x8B, 0x08, 0x48, 0x8B, 0x50, 0x08, 0x4C, 0x8B, 0x40, 0x10, 0x4C, 0x8B, 0x48, 0x18, 0xFF, 0x70, 0x20, 0xFF, 0x70, 0x28, 0x48, 0x83, 0xEC, 0x20, 0xE8, 0x05, 0x00, 0x00, 0x00, 0x48, 0x89, 0xEC, 0x5D, 0xC3, 0x55, 0x48, 0x89, 0xE5, 0x57, 0x56, 0x48, 0x89, 0x4D, 0x10, 0x48, 0x89, 0x55, 0x18, 0x4C, 0x89, 0x45, 0x20, 0x4C, 0x89, 0x4D, 0x28, 0x48, 0x8B, 0x45, 0x30, 0x48, 0x85, 0xC0, 0x48, 0xB8, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0xFF, 0xFF, 0x0F, 0x84, 0x5C, 0x01, 0x00, 0x00, 0x4C, 0x8B, 0x45, 0x38, 0x4D, 0x85, 0xC0, 0x48, 0xB8, 0x01, 0x00, 0x01, 0x00, 0x04, 0x00, 0xFF, 0xFF, 0x0F, 0x84, 0x45, 0x01, 0x00, 0x00, 0x48, 0x83, 0xEC, 0x20, 0x4C, 0x8D, 0x4D, 0xE8, 0xE8, 0x3F, 0x01, 0x00, 0x00, 0x49, 0xBA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x4C, 0x39, 0xD0, 0x72, 0x12, 0x48, 0xB9, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x48, 0x09, 0xC8, 0xE9, 0x17, 0x01, 0x00, 0x00, 0x48, 0x89, 0x45, 0xE0, 0x48, 0xB9, 0x00, 0xF0, 0xFF, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x48, 0x21, 0xC8, 0x48, 0x85, 0xC0, 0x75, 0x0F, 0x48, 0xB8, 0x01, 0x00, 0x08, 0x00, 0x03, 0x00, 0xFF, 0xFF, 0xE9, 0xF2, 0x00, 0x00, 0x00, 0x48, 0x8B, 0x55, 0x18, 0x48, 0xC7, 0xC1, 0xFF, 0x0F, 0x00, 0x00, 0x48, 0x21, 0xCA, 0x48, 0x89, 0x55, 0xD8, 0x48, 0x09, 0xD0, 0x48, 0x89, 0x45, 0xD0, 0x48, 0x83, 0xEC, 0x18, 0x48, 0x8B, 0x4D, 0x20, 0x48, 0x8B, 0x55, 0x28, 0x4C, 0x8D, 0x4D, 0xC8, 0xE8, 0xCB, 0x00, 0x00, 0x00, 0x49, 0xBA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x4C, 0x39, 0xD0, 0x72, 0x0D, 0x48, 0xB9, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x48, 0x09, 0xC8, 0x48, 0x89, 0x45, 0xC0, 0x48, 0xB9, 0x00, 0xF0, 0xFF, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x48, 0x21, 0xC8, 0x48, 0x85, 0xC0, 0x75, 0x0F, 0x48, 0xB8, 0x01, 0x00, 0x08, 0x00, 0x02, 0x00, 0xFF, 0xFF, 0xE9, 0x83, 0x00, 0x00, 0x00, 0x48, 0x8B, 0x55, 0x28, 0x48, 0xC7, 0xC1, 0xFF, 0x0F, 0x00, 0x00, 0x48, 0x21, 0xCA, 0x48, 0x89, 0x55, 0xB8, 0x48, 0x09, 0xD0, 0x48, 0x89, 0x45, 0xB0, 0x48, 0x8B, 0x45, 0xD8, 0x48, 0xC7, 0xC1, 0x00, 0x10, 0x00, 0x00, 0x48, 0x29, 0xC1, 0x48, 0x8B, 0x45, 0xB8, 0x48, 0xC7, 0xC2, 0x00, 0x10, 0x00, 0x00, 0x48, 0x29, 0xC2, 0x4C, 0x8B, 0x55, 0x30, 0x49, 0x39, 0xCA, 0x72, 0x03, 0x49, 0x89, 0xCA, 0x49, 0x39, 0xD2, 0x72, 0x03, 0x49, 0x89, 0xD2, 0x4C, 0x89, 0xD1, 0x48, 0x8B, 0x55, 0x38, 0x48, 0x8B, 0x7D, 0xD0, 0x48, 0x8B, 0x75, 0xB0, 0x45, 0x0F, 0x20, 0xC1, 0x49, 0x83, 0xF9, 0x02, 0x7D, 0x0B, 0x48, 0xC7, 0xC0, 0x02, 0x00, 0x00, 0x00, 0x44, 0x0F, 0x22, 0xC0, 0xFA, 0x41, 0x0F, 0x20, 0xD8, 0x0F, 0x22, 0xDA, 0xF3, 0xA4, 0x41, 0x0F, 0x22, 0xD8, 0xFB, 0x45, 0x0F, 0x22, 0xC1, 0x4C, 0x89, 0xD0, 0x5E, 0x5F, 0x48, 0x89, 0xEC, 0x5D, 0xC3, 0x48, 0x85, 0xC9, 0x75, 0x0F, 0x48, 0xB8, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xE9, 0x1C, 0x01, 0x00, 0x00, 0x48, 0x85, 0xD2, 0x75, 0x0F, 0x48, 0xB8, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xE9, 0x08, 0x01, 0x00, 0x00, 0x48, 0x89, 0xD0, 0x48, 0xC1, 0xE8, 0x30, 0x48, 0x85, 0xC0, 0x74, 0x1B, 0x49, 0xC7, 0xC2, 0xFF, 0xFF, 0x00, 0x00, 0x4C, 0x39, 0xD0, 0x74, 0x0F, 0x48, 0xB8, 0x02, 0x00, 0x03, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xE9, 0xE1, 0x00, 0x00, 0x00, 0x4D, 0x89, 0xCB, 0x49, 0x89, 0xD2, 0x49, 0xC1, 0xE2, 0x10, 0x4C, 0x89, 0xD2, 0x48, 0xC1, 0xEA, 0x37, 0xE8, 0xCC, 0x00, 0x00, 0x00, 0x48, 0x89, 0xC1, 0x48, 0x0F, 0xBA, 0xE1, 0x00, 0x72, 0x0F, 0x48, 0xB8, 0x02, 0x00, 0x04, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xE9, 0xB2, 0x00, 0x00, 0x00, 0x49, 0xC1, 0xE2, 0x09, 0x4C, 0x89, 0xD2, 0x48, 0xC1, 0xEA, 0x37, 0xE8, 0xA3, 0x00, 0x00, 0x00, 0x48, 0x89, 0xC1, 0x48, 0x0F, 0xBA, 0xE1, 0x00, 0x72, 0x0F, 0x48, 0xB8, 0x02, 0x00, 0x05, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xE9, 0x89, 0x00, 0x00, 0x00, 0x48, 0x0F, 0xBA, 0xE1, 0x07, 0x73, 0x0C, 0x48, 0xB8, 0x03, 0x00, 0x05, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xEB, 0x76, 0x49, 0xC1, 0xE2, 0x09, 0x4C, 0x89, 0xD2, 0x48, 0xC1, 0xEA, 0x37, 0xE8, 0x67, 0x00, 0x00, 0x00, 0x48, 0x89, 0xC1, 0x48, 0x0F, 0xBA, 0xE1, 0x00, 0x72, 0x0C, 0x48, 0xB8, 0x02, 0x00, 0x06, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xEB, 0x50, 0x48, 0x0F, 0xBA, 0xE1, 0x07, 0x73, 0x0C, 0x48, 0xB8, 0x03, 0x00, 0x06, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xEB, 0x3D, 0x49, 0xC1, 0xE2, 0x09, 0x4C, 0x89, 0xD2, 0x48, 0xC1, 0xEA, 0x37, 0x49, 0xB9, 0x00, 0xF0, 0xFF, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x4C, 0x21, 0xC9, 0x4C, 0x8D, 0x0C, 0xD1, 0x4D, 0x89, 0x0B, 0xE8, 0x1A, 0x00, 0x00, 0x00, 0x48, 0x89, 0xC1, 0x48, 0x0F, 0xBA, 0xE1, 0x00, 0x72, 0x0C, 0x48, 0xB8, 0x02, 0x00, 0x07, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xEB, 0x03, 0x48, 0x89, 0xC8, 0xC3, 0x49, 0xB9, 0x00, 0xF0, 0xFF, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x4C, 0x21, 0xC9, 0x48, 0x8D, 0x0C, 0xD1, 0x4C, 0x89, 0xC2, 0xE8, 0x01, 0x00, 0x00, 0x00, 0xC3, 0x45, 0x0F, 0x20, 0xC1, 0x49, 0x83, 0xF9, 0x02, 0x7D, 0x0B, 0x48, 0xC7, 0xC0, 0x02, 0x00, 0x00, 0x00, 0x44, 0x0F, 0x22, 0xC0, 0xFA, 0x41, 0x0F, 0x20, 0xD8, 0x0F, 0x22, 0xDA, 0x48, 0x8B, 0x01, 0x41, 0x0F, 0x22, 0xD8, 0xFB, 0x45, 0x0F, 0x22, 0xC1, 0x49, 0x89, 0xD0, 0xC3 };
/*
; returns bytes copyed or errorcore
; ULONG64 copy_size_pre(copy_size_params* ppar, SIZE_T sz)	
0:  55                      push   rbp
1:  48 89 e5                mov    rbp,rsp
4:  48 85 c9                test   rcx,rcx
7:  48 b8 01 00 09 00 00    movabs rax,0xffff000000090001
e:  00 ff ff
11: 74 46                   je     59 <copy_size_pre_ret>
13: 48 85 d2                test   rdx,rdx
16: 48 b8 01 00 09 00 01    movabs rax,0xffff000100090001
1d: 00 ff ff
20: 74 37                   je     59 <copy_size_pre_ret>
22: 48 c7 c0 30 00 00 00    mov    rax,0x30
29: 48 85 c2                test   rdx,rax
2c: 48 b8 02 00 09 00 01    movabs rax,0xffff000100090002
33: 00 ff ff
36: 74 21                   je     59 <copy_size_pre_ret>
38: 48 89 c8                mov    rax,rcx
3b: 48 8b 08                mov    rcx,QWORD PTR [rax]
3e: 48 8b 50 08             mov    rdx,QWORD PTR [rax+0x8]
42: 4c 8b 40 10             mov    r8,QWORD PTR [rax+0x10]
46: 4c 8b 48 18             mov    r9,QWORD PTR [rax+0x18]
4a: ff 70 20                push   QWORD PTR [rax+0x20]
4d: ff 70 28                push   QWORD PTR [rax+0x28]
50: 48 83 ec 20             sub    rsp,0x20
54: e8 05 00 00 00          call   5e <copy_page>
0000000000000059 <copy_size_pre_ret>:
59: 48 89 ec                mov    rsp,rbp
5c: 5d                      pop    rbp
5d: c3                      ret
; returns bytes copyed or errorcore
; ULONG64 copy_page(PVOID Cr3_Dest, PVOID VA_Dest, PVOID Cr3_Src, PVOID VA_Src, PVOID Cr3_Phys, SIZE_T Size)
000000000000005e <copy_page>:
5e: 55                      push   rbp
5f: 48 89 e5                mov    rbp,rsp
62: 57                      push   rdi
63: 56                      push   rsi
64: 48 89 4d 10             mov    QWORD PTR [rbp+0x10],rcx
68: 48 89 55 18             mov    QWORD PTR [rbp+0x18],rdx
6c: 4c 89 45 20             mov    QWORD PTR [rbp+0x20],r8
70: 4c 89 4d 28             mov    QWORD PTR [rbp+0x28],r9
74: 48 8b 45 30             mov    rax,QWORD PTR [rbp+0x30]
78: 48 85 c0                test   rax,rax
7b: 48 b8 01 00 00 00 01    movabs rax,0xffff000100000001
82: 00 ff ff
85: 0f 84 5c 01 00 00       je     1e7 <cm_ret>
8b: 4c 8b 45 38             mov    r8,QWORD PTR [rbp+0x38]
8f: 4d 85 c0                test   r8,r8
92: 48 b8 01 00 01 00 04    movabs rax,0xffff000400010001
99: 00 ff ff
9c: 0f 84 45 01 00 00       je     1e7 <cm_ret>
a2: 48 83 ec 20             sub    rsp,0x20
a6: 4c 8d 4d e8             lea    r9,[rbp-0x18]
aa: e8 3f 01 00 00          call   1ee <get_pte>
af: 49 ba 00 00 00 00 00    movabs r10,0xffff000000000000
b6: 00 ff ff
b9: 4c 39 d0                cmp    rax,r10
bc: 72 12                   jb     d0 <cm_pte_dest_valid>
be: 48 b9 00 00 00 00 03    movabs rcx,0x300000000
c5: 00 00 00
c8: 48 09 c8                or     rax,rcx
cb: e9 17 01 00 00          jmp    1e7 <cm_ret>
00000000000000d0 <cm_pte_dest_valid>:
d0: 48 89 45 e0             mov    QWORD PTR [rbp-0x20],rax
d4: 48 b9 00 f0 ff ff 0f    movabs rcx,0xffffff000
db: 00 00 00
de: 48 21 c8                and    rax,rcx
e1: 48 85 c0                test   rax,rax
e4: 75 0f                   jne    f5 <cm_pte_dest_pa>
e6: 48 b8 01 00 08 00 03    movabs rax,0xffff000300080001
ed: 00 ff ff
f0: e9 f2 00 00 00          jmp    1e7 <cm_ret>
00000000000000f5 <cm_pte_dest_pa>:
f5: 48 8b 55 18             mov    rdx,QWORD PTR [rbp+0x18]
f9: 48 c7 c1 ff 0f 00 00    mov    rcx,0xfff
100:    48 21 ca                and    rdx,rcx
103:    48 89 55 d8             mov    QWORD PTR [rbp-0x28],rdx
107:    48 09 d0                or     rax,rdx
10a:    48 89 45 d0             mov    QWORD PTR [rbp-0x30],rax
10e:    48 83 ec 18             sub    rsp,0x18
112:    48 8b 4d 20             mov    rcx,QWORD PTR [rbp+0x20]
116:    48 8b 55 28             mov    rdx,QWORD PTR [rbp+0x28]
11a:    4c 8d 4d c8             lea    r9,[rbp-0x38]
11e:    e8 cb 00 00 00          call   1ee <get_pte>
123:    49 ba 00 00 00 00 00    movabs r10,0xffff000000000000
12a:    00 ff ff
12d:    4c 39 d0                cmp    rax,r10
130:    72 0d                   jb     13f <cm_pte_scr_valid>
132:    48 b9 00 00 00 00 03    movabs rcx,0x300000000
139:    00 00 00
13c:    48 09 c8                or     rax,rcx
000000000000013f <cm_pte_scr_valid>:
13f:    48 89 45 c0             mov    QWORD PTR [rbp-0x40],rax
143:    48 b9 00 f0 ff ff 0f    movabs rcx,0xffffff000
14a:    00 00 00
14d:    48 21 c8                and    rax,rcx
150:    48 85 c0                test   rax,rax
153:    75 0f                   jne    164 <cm_pte_scr_pa>
155:    48 b8 01 00 08 00 02    movabs rax,0xffff000200080001
15c:    00 ff ff
15f:    e9 83 00 00 00          jmp    1e7 <cm_ret>
0000000000000164 <cm_pte_scr_pa>:
164:    48 8b 55 28             mov    rdx,QWORD PTR [rbp+0x28]
168:    48 c7 c1 ff 0f 00 00    mov    rcx,0xfff
16f:    48 21 ca                and    rdx,rcx
172:    48 89 55 b8             mov    QWORD PTR [rbp-0x48],rdx
176:    48 09 d0                or     rax,rdx
179:    48 89 45 b0             mov    QWORD PTR [rbp-0x50],rax
17d:    48 8b 45 d8             mov    rax,QWORD PTR [rbp-0x28]
181:    48 c7 c1 00 10 00 00    mov    rcx,0x1000
188:    48 29 c1                sub    rcx,rax
18b:    48 8b 45 b8             mov    rax,QWORD PTR [rbp-0x48]
18f:    48 c7 c2 00 10 00 00    mov    rdx,0x1000
196:    48 29 c2                sub    rdx,rax
199:    4c 8b 55 30             mov    r10,QWORD PTR [rbp+0x30]
19d:    49 39 ca                cmp    r10,rcx
1a0:    72 03                   jb     1a5 <cm_check_rdx>
1a2:    49 89 ca                mov    r10,rcx
00000000000001a5 <cm_check_rdx>:
1a5:    49 39 d2                cmp    r10,rdx
1a8:    72 03                   jb     1ad <peform_physical_copy>
1aa:    49 89 d2                mov    r10,rdx
00000000000001ad <peform_physical_copy>:
1ad:    4c 89 d1                mov    rcx,r10
1b0:    48 8b 55 38             mov    rdx,QWORD PTR [rbp+0x38]
1b4:    48 8b 7d d0             mov    rdi,QWORD PTR [rbp-0x30]
1b8:    48 8b 75 b0             mov    rsi,QWORD PTR [rbp-0x50]
1bc:    45 0f 20 c1             mov    r9,cr8
1c0:    49 83 f9 02             cmp    r9,0x2
1c4:    7d 0b                   jge    1d1 <cm_disable_int>
1c6:    48 c7 c0 02 00 00 00    mov    rax,0x2
1cd:    44 0f 22 c0             mov    cr8,rax
00000000000001d1 <cm_disable_int>:
1d1:    fa                      cli
1d2:    41 0f 20 d8             mov    r8,cr3
1d6:    0f 22 da                mov    cr3,rdx
1d9:    f3 a4                   rep movs BYTE PTR es:[rdi],BYTE PTR ds:[rsi]
1db:    41 0f 22 d8             mov    cr3,r8
1df:    fb                      sti
1e0:    45 0f 22 c1             mov    cr8,r9
1e4:    4c 89 d0                mov    rax,r10
00000000000001e7 <cm_ret>:
1e7:    5e                      pop    rsi
1e8:    5f                      pop    rdi
1e9:    48 89 ec                mov    rsp,rbp
1ec:    5d                      pop    rbp
1ed:    c3                      ret
; rcx = CR3
; rdx = VA
; r8  = phys_cr3
; r9  = pPA_PTE
00000000000001ee <get_pte>:
1ee:    48 85 c9                test   rcx,rcx
1f1:    75 0f                   jne    202 <cr3_not_zero>
1f3:    48 b8 01 00 01 00 00    movabs rax,0xffff000000010001
1fa:    00 ff ff
1fd:    e9 1c 01 00 00          jmp    31e <return>
0000000000000202 <cr3_not_zero>:
202:    48 85 d2                test   rdx,rdx
205:    75 0f                   jne    216 <va_not_zero>
207:    48 b8 01 00 02 00 00    movabs rax,0xffff000000020001
20e:    00 ff ff
211:    e9 08 01 00 00          jmp    31e <return>
0000000000000216 <va_not_zero>:
216:    48 89 d0                mov    rax,rdx
219:    48 c1 e8 30             shr    rax,0x30
21d:    48 85 c0                test   rax,rax
220:    74 1b                   je     23d <partition_valid>
222:    49 c7 c2 ff ff 00 00    mov    r10,0xffff
229:    4c 39 d0                cmp    rax,r10
22c:    74 0f                   je     23d <partition_valid>
22e:    48 b8 02 00 03 00 00    movabs rax,0xffff000000030002
235:    00 ff ff
238:    e9 e1 00 00 00          jmp    31e <return>
000000000000023d <partition_valid>:
23d:    4d 89 cb                mov    r11,r9
240:    49 89 d2                mov    r10,rdx
0000000000000243 <get_pml4_index>:
243:    49 c1 e2 10             shl    r10,0x10
247:    4c 89 d2                mov    rdx,r10
24a:    48 c1 ea 37             shr    rdx,0x37
24e:    e8 cc 00 00 00          call   31f <entry_to_entry>
253:    48 89 c1                mov    rcx,rax
256:    48 0f ba e1 00          bt     rcx,0x0
25b:    72 0f                   jb     26c <get_pdp_index>
25d:    48 b8 02 00 04 00 00    movabs rax,0xffff000000040002
264:    00 ff ff
267:    e9 b2 00 00 00          jmp    31e <return>
000000000000026c <get_pdp_index>:
26c:    49 c1 e2 09             shl    r10,0x9
270:    4c 89 d2                mov    rdx,r10
273:    48 c1 ea 37             shr    rdx,0x37
277:    e8 a3 00 00 00          call   31f <entry_to_entry>
27c:    48 89 c1                mov    rcx,rax
27f:    48 0f ba e1 00          bt     rcx,0x0
284:    72 0f                   jb     295 <is_pdp_large>
286:    48 b8 02 00 05 00 00    movabs rax,0xffff000000050002
28d:    00 ff ff
290:    e9 89 00 00 00          jmp    31e <return>
0000000000000295 <is_pdp_large>:
295:    48 0f ba e1 07          bt     rcx,0x7
29a:    73 0c                   jae    2a8 <get_pd_index>
29c:    48 b8 03 00 05 00 00    movabs rax,0xffff000000050003
2a3:    00 ff ff
2a6:    eb 76                   jmp    31e <return>
00000000000002a8 <get_pd_index>:
2a8:    49 c1 e2 09             shl    r10,0x9
2ac:    4c 89 d2                mov    rdx,r10
2af:    48 c1 ea 37             shr    rdx,0x37
2b3:    e8 67 00 00 00          call   31f <entry_to_entry>
2b8:    48 89 c1                mov    rcx,rax
2bb:    48 0f ba e1 00          bt     rcx,0x0
2c0:    72 0c                   jb     2ce <is_pd_large>
2c2:    48 b8 02 00 06 00 00    movabs rax,0xffff000000060002
2c9:    00 ff ff
2cc:    eb 50                   jmp    31e <return>
00000000000002ce <is_pd_large>:
2ce:    48 0f ba e1 07          bt     rcx,0x7
2d3:    73 0c                   jae    2e1 <get_pt_index>
2d5:    48 b8 03 00 06 00 00    movabs rax,0xffff000000060003
2dc:    00 ff ff
2df:    eb 3d                   jmp    31e <return>
00000000000002e1 <get_pt_index>:
2e1:    49 c1 e2 09             shl    r10,0x9
2e5:    4c 89 d2                mov    rdx,r10
2e8:    48 c1 ea 37             shr    rdx,0x37
2ec:    49 b9 00 f0 ff ff 0f    movabs r9,0xffffff000
2f3:    00 00 00
2f6:    4c 21 c9                and    rcx,r9
2f9:    4c 8d 0c d1             lea    r9,[rcx+rdx*8]
2fd:    4d 89 0b                mov    QWORD PTR [r11],r9
300:    e8 1a 00 00 00          call   31f <entry_to_entry>
305:    48 89 c1                mov    rcx,rax
308:    48 0f ba e1 00          bt     rcx,0x0
30d:    72 0c                   jb     31b <return_pte>
30f:    48 b8 02 00 07 00 00    movabs rax,0xffff000000070002
316:    00 ff ff
319:    eb 03                   jmp    31e <return>
000000000000031b <return_pte>:
31b:    48 89 c8                mov    rax,rcx
000000000000031e <return>:
31e:    c3                      ret
000000000000031f <entry_to_entry>:
31f:    49 b9 00 f0 ff ff 0f    movabs r9,0xffffff000
326:    00 00 00
329:    4c 21 c9                and    rcx,r9
32c:    48 8d 0c d1             lea    rcx,[rcx+rdx*8]
330:    4c 89 c2                mov    rdx,r8
333:    e8 01 00 00 00          call   339 <get_phys_qword>
338:    c3                      ret
0000000000000339 <get_phys_qword>:
339:    45 0f 20 c1             mov    r9,cr8
33d:    49 83 f9 02             cmp    r9,0x2
341:    7d 0b                   jge    34e <disable_int>
343:    48 c7 c0 02 00 00 00    mov    rax,0x2
34a:    44 0f 22 c0             mov    cr8,rax
000000000000034e <disable_int>:
34e:    fa                      cli
34f:    41 0f 20 d8             mov    r8,cr3
353:    0f 22 da                mov    cr3,rdx
356:    48 8b 01                mov    rax,QWORD PTR [rcx]
359:    41 0f 22 d8             mov    cr3,r8
35d:    fb                      sti
35e:    45 0f 22 c1             mov    cr8,r9
362:    49 89 d0                mov    r8,rdx
365:    c3                      ret
 */

ULONG64 mem_mgr::_MmGetVirtualForPhysical(const ULONG64 PA) const
{
	return this->r0->call(this->r0_MmGetVirtualForPhysical, PA);
}

BOOLEAN mem_mgr::_MmIsAddressValid(const ULONG64 VA) const
{
	return this->r0->call(this->r0_MmIsAddressValid, VA);
}

long long mem_mgr::_KeFlushCurrentTbImmediately() const
{
	return this->r0->call(this->r0_KeFlushCurrentTbImmediately);
}

ULONG64 mem_mgr::_MmAllocateContiguousMemory(SIZE_T NumberOfBytes, ULONG64 HighestAcceptableAddress) const
{
	return this->r0->call(this->r0_MmAllocateContiguousMemory, NumberOfBytes, HighestAcceptableAddress);
}

void mem_mgr::_MmFreeContiguousMemory(PVOID BaseAddress) const
{
	this->r0->call(this->r0_MmFreeContiguousMemory, reinterpret_cast<ULONG64>(BaseAddress));
}

void mem_mgr::set_pfn_PA(const ULONG64 PA_PTE, const ULONG64 Orig, const ULONG64 PFN) const
{
	// change pfn
	const auto Edit = (Orig & (~0xFFFFFF000ui64)) | (PFN << 0xC);
	// overwrite pte
	this->phys->S_PA_QWORD(PA_PTE, Edit);
	// flush tlb
	this->_KeFlushCurrentTbImmediately();
}

void mem_mgr::print_errorcode(const ULONG64 error)
{
	std::cout << "[!] "; PRINTVAR(error, "%llx");
	if ((error & 0xFFFF000000000000) == 0xFFFF000000000000)
	{
		std::cout << "    Error";
		switch ((error & 0x0000FFFF00000000) >> 32)
		{
		case 0: std::cout << " Generic"; break;
		case 1: std::cout << " Size"; break;
		case 2: std::cout << " Src"; break;
		case 3: std::cout << " Dest"; break;
		case 4: std::cout << " Phys"; break;
		default: std::cout << " Unknown"; break;
		}
		switch ((error & 0x00000000FFFF0000) >> 16)
		{
		case 0: std::cout << " Generic"; break;
		case 1: std::cout << " CR3"; break;
		case 2: std::cout << " VA"; break;
		case 3: std::cout << " Partition"; break;
		case 4: std::cout << " PML4"; break;
		case 5: std::cout << " PDP"; break;
		case 6: std::cout << " PD"; break;
		case 7: std::cout << " PT"; break;
		case 8: std::cout << " PA"; break;
		case 9: std::cout << " Params"; break;
		default: std::cout << " Unknown"; break;
		}
		switch ((error & 0x000000000000FFFF))
		{
		case 0: std::cout << " Generic"; break;
		case 1: std::cout << " Zero"; break;
		case 2: std::cout << " Invalid"; break;
		case 3: std::cout << " LargePage"; break;
		default: std::cout << " Unknown"; break;
		}
		std::cout << std::endl;
	}
}

mem_mgr::PAGE_INFO mem_mgr::page_info_virtual(PVOID VA) const
{
	if (!VA)
	{
		std::cout << "[!] "; PRINTVAR(VA, "%llx");
		return { nullptr,0,0, { 0, 0 , 0, 0 } };
	}

	const auto pMMVA = reinterpret_cast<PMMVA>(&VA);
	if (pMMVA->Partition != 0x0000 && pMMVA->Partition != 0xFFFF)
	{
		std::cout << "[!] "; PRINTVAR(pMMVA->Partition, "%llx");
		return { nullptr,0,0, { 0, 0 , 0, 0 } };
	}

	const auto PFN_pml4t = bit_field<uint64_t>(offset::_MMPTE_HARDWARE::PageFrameNumber, (void*)&this->cr3);

	const auto PA_pml4t_base = PFN_pml4t << offset::_MMPTE_HARDWARE::PageFrameNumber.bit;
	const auto PA_pml4t_entry = PA_pml4t_base + (pMMVA->PML4T * sizeof(_MMPTE));
	const auto VA_pml4t_entry = this->_MmGetVirtualForPhysical(PA_pml4t_entry);
	if (!this->_MmIsAddressValid(VA_pml4t_entry))
	{
		std::cout << "[!] VA_pml4t_entry MmIsAddressValid failed" << std::endl;
		return { nullptr,0,0, { 0, 0 , 0, 0 } };
	}
	const _MMPTE pml4t_entry = this->r0->G_R0_QWORD(VA_pml4t_entry);
	if (bit_field<uint64_t>(offset::_MMPTE_HARDWARE::Valid, (void*)&pml4t_entry) != 1)
	{
		std::cout << "[!] pml4t_entry invalid" << std::endl;
		return { nullptr,0,0, { 0, 0 , 0, 0 } };
	}

	const auto PFN_pdpt = bit_field<uint64_t>(offset::_MMPTE_HARDWARE::PageFrameNumber, (void*)&pml4t_entry);

	const auto PA_pdpt_base = PFN_pdpt << offset::_MMPTE_HARDWARE::PageFrameNumber.bit;
	const auto PA_pdpt_entry = PA_pdpt_base + (pMMVA->PDPT * sizeof(_MMPTE));
	const auto VA_pdpt_entry = this->_MmGetVirtualForPhysical(PA_pdpt_entry);
	if (!this->_MmIsAddressValid(VA_pdpt_entry))
	{
		std::cout << "[!] VA_pdpt_entry MmIsAddressValid failed" << std::endl;
		return { nullptr,0,0, { 0, 0 , 0, 0 } };
	}
	const _MMPTE pdpt_entry = this->r0->G_R0_QWORD(VA_pdpt_entry);
	if (bit_field<uint64_t>(offset::_MMPTE_HARDWARE::Valid, (void*)&pdpt_entry) != 1)
	{
		std::cout << "[!] pdpt_entry invalid" << std::endl;
		return { nullptr,0,0, { 0, 0 , 0, 0 } };
	}

	const auto PFN_pdt = bit_field<uint64_t>(offset::_MMPTE_HARDWARE::PageFrameNumber, (void*)&pdpt_entry);
	if (bit_field<uint64_t>(offset::_MMPTE_HARDWARE::LargePage, (void*)&pdpt_entry) == 1)
	{
		std::cout << "[!] 4GB largepage" << std::endl;
		return { nullptr,0,0, { 0, 0 , 0, 0 } };
	}

	const auto PA_pdt_base = PFN_pdt << offset::_MMPTE_HARDWARE::PageFrameNumber.bit;
	const auto PA_pdt_entry = PA_pdt_base + (pMMVA->PDT * sizeof(_MMPTE));
	const auto VA_pdt_entry = this->_MmGetVirtualForPhysical(PA_pdt_entry);
	if (!this->_MmIsAddressValid(VA_pdt_entry))
	{
		std::cout << "[!] VA_pdt_entry MmIsAddressValid failed" << std::endl;
		return { nullptr,0,0, { 0, 0 , 0, 0 } };
	}
	const _MMPTE pdt_entry = this->r0->G_R0_QWORD(VA_pdt_entry);
	if (bit_field<uint64_t>(offset::_MMPTE_HARDWARE::Valid, (void*)&pdt_entry) != 1)
	{
		std::cout << "[!] pdt_entry invalid" << std::endl;
		return { nullptr,0,0, { 0, 0 , 0, 0 } };
	}

	const auto PFN_pt = bit_field<uint64_t>(offset::_MMPTE_HARDWARE::PageFrameNumber, (void*)&pdt_entry);
	if (bit_field<uint64_t>(offset::_MMPTE_HARDWARE::LargePage, (void*)&pdt_entry) == 1)
	{
		std::cout << "[!] 2MB largepage" << std::endl;
		return { nullptr,0,0, { 0, 0 , 0, 0 } };
	}

	const auto PA_pt_base = bit_field<uint64_t>(offset::_MMPTE_HARDWARE::PageFrameNumber, (void*)&pdt_entry) << offset::_MMPTE_HARDWARE::PageFrameNumber.bit;
	const auto PA_pt_entry = PA_pt_base + (pMMVA->PT * sizeof(_MMPTE));
	const auto VA_pt_entry = this->_MmGetVirtualForPhysical(PA_pt_entry);
	if (!this->_MmIsAddressValid(VA_pt_entry))
	{
		std::cout << "[!] VA_pt_entry MmIsAddressValid failed" << std::endl;
		return { nullptr,0,0, { 0, 0 , 0, 0 } };
	}
	const _MMPTE pt_entry = this->r0->G_R0_QWORD(VA_pt_entry);
	if (bit_field<uint64_t>(offset::_MMPTE_HARDWARE::Valid, (void*)&pt_entry) != 1)
	{
		std::cout << "[!] pt_entry invalid" << std::endl;
		return { nullptr,0,0, { 0, 0 , 0, 0 } };
	}

	const auto PFN_p = bit_field<uint64_t>(offset::_MMPTE_HARDWARE::PageFrameNumber, (void*)&pt_entry);
	return {
		reinterpret_cast<PVOID>(PFN_p * 0x1000),
		pMMVA->Offset,
		0x1000ui64,
		{
			pt_entry,
			PFN_p,
			PA_pt_entry,
			VA_pt_entry
		}
	};
}

mem_mgr::PAGE_INFO mem_mgr::page_info_physical(PVOID VA) const
{
	if (!VA)
	{
		std::cout << "[!] "; PRINTVAR(VA, "%llx");
		return { nullptr,0,0, { 0, 0 , 0, 0 } };
	}

	const auto pMMVA = reinterpret_cast<PMMVA>(&VA);
	if (pMMVA->Partition != 0x0000 && pMMVA->Partition != 0xFFFF)
	{
		std::cout << "[!] "; PRINTVAR(pMMVA->Partition, "%llx");
		std::cout << "    "; PRINTVAR(VA, "%llx");
		return { nullptr,0,0, { 0, 0 , 0, 0 } };
	}

	const auto PFN_pml4t = bit_field<uint64_t>(offset::_MMPTE_HARDWARE::PageFrameNumber, (void*)&this->cr3);

	const auto PA_pml4t_base = PFN_pml4t << offset::_MMPTE_HARDWARE::PageFrameNumber.bit;
	const auto PA_pml4t_entry = PA_pml4t_base + (pMMVA->PML4T * sizeof(_MMPTE));
	const _MMPTE pml4t_entry = this->phys->G_PA_QWORD(PA_pml4t_entry);
	if (bit_field<uint64_t>(offset::_MMPTE_HARDWARE::Valid, (void*)&pml4t_entry) != 1)
	{
		std::cout << "[!] pml4t_entry invalid" << std::endl;
		return { nullptr,0,0, { 0, 0 , 0, 0 } };
	}

	const auto PFN_pdpt = bit_field<uint64_t>(offset::_MMPTE_HARDWARE::PageFrameNumber, (void*)&pml4t_entry);

	const auto PA_pdpt_base = PFN_pdpt << offset::_MMPTE_HARDWARE::PageFrameNumber.bit;
	const auto PA_pdpt_entry = PA_pdpt_base + (pMMVA->PDPT * sizeof(_MMPTE));
	const _MMPTE pdpt_entry = this->phys->G_PA_QWORD(PA_pdpt_entry);
	if (bit_field<uint64_t>(offset::_MMPTE_HARDWARE::Valid, (void*)&pdpt_entry) != 1)
	{
		std::cout << "[!] pdpt_entry invalid" << std::endl;
		return { nullptr,0,0, { 0, 0 , 0, 0 } };
	}

	const auto PFN_pdt = bit_field<uint64_t>(offset::_MMPTE_HARDWARE::PageFrameNumber, (void*)&pdpt_entry);
	if (bit_field<uint64_t>(offset::_MMPTE_HARDWARE::LargePage, (void*)&pdpt_entry) == 1)
	{
		std::cout << "[*] 1GB Large Page" << std::endl;
		return {
			reinterpret_cast<PVOID>(PFN_pdt * 0x1000 * 0x200 * 0x200),
			(pMMVA->PDT << 21) | (pMMVA->PT << 12) | pMMVA->Offset,
			0x1000ui64 * 0x200ui64 * 0x200ui64, // 1GB
			{
				pdpt_entry,
				PFN_pdt,
				PA_pdpt_entry,
				0
			}
		};
	}

	const auto PA_pdt_base = PFN_pdt << offset::_MMPTE_HARDWARE::PageFrameNumber.bit;
	const auto PA_pdt_entry = PA_pdt_base + (pMMVA->PDT * sizeof(_MMPTE));
	const _MMPTE pdt_entry = this->phys->G_PA_QWORD(PA_pdt_entry);
	if (bit_field<uint64_t>(offset::_MMPTE_HARDWARE::Valid, (void*)&pdt_entry) != 1)
	{
		std::cout << "[!] pdt_entry invalid" << std::endl;
		return { nullptr,0,0, { 0, 0 , 0, 0 } };
	}

	const auto PFN_pt = bit_field<uint64_t>(offset::_MMPTE_HARDWARE::PageFrameNumber, (void*)&pdt_entry);
	if (bit_field<uint64_t>(offset::_MMPTE_HARDWARE::LargePage, (void*)&pdt_entry) == 1)
	{
		std::cout << "[*] 2MB Large Page" << std::endl;
		return {
			reinterpret_cast<PVOID>(PFN_pt * 0x1000 * 0x200),
			(pMMVA->PT << 12) | pMMVA->Offset,
			0x1000ui64 * 0x200ui64,	// 2MB
			{
				pdt_entry,
				PFN_pt,
				PA_pdt_entry,
				0
			}
		};
	}

	const auto PA_pt_base = bit_field<uint64_t>(offset::_MMPTE_HARDWARE::PageFrameNumber, (void*)&pdt_entry) << offset::_MMPTE_HARDWARE::PageFrameNumber.bit;
	const auto PA_pt_entry = PA_pt_base + (pMMVA->PT * sizeof(_MMPTE));
	const _MMPTE pt_entry = this->phys->G_PA_QWORD(PA_pt_entry);
	if (bit_field<uint64_t>(offset::_MMPTE_HARDWARE::Valid, (void*)&pt_entry) != 1)
	{
		std::cout << "[!] pt_entry invalid" << std::endl;
		return { nullptr,0,0, { 0, 0 , 0, 0 } };
	}

	const auto PFN_p = bit_field<uint64_t>(offset::_MMPTE_HARDWARE::PageFrameNumber, (void*)&pt_entry);
	return {
		reinterpret_cast<PVOID>(PFN_p * 0x1000),
		pMMVA->Offset,
		0x1000ui64,	// 4KB
		{
			pt_entry,
			PFN_p,
			PA_pt_entry,
			0
		}
	};
}

mem_mgr::PAGE_INFO mem_mgr::page_info_shellcode(PVOID VA) const
{
	ULONG64 PA_PTE = 0;
	if (const auto PT_ENTRY = static_cast<ULONG64>(this->r0->call(
		reinterpret_cast<ULONG64>(this->r0_SC_get_pte),
		this->cr3,
		reinterpret_cast<ULONG64>(VA),
		this->phys->r0_CR3_PHYS,
		reinterpret_cast<ULONG64>(&PA_PTE)
	)); (PT_ENTRY & 0xFFFF000000000000) == 0xFFFF000000000000)
	{
		print_errorcode(PT_ENTRY);
		return { nullptr,0,0,{0,0,0,0} };
	}
	else
	{
		return {
			reinterpret_cast<PVOID>(PT_ENTRY & 0x0000000FFFFFF000),
			reinterpret_cast<PMMVA>(&VA)->Offset,
			0x1000,
			{
				PT_ENTRY,
				(PT_ENTRY & 0x0000000FFFFFF000) >> 12,
				PA_PTE,
				0
			}
		};
	}
}

bool mem_mgr::copy_safe(mem_mgr* mgr_local, PVOID VA_local, PVOID VA_far, SIZE_T bytes, bool write) const
{
	// allocate helper page
	const auto helper = reinterpret_cast<void*>(mgr_local->_MmAllocateContiguousMemory(0x1000));
	if (!helper)
	{
		std::cout << "[!] " << "MmAllocateContiguousMemory failed!" << std::endl;
		return false;
	}

	// get helper page info
	//const auto helper_page = mgr_local->page_info_virtual(helper);
	const auto helper_page = mgr_local->page_info_shellcode(helper);

	// allocating a whole physical page failed
	if (helper_page.offset || helper_page.size != 0x1000)
	{
		std::cout << "[!] "; PRINTVAR(helper_page.offset, "%llx");
		std::cout << "[!] "; PRINTVAR(helper_page.size, "%llx");
		mgr_local->_MmFreeContiguousMemory(helper);
		return false;
	}

	auto ploc = reinterpret_cast<ULONG64>(VA_local);
	for (auto todo = bytes; todo; )
	{
		// get current page info
		//const auto current_page = this->page_info_physical(VA_far);
		const auto current_page = this->page_info_shellcode(VA_far);

		// check for valid page
		if (current_page.size != 0x1000)
		{
			mgr_local->_MmFreeContiguousMemory(helper);
			std::cout << "[!] "; PRINTVAR(current_page.size, "%llx");
			return false;
		}

		const auto pfar = reinterpret_cast<ULONG64>(helper) + current_page.offset;
		const auto size = min(current_page.size - current_page.offset, todo);

		// make helper_page point to current_page
		this->set_pfn_PA(helper_page.extended_info.PA_PTE, helper_page.extended_info.PTE_QWORD, current_page.extended_info.PFN);

		// copy data
		if (write)
			mgr_local->r0->_RtlCopyMemory(reinterpret_cast<PVOID>(pfar), reinterpret_cast<PVOID>(ploc), size);
		else
			mgr_local->r0->_RtlCopyMemory(reinterpret_cast<PVOID>(ploc), reinterpret_cast<PVOID>(pfar), size);

		// restore helper_page
		this->set_pfn_PA(helper_page.extended_info.PA_PTE, helper_page.extended_info.PTE_QWORD, helper_page.extended_info.PFN);

		// decrement bytes to do
		todo -= size;
		// increment local pointer
		ploc += size;
	}

	// free helper page
	mgr_local->_MmFreeContiguousMemory(helper);
	return true;
}

bool mem_mgr::copy_unsafe(mem_mgr* mgr_local, PVOID VA_local, PVOID VA_far, SIZE_T bytes, bool write) const
{
	auto uloc = reinterpret_cast<ULONG64>(VA_local);
	auto ufar = reinterpret_cast<ULONG64>(VA_far);
	for (auto todo = bytes; todo; )
	{
		//const auto pi_loc = mgr_local->page_info_physical(reinterpret_cast<PVOID>(uloc));
		const auto pi_loc = mgr_local->page_info_shellcode(reinterpret_cast<PVOID>(uloc));
		if (!pi_loc.size) return false;
		const auto pa_loc = reinterpret_cast<ULONG64>(pi_loc.base) + pi_loc.offset;

		//const auto pi_far = this->page_info_physical(reinterpret_cast<PVOID>(ufar));
		const auto pi_far = this->page_info_shellcode(reinterpret_cast<PVOID>(ufar));
		if (!pi_far.size) return false;
		const auto pa_far = reinterpret_cast<ULONG64>(pi_far.base) + pi_far.offset;

		const auto sz_now = min(min(pi_loc.size - pi_loc.offset, pi_far.size - pi_far.offset), todo);
		if (!sz_now) return false;

		if (write)
			this->phys->UNSAFE_PHYS_MEMCPY(pa_far, pa_loc, sz_now);
		else
			this->phys->UNSAFE_PHYS_MEMCPY(pa_loc, pa_far, sz_now);

		uloc += sz_now;
		ufar += sz_now;
		todo -= sz_now;
	}
	return true;
}

bool mem_mgr::copy_via_shellcod(mem_mgr* mgr_local, PVOID VA_local, PVOID VA_far, SIZE_T bytes, bool write) const
{
	struct copy_size_params {
		PVOID	_Cr3_Dest;	/* [rcx+0x00] */
		PVOID	_VA_Dest;	/* [rcx+0x08] */
		PVOID	_Cr3_Src;	/* [rcx+0x10] */
		PVOID	_VA_Src;	/* [rcx+0x18] */
		PVOID	_Cr3_Phys;	/* [rcx+0x20] */
		SIZE_T	_Size;		/* [rcx+0x28] */
	} params = {};

	auto _va_dest = reinterpret_cast<ULONG64>(write ? VA_far : VA_local);
	auto _va_src = reinterpret_cast<ULONG64>(write ? VA_local : VA_far);
	
	for ( auto sz = bytes; sz > 0; )
	{
		memset(&params, 0, sizeof(copy_size_params));
		params._Cr3_Dest = reinterpret_cast<PVOID>(write ? this->cr3 : mgr_local->cr3);
		params._VA_Dest = reinterpret_cast<PVOID>(_va_dest);
		params._Cr3_Src = reinterpret_cast<PVOID>(write ? mgr_local->cr3 : this->cr3);
		params._VA_Src = reinterpret_cast<PVOID>(_va_src);
		params._Cr3_Phys = reinterpret_cast<PVOID>(this->phys->r0_CR3_PHYS);
		params._Size = sz;
		const auto retval = static_cast<ULONG64>(this->r0->call(
			reinterpret_cast<ULONG64>(this->r0_SC_copy_size_pre),
			reinterpret_cast<ULONG64>(&params),
			sizeof(copy_size_params)
		));
		if ((retval & 0xFFFF000000000000) == 0xFFFF000000000000)
		{
			print_errorcode(retval);
			return false;
		}
		sz -= retval;
		_va_dest += retval;
		_va_src += retval;
	}
	return true;
}

mem_mgr::mem_mgr(ring0_exec* r0, phys_mem* phys, uint64_t cr3)
	: r0(r0), phys(phys), cr3(cr3)
{
	printf("[+] " __FUNCTION__ "\n");

	this->r0_MmGetVirtualForPhysical = r0->_GetKernelModuleExport(r0->R0_ntoskrnl, "MmGetVirtualForPhysical");
	this->r0_MmIsAddressValid = r0->_GetKernelModuleExport(r0->R0_ntoskrnl, "MmIsAddressValid");
	this->r0_KeFlushCurrentTbImmediately = r0->_GetKernelModuleExport(r0->R0_ntoskrnl, "KeFlushCurrentTbImmediately");
	this->r0_MmAllocateContiguousMemory = r0->_GetKernelModuleExport(r0->R0_ntoskrnl, "MmAllocateContiguousMemory");
	this->r0_MmFreeContiguousMemory = r0->_GetKernelModuleExport(r0->R0_ntoskrnl, "MmFreeContiguousMemory");

	this->r0_SC_copy_size_pre = this->r0->_ExAllocatePool(static_cast<ULONG64>(nt::POOL_TYPE::NonPagedPool), sizeof(SC_copy_size_pre));
	this->r0_SC_copy_page = reinterpret_cast<PVOID>(reinterpret_cast<UINT64>(r0_SC_copy_size_pre) + r0_SC_copy_page_offset);
	this->r0_SC_get_pte = reinterpret_cast<PVOID>(reinterpret_cast<UINT64>(r0_SC_copy_size_pre) + r0_SC_get_pte_offset);
	this->r0->_RtlCopyMemory(this->r0_SC_copy_size_pre, SC_copy_size_pre, sizeof(SC_copy_size_pre));
}

mem_mgr::~mem_mgr()
{
	printf("[-] " __FUNCTION__ "\n");

	this->r0->_ExFreePool(this->r0_SC_copy_size_pre);
}
