
a.out:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 c1 bf 00 00 	mov    0xbfc1(%rip),%rax        # cfd0 <__gmon_start__>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	call   *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	ret

Disassembly of section .plt:

0000000000001020 <free@plt-0x10>:
    1020:	ff 35 ca bf 00 00    	push   0xbfca(%rip)        # cff0 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	ff 25 cc bf 00 00    	jmp    *0xbfcc(%rip)        # cff8 <_GLOBAL_OFFSET_TABLE_+0x10>
    102c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000001030 <free@plt>:
    1030:	ff 25 ca bf 00 00    	jmp    *0xbfca(%rip)        # d000 <free@GLIBC_2.2.5>
    1036:	68 00 00 00 00       	push   $0x0
    103b:	e9 e0 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001040 <putchar@plt>:
    1040:	ff 25 c2 bf 00 00    	jmp    *0xbfc2(%rip)        # d008 <putchar@GLIBC_2.2.5>
    1046:	68 01 00 00 00       	push   $0x1
    104b:	e9 d0 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001050 <puts@plt>:
    1050:	ff 25 ba bf 00 00    	jmp    *0xbfba(%rip)        # d010 <puts@GLIBC_2.2.5>
    1056:	68 02 00 00 00       	push   $0x2
    105b:	e9 c0 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001060 <write@plt>:
    1060:	ff 25 b2 bf 00 00    	jmp    *0xbfb2(%rip)        # d018 <write@GLIBC_2.2.5>
    1066:	68 03 00 00 00       	push   $0x3
    106b:	e9 b0 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001070 <strlen@plt>:
    1070:	ff 25 aa bf 00 00    	jmp    *0xbfaa(%rip)        # d020 <strlen@GLIBC_2.2.5>
    1076:	68 04 00 00 00       	push   $0x4
    107b:	e9 a0 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001080 <__stack_chk_fail@plt>:
    1080:	ff 25 a2 bf 00 00    	jmp    *0xbfa2(%rip)        # d028 <__stack_chk_fail@GLIBC_2.4>
    1086:	68 05 00 00 00       	push   $0x5
    108b:	e9 90 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001090 <printf@plt>:
    1090:	ff 25 9a bf 00 00    	jmp    *0xbf9a(%rip)        # d030 <printf@GLIBC_2.2.5>
    1096:	68 06 00 00 00       	push   $0x6
    109b:	e9 80 ff ff ff       	jmp    1020 <_init+0x20>

00000000000010a0 <close@plt>:
    10a0:	ff 25 92 bf 00 00    	jmp    *0xbf92(%rip)        # d038 <close@GLIBC_2.2.5>
    10a6:	68 07 00 00 00       	push   $0x7
    10ab:	e9 70 ff ff ff       	jmp    1020 <_init+0x20>

00000000000010b0 <read@plt>:
    10b0:	ff 25 8a bf 00 00    	jmp    *0xbf8a(%rip)        # d040 <read@GLIBC_2.2.5>
    10b6:	68 08 00 00 00       	push   $0x8
    10bb:	e9 60 ff ff ff       	jmp    1020 <_init+0x20>

00000000000010c0 <syscall@plt>:
    10c0:	ff 25 82 bf 00 00    	jmp    *0xbf82(%rip)        # d048 <syscall@GLIBC_2.2.5>
    10c6:	68 09 00 00 00       	push   $0x9
    10cb:	e9 50 ff ff ff       	jmp    1020 <_init+0x20>

00000000000010d0 <memcpy@plt>:
    10d0:	ff 25 7a bf 00 00    	jmp    *0xbf7a(%rip)        # d050 <memcpy@GLIBC_2.14>
    10d6:	68 0a 00 00 00       	push   $0xa
    10db:	e9 40 ff ff ff       	jmp    1020 <_init+0x20>

00000000000010e0 <malloc@plt>:
    10e0:	ff 25 72 bf 00 00    	jmp    *0xbf72(%rip)        # d058 <malloc@GLIBC_2.2.5>
    10e6:	68 0b 00 00 00       	push   $0xb
    10eb:	e9 30 ff ff ff       	jmp    1020 <_init+0x20>

00000000000010f0 <realloc@plt>:
    10f0:	ff 25 6a bf 00 00    	jmp    *0xbf6a(%rip)        # d060 <realloc@GLIBC_2.2.5>
    10f6:	68 0c 00 00 00       	push   $0xc
    10fb:	e9 20 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001100 <open@plt>:
    1100:	ff 25 62 bf 00 00    	jmp    *0xbf62(%rip)        # d068 <open@GLIBC_2.2.5>
    1106:	68 0d 00 00 00       	push   $0xd
    110b:	e9 10 ff ff ff       	jmp    1020 <_init+0x20>

Disassembly of section .text:

0000000000001110 <_start>:
    1110:	f3 0f 1e fa          	endbr64
    1114:	31 ed                	xor    %ebp,%ebp
    1116:	49 89 d1             	mov    %rdx,%r9
    1119:	5e                   	pop    %rsi
    111a:	48 89 e2             	mov    %rsp,%rdx
    111d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1121:	50                   	push   %rax
    1122:	54                   	push   %rsp
    1123:	45 31 c0             	xor    %r8d,%r8d
    1126:	31 c9                	xor    %ecx,%ecx
    1128:	48 8d 3d a1 7f 00 00 	lea    0x7fa1(%rip),%rdi        # 90d0 <main>
    112f:	ff 15 8b be 00 00    	call   *0xbe8b(%rip)        # cfc0 <__libc_start_main@GLIBC_2.34>
    1135:	f4                   	hlt
    1136:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    113d:	00 00 00 

0000000000001140 <deregister_tm_clones>:
    1140:	48 8d 3d 39 bf 00 00 	lea    0xbf39(%rip),%rdi        # d080 <__TMC_END__>
    1147:	48 8d 05 32 bf 00 00 	lea    0xbf32(%rip),%rax        # d080 <__TMC_END__>
    114e:	48 39 f8             	cmp    %rdi,%rax
    1151:	74 15                	je     1168 <deregister_tm_clones+0x28>
    1153:	48 8b 05 6e be 00 00 	mov    0xbe6e(%rip),%rax        # cfc8 <_ITM_deregisterTMCloneTable>
    115a:	48 85 c0             	test   %rax,%rax
    115d:	74 09                	je     1168 <deregister_tm_clones+0x28>
    115f:	ff e0                	jmp    *%rax
    1161:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1168:	c3                   	ret
    1169:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001170 <register_tm_clones>:
    1170:	48 8d 3d 09 bf 00 00 	lea    0xbf09(%rip),%rdi        # d080 <__TMC_END__>
    1177:	48 8d 35 02 bf 00 00 	lea    0xbf02(%rip),%rsi        # d080 <__TMC_END__>
    117e:	48 29 fe             	sub    %rdi,%rsi
    1181:	48 89 f0             	mov    %rsi,%rax
    1184:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1188:	48 c1 f8 03          	sar    $0x3,%rax
    118c:	48 01 c6             	add    %rax,%rsi
    118f:	48 d1 fe             	sar    $1,%rsi
    1192:	74 14                	je     11a8 <register_tm_clones+0x38>
    1194:	48 8b 05 3d be 00 00 	mov    0xbe3d(%rip),%rax        # cfd8 <_ITM_registerTMCloneTable>
    119b:	48 85 c0             	test   %rax,%rax
    119e:	74 08                	je     11a8 <register_tm_clones+0x38>
    11a0:	ff e0                	jmp    *%rax
    11a2:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    11a8:	c3                   	ret
    11a9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000011b0 <__do_global_dtors_aux>:
    11b0:	f3 0f 1e fa          	endbr64
    11b4:	80 3d c5 be 00 00 00 	cmpb   $0x0,0xbec5(%rip)        # d080 <__TMC_END__>
    11bb:	75 33                	jne    11f0 <__do_global_dtors_aux+0x40>
    11bd:	55                   	push   %rbp
    11be:	48 83 3d 1a be 00 00 	cmpq   $0x0,0xbe1a(%rip)        # cfe0 <__cxa_finalize@GLIBC_2.2.5>
    11c5:	00 
    11c6:	48 89 e5             	mov    %rsp,%rbp
    11c9:	74 0d                	je     11d8 <__do_global_dtors_aux+0x28>
    11cb:	48 8b 3d a6 be 00 00 	mov    0xbea6(%rip),%rdi        # d078 <__dso_handle>
    11d2:	ff 15 08 be 00 00    	call   *0xbe08(%rip)        # cfe0 <__cxa_finalize@GLIBC_2.2.5>
    11d8:	e8 63 ff ff ff       	call   1140 <deregister_tm_clones>
    11dd:	c6 05 9c be 00 00 01 	movb   $0x1,0xbe9c(%rip)        # d080 <__TMC_END__>
    11e4:	5d                   	pop    %rbp
    11e5:	c3                   	ret
    11e6:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    11ed:	00 00 00 
    11f0:	c3                   	ret
    11f1:	0f 1f 40 00          	nopl   0x0(%rax)
    11f5:	66 66 2e 0f 1f 84 00 	data16 cs nopw 0x0(%rax,%rax,1)
    11fc:	00 00 00 00 

0000000000001200 <frame_dummy>:
    1200:	f3 0f 1e fa          	endbr64
    1204:	e9 67 ff ff ff       	jmp    1170 <register_tm_clones>

0000000000001209 <arenaNewBlock>:
    1209:	55                   	push   %rbp
    120a:	48 89 e5             	mov    %rsp,%rbp
    120d:	48 83 ec 20          	sub    $0x20,%rsp
    1211:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    1215:	bf 20 00 00 00       	mov    $0x20,%edi
    121a:	e8 c1 fe ff ff       	call   10e0 <malloc@plt>
    121f:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1223:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    1228:	75 07                	jne    1231 <arenaNewBlock+0x28>
    122a:	b8 00 00 00 00       	mov    $0x0,%eax
    122f:	eb 5d                	jmp    128e <arenaNewBlock+0x85>
    1231:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1235:	48 89 c7             	mov    %rax,%rdi
    1238:	e8 a3 fe ff ff       	call   10e0 <malloc@plt>
    123d:	48 89 c2             	mov    %rax,%rdx
    1240:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1244:	48 89 10             	mov    %rdx,(%rax)
    1247:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    124b:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    124f:	48 89 50 08          	mov    %rdx,0x8(%rax)
    1253:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1257:	48 c7 40 10 00 00 00 	movq   $0x0,0x10(%rax)
    125e:	00 
    125f:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1263:	48 c7 40 18 00 00 00 	movq   $0x0,0x18(%rax)
    126a:	00 
    126b:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    126f:	48 8b 00             	mov    (%rax),%rax
    1272:	48 85 c0             	test   %rax,%rax
    1275:	75 13                	jne    128a <arenaNewBlock+0x81>
    1277:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    127b:	48 89 c7             	mov    %rax,%rdi
    127e:	e8 ad fd ff ff       	call   1030 <free@plt>
    1283:	b8 00 00 00 00       	mov    $0x0,%eax
    1288:	eb 04                	jmp    128e <arenaNewBlock+0x85>
    128a:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    128e:	c9                   	leave
    128f:	c3                   	ret

0000000000001290 <Arena_init>:
    1290:	55                   	push   %rbp
    1291:	48 89 e5             	mov    %rsp,%rbp
    1294:	48 83 ec 10          	sub    $0x10,%rsp
    1298:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    129c:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    12a0:	48 83 7d f0 3f       	cmpq   $0x3f,-0x10(%rbp)
    12a5:	77 08                	ja     12af <Arena_init+0x1f>
    12a7:	48 c7 45 f0 40 00 00 	movq   $0x40,-0x10(%rbp)
    12ae:	00 
    12af:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    12b3:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
    12b7:	48 89 50 08          	mov    %rdx,0x8(%rax)
    12bb:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    12bf:	48 89 c7             	mov    %rax,%rdi
    12c2:	e8 42 ff ff ff       	call   1209 <arenaNewBlock>
    12c7:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
    12cb:	48 89 02             	mov    %rax,(%rdx)
    12ce:	90                   	nop
    12cf:	c9                   	leave
    12d0:	c3                   	ret

00000000000012d1 <Arena_alloc>:
    12d1:	55                   	push   %rbp
    12d2:	48 89 e5             	mov    %rsp,%rbp
    12d5:	48 83 ec 50          	sub    $0x50,%rsp
    12d9:	48 89 7d c8          	mov    %rdi,-0x38(%rbp)
    12dd:	48 89 75 c0          	mov    %rsi,-0x40(%rbp)
    12e1:	48 89 55 b8          	mov    %rdx,-0x48(%rbp)
    12e5:	48 83 7d b8 00       	cmpq   $0x0,-0x48(%rbp)
    12ea:	75 08                	jne    12f4 <Arena_alloc+0x23>
    12ec:	48 c7 45 b8 01 00 00 	movq   $0x1,-0x48(%rbp)
    12f3:	00 
    12f4:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    12f8:	48 8b 00             	mov    (%rax),%rax
    12fb:	48 85 c0             	test   %rax,%rax
    12fe:	75 17                	jne    1317 <Arena_alloc+0x46>
    1300:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    1304:	48 8b 40 08          	mov    0x8(%rax),%rax
    1308:	48 89 c7             	mov    %rax,%rdi
    130b:	e8 f9 fe ff ff       	call   1209 <arenaNewBlock>
    1310:	48 8b 55 c8          	mov    -0x38(%rbp),%rdx
    1314:	48 89 02             	mov    %rax,(%rdx)
    1317:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    131b:	48 8b 00             	mov    (%rax),%rax
    131e:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
    1322:	48 83 7d d8 00       	cmpq   $0x0,-0x28(%rbp)
    1327:	75 0a                	jne    1333 <Arena_alloc+0x62>
    1329:	b8 00 00 00 00       	mov    $0x0,%eax
    132e:	e9 e4 00 00 00       	jmp    1417 <Arena_alloc+0x146>
    1333:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    1337:	48 8b 50 10          	mov    0x10(%rax),%rdx
    133b:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    133f:	48 01 d0             	add    %rdx,%rax
    1342:	48 8d 50 ff          	lea    -0x1(%rax),%rdx
    1346:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    134a:	48 f7 d8             	neg    %rax
    134d:	48 21 d0             	and    %rdx,%rax
    1350:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    1354:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    1358:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
    135c:	48 01 c2             	add    %rax,%rdx
    135f:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    1363:	48 8b 40 08          	mov    0x8(%rax),%rax
    1367:	48 39 d0             	cmp    %rdx,%rax
    136a:	73 7f                	jae    13eb <Arena_alloc+0x11a>
    136c:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    1370:	48 8b 40 08          	mov    0x8(%rax),%rax
    1374:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    1378:	48 8b 55 c0          	mov    -0x40(%rbp),%rdx
    137c:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    1380:	48 01 c2             	add    %rax,%rdx
    1383:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    1387:	48 01 d0             	add    %rdx,%rax
    138a:	48 39 45 e8          	cmp    %rax,-0x18(%rbp)
    138e:	73 16                	jae    13a6 <Arena_alloc+0xd5>
    1390:	48 8b 55 c0          	mov    -0x40(%rbp),%rdx
    1394:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    1398:	48 01 c2             	add    %rax,%rdx
    139b:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    139f:	48 01 d0             	add    %rdx,%rax
    13a2:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    13a6:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    13aa:	48 89 c7             	mov    %rax,%rdi
    13ad:	e8 57 fe ff ff       	call   1209 <arenaNewBlock>
    13b2:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    13b6:	48 83 7d f0 00       	cmpq   $0x0,-0x10(%rbp)
    13bb:	75 07                	jne    13c4 <Arena_alloc+0xf3>
    13bd:	b8 00 00 00 00       	mov    $0x0,%eax
    13c2:	eb 53                	jmp    1417 <Arena_alloc+0x146>
    13c4:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    13c8:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    13cc:	48 89 50 18          	mov    %rdx,0x18(%rax)
    13d0:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    13d4:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
    13d8:	48 89 10             	mov    %rdx,(%rax)
    13db:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    13df:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
    13e3:	48 c7 45 e0 00 00 00 	movq   $0x0,-0x20(%rbp)
    13ea:	00 
    13eb:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    13ef:	48 8b 00             	mov    (%rax),%rax
    13f2:	48 89 c2             	mov    %rax,%rdx
    13f5:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    13f9:	48 01 d0             	add    %rdx,%rax
    13fc:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    1400:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    1404:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
    1408:	48 01 c2             	add    %rax,%rdx
    140b:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    140f:	48 89 50 10          	mov    %rdx,0x10(%rax)
    1413:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1417:	c9                   	leave
    1418:	c3                   	ret

0000000000001419 <Arena_freeAll>:
    1419:	55                   	push   %rbp
    141a:	48 89 e5             	mov    %rsp,%rbp
    141d:	48 83 ec 20          	sub    $0x20,%rsp
    1421:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    1425:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1429:	48 8b 00             	mov    (%rax),%rax
    142c:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    1430:	eb 2f                	jmp    1461 <Arena_freeAll+0x48>
    1432:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    1436:	48 8b 40 18          	mov    0x18(%rax),%rax
    143a:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    143e:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    1442:	48 8b 00             	mov    (%rax),%rax
    1445:	48 89 c7             	mov    %rax,%rdi
    1448:	e8 e3 fb ff ff       	call   1030 <free@plt>
    144d:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    1451:	48 89 c7             	mov    %rax,%rdi
    1454:	e8 d7 fb ff ff       	call   1030 <free@plt>
    1459:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    145d:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    1461:	48 83 7d f0 00       	cmpq   $0x0,-0x10(%rbp)
    1466:	75 ca                	jne    1432 <Arena_freeAll+0x19>
    1468:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    146c:	48 8b 40 08          	mov    0x8(%rax),%rax
    1470:	48 89 c7             	mov    %rax,%rdi
    1473:	e8 91 fd ff ff       	call   1209 <arenaNewBlock>
    1478:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    147c:	48 89 02             	mov    %rax,(%rdx)
    147f:	90                   	nop
    1480:	c9                   	leave
    1481:	c3                   	ret

0000000000001482 <Slice_from>:
    1482:	55                   	push   %rbp
    1483:	48 89 e5             	mov    %rsp,%rbp
    1486:	53                   	push   %rbx
    1487:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    148b:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    148f:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1493:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    1497:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
    149b:	c9                   	leave
    149c:	c3                   	ret

000000000000149d <Slice_eq>:
    149d:	55                   	push   %rbp
    149e:	48 89 e5             	mov    %rsp,%rbp
    14a1:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    14a5:	48 89 f0             	mov    %rsi,%rax
    14a8:	48 89 d1             	mov    %rdx,%rcx
    14ab:	48 89 c0             	mov    %rax,%rax
    14ae:	ba 00 00 00 00       	mov    $0x0,%edx
    14b3:	48 89 ca             	mov    %rcx,%rdx
    14b6:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
    14ba:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    14be:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    14c2:	48 8b 50 08          	mov    0x8(%rax),%rdx
    14c6:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    14ca:	48 39 c2             	cmp    %rax,%rdx
    14cd:	74 07                	je     14d6 <Slice_eq+0x39>
    14cf:	b8 00 00 00 00       	mov    $0x0,%eax
    14d4:	eb 4c                	jmp    1522 <Slice_eq+0x85>
    14d6:	48 c7 45 f8 00 00 00 	movq   $0x0,-0x8(%rbp)
    14dd:	00 
    14de:	eb 2f                	jmp    150f <Slice_eq+0x72>
    14e0:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    14e4:	48 8b 10             	mov    (%rax),%rdx
    14e7:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    14eb:	48 01 d0             	add    %rdx,%rax
    14ee:	0f b6 10             	movzbl (%rax),%edx
    14f1:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    14f5:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    14f9:	48 01 c8             	add    %rcx,%rax
    14fc:	0f b6 00             	movzbl (%rax),%eax
    14ff:	38 c2                	cmp    %al,%dl
    1501:	74 07                	je     150a <Slice_eq+0x6d>
    1503:	b8 00 00 00 00       	mov    $0x0,%eax
    1508:	eb 18                	jmp    1522 <Slice_eq+0x85>
    150a:	48 83 45 f8 01       	addq   $0x1,-0x8(%rbp)
    150f:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1513:	48 8b 40 08          	mov    0x8(%rax),%rax
    1517:	48 39 45 f8          	cmp    %rax,-0x8(%rbp)
    151b:	72 c3                	jb     14e0 <Slice_eq+0x43>
    151d:	b8 01 00 00 00       	mov    $0x1,%eax
    1522:	5d                   	pop    %rbp
    1523:	c3                   	ret

0000000000001524 <Lexer_init>:
    1524:	55                   	push   %rbp
    1525:	48 89 e5             	mov    %rsp,%rbp
    1528:	48 89 7d c8          	mov    %rdi,-0x38(%rbp)
    152c:	48 89 f0             	mov    %rsi,%rax
    152f:	48 89 d1             	mov    %rdx,%rcx
    1532:	48 89 c0             	mov    %rax,%rax
    1535:	ba 00 00 00 00       	mov    $0x0,%edx
    153a:	48 89 ca             	mov    %rcx,%rdx
    153d:	48 89 45 b0          	mov    %rax,-0x50(%rbp)
    1541:	48 89 55 b8          	mov    %rdx,-0x48(%rbp)
    1545:	48 8b 4d c8          	mov    -0x38(%rbp),%rcx
    1549:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    154d:	48 8b 55 b8          	mov    -0x48(%rbp),%rdx
    1551:	48 89 01             	mov    %rax,(%rcx)
    1554:	48 89 51 08          	mov    %rdx,0x8(%rcx)
    1558:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    155c:	48 c7 40 10 00 00 00 	movq   $0x0,0x10(%rax)
    1563:	00 
    1564:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    1568:	48 c7 40 18 01 00 00 	movq   $0x1,0x18(%rax)
    156f:	00 
    1570:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    1574:	48 c7 40 20 01 00 00 	movq   $0x1,0x20(%rax)
    157b:	00 
    157c:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    1580:	c6 40 28 00          	movb   $0x0,0x28(%rax)
    1584:	90                   	nop
    1585:	5d                   	pop    %rbp
    1586:	c3                   	ret

0000000000001587 <Lexer_peek>:
    1587:	55                   	push   %rbp
    1588:	48 89 e5             	mov    %rsp,%rbp
    158b:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    158f:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1593:	48 8b 50 10          	mov    0x10(%rax),%rdx
    1597:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    159b:	48 8b 40 08          	mov    0x8(%rax),%rax
    159f:	48 39 c2             	cmp    %rax,%rdx
    15a2:	72 07                	jb     15ab <Lexer_peek+0x24>
    15a4:	b8 00 00 00 00       	mov    $0x0,%eax
    15a9:	eb 15                	jmp    15c0 <Lexer_peek+0x39>
    15ab:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    15af:	48 8b 10             	mov    (%rax),%rdx
    15b2:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    15b6:	48 8b 40 10          	mov    0x10(%rax),%rax
    15ba:	48 01 d0             	add    %rdx,%rax
    15bd:	0f b6 00             	movzbl (%rax),%eax
    15c0:	5d                   	pop    %rbp
    15c1:	c3                   	ret

00000000000015c2 <Lexer_skipWsAndComments>:
    15c2:	55                   	push   %rbp
    15c3:	48 89 e5             	mov    %rsp,%rbp
    15c6:	48 83 ec 20          	sub    $0x20,%rsp
    15ca:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    15ce:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    15d2:	48 89 c7             	mov    %rax,%rdi
    15d5:	e8 ad ff ff ff       	call   1587 <Lexer_peek>
    15da:	88 45 ff             	mov    %al,-0x1(%rbp)
    15dd:	80 7d ff 20          	cmpb   $0x20,-0x1(%rbp)
    15e1:	74 12                	je     15f5 <Lexer_skipWsAndComments+0x33>
    15e3:	80 7d ff 09          	cmpb   $0x9,-0x1(%rbp)
    15e7:	74 0c                	je     15f5 <Lexer_skipWsAndComments+0x33>
    15e9:	80 7d ff 0d          	cmpb   $0xd,-0x1(%rbp)
    15ed:	74 06                	je     15f5 <Lexer_skipWsAndComments+0x33>
    15ef:	80 7d ff 0a          	cmpb   $0xa,-0x1(%rbp)
    15f3:	75 0e                	jne    1603 <Lexer_skipWsAndComments+0x41>
    15f5:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    15f9:	48 89 c7             	mov    %rax,%rdi
    15fc:	e8 3d 00 00 00       	call   163e <Lexer_advance>
    1601:	eb 35                	jmp    1638 <Lexer_skipWsAndComments+0x76>
    1603:	80 7d ff 23          	cmpb   $0x23,-0x1(%rbp)
    1607:	75 31                	jne    163a <Lexer_skipWsAndComments+0x78>
    1609:	eb 0c                	jmp    1617 <Lexer_skipWsAndComments+0x55>
    160b:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    160f:	48 89 c7             	mov    %rax,%rdi
    1612:	e8 27 00 00 00       	call   163e <Lexer_advance>
    1617:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    161b:	48 89 c7             	mov    %rax,%rdi
    161e:	e8 64 ff ff ff       	call   1587 <Lexer_peek>
    1623:	84 c0                	test   %al,%al
    1625:	74 10                	je     1637 <Lexer_skipWsAndComments+0x75>
    1627:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    162b:	48 89 c7             	mov    %rax,%rdi
    162e:	e8 54 ff ff ff       	call   1587 <Lexer_peek>
    1633:	3c 0a                	cmp    $0xa,%al
    1635:	75 d4                	jne    160b <Lexer_skipWsAndComments+0x49>
    1637:	90                   	nop
    1638:	eb 94                	jmp    15ce <Lexer_skipWsAndComments+0xc>
    163a:	90                   	nop
    163b:	90                   	nop
    163c:	c9                   	leave
    163d:	c3                   	ret

000000000000163e <Lexer_advance>:
    163e:	55                   	push   %rbp
    163f:	48 89 e5             	mov    %rsp,%rbp
    1642:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    1646:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    164a:	48 8b 10             	mov    (%rax),%rdx
    164d:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1651:	48 8b 40 10          	mov    0x10(%rax),%rax
    1655:	48 01 d0             	add    %rdx,%rax
    1658:	0f b6 00             	movzbl (%rax),%eax
    165b:	88 45 ff             	mov    %al,-0x1(%rbp)
    165e:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1662:	48 8b 40 10          	mov    0x10(%rax),%rax
    1666:	48 8d 50 01          	lea    0x1(%rax),%rdx
    166a:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    166e:	48 89 50 10          	mov    %rdx,0x10(%rax)
    1672:	80 7d ff 0a          	cmpb   $0xa,-0x1(%rbp)
    1676:	75 22                	jne    169a <Lexer_advance+0x5c>
    1678:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    167c:	48 8b 40 18          	mov    0x18(%rax),%rax
    1680:	48 8d 50 01          	lea    0x1(%rax),%rdx
    1684:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1688:	48 89 50 18          	mov    %rdx,0x18(%rax)
    168c:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1690:	48 c7 40 20 01 00 00 	movq   $0x1,0x20(%rax)
    1697:	00 
    1698:	eb 14                	jmp    16ae <Lexer_advance+0x70>
    169a:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    169e:	48 8b 40 20          	mov    0x20(%rax),%rax
    16a2:	48 8d 50 01          	lea    0x1(%rax),%rdx
    16a6:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    16aa:	48 89 50 20          	mov    %rdx,0x20(%rax)
    16ae:	0f b6 45 ff          	movzbl -0x1(%rbp),%eax
    16b2:	5d                   	pop    %rbp
    16b3:	c3                   	ret

00000000000016b4 <Lexer_next>:
    16b4:	55                   	push   %rbp
    16b5:	48 89 e5             	mov    %rsp,%rbp
    16b8:	53                   	push   %rbx
    16b9:	48 81 ec b8 00 00 00 	sub    $0xb8,%rsp
    16c0:	48 89 bd 48 ff ff ff 	mov    %rdi,-0xb8(%rbp)
    16c7:	48 89 b5 40 ff ff ff 	mov    %rsi,-0xc0(%rbp)
    16ce:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    16d5:	00 00 
    16d7:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    16db:	31 c0                	xor    %eax,%eax
    16dd:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    16e4:	48 89 c7             	mov    %rax,%rdi
    16e7:	e8 d6 fe ff ff       	call   15c2 <Lexer_skipWsAndComments>
    16ec:	c7 45 b0 00 00 00 00 	movl   $0x0,-0x50(%rbp)
    16f3:	be 00 00 00 00       	mov    $0x0,%esi
    16f8:	bf 00 00 00 00       	mov    $0x0,%edi
    16fd:	e8 a6 0a 00 00       	call   21a8 <mkSlice>
    1702:	48 89 45 b8          	mov    %rax,-0x48(%rbp)
    1706:	48 89 55 c0          	mov    %rdx,-0x40(%rbp)
    170a:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    1711:	48 8b 40 18          	mov    0x18(%rax),%rax
    1715:	48 89 45 c8          	mov    %rax,-0x38(%rbp)
    1719:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    1720:	48 8b 40 20          	mov    0x20(%rax),%rax
    1724:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
    1728:	48 c7 45 d8 00 00 00 	movq   $0x0,-0x28(%rbp)
    172f:	00 
    1730:	c6 45 e0 00          	movb   $0x0,-0x20(%rbp)
    1734:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    173b:	48 8b 50 10          	mov    0x10(%rax),%rdx
    173f:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    1746:	48 8b 40 08          	mov    0x8(%rax),%rax
    174a:	48 39 c2             	cmp    %rax,%rdx
    174d:	72 43                	jb     1792 <Lexer_next+0xde>
    174f:	48 8b 85 48 ff ff ff 	mov    -0xb8(%rbp),%rax
    1756:	48 8b 4d b0          	mov    -0x50(%rbp),%rcx
    175a:	48 8b 5d b8          	mov    -0x48(%rbp),%rbx
    175e:	48 89 08             	mov    %rcx,(%rax)
    1761:	48 89 58 08          	mov    %rbx,0x8(%rax)
    1765:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
    1769:	48 8b 5d c8          	mov    -0x38(%rbp),%rbx
    176d:	48 89 48 10          	mov    %rcx,0x10(%rax)
    1771:	48 89 58 18          	mov    %rbx,0x18(%rax)
    1775:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    1779:	48 8b 5d d8          	mov    -0x28(%rbp),%rbx
    177d:	48 89 48 20          	mov    %rcx,0x20(%rax)
    1781:	48 89 58 28          	mov    %rbx,0x28(%rax)
    1785:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    1789:	48 89 50 30          	mov    %rdx,0x30(%rax)
    178d:	e9 54 09 00 00       	jmp    20e6 <Lexer_next+0xa32>
    1792:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    1799:	48 89 c7             	mov    %rax,%rdi
    179c:	e8 e6 fd ff ff       	call   1587 <Lexer_peek>
    17a1:	88 85 5d ff ff ff    	mov    %al,-0xa3(%rbp)
    17a7:	80 bd 5d ff ff ff 7b 	cmpb   $0x7b,-0xa3(%rbp)
    17ae:	75 59                	jne    1809 <Lexer_next+0x155>
    17b0:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    17b7:	48 89 c7             	mov    %rax,%rdi
    17ba:	e8 7f fe ff ff       	call   163e <Lexer_advance>
    17bf:	c7 45 b0 05 00 00 00 	movl   $0x5,-0x50(%rbp)
    17c6:	48 8b 85 48 ff ff ff 	mov    -0xb8(%rbp),%rax
    17cd:	48 8b 4d b0          	mov    -0x50(%rbp),%rcx
    17d1:	48 8b 5d b8          	mov    -0x48(%rbp),%rbx
    17d5:	48 89 08             	mov    %rcx,(%rax)
    17d8:	48 89 58 08          	mov    %rbx,0x8(%rax)
    17dc:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
    17e0:	48 8b 5d c8          	mov    -0x38(%rbp),%rbx
    17e4:	48 89 48 10          	mov    %rcx,0x10(%rax)
    17e8:	48 89 58 18          	mov    %rbx,0x18(%rax)
    17ec:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    17f0:	48 8b 5d d8          	mov    -0x28(%rbp),%rbx
    17f4:	48 89 48 20          	mov    %rcx,0x20(%rax)
    17f8:	48 89 58 28          	mov    %rbx,0x28(%rax)
    17fc:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    1800:	48 89 50 30          	mov    %rdx,0x30(%rax)
    1804:	e9 dd 08 00 00       	jmp    20e6 <Lexer_next+0xa32>
    1809:	80 bd 5d ff ff ff 7d 	cmpb   $0x7d,-0xa3(%rbp)
    1810:	75 59                	jne    186b <Lexer_next+0x1b7>
    1812:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    1819:	48 89 c7             	mov    %rax,%rdi
    181c:	e8 1d fe ff ff       	call   163e <Lexer_advance>
    1821:	c7 45 b0 06 00 00 00 	movl   $0x6,-0x50(%rbp)
    1828:	48 8b 85 48 ff ff ff 	mov    -0xb8(%rbp),%rax
    182f:	48 8b 4d b0          	mov    -0x50(%rbp),%rcx
    1833:	48 8b 5d b8          	mov    -0x48(%rbp),%rbx
    1837:	48 89 08             	mov    %rcx,(%rax)
    183a:	48 89 58 08          	mov    %rbx,0x8(%rax)
    183e:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
    1842:	48 8b 5d c8          	mov    -0x38(%rbp),%rbx
    1846:	48 89 48 10          	mov    %rcx,0x10(%rax)
    184a:	48 89 58 18          	mov    %rbx,0x18(%rax)
    184e:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    1852:	48 8b 5d d8          	mov    -0x28(%rbp),%rbx
    1856:	48 89 48 20          	mov    %rcx,0x20(%rax)
    185a:	48 89 58 28          	mov    %rbx,0x28(%rax)
    185e:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    1862:	48 89 50 30          	mov    %rdx,0x30(%rax)
    1866:	e9 7b 08 00 00       	jmp    20e6 <Lexer_next+0xa32>
    186b:	80 bd 5d ff ff ff 5b 	cmpb   $0x5b,-0xa3(%rbp)
    1872:	75 59                	jne    18cd <Lexer_next+0x219>
    1874:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    187b:	48 89 c7             	mov    %rax,%rdi
    187e:	e8 bb fd ff ff       	call   163e <Lexer_advance>
    1883:	c7 45 b0 07 00 00 00 	movl   $0x7,-0x50(%rbp)
    188a:	48 8b 85 48 ff ff ff 	mov    -0xb8(%rbp),%rax
    1891:	48 8b 4d b0          	mov    -0x50(%rbp),%rcx
    1895:	48 8b 5d b8          	mov    -0x48(%rbp),%rbx
    1899:	48 89 08             	mov    %rcx,(%rax)
    189c:	48 89 58 08          	mov    %rbx,0x8(%rax)
    18a0:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
    18a4:	48 8b 5d c8          	mov    -0x38(%rbp),%rbx
    18a8:	48 89 48 10          	mov    %rcx,0x10(%rax)
    18ac:	48 89 58 18          	mov    %rbx,0x18(%rax)
    18b0:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    18b4:	48 8b 5d d8          	mov    -0x28(%rbp),%rbx
    18b8:	48 89 48 20          	mov    %rcx,0x20(%rax)
    18bc:	48 89 58 28          	mov    %rbx,0x28(%rax)
    18c0:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    18c4:	48 89 50 30          	mov    %rdx,0x30(%rax)
    18c8:	e9 19 08 00 00       	jmp    20e6 <Lexer_next+0xa32>
    18cd:	80 bd 5d ff ff ff 5d 	cmpb   $0x5d,-0xa3(%rbp)
    18d4:	75 59                	jne    192f <Lexer_next+0x27b>
    18d6:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    18dd:	48 89 c7             	mov    %rax,%rdi
    18e0:	e8 59 fd ff ff       	call   163e <Lexer_advance>
    18e5:	c7 45 b0 08 00 00 00 	movl   $0x8,-0x50(%rbp)
    18ec:	48 8b 85 48 ff ff ff 	mov    -0xb8(%rbp),%rax
    18f3:	48 8b 4d b0          	mov    -0x50(%rbp),%rcx
    18f7:	48 8b 5d b8          	mov    -0x48(%rbp),%rbx
    18fb:	48 89 08             	mov    %rcx,(%rax)
    18fe:	48 89 58 08          	mov    %rbx,0x8(%rax)
    1902:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
    1906:	48 8b 5d c8          	mov    -0x38(%rbp),%rbx
    190a:	48 89 48 10          	mov    %rcx,0x10(%rax)
    190e:	48 89 58 18          	mov    %rbx,0x18(%rax)
    1912:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    1916:	48 8b 5d d8          	mov    -0x28(%rbp),%rbx
    191a:	48 89 48 20          	mov    %rcx,0x20(%rax)
    191e:	48 89 58 28          	mov    %rbx,0x28(%rax)
    1922:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    1926:	48 89 50 30          	mov    %rdx,0x30(%rax)
    192a:	e9 b7 07 00 00       	jmp    20e6 <Lexer_next+0xa32>
    192f:	80 bd 5d ff ff ff 3d 	cmpb   $0x3d,-0xa3(%rbp)
    1936:	75 59                	jne    1991 <Lexer_next+0x2dd>
    1938:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    193f:	48 89 c7             	mov    %rax,%rdi
    1942:	e8 f7 fc ff ff       	call   163e <Lexer_advance>
    1947:	c7 45 b0 09 00 00 00 	movl   $0x9,-0x50(%rbp)
    194e:	48 8b 85 48 ff ff ff 	mov    -0xb8(%rbp),%rax
    1955:	48 8b 4d b0          	mov    -0x50(%rbp),%rcx
    1959:	48 8b 5d b8          	mov    -0x48(%rbp),%rbx
    195d:	48 89 08             	mov    %rcx,(%rax)
    1960:	48 89 58 08          	mov    %rbx,0x8(%rax)
    1964:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
    1968:	48 8b 5d c8          	mov    -0x38(%rbp),%rbx
    196c:	48 89 48 10          	mov    %rcx,0x10(%rax)
    1970:	48 89 58 18          	mov    %rbx,0x18(%rax)
    1974:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    1978:	48 8b 5d d8          	mov    -0x28(%rbp),%rbx
    197c:	48 89 48 20          	mov    %rcx,0x20(%rax)
    1980:	48 89 58 28          	mov    %rbx,0x28(%rax)
    1984:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    1988:	48 89 50 30          	mov    %rdx,0x30(%rax)
    198c:	e9 55 07 00 00       	jmp    20e6 <Lexer_next+0xa32>
    1991:	80 bd 5d ff ff ff 3b 	cmpb   $0x3b,-0xa3(%rbp)
    1998:	75 59                	jne    19f3 <Lexer_next+0x33f>
    199a:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    19a1:	48 89 c7             	mov    %rax,%rdi
    19a4:	e8 95 fc ff ff       	call   163e <Lexer_advance>
    19a9:	c7 45 b0 0a 00 00 00 	movl   $0xa,-0x50(%rbp)
    19b0:	48 8b 85 48 ff ff ff 	mov    -0xb8(%rbp),%rax
    19b7:	48 8b 4d b0          	mov    -0x50(%rbp),%rcx
    19bb:	48 8b 5d b8          	mov    -0x48(%rbp),%rbx
    19bf:	48 89 08             	mov    %rcx,(%rax)
    19c2:	48 89 58 08          	mov    %rbx,0x8(%rax)
    19c6:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
    19ca:	48 8b 5d c8          	mov    -0x38(%rbp),%rbx
    19ce:	48 89 48 10          	mov    %rcx,0x10(%rax)
    19d2:	48 89 58 18          	mov    %rbx,0x18(%rax)
    19d6:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    19da:	48 8b 5d d8          	mov    -0x28(%rbp),%rbx
    19de:	48 89 48 20          	mov    %rcx,0x20(%rax)
    19e2:	48 89 58 28          	mov    %rbx,0x28(%rax)
    19e6:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    19ea:	48 89 50 30          	mov    %rdx,0x30(%rax)
    19ee:	e9 f3 06 00 00       	jmp    20e6 <Lexer_next+0xa32>
    19f3:	80 bd 5d ff ff ff 2c 	cmpb   $0x2c,-0xa3(%rbp)
    19fa:	75 59                	jne    1a55 <Lexer_next+0x3a1>
    19fc:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    1a03:	48 89 c7             	mov    %rax,%rdi
    1a06:	e8 33 fc ff ff       	call   163e <Lexer_advance>
    1a0b:	c7 45 b0 0b 00 00 00 	movl   $0xb,-0x50(%rbp)
    1a12:	48 8b 85 48 ff ff ff 	mov    -0xb8(%rbp),%rax
    1a19:	48 8b 4d b0          	mov    -0x50(%rbp),%rcx
    1a1d:	48 8b 5d b8          	mov    -0x48(%rbp),%rbx
    1a21:	48 89 08             	mov    %rcx,(%rax)
    1a24:	48 89 58 08          	mov    %rbx,0x8(%rax)
    1a28:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
    1a2c:	48 8b 5d c8          	mov    -0x38(%rbp),%rbx
    1a30:	48 89 48 10          	mov    %rcx,0x10(%rax)
    1a34:	48 89 58 18          	mov    %rbx,0x18(%rax)
    1a38:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    1a3c:	48 8b 5d d8          	mov    -0x28(%rbp),%rbx
    1a40:	48 89 48 20          	mov    %rcx,0x20(%rax)
    1a44:	48 89 58 28          	mov    %rbx,0x28(%rax)
    1a48:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    1a4c:	48 89 50 30          	mov    %rdx,0x30(%rax)
    1a50:	e9 91 06 00 00       	jmp    20e6 <Lexer_next+0xa32>
    1a55:	80 bd 5d ff ff ff 22 	cmpb   $0x22,-0xa3(%rbp)
    1a5c:	0f 85 9c 02 00 00    	jne    1cfe <Lexer_next+0x64a>
    1a62:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    1a69:	48 89 c7             	mov    %rax,%rdi
    1a6c:	e8 cd fb ff ff       	call   163e <Lexer_advance>
    1a71:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    1a78:	48 8b 40 10          	mov    0x10(%rax),%rax
    1a7c:	48 89 45 98          	mov    %rax,-0x68(%rbp)
    1a80:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    1a84:	48 89 85 60 ff ff ff 	mov    %rax,-0xa0(%rbp)
    1a8b:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    1a92:	48 89 c7             	mov    %rax,%rdi
    1a95:	e8 ed fa ff ff       	call   1587 <Lexer_peek>
    1a9a:	88 85 5e ff ff ff    	mov    %al,-0xa2(%rbp)
    1aa0:	80 bd 5e ff ff ff 00 	cmpb   $0x0,-0xa2(%rbp)
    1aa7:	75 55                	jne    1afe <Lexer_next+0x44a>
    1aa9:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    1ab0:	c6 40 28 01          	movb   $0x1,0x28(%rax)
    1ab4:	c7 45 b0 0c 00 00 00 	movl   $0xc,-0x50(%rbp)
    1abb:	48 8b 85 48 ff ff ff 	mov    -0xb8(%rbp),%rax
    1ac2:	48 8b 4d b0          	mov    -0x50(%rbp),%rcx
    1ac6:	48 8b 5d b8          	mov    -0x48(%rbp),%rbx
    1aca:	48 89 08             	mov    %rcx,(%rax)
    1acd:	48 89 58 08          	mov    %rbx,0x8(%rax)
    1ad1:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
    1ad5:	48 8b 5d c8          	mov    -0x38(%rbp),%rbx
    1ad9:	48 89 48 10          	mov    %rcx,0x10(%rax)
    1add:	48 89 58 18          	mov    %rbx,0x18(%rax)
    1ae1:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    1ae5:	48 8b 5d d8          	mov    -0x28(%rbp),%rbx
    1ae9:	48 89 48 20          	mov    %rcx,0x20(%rax)
    1aed:	48 89 58 28          	mov    %rbx,0x28(%rax)
    1af1:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    1af5:	48 89 50 30          	mov    %rdx,0x30(%rax)
    1af9:	e9 e8 05 00 00       	jmp    20e6 <Lexer_next+0xa32>
    1afe:	80 bd 5e ff ff ff 22 	cmpb   $0x22,-0xa2(%rbp)
    1b05:	0f 85 89 00 00 00    	jne    1b94 <Lexer_next+0x4e0>
    1b0b:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    1b12:	48 89 c7             	mov    %rax,%rdi
    1b15:	e8 24 fb ff ff       	call   163e <Lexer_advance>
    1b1a:	90                   	nop
    1b1b:	c7 45 b0 02 00 00 00 	movl   $0x2,-0x50(%rbp)
    1b22:	48 8b 85 60 ff ff ff 	mov    -0xa0(%rbp),%rax
    1b29:	48 2b 45 98          	sub    -0x68(%rbp),%rax
    1b2d:	48 8b 95 40 ff ff ff 	mov    -0xc0(%rbp),%rdx
    1b34:	48 8b 0a             	mov    (%rdx),%rcx
    1b37:	48 8b 55 98          	mov    -0x68(%rbp),%rdx
    1b3b:	48 01 ca             	add    %rcx,%rdx
    1b3e:	48 89 c6             	mov    %rax,%rsi
    1b41:	48 89 d7             	mov    %rdx,%rdi
    1b44:	e8 5f 06 00 00       	call   21a8 <mkSlice>
    1b49:	48 89 45 b8          	mov    %rax,-0x48(%rbp)
    1b4d:	48 89 55 c0          	mov    %rdx,-0x40(%rbp)
    1b51:	48 8b 85 48 ff ff ff 	mov    -0xb8(%rbp),%rax
    1b58:	48 8b 4d b0          	mov    -0x50(%rbp),%rcx
    1b5c:	48 8b 5d b8          	mov    -0x48(%rbp),%rbx
    1b60:	48 89 08             	mov    %rcx,(%rax)
    1b63:	48 89 58 08          	mov    %rbx,0x8(%rax)
    1b67:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
    1b6b:	48 8b 5d c8          	mov    -0x38(%rbp),%rbx
    1b6f:	48 89 48 10          	mov    %rcx,0x10(%rax)
    1b73:	48 89 58 18          	mov    %rbx,0x18(%rax)
    1b77:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    1b7b:	48 8b 5d d8          	mov    -0x28(%rbp),%rbx
    1b7f:	48 89 48 20          	mov    %rcx,0x20(%rax)
    1b83:	48 89 58 28          	mov    %rbx,0x28(%rax)
    1b87:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    1b8b:	48 89 50 30          	mov    %rdx,0x30(%rax)
    1b8f:	e9 52 05 00 00       	jmp    20e6 <Lexer_next+0xa32>
    1b94:	80 bd 5e ff ff ff 5c 	cmpb   $0x5c,-0xa2(%rbp)
    1b9b:	0f 85 24 01 00 00    	jne    1cc5 <Lexer_next+0x611>
    1ba1:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    1ba8:	48 89 c7             	mov    %rax,%rdi
    1bab:	e8 8e fa ff ff       	call   163e <Lexer_advance>
    1bb0:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    1bb7:	48 89 c7             	mov    %rax,%rdi
    1bba:	e8 c8 f9 ff ff       	call   1587 <Lexer_peek>
    1bbf:	88 85 5f ff ff ff    	mov    %al,-0xa1(%rbp)
    1bc5:	80 bd 5f ff ff ff 00 	cmpb   $0x0,-0xa1(%rbp)
    1bcc:	75 55                	jne    1c23 <Lexer_next+0x56f>
    1bce:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    1bd5:	c6 40 28 01          	movb   $0x1,0x28(%rax)
    1bd9:	c7 45 b0 0c 00 00 00 	movl   $0xc,-0x50(%rbp)
    1be0:	48 8b 85 48 ff ff ff 	mov    -0xb8(%rbp),%rax
    1be7:	48 8b 4d b0          	mov    -0x50(%rbp),%rcx
    1beb:	48 8b 5d b8          	mov    -0x48(%rbp),%rbx
    1bef:	48 89 08             	mov    %rcx,(%rax)
    1bf2:	48 89 58 08          	mov    %rbx,0x8(%rax)
    1bf6:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
    1bfa:	48 8b 5d c8          	mov    -0x38(%rbp),%rbx
    1bfe:	48 89 48 10          	mov    %rcx,0x10(%rax)
    1c02:	48 89 58 18          	mov    %rbx,0x18(%rax)
    1c06:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    1c0a:	48 8b 5d d8          	mov    -0x28(%rbp),%rbx
    1c0e:	48 89 48 20          	mov    %rcx,0x20(%rax)
    1c12:	48 89 58 28          	mov    %rbx,0x28(%rax)
    1c16:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    1c1a:	48 89 50 30          	mov    %rdx,0x30(%rax)
    1c1e:	e9 c3 04 00 00       	jmp    20e6 <Lexer_next+0xa32>
    1c23:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    1c2a:	48 89 c7             	mov    %rax,%rdi
    1c2d:	e8 0c fa ff ff       	call   163e <Lexer_advance>
    1c32:	0f b6 85 5f ff ff ff 	movzbl -0xa1(%rbp),%eax
    1c39:	83 f8 74             	cmp    $0x74,%eax
    1c3c:	74 2e                	je     1c6c <Lexer_next+0x5b8>
    1c3e:	83 f8 74             	cmp    $0x74,%eax
    1c41:	7f 4d                	jg     1c90 <Lexer_next+0x5dc>
    1c43:	83 f8 72             	cmp    $0x72,%eax
    1c46:	74 2d                	je     1c75 <Lexer_next+0x5c1>
    1c48:	83 f8 72             	cmp    $0x72,%eax
    1c4b:	7f 43                	jg     1c90 <Lexer_next+0x5dc>
    1c4d:	83 f8 6e             	cmp    $0x6e,%eax
    1c50:	74 11                	je     1c63 <Lexer_next+0x5af>
    1c52:	83 f8 6e             	cmp    $0x6e,%eax
    1c55:	7f 39                	jg     1c90 <Lexer_next+0x5dc>
    1c57:	83 f8 22             	cmp    $0x22,%eax
    1c5a:	74 22                	je     1c7e <Lexer_next+0x5ca>
    1c5c:	83 f8 5c             	cmp    $0x5c,%eax
    1c5f:	74 26                	je     1c87 <Lexer_next+0x5d3>
    1c61:	eb 2d                	jmp    1c90 <Lexer_next+0x5dc>
    1c63:	c6 85 5c ff ff ff 0a 	movb   $0xa,-0xa4(%rbp)
    1c6a:	eb 32                	jmp    1c9e <Lexer_next+0x5ea>
    1c6c:	c6 85 5c ff ff ff 09 	movb   $0x9,-0xa4(%rbp)
    1c73:	eb 29                	jmp    1c9e <Lexer_next+0x5ea>
    1c75:	c6 85 5c ff ff ff 0d 	movb   $0xd,-0xa4(%rbp)
    1c7c:	eb 20                	jmp    1c9e <Lexer_next+0x5ea>
    1c7e:	c6 85 5c ff ff ff 22 	movb   $0x22,-0xa4(%rbp)
    1c85:	eb 17                	jmp    1c9e <Lexer_next+0x5ea>
    1c87:	c6 85 5c ff ff ff 5c 	movb   $0x5c,-0xa4(%rbp)
    1c8e:	eb 0e                	jmp    1c9e <Lexer_next+0x5ea>
    1c90:	0f b6 85 5f ff ff ff 	movzbl -0xa1(%rbp),%eax
    1c97:	88 85 5c ff ff ff    	mov    %al,-0xa4(%rbp)
    1c9d:	90                   	nop
    1c9e:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    1ca5:	48 8b 10             	mov    (%rax),%rdx
    1ca8:	48 8b 85 60 ff ff ff 	mov    -0xa0(%rbp),%rax
    1caf:	48 01 c2             	add    %rax,%rdx
    1cb2:	0f b6 85 5c ff ff ff 	movzbl -0xa4(%rbp),%eax
    1cb9:	88 02                	mov    %al,(%rdx)
    1cbb:	48 83 85 60 ff ff ff 	addq   $0x1,-0xa0(%rbp)
    1cc2:	01 
    1cc3:	eb 34                	jmp    1cf9 <Lexer_next+0x645>
    1cc5:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    1ccc:	48 8b 10             	mov    (%rax),%rdx
    1ccf:	48 8b 85 60 ff ff ff 	mov    -0xa0(%rbp),%rax
    1cd6:	48 01 c2             	add    %rax,%rdx
    1cd9:	0f b6 85 5e ff ff ff 	movzbl -0xa2(%rbp),%eax
    1ce0:	88 02                	mov    %al,(%rdx)
    1ce2:	48 83 85 60 ff ff ff 	addq   $0x1,-0xa0(%rbp)
    1ce9:	01 
    1cea:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    1cf1:	48 89 c7             	mov    %rax,%rdi
    1cf4:	e8 45 f9 ff ff       	call   163e <Lexer_advance>
    1cf9:	e9 8d fd ff ff       	jmp    1a8b <Lexer_next+0x3d7>
    1cfe:	0f b6 85 5d ff ff ff 	movzbl -0xa3(%rbp),%eax
    1d05:	89 c7                	mov    %eax,%edi
    1d07:	e8 77 04 00 00       	call   2183 <isDigit>
    1d0c:	84 c0                	test   %al,%al
    1d0e:	0f 84 41 01 00 00    	je     1e55 <Lexer_next+0x7a1>
    1d14:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    1d1b:	48 8b 40 10          	mov    0x10(%rax),%rax
    1d1f:	48 89 45 88          	mov    %rax,-0x78(%rbp)
    1d23:	eb 0f                	jmp    1d34 <Lexer_next+0x680>
    1d25:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    1d2c:	48 89 c7             	mov    %rax,%rdi
    1d2f:	e8 0a f9 ff ff       	call   163e <Lexer_advance>
    1d34:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    1d3b:	48 89 c7             	mov    %rax,%rdi
    1d3e:	e8 44 f8 ff ff       	call   1587 <Lexer_peek>
    1d43:	0f b6 c0             	movzbl %al,%eax
    1d46:	89 c7                	mov    %eax,%edi
    1d48:	e8 36 04 00 00       	call   2183 <isDigit>
    1d4d:	84 c0                	test   %al,%al
    1d4f:	75 d4                	jne    1d25 <Lexer_next+0x671>
    1d51:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    1d58:	48 8b 40 10          	mov    0x10(%rax),%rax
    1d5c:	48 2b 45 88          	sub    -0x78(%rbp),%rax
    1d60:	48 89 45 90          	mov    %rax,-0x70(%rbp)
    1d64:	c7 45 b0 03 00 00 00 	movl   $0x3,-0x50(%rbp)
    1d6b:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    1d72:	48 8b 10             	mov    (%rax),%rdx
    1d75:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    1d79:	48 01 c2             	add    %rax,%rdx
    1d7c:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    1d80:	48 89 c6             	mov    %rax,%rsi
    1d83:	48 89 d7             	mov    %rdx,%rdi
    1d86:	e8 1d 04 00 00       	call   21a8 <mkSlice>
    1d8b:	48 89 45 b8          	mov    %rax,-0x48(%rbp)
    1d8f:	48 89 55 c0          	mov    %rdx,-0x40(%rbp)
    1d93:	48 c7 85 68 ff ff ff 	movq   $0x0,-0x98(%rbp)
    1d9a:	00 00 00 00 
    1d9e:	48 c7 85 70 ff ff ff 	movq   $0x0,-0x90(%rbp)
    1da5:	00 00 00 00 
    1da9:	eb 4f                	jmp    1dfa <Lexer_next+0x746>
    1dab:	48 8b 95 68 ff ff ff 	mov    -0x98(%rbp),%rdx
    1db2:	48 89 d0             	mov    %rdx,%rax
    1db5:	48 c1 e0 02          	shl    $0x2,%rax
    1db9:	48 01 d0             	add    %rdx,%rax
    1dbc:	48 01 c0             	add    %rax,%rax
    1dbf:	48 89 c6             	mov    %rax,%rsi
    1dc2:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    1dc9:	48 8b 00             	mov    (%rax),%rax
    1dcc:	48 8b 4d 88          	mov    -0x78(%rbp),%rcx
    1dd0:	48 8b 95 70 ff ff ff 	mov    -0x90(%rbp),%rdx
    1dd7:	48 01 ca             	add    %rcx,%rdx
    1dda:	48 01 d0             	add    %rdx,%rax
    1ddd:	0f b6 00             	movzbl (%rax),%eax
    1de0:	0f b6 c0             	movzbl %al,%eax
    1de3:	83 e8 30             	sub    $0x30,%eax
    1de6:	48 98                	cltq
    1de8:	48 01 f0             	add    %rsi,%rax
    1deb:	48 89 85 68 ff ff ff 	mov    %rax,-0x98(%rbp)
    1df2:	48 83 85 70 ff ff ff 	addq   $0x1,-0x90(%rbp)
    1df9:	01 
    1dfa:	48 8b 85 70 ff ff ff 	mov    -0x90(%rbp),%rax
    1e01:	48 3b 45 90          	cmp    -0x70(%rbp),%rax
    1e05:	72 a4                	jb     1dab <Lexer_next+0x6f7>
    1e07:	48 8b 85 68 ff ff ff 	mov    -0x98(%rbp),%rax
    1e0e:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
    1e12:	48 8b 85 48 ff ff ff 	mov    -0xb8(%rbp),%rax
    1e19:	48 8b 4d b0          	mov    -0x50(%rbp),%rcx
    1e1d:	48 8b 5d b8          	mov    -0x48(%rbp),%rbx
    1e21:	48 89 08             	mov    %rcx,(%rax)
    1e24:	48 89 58 08          	mov    %rbx,0x8(%rax)
    1e28:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
    1e2c:	48 8b 5d c8          	mov    -0x38(%rbp),%rbx
    1e30:	48 89 48 10          	mov    %rcx,0x10(%rax)
    1e34:	48 89 58 18          	mov    %rbx,0x18(%rax)
    1e38:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    1e3c:	48 8b 5d d8          	mov    -0x28(%rbp),%rbx
    1e40:	48 89 48 20          	mov    %rcx,0x20(%rax)
    1e44:	48 89 58 28          	mov    %rbx,0x28(%rax)
    1e48:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    1e4c:	48 89 50 30          	mov    %rdx,0x30(%rax)
    1e50:	e9 91 02 00 00       	jmp    20e6 <Lexer_next+0xa32>
    1e55:	0f b6 85 5d ff ff ff 	movzbl -0xa3(%rbp),%eax
    1e5c:	89 c7                	mov    %eax,%edi
    1e5e:	e8 a4 02 00 00       	call   2107 <isIdentStart>
    1e63:	84 c0                	test   %al,%al
    1e65:	0f 84 eb 01 00 00    	je     2056 <Lexer_next+0x9a2>
    1e6b:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    1e72:	48 8b 40 10          	mov    0x10(%rax),%rax
    1e76:	48 89 85 78 ff ff ff 	mov    %rax,-0x88(%rbp)
    1e7d:	eb 0f                	jmp    1e8e <Lexer_next+0x7da>
    1e7f:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    1e86:	48 89 c7             	mov    %rax,%rdi
    1e89:	e8 b0 f7 ff ff       	call   163e <Lexer_advance>
    1e8e:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    1e95:	48 89 c7             	mov    %rax,%rdi
    1e98:	e8 ea f6 ff ff       	call   1587 <Lexer_peek>
    1e9d:	0f b6 c0             	movzbl %al,%eax
    1ea0:	89 c7                	mov    %eax,%edi
    1ea2:	e8 97 02 00 00       	call   213e <isIdentCont>
    1ea7:	84 c0                	test   %al,%al
    1ea9:	75 d4                	jne    1e7f <Lexer_next+0x7cb>
    1eab:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    1eb2:	48 8b 40 10          	mov    0x10(%rax),%rax
    1eb6:	48 2b 85 78 ff ff ff 	sub    -0x88(%rbp),%rax
    1ebd:	48 89 45 80          	mov    %rax,-0x80(%rbp)
    1ec1:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    1ec8:	48 8b 10             	mov    (%rax),%rdx
    1ecb:	48 8b 85 78 ff ff ff 	mov    -0x88(%rbp),%rax
    1ed2:	48 01 c2             	add    %rax,%rdx
    1ed5:	48 8b 45 80          	mov    -0x80(%rbp),%rax
    1ed9:	48 89 c6             	mov    %rax,%rsi
    1edc:	48 89 d7             	mov    %rdx,%rdi
    1edf:	e8 c4 02 00 00       	call   21a8 <mkSlice>
    1ee4:	48 89 45 a0          	mov    %rax,-0x60(%rbp)
    1ee8:	48 89 55 a8          	mov    %rdx,-0x58(%rbp)
    1eec:	48 8d 05 15 81 00 00 	lea    0x8115(%rip),%rax        # a008 <_IO_stdin_used+0x8>
    1ef3:	be 04 00 00 00       	mov    $0x4,%esi
    1ef8:	48 89 c7             	mov    %rax,%rdi
    1efb:	e8 a8 02 00 00       	call   21a8 <mkSlice>
    1f00:	48 89 c1             	mov    %rax,%rcx
    1f03:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
    1f07:	48 89 ce             	mov    %rcx,%rsi
    1f0a:	48 89 c7             	mov    %rax,%rdi
    1f0d:	e8 8b f5 ff ff       	call   149d <Slice_eq>
    1f12:	84 c0                	test   %al,%al
    1f14:	74 5e                	je     1f74 <Lexer_next+0x8c0>
    1f16:	c7 45 b0 04 00 00 00 	movl   $0x4,-0x50(%rbp)
    1f1d:	c6 45 e0 01          	movb   $0x1,-0x20(%rbp)
    1f21:	48 8b 45 a0          	mov    -0x60(%rbp),%rax
    1f25:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
    1f29:	48 89 45 b8          	mov    %rax,-0x48(%rbp)
    1f2d:	48 89 55 c0          	mov    %rdx,-0x40(%rbp)
    1f31:	48 8b 85 48 ff ff ff 	mov    -0xb8(%rbp),%rax
    1f38:	48 8b 4d b0          	mov    -0x50(%rbp),%rcx
    1f3c:	48 8b 5d b8          	mov    -0x48(%rbp),%rbx
    1f40:	48 89 08             	mov    %rcx,(%rax)
    1f43:	48 89 58 08          	mov    %rbx,0x8(%rax)
    1f47:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
    1f4b:	48 8b 5d c8          	mov    -0x38(%rbp),%rbx
    1f4f:	48 89 48 10          	mov    %rcx,0x10(%rax)
    1f53:	48 89 58 18          	mov    %rbx,0x18(%rax)
    1f57:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    1f5b:	48 8b 5d d8          	mov    -0x28(%rbp),%rbx
    1f5f:	48 89 48 20          	mov    %rcx,0x20(%rax)
    1f63:	48 89 58 28          	mov    %rbx,0x28(%rax)
    1f67:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    1f6b:	48 89 50 30          	mov    %rdx,0x30(%rax)
    1f6f:	e9 72 01 00 00       	jmp    20e6 <Lexer_next+0xa32>
    1f74:	48 8d 05 92 80 00 00 	lea    0x8092(%rip),%rax        # a00d <_IO_stdin_used+0xd>
    1f7b:	be 05 00 00 00       	mov    $0x5,%esi
    1f80:	48 89 c7             	mov    %rax,%rdi
    1f83:	e8 20 02 00 00       	call   21a8 <mkSlice>
    1f88:	48 89 c1             	mov    %rax,%rcx
    1f8b:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
    1f8f:	48 89 ce             	mov    %rcx,%rsi
    1f92:	48 89 c7             	mov    %rax,%rdi
    1f95:	e8 03 f5 ff ff       	call   149d <Slice_eq>
    1f9a:	84 c0                	test   %al,%al
    1f9c:	74 5e                	je     1ffc <Lexer_next+0x948>
    1f9e:	c7 45 b0 04 00 00 00 	movl   $0x4,-0x50(%rbp)
    1fa5:	c6 45 e0 00          	movb   $0x0,-0x20(%rbp)
    1fa9:	48 8b 45 a0          	mov    -0x60(%rbp),%rax
    1fad:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
    1fb1:	48 89 45 b8          	mov    %rax,-0x48(%rbp)
    1fb5:	48 89 55 c0          	mov    %rdx,-0x40(%rbp)
    1fb9:	48 8b 85 48 ff ff ff 	mov    -0xb8(%rbp),%rax
    1fc0:	48 8b 4d b0          	mov    -0x50(%rbp),%rcx
    1fc4:	48 8b 5d b8          	mov    -0x48(%rbp),%rbx
    1fc8:	48 89 08             	mov    %rcx,(%rax)
    1fcb:	48 89 58 08          	mov    %rbx,0x8(%rax)
    1fcf:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
    1fd3:	48 8b 5d c8          	mov    -0x38(%rbp),%rbx
    1fd7:	48 89 48 10          	mov    %rcx,0x10(%rax)
    1fdb:	48 89 58 18          	mov    %rbx,0x18(%rax)
    1fdf:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    1fe3:	48 8b 5d d8          	mov    -0x28(%rbp),%rbx
    1fe7:	48 89 48 20          	mov    %rcx,0x20(%rax)
    1feb:	48 89 58 28          	mov    %rbx,0x28(%rax)
    1fef:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    1ff3:	48 89 50 30          	mov    %rdx,0x30(%rax)
    1ff7:	e9 ea 00 00 00       	jmp    20e6 <Lexer_next+0xa32>
    1ffc:	c7 45 b0 01 00 00 00 	movl   $0x1,-0x50(%rbp)
    2003:	48 8b 45 a0          	mov    -0x60(%rbp),%rax
    2007:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
    200b:	48 89 45 b8          	mov    %rax,-0x48(%rbp)
    200f:	48 89 55 c0          	mov    %rdx,-0x40(%rbp)
    2013:	48 8b 85 48 ff ff ff 	mov    -0xb8(%rbp),%rax
    201a:	48 8b 4d b0          	mov    -0x50(%rbp),%rcx
    201e:	48 8b 5d b8          	mov    -0x48(%rbp),%rbx
    2022:	48 89 08             	mov    %rcx,(%rax)
    2025:	48 89 58 08          	mov    %rbx,0x8(%rax)
    2029:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
    202d:	48 8b 5d c8          	mov    -0x38(%rbp),%rbx
    2031:	48 89 48 10          	mov    %rcx,0x10(%rax)
    2035:	48 89 58 18          	mov    %rbx,0x18(%rax)
    2039:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    203d:	48 8b 5d d8          	mov    -0x28(%rbp),%rbx
    2041:	48 89 48 20          	mov    %rcx,0x20(%rax)
    2045:	48 89 58 28          	mov    %rbx,0x28(%rax)
    2049:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    204d:	48 89 50 30          	mov    %rdx,0x30(%rax)
    2051:	e9 90 00 00 00       	jmp    20e6 <Lexer_next+0xa32>
    2056:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    205d:	48 89 c7             	mov    %rax,%rdi
    2060:	e8 d9 f5 ff ff       	call   163e <Lexer_advance>
    2065:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    206c:	c6 40 28 01          	movb   $0x1,0x28(%rax)
    2070:	c7 45 b0 0c 00 00 00 	movl   $0xc,-0x50(%rbp)
    2077:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    207e:	48 8b 10             	mov    (%rax),%rdx
    2081:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    2088:	48 8b 40 10          	mov    0x10(%rax),%rax
    208c:	48 83 e8 01          	sub    $0x1,%rax
    2090:	48 01 d0             	add    %rdx,%rax
    2093:	be 01 00 00 00       	mov    $0x1,%esi
    2098:	48 89 c7             	mov    %rax,%rdi
    209b:	e8 08 01 00 00       	call   21a8 <mkSlice>
    20a0:	48 89 45 b8          	mov    %rax,-0x48(%rbp)
    20a4:	48 89 55 c0          	mov    %rdx,-0x40(%rbp)
    20a8:	48 8b 85 48 ff ff ff 	mov    -0xb8(%rbp),%rax
    20af:	48 8b 4d b0          	mov    -0x50(%rbp),%rcx
    20b3:	48 8b 5d b8          	mov    -0x48(%rbp),%rbx
    20b7:	48 89 08             	mov    %rcx,(%rax)
    20ba:	48 89 58 08          	mov    %rbx,0x8(%rax)
    20be:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
    20c2:	48 8b 5d c8          	mov    -0x38(%rbp),%rbx
    20c6:	48 89 48 10          	mov    %rcx,0x10(%rax)
    20ca:	48 89 58 18          	mov    %rbx,0x18(%rax)
    20ce:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    20d2:	48 8b 5d d8          	mov    -0x28(%rbp),%rbx
    20d6:	48 89 48 20          	mov    %rcx,0x20(%rax)
    20da:	48 89 58 28          	mov    %rbx,0x28(%rax)
    20de:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    20e2:	48 89 50 30          	mov    %rdx,0x30(%rax)
    20e6:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    20ea:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    20f1:	00 00 
    20f3:	74 05                	je     20fa <Lexer_next+0xa46>
    20f5:	e8 86 ef ff ff       	call   1080 <__stack_chk_fail@plt>
    20fa:	48 8b 85 48 ff ff ff 	mov    -0xb8(%rbp),%rax
    2101:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
    2105:	c9                   	leave
    2106:	c3                   	ret

0000000000002107 <isIdentStart>:
    2107:	55                   	push   %rbp
    2108:	48 89 e5             	mov    %rsp,%rbp
    210b:	40 88 7d ff          	mov    %dil,-0x1(%rbp)
    210f:	80 7d ff 40          	cmpb   $0x40,-0x1(%rbp)
    2113:	76 06                	jbe    211b <isIdentStart+0x14>
    2115:	80 7d ff 5a          	cmpb   $0x5a,-0x1(%rbp)
    2119:	76 12                	jbe    212d <isIdentStart+0x26>
    211b:	80 7d ff 60          	cmpb   $0x60,-0x1(%rbp)
    211f:	76 06                	jbe    2127 <isIdentStart+0x20>
    2121:	80 7d ff 7a          	cmpb   $0x7a,-0x1(%rbp)
    2125:	76 06                	jbe    212d <isIdentStart+0x26>
    2127:	80 7d ff 5f          	cmpb   $0x5f,-0x1(%rbp)
    212b:	75 07                	jne    2134 <isIdentStart+0x2d>
    212d:	b8 01 00 00 00       	mov    $0x1,%eax
    2132:	eb 05                	jmp    2139 <isIdentStart+0x32>
    2134:	b8 00 00 00 00       	mov    $0x0,%eax
    2139:	83 e0 01             	and    $0x1,%eax
    213c:	5d                   	pop    %rbp
    213d:	c3                   	ret

000000000000213e <isIdentCont>:
    213e:	55                   	push   %rbp
    213f:	48 89 e5             	mov    %rsp,%rbp
    2142:	48 83 ec 08          	sub    $0x8,%rsp
    2146:	40 88 7d ff          	mov    %dil,-0x1(%rbp)
    214a:	0f b6 45 ff          	movzbl -0x1(%rbp),%eax
    214e:	89 c7                	mov    %eax,%edi
    2150:	e8 b2 ff ff ff       	call   2107 <isIdentStart>
    2155:	84 c0                	test   %al,%al
    2157:	74 07                	je     2160 <isIdentCont+0x22>
    2159:	b8 01 00 00 00       	mov    $0x1,%eax
    215e:	eb 21                	jmp    2181 <isIdentCont+0x43>
    2160:	80 7d ff 2f          	cmpb   $0x2f,-0x1(%rbp)
    2164:	76 06                	jbe    216c <isIdentCont+0x2e>
    2166:	80 7d ff 39          	cmpb   $0x39,-0x1(%rbp)
    216a:	76 06                	jbe    2172 <isIdentCont+0x34>
    216c:	80 7d ff 2d          	cmpb   $0x2d,-0x1(%rbp)
    2170:	75 07                	jne    2179 <isIdentCont+0x3b>
    2172:	b8 01 00 00 00       	mov    $0x1,%eax
    2177:	eb 05                	jmp    217e <isIdentCont+0x40>
    2179:	b8 00 00 00 00       	mov    $0x0,%eax
    217e:	83 e0 01             	and    $0x1,%eax
    2181:	c9                   	leave
    2182:	c3                   	ret

0000000000002183 <isDigit>:
    2183:	55                   	push   %rbp
    2184:	48 89 e5             	mov    %rsp,%rbp
    2187:	40 88 7d ff          	mov    %dil,-0x1(%rbp)
    218b:	80 7d ff 2f          	cmpb   $0x2f,-0x1(%rbp)
    218f:	76 0d                	jbe    219e <isDigit+0x1b>
    2191:	80 7d ff 39          	cmpb   $0x39,-0x1(%rbp)
    2195:	77 07                	ja     219e <isDigit+0x1b>
    2197:	b8 01 00 00 00       	mov    $0x1,%eax
    219c:	eb 05                	jmp    21a3 <isDigit+0x20>
    219e:	b8 00 00 00 00       	mov    $0x0,%eax
    21a3:	83 e0 01             	and    $0x1,%eax
    21a6:	5d                   	pop    %rbp
    21a7:	c3                   	ret

00000000000021a8 <mkSlice>:
    21a8:	55                   	push   %rbp
    21a9:	48 89 e5             	mov    %rsp,%rbp
    21ac:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    21b0:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    21b4:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    21b8:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    21bc:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    21c0:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    21c4:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    21c8:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
    21cc:	5d                   	pop    %rbp
    21cd:	c3                   	ret

00000000000021ce <Node_init>:
    21ce:	55                   	push   %rbp
    21cf:	48 89 e5             	mov    %rsp,%rbp
    21d2:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    21d6:	89 75 f4             	mov    %esi,-0xc(%rbp)
    21d9:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
    21dd:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    21e1:	8b 55 f4             	mov    -0xc(%rbp),%edx
    21e4:	89 10                	mov    %edx,(%rax)
    21e6:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    21ea:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    21ee:	48 89 90 90 00 00 00 	mov    %rdx,0x90(%rax)
    21f5:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    21f9:	48 c7 40 08 00 00 00 	movq   $0x0,0x8(%rax)
    2200:	00 
    2201:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2205:	48 c7 40 10 00 00 00 	movq   $0x0,0x10(%rax)
    220c:	00 
    220d:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2211:	c6 40 18 00          	movb   $0x0,0x18(%rax)
    2215:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2219:	48 c7 40 20 00 00 00 	movq   $0x0,0x20(%rax)
    2220:	00 
    2221:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2225:	48 c7 40 28 00 00 00 	movq   $0x0,0x28(%rax)
    222c:	00 
    222d:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2231:	c6 40 30 00          	movb   $0x0,0x30(%rax)
    2235:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2239:	48 c7 40 38 00 00 00 	movq   $0x0,0x38(%rax)
    2240:	00 
    2241:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2245:	48 c7 40 40 00 00 00 	movq   $0x0,0x40(%rax)
    224c:	00 
    224d:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2251:	c6 40 48 00          	movb   $0x0,0x48(%rax)
    2255:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2259:	48 c7 40 50 00 00 00 	movq   $0x0,0x50(%rax)
    2260:	00 
    2261:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2265:	48 c7 40 58 00 00 00 	movq   $0x0,0x58(%rax)
    226c:	00 
    226d:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2271:	48 c7 40 60 00 00 00 	movq   $0x0,0x60(%rax)
    2278:	00 
    2279:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    227d:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    2281:	48 89 50 68          	mov    %rdx,0x68(%rax)
    2285:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2289:	48 c7 40 70 00 00 00 	movq   $0x0,0x70(%rax)
    2290:	00 
    2291:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2295:	48 c7 40 78 00 00 00 	movq   $0x0,0x78(%rax)
    229c:	00 
    229d:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    22a1:	48 c7 80 80 00 00 00 	movq   $0x0,0x80(%rax)
    22a8:	00 00 00 00 
    22ac:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    22b0:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    22b4:	48 89 90 88 00 00 00 	mov    %rdx,0x88(%rax)
    22bb:	90                   	nop
    22bc:	5d                   	pop    %rbp
    22bd:	c3                   	ret

00000000000022be <Node_addField>:
    22be:	55                   	push   %rbp
    22bf:	48 89 e5             	mov    %rsp,%rbp
    22c2:	53                   	push   %rbx
    22c3:	48 83 ec 48          	sub    $0x48,%rsp
    22c7:	48 89 7d c8          	mov    %rdi,-0x38(%rbp)
    22cb:	48 89 f0             	mov    %rsi,%rax
    22ce:	48 89 d1             	mov    %rdx,%rcx
    22d1:	48 89 c0             	mov    %rax,%rax
    22d4:	ba 00 00 00 00       	mov    $0x0,%edx
    22d9:	48 89 ca             	mov    %rcx,%rdx
    22dc:	48 89 45 b0          	mov    %rax,-0x50(%rbp)
    22e0:	48 89 55 b8          	mov    %rdx,-0x48(%rbp)
    22e4:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    22e8:	48 8b 50 58          	mov    0x58(%rax),%rdx
    22ec:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    22f0:	48 8b 40 60          	mov    0x60(%rax),%rax
    22f4:	48 39 c2             	cmp    %rax,%rdx
    22f7:	0f 82 f8 00 00 00    	jb     23f5 <Node_addField+0x137>
    22fd:	48 c7 45 d8 08 00 00 	movq   $0x8,-0x28(%rbp)
    2304:	00 
    2305:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    2309:	48 8b 40 60          	mov    0x60(%rax),%rax
    230d:	48 85 c0             	test   %rax,%rax
    2310:	74 0f                	je     2321 <Node_addField+0x63>
    2312:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    2316:	48 8b 40 60          	mov    0x60(%rax),%rax
    231a:	48 01 c0             	add    %rax,%rax
    231d:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
    2321:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    2325:	48 89 d0             	mov    %rdx,%rax
    2328:	48 c1 e0 02          	shl    $0x2,%rax
    232c:	48 01 d0             	add    %rdx,%rax
    232f:	48 c1 e0 03          	shl    $0x3,%rax
    2333:	48 89 c1             	mov    %rax,%rcx
    2336:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    233a:	48 8b 80 90 00 00 00 	mov    0x90(%rax),%rax
    2341:	ba 08 00 00 00       	mov    $0x8,%edx
    2346:	48 89 ce             	mov    %rcx,%rsi
    2349:	48 89 c7             	mov    %rax,%rdi
    234c:	e8 80 ef ff ff       	call   12d1 <Arena_alloc>
    2351:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    2355:	48 83 7d e8 00       	cmpq   $0x0,-0x18(%rbp)
    235a:	0f 84 14 01 00 00    	je     2474 <Node_addField+0x1b6>
    2360:	48 c7 45 e0 00 00 00 	movq   $0x0,-0x20(%rbp)
    2367:	00 
    2368:	eb 65                	jmp    23cf <Node_addField+0x111>
    236a:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    236e:	48 8b 48 50          	mov    0x50(%rax),%rcx
    2372:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    2376:	48 89 d0             	mov    %rdx,%rax
    2379:	48 c1 e0 02          	shl    $0x2,%rax
    237d:	48 01 d0             	add    %rdx,%rax
    2380:	48 c1 e0 03          	shl    $0x3,%rax
    2384:	48 8d 14 01          	lea    (%rcx,%rax,1),%rdx
    2388:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
    238c:	48 89 c8             	mov    %rcx,%rax
    238f:	48 c1 e0 02          	shl    $0x2,%rax
    2393:	48 01 c8             	add    %rcx,%rax
    2396:	48 c1 e0 03          	shl    $0x3,%rax
    239a:	48 89 c1             	mov    %rax,%rcx
    239d:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    23a1:	48 01 c8             	add    %rcx,%rax
    23a4:	48 8b 0a             	mov    (%rdx),%rcx
    23a7:	48 8b 5a 08          	mov    0x8(%rdx),%rbx
    23ab:	48 89 08             	mov    %rcx,(%rax)
    23ae:	48 89 58 08          	mov    %rbx,0x8(%rax)
    23b2:	48 8b 4a 10          	mov    0x10(%rdx),%rcx
    23b6:	48 8b 5a 18          	mov    0x18(%rdx),%rbx
    23ba:	48 89 48 10          	mov    %rcx,0x10(%rax)
    23be:	48 89 58 18          	mov    %rbx,0x18(%rax)
    23c2:	48 8b 52 20          	mov    0x20(%rdx),%rdx
    23c6:	48 89 50 20          	mov    %rdx,0x20(%rax)
    23ca:	48 83 45 e0 01       	addq   $0x1,-0x20(%rbp)
    23cf:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    23d3:	48 8b 40 58          	mov    0x58(%rax),%rax
    23d7:	48 39 45 e0          	cmp    %rax,-0x20(%rbp)
    23db:	72 8d                	jb     236a <Node_addField+0xac>
    23dd:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    23e1:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    23e5:	48 89 50 50          	mov    %rdx,0x50(%rax)
    23e9:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    23ed:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    23f1:	48 89 50 60          	mov    %rdx,0x60(%rax)
    23f5:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    23f9:	48 8b 48 50          	mov    0x50(%rax),%rcx
    23fd:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    2401:	48 8b 50 58          	mov    0x58(%rax),%rdx
    2405:	48 89 d0             	mov    %rdx,%rax
    2408:	48 c1 e0 02          	shl    $0x2,%rax
    240c:	48 01 d0             	add    %rdx,%rax
    240f:	48 c1 e0 03          	shl    $0x3,%rax
    2413:	48 01 c1             	add    %rax,%rcx
    2416:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    241a:	48 8b 55 b8          	mov    -0x48(%rbp),%rdx
    241e:	48 89 01             	mov    %rax,(%rcx)
    2421:	48 89 51 08          	mov    %rdx,0x8(%rcx)
    2425:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    2429:	48 8b 48 50          	mov    0x50(%rax),%rcx
    242d:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    2431:	48 8b 50 58          	mov    0x58(%rax),%rdx
    2435:	48 89 d0             	mov    %rdx,%rax
    2438:	48 c1 e0 02          	shl    $0x2,%rax
    243c:	48 01 d0             	add    %rdx,%rax
    243f:	48 c1 e0 03          	shl    $0x3,%rax
    2443:	48 01 c1             	add    %rax,%rcx
    2446:	48 8b 45 10          	mov    0x10(%rbp),%rax
    244a:	48 8b 55 18          	mov    0x18(%rbp),%rdx
    244e:	48 89 41 10          	mov    %rax,0x10(%rcx)
    2452:	48 89 51 18          	mov    %rdx,0x18(%rcx)
    2456:	48 8b 45 20          	mov    0x20(%rbp),%rax
    245a:	48 89 41 20          	mov    %rax,0x20(%rcx)
    245e:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    2462:	48 8b 40 58          	mov    0x58(%rax),%rax
    2466:	48 8d 50 01          	lea    0x1(%rax),%rdx
    246a:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    246e:	48 89 50 58          	mov    %rdx,0x58(%rax)
    2472:	eb 01                	jmp    2475 <Node_addField+0x1b7>
    2474:	90                   	nop
    2475:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
    2479:	c9                   	leave
    247a:	c3                   	ret

000000000000247b <Node_addChild>:
    247b:	55                   	push   %rbp
    247c:	48 89 e5             	mov    %rsp,%rbp
    247f:	53                   	push   %rbx
    2480:	48 83 ec 38          	sub    $0x38,%rsp
    2484:	48 89 7d c8          	mov    %rdi,-0x38(%rbp)
    2488:	48 89 75 c0          	mov    %rsi,-0x40(%rbp)
    248c:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    2490:	48 8b 50 78          	mov    0x78(%rax),%rdx
    2494:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    2498:	48 8b 80 80 00 00 00 	mov    0x80(%rax),%rax
    249f:	48 39 c2             	cmp    %rax,%rdx
    24a2:	0f 82 6e 01 00 00    	jb     2616 <Node_addChild+0x19b>
    24a8:	48 c7 45 d8 08 00 00 	movq   $0x8,-0x28(%rbp)
    24af:	00 
    24b0:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    24b4:	48 8b 80 80 00 00 00 	mov    0x80(%rax),%rax
    24bb:	48 85 c0             	test   %rax,%rax
    24be:	74 12                	je     24d2 <Node_addChild+0x57>
    24c0:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    24c4:	48 8b 80 80 00 00 00 	mov    0x80(%rax),%rax
    24cb:	48 01 c0             	add    %rax,%rax
    24ce:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
    24d2:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    24d6:	48 69 c8 98 00 00 00 	imul   $0x98,%rax,%rcx
    24dd:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    24e1:	48 8b 80 90 00 00 00 	mov    0x90(%rax),%rax
    24e8:	ba 08 00 00 00       	mov    $0x8,%edx
    24ed:	48 89 ce             	mov    %rcx,%rsi
    24f0:	48 89 c7             	mov    %rax,%rdi
    24f3:	e8 d9 ed ff ff       	call   12d1 <Arena_alloc>
    24f8:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    24fc:	48 83 7d e8 00       	cmpq   $0x0,-0x18(%rbp)
    2501:	0f 84 eb 01 00 00    	je     26f2 <Node_addChild+0x277>
    2507:	48 c7 45 e0 00 00 00 	movq   $0x0,-0x20(%rbp)
    250e:	00 
    250f:	e9 d5 00 00 00       	jmp    25e9 <Node_addChild+0x16e>
    2514:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    2518:	48 8b 50 70          	mov    0x70(%rax),%rdx
    251c:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    2520:	48 69 c0 98 00 00 00 	imul   $0x98,%rax,%rax
    2527:	48 01 c2             	add    %rax,%rdx
    252a:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    252e:	48 69 c8 98 00 00 00 	imul   $0x98,%rax,%rcx
    2535:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    2539:	48 01 c8             	add    %rcx,%rax
    253c:	48 8b 0a             	mov    (%rdx),%rcx
    253f:	48 8b 5a 08          	mov    0x8(%rdx),%rbx
    2543:	48 89 08             	mov    %rcx,(%rax)
    2546:	48 89 58 08          	mov    %rbx,0x8(%rax)
    254a:	48 8b 4a 10          	mov    0x10(%rdx),%rcx
    254e:	48 8b 5a 18          	mov    0x18(%rdx),%rbx
    2552:	48 89 48 10          	mov    %rcx,0x10(%rax)
    2556:	48 89 58 18          	mov    %rbx,0x18(%rax)
    255a:	48 8b 4a 20          	mov    0x20(%rdx),%rcx
    255e:	48 8b 5a 28          	mov    0x28(%rdx),%rbx
    2562:	48 89 48 20          	mov    %rcx,0x20(%rax)
    2566:	48 89 58 28          	mov    %rbx,0x28(%rax)
    256a:	48 8b 4a 30          	mov    0x30(%rdx),%rcx
    256e:	48 8b 5a 38          	mov    0x38(%rdx),%rbx
    2572:	48 89 48 30          	mov    %rcx,0x30(%rax)
    2576:	48 89 58 38          	mov    %rbx,0x38(%rax)
    257a:	48 8b 4a 40          	mov    0x40(%rdx),%rcx
    257e:	48 8b 5a 48          	mov    0x48(%rdx),%rbx
    2582:	48 89 48 40          	mov    %rcx,0x40(%rax)
    2586:	48 89 58 48          	mov    %rbx,0x48(%rax)
    258a:	48 8b 4a 50          	mov    0x50(%rdx),%rcx
    258e:	48 8b 5a 58          	mov    0x58(%rdx),%rbx
    2592:	48 89 48 50          	mov    %rcx,0x50(%rax)
    2596:	48 89 58 58          	mov    %rbx,0x58(%rax)
    259a:	48 8b 4a 60          	mov    0x60(%rdx),%rcx
    259e:	48 8b 5a 68          	mov    0x68(%rdx),%rbx
    25a2:	48 89 48 60          	mov    %rcx,0x60(%rax)
    25a6:	48 89 58 68          	mov    %rbx,0x68(%rax)
    25aa:	48 8b 4a 70          	mov    0x70(%rdx),%rcx
    25ae:	48 8b 5a 78          	mov    0x78(%rdx),%rbx
    25b2:	48 89 48 70          	mov    %rcx,0x70(%rax)
    25b6:	48 89 58 78          	mov    %rbx,0x78(%rax)
    25ba:	48 8b 8a 80 00 00 00 	mov    0x80(%rdx),%rcx
    25c1:	48 8b 9a 88 00 00 00 	mov    0x88(%rdx),%rbx
    25c8:	48 89 88 80 00 00 00 	mov    %rcx,0x80(%rax)
    25cf:	48 89 98 88 00 00 00 	mov    %rbx,0x88(%rax)
    25d6:	48 8b 92 90 00 00 00 	mov    0x90(%rdx),%rdx
    25dd:	48 89 90 90 00 00 00 	mov    %rdx,0x90(%rax)
    25e4:	48 83 45 e0 01       	addq   $0x1,-0x20(%rbp)
    25e9:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    25ed:	48 8b 40 78          	mov    0x78(%rax),%rax
    25f1:	48 39 45 e0          	cmp    %rax,-0x20(%rbp)
    25f5:	0f 82 19 ff ff ff    	jb     2514 <Node_addChild+0x99>
    25fb:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    25ff:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    2603:	48 89 50 70          	mov    %rdx,0x70(%rax)
    2607:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    260b:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    260f:	48 89 90 80 00 00 00 	mov    %rdx,0x80(%rax)
    2616:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    261a:	48 8b 50 70          	mov    0x70(%rax),%rdx
    261e:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    2622:	48 8b 40 78          	mov    0x78(%rax),%rax
    2626:	48 69 c0 98 00 00 00 	imul   $0x98,%rax,%rax
    262d:	48 01 c2             	add    %rax,%rdx
    2630:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
    2634:	48 8b 08             	mov    (%rax),%rcx
    2637:	48 8b 58 08          	mov    0x8(%rax),%rbx
    263b:	48 89 0a             	mov    %rcx,(%rdx)
    263e:	48 89 5a 08          	mov    %rbx,0x8(%rdx)
    2642:	48 8b 48 10          	mov    0x10(%rax),%rcx
    2646:	48 8b 58 18          	mov    0x18(%rax),%rbx
    264a:	48 89 4a 10          	mov    %rcx,0x10(%rdx)
    264e:	48 89 5a 18          	mov    %rbx,0x18(%rdx)
    2652:	48 8b 48 20          	mov    0x20(%rax),%rcx
    2656:	48 8b 58 28          	mov    0x28(%rax),%rbx
    265a:	48 89 4a 20          	mov    %rcx,0x20(%rdx)
    265e:	48 89 5a 28          	mov    %rbx,0x28(%rdx)
    2662:	48 8b 48 30          	mov    0x30(%rax),%rcx
    2666:	48 8b 58 38          	mov    0x38(%rax),%rbx
    266a:	48 89 4a 30          	mov    %rcx,0x30(%rdx)
    266e:	48 89 5a 38          	mov    %rbx,0x38(%rdx)
    2672:	48 8b 48 40          	mov    0x40(%rax),%rcx
    2676:	48 8b 58 48          	mov    0x48(%rax),%rbx
    267a:	48 89 4a 40          	mov    %rcx,0x40(%rdx)
    267e:	48 89 5a 48          	mov    %rbx,0x48(%rdx)
    2682:	48 8b 48 50          	mov    0x50(%rax),%rcx
    2686:	48 8b 58 58          	mov    0x58(%rax),%rbx
    268a:	48 89 4a 50          	mov    %rcx,0x50(%rdx)
    268e:	48 89 5a 58          	mov    %rbx,0x58(%rdx)
    2692:	48 8b 48 60          	mov    0x60(%rax),%rcx
    2696:	48 8b 58 68          	mov    0x68(%rax),%rbx
    269a:	48 89 4a 60          	mov    %rcx,0x60(%rdx)
    269e:	48 89 5a 68          	mov    %rbx,0x68(%rdx)
    26a2:	48 8b 48 70          	mov    0x70(%rax),%rcx
    26a6:	48 8b 58 78          	mov    0x78(%rax),%rbx
    26aa:	48 89 4a 70          	mov    %rcx,0x70(%rdx)
    26ae:	48 89 5a 78          	mov    %rbx,0x78(%rdx)
    26b2:	48 8b 88 80 00 00 00 	mov    0x80(%rax),%rcx
    26b9:	48 8b 98 88 00 00 00 	mov    0x88(%rax),%rbx
    26c0:	48 89 8a 80 00 00 00 	mov    %rcx,0x80(%rdx)
    26c7:	48 89 9a 88 00 00 00 	mov    %rbx,0x88(%rdx)
    26ce:	48 8b 80 90 00 00 00 	mov    0x90(%rax),%rax
    26d5:	48 89 82 90 00 00 00 	mov    %rax,0x90(%rdx)
    26dc:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    26e0:	48 8b 40 78          	mov    0x78(%rax),%rax
    26e4:	48 8d 50 01          	lea    0x1(%rax),%rdx
    26e8:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    26ec:	48 89 50 78          	mov    %rdx,0x78(%rax)
    26f0:	eb 01                	jmp    26f3 <Node_addChild+0x278>
    26f2:	90                   	nop
    26f3:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
    26f7:	c9                   	leave
    26f8:	c3                   	ret

00000000000026f9 <nodeKindName>:
    26f9:	55                   	push   %rbp
    26fa:	48 89 e5             	mov    %rsp,%rbp
    26fd:	89 7d fc             	mov    %edi,-0x4(%rbp)
    2700:	83 7d fc 1b          	cmpl   $0x1b,-0x4(%rbp)
    2704:	0f 84 20 03 00 00    	je     2a2a <nodeKindName+0x331>
    270a:	83 7d fc 1b          	cmpl   $0x1b,-0x4(%rbp)
    270e:	0f 87 1f 03 00 00    	ja     2a33 <nodeKindName+0x33a>
    2714:	83 7d fc 1a          	cmpl   $0x1a,-0x4(%rbp)
    2718:	0f 84 03 03 00 00    	je     2a21 <nodeKindName+0x328>
    271e:	83 7d fc 1a          	cmpl   $0x1a,-0x4(%rbp)
    2722:	0f 87 0b 03 00 00    	ja     2a33 <nodeKindName+0x33a>
    2728:	83 7d fc 19          	cmpl   $0x19,-0x4(%rbp)
    272c:	0f 84 e6 02 00 00    	je     2a18 <nodeKindName+0x31f>
    2732:	83 7d fc 19          	cmpl   $0x19,-0x4(%rbp)
    2736:	0f 87 f7 02 00 00    	ja     2a33 <nodeKindName+0x33a>
    273c:	83 7d fc 18          	cmpl   $0x18,-0x4(%rbp)
    2740:	0f 84 c9 02 00 00    	je     2a0f <nodeKindName+0x316>
    2746:	83 7d fc 18          	cmpl   $0x18,-0x4(%rbp)
    274a:	0f 87 e3 02 00 00    	ja     2a33 <nodeKindName+0x33a>
    2750:	83 7d fc 17          	cmpl   $0x17,-0x4(%rbp)
    2754:	0f 84 ac 02 00 00    	je     2a06 <nodeKindName+0x30d>
    275a:	83 7d fc 17          	cmpl   $0x17,-0x4(%rbp)
    275e:	0f 87 cf 02 00 00    	ja     2a33 <nodeKindName+0x33a>
    2764:	83 7d fc 16          	cmpl   $0x16,-0x4(%rbp)
    2768:	0f 84 8f 02 00 00    	je     29fd <nodeKindName+0x304>
    276e:	83 7d fc 16          	cmpl   $0x16,-0x4(%rbp)
    2772:	0f 87 bb 02 00 00    	ja     2a33 <nodeKindName+0x33a>
    2778:	83 7d fc 15          	cmpl   $0x15,-0x4(%rbp)
    277c:	0f 84 72 02 00 00    	je     29f4 <nodeKindName+0x2fb>
    2782:	83 7d fc 15          	cmpl   $0x15,-0x4(%rbp)
    2786:	0f 87 a7 02 00 00    	ja     2a33 <nodeKindName+0x33a>
    278c:	83 7d fc 14          	cmpl   $0x14,-0x4(%rbp)
    2790:	0f 84 55 02 00 00    	je     29eb <nodeKindName+0x2f2>
    2796:	83 7d fc 14          	cmpl   $0x14,-0x4(%rbp)
    279a:	0f 87 93 02 00 00    	ja     2a33 <nodeKindName+0x33a>
    27a0:	83 7d fc 13          	cmpl   $0x13,-0x4(%rbp)
    27a4:	0f 84 38 02 00 00    	je     29e2 <nodeKindName+0x2e9>
    27aa:	83 7d fc 13          	cmpl   $0x13,-0x4(%rbp)
    27ae:	0f 87 7f 02 00 00    	ja     2a33 <nodeKindName+0x33a>
    27b4:	83 7d fc 12          	cmpl   $0x12,-0x4(%rbp)
    27b8:	0f 84 1b 02 00 00    	je     29d9 <nodeKindName+0x2e0>
    27be:	83 7d fc 12          	cmpl   $0x12,-0x4(%rbp)
    27c2:	0f 87 6b 02 00 00    	ja     2a33 <nodeKindName+0x33a>
    27c8:	83 7d fc 11          	cmpl   $0x11,-0x4(%rbp)
    27cc:	0f 84 fe 01 00 00    	je     29d0 <nodeKindName+0x2d7>
    27d2:	83 7d fc 11          	cmpl   $0x11,-0x4(%rbp)
    27d6:	0f 87 57 02 00 00    	ja     2a33 <nodeKindName+0x33a>
    27dc:	83 7d fc 10          	cmpl   $0x10,-0x4(%rbp)
    27e0:	0f 84 e1 01 00 00    	je     29c7 <nodeKindName+0x2ce>
    27e6:	83 7d fc 10          	cmpl   $0x10,-0x4(%rbp)
    27ea:	0f 87 43 02 00 00    	ja     2a33 <nodeKindName+0x33a>
    27f0:	83 7d fc 0f          	cmpl   $0xf,-0x4(%rbp)
    27f4:	0f 84 c4 01 00 00    	je     29be <nodeKindName+0x2c5>
    27fa:	83 7d fc 0f          	cmpl   $0xf,-0x4(%rbp)
    27fe:	0f 87 2f 02 00 00    	ja     2a33 <nodeKindName+0x33a>
    2804:	83 7d fc 0e          	cmpl   $0xe,-0x4(%rbp)
    2808:	0f 84 a7 01 00 00    	je     29b5 <nodeKindName+0x2bc>
    280e:	83 7d fc 0e          	cmpl   $0xe,-0x4(%rbp)
    2812:	0f 87 1b 02 00 00    	ja     2a33 <nodeKindName+0x33a>
    2818:	83 7d fc 0d          	cmpl   $0xd,-0x4(%rbp)
    281c:	0f 84 87 01 00 00    	je     29a9 <nodeKindName+0x2b0>
    2822:	83 7d fc 0d          	cmpl   $0xd,-0x4(%rbp)
    2826:	0f 87 07 02 00 00    	ja     2a33 <nodeKindName+0x33a>
    282c:	83 7d fc 0c          	cmpl   $0xc,-0x4(%rbp)
    2830:	0f 84 67 01 00 00    	je     299d <nodeKindName+0x2a4>
    2836:	83 7d fc 0c          	cmpl   $0xc,-0x4(%rbp)
    283a:	0f 87 f3 01 00 00    	ja     2a33 <nodeKindName+0x33a>
    2840:	83 7d fc 0b          	cmpl   $0xb,-0x4(%rbp)
    2844:	0f 84 47 01 00 00    	je     2991 <nodeKindName+0x298>
    284a:	83 7d fc 0b          	cmpl   $0xb,-0x4(%rbp)
    284e:	0f 87 df 01 00 00    	ja     2a33 <nodeKindName+0x33a>
    2854:	83 7d fc 0a          	cmpl   $0xa,-0x4(%rbp)
    2858:	0f 84 27 01 00 00    	je     2985 <nodeKindName+0x28c>
    285e:	83 7d fc 0a          	cmpl   $0xa,-0x4(%rbp)
    2862:	0f 87 cb 01 00 00    	ja     2a33 <nodeKindName+0x33a>
    2868:	83 7d fc 09          	cmpl   $0x9,-0x4(%rbp)
    286c:	0f 84 07 01 00 00    	je     2979 <nodeKindName+0x280>
    2872:	83 7d fc 09          	cmpl   $0x9,-0x4(%rbp)
    2876:	0f 87 b7 01 00 00    	ja     2a33 <nodeKindName+0x33a>
    287c:	83 7d fc 08          	cmpl   $0x8,-0x4(%rbp)
    2880:	0f 84 e7 00 00 00    	je     296d <nodeKindName+0x274>
    2886:	83 7d fc 08          	cmpl   $0x8,-0x4(%rbp)
    288a:	0f 87 a3 01 00 00    	ja     2a33 <nodeKindName+0x33a>
    2890:	83 7d fc 07          	cmpl   $0x7,-0x4(%rbp)
    2894:	0f 84 c7 00 00 00    	je     2961 <nodeKindName+0x268>
    289a:	83 7d fc 07          	cmpl   $0x7,-0x4(%rbp)
    289e:	0f 87 8f 01 00 00    	ja     2a33 <nodeKindName+0x33a>
    28a4:	83 7d fc 06          	cmpl   $0x6,-0x4(%rbp)
    28a8:	0f 84 a7 00 00 00    	je     2955 <nodeKindName+0x25c>
    28ae:	83 7d fc 06          	cmpl   $0x6,-0x4(%rbp)
    28b2:	0f 87 7b 01 00 00    	ja     2a33 <nodeKindName+0x33a>
    28b8:	83 7d fc 05          	cmpl   $0x5,-0x4(%rbp)
    28bc:	0f 84 87 00 00 00    	je     2949 <nodeKindName+0x250>
    28c2:	83 7d fc 05          	cmpl   $0x5,-0x4(%rbp)
    28c6:	0f 87 67 01 00 00    	ja     2a33 <nodeKindName+0x33a>
    28cc:	83 7d fc 04          	cmpl   $0x4,-0x4(%rbp)
    28d0:	74 6b                	je     293d <nodeKindName+0x244>
    28d2:	83 7d fc 04          	cmpl   $0x4,-0x4(%rbp)
    28d6:	0f 87 57 01 00 00    	ja     2a33 <nodeKindName+0x33a>
    28dc:	83 7d fc 03          	cmpl   $0x3,-0x4(%rbp)
    28e0:	74 4f                	je     2931 <nodeKindName+0x238>
    28e2:	83 7d fc 03          	cmpl   $0x3,-0x4(%rbp)
    28e6:	0f 87 47 01 00 00    	ja     2a33 <nodeKindName+0x33a>
    28ec:	83 7d fc 02          	cmpl   $0x2,-0x4(%rbp)
    28f0:	74 33                	je     2925 <nodeKindName+0x22c>
    28f2:	83 7d fc 02          	cmpl   $0x2,-0x4(%rbp)
    28f6:	0f 87 37 01 00 00    	ja     2a33 <nodeKindName+0x33a>
    28fc:	83 7d fc 00          	cmpl   $0x0,-0x4(%rbp)
    2900:	74 0b                	je     290d <nodeKindName+0x214>
    2902:	83 7d fc 01          	cmpl   $0x1,-0x4(%rbp)
    2906:	74 11                	je     2919 <nodeKindName+0x220>
    2908:	e9 26 01 00 00       	jmp    2a33 <nodeKindName+0x33a>
    290d:	48 8d 05 ff 76 00 00 	lea    0x76ff(%rip),%rax        # a013 <_IO_stdin_used+0x13>
    2914:	e9 21 01 00 00       	jmp    2a3a <nodeKindName+0x341>
    2919:	48 8d 05 f8 76 00 00 	lea    0x76f8(%rip),%rax        # a018 <_IO_stdin_used+0x18>
    2920:	e9 15 01 00 00       	jmp    2a3a <nodeKindName+0x341>
    2925:	48 8d 05 f3 76 00 00 	lea    0x76f3(%rip),%rax        # a01f <_IO_stdin_used+0x1f>
    292c:	e9 09 01 00 00       	jmp    2a3a <nodeKindName+0x341>
    2931:	48 8d 05 ee 76 00 00 	lea    0x76ee(%rip),%rax        # a026 <_IO_stdin_used+0x26>
    2938:	e9 fd 00 00 00       	jmp    2a3a <nodeKindName+0x341>
    293d:	48 8d 05 e8 76 00 00 	lea    0x76e8(%rip),%rax        # a02c <_IO_stdin_used+0x2c>
    2944:	e9 f1 00 00 00       	jmp    2a3a <nodeKindName+0x341>
    2949:	48 8d 05 e6 76 00 00 	lea    0x76e6(%rip),%rax        # a036 <_IO_stdin_used+0x36>
    2950:	e9 e5 00 00 00       	jmp    2a3a <nodeKindName+0x341>
    2955:	48 8d 05 e2 76 00 00 	lea    0x76e2(%rip),%rax        # a03e <_IO_stdin_used+0x3e>
    295c:	e9 d9 00 00 00       	jmp    2a3a <nodeKindName+0x341>
    2961:	48 8d 05 dc 76 00 00 	lea    0x76dc(%rip),%rax        # a044 <_IO_stdin_used+0x44>
    2968:	e9 cd 00 00 00       	jmp    2a3a <nodeKindName+0x341>
    296d:	48 8d 05 d5 76 00 00 	lea    0x76d5(%rip),%rax        # a049 <_IO_stdin_used+0x49>
    2974:	e9 c1 00 00 00       	jmp    2a3a <nodeKindName+0x341>
    2979:	48 8d 05 ce 76 00 00 	lea    0x76ce(%rip),%rax        # a04e <_IO_stdin_used+0x4e>
    2980:	e9 b5 00 00 00       	jmp    2a3a <nodeKindName+0x341>
    2985:	48 8d 05 c8 76 00 00 	lea    0x76c8(%rip),%rax        # a054 <_IO_stdin_used+0x54>
    298c:	e9 a9 00 00 00       	jmp    2a3a <nodeKindName+0x341>
    2991:	48 8d 05 c1 76 00 00 	lea    0x76c1(%rip),%rax        # a059 <_IO_stdin_used+0x59>
    2998:	e9 9d 00 00 00       	jmp    2a3a <nodeKindName+0x341>
    299d:	48 8d 05 bb 76 00 00 	lea    0x76bb(%rip),%rax        # a05f <_IO_stdin_used+0x5f>
    29a4:	e9 91 00 00 00       	jmp    2a3a <nodeKindName+0x341>
    29a9:	48 8d 05 b6 76 00 00 	lea    0x76b6(%rip),%rax        # a066 <_IO_stdin_used+0x66>
    29b0:	e9 85 00 00 00       	jmp    2a3a <nodeKindName+0x341>
    29b5:	48 8d 05 af 76 00 00 	lea    0x76af(%rip),%rax        # a06b <_IO_stdin_used+0x6b>
    29bc:	eb 7c                	jmp    2a3a <nodeKindName+0x341>
    29be:	48 8d 05 af 76 00 00 	lea    0x76af(%rip),%rax        # a074 <_IO_stdin_used+0x74>
    29c5:	eb 73                	jmp    2a3a <nodeKindName+0x341>
    29c7:	48 8d 05 af 76 00 00 	lea    0x76af(%rip),%rax        # a07d <_IO_stdin_used+0x7d>
    29ce:	eb 6a                	jmp    2a3a <nodeKindName+0x341>
    29d0:	48 8d 05 aa 76 00 00 	lea    0x76aa(%rip),%rax        # a081 <_IO_stdin_used+0x81>
    29d7:	eb 61                	jmp    2a3a <nodeKindName+0x341>
    29d9:	48 8d 05 a5 76 00 00 	lea    0x76a5(%rip),%rax        # a085 <_IO_stdin_used+0x85>
    29e0:	eb 58                	jmp    2a3a <nodeKindName+0x341>
    29e2:	48 8d 05 a4 76 00 00 	lea    0x76a4(%rip),%rax        # a08d <_IO_stdin_used+0x8d>
    29e9:	eb 4f                	jmp    2a3a <nodeKindName+0x341>
    29eb:	48 8d 05 a0 76 00 00 	lea    0x76a0(%rip),%rax        # a092 <_IO_stdin_used+0x92>
    29f2:	eb 46                	jmp    2a3a <nodeKindName+0x341>
    29f4:	48 8d 05 9e 76 00 00 	lea    0x769e(%rip),%rax        # a099 <_IO_stdin_used+0x99>
    29fb:	eb 3d                	jmp    2a3a <nodeKindName+0x341>
    29fd:	48 8d 05 99 76 00 00 	lea    0x7699(%rip),%rax        # a09d <_IO_stdin_used+0x9d>
    2a04:	eb 34                	jmp    2a3a <nodeKindName+0x341>
    2a06:	48 8d 05 93 76 00 00 	lea    0x7693(%rip),%rax        # a0a0 <_IO_stdin_used+0xa0>
    2a0d:	eb 2b                	jmp    2a3a <nodeKindName+0x341>
    2a0f:	48 8d 05 91 76 00 00 	lea    0x7691(%rip),%rax        # a0a7 <_IO_stdin_used+0xa7>
    2a16:	eb 22                	jmp    2a3a <nodeKindName+0x341>
    2a18:	48 8d 05 8d 76 00 00 	lea    0x768d(%rip),%rax        # a0ac <_IO_stdin_used+0xac>
    2a1f:	eb 19                	jmp    2a3a <nodeKindName+0x341>
    2a21:	48 8d 05 8e 76 00 00 	lea    0x768e(%rip),%rax        # a0b6 <_IO_stdin_used+0xb6>
    2a28:	eb 10                	jmp    2a3a <nodeKindName+0x341>
    2a2a:	48 8d 05 8e 76 00 00 	lea    0x768e(%rip),%rax        # a0bf <_IO_stdin_used+0xbf>
    2a31:	eb 07                	jmp    2a3a <nodeKindName+0x341>
    2a33:	48 8d 05 8d 76 00 00 	lea    0x768d(%rip),%rax        # a0c7 <_IO_stdin_used+0xc7>
    2a3a:	5d                   	pop    %rbp
    2a3b:	c3                   	ret

0000000000002a3c <valueArrayPush>:
    2a3c:	55                   	push   %rbp
    2a3d:	48 89 e5             	mov    %rsp,%rbp
    2a40:	48 83 ec 30          	sub    $0x30,%rsp
    2a44:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
    2a48:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    2a4c:	48 8b 50 08          	mov    0x8(%rax),%rdx
    2a50:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    2a54:	48 8b 40 10          	mov    0x10(%rax),%rax
    2a58:	48 39 c2             	cmp    %rax,%rdx
    2a5b:	0f 82 e1 00 00 00    	jb     2b42 <valueArrayPush+0x106>
    2a61:	48 c7 45 e8 08 00 00 	movq   $0x8,-0x18(%rbp)
    2a68:	00 
    2a69:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    2a6d:	48 8b 40 10          	mov    0x10(%rax),%rax
    2a71:	48 85 c0             	test   %rax,%rax
    2a74:	74 0f                	je     2a85 <valueArrayPush+0x49>
    2a76:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    2a7a:	48 8b 40 10          	mov    0x10(%rax),%rax
    2a7e:	48 01 c0             	add    %rax,%rax
    2a81:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    2a85:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    2a89:	48 89 d0             	mov    %rdx,%rax
    2a8c:	48 01 c0             	add    %rax,%rax
    2a8f:	48 01 d0             	add    %rdx,%rax
    2a92:	48 c1 e0 03          	shl    $0x3,%rax
    2a96:	48 89 c1             	mov    %rax,%rcx
    2a99:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    2a9d:	48 8b 40 18          	mov    0x18(%rax),%rax
    2aa1:	ba 08 00 00 00       	mov    $0x8,%edx
    2aa6:	48 89 ce             	mov    %rcx,%rsi
    2aa9:	48 89 c7             	mov    %rax,%rdi
    2aac:	e8 20 e8 ff ff       	call   12d1 <Arena_alloc>
    2ab1:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    2ab5:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    2aba:	0f 84 ce 00 00 00    	je     2b8e <valueArrayPush+0x152>
    2ac0:	48 c7 45 f0 00 00 00 	movq   $0x0,-0x10(%rbp)
    2ac7:	00 
    2ac8:	eb 53                	jmp    2b1d <valueArrayPush+0xe1>
    2aca:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    2ace:	48 8b 08             	mov    (%rax),%rcx
    2ad1:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
    2ad5:	48 89 d0             	mov    %rdx,%rax
    2ad8:	48 01 c0             	add    %rax,%rax
    2adb:	48 01 d0             	add    %rdx,%rax
    2ade:	48 c1 e0 03          	shl    $0x3,%rax
    2ae2:	48 8d 34 01          	lea    (%rcx,%rax,1),%rsi
    2ae6:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
    2aea:	48 89 d0             	mov    %rdx,%rax
    2aed:	48 01 c0             	add    %rax,%rax
    2af0:	48 01 d0             	add    %rdx,%rax
    2af3:	48 c1 e0 03          	shl    $0x3,%rax
    2af7:	48 89 c2             	mov    %rax,%rdx
    2afa:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2afe:	48 8d 0c 02          	lea    (%rdx,%rax,1),%rcx
    2b02:	48 8b 06             	mov    (%rsi),%rax
    2b05:	48 8b 56 08          	mov    0x8(%rsi),%rdx
    2b09:	48 89 01             	mov    %rax,(%rcx)
    2b0c:	48 89 51 08          	mov    %rdx,0x8(%rcx)
    2b10:	48 8b 46 10          	mov    0x10(%rsi),%rax
    2b14:	48 89 41 10          	mov    %rax,0x10(%rcx)
    2b18:	48 83 45 f0 01       	addq   $0x1,-0x10(%rbp)
    2b1d:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    2b21:	48 8b 40 08          	mov    0x8(%rax),%rax
    2b25:	48 39 45 f0          	cmp    %rax,-0x10(%rbp)
    2b29:	72 9f                	jb     2aca <valueArrayPush+0x8e>
    2b2b:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    2b2f:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
    2b33:	48 89 10             	mov    %rdx,(%rax)
    2b36:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    2b3a:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    2b3e:	48 89 50 10          	mov    %rdx,0x10(%rax)
    2b42:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    2b46:	48 8b 08             	mov    (%rax),%rcx
    2b49:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    2b4d:	48 8b 50 08          	mov    0x8(%rax),%rdx
    2b51:	48 89 d0             	mov    %rdx,%rax
    2b54:	48 01 c0             	add    %rax,%rax
    2b57:	48 01 d0             	add    %rdx,%rax
    2b5a:	48 c1 e0 03          	shl    $0x3,%rax
    2b5e:	48 01 c1             	add    %rax,%rcx
    2b61:	48 8b 45 10          	mov    0x10(%rbp),%rax
    2b65:	48 8b 55 18          	mov    0x18(%rbp),%rdx
    2b69:	48 89 01             	mov    %rax,(%rcx)
    2b6c:	48 89 51 08          	mov    %rdx,0x8(%rcx)
    2b70:	48 8b 45 20          	mov    0x20(%rbp),%rax
    2b74:	48 89 41 10          	mov    %rax,0x10(%rcx)
    2b78:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    2b7c:	48 8b 40 08          	mov    0x8(%rax),%rax
    2b80:	48 8d 50 01          	lea    0x1(%rax),%rdx
    2b84:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    2b88:	48 89 50 08          	mov    %rdx,0x8(%rax)
    2b8c:	eb 01                	jmp    2b8f <valueArrayPush+0x153>
    2b8e:	90                   	nop
    2b8f:	c9                   	leave
    2b90:	c3                   	ret

0000000000002b91 <Parser_init>:
    2b91:	55                   	push   %rbp
    2b92:	48 89 e5             	mov    %rsp,%rbp
    2b95:	53                   	push   %rbx
    2b96:	48 83 ec 78          	sub    $0x78,%rsp
    2b9a:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
    2b9e:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
    2ba2:	48 89 55 c0          	mov    %rdx,-0x40(%rbp)
    2ba6:	48 89 4d c8          	mov    %rcx,-0x38(%rbp)
    2baa:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    2bb1:	00 00 
    2bb3:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    2bb7:	31 c0                	xor    %eax,%eax
    2bb9:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    2bbd:	48 8b 55 d0          	mov    -0x30(%rbp),%rdx
    2bc1:	48 89 90 b0 00 00 00 	mov    %rdx,0xb0(%rax)
    2bc8:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    2bcc:	c7 80 b8 00 00 00 00 	movl   $0x0,0xb8(%rax)
    2bd3:	00 00 00 
    2bd6:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    2bda:	48 8b 80 b0 00 00 00 	mov    0xb0(%rax),%rax
    2be1:	ba 08 00 00 00       	mov    $0x8,%edx
    2be6:	be 30 00 00 00       	mov    $0x30,%esi
    2beb:	48 89 c7             	mov    %rax,%rdi
    2bee:	e8 de e6 ff ff       	call   12d1 <Arena_alloc>
    2bf3:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    2bf7:	48 89 02             	mov    %rax,(%rdx)
    2bfa:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    2bfe:	48 8b 00             	mov    (%rax),%rax
    2c01:	48 85 c0             	test   %rax,%rax
    2c04:	0f 84 12 01 00 00    	je     2d1c <Parser_init+0x18b>
    2c0a:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    2c0e:	48 8b 00             	mov    (%rax),%rax
    2c11:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
    2c15:	48 8b 55 c8          	mov    -0x38(%rbp),%rdx
    2c19:	48 89 ce             	mov    %rcx,%rsi
    2c1c:	48 89 c7             	mov    %rax,%rdi
    2c1f:	e8 00 e9 ff ff       	call   1524 <Lexer_init>
    2c24:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    2c28:	48 8b 10             	mov    (%rax),%rdx
    2c2b:	48 8b 5d d8          	mov    -0x28(%rbp),%rbx
    2c2f:	48 8d 45 80          	lea    -0x80(%rbp),%rax
    2c33:	48 89 d6             	mov    %rdx,%rsi
    2c36:	48 89 c7             	mov    %rax,%rdi
    2c39:	e8 76 ea ff ff       	call   16b4 <Lexer_next>
    2c3e:	48 8b 45 80          	mov    -0x80(%rbp),%rax
    2c42:	48 8b 55 88          	mov    -0x78(%rbp),%rdx
    2c46:	48 89 43 40          	mov    %rax,0x40(%rbx)
    2c4a:	48 89 53 48          	mov    %rdx,0x48(%rbx)
    2c4e:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    2c52:	48 8b 55 98          	mov    -0x68(%rbp),%rdx
    2c56:	48 89 43 50          	mov    %rax,0x50(%rbx)
    2c5a:	48 89 53 58          	mov    %rdx,0x58(%rbx)
    2c5e:	48 8b 45 a0          	mov    -0x60(%rbp),%rax
    2c62:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
    2c66:	48 89 43 60          	mov    %rax,0x60(%rbx)
    2c6a:	48 89 53 68          	mov    %rdx,0x68(%rbx)
    2c6e:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    2c72:	48 89 43 70          	mov    %rax,0x70(%rbx)
    2c76:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    2c7a:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    2c7e:	48 8b 4a 40          	mov    0x40(%rdx),%rcx
    2c82:	48 8b 5a 48          	mov    0x48(%rdx),%rbx
    2c86:	48 89 48 08          	mov    %rcx,0x8(%rax)
    2c8a:	48 89 58 10          	mov    %rbx,0x10(%rax)
    2c8e:	48 8b 4a 50          	mov    0x50(%rdx),%rcx
    2c92:	48 8b 5a 58          	mov    0x58(%rdx),%rbx
    2c96:	48 89 48 18          	mov    %rcx,0x18(%rax)
    2c9a:	48 89 58 20          	mov    %rbx,0x20(%rax)
    2c9e:	48 8b 4a 60          	mov    0x60(%rdx),%rcx
    2ca2:	48 8b 5a 68          	mov    0x68(%rdx),%rbx
    2ca6:	48 89 48 28          	mov    %rcx,0x28(%rax)
    2caa:	48 89 58 30          	mov    %rbx,0x30(%rax)
    2cae:	48 8b 52 70          	mov    0x70(%rdx),%rdx
    2cb2:	48 89 50 38          	mov    %rdx,0x38(%rax)
    2cb6:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    2cba:	48 8b 10             	mov    (%rax),%rdx
    2cbd:	48 8b 5d d8          	mov    -0x28(%rbp),%rbx
    2cc1:	48 8d 45 80          	lea    -0x80(%rbp),%rax
    2cc5:	48 89 d6             	mov    %rdx,%rsi
    2cc8:	48 89 c7             	mov    %rax,%rdi
    2ccb:	e8 e4 e9 ff ff       	call   16b4 <Lexer_next>
    2cd0:	48 8b 45 80          	mov    -0x80(%rbp),%rax
    2cd4:	48 8b 55 88          	mov    -0x78(%rbp),%rdx
    2cd8:	48 89 43 78          	mov    %rax,0x78(%rbx)
    2cdc:	48 89 93 80 00 00 00 	mov    %rdx,0x80(%rbx)
    2ce3:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    2ce7:	48 8b 55 98          	mov    -0x68(%rbp),%rdx
    2ceb:	48 89 83 88 00 00 00 	mov    %rax,0x88(%rbx)
    2cf2:	48 89 93 90 00 00 00 	mov    %rdx,0x90(%rbx)
    2cf9:	48 8b 45 a0          	mov    -0x60(%rbp),%rax
    2cfd:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
    2d01:	48 89 83 98 00 00 00 	mov    %rax,0x98(%rbx)
    2d08:	48 89 93 a0 00 00 00 	mov    %rdx,0xa0(%rbx)
    2d0f:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    2d13:	48 89 83 a8 00 00 00 	mov    %rax,0xa8(%rbx)
    2d1a:	eb 01                	jmp    2d1d <Parser_init+0x18c>
    2d1c:	90                   	nop
    2d1d:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    2d21:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    2d28:	00 00 
    2d2a:	74 05                	je     2d31 <Parser_init+0x1a0>
    2d2c:	e8 4f e3 ff ff       	call   1080 <__stack_chk_fail@plt>
    2d31:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
    2d35:	c9                   	leave
    2d36:	c3                   	ret

0000000000002d37 <Parser_advance>:
    2d37:	55                   	push   %rbp
    2d38:	48 89 e5             	mov    %rsp,%rbp
    2d3b:	53                   	push   %rbx
    2d3c:	48 83 ec 68          	sub    $0x68,%rsp
    2d40:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
    2d44:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    2d4b:	00 00 
    2d4d:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    2d51:	31 c0                	xor    %eax,%eax
    2d53:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    2d57:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    2d5b:	48 8b 4a 40          	mov    0x40(%rdx),%rcx
    2d5f:	48 8b 5a 48          	mov    0x48(%rdx),%rbx
    2d63:	48 89 48 08          	mov    %rcx,0x8(%rax)
    2d67:	48 89 58 10          	mov    %rbx,0x10(%rax)
    2d6b:	48 8b 4a 50          	mov    0x50(%rdx),%rcx
    2d6f:	48 8b 5a 58          	mov    0x58(%rdx),%rbx
    2d73:	48 89 48 18          	mov    %rcx,0x18(%rax)
    2d77:	48 89 58 20          	mov    %rbx,0x20(%rax)
    2d7b:	48 8b 4a 60          	mov    0x60(%rdx),%rcx
    2d7f:	48 8b 5a 68          	mov    0x68(%rdx),%rbx
    2d83:	48 89 48 28          	mov    %rcx,0x28(%rax)
    2d87:	48 89 58 30          	mov    %rbx,0x30(%rax)
    2d8b:	48 8b 52 70          	mov    0x70(%rdx),%rdx
    2d8f:	48 89 50 38          	mov    %rdx,0x38(%rax)
    2d93:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    2d97:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    2d9b:	48 8b 4a 78          	mov    0x78(%rdx),%rcx
    2d9f:	48 8b 9a 80 00 00 00 	mov    0x80(%rdx),%rbx
    2da6:	48 89 48 40          	mov    %rcx,0x40(%rax)
    2daa:	48 89 58 48          	mov    %rbx,0x48(%rax)
    2dae:	48 8b 8a 88 00 00 00 	mov    0x88(%rdx),%rcx
    2db5:	48 8b 9a 90 00 00 00 	mov    0x90(%rdx),%rbx
    2dbc:	48 89 48 50          	mov    %rcx,0x50(%rax)
    2dc0:	48 89 58 58          	mov    %rbx,0x58(%rax)
    2dc4:	48 8b 8a 98 00 00 00 	mov    0x98(%rdx),%rcx
    2dcb:	48 8b 9a a0 00 00 00 	mov    0xa0(%rdx),%rbx
    2dd2:	48 89 48 60          	mov    %rcx,0x60(%rax)
    2dd6:	48 89 58 68          	mov    %rbx,0x68(%rax)
    2dda:	48 8b 92 a8 00 00 00 	mov    0xa8(%rdx),%rdx
    2de1:	48 89 50 70          	mov    %rdx,0x70(%rax)
    2de5:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    2de9:	48 8b 10             	mov    (%rax),%rdx
    2dec:	48 8b 5d d8          	mov    -0x28(%rbp),%rbx
    2df0:	48 8d 45 90          	lea    -0x70(%rbp),%rax
    2df4:	48 89 d6             	mov    %rdx,%rsi
    2df7:	48 89 c7             	mov    %rax,%rdi
    2dfa:	e8 b5 e8 ff ff       	call   16b4 <Lexer_next>
    2dff:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    2e03:	48 8b 55 98          	mov    -0x68(%rbp),%rdx
    2e07:	48 89 43 78          	mov    %rax,0x78(%rbx)
    2e0b:	48 89 93 80 00 00 00 	mov    %rdx,0x80(%rbx)
    2e12:	48 8b 45 a0          	mov    -0x60(%rbp),%rax
    2e16:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
    2e1a:	48 89 83 88 00 00 00 	mov    %rax,0x88(%rbx)
    2e21:	48 89 93 90 00 00 00 	mov    %rdx,0x90(%rbx)
    2e28:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    2e2c:	48 8b 55 b8          	mov    -0x48(%rbp),%rdx
    2e30:	48 89 83 98 00 00 00 	mov    %rax,0x98(%rbx)
    2e37:	48 89 93 a0 00 00 00 	mov    %rdx,0xa0(%rbx)
    2e3e:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
    2e42:	48 89 83 a8 00 00 00 	mov    %rax,0xa8(%rbx)
    2e49:	90                   	nop
    2e4a:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    2e4e:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    2e55:	00 00 
    2e57:	74 05                	je     2e5e <Parser_advance+0x127>
    2e59:	e8 22 e2 ff ff       	call   1080 <__stack_chk_fail@plt>
    2e5e:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
    2e62:	c9                   	leave
    2e63:	c3                   	ret

0000000000002e64 <Parser_check>:
    2e64:	55                   	push   %rbp
    2e65:	48 89 e5             	mov    %rsp,%rbp
    2e68:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    2e6c:	89 75 f4             	mov    %esi,-0xc(%rbp)
    2e6f:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2e73:	8b 40 40             	mov    0x40(%rax),%eax
    2e76:	39 45 f4             	cmp    %eax,-0xc(%rbp)
    2e79:	0f 94 c0             	sete   %al
    2e7c:	5d                   	pop    %rbp
    2e7d:	c3                   	ret

0000000000002e7e <Parser_checkNext>:
    2e7e:	55                   	push   %rbp
    2e7f:	48 89 e5             	mov    %rsp,%rbp
    2e82:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    2e86:	89 75 f4             	mov    %esi,-0xc(%rbp)
    2e89:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2e8d:	8b 40 78             	mov    0x78(%rax),%eax
    2e90:	39 45 f4             	cmp    %eax,-0xc(%rbp)
    2e93:	0f 94 c0             	sete   %al
    2e96:	5d                   	pop    %rbp
    2e97:	c3                   	ret

0000000000002e98 <Parser_match>:
    2e98:	55                   	push   %rbp
    2e99:	48 89 e5             	mov    %rsp,%rbp
    2e9c:	48 83 ec 10          	sub    $0x10,%rsp
    2ea0:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    2ea4:	89 75 f4             	mov    %esi,-0xc(%rbp)
    2ea7:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2eab:	8b 40 40             	mov    0x40(%rax),%eax
    2eae:	39 45 f4             	cmp    %eax,-0xc(%rbp)
    2eb1:	74 07                	je     2eba <Parser_match+0x22>
    2eb3:	b8 00 00 00 00       	mov    $0x0,%eax
    2eb8:	eb 11                	jmp    2ecb <Parser_match+0x33>
    2eba:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2ebe:	48 89 c7             	mov    %rax,%rdi
    2ec1:	e8 71 fe ff ff       	call   2d37 <Parser_advance>
    2ec6:	b8 01 00 00 00       	mov    $0x1,%eax
    2ecb:	c9                   	leave
    2ecc:	c3                   	ret

0000000000002ecd <Parser_errorAt>:
    2ecd:	55                   	push   %rbp
    2ece:	48 89 e5             	mov    %rsp,%rbp
    2ed1:	48 83 ec 10          	sub    $0x10,%rsp
    2ed5:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    2ed9:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    2edd:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2ee1:	8b 80 b8 00 00 00    	mov    0xb8(%rax),%eax
    2ee7:	8d 50 01             	lea    0x1(%rax),%edx
    2eea:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    2eee:	89 90 b8 00 00 00    	mov    %edx,0xb8(%rax)
    2ef4:	48 8b 55 30          	mov    0x30(%rbp),%rdx
    2ef8:	48 8b 45 28          	mov    0x28(%rbp),%rax
    2efc:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
    2f00:	48 8d 3d c5 71 00 00 	lea    0x71c5(%rip),%rdi        # a0cc <_IO_stdin_used+0xcc>
    2f07:	48 89 c6             	mov    %rax,%rsi
    2f0a:	b8 00 00 00 00       	mov    $0x0,%eax
    2f0f:	e8 7c e1 ff ff       	call   1090 <printf@plt>
    2f14:	90                   	nop
    2f15:	c9                   	leave
    2f16:	c3                   	ret

0000000000002f17 <Parser_expect>:
    2f17:	55                   	push   %rbp
    2f18:	48 89 e5             	mov    %rsp,%rbp
    2f1b:	53                   	push   %rbx
    2f1c:	48 83 ec 28          	sub    $0x28,%rsp
    2f20:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    2f24:	89 75 e4             	mov    %esi,-0x1c(%rbp)
    2f27:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    2f2b:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    2f2f:	8b 40 40             	mov    0x40(%rax),%eax
    2f32:	39 45 e4             	cmp    %eax,-0x1c(%rbp)
    2f35:	74 59                	je     2f90 <Parser_expect+0x79>
    2f37:	48 8b 75 d8          	mov    -0x28(%rbp),%rsi
    2f3b:	48 8b 7d e8          	mov    -0x18(%rbp),%rdi
    2f3f:	48 83 ec 08          	sub    $0x8,%rsp
    2f43:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    2f47:	48 83 ec 38          	sub    $0x38,%rsp
    2f4b:	48 89 e2             	mov    %rsp,%rdx
    2f4e:	48 8b 48 40          	mov    0x40(%rax),%rcx
    2f52:	48 8b 58 48          	mov    0x48(%rax),%rbx
    2f56:	48 89 0a             	mov    %rcx,(%rdx)
    2f59:	48 89 5a 08          	mov    %rbx,0x8(%rdx)
    2f5d:	48 8b 48 50          	mov    0x50(%rax),%rcx
    2f61:	48 8b 58 58          	mov    0x58(%rax),%rbx
    2f65:	48 89 4a 10          	mov    %rcx,0x10(%rdx)
    2f69:	48 89 5a 18          	mov    %rbx,0x18(%rdx)
    2f6d:	48 8b 48 60          	mov    0x60(%rax),%rcx
    2f71:	48 8b 58 68          	mov    0x68(%rax),%rbx
    2f75:	48 89 4a 20          	mov    %rcx,0x20(%rdx)
    2f79:	48 89 5a 28          	mov    %rbx,0x28(%rdx)
    2f7d:	48 8b 40 70          	mov    0x70(%rax),%rax
    2f81:	48 89 42 30          	mov    %rax,0x30(%rdx)
    2f85:	e8 43 ff ff ff       	call   2ecd <Parser_errorAt>
    2f8a:	48 83 c4 40          	add    $0x40,%rsp
    2f8e:	eb 0c                	jmp    2f9c <Parser_expect+0x85>
    2f90:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    2f94:	48 89 c7             	mov    %rax,%rdi
    2f97:	e8 9b fd ff ff       	call   2d37 <Parser_advance>
    2f9c:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
    2fa0:	c9                   	leave
    2fa1:	c3                   	ret

0000000000002fa2 <Parser_isWord>:
    2fa2:	55                   	push   %rbp
    2fa3:	48 89 e5             	mov    %rsp,%rbp
    2fa6:	48 83 ec 40          	sub    $0x40,%rsp
    2faa:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
    2fae:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
    2fb2:	48 89 55 c8          	mov    %rdx,-0x38(%rbp)
    2fb6:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    2fbd:	00 00 
    2fbf:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    2fc3:	31 c0                	xor    %eax,%eax
    2fc5:	8b 45 10             	mov    0x10(%rbp),%eax
    2fc8:	83 f8 01             	cmp    $0x1,%eax
    2fcb:	74 07                	je     2fd4 <Parser_isWord+0x32>
    2fcd:	b8 00 00 00 00       	mov    $0x0,%eax
    2fd2:	eb 35                	jmp    3009 <Parser_isWord+0x67>
    2fd4:	48 8b 45 18          	mov    0x18(%rbp),%rax
    2fd8:	48 8b 55 20          	mov    0x20(%rbp),%rdx
    2fdc:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    2fe0:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
    2fe4:	48 8b 55 c8          	mov    -0x38(%rbp),%rdx
    2fe8:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    2fec:	48 89 d6             	mov    %rdx,%rsi
    2fef:	48 89 c7             	mov    %rax,%rdi
    2ff2:	e8 b1 f1 ff ff       	call   21a8 <mkSlice>
    2ff7:	48 89 c1             	mov    %rax,%rcx
    2ffa:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    2ffe:	48 89 ce             	mov    %rcx,%rsi
    3001:	48 89 c7             	mov    %rax,%rdi
    3004:	e8 94 e4 ff ff       	call   149d <Slice_eq>
    3009:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
    300d:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
    3014:	00 00 
    3016:	74 05                	je     301d <Parser_isWord+0x7b>
    3018:	e8 63 e0 ff ff       	call   1080 <__stack_chk_fail@plt>
    301d:	c9                   	leave
    301e:	c3                   	ret

000000000000301f <Parser_curIsWord>:
    301f:	55                   	push   %rbp
    3020:	48 89 e5             	mov    %rsp,%rbp
    3023:	53                   	push   %rbx
    3024:	48 83 ec 28          	sub    $0x28,%rsp
    3028:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    302c:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    3030:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    3034:	4c 8b 45 d8          	mov    -0x28(%rbp),%r8
    3038:	48 8b 75 e0          	mov    -0x20(%rbp),%rsi
    303c:	48 8b 7d e8          	mov    -0x18(%rbp),%rdi
    3040:	48 83 ec 08          	sub    $0x8,%rsp
    3044:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    3048:	48 83 ec 38          	sub    $0x38,%rsp
    304c:	48 89 e2             	mov    %rsp,%rdx
    304f:	48 8b 48 40          	mov    0x40(%rax),%rcx
    3053:	48 8b 58 48          	mov    0x48(%rax),%rbx
    3057:	48 89 0a             	mov    %rcx,(%rdx)
    305a:	48 89 5a 08          	mov    %rbx,0x8(%rdx)
    305e:	48 8b 48 50          	mov    0x50(%rax),%rcx
    3062:	48 8b 58 58          	mov    0x58(%rax),%rbx
    3066:	48 89 4a 10          	mov    %rcx,0x10(%rdx)
    306a:	48 89 5a 18          	mov    %rbx,0x18(%rdx)
    306e:	48 8b 48 60          	mov    0x60(%rax),%rcx
    3072:	48 8b 58 68          	mov    0x68(%rax),%rbx
    3076:	48 89 4a 20          	mov    %rcx,0x20(%rdx)
    307a:	48 89 5a 28          	mov    %rbx,0x28(%rdx)
    307e:	48 8b 40 70          	mov    0x70(%rax),%rax
    3082:	48 89 42 30          	mov    %rax,0x30(%rdx)
    3086:	4c 89 c2             	mov    %r8,%rdx
    3089:	e8 14 ff ff ff       	call   2fa2 <Parser_isWord>
    308e:	48 83 c4 40          	add    $0x40,%rsp
    3092:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
    3096:	c9                   	leave
    3097:	c3                   	ret

0000000000003098 <Parser_parseValue>:
    3098:	55                   	push   %rbp
    3099:	48 89 e5             	mov    %rsp,%rbp
    309c:	53                   	push   %rbx
    309d:	48 83 ec 48          	sub    $0x48,%rsp
    30a1:	48 89 7d b8          	mov    %rdi,-0x48(%rbp)
    30a5:	48 89 75 b0          	mov    %rsi,-0x50(%rbp)
    30a9:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    30b0:	00 00 
    30b2:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    30b6:	31 c0                	xor    %eax,%eax
    30b8:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    30bc:	8b 40 40             	mov    0x40(%rax),%eax
    30bf:	83 f8 07             	cmp    $0x7,%eax
    30c2:	0f 84 ee 00 00 00    	je     31b6 <Parser_parseValue+0x11e>
    30c8:	83 f8 07             	cmp    $0x7,%eax
    30cb:	0f 87 37 02 00 00    	ja     3308 <Parser_parseValue+0x270>
    30d1:	83 f8 04             	cmp    $0x4,%eax
    30d4:	0f 84 9e 00 00 00    	je     3178 <Parser_parseValue+0xe0>
    30da:	83 f8 04             	cmp    $0x4,%eax
    30dd:	0f 87 25 02 00 00    	ja     3308 <Parser_parseValue+0x270>
    30e3:	83 f8 02             	cmp    $0x2,%eax
    30e6:	74 0a                	je     30f2 <Parser_parseValue+0x5a>
    30e8:	83 f8 03             	cmp    $0x3,%eax
    30eb:	74 4c                	je     3139 <Parser_parseValue+0xa1>
    30ed:	e9 16 02 00 00       	jmp    3308 <Parser_parseValue+0x270>
    30f2:	c7 45 d0 00 00 00 00 	movl   $0x0,-0x30(%rbp)
    30f9:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    30fd:	48 8b 50 50          	mov    0x50(%rax),%rdx
    3101:	48 8b 40 48          	mov    0x48(%rax),%rax
    3105:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
    3109:	48 89 55 e0          	mov    %rdx,-0x20(%rbp)
    310d:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    3111:	48 89 c7             	mov    %rax,%rdi
    3114:	e8 1e fc ff ff       	call   2d37 <Parser_advance>
    3119:	48 8b 4d b8          	mov    -0x48(%rbp),%rcx
    311d:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    3121:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    3125:	48 89 01             	mov    %rax,(%rcx)
    3128:	48 89 51 08          	mov    %rdx,0x8(%rcx)
    312c:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    3130:	48 89 41 10          	mov    %rax,0x10(%rcx)
    3134:	e9 5f 02 00 00       	jmp    3398 <Parser_parseValue+0x300>
    3139:	c7 45 d0 01 00 00 00 	movl   $0x1,-0x30(%rbp)
    3140:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    3144:	48 8b 40 68          	mov    0x68(%rax),%rax
    3148:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
    314c:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    3150:	48 89 c7             	mov    %rax,%rdi
    3153:	e8 df fb ff ff       	call   2d37 <Parser_advance>
    3158:	48 8b 4d b8          	mov    -0x48(%rbp),%rcx
    315c:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    3160:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    3164:	48 89 01             	mov    %rax,(%rcx)
    3167:	48 89 51 08          	mov    %rdx,0x8(%rcx)
    316b:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    316f:	48 89 41 10          	mov    %rax,0x10(%rcx)
    3173:	e9 20 02 00 00       	jmp    3398 <Parser_parseValue+0x300>
    3178:	c7 45 d0 02 00 00 00 	movl   $0x2,-0x30(%rbp)
    317f:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    3183:	0f b6 40 70          	movzbl 0x70(%rax),%eax
    3187:	88 45 d8             	mov    %al,-0x28(%rbp)
    318a:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    318e:	48 89 c7             	mov    %rax,%rdi
    3191:	e8 a1 fb ff ff       	call   2d37 <Parser_advance>
    3196:	48 8b 4d b8          	mov    -0x48(%rbp),%rcx
    319a:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    319e:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    31a2:	48 89 01             	mov    %rax,(%rcx)
    31a5:	48 89 51 08          	mov    %rdx,0x8(%rcx)
    31a9:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    31ad:	48 89 41 10          	mov    %rax,0x10(%rcx)
    31b1:	e9 e2 01 00 00       	jmp    3398 <Parser_parseValue+0x300>
    31b6:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    31ba:	48 89 c7             	mov    %rax,%rdi
    31bd:	e8 75 fb ff ff       	call   2d37 <Parser_advance>
    31c2:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    31c6:	48 8b 80 b0 00 00 00 	mov    0xb0(%rax),%rax
    31cd:	ba 08 00 00 00       	mov    $0x8,%edx
    31d2:	be 20 00 00 00       	mov    $0x20,%esi
    31d7:	48 89 c7             	mov    %rax,%rdi
    31da:	e8 f2 e0 ff ff       	call   12d1 <Arena_alloc>
    31df:	48 89 45 c8          	mov    %rax,-0x38(%rbp)
    31e3:	48 83 7d c8 00       	cmpq   $0x0,-0x38(%rbp)
    31e8:	0f 84 9c 00 00 00    	je     328a <Parser_parseValue+0x1f2>
    31ee:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    31f2:	48 c7 00 00 00 00 00 	movq   $0x0,(%rax)
    31f9:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    31fd:	48 c7 40 08 00 00 00 	movq   $0x0,0x8(%rax)
    3204:	00 
    3205:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    3209:	48 c7 40 10 00 00 00 	movq   $0x0,0x10(%rax)
    3210:	00 
    3211:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    3215:	48 8b 90 b0 00 00 00 	mov    0xb0(%rax),%rdx
    321c:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    3220:	48 89 50 18          	mov    %rdx,0x18(%rax)
    3224:	eb 64                	jmp    328a <Parser_parseValue+0x1f2>
    3226:	48 8d 45 d0          	lea    -0x30(%rbp),%rax
    322a:	48 8b 55 b0          	mov    -0x50(%rbp),%rdx
    322e:	48 89 d6             	mov    %rdx,%rsi
    3231:	48 89 c7             	mov    %rax,%rdi
    3234:	e8 5f fe ff ff       	call   3098 <Parser_parseValue>
    3239:	48 83 7d c8 00       	cmpq   $0x0,-0x38(%rbp)
    323e:	74 32                	je     3272 <Parser_parseValue+0x1da>
    3240:	48 8b 75 c8          	mov    -0x38(%rbp),%rsi
    3244:	48 83 ec 08          	sub    $0x8,%rsp
    3248:	48 83 ec 18          	sub    $0x18,%rsp
    324c:	48 89 e1             	mov    %rsp,%rcx
    324f:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    3253:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    3257:	48 89 01             	mov    %rax,(%rcx)
    325a:	48 89 51 08          	mov    %rdx,0x8(%rcx)
    325e:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    3262:	48 89 41 10          	mov    %rax,0x10(%rcx)
    3266:	48 89 f7             	mov    %rsi,%rdi
    3269:	e8 ce f7 ff ff       	call   2a3c <valueArrayPush>
    326e:	48 83 c4 20          	add    $0x20,%rsp
    3272:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    3276:	be 0b 00 00 00       	mov    $0xb,%esi
    327b:	48 89 c7             	mov    %rax,%rdi
    327e:	e8 15 fc ff ff       	call   2e98 <Parser_match>
    3283:	83 f0 01             	xor    $0x1,%eax
    3286:	84 c0                	test   %al,%al
    3288:	75 36                	jne    32c0 <Parser_parseValue+0x228>
    328a:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    328e:	be 08 00 00 00       	mov    $0x8,%esi
    3293:	48 89 c7             	mov    %rax,%rdi
    3296:	e8 c9 fb ff ff       	call   2e64 <Parser_check>
    329b:	83 f0 01             	xor    $0x1,%eax
    329e:	84 c0                	test   %al,%al
    32a0:	74 1f                	je     32c1 <Parser_parseValue+0x229>
    32a2:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    32a6:	be 00 00 00 00       	mov    $0x0,%esi
    32ab:	48 89 c7             	mov    %rax,%rdi
    32ae:	e8 b1 fb ff ff       	call   2e64 <Parser_check>
    32b3:	83 f0 01             	xor    $0x1,%eax
    32b6:	84 c0                	test   %al,%al
    32b8:	0f 85 68 ff ff ff    	jne    3226 <Parser_parseValue+0x18e>
    32be:	eb 01                	jmp    32c1 <Parser_parseValue+0x229>
    32c0:	90                   	nop
    32c1:	48 8d 15 20 6e 00 00 	lea    0x6e20(%rip),%rdx        # a0e8 <_IO_stdin_used+0xe8>
    32c8:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    32cc:	be 08 00 00 00       	mov    $0x8,%esi
    32d1:	48 89 c7             	mov    %rax,%rdi
    32d4:	e8 3e fc ff ff       	call   2f17 <Parser_expect>
    32d9:	c7 45 d0 03 00 00 00 	movl   $0x3,-0x30(%rbp)
    32e0:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    32e4:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
    32e8:	48 8b 4d b8          	mov    -0x48(%rbp),%rcx
    32ec:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    32f0:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    32f4:	48 89 01             	mov    %rax,(%rcx)
    32f7:	48 89 51 08          	mov    %rdx,0x8(%rcx)
    32fb:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    32ff:	48 89 41 10          	mov    %rax,0x10(%rcx)
    3303:	e9 90 00 00 00       	jmp    3398 <Parser_parseValue+0x300>
    3308:	48 8d 35 f2 6d 00 00 	lea    0x6df2(%rip),%rsi        # a101 <_IO_stdin_used+0x101>
    330f:	48 8b 7d b0          	mov    -0x50(%rbp),%rdi
    3313:	48 83 ec 08          	sub    $0x8,%rsp
    3317:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    331b:	48 83 ec 38          	sub    $0x38,%rsp
    331f:	48 89 e2             	mov    %rsp,%rdx
    3322:	48 8b 48 40          	mov    0x40(%rax),%rcx
    3326:	48 8b 58 48          	mov    0x48(%rax),%rbx
    332a:	48 89 0a             	mov    %rcx,(%rdx)
    332d:	48 89 5a 08          	mov    %rbx,0x8(%rdx)
    3331:	48 8b 48 50          	mov    0x50(%rax),%rcx
    3335:	48 8b 58 58          	mov    0x58(%rax),%rbx
    3339:	48 89 4a 10          	mov    %rcx,0x10(%rdx)
    333d:	48 89 5a 18          	mov    %rbx,0x18(%rdx)
    3341:	48 8b 48 60          	mov    0x60(%rax),%rcx
    3345:	48 8b 58 68          	mov    0x68(%rax),%rbx
    3349:	48 89 4a 20          	mov    %rcx,0x20(%rdx)
    334d:	48 89 5a 28          	mov    %rbx,0x28(%rdx)
    3351:	48 8b 40 70          	mov    0x70(%rax),%rax
    3355:	48 89 42 30          	mov    %rax,0x30(%rdx)
    3359:	e8 6f fb ff ff       	call   2ecd <Parser_errorAt>
    335e:	48 83 c4 40          	add    $0x40,%rsp
    3362:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    3366:	48 89 c7             	mov    %rax,%rdi
    3369:	e8 c9 f9 ff ff       	call   2d37 <Parser_advance>
    336e:	c7 45 d0 01 00 00 00 	movl   $0x1,-0x30(%rbp)
    3375:	48 c7 45 d8 00 00 00 	movq   $0x0,-0x28(%rbp)
    337c:	00 
    337d:	48 8b 4d b8          	mov    -0x48(%rbp),%rcx
    3381:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    3385:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    3389:	48 89 01             	mov    %rax,(%rcx)
    338c:	48 89 51 08          	mov    %rdx,0x8(%rcx)
    3390:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    3394:	48 89 41 10          	mov    %rax,0x10(%rcx)
    3398:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    339c:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    33a3:	00 00 
    33a5:	74 05                	je     33ac <Parser_parseValue+0x314>
    33a7:	e8 d4 dc ff ff       	call   1080 <__stack_chk_fail@plt>
    33ac:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    33b0:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
    33b4:	c9                   	leave
    33b5:	c3                   	ret

00000000000033b6 <Parser_childKind>:
    33b6:	55                   	push   %rbp
    33b7:	48 89 e5             	mov    %rsp,%rbp
    33ba:	48 83 ec 20          	sub    $0x20,%rsp
    33be:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    33c2:	48 89 f0             	mov    %rsi,%rax
    33c5:	48 89 d6             	mov    %rdx,%rsi
    33c8:	48 89 c0             	mov    %rax,%rax
    33cb:	ba 00 00 00 00       	mov    $0x0,%edx
    33d0:	48 89 f2             	mov    %rsi,%rdx
    33d3:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    33d7:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
    33db:	48 89 4d f0          	mov    %rcx,-0x10(%rbp)
    33df:	48 8d 05 d0 6c 00 00 	lea    0x6cd0(%rip),%rax        # a0b6 <_IO_stdin_used+0xb6>
    33e6:	be 08 00 00 00       	mov    $0x8,%esi
    33eb:	48 89 c7             	mov    %rax,%rdi
    33ee:	e8 b5 ed ff ff       	call   21a8 <mkSlice>
    33f3:	48 89 c1             	mov    %rax,%rcx
    33f6:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    33fa:	48 89 ce             	mov    %rcx,%rsi
    33fd:	48 89 c7             	mov    %rax,%rdi
    3400:	e8 98 e0 ff ff       	call   149d <Slice_eq>
    3405:	84 c0                	test   %al,%al
    3407:	74 14                	je     341d <Parser_childKind+0x67>
    3409:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    340d:	c7 00 1a 00 00 00    	movl   $0x1a,(%rax)
    3413:	b8 01 00 00 00       	mov    $0x1,%eax
    3418:	e9 cc 05 00 00       	jmp    39e9 <Parser_childKind+0x633>
    341d:	48 8d 05 3b 6c 00 00 	lea    0x6c3b(%rip),%rax        # a05f <_IO_stdin_used+0x5f>
    3424:	be 06 00 00 00       	mov    $0x6,%esi
    3429:	48 89 c7             	mov    %rax,%rdi
    342c:	e8 77 ed ff ff       	call   21a8 <mkSlice>
    3431:	48 89 c1             	mov    %rax,%rcx
    3434:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    3438:	48 89 ce             	mov    %rcx,%rsi
    343b:	48 89 c7             	mov    %rax,%rdi
    343e:	e8 5a e0 ff ff       	call   149d <Slice_eq>
    3443:	84 c0                	test   %al,%al
    3445:	74 14                	je     345b <Parser_childKind+0xa5>
    3447:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    344b:	c7 00 0c 00 00 00    	movl   $0xc,(%rax)
    3451:	b8 01 00 00 00       	mov    $0x1,%eax
    3456:	e9 8e 05 00 00       	jmp    39e9 <Parser_childKind+0x633>
    345b:	48 8d 05 04 6c 00 00 	lea    0x6c04(%rip),%rax        # a066 <_IO_stdin_used+0x66>
    3462:	be 04 00 00 00       	mov    $0x4,%esi
    3467:	48 89 c7             	mov    %rax,%rdi
    346a:	e8 39 ed ff ff       	call   21a8 <mkSlice>
    346f:	48 89 c1             	mov    %rax,%rcx
    3472:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    3476:	48 89 ce             	mov    %rcx,%rsi
    3479:	48 89 c7             	mov    %rax,%rdi
    347c:	e8 1c e0 ff ff       	call   149d <Slice_eq>
    3481:	84 c0                	test   %al,%al
    3483:	74 14                	je     3499 <Parser_childKind+0xe3>
    3485:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    3489:	c7 00 0d 00 00 00    	movl   $0xd,(%rax)
    348f:	b8 01 00 00 00       	mov    $0x1,%eax
    3494:	e9 50 05 00 00       	jmp    39e9 <Parser_childKind+0x633>
    3499:	48 8d 05 cb 6b 00 00 	lea    0x6bcb(%rip),%rax        # a06b <_IO_stdin_used+0x6b>
    34a0:	be 08 00 00 00       	mov    $0x8,%esi
    34a5:	48 89 c7             	mov    %rax,%rdi
    34a8:	e8 fb ec ff ff       	call   21a8 <mkSlice>
    34ad:	48 89 c1             	mov    %rax,%rcx
    34b0:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    34b4:	48 89 ce             	mov    %rcx,%rsi
    34b7:	48 89 c7             	mov    %rax,%rdi
    34ba:	e8 de df ff ff       	call   149d <Slice_eq>
    34bf:	84 c0                	test   %al,%al
    34c1:	74 14                	je     34d7 <Parser_childKind+0x121>
    34c3:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    34c7:	c7 00 0e 00 00 00    	movl   $0xe,(%rax)
    34cd:	b8 01 00 00 00       	mov    $0x1,%eax
    34d2:	e9 12 05 00 00       	jmp    39e9 <Parser_childKind+0x633>
    34d7:	48 8d 05 96 6b 00 00 	lea    0x6b96(%rip),%rax        # a074 <_IO_stdin_used+0x74>
    34de:	be 08 00 00 00       	mov    $0x8,%esi
    34e3:	48 89 c7             	mov    %rax,%rdi
    34e6:	e8 bd ec ff ff       	call   21a8 <mkSlice>
    34eb:	48 89 c1             	mov    %rax,%rcx
    34ee:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    34f2:	48 89 ce             	mov    %rcx,%rsi
    34f5:	48 89 c7             	mov    %rax,%rdi
    34f8:	e8 a0 df ff ff       	call   149d <Slice_eq>
    34fd:	84 c0                	test   %al,%al
    34ff:	74 14                	je     3515 <Parser_childKind+0x15f>
    3501:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    3505:	c7 00 0f 00 00 00    	movl   $0xf,(%rax)
    350b:	b8 01 00 00 00       	mov    $0x1,%eax
    3510:	e9 d4 04 00 00       	jmp    39e9 <Parser_childKind+0x633>
    3515:	48 8d 05 61 6b 00 00 	lea    0x6b61(%rip),%rax        # a07d <_IO_stdin_used+0x7d>
    351c:	be 03 00 00 00       	mov    $0x3,%esi
    3521:	48 89 c7             	mov    %rax,%rdi
    3524:	e8 7f ec ff ff       	call   21a8 <mkSlice>
    3529:	48 89 c1             	mov    %rax,%rcx
    352c:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    3530:	48 89 ce             	mov    %rcx,%rsi
    3533:	48 89 c7             	mov    %rax,%rdi
    3536:	e8 62 df ff ff       	call   149d <Slice_eq>
    353b:	84 c0                	test   %al,%al
    353d:	74 14                	je     3553 <Parser_childKind+0x19d>
    353f:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    3543:	c7 00 10 00 00 00    	movl   $0x10,(%rax)
    3549:	b8 01 00 00 00       	mov    $0x1,%eax
    354e:	e9 96 04 00 00       	jmp    39e9 <Parser_childKind+0x633>
    3553:	48 8d 05 27 6b 00 00 	lea    0x6b27(%rip),%rax        # a081 <_IO_stdin_used+0x81>
    355a:	be 03 00 00 00       	mov    $0x3,%esi
    355f:	48 89 c7             	mov    %rax,%rdi
    3562:	e8 41 ec ff ff       	call   21a8 <mkSlice>
    3567:	48 89 c1             	mov    %rax,%rcx
    356a:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    356e:	48 89 ce             	mov    %rcx,%rsi
    3571:	48 89 c7             	mov    %rax,%rdi
    3574:	e8 24 df ff ff       	call   149d <Slice_eq>
    3579:	84 c0                	test   %al,%al
    357b:	74 14                	je     3591 <Parser_childKind+0x1db>
    357d:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    3581:	c7 00 11 00 00 00    	movl   $0x11,(%rax)
    3587:	b8 01 00 00 00       	mov    $0x1,%eax
    358c:	e9 58 04 00 00       	jmp    39e9 <Parser_childKind+0x633>
    3591:	48 8d 05 ed 6a 00 00 	lea    0x6aed(%rip),%rax        # a085 <_IO_stdin_used+0x85>
    3598:	be 07 00 00 00       	mov    $0x7,%esi
    359d:	48 89 c7             	mov    %rax,%rdi
    35a0:	e8 03 ec ff ff       	call   21a8 <mkSlice>
    35a5:	48 89 c1             	mov    %rax,%rcx
    35a8:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    35ac:	48 89 ce             	mov    %rcx,%rsi
    35af:	48 89 c7             	mov    %rax,%rdi
    35b2:	e8 e6 de ff ff       	call   149d <Slice_eq>
    35b7:	84 c0                	test   %al,%al
    35b9:	74 14                	je     35cf <Parser_childKind+0x219>
    35bb:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    35bf:	c7 00 12 00 00 00    	movl   $0x12,(%rax)
    35c5:	b8 01 00 00 00       	mov    $0x1,%eax
    35ca:	e9 1a 04 00 00       	jmp    39e9 <Parser_childKind+0x633>
    35cf:	48 8d 05 73 6a 00 00 	lea    0x6a73(%rip),%rax        # a049 <_IO_stdin_used+0x49>
    35d6:	be 04 00 00 00       	mov    $0x4,%esi
    35db:	48 89 c7             	mov    %rax,%rdi
    35de:	e8 c5 eb ff ff       	call   21a8 <mkSlice>
    35e3:	48 89 c1             	mov    %rax,%rcx
    35e6:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    35ea:	48 89 ce             	mov    %rcx,%rsi
    35ed:	48 89 c7             	mov    %rax,%rdi
    35f0:	e8 a8 de ff ff       	call   149d <Slice_eq>
    35f5:	84 c0                	test   %al,%al
    35f7:	74 14                	je     360d <Parser_childKind+0x257>
    35f9:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    35fd:	c7 00 08 00 00 00    	movl   $0x8,(%rax)
    3603:	b8 01 00 00 00       	mov    $0x1,%eax
    3608:	e9 dc 03 00 00       	jmp    39e9 <Parser_childKind+0x633>
    360d:	48 8d 05 3a 6a 00 00 	lea    0x6a3a(%rip),%rax        # a04e <_IO_stdin_used+0x4e>
    3614:	be 05 00 00 00       	mov    $0x5,%esi
    3619:	48 89 c7             	mov    %rax,%rdi
    361c:	e8 87 eb ff ff       	call   21a8 <mkSlice>
    3621:	48 89 c1             	mov    %rax,%rcx
    3624:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    3628:	48 89 ce             	mov    %rcx,%rsi
    362b:	48 89 c7             	mov    %rax,%rdi
    362e:	e8 6a de ff ff       	call   149d <Slice_eq>
    3633:	84 c0                	test   %al,%al
    3635:	74 14                	je     364b <Parser_childKind+0x295>
    3637:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    363b:	c7 00 09 00 00 00    	movl   $0x9,(%rax)
    3641:	b8 01 00 00 00       	mov    $0x1,%eax
    3646:	e9 9e 03 00 00       	jmp    39e9 <Parser_childKind+0x633>
    364b:	48 8d 05 02 6a 00 00 	lea    0x6a02(%rip),%rax        # a054 <_IO_stdin_used+0x54>
    3652:	be 04 00 00 00       	mov    $0x4,%esi
    3657:	48 89 c7             	mov    %rax,%rdi
    365a:	e8 49 eb ff ff       	call   21a8 <mkSlice>
    365f:	48 89 c1             	mov    %rax,%rcx
    3662:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    3666:	48 89 ce             	mov    %rcx,%rsi
    3669:	48 89 c7             	mov    %rax,%rdi
    366c:	e8 2c de ff ff       	call   149d <Slice_eq>
    3671:	84 c0                	test   %al,%al
    3673:	74 14                	je     3689 <Parser_childKind+0x2d3>
    3675:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    3679:	c7 00 0a 00 00 00    	movl   $0xa,(%rax)
    367f:	b8 01 00 00 00       	mov    $0x1,%eax
    3684:	e9 60 03 00 00       	jmp    39e9 <Parser_childKind+0x633>
    3689:	48 8d 05 c9 69 00 00 	lea    0x69c9(%rip),%rax        # a059 <_IO_stdin_used+0x59>
    3690:	be 05 00 00 00       	mov    $0x5,%esi
    3695:	48 89 c7             	mov    %rax,%rdi
    3698:	e8 0b eb ff ff       	call   21a8 <mkSlice>
    369d:	48 89 c1             	mov    %rax,%rcx
    36a0:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    36a4:	48 89 ce             	mov    %rcx,%rsi
    36a7:	48 89 c7             	mov    %rax,%rdi
    36aa:	e8 ee dd ff ff       	call   149d <Slice_eq>
    36af:	84 c0                	test   %al,%al
    36b1:	74 14                	je     36c7 <Parser_childKind+0x311>
    36b3:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    36b7:	c7 00 0b 00 00 00    	movl   $0xb,(%rax)
    36bd:	b8 01 00 00 00       	mov    $0x1,%eax
    36c2:	e9 22 03 00 00       	jmp    39e9 <Parser_childKind+0x633>
    36c7:	48 8d 05 76 69 00 00 	lea    0x6976(%rip),%rax        # a044 <_IO_stdin_used+0x44>
    36ce:	be 04 00 00 00       	mov    $0x4,%esi
    36d3:	48 89 c7             	mov    %rax,%rdi
    36d6:	e8 cd ea ff ff       	call   21a8 <mkSlice>
    36db:	48 89 c1             	mov    %rax,%rcx
    36de:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    36e2:	48 89 ce             	mov    %rcx,%rsi
    36e5:	48 89 c7             	mov    %rax,%rdi
    36e8:	e8 b0 dd ff ff       	call   149d <Slice_eq>
    36ed:	84 c0                	test   %al,%al
    36ef:	74 14                	je     3705 <Parser_childKind+0x34f>
    36f1:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    36f5:	c7 00 07 00 00 00    	movl   $0x7,(%rax)
    36fb:	b8 01 00 00 00       	mov    $0x1,%eax
    3700:	e9 e4 02 00 00       	jmp    39e9 <Parser_childKind+0x633>
    3705:	48 8d 05 2a 69 00 00 	lea    0x692a(%rip),%rax        # a036 <_IO_stdin_used+0x36>
    370c:	be 07 00 00 00       	mov    $0x7,%esi
    3711:	48 89 c7             	mov    %rax,%rdi
    3714:	e8 8f ea ff ff       	call   21a8 <mkSlice>
    3719:	48 89 c1             	mov    %rax,%rcx
    371c:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    3720:	48 89 ce             	mov    %rcx,%rsi
    3723:	48 89 c7             	mov    %rax,%rdi
    3726:	e8 72 dd ff ff       	call   149d <Slice_eq>
    372b:	84 c0                	test   %al,%al
    372d:	74 14                	je     3743 <Parser_childKind+0x38d>
    372f:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    3733:	c7 00 05 00 00 00    	movl   $0x5,(%rax)
    3739:	b8 01 00 00 00       	mov    $0x1,%eax
    373e:	e9 a6 02 00 00       	jmp    39e9 <Parser_childKind+0x633>
    3743:	48 8d 05 e2 68 00 00 	lea    0x68e2(%rip),%rax        # a02c <_IO_stdin_used+0x2c>
    374a:	be 09 00 00 00       	mov    $0x9,%esi
    374f:	48 89 c7             	mov    %rax,%rdi
    3752:	e8 51 ea ff ff       	call   21a8 <mkSlice>
    3757:	48 89 c1             	mov    %rax,%rcx
    375a:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    375e:	48 89 ce             	mov    %rcx,%rsi
    3761:	48 89 c7             	mov    %rax,%rdi
    3764:	e8 34 dd ff ff       	call   149d <Slice_eq>
    3769:	84 c0                	test   %al,%al
    376b:	74 14                	je     3781 <Parser_childKind+0x3cb>
    376d:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    3771:	c7 00 04 00 00 00    	movl   $0x4,(%rax)
    3777:	b8 01 00 00 00       	mov    $0x1,%eax
    377c:	e9 68 02 00 00       	jmp    39e9 <Parser_childKind+0x633>
    3781:	48 8d 05 1f 69 00 00 	lea    0x691f(%rip),%rax        # a0a7 <_IO_stdin_used+0xa7>
    3788:	be 04 00 00 00       	mov    $0x4,%esi
    378d:	48 89 c7             	mov    %rax,%rdi
    3790:	e8 13 ea ff ff       	call   21a8 <mkSlice>
    3795:	48 89 c1             	mov    %rax,%rcx
    3798:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    379c:	48 89 ce             	mov    %rcx,%rsi
    379f:	48 89 c7             	mov    %rax,%rdi
    37a2:	e8 f6 dc ff ff       	call   149d <Slice_eq>
    37a7:	84 c0                	test   %al,%al
    37a9:	74 14                	je     37bf <Parser_childKind+0x409>
    37ab:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    37af:	c7 00 18 00 00 00    	movl   $0x18,(%rax)
    37b5:	b8 01 00 00 00       	mov    $0x1,%eax
    37ba:	e9 2a 02 00 00       	jmp    39e9 <Parser_childKind+0x633>
    37bf:	48 8d 05 da 68 00 00 	lea    0x68da(%rip),%rax        # a0a0 <_IO_stdin_used+0xa0>
    37c6:	be 06 00 00 00       	mov    $0x6,%esi
    37cb:	48 89 c7             	mov    %rax,%rdi
    37ce:	e8 d5 e9 ff ff       	call   21a8 <mkSlice>
    37d3:	48 89 c1             	mov    %rax,%rcx
    37d6:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    37da:	48 89 ce             	mov    %rcx,%rsi
    37dd:	48 89 c7             	mov    %rax,%rdi
    37e0:	e8 b8 dc ff ff       	call   149d <Slice_eq>
    37e5:	84 c0                	test   %al,%al
    37e7:	74 14                	je     37fd <Parser_childKind+0x447>
    37e9:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    37ed:	c7 00 17 00 00 00    	movl   $0x17,(%rax)
    37f3:	b8 01 00 00 00       	mov    $0x1,%eax
    37f8:	e9 ec 01 00 00       	jmp    39e9 <Parser_childKind+0x633>
    37fd:	48 8d 05 99 68 00 00 	lea    0x6899(%rip),%rax        # a09d <_IO_stdin_used+0x9d>
    3804:	be 02 00 00 00       	mov    $0x2,%esi
    3809:	48 89 c7             	mov    %rax,%rdi
    380c:	e8 97 e9 ff ff       	call   21a8 <mkSlice>
    3811:	48 89 c1             	mov    %rax,%rcx
    3814:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    3818:	48 89 ce             	mov    %rcx,%rsi
    381b:	48 89 c7             	mov    %rax,%rdi
    381e:	e8 7a dc ff ff       	call   149d <Slice_eq>
    3823:	84 c0                	test   %al,%al
    3825:	74 14                	je     383b <Parser_childKind+0x485>
    3827:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    382b:	c7 00 16 00 00 00    	movl   $0x16,(%rax)
    3831:	b8 01 00 00 00       	mov    $0x1,%eax
    3836:	e9 ae 01 00 00       	jmp    39e9 <Parser_childKind+0x633>
    383b:	48 8d 05 4b 68 00 00 	lea    0x684b(%rip),%rax        # a08d <_IO_stdin_used+0x8d>
    3842:	be 04 00 00 00       	mov    $0x4,%esi
    3847:	48 89 c7             	mov    %rax,%rdi
    384a:	e8 59 e9 ff ff       	call   21a8 <mkSlice>
    384f:	48 89 c1             	mov    %rax,%rcx
    3852:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    3856:	48 89 ce             	mov    %rcx,%rsi
    3859:	48 89 c7             	mov    %rax,%rdi
    385c:	e8 3c dc ff ff       	call   149d <Slice_eq>
    3861:	84 c0                	test   %al,%al
    3863:	74 14                	je     3879 <Parser_childKind+0x4c3>
    3865:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    3869:	c7 00 13 00 00 00    	movl   $0x13,(%rax)
    386f:	b8 01 00 00 00       	mov    $0x1,%eax
    3874:	e9 70 01 00 00       	jmp    39e9 <Parser_childKind+0x633>
    3879:	48 8d 05 12 68 00 00 	lea    0x6812(%rip),%rax        # a092 <_IO_stdin_used+0x92>
    3880:	be 06 00 00 00       	mov    $0x6,%esi
    3885:	48 89 c7             	mov    %rax,%rdi
    3888:	e8 1b e9 ff ff       	call   21a8 <mkSlice>
    388d:	48 89 c1             	mov    %rax,%rcx
    3890:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    3894:	48 89 ce             	mov    %rcx,%rsi
    3897:	48 89 c7             	mov    %rax,%rdi
    389a:	e8 fe db ff ff       	call   149d <Slice_eq>
    389f:	84 c0                	test   %al,%al
    38a1:	74 14                	je     38b7 <Parser_childKind+0x501>
    38a3:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    38a7:	c7 00 14 00 00 00    	movl   $0x14,(%rax)
    38ad:	b8 01 00 00 00       	mov    $0x1,%eax
    38b2:	e9 32 01 00 00       	jmp    39e9 <Parser_childKind+0x633>
    38b7:	48 8d 05 db 67 00 00 	lea    0x67db(%rip),%rax        # a099 <_IO_stdin_used+0x99>
    38be:	be 03 00 00 00       	mov    $0x3,%esi
    38c3:	48 89 c7             	mov    %rax,%rdi
    38c6:	e8 dd e8 ff ff       	call   21a8 <mkSlice>
    38cb:	48 89 c1             	mov    %rax,%rcx
    38ce:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    38d2:	48 89 ce             	mov    %rcx,%rsi
    38d5:	48 89 c7             	mov    %rax,%rdi
    38d8:	e8 c0 db ff ff       	call   149d <Slice_eq>
    38dd:	84 c0                	test   %al,%al
    38df:	74 14                	je     38f5 <Parser_childKind+0x53f>
    38e1:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    38e5:	c7 00 15 00 00 00    	movl   $0x15,(%rax)
    38eb:	b8 01 00 00 00       	mov    $0x1,%eax
    38f0:	e9 f4 00 00 00       	jmp    39e9 <Parser_childKind+0x633>
    38f5:	48 8d 05 c3 67 00 00 	lea    0x67c3(%rip),%rax        # a0bf <_IO_stdin_used+0xbf>
    38fc:	be 07 00 00 00       	mov    $0x7,%esi
    3901:	48 89 c7             	mov    %rax,%rdi
    3904:	e8 9f e8 ff ff       	call   21a8 <mkSlice>
    3909:	48 89 c1             	mov    %rax,%rcx
    390c:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    3910:	48 89 ce             	mov    %rcx,%rsi
    3913:	48 89 c7             	mov    %rax,%rdi
    3916:	e8 82 db ff ff       	call   149d <Slice_eq>
    391b:	84 c0                	test   %al,%al
    391d:	74 14                	je     3933 <Parser_childKind+0x57d>
    391f:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    3923:	c7 00 1b 00 00 00    	movl   $0x1b,(%rax)
    3929:	b8 01 00 00 00       	mov    $0x1,%eax
    392e:	e9 b6 00 00 00       	jmp    39e9 <Parser_childKind+0x633>
    3933:	48 8d 05 ec 66 00 00 	lea    0x66ec(%rip),%rax        # a026 <_IO_stdin_used+0x26>
    393a:	be 05 00 00 00       	mov    $0x5,%esi
    393f:	48 89 c7             	mov    %rax,%rdi
    3942:	e8 61 e8 ff ff       	call   21a8 <mkSlice>
    3947:	48 89 c1             	mov    %rax,%rcx
    394a:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    394e:	48 89 ce             	mov    %rcx,%rsi
    3951:	48 89 c7             	mov    %rax,%rdi
    3954:	e8 44 db ff ff       	call   149d <Slice_eq>
    3959:	84 c0                	test   %al,%al
    395b:	74 11                	je     396e <Parser_childKind+0x5b8>
    395d:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    3961:	c7 00 03 00 00 00    	movl   $0x3,(%rax)
    3967:	b8 01 00 00 00       	mov    $0x1,%eax
    396c:	eb 7b                	jmp    39e9 <Parser_childKind+0x633>
    396e:	48 8d 05 a3 66 00 00 	lea    0x66a3(%rip),%rax        # a018 <_IO_stdin_used+0x18>
    3975:	be 06 00 00 00       	mov    $0x6,%esi
    397a:	48 89 c7             	mov    %rax,%rdi
    397d:	e8 26 e8 ff ff       	call   21a8 <mkSlice>
    3982:	48 89 c1             	mov    %rax,%rcx
    3985:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    3989:	48 89 ce             	mov    %rcx,%rsi
    398c:	48 89 c7             	mov    %rax,%rdi
    398f:	e8 09 db ff ff       	call   149d <Slice_eq>
    3994:	84 c0                	test   %al,%al
    3996:	74 11                	je     39a9 <Parser_childKind+0x5f3>
    3998:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    399c:	c7 00 01 00 00 00    	movl   $0x1,(%rax)
    39a2:	b8 01 00 00 00       	mov    $0x1,%eax
    39a7:	eb 40                	jmp    39e9 <Parser_childKind+0x633>
    39a9:	48 8d 05 6f 66 00 00 	lea    0x666f(%rip),%rax        # a01f <_IO_stdin_used+0x1f>
    39b0:	be 06 00 00 00       	mov    $0x6,%esi
    39b5:	48 89 c7             	mov    %rax,%rdi
    39b8:	e8 eb e7 ff ff       	call   21a8 <mkSlice>
    39bd:	48 89 c1             	mov    %rax,%rcx
    39c0:	48 8d 45 e0          	lea    -0x20(%rbp),%rax
    39c4:	48 89 ce             	mov    %rcx,%rsi
    39c7:	48 89 c7             	mov    %rax,%rdi
    39ca:	e8 ce da ff ff       	call   149d <Slice_eq>
    39cf:	84 c0                	test   %al,%al
    39d1:	74 11                	je     39e4 <Parser_childKind+0x62e>
    39d3:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    39d7:	c7 00 02 00 00 00    	movl   $0x2,(%rax)
    39dd:	b8 01 00 00 00       	mov    $0x1,%eax
    39e2:	eb 05                	jmp    39e9 <Parser_childKind+0x633>
    39e4:	b8 00 00 00 00       	mov    $0x0,%eax
    39e9:	c9                   	leave
    39ea:	c3                   	ret

00000000000039eb <Parser_parseBlockInto>:
    39eb:	55                   	push   %rbp
    39ec:	48 89 e5             	mov    %rsp,%rbp
    39ef:	53                   	push   %rbx
    39f0:	48 81 ec d8 00 00 00 	sub    $0xd8,%rsp
    39f7:	48 89 bd 28 ff ff ff 	mov    %rdi,-0xd8(%rbp)
    39fe:	48 89 b5 20 ff ff ff 	mov    %rsi,-0xe0(%rbp)
    3a05:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    3a0c:	00 00 
    3a0e:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    3a12:	31 c0                	xor    %eax,%eax
    3a14:	48 8d 15 f5 66 00 00 	lea    0x66f5(%rip),%rdx        # a110 <_IO_stdin_used+0x110>
    3a1b:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3a22:	be 05 00 00 00       	mov    $0x5,%esi
    3a27:	48 89 c7             	mov    %rax,%rdi
    3a2a:	e8 e8 f4 ff ff       	call   2f17 <Parser_expect>
    3a2f:	e9 4c 06 00 00       	jmp    4080 <Parser_parseBlockInto+0x695>
    3a34:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3a3b:	be 01 00 00 00       	mov    $0x1,%esi
    3a40:	48 89 c7             	mov    %rax,%rdi
    3a43:	e8 1c f4 ff ff       	call   2e64 <Parser_check>
    3a48:	84 c0                	test   %al,%al
    3a4a:	0f 84 b1 04 00 00    	je     3f01 <Parser_parseBlockInto+0x516>
    3a50:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3a57:	48 8b 50 50          	mov    0x50(%rax),%rdx
    3a5b:	48 8b 40 48          	mov    0x48(%rax),%rax
    3a5f:	48 89 85 40 ff ff ff 	mov    %rax,-0xc0(%rbp)
    3a66:	48 89 95 48 ff ff ff 	mov    %rdx,-0xb8(%rbp)
    3a6d:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3a74:	48 89 c7             	mov    %rax,%rdi
    3a77:	e8 bb f2 ff ff       	call   2d37 <Parser_advance>
    3a7c:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3a83:	be 09 00 00 00       	mov    $0x9,%esi
    3a88:	48 89 c7             	mov    %rax,%rdi
    3a8b:	e8 d4 f3 ff ff       	call   2e64 <Parser_check>
    3a90:	84 c0                	test   %al,%al
    3a92:	0f 84 df 01 00 00    	je     3c77 <Parser_parseBlockInto+0x28c>
    3a98:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3a9f:	48 89 c7             	mov    %rax,%rdi
    3aa2:	e8 90 f2 ff ff       	call   2d37 <Parser_advance>
    3aa7:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3aae:	be 05 00 00 00       	mov    $0x5,%esi
    3ab3:	48 89 c7             	mov    %rax,%rdi
    3ab6:	e8 a9 f3 ff ff       	call   2e64 <Parser_check>
    3abb:	84 c0                	test   %al,%al
    3abd:	0f 84 2f 01 00 00    	je     3bf2 <Parser_parseBlockInto+0x207>
    3ac3:	48 8d 8d 3c ff ff ff 	lea    -0xc4(%rbp),%rcx
    3aca:	48 8b b5 40 ff ff ff 	mov    -0xc0(%rbp),%rsi
    3ad1:	48 8b 95 48 ff ff ff 	mov    -0xb8(%rbp),%rdx
    3ad8:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3adf:	48 89 c7             	mov    %rax,%rdi
    3ae2:	e8 cf f8 ff ff       	call   33b6 <Parser_childKind>
    3ae7:	83 f0 01             	xor    $0x1,%eax
    3aea:	84 c0                	test   %al,%al
    3aec:	74 6a                	je     3b58 <Parser_parseBlockInto+0x16d>
    3aee:	48 8d 35 34 66 00 00 	lea    0x6634(%rip),%rsi        # a129 <_IO_stdin_used+0x129>
    3af5:	48 8b bd 28 ff ff ff 	mov    -0xd8(%rbp),%rdi
    3afc:	48 83 ec 08          	sub    $0x8,%rsp
    3b00:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3b07:	48 83 ec 38          	sub    $0x38,%rsp
    3b0b:	48 89 e2             	mov    %rsp,%rdx
    3b0e:	48 8b 48 08          	mov    0x8(%rax),%rcx
    3b12:	48 8b 58 10          	mov    0x10(%rax),%rbx
    3b16:	48 89 0a             	mov    %rcx,(%rdx)
    3b19:	48 89 5a 08          	mov    %rbx,0x8(%rdx)
    3b1d:	48 8b 48 18          	mov    0x18(%rax),%rcx
    3b21:	48 8b 58 20          	mov    0x20(%rax),%rbx
    3b25:	48 89 4a 10          	mov    %rcx,0x10(%rdx)
    3b29:	48 89 5a 18          	mov    %rbx,0x18(%rdx)
    3b2d:	48 8b 48 28          	mov    0x28(%rax),%rcx
    3b31:	48 8b 58 30          	mov    0x30(%rax),%rbx
    3b35:	48 89 4a 20          	mov    %rcx,0x20(%rdx)
    3b39:	48 89 5a 28          	mov    %rbx,0x28(%rdx)
    3b3d:	48 8b 40 38          	mov    0x38(%rax),%rax
    3b41:	48 89 42 30          	mov    %rax,0x30(%rdx)
    3b45:	e8 83 f3 ff ff       	call   2ecd <Parser_errorAt>
    3b4a:	48 83 c4 40          	add    $0x40,%rsp
    3b4e:	c7 85 3c ff ff ff 10 	movl   $0x10,-0xc4(%rbp)
    3b55:	00 00 00 
    3b58:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3b5f:	48 8b 90 b0 00 00 00 	mov    0xb0(%rax),%rdx
    3b66:	8b 8d 3c ff ff ff    	mov    -0xc4(%rbp),%ecx
    3b6c:	48 8d 85 50 ff ff ff 	lea    -0xb0(%rbp),%rax
    3b73:	89 ce                	mov    %ecx,%esi
    3b75:	48 89 c7             	mov    %rax,%rdi
    3b78:	e8 51 e6 ff ff       	call   21ce <Node_init>
    3b7d:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    3b84:	48 8b 95 48 ff ff ff 	mov    -0xb8(%rbp),%rdx
    3b8b:	48 89 85 58 ff ff ff 	mov    %rax,-0xa8(%rbp)
    3b92:	48 89 95 60 ff ff ff 	mov    %rdx,-0xa0(%rbp)
    3b99:	c6 85 68 ff ff ff 01 	movb   $0x1,-0x98(%rbp)
    3ba0:	48 8d 95 50 ff ff ff 	lea    -0xb0(%rbp),%rdx
    3ba7:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3bae:	48 89 d6             	mov    %rdx,%rsi
    3bb1:	48 89 c7             	mov    %rax,%rdi
    3bb4:	e8 32 fe ff ff       	call   39eb <Parser_parseBlockInto>
    3bb9:	48 8d 15 7c 65 00 00 	lea    0x657c(%rip),%rdx        # a13c <_IO_stdin_used+0x13c>
    3bc0:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3bc7:	be 0a 00 00 00       	mov    $0xa,%esi
    3bcc:	48 89 c7             	mov    %rax,%rdi
    3bcf:	e8 43 f3 ff ff       	call   2f17 <Parser_expect>
    3bd4:	48 8d 95 50 ff ff ff 	lea    -0xb0(%rbp),%rdx
    3bdb:	48 8b 85 20 ff ff ff 	mov    -0xe0(%rbp),%rax
    3be2:	48 89 d6             	mov    %rdx,%rsi
    3be5:	48 89 c7             	mov    %rax,%rdi
    3be8:	e8 8e e8 ff ff       	call   247b <Node_addChild>
    3bed:	e9 8e 04 00 00       	jmp    4080 <Parser_parseBlockInto+0x695>
    3bf2:	48 8d 85 50 ff ff ff 	lea    -0xb0(%rbp),%rax
    3bf9:	48 8b 95 28 ff ff ff 	mov    -0xd8(%rbp),%rdx
    3c00:	48 89 d6             	mov    %rdx,%rsi
    3c03:	48 89 c7             	mov    %rax,%rdi
    3c06:	e8 8d f4 ff ff       	call   3098 <Parser_parseValue>
    3c0b:	48 8d 15 41 65 00 00 	lea    0x6541(%rip),%rdx        # a153 <_IO_stdin_used+0x153>
    3c12:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3c19:	be 0a 00 00 00       	mov    $0xa,%esi
    3c1e:	48 89 c7             	mov    %rax,%rdi
    3c21:	e8 f1 f2 ff ff       	call   2f17 <Parser_expect>
    3c26:	48 8b b5 40 ff ff ff 	mov    -0xc0(%rbp),%rsi
    3c2d:	4c 8b 85 48 ff ff ff 	mov    -0xb8(%rbp),%r8
    3c34:	48 8b bd 20 ff ff ff 	mov    -0xe0(%rbp),%rdi
    3c3b:	48 83 ec 08          	sub    $0x8,%rsp
    3c3f:	48 83 ec 18          	sub    $0x18,%rsp
    3c43:	48 89 e1             	mov    %rsp,%rcx
    3c46:	48 8b 85 50 ff ff ff 	mov    -0xb0(%rbp),%rax
    3c4d:	48 8b 95 58 ff ff ff 	mov    -0xa8(%rbp),%rdx
    3c54:	48 89 01             	mov    %rax,(%rcx)
    3c57:	48 89 51 08          	mov    %rdx,0x8(%rcx)
    3c5b:	48 8b 85 60 ff ff ff 	mov    -0xa0(%rbp),%rax
    3c62:	48 89 41 10          	mov    %rax,0x10(%rcx)
    3c66:	4c 89 c2             	mov    %r8,%rdx
    3c69:	e8 50 e6 ff ff       	call   22be <Node_addField>
    3c6e:	48 83 c4 20          	add    $0x20,%rsp
    3c72:	e9 09 04 00 00       	jmp    4080 <Parser_parseBlockInto+0x695>
    3c77:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3c7e:	be 02 00 00 00       	mov    $0x2,%esi
    3c83:	48 89 c7             	mov    %rax,%rdi
    3c86:	e8 d9 f1 ff ff       	call   2e64 <Parser_check>
    3c8b:	84 c0                	test   %al,%al
    3c8d:	75 1c                	jne    3cab <Parser_parseBlockInto+0x2c0>
    3c8f:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3c96:	be 05 00 00 00       	mov    $0x5,%esi
    3c9b:	48 89 c7             	mov    %rax,%rdi
    3c9e:	e8 c1 f1 ff ff       	call   2e64 <Parser_check>
    3ca3:	84 c0                	test   %al,%al
    3ca5:	0f 84 f0 01 00 00    	je     3e9b <Parser_parseBlockInto+0x4b0>
    3cab:	48 8d 8d 3c ff ff ff 	lea    -0xc4(%rbp),%rcx
    3cb2:	48 8b b5 40 ff ff ff 	mov    -0xc0(%rbp),%rsi
    3cb9:	48 8b 95 48 ff ff ff 	mov    -0xb8(%rbp),%rdx
    3cc0:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3cc7:	48 89 c7             	mov    %rax,%rdi
    3cca:	e8 e7 f6 ff ff       	call   33b6 <Parser_childKind>
    3ccf:	83 f0 01             	xor    $0x1,%eax
    3cd2:	84 c0                	test   %al,%al
    3cd4:	74 6a                	je     3d40 <Parser_parseBlockInto+0x355>
    3cd6:	48 8d 35 4c 64 00 00 	lea    0x644c(%rip),%rsi        # a129 <_IO_stdin_used+0x129>
    3cdd:	48 8b bd 28 ff ff ff 	mov    -0xd8(%rbp),%rdi
    3ce4:	48 83 ec 08          	sub    $0x8,%rsp
    3ce8:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3cef:	48 83 ec 38          	sub    $0x38,%rsp
    3cf3:	48 89 e2             	mov    %rsp,%rdx
    3cf6:	48 8b 48 08          	mov    0x8(%rax),%rcx
    3cfa:	48 8b 58 10          	mov    0x10(%rax),%rbx
    3cfe:	48 89 0a             	mov    %rcx,(%rdx)
    3d01:	48 89 5a 08          	mov    %rbx,0x8(%rdx)
    3d05:	48 8b 48 18          	mov    0x18(%rax),%rcx
    3d09:	48 8b 58 20          	mov    0x20(%rax),%rbx
    3d0d:	48 89 4a 10          	mov    %rcx,0x10(%rdx)
    3d11:	48 89 5a 18          	mov    %rbx,0x18(%rdx)
    3d15:	48 8b 48 28          	mov    0x28(%rax),%rcx
    3d19:	48 8b 58 30          	mov    0x30(%rax),%rbx
    3d1d:	48 89 4a 20          	mov    %rcx,0x20(%rdx)
    3d21:	48 89 5a 28          	mov    %rbx,0x28(%rdx)
    3d25:	48 8b 40 38          	mov    0x38(%rax),%rax
    3d29:	48 89 42 30          	mov    %rax,0x30(%rdx)
    3d2d:	e8 9b f1 ff ff       	call   2ecd <Parser_errorAt>
    3d32:	48 83 c4 40          	add    $0x40,%rsp
    3d36:	c7 85 3c ff ff ff 1a 	movl   $0x1a,-0xc4(%rbp)
    3d3d:	00 00 00 
    3d40:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3d47:	48 8b 90 b0 00 00 00 	mov    0xb0(%rax),%rdx
    3d4e:	8b 8d 3c ff ff ff    	mov    -0xc4(%rbp),%ecx
    3d54:	48 8d 85 50 ff ff ff 	lea    -0xb0(%rbp),%rax
    3d5b:	89 ce                	mov    %ecx,%esi
    3d5d:	48 89 c7             	mov    %rax,%rdi
    3d60:	e8 69 e4 ff ff       	call   21ce <Node_init>
    3d65:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    3d6c:	48 8b 95 48 ff ff ff 	mov    -0xb8(%rbp),%rdx
    3d73:	48 89 85 58 ff ff ff 	mov    %rax,-0xa8(%rbp)
    3d7a:	48 89 95 60 ff ff ff 	mov    %rdx,-0xa0(%rbp)
    3d81:	c6 85 68 ff ff ff 01 	movb   $0x1,-0x98(%rbp)
    3d88:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3d8f:	be 02 00 00 00       	mov    $0x2,%esi
    3d94:	48 89 c7             	mov    %rax,%rdi
    3d97:	e8 c8 f0 ff ff       	call   2e64 <Parser_check>
    3d9c:	84 c0                	test   %al,%al
    3d9e:	74 33                	je     3dd3 <Parser_parseBlockInto+0x3e8>
    3da0:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3da7:	48 8b 50 50          	mov    0x50(%rax),%rdx
    3dab:	48 8b 40 48          	mov    0x48(%rax),%rax
    3daf:	48 89 85 58 ff ff ff 	mov    %rax,-0xa8(%rbp)
    3db6:	48 89 95 60 ff ff ff 	mov    %rdx,-0xa0(%rbp)
    3dbd:	c6 85 68 ff ff ff 01 	movb   $0x1,-0x98(%rbp)
    3dc4:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3dcb:	48 89 c7             	mov    %rax,%rdi
    3dce:	e8 64 ef ff ff       	call   2d37 <Parser_advance>
    3dd3:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3dda:	be 01 00 00 00       	mov    $0x1,%esi
    3ddf:	48 89 c7             	mov    %rax,%rdi
    3de2:	e8 7d f0 ff ff       	call   2e64 <Parser_check>
    3de7:	84 c0                	test   %al,%al
    3de9:	74 79                	je     3e64 <Parser_parseBlockInto+0x479>
    3deb:	48 8d 0d 78 63 00 00 	lea    0x6378(%rip),%rcx        # a16a <_IO_stdin_used+0x16a>
    3df2:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3df9:	ba 07 00 00 00       	mov    $0x7,%edx
    3dfe:	48 89 ce             	mov    %rcx,%rsi
    3e01:	48 89 c7             	mov    %rax,%rdi
    3e04:	e8 16 f2 ff ff       	call   301f <Parser_curIsWord>
    3e09:	84 c0                	test   %al,%al
    3e0b:	74 57                	je     3e64 <Parser_parseBlockInto+0x479>
    3e0d:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3e14:	48 89 c7             	mov    %rax,%rdi
    3e17:	e8 1b ef ff ff       	call   2d37 <Parser_advance>
    3e1c:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3e23:	be 02 00 00 00       	mov    $0x2,%esi
    3e28:	48 89 c7             	mov    %rax,%rdi
    3e2b:	e8 34 f0 ff ff       	call   2e64 <Parser_check>
    3e30:	84 c0                	test   %al,%al
    3e32:	74 30                	je     3e64 <Parser_parseBlockInto+0x479>
    3e34:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3e3b:	48 8b 50 50          	mov    0x50(%rax),%rdx
    3e3f:	48 8b 40 48          	mov    0x48(%rax),%rax
    3e43:	48 89 85 70 ff ff ff 	mov    %rax,-0x90(%rbp)
    3e4a:	48 89 95 78 ff ff ff 	mov    %rdx,-0x88(%rbp)
    3e51:	c6 45 80 01          	movb   $0x1,-0x80(%rbp)
    3e55:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3e5c:	48 89 c7             	mov    %rax,%rdi
    3e5f:	e8 d3 ee ff ff       	call   2d37 <Parser_advance>
    3e64:	48 8d 95 50 ff ff ff 	lea    -0xb0(%rbp),%rdx
    3e6b:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3e72:	48 89 d6             	mov    %rdx,%rsi
    3e75:	48 89 c7             	mov    %rax,%rdi
    3e78:	e8 6e fb ff ff       	call   39eb <Parser_parseBlockInto>
    3e7d:	48 8d 95 50 ff ff ff 	lea    -0xb0(%rbp),%rdx
    3e84:	48 8b 85 20 ff ff ff 	mov    -0xe0(%rbp),%rax
    3e8b:	48 89 d6             	mov    %rdx,%rsi
    3e8e:	48 89 c7             	mov    %rax,%rdi
    3e91:	e8 e5 e5 ff ff       	call   247b <Node_addChild>
    3e96:	e9 e5 01 00 00       	jmp    4080 <Parser_parseBlockInto+0x695>
    3e9b:	48 8d 35 d0 62 00 00 	lea    0x62d0(%rip),%rsi        # a172 <_IO_stdin_used+0x172>
    3ea2:	48 8b bd 28 ff ff ff 	mov    -0xd8(%rbp),%rdi
    3ea9:	48 83 ec 08          	sub    $0x8,%rsp
    3ead:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3eb4:	48 83 ec 38          	sub    $0x38,%rsp
    3eb8:	48 89 e2             	mov    %rsp,%rdx
    3ebb:	48 8b 48 40          	mov    0x40(%rax),%rcx
    3ebf:	48 8b 58 48          	mov    0x48(%rax),%rbx
    3ec3:	48 89 0a             	mov    %rcx,(%rdx)
    3ec6:	48 89 5a 08          	mov    %rbx,0x8(%rdx)
    3eca:	48 8b 48 50          	mov    0x50(%rax),%rcx
    3ece:	48 8b 58 58          	mov    0x58(%rax),%rbx
    3ed2:	48 89 4a 10          	mov    %rcx,0x10(%rdx)
    3ed6:	48 89 5a 18          	mov    %rbx,0x18(%rdx)
    3eda:	48 8b 48 60          	mov    0x60(%rax),%rcx
    3ede:	48 8b 58 68          	mov    0x68(%rax),%rbx
    3ee2:	48 89 4a 20          	mov    %rcx,0x20(%rdx)
    3ee6:	48 89 5a 28          	mov    %rbx,0x28(%rdx)
    3eea:	48 8b 40 70          	mov    0x70(%rax),%rax
    3eee:	48 89 42 30          	mov    %rax,0x30(%rdx)
    3ef2:	e8 d6 ef ff ff       	call   2ecd <Parser_errorAt>
    3ef7:	48 83 c4 40          	add    $0x40,%rsp
    3efb:	90                   	nop
    3efc:	e9 7f 01 00 00       	jmp    4080 <Parser_parseBlockInto+0x695>
    3f01:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3f08:	be 02 00 00 00       	mov    $0x2,%esi
    3f0d:	48 89 c7             	mov    %rax,%rdi
    3f10:	e8 4f ef ff ff       	call   2e64 <Parser_check>
    3f15:	84 c0                	test   %al,%al
    3f17:	0f 84 f4 00 00 00    	je     4011 <Parser_parseBlockInto+0x626>
    3f1d:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3f24:	48 8b 50 50          	mov    0x50(%rax),%rdx
    3f28:	48 8b 40 48          	mov    0x48(%rax),%rax
    3f2c:	48 89 85 40 ff ff ff 	mov    %rax,-0xc0(%rbp)
    3f33:	48 89 95 48 ff ff ff 	mov    %rdx,-0xb8(%rbp)
    3f3a:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3f41:	48 89 c7             	mov    %rax,%rdi
    3f44:	e8 ee ed ff ff       	call   2d37 <Parser_advance>
    3f49:	48 8d 15 3d 62 00 00 	lea    0x623d(%rip),%rdx        # a18d <_IO_stdin_used+0x18d>
    3f50:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3f57:	be 09 00 00 00       	mov    $0x9,%esi
    3f5c:	48 89 c7             	mov    %rax,%rdi
    3f5f:	e8 b3 ef ff ff       	call   2f17 <Parser_expect>
    3f64:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3f6b:	48 8b 90 b0 00 00 00 	mov    0xb0(%rax),%rdx
    3f72:	48 8d 85 50 ff ff ff 	lea    -0xb0(%rbp),%rax
    3f79:	be 19 00 00 00       	mov    $0x19,%esi
    3f7e:	48 89 c7             	mov    %rax,%rdi
    3f81:	e8 48 e2 ff ff       	call   21ce <Node_init>
    3f86:	48 8b 85 40 ff ff ff 	mov    -0xc0(%rbp),%rax
    3f8d:	48 8b 95 48 ff ff ff 	mov    -0xb8(%rbp),%rdx
    3f94:	48 89 85 58 ff ff ff 	mov    %rax,-0xa8(%rbp)
    3f9b:	48 89 95 60 ff ff ff 	mov    %rdx,-0xa0(%rbp)
    3fa2:	c6 85 68 ff ff ff 01 	movb   $0x1,-0x98(%rbp)
    3fa9:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3fb0:	be 05 00 00 00       	mov    $0x5,%esi
    3fb5:	48 89 c7             	mov    %rax,%rdi
    3fb8:	e8 a7 ee ff ff       	call   2e64 <Parser_check>
    3fbd:	84 c0                	test   %al,%al
    3fbf:	74 19                	je     3fda <Parser_parseBlockInto+0x5ef>
    3fc1:	48 8d 95 50 ff ff ff 	lea    -0xb0(%rbp),%rdx
    3fc8:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3fcf:	48 89 d6             	mov    %rdx,%rsi
    3fd2:	48 89 c7             	mov    %rax,%rdi
    3fd5:	e8 11 fa ff ff       	call   39eb <Parser_parseBlockInto>
    3fda:	48 8d 15 c8 61 00 00 	lea    0x61c8(%rip),%rdx        # a1a9 <_IO_stdin_used+0x1a9>
    3fe1:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    3fe8:	be 0a 00 00 00       	mov    $0xa,%esi
    3fed:	48 89 c7             	mov    %rax,%rdi
    3ff0:	e8 22 ef ff ff       	call   2f17 <Parser_expect>
    3ff5:	48 8d 95 50 ff ff ff 	lea    -0xb0(%rbp),%rdx
    3ffc:	48 8b 85 20 ff ff ff 	mov    -0xe0(%rbp),%rax
    4003:	48 89 d6             	mov    %rdx,%rsi
    4006:	48 89 c7             	mov    %rax,%rdi
    4009:	e8 6d e4 ff ff       	call   247b <Node_addChild>
    400e:	90                   	nop
    400f:	eb 6f                	jmp    4080 <Parser_parseBlockInto+0x695>
    4011:	48 8d 35 a8 61 00 00 	lea    0x61a8(%rip),%rsi        # a1c0 <_IO_stdin_used+0x1c0>
    4018:	48 8b bd 28 ff ff ff 	mov    -0xd8(%rbp),%rdi
    401f:	48 83 ec 08          	sub    $0x8,%rsp
    4023:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    402a:	48 83 ec 38          	sub    $0x38,%rsp
    402e:	48 89 e2             	mov    %rsp,%rdx
    4031:	48 8b 48 40          	mov    0x40(%rax),%rcx
    4035:	48 8b 58 48          	mov    0x48(%rax),%rbx
    4039:	48 89 0a             	mov    %rcx,(%rdx)
    403c:	48 89 5a 08          	mov    %rbx,0x8(%rdx)
    4040:	48 8b 48 50          	mov    0x50(%rax),%rcx
    4044:	48 8b 58 58          	mov    0x58(%rax),%rbx
    4048:	48 89 4a 10          	mov    %rcx,0x10(%rdx)
    404c:	48 89 5a 18          	mov    %rbx,0x18(%rdx)
    4050:	48 8b 48 60          	mov    0x60(%rax),%rcx
    4054:	48 8b 58 68          	mov    0x68(%rax),%rbx
    4058:	48 89 4a 20          	mov    %rcx,0x20(%rdx)
    405c:	48 89 5a 28          	mov    %rbx,0x28(%rdx)
    4060:	48 8b 40 70          	mov    0x70(%rax),%rax
    4064:	48 89 42 30          	mov    %rax,0x30(%rdx)
    4068:	e8 60 ee ff ff       	call   2ecd <Parser_errorAt>
    406d:	48 83 c4 40          	add    $0x40,%rsp
    4071:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    4078:	48 89 c7             	mov    %rax,%rdi
    407b:	e8 b7 ec ff ff       	call   2d37 <Parser_advance>
    4080:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    4087:	be 06 00 00 00       	mov    $0x6,%esi
    408c:	48 89 c7             	mov    %rax,%rdi
    408f:	e8 d0 ed ff ff       	call   2e64 <Parser_check>
    4094:	83 f0 01             	xor    $0x1,%eax
    4097:	84 c0                	test   %al,%al
    4099:	74 1f                	je     40ba <Parser_parseBlockInto+0x6cf>
    409b:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    40a2:	be 00 00 00 00       	mov    $0x0,%esi
    40a7:	48 89 c7             	mov    %rax,%rdi
    40aa:	e8 b5 ed ff ff       	call   2e64 <Parser_check>
    40af:	83 f0 01             	xor    $0x1,%eax
    40b2:	84 c0                	test   %al,%al
    40b4:	0f 85 7a f9 ff ff    	jne    3a34 <Parser_parseBlockInto+0x49>
    40ba:	48 8d 15 19 61 00 00 	lea    0x6119(%rip),%rdx        # a1da <_IO_stdin_used+0x1da>
    40c1:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    40c8:	be 06 00 00 00       	mov    $0x6,%esi
    40cd:	48 89 c7             	mov    %rax,%rdi
    40d0:	e8 42 ee ff ff       	call   2f17 <Parser_expect>
    40d5:	90                   	nop
    40d6:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    40da:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    40e1:	00 00 
    40e3:	74 05                	je     40ea <Parser_parseBlockInto+0x6ff>
    40e5:	e8 96 cf ff ff       	call   1080 <__stack_chk_fail@plt>
    40ea:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
    40ee:	c9                   	leave
    40ef:	c3                   	ret

00000000000040f0 <Parser_parseTopDecl>:
    40f0:	55                   	push   %rbp
    40f1:	48 89 e5             	mov    %rsp,%rbp
    40f4:	53                   	push   %rbx
    40f5:	48 83 ec 78          	sub    $0x78,%rsp
    40f9:	48 89 7d 88          	mov    %rdi,-0x78(%rbp)
    40fd:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    4104:	00 00 
    4106:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    410a:	31 c0                	xor    %eax,%eax
    410c:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    4110:	be 01 00 00 00       	mov    $0x1,%esi
    4115:	48 89 c7             	mov    %rax,%rdi
    4118:	e8 47 ed ff ff       	call   2e64 <Parser_check>
    411d:	83 f0 01             	xor    $0x1,%eax
    4120:	84 c0                	test   %al,%al
    4122:	74 70                	je     4194 <Parser_parseTopDecl+0xa4>
    4124:	48 8d 35 c9 60 00 00 	lea    0x60c9(%rip),%rsi        # a1f4 <_IO_stdin_used+0x1f4>
    412b:	48 8b 7d 88          	mov    -0x78(%rbp),%rdi
    412f:	48 83 ec 08          	sub    $0x8,%rsp
    4133:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    4137:	48 83 ec 38          	sub    $0x38,%rsp
    413b:	48 89 e2             	mov    %rsp,%rdx
    413e:	48 8b 48 40          	mov    0x40(%rax),%rcx
    4142:	48 8b 58 48          	mov    0x48(%rax),%rbx
    4146:	48 89 0a             	mov    %rcx,(%rdx)
    4149:	48 89 5a 08          	mov    %rbx,0x8(%rdx)
    414d:	48 8b 48 50          	mov    0x50(%rax),%rcx
    4151:	48 8b 58 58          	mov    0x58(%rax),%rbx
    4155:	48 89 4a 10          	mov    %rcx,0x10(%rdx)
    4159:	48 89 5a 18          	mov    %rbx,0x18(%rdx)
    415d:	48 8b 48 60          	mov    0x60(%rax),%rcx
    4161:	48 8b 58 68          	mov    0x68(%rax),%rbx
    4165:	48 89 4a 20          	mov    %rcx,0x20(%rdx)
    4169:	48 89 5a 28          	mov    %rbx,0x28(%rdx)
    416d:	48 8b 40 70          	mov    0x70(%rax),%rax
    4171:	48 89 42 30          	mov    %rax,0x30(%rdx)
    4175:	e8 53 ed ff ff       	call   2ecd <Parser_errorAt>
    417a:	48 83 c4 40          	add    $0x40,%rsp
    417e:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    4182:	48 89 c7             	mov    %rax,%rdi
    4185:	e8 ad eb ff ff       	call   2d37 <Parser_advance>
    418a:	b8 00 00 00 00       	mov    $0x0,%eax
    418f:	e9 57 06 00 00       	jmp    47eb <Parser_parseTopDecl+0x6fb>
    4194:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    4198:	48 8b 50 50          	mov    0x50(%rax),%rdx
    419c:	48 8b 40 48          	mov    0x48(%rax),%rax
    41a0:	48 89 45 c0          	mov    %rax,-0x40(%rbp)
    41a4:	48 89 55 c8          	mov    %rdx,-0x38(%rbp)
    41a8:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    41ac:	48 89 c7             	mov    %rax,%rdi
    41af:	e8 83 eb ff ff       	call   2d37 <Parser_advance>
    41b4:	48 8d 05 5d 5e 00 00 	lea    0x5e5d(%rip),%rax        # a018 <_IO_stdin_used+0x18>
    41bb:	be 06 00 00 00       	mov    $0x6,%esi
    41c0:	48 89 c7             	mov    %rax,%rdi
    41c3:	e8 e0 df ff ff       	call   21a8 <mkSlice>
    41c8:	48 89 c1             	mov    %rax,%rcx
    41cb:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
    41cf:	48 89 ce             	mov    %rcx,%rsi
    41d2:	48 89 c7             	mov    %rax,%rdi
    41d5:	e8 c3 d2 ff ff       	call   149d <Slice_eq>
    41da:	84 c0                	test   %al,%al
    41dc:	75 2e                	jne    420c <Parser_parseTopDecl+0x11c>
    41de:	48 8d 05 3a 5e 00 00 	lea    0x5e3a(%rip),%rax        # a01f <_IO_stdin_used+0x1f>
    41e5:	be 06 00 00 00       	mov    $0x6,%esi
    41ea:	48 89 c7             	mov    %rax,%rdi
    41ed:	e8 b6 df ff ff       	call   21a8 <mkSlice>
    41f2:	48 89 c1             	mov    %rax,%rcx
    41f5:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
    41f9:	48 89 ce             	mov    %rcx,%rsi
    41fc:	48 89 c7             	mov    %rax,%rdi
    41ff:	e8 99 d2 ff ff       	call   149d <Slice_eq>
    4204:	84 c0                	test   %al,%al
    4206:	0f 84 0c 01 00 00    	je     4318 <Parser_parseTopDecl+0x228>
    420c:	c7 45 9c 01 00 00 00 	movl   $0x1,-0x64(%rbp)
    4213:	48 8d 05 05 5e 00 00 	lea    0x5e05(%rip),%rax        # a01f <_IO_stdin_used+0x1f>
    421a:	be 06 00 00 00       	mov    $0x6,%esi
    421f:	48 89 c7             	mov    %rax,%rdi
    4222:	e8 81 df ff ff       	call   21a8 <mkSlice>
    4227:	48 89 c1             	mov    %rax,%rcx
    422a:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
    422e:	48 89 ce             	mov    %rcx,%rsi
    4231:	48 89 c7             	mov    %rax,%rdi
    4234:	e8 64 d2 ff ff       	call   149d <Slice_eq>
    4239:	84 c0                	test   %al,%al
    423b:	74 07                	je     4244 <Parser_parseTopDecl+0x154>
    423d:	c7 45 9c 02 00 00 00 	movl   $0x2,-0x64(%rbp)
    4244:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    4248:	48 8b 80 b0 00 00 00 	mov    0xb0(%rax),%rax
    424f:	ba 08 00 00 00       	mov    $0x8,%edx
    4254:	be 98 00 00 00       	mov    $0x98,%esi
    4259:	48 89 c7             	mov    %rax,%rdi
    425c:	e8 70 d0 ff ff       	call   12d1 <Arena_alloc>
    4261:	48 89 45 b8          	mov    %rax,-0x48(%rbp)
    4265:	48 83 7d b8 00       	cmpq   $0x0,-0x48(%rbp)
    426a:	75 0a                	jne    4276 <Parser_parseTopDecl+0x186>
    426c:	b8 00 00 00 00       	mov    $0x0,%eax
    4271:	e9 75 05 00 00       	jmp    47eb <Parser_parseTopDecl+0x6fb>
    4276:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    427a:	48 8b 90 b0 00 00 00 	mov    0xb0(%rax),%rdx
    4281:	8b 4d 9c             	mov    -0x64(%rbp),%ecx
    4284:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    4288:	89 ce                	mov    %ecx,%esi
    428a:	48 89 c7             	mov    %rax,%rdi
    428d:	e8 3c df ff ff       	call   21ce <Node_init>
    4292:	48 8d 15 77 5f 00 00 	lea    0x5f77(%rip),%rdx        # a210 <_IO_stdin_used+0x210>
    4299:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    429d:	be 09 00 00 00       	mov    $0x9,%esi
    42a2:	48 89 c7             	mov    %rax,%rdi
    42a5:	e8 6d ec ff ff       	call   2f17 <Parser_expect>
    42aa:	48 8d 45 d0          	lea    -0x30(%rbp),%rax
    42ae:	48 8b 55 88          	mov    -0x78(%rbp),%rdx
    42b2:	48 89 d6             	mov    %rdx,%rsi
    42b5:	48 89 c7             	mov    %rax,%rdi
    42b8:	e8 db ed ff ff       	call   3098 <Parser_parseValue>
    42bd:	48 8d 15 74 5f 00 00 	lea    0x5f74(%rip),%rdx        # a238 <_IO_stdin_used+0x238>
    42c4:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    42c8:	be 0a 00 00 00       	mov    $0xa,%esi
    42cd:	48 89 c7             	mov    %rax,%rdi
    42d0:	e8 42 ec ff ff       	call   2f17 <Parser_expect>
    42d5:	48 8b 75 c0          	mov    -0x40(%rbp),%rsi
    42d9:	4c 8b 45 c8          	mov    -0x38(%rbp),%r8
    42dd:	48 8b 7d b8          	mov    -0x48(%rbp),%rdi
    42e1:	48 83 ec 08          	sub    $0x8,%rsp
    42e5:	48 83 ec 18          	sub    $0x18,%rsp
    42e9:	48 89 e1             	mov    %rsp,%rcx
    42ec:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    42f0:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    42f4:	48 89 01             	mov    %rax,(%rcx)
    42f7:	48 89 51 08          	mov    %rdx,0x8(%rcx)
    42fb:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    42ff:	48 89 41 10          	mov    %rax,0x10(%rcx)
    4303:	4c 89 c2             	mov    %r8,%rdx
    4306:	e8 b3 df ff ff       	call   22be <Node_addField>
    430b:	48 83 c4 20          	add    $0x20,%rsp
    430f:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    4313:	e9 d3 04 00 00       	jmp    47eb <Parser_parseTopDecl+0x6fb>
    4318:	48 8d 05 1f 5d 00 00 	lea    0x5d1f(%rip),%rax        # a03e <_IO_stdin_used+0x3e>
    431f:	be 05 00 00 00       	mov    $0x5,%esi
    4324:	48 89 c7             	mov    %rax,%rdi
    4327:	e8 7c de ff ff       	call   21a8 <mkSlice>
    432c:	48 89 c1             	mov    %rax,%rcx
    432f:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
    4333:	48 89 ce             	mov    %rcx,%rsi
    4336:	48 89 c7             	mov    %rax,%rdi
    4339:	e8 5f d1 ff ff       	call   149d <Slice_eq>
    433e:	84 c0                	test   %al,%al
    4340:	0f 84 c1 01 00 00    	je     4507 <Parser_parseTopDecl+0x417>
    4346:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    434a:	48 8b 80 b0 00 00 00 	mov    0xb0(%rax),%rax
    4351:	ba 08 00 00 00       	mov    $0x8,%edx
    4356:	be 98 00 00 00       	mov    $0x98,%esi
    435b:	48 89 c7             	mov    %rax,%rdi
    435e:	e8 6e cf ff ff       	call   12d1 <Arena_alloc>
    4363:	48 89 45 b0          	mov    %rax,-0x50(%rbp)
    4367:	48 83 7d b0 00       	cmpq   $0x0,-0x50(%rbp)
    436c:	75 0a                	jne    4378 <Parser_parseTopDecl+0x288>
    436e:	b8 00 00 00 00       	mov    $0x0,%eax
    4373:	e9 73 04 00 00       	jmp    47eb <Parser_parseTopDecl+0x6fb>
    4378:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    437c:	48 8b 90 b0 00 00 00 	mov    0xb0(%rax),%rdx
    4383:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    4387:	be 06 00 00 00       	mov    $0x6,%esi
    438c:	48 89 c7             	mov    %rax,%rdi
    438f:	e8 3a de ff ff       	call   21ce <Node_init>
    4394:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    4398:	be 01 00 00 00       	mov    $0x1,%esi
    439d:	48 89 c7             	mov    %rax,%rdi
    43a0:	e8 bf ea ff ff       	call   2e64 <Parser_check>
    43a5:	84 c0                	test   %al,%al
    43a7:	74 2e                	je     43d7 <Parser_parseTopDecl+0x2e7>
    43a9:	48 8b 4d b0          	mov    -0x50(%rbp),%rcx
    43ad:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    43b1:	48 8b 50 50          	mov    0x50(%rax),%rdx
    43b5:	48 8b 40 48          	mov    0x48(%rax),%rax
    43b9:	48 89 41 08          	mov    %rax,0x8(%rcx)
    43bd:	48 89 51 10          	mov    %rdx,0x10(%rcx)
    43c1:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    43c5:	c6 40 18 01          	movb   $0x1,0x18(%rax)
    43c9:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    43cd:	48 89 c7             	mov    %rax,%rdi
    43d0:	e8 62 e9 ff ff       	call   2d37 <Parser_advance>
    43d5:	eb 5a                	jmp    4431 <Parser_parseTopDecl+0x341>
    43d7:	48 8d 35 79 5e 00 00 	lea    0x5e79(%rip),%rsi        # a257 <_IO_stdin_used+0x257>
    43de:	48 8b 7d 88          	mov    -0x78(%rbp),%rdi
    43e2:	48 83 ec 08          	sub    $0x8,%rsp
    43e6:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    43ea:	48 83 ec 38          	sub    $0x38,%rsp
    43ee:	48 89 e2             	mov    %rsp,%rdx
    43f1:	48 8b 48 40          	mov    0x40(%rax),%rcx
    43f5:	48 8b 58 48          	mov    0x48(%rax),%rbx
    43f9:	48 89 0a             	mov    %rcx,(%rdx)
    43fc:	48 89 5a 08          	mov    %rbx,0x8(%rdx)
    4400:	48 8b 48 50          	mov    0x50(%rax),%rcx
    4404:	48 8b 58 58          	mov    0x58(%rax),%rbx
    4408:	48 89 4a 10          	mov    %rcx,0x10(%rdx)
    440c:	48 89 5a 18          	mov    %rbx,0x18(%rdx)
    4410:	48 8b 48 60          	mov    0x60(%rax),%rcx
    4414:	48 8b 58 68          	mov    0x68(%rax),%rbx
    4418:	48 89 4a 20          	mov    %rcx,0x20(%rdx)
    441c:	48 89 5a 28          	mov    %rbx,0x28(%rdx)
    4420:	48 8b 40 70          	mov    0x70(%rax),%rax
    4424:	48 89 42 30          	mov    %rax,0x30(%rdx)
    4428:	e8 a0 ea ff ff       	call   2ecd <Parser_errorAt>
    442d:	48 83 c4 40          	add    $0x40,%rsp
    4431:	48 8d 15 33 5e 00 00 	lea    0x5e33(%rip),%rdx        # a26b <_IO_stdin_used+0x26b>
    4438:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    443c:	be 09 00 00 00       	mov    $0x9,%esi
    4441:	48 89 c7             	mov    %rax,%rdi
    4444:	e8 ce ea ff ff       	call   2f17 <Parser_expect>
    4449:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    444d:	be 02 00 00 00       	mov    $0x2,%esi
    4452:	48 89 c7             	mov    %rax,%rdi
    4455:	e8 0a ea ff ff       	call   2e64 <Parser_check>
    445a:	84 c0                	test   %al,%al
    445c:	74 2e                	je     448c <Parser_parseTopDecl+0x39c>
    445e:	48 8b 4d b0          	mov    -0x50(%rbp),%rcx
    4462:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    4466:	48 8b 50 50          	mov    0x50(%rax),%rdx
    446a:	48 8b 40 48          	mov    0x48(%rax),%rax
    446e:	48 89 41 38          	mov    %rax,0x38(%rcx)
    4472:	48 89 51 40          	mov    %rdx,0x40(%rcx)
    4476:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    447a:	c6 40 48 01          	movb   $0x1,0x48(%rax)
    447e:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    4482:	48 89 c7             	mov    %rax,%rdi
    4485:	e8 ad e8 ff ff       	call   2d37 <Parser_advance>
    448a:	eb 5a                	jmp    44e6 <Parser_parseTopDecl+0x3f6>
    448c:	48 8d 35 f5 5d 00 00 	lea    0x5df5(%rip),%rsi        # a288 <_IO_stdin_used+0x288>
    4493:	48 8b 7d 88          	mov    -0x78(%rbp),%rdi
    4497:	48 83 ec 08          	sub    $0x8,%rsp
    449b:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    449f:	48 83 ec 38          	sub    $0x38,%rsp
    44a3:	48 89 e2             	mov    %rsp,%rdx
    44a6:	48 8b 48 40          	mov    0x40(%rax),%rcx
    44aa:	48 8b 58 48          	mov    0x48(%rax),%rbx
    44ae:	48 89 0a             	mov    %rcx,(%rdx)
    44b1:	48 89 5a 08          	mov    %rbx,0x8(%rdx)
    44b5:	48 8b 48 50          	mov    0x50(%rax),%rcx
    44b9:	48 8b 58 58          	mov    0x58(%rax),%rbx
    44bd:	48 89 4a 10          	mov    %rcx,0x10(%rdx)
    44c1:	48 89 5a 18          	mov    %rbx,0x18(%rdx)
    44c5:	48 8b 48 60          	mov    0x60(%rax),%rcx
    44c9:	48 8b 58 68          	mov    0x68(%rax),%rbx
    44cd:	48 89 4a 20          	mov    %rcx,0x20(%rdx)
    44d1:	48 89 5a 28          	mov    %rbx,0x28(%rdx)
    44d5:	48 8b 40 70          	mov    0x70(%rax),%rax
    44d9:	48 89 42 30          	mov    %rax,0x30(%rdx)
    44dd:	e8 eb e9 ff ff       	call   2ecd <Parser_errorAt>
    44e2:	48 83 c4 40          	add    $0x40,%rsp
    44e6:	48 8d 15 bb 5d 00 00 	lea    0x5dbb(%rip),%rdx        # a2a8 <_IO_stdin_used+0x2a8>
    44ed:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    44f1:	be 0a 00 00 00       	mov    $0xa,%esi
    44f6:	48 89 c7             	mov    %rax,%rdi
    44f9:	e8 19 ea ff ff       	call   2f17 <Parser_expect>
    44fe:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    4502:	e9 e4 02 00 00       	jmp    47eb <Parser_parseTopDecl+0x6fb>
    4507:	48 8d 05 b1 5b 00 00 	lea    0x5bb1(%rip),%rax        # a0bf <_IO_stdin_used+0xbf>
    450e:	be 07 00 00 00       	mov    $0x7,%esi
    4513:	48 89 c7             	mov    %rax,%rdi
    4516:	e8 8d dc ff ff       	call   21a8 <mkSlice>
    451b:	48 89 c1             	mov    %rax,%rcx
    451e:	48 8d 45 c0          	lea    -0x40(%rbp),%rax
    4522:	48 89 ce             	mov    %rcx,%rsi
    4525:	48 89 c7             	mov    %rax,%rdi
    4528:	e8 70 cf ff ff       	call   149d <Slice_eq>
    452d:	84 c0                	test   %al,%al
    452f:	0f 84 0c 01 00 00    	je     4641 <Parser_parseTopDecl+0x551>
    4535:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    4539:	48 8b 80 b0 00 00 00 	mov    0xb0(%rax),%rax
    4540:	ba 08 00 00 00       	mov    $0x8,%edx
    4545:	be 98 00 00 00       	mov    $0x98,%esi
    454a:	48 89 c7             	mov    %rax,%rdi
    454d:	e8 7f cd ff ff       	call   12d1 <Arena_alloc>
    4552:	48 89 45 a8          	mov    %rax,-0x58(%rbp)
    4556:	48 83 7d a8 00       	cmpq   $0x0,-0x58(%rbp)
    455b:	75 0a                	jne    4567 <Parser_parseTopDecl+0x477>
    455d:	b8 00 00 00 00       	mov    $0x0,%eax
    4562:	e9 84 02 00 00       	jmp    47eb <Parser_parseTopDecl+0x6fb>
    4567:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    456b:	48 8b 90 b0 00 00 00 	mov    0xb0(%rax),%rdx
    4572:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    4576:	be 1b 00 00 00       	mov    $0x1b,%esi
    457b:	48 89 c7             	mov    %rax,%rdi
    457e:	e8 4b dc ff ff       	call   21ce <Node_init>
    4583:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    4587:	be 02 00 00 00       	mov    $0x2,%esi
    458c:	48 89 c7             	mov    %rax,%rdi
    458f:	e8 d0 e8 ff ff       	call   2e64 <Parser_check>
    4594:	84 c0                	test   %al,%al
    4596:	74 2e                	je     45c6 <Parser_parseTopDecl+0x4d6>
    4598:	48 8b 4d a8          	mov    -0x58(%rbp),%rcx
    459c:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    45a0:	48 8b 50 50          	mov    0x50(%rax),%rdx
    45a4:	48 8b 40 48          	mov    0x48(%rax),%rax
    45a8:	48 89 41 38          	mov    %rax,0x38(%rcx)
    45ac:	48 89 51 40          	mov    %rdx,0x40(%rcx)
    45b0:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    45b4:	c6 40 48 01          	movb   $0x1,0x48(%rax)
    45b8:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    45bc:	48 89 c7             	mov    %rax,%rdi
    45bf:	e8 73 e7 ff ff       	call   2d37 <Parser_advance>
    45c4:	eb 5a                	jmp    4620 <Parser_parseTopDecl+0x530>
    45c6:	48 8d 35 f3 5c 00 00 	lea    0x5cf3(%rip),%rsi        # a2c0 <_IO_stdin_used+0x2c0>
    45cd:	48 8b 7d 88          	mov    -0x78(%rbp),%rdi
    45d1:	48 83 ec 08          	sub    $0x8,%rsp
    45d5:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    45d9:	48 83 ec 38          	sub    $0x38,%rsp
    45dd:	48 89 e2             	mov    %rsp,%rdx
    45e0:	48 8b 48 40          	mov    0x40(%rax),%rcx
    45e4:	48 8b 58 48          	mov    0x48(%rax),%rbx
    45e8:	48 89 0a             	mov    %rcx,(%rdx)
    45eb:	48 89 5a 08          	mov    %rbx,0x8(%rdx)
    45ef:	48 8b 48 50          	mov    0x50(%rax),%rcx
    45f3:	48 8b 58 58          	mov    0x58(%rax),%rbx
    45f7:	48 89 4a 10          	mov    %rcx,0x10(%rdx)
    45fb:	48 89 5a 18          	mov    %rbx,0x18(%rdx)
    45ff:	48 8b 48 60          	mov    0x60(%rax),%rcx
    4603:	48 8b 58 68          	mov    0x68(%rax),%rbx
    4607:	48 89 4a 20          	mov    %rcx,0x20(%rdx)
    460b:	48 89 5a 28          	mov    %rbx,0x28(%rdx)
    460f:	48 8b 40 70          	mov    0x70(%rax),%rax
    4613:	48 89 42 30          	mov    %rax,0x30(%rdx)
    4617:	e8 b1 e8 ff ff       	call   2ecd <Parser_errorAt>
    461c:	48 83 c4 40          	add    $0x40,%rsp
    4620:	48 8d 15 b9 5c 00 00 	lea    0x5cb9(%rip),%rdx        # a2e0 <_IO_stdin_used+0x2e0>
    4627:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    462b:	be 0a 00 00 00       	mov    $0xa,%esi
    4630:	48 89 c7             	mov    %rax,%rdi
    4633:	e8 df e8 ff ff       	call   2f17 <Parser_expect>
    4638:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    463c:	e9 aa 01 00 00       	jmp    47eb <Parser_parseTopDecl+0x6fb>
    4641:	48 8d 4d d0          	lea    -0x30(%rbp),%rcx
    4645:	48 8b 75 c0          	mov    -0x40(%rbp),%rsi
    4649:	48 8b 55 c8          	mov    -0x38(%rbp),%rdx
    464d:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    4651:	48 89 c7             	mov    %rax,%rdi
    4654:	e8 5d ed ff ff       	call   33b6 <Parser_childKind>
    4659:	83 f0 01             	xor    $0x1,%eax
    465c:	84 c0                	test   %al,%al
    465e:	74 64                	je     46c4 <Parser_parseTopDecl+0x5d4>
    4660:	48 8d 35 92 5c 00 00 	lea    0x5c92(%rip),%rsi        # a2f9 <_IO_stdin_used+0x2f9>
    4667:	48 8b 7d 88          	mov    -0x78(%rbp),%rdi
    466b:	48 83 ec 08          	sub    $0x8,%rsp
    466f:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    4673:	48 83 ec 38          	sub    $0x38,%rsp
    4677:	48 89 e2             	mov    %rsp,%rdx
    467a:	48 8b 48 08          	mov    0x8(%rax),%rcx
    467e:	48 8b 58 10          	mov    0x10(%rax),%rbx
    4682:	48 89 0a             	mov    %rcx,(%rdx)
    4685:	48 89 5a 08          	mov    %rbx,0x8(%rdx)
    4689:	48 8b 48 18          	mov    0x18(%rax),%rcx
    468d:	48 8b 58 20          	mov    0x20(%rax),%rbx
    4691:	48 89 4a 10          	mov    %rcx,0x10(%rdx)
    4695:	48 89 5a 18          	mov    %rbx,0x18(%rdx)
    4699:	48 8b 48 28          	mov    0x28(%rax),%rcx
    469d:	48 8b 58 30          	mov    0x30(%rax),%rbx
    46a1:	48 89 4a 20          	mov    %rcx,0x20(%rdx)
    46a5:	48 89 5a 28          	mov    %rbx,0x28(%rdx)
    46a9:	48 8b 40 38          	mov    0x38(%rax),%rax
    46ad:	48 89 42 30          	mov    %rax,0x30(%rdx)
    46b1:	e8 17 e8 ff ff       	call   2ecd <Parser_errorAt>
    46b6:	48 83 c4 40          	add    $0x40,%rsp
    46ba:	b8 00 00 00 00       	mov    $0x0,%eax
    46bf:	e9 27 01 00 00       	jmp    47eb <Parser_parseTopDecl+0x6fb>
    46c4:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    46c8:	48 8b 80 b0 00 00 00 	mov    0xb0(%rax),%rax
    46cf:	ba 08 00 00 00       	mov    $0x8,%edx
    46d4:	be 98 00 00 00       	mov    $0x98,%esi
    46d9:	48 89 c7             	mov    %rax,%rdi
    46dc:	e8 f0 cb ff ff       	call   12d1 <Arena_alloc>
    46e1:	48 89 45 a0          	mov    %rax,-0x60(%rbp)
    46e5:	48 83 7d a0 00       	cmpq   $0x0,-0x60(%rbp)
    46ea:	75 0a                	jne    46f6 <Parser_parseTopDecl+0x606>
    46ec:	b8 00 00 00 00       	mov    $0x0,%eax
    46f1:	e9 f5 00 00 00       	jmp    47eb <Parser_parseTopDecl+0x6fb>
    46f6:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    46fa:	48 8b 90 b0 00 00 00 	mov    0xb0(%rax),%rdx
    4701:	8b 4d d0             	mov    -0x30(%rbp),%ecx
    4704:	48 8b 45 a0          	mov    -0x60(%rbp),%rax
    4708:	89 ce                	mov    %ecx,%esi
    470a:	48 89 c7             	mov    %rax,%rdi
    470d:	e8 bc da ff ff       	call   21ce <Node_init>
    4712:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    4716:	be 02 00 00 00       	mov    $0x2,%esi
    471b:	48 89 c7             	mov    %rax,%rdi
    471e:	e8 41 e7 ff ff       	call   2e64 <Parser_check>
    4723:	84 c0                	test   %al,%al
    4725:	74 2c                	je     4753 <Parser_parseTopDecl+0x663>
    4727:	48 8b 4d a0          	mov    -0x60(%rbp),%rcx
    472b:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    472f:	48 8b 50 50          	mov    0x50(%rax),%rdx
    4733:	48 8b 40 48          	mov    0x48(%rax),%rax
    4737:	48 89 41 08          	mov    %rax,0x8(%rcx)
    473b:	48 89 51 10          	mov    %rdx,0x10(%rcx)
    473f:	48 8b 45 a0          	mov    -0x60(%rbp),%rax
    4743:	c6 40 18 01          	movb   $0x1,0x18(%rax)
    4747:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    474b:	48 89 c7             	mov    %rax,%rdi
    474e:	e8 e4 e5 ff ff       	call   2d37 <Parser_advance>
    4753:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    4757:	be 01 00 00 00       	mov    $0x1,%esi
    475c:	48 89 c7             	mov    %rax,%rdi
    475f:	e8 00 e7 ff ff       	call   2e64 <Parser_check>
    4764:	84 c0                	test   %al,%al
    4766:	74 6c                	je     47d4 <Parser_parseTopDecl+0x6e4>
    4768:	48 8d 0d fb 59 00 00 	lea    0x59fb(%rip),%rcx        # a16a <_IO_stdin_used+0x16a>
    476f:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    4773:	ba 07 00 00 00       	mov    $0x7,%edx
    4778:	48 89 ce             	mov    %rcx,%rsi
    477b:	48 89 c7             	mov    %rax,%rdi
    477e:	e8 9c e8 ff ff       	call   301f <Parser_curIsWord>
    4783:	84 c0                	test   %al,%al
    4785:	74 4d                	je     47d4 <Parser_parseTopDecl+0x6e4>
    4787:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    478b:	48 89 c7             	mov    %rax,%rdi
    478e:	e8 a4 e5 ff ff       	call   2d37 <Parser_advance>
    4793:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    4797:	be 02 00 00 00       	mov    $0x2,%esi
    479c:	48 89 c7             	mov    %rax,%rdi
    479f:	e8 c0 e6 ff ff       	call   2e64 <Parser_check>
    47a4:	84 c0                	test   %al,%al
    47a6:	74 2c                	je     47d4 <Parser_parseTopDecl+0x6e4>
    47a8:	48 8b 4d a0          	mov    -0x60(%rbp),%rcx
    47ac:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    47b0:	48 8b 50 50          	mov    0x50(%rax),%rdx
    47b4:	48 8b 40 48          	mov    0x48(%rax),%rax
    47b8:	48 89 41 20          	mov    %rax,0x20(%rcx)
    47bc:	48 89 51 28          	mov    %rdx,0x28(%rcx)
    47c0:	48 8b 45 a0          	mov    -0x60(%rbp),%rax
    47c4:	c6 40 30 01          	movb   $0x1,0x30(%rax)
    47c8:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    47cc:	48 89 c7             	mov    %rax,%rdi
    47cf:	e8 63 e5 ff ff       	call   2d37 <Parser_advance>
    47d4:	48 8b 55 a0          	mov    -0x60(%rbp),%rdx
    47d8:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    47dc:	48 89 d6             	mov    %rdx,%rsi
    47df:	48 89 c7             	mov    %rax,%rdi
    47e2:	e8 04 f2 ff ff       	call   39eb <Parser_parseBlockInto>
    47e7:	48 8b 45 a0          	mov    -0x60(%rbp),%rax
    47eb:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    47ef:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
    47f6:	00 00 
    47f8:	74 05                	je     47ff <Parser_parseTopDecl+0x70f>
    47fa:	e8 81 c8 ff ff       	call   1080 <__stack_chk_fail@plt>
    47ff:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
    4803:	c9                   	leave
    4804:	c3                   	ret

0000000000004805 <Parser_parseFile>:
    4805:	55                   	push   %rbp
    4806:	48 89 e5             	mov    %rsp,%rbp
    4809:	48 83 ec 20          	sub    $0x20,%rsp
    480d:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    4811:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    4815:	48 8b 80 b0 00 00 00 	mov    0xb0(%rax),%rax
    481c:	ba 08 00 00 00       	mov    $0x8,%edx
    4821:	be 98 00 00 00       	mov    $0x98,%esi
    4826:	48 89 c7             	mov    %rax,%rdi
    4829:	e8 a3 ca ff ff       	call   12d1 <Arena_alloc>
    482e:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    4832:	48 83 7d f0 00       	cmpq   $0x0,-0x10(%rbp)
    4837:	75 0a                	jne    4843 <Parser_parseFile+0x3e>
    4839:	b8 00 00 00 00       	mov    $0x0,%eax
    483e:	e9 9c 00 00 00       	jmp    48df <Parser_parseFile+0xda>
    4843:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    4847:	48 8b 90 b0 00 00 00 	mov    0xb0(%rax),%rdx
    484e:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    4852:	be 00 00 00 00       	mov    $0x0,%esi
    4857:	48 89 c7             	mov    %rax,%rdi
    485a:	e8 6f d9 ff ff       	call   21ce <Node_init>
    485f:	eb 39                	jmp    489a <Parser_parseFile+0x95>
    4861:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    4865:	48 89 c7             	mov    %rax,%rdi
    4868:	e8 83 f8 ff ff       	call   40f0 <Parser_parseTopDecl>
    486d:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    4871:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    4876:	74 13                	je     488b <Parser_parseFile+0x86>
    4878:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
    487c:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    4880:	48 89 d6             	mov    %rdx,%rsi
    4883:	48 89 c7             	mov    %rax,%rdi
    4886:	e8 f0 db ff ff       	call   247b <Node_addChild>
    488b:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    488f:	8b 80 b8 00 00 00    	mov    0xb8(%rax),%eax
    4895:	83 f8 40             	cmp    $0x40,%eax
    4898:	77 1a                	ja     48b4 <Parser_parseFile+0xaf>
    489a:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    489e:	be 00 00 00 00       	mov    $0x0,%esi
    48a3:	48 89 c7             	mov    %rax,%rdi
    48a6:	e8 b9 e5 ff ff       	call   2e64 <Parser_check>
    48ab:	83 f0 01             	xor    $0x1,%eax
    48ae:	84 c0                	test   %al,%al
    48b0:	75 af                	jne    4861 <Parser_parseFile+0x5c>
    48b2:	eb 01                	jmp    48b5 <Parser_parseFile+0xb0>
    48b4:	90                   	nop
    48b5:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    48b9:	48 8b 00             	mov    (%rax),%rax
    48bc:	0f b6 40 28          	movzbl 0x28(%rax),%eax
    48c0:	84 c0                	test   %al,%al
    48c2:	74 17                	je     48db <Parser_parseFile+0xd6>
    48c4:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    48c8:	8b 80 b8 00 00 00    	mov    0xb8(%rax),%eax
    48ce:	8d 50 01             	lea    0x1(%rax),%edx
    48d1:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    48d5:	89 90 b8 00 00 00    	mov    %edx,0xb8(%rax)
    48db:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    48df:	c9                   	leave
    48e0:	c3                   	ret

00000000000048e1 <bEq>:
    48e1:	55                   	push   %rbp
    48e2:	48 89 e5             	mov    %rsp,%rbp
    48e5:	48 89 f8             	mov    %rdi,%rax
    48e8:	49 89 f0             	mov    %rsi,%r8
    48eb:	48 89 c6             	mov    %rax,%rsi
    48ee:	bf 00 00 00 00       	mov    $0x0,%edi
    48f3:	4c 89 c7             	mov    %r8,%rdi
    48f6:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    48fa:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    48fe:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    4902:	48 89 4d d0          	mov    %rcx,-0x30(%rbp)
    4906:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    490a:	48 39 45 d0          	cmp    %rax,-0x30(%rbp)
    490e:	74 07                	je     4917 <bEq+0x36>
    4910:	b8 00 00 00 00       	mov    $0x0,%eax
    4915:	eb 45                	jmp    495c <bEq+0x7b>
    4917:	48 c7 45 f8 00 00 00 	movq   $0x0,-0x8(%rbp)
    491e:	00 
    491f:	eb 2c                	jmp    494d <bEq+0x6c>
    4921:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    4925:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    4929:	48 01 d0             	add    %rdx,%rax
    492c:	0f b6 10             	movzbl (%rax),%edx
    492f:	48 8b 4d d8          	mov    -0x28(%rbp),%rcx
    4933:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    4937:	48 01 c8             	add    %rcx,%rax
    493a:	0f b6 00             	movzbl (%rax),%eax
    493d:	38 c2                	cmp    %al,%dl
    493f:	74 07                	je     4948 <bEq+0x67>
    4941:	b8 00 00 00 00       	mov    $0x0,%eax
    4946:	eb 14                	jmp    495c <bEq+0x7b>
    4948:	48 83 45 f8 01       	addq   $0x1,-0x8(%rbp)
    494d:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    4951:	48 3b 45 d0          	cmp    -0x30(%rbp),%rax
    4955:	72 ca                	jb     4921 <bEq+0x40>
    4957:	b8 01 00 00 00       	mov    $0x1,%eax
    495c:	5d                   	pop    %rbp
    495d:	c3                   	ret

000000000000495e <bEndsWith>:
    495e:	55                   	push   %rbp
    495f:	48 89 e5             	mov    %rsp,%rbp
    4962:	48 83 ec 20          	sub    $0x20,%rsp
    4966:	48 89 f8             	mov    %rdi,%rax
    4969:	49 89 f0             	mov    %rsi,%r8
    496c:	48 89 c6             	mov    %rax,%rsi
    496f:	bf 00 00 00 00       	mov    $0x0,%edi
    4974:	4c 89 c7             	mov    %r8,%rdi
    4977:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    497b:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    497f:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
    4983:	48 89 4d e0          	mov    %rcx,-0x20(%rbp)
    4987:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    498b:	48 3b 45 e0          	cmp    -0x20(%rbp),%rax
    498f:	73 07                	jae    4998 <bEndsWith+0x3a>
    4991:	b8 00 00 00 00       	mov    $0x0,%eax
    4996:	eb 37                	jmp    49cf <bEndsWith+0x71>
    4998:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
    499c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    49a0:	48 2b 45 e0          	sub    -0x20(%rbp),%rax
    49a4:	48 01 c2             	add    %rax,%rdx
    49a7:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    49ab:	48 89 c6             	mov    %rax,%rsi
    49ae:	48 89 d7             	mov    %rdx,%rdi
    49b1:	e8 cc ca ff ff       	call   1482 <Slice_from>
    49b6:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
    49ba:	48 8b 75 e8          	mov    -0x18(%rbp),%rsi
    49be:	48 89 c7             	mov    %rax,%rdi
    49c1:	48 89 d0             	mov    %rdx,%rax
    49c4:	48 89 f2             	mov    %rsi,%rdx
    49c7:	48 89 c6             	mov    %rax,%rsi
    49ca:	e8 12 ff ff ff       	call   48e1 <bEq>
    49cf:	c9                   	leave
    49d0:	c3                   	ret

00000000000049d1 <bCStr>:
    49d1:	55                   	push   %rbp
    49d2:	48 89 e5             	mov    %rsp,%rbp
    49d5:	48 83 ec 30          	sub    $0x30,%rsp
    49d9:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    49dd:	48 89 f0             	mov    %rsi,%rax
    49e0:	48 89 d1             	mov    %rdx,%rcx
    49e3:	48 89 c0             	mov    %rax,%rax
    49e6:	ba 00 00 00 00       	mov    $0x0,%edx
    49eb:	48 89 ca             	mov    %rcx,%rdx
    49ee:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
    49f2:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    49f6:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    49fa:	48 8d 48 01          	lea    0x1(%rax),%rcx
    49fe:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    4a02:	ba 01 00 00 00       	mov    $0x1,%edx
    4a07:	48 89 ce             	mov    %rcx,%rsi
    4a0a:	48 89 c7             	mov    %rax,%rdi
    4a0d:	e8 bf c8 ff ff       	call   12d1 <Arena_alloc>
    4a12:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    4a16:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    4a1b:	75 07                	jne    4a24 <bCStr+0x53>
    4a1d:	b8 00 00 00 00       	mov    $0x0,%eax
    4a22:	eb 29                	jmp    4a4d <bCStr+0x7c>
    4a24:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    4a28:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    4a2c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    4a30:	48 89 ce             	mov    %rcx,%rsi
    4a33:	48 89 c7             	mov    %rax,%rdi
    4a36:	e8 95 c6 ff ff       	call   10d0 <memcpy@plt>
    4a3b:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    4a3f:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    4a43:	48 01 d0             	add    %rdx,%rax
    4a46:	c6 00 00             	movb   $0x0,(%rax)
    4a49:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    4a4d:	c9                   	leave
    4a4e:	c3                   	ret

0000000000004a4f <bConcat3>:
    4a4f:	55                   	push   %rbp
    4a50:	48 89 e5             	mov    %rsp,%rbp
    4a53:	48 83 ec 40          	sub    $0x40,%rsp
    4a57:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    4a5b:	48 89 f0             	mov    %rsi,%rax
    4a5e:	48 89 d6             	mov    %rdx,%rsi
    4a61:	48 89 c0             	mov    %rax,%rax
    4a64:	ba 00 00 00 00       	mov    $0x0,%edx
    4a69:	48 89 f2             	mov    %rsi,%rdx
    4a6c:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
    4a70:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    4a74:	48 89 4d e0          	mov    %rcx,-0x20(%rbp)
    4a78:	4c 89 45 c8          	mov    %r8,-0x38(%rbp)
    4a7c:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    4a80:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    4a84:	48 01 c2             	add    %rax,%rdx
    4a87:	48 8b 45 18          	mov    0x18(%rbp),%rax
    4a8b:	48 01 d0             	add    %rdx,%rax
    4a8e:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    4a92:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    4a96:	48 8d 48 01          	lea    0x1(%rax),%rcx
    4a9a:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    4a9e:	ba 01 00 00 00       	mov    $0x1,%edx
    4aa3:	48 89 ce             	mov    %rcx,%rsi
    4aa6:	48 89 c7             	mov    %rax,%rdi
    4aa9:	e8 23 c8 ff ff       	call   12d1 <Arena_alloc>
    4aae:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    4ab2:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    4ab7:	75 07                	jne    4ac0 <bConcat3+0x71>
    4ab9:	b8 00 00 00 00       	mov    $0x0,%eax
    4abe:	eb 6d                	jmp    4b2d <bConcat3+0xde>
    4ac0:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    4ac4:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    4ac8:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    4acc:	48 89 ce             	mov    %rcx,%rsi
    4acf:	48 89 c7             	mov    %rax,%rdi
    4ad2:	e8 f9 c5 ff ff       	call   10d0 <memcpy@plt>
    4ad7:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    4adb:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    4adf:	48 8d 0c 02          	lea    (%rdx,%rax,1),%rcx
    4ae3:	48 8b 55 c8          	mov    -0x38(%rbp),%rdx
    4ae7:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    4aeb:	48 89 c6             	mov    %rax,%rsi
    4aee:	48 89 cf             	mov    %rcx,%rdi
    4af1:	e8 da c5 ff ff       	call   10d0 <memcpy@plt>
    4af6:	48 8b 55 18          	mov    0x18(%rbp),%rdx
    4afa:	48 8b 45 10          	mov    0x10(%rbp),%rax
    4afe:	48 8b 75 d8          	mov    -0x28(%rbp),%rsi
    4b02:	48 8b 4d c8          	mov    -0x38(%rbp),%rcx
    4b06:	48 01 ce             	add    %rcx,%rsi
    4b09:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
    4b0d:	48 01 f1             	add    %rsi,%rcx
    4b10:	48 89 c6             	mov    %rax,%rsi
    4b13:	48 89 cf             	mov    %rcx,%rdi
    4b16:	e8 b5 c5 ff ff       	call   10d0 <memcpy@plt>
    4b1b:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
    4b1f:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    4b23:	48 01 d0             	add    %rdx,%rax
    4b26:	c6 00 00             	movb   $0x0,(%rax)
    4b29:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    4b2d:	c9                   	leave
    4b2e:	c3                   	ret

0000000000004b2f <bJoin>:
    4b2f:	55                   	push   %rbp
    4b30:	48 89 e5             	mov    %rsp,%rbp
    4b33:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    4b37:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    4b3b:	48 89 55 d0          	mov    %rdx,-0x30(%rbp)
    4b3f:	48 89 4d d8          	mov    %rcx,-0x28(%rbp)
    4b43:	4c 89 45 c0          	mov    %r8,-0x40(%rbp)
    4b47:	4c 89 4d c8          	mov    %r9,-0x38(%rbp)
    4b4b:	48 c7 45 f0 00 00 00 	movq   $0x0,-0x10(%rbp)
    4b52:	00 
    4b53:	48 c7 45 f8 00 00 00 	movq   $0x0,-0x8(%rbp)
    4b5a:	00 
    4b5b:	eb 25                	jmp    4b82 <bJoin+0x53>
    4b5d:	48 8b 55 d0          	mov    -0x30(%rbp),%rdx
    4b61:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    4b65:	48 01 d0             	add    %rdx,%rax
    4b68:	48 8b 4d e8          	mov    -0x18(%rbp),%rcx
    4b6c:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
    4b70:	48 01 ca             	add    %rcx,%rdx
    4b73:	0f b6 00             	movzbl (%rax),%eax
    4b76:	88 02                	mov    %al,(%rdx)
    4b78:	48 83 45 f0 01       	addq   $0x1,-0x10(%rbp)
    4b7d:	48 83 45 f8 01       	addq   $0x1,-0x8(%rbp)
    4b82:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    4b86:	48 39 45 f8          	cmp    %rax,-0x8(%rbp)
    4b8a:	73 0e                	jae    4b9a <bJoin+0x6b>
    4b8c:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    4b90:	48 83 c0 01          	add    $0x1,%rax
    4b94:	48 3b 45 e0          	cmp    -0x20(%rbp),%rax
    4b98:	72 c3                	jb     4b5d <bJoin+0x2e>
    4b9a:	48 83 7d f0 00       	cmpq   $0x0,-0x10(%rbp)
    4b9f:	74 37                	je     4bd8 <bJoin+0xa9>
    4ba1:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    4ba5:	48 8d 50 ff          	lea    -0x1(%rax),%rdx
    4ba9:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    4bad:	48 01 d0             	add    %rdx,%rax
    4bb0:	0f b6 00             	movzbl (%rax),%eax
    4bb3:	3c 2f                	cmp    $0x2f,%al
    4bb5:	74 21                	je     4bd8 <bJoin+0xa9>
    4bb7:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    4bbb:	48 83 c0 01          	add    $0x1,%rax
    4bbf:	48 3b 45 e0          	cmp    -0x20(%rbp),%rax
    4bc3:	73 13                	jae    4bd8 <bJoin+0xa9>
    4bc5:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    4bc9:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    4bcd:	48 01 d0             	add    %rdx,%rax
    4bd0:	c6 00 2f             	movb   $0x2f,(%rax)
    4bd3:	48 83 45 f0 01       	addq   $0x1,-0x10(%rbp)
    4bd8:	48 c7 45 f8 00 00 00 	movq   $0x0,-0x8(%rbp)
    4bdf:	00 
    4be0:	eb 25                	jmp    4c07 <bJoin+0xd8>
    4be2:	48 8b 55 c0          	mov    -0x40(%rbp),%rdx
    4be6:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    4bea:	48 01 d0             	add    %rdx,%rax
    4bed:	48 8b 4d e8          	mov    -0x18(%rbp),%rcx
    4bf1:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
    4bf5:	48 01 ca             	add    %rcx,%rdx
    4bf8:	0f b6 00             	movzbl (%rax),%eax
    4bfb:	88 02                	mov    %al,(%rdx)
    4bfd:	48 83 45 f0 01       	addq   $0x1,-0x10(%rbp)
    4c02:	48 83 45 f8 01       	addq   $0x1,-0x8(%rbp)
    4c07:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    4c0b:	48 39 45 f8          	cmp    %rax,-0x8(%rbp)
    4c0f:	73 0e                	jae    4c1f <bJoin+0xf0>
    4c11:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    4c15:	48 83 c0 01          	add    $0x1,%rax
    4c19:	48 3b 45 e0          	cmp    -0x20(%rbp),%rax
    4c1d:	72 c3                	jb     4be2 <bJoin+0xb3>
    4c1f:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    4c23:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    4c27:	48 01 d0             	add    %rdx,%rax
    4c2a:	c6 00 00             	movb   $0x0,(%rax)
    4c2d:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    4c31:	5d                   	pop    %rbp
    4c32:	c3                   	ret

0000000000004c33 <bFnv>:
    4c33:	55                   	push   %rbp
    4c34:	48 89 e5             	mov    %rsp,%rbp
    4c37:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    4c3b:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    4c3f:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    4c43:	48 c7 45 f8 00 00 00 	movq   $0x0,-0x8(%rbp)
    4c4a:	00 
    4c4b:	eb 30                	jmp    4c7d <bFnv+0x4a>
    4c4d:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    4c51:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    4c55:	48 01 d0             	add    %rdx,%rax
    4c58:	0f b6 00             	movzbl (%rax),%eax
    4c5b:	0f b6 c0             	movzbl %al,%eax
    4c5e:	48 31 45 e8          	xor    %rax,-0x18(%rbp)
    4c62:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    4c66:	48 ba b3 01 00 00 00 	movabs $0x100000001b3,%rdx
    4c6d:	01 00 00 
    4c70:	48 0f af c2          	imul   %rdx,%rax
    4c74:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    4c78:	48 83 45 f8 01       	addq   $0x1,-0x8(%rbp)
    4c7d:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    4c81:	48 3b 45 d8          	cmp    -0x28(%rbp),%rax
    4c85:	72 c6                	jb     4c4d <bFnv+0x1a>
    4c87:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    4c8b:	5d                   	pop    %rbp
    4c8c:	c3                   	ret

0000000000004c8d <bApp>:
    4c8d:	55                   	push   %rbp
    4c8e:	48 89 e5             	mov    %rsp,%rbp
    4c91:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    4c95:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    4c99:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    4c9d:	48 89 4d d0          	mov    %rcx,-0x30(%rbp)
    4ca1:	4c 89 45 c8          	mov    %r8,-0x38(%rbp)
    4ca5:	48 c7 45 f8 00 00 00 	movq   $0x0,-0x8(%rbp)
    4cac:	00 
    4cad:	eb 36                	jmp    4ce5 <bApp+0x58>
    4caf:	48 8b 55 d0          	mov    -0x30(%rbp),%rdx
    4cb3:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    4cb7:	48 8d 0c 02          	lea    (%rdx,%rax,1),%rcx
    4cbb:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    4cbf:	48 8b 10             	mov    (%rax),%rdx
    4cc2:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    4cc6:	48 01 c2             	add    %rax,%rdx
    4cc9:	0f b6 01             	movzbl (%rcx),%eax
    4ccc:	88 02                	mov    %al,(%rdx)
    4cce:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    4cd2:	48 8b 00             	mov    (%rax),%rax
    4cd5:	48 8d 50 01          	lea    0x1(%rax),%rdx
    4cd9:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    4cdd:	48 89 10             	mov    %rdx,(%rax)
    4ce0:	48 83 45 f8 01       	addq   $0x1,-0x8(%rbp)
    4ce5:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    4ce9:	48 3b 45 c8          	cmp    -0x38(%rbp),%rax
    4ced:	73 0d                	jae    4cfc <bApp+0x6f>
    4cef:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    4cf3:	48 8b 00             	mov    (%rax),%rax
    4cf6:	48 3b 45 e0          	cmp    -0x20(%rbp),%rax
    4cfa:	72 b3                	jb     4caf <bApp+0x22>
    4cfc:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    4d00:	48 8b 00             	mov    (%rax),%rax
    4d03:	5d                   	pop    %rbp
    4d04:	c3                   	ret

0000000000004d05 <bFileExists>:
    4d05:	55                   	push   %rbp
    4d06:	48 89 e5             	mov    %rsp,%rbp
    4d09:	48 83 ec 20          	sub    $0x20,%rsp
    4d0d:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    4d11:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    4d15:	ba 00 00 00 00       	mov    $0x0,%edx
    4d1a:	be 00 00 00 00       	mov    $0x0,%esi
    4d1f:	48 89 c7             	mov    %rax,%rdi
    4d22:	e8 d9 c3 ff ff       	call   1100 <open@plt>
    4d27:	89 45 fc             	mov    %eax,-0x4(%rbp)
    4d2a:	83 7d fc 00          	cmpl   $0x0,-0x4(%rbp)
    4d2e:	79 07                	jns    4d37 <bFileExists+0x32>
    4d30:	b8 00 00 00 00       	mov    $0x0,%eax
    4d35:	eb 0f                	jmp    4d46 <bFileExists+0x41>
    4d37:	8b 45 fc             	mov    -0x4(%rbp),%eax
    4d3a:	89 c7                	mov    %eax,%edi
    4d3c:	e8 5f c3 ff ff       	call   10a0 <close@plt>
    4d41:	b8 01 00 00 00       	mov    $0x1,%eax
    4d46:	c9                   	leave
    4d47:	c3                   	ret

0000000000004d48 <bReadFile>:
    4d48:	55                   	push   %rbp
    4d49:	48 89 e5             	mov    %rsp,%rbp
    4d4c:	48 83 ec 50          	sub    $0x50,%rsp
    4d50:	48 89 7d c8          	mov    %rdi,-0x38(%rbp)
    4d54:	48 89 75 c0          	mov    %rsi,-0x40(%rbp)
    4d58:	48 89 55 b8          	mov    %rdx,-0x48(%rbp)
    4d5c:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    4d60:	48 c7 00 00 00 00 00 	movq   $0x0,(%rax)
    4d67:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
    4d6b:	ba 00 00 00 00       	mov    $0x0,%edx
    4d70:	be 00 00 00 00       	mov    $0x0,%esi
    4d75:	48 89 c7             	mov    %rax,%rdi
    4d78:	e8 83 c3 ff ff       	call   1100 <open@plt>
    4d7d:	89 45 d0             	mov    %eax,-0x30(%rbp)
    4d80:	83 7d d0 00          	cmpl   $0x0,-0x30(%rbp)
    4d84:	79 14                	jns    4d9a <bReadFile+0x52>
    4d86:	be 00 00 00 00       	mov    $0x0,%esi
    4d8b:	bf 00 00 00 00       	mov    $0x0,%edi
    4d90:	e8 ed c6 ff ff       	call   1482 <Slice_from>
    4d95:	e9 55 01 00 00       	jmp    4eef <bReadFile+0x1a7>
    4d9a:	48 c7 45 d8 00 00 01 	movq   $0x10000,-0x28(%rbp)
    4da1:	00 
    4da2:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    4da6:	48 89 c7             	mov    %rax,%rdi
    4da9:	e8 32 c3 ff ff       	call   10e0 <malloc@plt>
    4dae:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    4db2:	48 83 7d e0 00       	cmpq   $0x0,-0x20(%rbp)
    4db7:	75 1e                	jne    4dd7 <bReadFile+0x8f>
    4db9:	8b 45 d0             	mov    -0x30(%rbp),%eax
    4dbc:	89 c7                	mov    %eax,%edi
    4dbe:	e8 dd c2 ff ff       	call   10a0 <close@plt>
    4dc3:	be 00 00 00 00       	mov    $0x0,%esi
    4dc8:	bf 00 00 00 00       	mov    $0x0,%edi
    4dcd:	e8 b0 c6 ff ff       	call   1482 <Slice_from>
    4dd2:	e9 18 01 00 00       	jmp    4eef <bReadFile+0x1a7>
    4dd7:	48 c7 45 e8 00 00 00 	movq   $0x0,-0x18(%rbp)
    4dde:	00 
    4ddf:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    4de3:	48 3b 45 d8          	cmp    -0x28(%rbp),%rax
    4de7:	72 2e                	jb     4e17 <bReadFile+0xcf>
    4de9:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    4ded:	48 8d 14 00          	lea    (%rax,%rax,1),%rdx
    4df1:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    4df5:	48 89 d6             	mov    %rdx,%rsi
    4df8:	48 89 c7             	mov    %rax,%rdi
    4dfb:	e8 f0 c2 ff ff       	call   10f0 <realloc@plt>
    4e00:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    4e04:	48 83 7d f0 00       	cmpq   $0x0,-0x10(%rbp)
    4e09:	74 43                	je     4e4e <bReadFile+0x106>
    4e0b:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    4e0f:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    4e13:	48 d1 65 d8          	shlq   $1,-0x28(%rbp)
    4e17:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    4e1b:	48 2b 45 e8          	sub    -0x18(%rbp),%rax
    4e1f:	48 89 c2             	mov    %rax,%rdx
    4e22:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
    4e26:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    4e2a:	48 01 c1             	add    %rax,%rcx
    4e2d:	8b 45 d0             	mov    -0x30(%rbp),%eax
    4e30:	48 89 ce             	mov    %rcx,%rsi
    4e33:	89 c7                	mov    %eax,%edi
    4e35:	e8 76 c2 ff ff       	call   10b0 <read@plt>
    4e3a:	89 45 d4             	mov    %eax,-0x2c(%rbp)
    4e3d:	83 7d d4 00          	cmpl   $0x0,-0x2c(%rbp)
    4e41:	7e 0e                	jle    4e51 <bReadFile+0x109>
    4e43:	8b 45 d4             	mov    -0x2c(%rbp),%eax
    4e46:	48 98                	cltq
    4e48:	48 01 45 e8          	add    %rax,-0x18(%rbp)
    4e4c:	eb 91                	jmp    4ddf <bReadFile+0x97>
    4e4e:	90                   	nop
    4e4f:	eb 01                	jmp    4e52 <bReadFile+0x10a>
    4e51:	90                   	nop
    4e52:	8b 45 d0             	mov    -0x30(%rbp),%eax
    4e55:	89 c7                	mov    %eax,%edi
    4e57:	e8 44 c2 ff ff       	call   10a0 <close@plt>
    4e5c:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    4e60:	48 8d 48 01          	lea    0x1(%rax),%rcx
    4e64:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    4e68:	ba 01 00 00 00       	mov    $0x1,%edx
    4e6d:	48 89 ce             	mov    %rcx,%rsi
    4e70:	48 89 c7             	mov    %rax,%rdi
    4e73:	e8 59 c4 ff ff       	call   12d1 <Arena_alloc>
    4e78:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    4e7c:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    4e81:	75 1d                	jne    4ea0 <bReadFile+0x158>
    4e83:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    4e87:	48 89 c7             	mov    %rax,%rdi
    4e8a:	e8 a1 c1 ff ff       	call   1030 <free@plt>
    4e8f:	be 00 00 00 00       	mov    $0x0,%esi
    4e94:	bf 00 00 00 00       	mov    $0x0,%edi
    4e99:	e8 e4 c5 ff ff       	call   1482 <Slice_from>
    4e9e:	eb 4f                	jmp    4eef <bReadFile+0x1a7>
    4ea0:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    4ea4:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
    4ea8:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    4eac:	48 89 ce             	mov    %rcx,%rsi
    4eaf:	48 89 c7             	mov    %rax,%rdi
    4eb2:	e8 19 c2 ff ff       	call   10d0 <memcpy@plt>
    4eb7:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
    4ebb:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    4ebf:	48 01 d0             	add    %rdx,%rax
    4ec2:	c6 00 00             	movb   $0x0,(%rax)
    4ec5:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    4ec9:	48 89 c7             	mov    %rax,%rdi
    4ecc:	e8 5f c1 ff ff       	call   1030 <free@plt>
    4ed1:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    4ed5:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    4ed9:	48 89 10             	mov    %rdx,(%rax)
    4edc:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    4ee0:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    4ee4:	48 89 d6             	mov    %rdx,%rsi
    4ee7:	48 89 c7             	mov    %rax,%rdi
    4eea:	e8 93 c5 ff ff       	call   1482 <Slice_from>
    4eef:	c9                   	leave
    4ef0:	c3                   	ret

0000000000004ef1 <bListDir>:
    4ef1:	55                   	push   %rbp
    4ef2:	48 89 e5             	mov    %rsp,%rbp
    4ef5:	48 83 ec 70          	sub    $0x70,%rsp
    4ef9:	48 89 7d a8          	mov    %rdi,-0x58(%rbp)
    4efd:	48 89 75 a0          	mov    %rsi,-0x60(%rbp)
    4f01:	48 89 55 98          	mov    %rdx,-0x68(%rbp)
    4f05:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    4f09:	c7 00 00 00 00 00    	movl   $0x0,(%rax)
    4f0f:	48 8b 45 a0          	mov    -0x60(%rbp),%rax
    4f13:	ba 00 00 00 00       	mov    $0x0,%edx
    4f18:	be 00 00 00 00       	mov    $0x0,%esi
    4f1d:	48 89 c7             	mov    %rax,%rdi
    4f20:	e8 db c1 ff ff       	call   1100 <open@plt>
    4f25:	89 45 c0             	mov    %eax,-0x40(%rbp)
    4f28:	83 7d c0 00          	cmpl   $0x0,-0x40(%rbp)
    4f2c:	79 0a                	jns    4f38 <bListDir+0x47>
    4f2e:	b8 00 00 00 00       	mov    $0x0,%eax
    4f33:	e9 9b 02 00 00       	jmp    51d3 <bListDir+0x2e2>
    4f38:	bf 00 00 01 00       	mov    $0x10000,%edi
    4f3d:	e8 9e c1 ff ff       	call   10e0 <malloc@plt>
    4f42:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    4f46:	48 83 7d e0 00       	cmpq   $0x0,-0x20(%rbp)
    4f4b:	75 14                	jne    4f61 <bListDir+0x70>
    4f4d:	8b 45 c0             	mov    -0x40(%rbp),%eax
    4f50:	89 c7                	mov    %eax,%edi
    4f52:	e8 49 c1 ff ff       	call   10a0 <close@plt>
    4f57:	b8 00 00 00 00       	mov    $0x0,%eax
    4f5c:	e9 72 02 00 00       	jmp    51d3 <bListDir+0x2e2>
    4f61:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    4f65:	ba 08 00 00 00       	mov    $0x8,%edx
    4f6a:	be 00 04 00 00       	mov    $0x400,%esi
    4f6f:	48 89 c7             	mov    %rax,%rdi
    4f72:	e8 5a c3 ff ff       	call   12d1 <Arena_alloc>
    4f77:	48 89 45 c8          	mov    %rax,-0x38(%rbp)
    4f7b:	c7 45 b4 40 00 00 00 	movl   $0x40,-0x4c(%rbp)
    4f82:	48 83 7d c8 00       	cmpq   $0x0,-0x38(%rbp)
    4f87:	75 20                	jne    4fa9 <bListDir+0xb8>
    4f89:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    4f8d:	48 89 c7             	mov    %rax,%rdi
    4f90:	e8 9b c0 ff ff       	call   1030 <free@plt>
    4f95:	8b 45 c0             	mov    -0x40(%rbp),%eax
    4f98:	89 c7                	mov    %eax,%edi
    4f9a:	e8 01 c1 ff ff       	call   10a0 <close@plt>
    4f9f:	b8 00 00 00 00       	mov    $0x0,%eax
    4fa4:	e9 2a 02 00 00       	jmp    51d3 <bListDir+0x2e2>
    4fa9:	c7 45 b8 00 00 00 00 	movl   $0x0,-0x48(%rbp)
    4fb0:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    4fb4:	8b 45 c0             	mov    -0x40(%rbp),%eax
    4fb7:	b9 00 00 01 00       	mov    $0x10000,%ecx
    4fbc:	89 c6                	mov    %eax,%esi
    4fbe:	bf d9 00 00 00       	mov    $0xd9,%edi
    4fc3:	b8 00 00 00 00       	mov    $0x0,%eax
    4fc8:	e8 f3 c0 ff ff       	call   10c0 <syscall@plt>
    4fcd:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    4fd1:	48 83 7d e8 00       	cmpq   $0x0,-0x18(%rbp)
    4fd6:	0f 8e d3 01 00 00    	jle    51af <bListDir+0x2be>
    4fdc:	48 c7 45 d0 00 00 00 	movq   $0x0,-0x30(%rbp)
    4fe3:	00 
    4fe4:	e9 a7 01 00 00       	jmp    5190 <bListDir+0x29f>
    4fe9:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    4fed:	48 8d 50 10          	lea    0x10(%rax),%rdx
    4ff1:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    4ff5:	48 01 d0             	add    %rdx,%rax
    4ff8:	0f b6 00             	movzbl (%rax),%eax
    4ffb:	0f b6 c8             	movzbl %al,%ecx
    4ffe:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    5002:	48 8d 50 11          	lea    0x11(%rax),%rdx
    5006:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    500a:	48 01 d0             	add    %rdx,%rax
    500d:	0f b6 00             	movzbl (%rax),%eax
    5010:	0f b6 c0             	movzbl %al,%eax
    5013:	c1 e0 08             	shl    $0x8,%eax
    5016:	09 c8                	or     %ecx,%eax
    5018:	66 89 45 b2          	mov    %ax,-0x4e(%rbp)
    501c:	66 83 7d b2 00       	cmpw   $0x0,-0x4e(%rbp)
    5021:	0f 84 7c 01 00 00    	je     51a3 <bListDir+0x2b2>
    5027:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    502b:	48 8d 50 12          	lea    0x12(%rax),%rdx
    502f:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    5033:	48 01 d0             	add    %rdx,%rax
    5036:	0f b6 00             	movzbl (%rax),%eax
    5039:	88 45 b1             	mov    %al,-0x4f(%rbp)
    503c:	48 c7 45 d8 00 00 00 	movq   $0x0,-0x28(%rbp)
    5043:	00 
    5044:	eb 05                	jmp    504b <bListDir+0x15a>
    5046:	48 83 45 d8 01       	addq   $0x1,-0x28(%rbp)
    504b:	48 81 7d d8 fe 00 00 	cmpq   $0xfe,-0x28(%rbp)
    5052:	00 
    5053:	77 1d                	ja     5072 <bListDir+0x181>
    5055:	48 8b 55 d0          	mov    -0x30(%rbp),%rdx
    5059:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    505d:	48 01 d0             	add    %rdx,%rax
    5060:	48 8d 50 13          	lea    0x13(%rax),%rdx
    5064:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    5068:	48 01 d0             	add    %rdx,%rax
    506b:	0f b6 00             	movzbl (%rax),%eax
    506e:	84 c0                	test   %al,%al
    5070:	75 d4                	jne    5046 <bListDir+0x155>
    5072:	8b 45 b8             	mov    -0x48(%rbp),%eax
    5075:	3b 45 b4             	cmp    -0x4c(%rbp),%eax
    5078:	0f 82 85 00 00 00    	jb     5103 <bListDir+0x212>
    507e:	8b 45 b4             	mov    -0x4c(%rbp),%eax
    5081:	01 c0                	add    %eax,%eax
    5083:	89 45 c4             	mov    %eax,-0x3c(%rbp)
    5086:	8b 45 c4             	mov    -0x3c(%rbp),%eax
    5089:	48 c1 e0 04          	shl    $0x4,%rax
    508d:	48 89 c1             	mov    %rax,%rcx
    5090:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    5094:	ba 08 00 00 00       	mov    $0x8,%edx
    5099:	48 89 ce             	mov    %rcx,%rsi
    509c:	48 89 c7             	mov    %rax,%rdi
    509f:	e8 2d c2 ff ff       	call   12d1 <Arena_alloc>
    50a4:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    50a8:	48 83 7d f0 00       	cmpq   $0x0,-0x10(%rbp)
    50ad:	0f 84 f6 00 00 00    	je     51a9 <bListDir+0x2b8>
    50b3:	c7 45 bc 00 00 00 00 	movl   $0x0,-0x44(%rbp)
    50ba:	eb 34                	jmp    50f0 <bListDir+0x1ff>
    50bc:	8b 45 bc             	mov    -0x44(%rbp),%eax
    50bf:	48 c1 e0 04          	shl    $0x4,%rax
    50c3:	48 89 c2             	mov    %rax,%rdx
    50c6:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    50ca:	48 01 d0             	add    %rdx,%rax
    50cd:	8b 55 bc             	mov    -0x44(%rbp),%edx
    50d0:	48 89 d1             	mov    %rdx,%rcx
    50d3:	48 c1 e1 04          	shl    $0x4,%rcx
    50d7:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
    50db:	48 01 d1             	add    %rdx,%rcx
    50de:	48 8b 50 08          	mov    0x8(%rax),%rdx
    50e2:	48 8b 00             	mov    (%rax),%rax
    50e5:	48 89 01             	mov    %rax,(%rcx)
    50e8:	48 89 51 08          	mov    %rdx,0x8(%rcx)
    50ec:	83 45 bc 01          	addl   $0x1,-0x44(%rbp)
    50f0:	8b 45 bc             	mov    -0x44(%rbp),%eax
    50f3:	3b 45 b8             	cmp    -0x48(%rbp),%eax
    50f6:	72 c4                	jb     50bc <bListDir+0x1cb>
    50f8:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    50fc:	48 89 45 c8          	mov    %rax,-0x38(%rbp)
    5100:	d1 65 b4             	shll   $1,-0x4c(%rbp)
    5103:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    5107:	48 8d 48 01          	lea    0x1(%rax),%rcx
    510b:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    510f:	ba 01 00 00 00       	mov    $0x1,%edx
    5114:	48 89 ce             	mov    %rcx,%rsi
    5117:	48 89 c7             	mov    %rax,%rdi
    511a:	e8 b2 c1 ff ff       	call   12d1 <Arena_alloc>
    511f:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    5123:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    5127:	48 8d 50 13          	lea    0x13(%rax),%rdx
    512b:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    512f:	48 8d 0c 02          	lea    (%rdx,%rax,1),%rcx
    5133:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    5137:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    513b:	48 89 ce             	mov    %rcx,%rsi
    513e:	48 89 c7             	mov    %rax,%rdi
    5141:	e8 8a bf ff ff       	call   10d0 <memcpy@plt>
    5146:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
    514a:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    514e:	48 01 d0             	add    %rdx,%rax
    5151:	c6 00 00             	movb   $0x0,(%rax)
    5154:	8b 45 b8             	mov    -0x48(%rbp),%eax
    5157:	48 c1 e0 04          	shl    $0x4,%rax
    515b:	48 89 c2             	mov    %rax,%rdx
    515e:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    5162:	48 01 c2             	add    %rax,%rdx
    5165:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    5169:	48 89 02             	mov    %rax,(%rdx)
    516c:	8b 45 b8             	mov    -0x48(%rbp),%eax
    516f:	48 c1 e0 04          	shl    $0x4,%rax
    5173:	48 89 c2             	mov    %rax,%rdx
    5176:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    517a:	48 01 c2             	add    %rax,%rdx
    517d:	0f b6 45 b1          	movzbl -0x4f(%rbp),%eax
    5181:	88 42 08             	mov    %al,0x8(%rdx)
    5184:	83 45 b8 01          	addl   $0x1,-0x48(%rbp)
    5188:	0f b7 45 b2          	movzwl -0x4e(%rbp),%eax
    518c:	48 01 45 d0          	add    %rax,-0x30(%rbp)
    5190:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    5194:	48 3b 45 e8          	cmp    -0x18(%rbp),%rax
    5198:	0f 8c 4b fe ff ff    	jl     4fe9 <bListDir+0xf8>
    519e:	e9 0d fe ff ff       	jmp    4fb0 <bListDir+0xbf>
    51a3:	90                   	nop
    51a4:	e9 07 fe ff ff       	jmp    4fb0 <bListDir+0xbf>
    51a9:	90                   	nop
    51aa:	e9 01 fe ff ff       	jmp    4fb0 <bListDir+0xbf>
    51af:	90                   	nop
    51b0:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    51b4:	48 89 c7             	mov    %rax,%rdi
    51b7:	e8 74 be ff ff       	call   1030 <free@plt>
    51bc:	8b 45 c0             	mov    -0x40(%rbp),%eax
    51bf:	89 c7                	mov    %eax,%edi
    51c1:	e8 da be ff ff       	call   10a0 <close@plt>
    51c6:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    51ca:	8b 55 b8             	mov    -0x48(%rbp),%edx
    51cd:	89 10                	mov    %edx,(%rax)
    51cf:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    51d3:	c9                   	leave
    51d4:	c3                   	ret

00000000000051d5 <bIsSkipped>:
    51d5:	55                   	push   %rbp
    51d6:	48 89 e5             	mov    %rsp,%rbp
    51d9:	48 83 ec 30          	sub    $0x30,%rsp
    51dd:	48 89 f8             	mov    %rdi,%rax
    51e0:	49 89 f0             	mov    %rsi,%r8
    51e3:	48 89 c6             	mov    %rax,%rsi
    51e6:	bf 00 00 00 00       	mov    $0x0,%edi
    51eb:	4c 89 c7             	mov    %r8,%rdi
    51ee:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    51f2:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    51f6:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    51fa:	89 4d d4             	mov    %ecx,-0x2c(%rbp)
    51fd:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
    5204:	eb 4b                	jmp    5251 <bIsSkipped+0x7c>
    5206:	8b 45 fc             	mov    -0x4(%rbp),%eax
    5209:	48 c1 e0 04          	shl    $0x4,%rax
    520d:	48 89 c2             	mov    %rax,%rdx
    5210:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    5214:	48 01 d0             	add    %rdx,%rax
    5217:	48 8b 48 08          	mov    0x8(%rax),%rcx
    521b:	8b 45 fc             	mov    -0x4(%rbp),%eax
    521e:	48 c1 e0 04          	shl    $0x4,%rax
    5222:	48 89 c2             	mov    %rax,%rdx
    5225:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    5229:	48 01 d0             	add    %rdx,%rax
    522c:	48 8b 10             	mov    (%rax),%rdx
    522f:	48 8b 75 e0          	mov    -0x20(%rbp),%rsi
    5233:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    5237:	48 89 f7             	mov    %rsi,%rdi
    523a:	48 89 c6             	mov    %rax,%rsi
    523d:	e8 9f f6 ff ff       	call   48e1 <bEq>
    5242:	84 c0                	test   %al,%al
    5244:	74 07                	je     524d <bIsSkipped+0x78>
    5246:	b8 01 00 00 00       	mov    $0x1,%eax
    524b:	eb 11                	jmp    525e <bIsSkipped+0x89>
    524d:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
    5251:	8b 45 fc             	mov    -0x4(%rbp),%eax
    5254:	3b 45 d4             	cmp    -0x2c(%rbp),%eax
    5257:	72 ad                	jb     5206 <bIsSkipped+0x31>
    5259:	b8 00 00 00 00       	mov    $0x0,%eax
    525e:	c9                   	leave
    525f:	c3                   	ret

0000000000005260 <bCollectCrl>:
    5260:	55                   	push   %rbp
    5261:	48 89 e5             	mov    %rsp,%rbp
    5264:	53                   	push   %rbx
    5265:	48 81 ec 98 00 00 00 	sub    $0x98,%rsp
    526c:	48 89 7d 98          	mov    %rdi,-0x68(%rbp)
    5270:	48 89 75 90          	mov    %rsi,-0x70(%rbp)
    5274:	48 89 55 80          	mov    %rdx,-0x80(%rbp)
    5278:	48 89 4d 88          	mov    %rcx,-0x78(%rbp)
    527c:	4c 89 85 78 ff ff ff 	mov    %r8,-0x88(%rbp)
    5283:	44 89 8d 74 ff ff ff 	mov    %r9d,-0x8c(%rbp)
    528a:	48 8b 45 10          	mov    0x10(%rbp),%rax
    528e:	48 89 85 68 ff ff ff 	mov    %rax,-0x98(%rbp)
    5295:	48 8b 45 20          	mov    0x20(%rbp),%rax
    5299:	48 89 85 60 ff ff ff 	mov    %rax,-0xa0(%rbp)
    52a0:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    52a7:	00 00 
    52a9:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    52ad:	31 c0                	xor    %eax,%eax
    52af:	48 c7 45 a8 00 00 00 	movq   $0x0,-0x58(%rbp)
    52b6:	00 
    52b7:	c7 45 a0 00 00 00 00 	movl   $0x0,-0x60(%rbp)
    52be:	48 8d 55 a0          	lea    -0x60(%rbp),%rdx
    52c2:	48 8b 4d 90          	mov    -0x70(%rbp),%rcx
    52c6:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    52ca:	48 89 ce             	mov    %rcx,%rsi
    52cd:	48 89 c7             	mov    %rax,%rdi
    52d0:	e8 1c fc ff ff       	call   4ef1 <bListDir>
    52d5:	48 89 45 a8          	mov    %rax,-0x58(%rbp)
    52d9:	c7 45 a4 00 00 00 00 	movl   $0x0,-0x5c(%rbp)
    52e0:	e9 7a 02 00 00       	jmp    555f <bCollectCrl+0x2ff>
    52e5:	8b 45 a4             	mov    -0x5c(%rbp),%eax
    52e8:	48 c1 e0 04          	shl    $0x4,%rax
    52ec:	48 89 c2             	mov    %rax,%rdx
    52ef:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    52f3:	48 01 d0             	add    %rdx,%rax
    52f6:	48 8b 00             	mov    (%rax),%rax
    52f9:	48 89 c7             	mov    %rax,%rdi
    52fc:	e8 6f bd ff ff       	call   1070 <strlen@plt>
    5301:	48 89 c2             	mov    %rax,%rdx
    5304:	8b 45 a4             	mov    -0x5c(%rbp),%eax
    5307:	48 c1 e0 04          	shl    $0x4,%rax
    530b:	48 89 c1             	mov    %rax,%rcx
    530e:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    5312:	48 01 c8             	add    %rcx,%rax
    5315:	48 8b 00             	mov    (%rax),%rax
    5318:	48 89 d6             	mov    %rdx,%rsi
    531b:	48 89 c7             	mov    %rax,%rdi
    531e:	e8 5f c1 ff ff       	call   1482 <Slice_from>
    5323:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
    5327:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    532b:	48 8d 15 e5 4f 00 00 	lea    0x4fe5(%rip),%rdx        # a317 <_IO_stdin_used+0x317>
    5332:	48 8b 75 d0          	mov    -0x30(%rbp),%rsi
    5336:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    533a:	b9 01 00 00 00       	mov    $0x1,%ecx
    533f:	48 89 f7             	mov    %rsi,%rdi
    5342:	48 89 c6             	mov    %rax,%rsi
    5345:	e8 97 f5 ff ff       	call   48e1 <bEq>
    534a:	83 f0 01             	xor    $0x1,%eax
    534d:	84 c0                	test   %al,%al
    534f:	0f 84 06 02 00 00    	je     555b <bCollectCrl+0x2fb>
    5355:	48 8d 15 bd 4f 00 00 	lea    0x4fbd(%rip),%rdx        # a319 <_IO_stdin_used+0x319>
    535c:	48 8b 75 d0          	mov    -0x30(%rbp),%rsi
    5360:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    5364:	b9 02 00 00 00       	mov    $0x2,%ecx
    5369:	48 89 f7             	mov    %rsi,%rdi
    536c:	48 89 c6             	mov    %rax,%rsi
    536f:	e8 6d f5 ff ff       	call   48e1 <bEq>
    5374:	83 f0 01             	xor    $0x1,%eax
    5377:	84 c0                	test   %al,%al
    5379:	0f 84 dc 01 00 00    	je     555b <bCollectCrl+0x2fb>
    537f:	8b 45 a4             	mov    -0x5c(%rbp),%eax
    5382:	48 c1 e0 04          	shl    $0x4,%rax
    5386:	48 89 c2             	mov    %rax,%rdx
    5389:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    538d:	48 01 d0             	add    %rdx,%rax
    5390:	0f b6 40 08          	movzbl 0x8(%rax),%eax
    5394:	3c 04                	cmp    $0x4,%al
    5396:	0f 85 db 00 00 00    	jne    5477 <bCollectCrl+0x217>
    539c:	8b 8d 74 ff ff ff    	mov    -0x8c(%rbp),%ecx
    53a2:	48 8b 95 78 ff ff ff 	mov    -0x88(%rbp),%rdx
    53a9:	48 8b 75 d0          	mov    -0x30(%rbp),%rsi
    53ad:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    53b1:	48 89 f7             	mov    %rsi,%rdi
    53b4:	48 89 c6             	mov    %rax,%rsi
    53b7:	e8 19 fe ff ff       	call   51d5 <bIsSkipped>
    53bc:	83 f0 01             	xor    $0x1,%eax
    53bf:	84 c0                	test   %al,%al
    53c1:	0f 84 94 01 00 00    	je     555b <bCollectCrl+0x2fb>
    53c7:	48 8b 55 88          	mov    -0x78(%rbp),%rdx
    53cb:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    53cf:	48 01 d0             	add    %rdx,%rax
    53d2:	48 8d 48 02          	lea    0x2(%rax),%rcx
    53d6:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    53da:	ba 01 00 00 00       	mov    $0x1,%edx
    53df:	48 89 ce             	mov    %rcx,%rsi
    53e2:	48 89 c7             	mov    %rax,%rdi
    53e5:	e8 e7 be ff ff       	call   12d1 <Arena_alloc>
    53ea:	48 89 45 c0          	mov    %rax,-0x40(%rbp)
    53ee:	48 8b 55 88          	mov    -0x78(%rbp),%rdx
    53f2:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    53f6:	48 01 d0             	add    %rdx,%rax
    53f9:	48 8d 70 02          	lea    0x2(%rax),%rsi
    53fd:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    5401:	48 8b 5d d8          	mov    -0x28(%rbp),%rbx
    5405:	48 8b 45 80          	mov    -0x80(%rbp),%rax
    5409:	48 8b 55 88          	mov    -0x78(%rbp),%rdx
    540d:	48 8b 7d c0          	mov    -0x40(%rbp),%rdi
    5411:	49 89 c8             	mov    %rcx,%r8
    5414:	49 89 d9             	mov    %rbx,%r9
    5417:	48 89 d1             	mov    %rdx,%rcx
    541a:	48 89 c2             	mov    %rax,%rdx
    541d:	e8 0d f7 ff ff       	call   4b2f <bJoin>
    5422:	48 89 45 c8          	mov    %rax,-0x38(%rbp)
    5426:	48 8b 55 c8          	mov    -0x38(%rbp),%rdx
    542a:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
    542e:	48 89 d6             	mov    %rdx,%rsi
    5431:	48 89 c7             	mov    %rax,%rdi
    5434:	e8 49 c0 ff ff       	call   1482 <Slice_from>
    5439:	44 8b 8d 74 ff ff ff 	mov    -0x8c(%rbp),%r9d
    5440:	4c 8b 85 78 ff ff ff 	mov    -0x88(%rbp),%r8
    5447:	48 8b 75 c0          	mov    -0x40(%rbp),%rsi
    544b:	48 8b 7d 98          	mov    -0x68(%rbp),%rdi
    544f:	48 83 ec 08          	sub    $0x8,%rsp
    5453:	ff b5 60 ff ff ff    	push   -0xa0(%rbp)
    5459:	8b 4d 18             	mov    0x18(%rbp),%ecx
    545c:	51                   	push   %rcx
    545d:	ff b5 68 ff ff ff    	push   -0x98(%rbp)
    5463:	48 89 d1             	mov    %rdx,%rcx
    5466:	48 89 c2             	mov    %rax,%rdx
    5469:	e8 f2 fd ff ff       	call   5260 <bCollectCrl>
    546e:	48 83 c4 20          	add    $0x20,%rsp
    5472:	e9 e4 00 00 00       	jmp    555b <bCollectCrl+0x2fb>
    5477:	48 8d 15 9e 4e 00 00 	lea    0x4e9e(%rip),%rdx        # a31c <_IO_stdin_used+0x31c>
    547e:	48 8b 75 d0          	mov    -0x30(%rbp),%rsi
    5482:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    5486:	b9 04 00 00 00       	mov    $0x4,%ecx
    548b:	48 89 f7             	mov    %rsi,%rdi
    548e:	48 89 c6             	mov    %rax,%rsi
    5491:	e8 c8 f4 ff ff       	call   495e <bEndsWith>
    5496:	84 c0                	test   %al,%al
    5498:	0f 84 bd 00 00 00    	je     555b <bCollectCrl+0x2fb>
    549e:	48 8b 85 60 ff ff ff 	mov    -0xa0(%rbp),%rax
    54a5:	8b 00                	mov    (%rax),%eax
    54a7:	3b 45 18             	cmp    0x18(%rbp),%eax
    54aa:	0f 83 ab 00 00 00    	jae    555b <bCollectCrl+0x2fb>
    54b0:	48 8b 55 88          	mov    -0x78(%rbp),%rdx
    54b4:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    54b8:	48 01 d0             	add    %rdx,%rax
    54bb:	48 8d 48 02          	lea    0x2(%rax),%rcx
    54bf:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    54c3:	ba 01 00 00 00       	mov    $0x1,%edx
    54c8:	48 89 ce             	mov    %rcx,%rsi
    54cb:	48 89 c7             	mov    %rax,%rdi
    54ce:	e8 fe bd ff ff       	call   12d1 <Arena_alloc>
    54d3:	48 89 45 b0          	mov    %rax,-0x50(%rbp)
    54d7:	48 8b 55 88          	mov    -0x78(%rbp),%rdx
    54db:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    54df:	48 01 d0             	add    %rdx,%rax
    54e2:	48 8d 70 02          	lea    0x2(%rax),%rsi
    54e6:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    54ea:	48 8b 5d d8          	mov    -0x28(%rbp),%rbx
    54ee:	48 8b 45 80          	mov    -0x80(%rbp),%rax
    54f2:	48 8b 55 88          	mov    -0x78(%rbp),%rdx
    54f6:	48 8b 7d b0          	mov    -0x50(%rbp),%rdi
    54fa:	49 89 c8             	mov    %rcx,%r8
    54fd:	49 89 d9             	mov    %rbx,%r9
    5500:	48 89 d1             	mov    %rdx,%rcx
    5503:	48 89 c2             	mov    %rax,%rdx
    5506:	e8 24 f6 ff ff       	call   4b2f <bJoin>
    550b:	48 89 45 b8          	mov    %rax,-0x48(%rbp)
    550f:	48 8b 85 60 ff ff ff 	mov    -0xa0(%rbp),%rax
    5516:	8b 00                	mov    (%rax),%eax
    5518:	89 c0                	mov    %eax,%eax
    551a:	48 c1 e0 04          	shl    $0x4,%rax
    551e:	48 89 c2             	mov    %rax,%rdx
    5521:	48 8b 85 68 ff ff ff 	mov    -0x98(%rbp),%rax
    5528:	48 8d 1c 02          	lea    (%rdx,%rax,1),%rbx
    552c:	48 8b 55 b8          	mov    -0x48(%rbp),%rdx
    5530:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    5534:	48 89 d6             	mov    %rdx,%rsi
    5537:	48 89 c7             	mov    %rax,%rdi
    553a:	e8 43 bf ff ff       	call   1482 <Slice_from>
    553f:	48 89 03             	mov    %rax,(%rbx)
    5542:	48 89 53 08          	mov    %rdx,0x8(%rbx)
    5546:	48 8b 85 60 ff ff ff 	mov    -0xa0(%rbp),%rax
    554d:	8b 00                	mov    (%rax),%eax
    554f:	8d 50 01             	lea    0x1(%rax),%edx
    5552:	48 8b 85 60 ff ff ff 	mov    -0xa0(%rbp),%rax
    5559:	89 10                	mov    %edx,(%rax)
    555b:	83 45 a4 01          	addl   $0x1,-0x5c(%rbp)
    555f:	8b 45 a0             	mov    -0x60(%rbp),%eax
    5562:	39 45 a4             	cmp    %eax,-0x5c(%rbp)
    5565:	0f 82 7a fd ff ff    	jb     52e5 <bCollectCrl+0x85>
    556b:	48 8b 85 60 ff ff ff 	mov    -0xa0(%rbp),%rax
    5572:	8b 00                	mov    (%rax),%eax
    5574:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    5578:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
    557f:	00 00 
    5581:	74 05                	je     5588 <bCollectCrl+0x328>
    5583:	e8 f8 ba ff ff       	call   1080 <__stack_chk_fail@plt>
    5588:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
    558c:	c9                   	leave
    558d:	c3                   	ret

000000000000558e <bSortFiles>:
    558e:	55                   	push   %rbp
    558f:	48 89 e5             	mov    %rsp,%rbp
    5592:	48 89 7d b8          	mov    %rdi,-0x48(%rbp)
    5596:	89 75 b4             	mov    %esi,-0x4c(%rbp)
    5599:	c7 45 c8 01 00 00 00 	movl   $0x1,-0x38(%rbp)
    55a0:	e9 6e 01 00 00       	jmp    5713 <bSortFiles+0x185>
    55a5:	8b 45 c8             	mov    -0x38(%rbp),%eax
    55a8:	48 c1 e0 04          	shl    $0x4,%rax
    55ac:	48 89 c2             	mov    %rax,%rdx
    55af:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    55b3:	48 01 d0             	add    %rdx,%rax
    55b6:	48 8b 50 08          	mov    0x8(%rax),%rdx
    55ba:	48 8b 00             	mov    (%rax),%rax
    55bd:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    55c1:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
    55c5:	8b 45 c8             	mov    -0x38(%rbp),%eax
    55c8:	83 e8 01             	sub    $0x1,%eax
    55cb:	89 45 cc             	mov    %eax,-0x34(%rbp)
    55ce:	e9 08 01 00 00       	jmp    56db <bSortFiles+0x14d>
    55d3:	c6 45 c7 00          	movb   $0x0,-0x39(%rbp)
    55d7:	8b 45 cc             	mov    -0x34(%rbp),%eax
    55da:	48 98                	cltq
    55dc:	48 c1 e0 04          	shl    $0x4,%rax
    55e0:	48 89 c2             	mov    %rax,%rdx
    55e3:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    55e7:	48 01 d0             	add    %rdx,%rax
    55ea:	48 8b 50 08          	mov    0x8(%rax),%rdx
    55ee:	48 8b 00             	mov    (%rax),%rax
    55f1:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    55f5:	48 89 55 f8          	mov    %rdx,-0x8(%rbp)
    55f9:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    55fd:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
    5601:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    5605:	48 3b 45 d0          	cmp    -0x30(%rbp),%rax
    5609:	73 08                	jae    5613 <bSortFiles+0x85>
    560b:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    560f:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
    5613:	48 c7 45 d8 00 00 00 	movq   $0x0,-0x28(%rbp)
    561a:	00 
    561b:	eb 6c                	jmp    5689 <bSortFiles+0xfb>
    561d:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
    5621:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    5625:	48 01 d0             	add    %rdx,%rax
    5628:	0f b6 10             	movzbl (%rax),%edx
    562b:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
    562f:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    5633:	48 01 c8             	add    %rcx,%rax
    5636:	0f b6 00             	movzbl (%rax),%eax
    5639:	38 c2                	cmp    %al,%dl
    563b:	73 06                	jae    5643 <bSortFiles+0xb5>
    563d:	c6 45 c7 01          	movb   $0x1,-0x39(%rbp)
    5641:	eb 50                	jmp    5693 <bSortFiles+0x105>
    5643:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
    5647:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    564b:	48 01 d0             	add    %rdx,%rax
    564e:	0f b6 00             	movzbl (%rax),%eax
    5651:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
    5655:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    5659:	48 01 ca             	add    %rcx,%rdx
    565c:	0f b6 12             	movzbl (%rdx),%edx
    565f:	38 c2                	cmp    %al,%dl
    5661:	73 06                	jae    5669 <bSortFiles+0xdb>
    5663:	c6 45 c7 00          	movb   $0x0,-0x39(%rbp)
    5667:	eb 2a                	jmp    5693 <bSortFiles+0x105>
    5669:	48 83 45 d8 01       	addq   $0x1,-0x28(%rbp)
    566e:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    5672:	48 3b 45 d0          	cmp    -0x30(%rbp),%rax
    5676:	75 11                	jne    5689 <bSortFiles+0xfb>
    5678:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
    567c:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    5680:	48 39 c2             	cmp    %rax,%rdx
    5683:	73 04                	jae    5689 <bSortFiles+0xfb>
    5685:	c6 45 c7 01          	movb   $0x1,-0x39(%rbp)
    5689:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    568d:	48 3b 45 d0          	cmp    -0x30(%rbp),%rax
    5691:	72 8a                	jb     561d <bSortFiles+0x8f>
    5693:	0f b6 45 c7          	movzbl -0x39(%rbp),%eax
    5697:	83 f0 01             	xor    $0x1,%eax
    569a:	84 c0                	test   %al,%al
    569c:	75 49                	jne    56e7 <bSortFiles+0x159>
    569e:	8b 45 cc             	mov    -0x34(%rbp),%eax
    56a1:	48 98                	cltq
    56a3:	48 c1 e0 04          	shl    $0x4,%rax
    56a7:	48 89 c2             	mov    %rax,%rdx
    56aa:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    56ae:	48 01 d0             	add    %rdx,%rax
    56b1:	8b 55 cc             	mov    -0x34(%rbp),%edx
    56b4:	48 63 d2             	movslq %edx,%rdx
    56b7:	48 83 c2 01          	add    $0x1,%rdx
    56bb:	48 89 d1             	mov    %rdx,%rcx
    56be:	48 c1 e1 04          	shl    $0x4,%rcx
    56c2:	48 8b 55 b8          	mov    -0x48(%rbp),%rdx
    56c6:	48 01 d1             	add    %rdx,%rcx
    56c9:	48 8b 50 08          	mov    0x8(%rax),%rdx
    56cd:	48 8b 00             	mov    (%rax),%rax
    56d0:	48 89 01             	mov    %rax,(%rcx)
    56d3:	48 89 51 08          	mov    %rdx,0x8(%rcx)
    56d7:	83 6d cc 01          	subl   $0x1,-0x34(%rbp)
    56db:	83 7d cc 00          	cmpl   $0x0,-0x34(%rbp)
    56df:	0f 89 ee fe ff ff    	jns    55d3 <bSortFiles+0x45>
    56e5:	eb 01                	jmp    56e8 <bSortFiles+0x15a>
    56e7:	90                   	nop
    56e8:	8b 45 cc             	mov    -0x34(%rbp),%eax
    56eb:	48 98                	cltq
    56ed:	48 83 c0 01          	add    $0x1,%rax
    56f1:	48 c1 e0 04          	shl    $0x4,%rax
    56f5:	48 89 c2             	mov    %rax,%rdx
    56f8:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    56fc:	48 8d 0c 02          	lea    (%rdx,%rax,1),%rcx
    5700:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    5704:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    5708:	48 89 01             	mov    %rax,(%rcx)
    570b:	48 89 51 08          	mov    %rdx,0x8(%rcx)
    570f:	83 45 c8 01          	addl   $0x1,-0x38(%rbp)
    5713:	8b 45 c8             	mov    -0x38(%rbp),%eax
    5716:	3b 45 b4             	cmp    -0x4c(%rbp),%eax
    5719:	0f 82 86 fe ff ff    	jb     55a5 <bSortFiles+0x17>
    571f:	90                   	nop
    5720:	90                   	nop
    5721:	5d                   	pop    %rbp
    5722:	c3                   	ret

0000000000005723 <bFindField>:
    5723:	55                   	push   %rbp
    5724:	48 89 e5             	mov    %rsp,%rbp
    5727:	48 83 ec 30          	sub    $0x30,%rsp
    572b:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    572f:	48 89 f0             	mov    %rsi,%rax
    5732:	48 89 d1             	mov    %rdx,%rcx
    5735:	48 89 c0             	mov    %rax,%rax
    5738:	ba 00 00 00 00       	mov    $0x0,%edx
    573d:	48 89 ca             	mov    %rcx,%rdx
    5740:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
    5744:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    5748:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
    574f:	eb 5f                	jmp    57b0 <bFindField+0x8d>
    5751:	48 8b 4d d8          	mov    -0x28(%rbp),%rcx
    5755:	48 8b 7d d0          	mov    -0x30(%rbp),%rdi
    5759:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    575d:	48 8b 70 50          	mov    0x50(%rax),%rsi
    5761:	8b 55 fc             	mov    -0x4(%rbp),%edx
    5764:	48 89 d0             	mov    %rdx,%rax
    5767:	48 c1 e0 02          	shl    $0x2,%rax
    576b:	48 01 d0             	add    %rdx,%rax
    576e:	48 c1 e0 03          	shl    $0x3,%rax
    5772:	48 01 f0             	add    %rsi,%rax
    5775:	48 8b 30             	mov    (%rax),%rsi
    5778:	48 8b 40 08          	mov    0x8(%rax),%rax
    577c:	48 89 fa             	mov    %rdi,%rdx
    577f:	48 89 f7             	mov    %rsi,%rdi
    5782:	48 89 c6             	mov    %rax,%rsi
    5785:	e8 57 f1 ff ff       	call   48e1 <bEq>
    578a:	84 c0                	test   %al,%al
    578c:	74 1e                	je     57ac <bFindField+0x89>
    578e:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    5792:	48 8b 48 50          	mov    0x50(%rax),%rcx
    5796:	8b 55 fc             	mov    -0x4(%rbp),%edx
    5799:	48 89 d0             	mov    %rdx,%rax
    579c:	48 c1 e0 02          	shl    $0x2,%rax
    57a0:	48 01 d0             	add    %rdx,%rax
    57a3:	48 c1 e0 03          	shl    $0x3,%rax
    57a7:	48 01 c8             	add    %rcx,%rax
    57aa:	eb 19                	jmp    57c5 <bFindField+0xa2>
    57ac:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
    57b0:	8b 55 fc             	mov    -0x4(%rbp),%edx
    57b3:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    57b7:	48 8b 40 58          	mov    0x58(%rax),%rax
    57bb:	48 39 c2             	cmp    %rax,%rdx
    57be:	72 91                	jb     5751 <bFindField+0x2e>
    57c0:	b8 00 00 00 00       	mov    $0x0,%eax
    57c5:	c9                   	leave
    57c6:	c3                   	ret

00000000000057c7 <bFieldStr>:
    57c7:	55                   	push   %rbp
    57c8:	48 89 e5             	mov    %rsp,%rbp
    57cb:	48 83 ec 50          	sub    $0x50,%rsp
    57cf:	48 89 7d c8          	mov    %rdi,-0x38(%rbp)
    57d3:	48 89 f0             	mov    %rsi,%rax
    57d6:	48 89 d6             	mov    %rdx,%rsi
    57d9:	48 89 c0             	mov    %rax,%rax
    57dc:	ba 00 00 00 00       	mov    $0x0,%edx
    57e1:	48 89 f2             	mov    %rsi,%rdx
    57e4:	48 89 45 b0          	mov    %rax,-0x50(%rbp)
    57e8:	48 89 55 b8          	mov    %rdx,-0x48(%rbp)
    57ec:	48 89 4d c0          	mov    %rcx,-0x40(%rbp)
    57f0:	48 8b 4d b0          	mov    -0x50(%rbp),%rcx
    57f4:	48 8b 55 b8          	mov    -0x48(%rbp),%rdx
    57f8:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    57fc:	48 89 ce             	mov    %rcx,%rsi
    57ff:	48 89 c7             	mov    %rax,%rdi
    5802:	e8 1c ff ff ff       	call   5723 <bFindField>
    5807:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
    580b:	48 83 7d d8 00       	cmpq   $0x0,-0x28(%rbp)
    5810:	75 07                	jne    5819 <bFieldStr+0x52>
    5812:	b8 00 00 00 00       	mov    $0x0,%eax
    5817:	eb 42                	jmp    585b <bFieldStr+0x94>
    5819:	48 8b 4d d8          	mov    -0x28(%rbp),%rcx
    581d:	48 8b 41 10          	mov    0x10(%rcx),%rax
    5821:	48 8b 51 18          	mov    0x18(%rcx),%rdx
    5825:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    5829:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
    582d:	48 8b 41 20          	mov    0x20(%rcx),%rax
    5831:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    5835:	8b 45 e0             	mov    -0x20(%rbp),%eax
    5838:	85 c0                	test   %eax,%eax
    583a:	74 07                	je     5843 <bFieldStr+0x7c>
    583c:	b8 00 00 00 00       	mov    $0x0,%eax
    5841:	eb 18                	jmp    585b <bFieldStr+0x94>
    5843:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
    5847:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    584b:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
    584f:	48 89 01             	mov    %rax,(%rcx)
    5852:	48 89 51 08          	mov    %rdx,0x8(%rcx)
    5856:	b8 01 00 00 00       	mov    $0x1,%eax
    585b:	c9                   	leave
    585c:	c3                   	ret

000000000000585d <bFieldList>:
    585d:	55                   	push   %rbp
    585e:	48 89 e5             	mov    %rsp,%rbp
    5861:	48 81 ec 90 00 00 00 	sub    $0x90,%rsp
    5868:	48 89 7d 98          	mov    %rdi,-0x68(%rbp)
    586c:	48 89 f0             	mov    %rsi,%rax
    586f:	48 89 d6             	mov    %rdx,%rsi
    5872:	48 89 c0             	mov    %rax,%rax
    5875:	ba 00 00 00 00       	mov    $0x0,%edx
    587a:	48 89 f2             	mov    %rsi,%rdx
    587d:	48 89 45 80          	mov    %rax,-0x80(%rbp)
    5881:	48 89 55 88          	mov    %rdx,-0x78(%rbp)
    5885:	48 89 4d 90          	mov    %rcx,-0x70(%rbp)
    5889:	4c 89 85 78 ff ff ff 	mov    %r8,-0x88(%rbp)
    5890:	44 89 8d 74 ff ff ff 	mov    %r9d,-0x8c(%rbp)
    5897:	48 8b 4d 80          	mov    -0x80(%rbp),%rcx
    589b:	48 8b 55 88          	mov    -0x78(%rbp),%rdx
    589f:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    58a3:	48 89 ce             	mov    %rcx,%rsi
    58a6:	48 89 c7             	mov    %rax,%rdi
    58a9:	e8 75 fe ff ff       	call   5723 <bFindField>
    58ae:	48 89 45 b0          	mov    %rax,-0x50(%rbp)
    58b2:	48 83 7d b0 00       	cmpq   $0x0,-0x50(%rbp)
    58b7:	75 0a                	jne    58c3 <bFieldList+0x66>
    58b9:	b8 00 00 00 00       	mov    $0x0,%eax
    58be:	e9 03 01 00 00       	jmp    59c6 <bFieldList+0x169>
    58c3:	48 8b 4d b0          	mov    -0x50(%rbp),%rcx
    58c7:	48 8b 41 10          	mov    0x10(%rcx),%rax
    58cb:	48 8b 51 18          	mov    0x18(%rcx),%rdx
    58cf:	48 89 45 c0          	mov    %rax,-0x40(%rbp)
    58d3:	48 89 55 c8          	mov    %rdx,-0x38(%rbp)
    58d7:	48 8b 41 20          	mov    0x20(%rcx),%rax
    58db:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
    58df:	8b 45 c0             	mov    -0x40(%rbp),%eax
    58e2:	83 f8 03             	cmp    $0x3,%eax
    58e5:	74 0a                	je     58f1 <bFieldList+0x94>
    58e7:	b8 00 00 00 00       	mov    $0x0,%eax
    58ec:	e9 d5 00 00 00       	jmp    59c6 <bFieldList+0x169>
    58f1:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    58f5:	48 89 45 b8          	mov    %rax,-0x48(%rbp)
    58f9:	48 83 7d b8 00       	cmpq   $0x0,-0x48(%rbp)
    58fe:	75 0a                	jne    590a <bFieldList+0xad>
    5900:	b8 00 00 00 00       	mov    $0x0,%eax
    5905:	e9 bc 00 00 00       	jmp    59c6 <bFieldList+0x169>
    590a:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    590e:	48 8b 40 08          	mov    0x8(%rax),%rax
    5912:	48 85 c0             	test   %rax,%rax
    5915:	75 0a                	jne    5921 <bFieldList+0xc4>
    5917:	b8 00 00 00 00       	mov    $0x0,%eax
    591c:	e9 a5 00 00 00       	jmp    59c6 <bFieldList+0x169>
    5921:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5925:	48 8b 40 08          	mov    0x8(%rax),%rax
    5929:	8b 95 74 ff ff ff    	mov    -0x8c(%rbp),%edx
    592f:	48 39 c2             	cmp    %rax,%rdx
    5932:	73 0a                	jae    593e <bFieldList+0xe1>
    5934:	b8 00 00 00 00       	mov    $0x0,%eax
    5939:	e9 88 00 00 00       	jmp    59c6 <bFieldList+0x169>
    593e:	c7 45 ac 00 00 00 00 	movl   $0x0,-0x54(%rbp)
    5945:	eb 67                	jmp    59ae <bFieldList+0x151>
    5947:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    594b:	48 8b 08             	mov    (%rax),%rcx
    594e:	8b 55 ac             	mov    -0x54(%rbp),%edx
    5951:	48 89 d0             	mov    %rdx,%rax
    5954:	48 01 c0             	add    %rax,%rax
    5957:	48 01 d0             	add    %rdx,%rax
    595a:	48 c1 e0 03          	shl    $0x3,%rax
    595e:	48 01 c1             	add    %rax,%rcx
    5961:	48 8b 01             	mov    (%rcx),%rax
    5964:	48 8b 51 08          	mov    0x8(%rcx),%rdx
    5968:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    596c:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
    5970:	48 8b 41 10          	mov    0x10(%rcx),%rax
    5974:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    5978:	8b 45 e0             	mov    -0x20(%rbp),%eax
    597b:	85 c0                	test   %eax,%eax
    597d:	74 07                	je     5986 <bFieldList+0x129>
    597f:	b8 00 00 00 00       	mov    $0x0,%eax
    5984:	eb 40                	jmp    59c6 <bFieldList+0x169>
    5986:	8b 45 ac             	mov    -0x54(%rbp),%eax
    5989:	48 c1 e0 04          	shl    $0x4,%rax
    598d:	48 89 c2             	mov    %rax,%rdx
    5990:	48 8b 85 78 ff ff ff 	mov    -0x88(%rbp),%rax
    5997:	48 8d 0c 02          	lea    (%rdx,%rax,1),%rcx
    599b:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    599f:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
    59a3:	48 89 01             	mov    %rax,(%rcx)
    59a6:	48 89 51 08          	mov    %rdx,0x8(%rcx)
    59aa:	83 45 ac 01          	addl   $0x1,-0x54(%rbp)
    59ae:	8b 55 ac             	mov    -0x54(%rbp),%edx
    59b1:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    59b5:	48 8b 40 08          	mov    0x8(%rax),%rax
    59b9:	48 39 c2             	cmp    %rax,%rdx
    59bc:	72 89                	jb     5947 <bFieldList+0xea>
    59be:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    59c2:	48 8b 40 08          	mov    0x8(%rax),%rax
    59c6:	c9                   	leave
    59c7:	c3                   	ret

00000000000059c8 <bError>:
    59c8:	55                   	push   %rbp
    59c9:	48 89 e5             	mov    %rsp,%rbp
    59cc:	48 83 ec 30          	sub    $0x30,%rsp
    59d0:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    59d4:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    59d8:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
    59dc:	48 89 4d e0          	mov    %rcx,-0x20(%rbp)
    59e0:	4c 89 45 d8          	mov    %r8,-0x28(%rbp)
    59e4:	4c 89 4d d0          	mov    %r9,-0x30(%rbp)
    59e8:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    59ec:	8b 80 b0 00 00 00    	mov    0xb0(%rax),%eax
    59f2:	8d 50 01             	lea    0x1(%rax),%edx
    59f5:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    59f9:	89 90 b0 00 00 00    	mov    %edx,0xb0(%rax)
    59ff:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    5a03:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    5a07:	48 8d 0d 13 49 00 00 	lea    0x4913(%rip),%rcx        # a321 <_IO_stdin_used+0x321>
    5a0e:	48 89 c6             	mov    %rax,%rsi
    5a11:	48 89 cf             	mov    %rcx,%rdi
    5a14:	b8 00 00 00 00       	mov    $0x0,%eax
    5a19:	e8 72 b6 ff ff       	call   1090 <printf@plt>
    5a1e:	48 83 7d e0 00       	cmpq   $0x0,-0x20(%rbp)
    5a23:	74 1f                	je     5a44 <bError+0x7c>
    5a25:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    5a29:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    5a2d:	48 8d 0d f5 48 00 00 	lea    0x48f5(%rip),%rcx        # a329 <_IO_stdin_used+0x329>
    5a34:	48 89 c6             	mov    %rax,%rsi
    5a37:	48 89 cf             	mov    %rcx,%rdi
    5a3a:	b8 00 00 00 00       	mov    $0x0,%eax
    5a3f:	e8 4c b6 ff ff       	call   1090 <printf@plt>
    5a44:	48 83 7d d0 00       	cmpq   $0x0,-0x30(%rbp)
    5a49:	74 1f                	je     5a6a <bError+0xa2>
    5a4b:	48 8b 55 10          	mov    0x10(%rbp),%rdx
    5a4f:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    5a53:	48 8d 0d cf 48 00 00 	lea    0x48cf(%rip),%rcx        # a329 <_IO_stdin_used+0x329>
    5a5a:	48 89 c6             	mov    %rax,%rsi
    5a5d:	48 89 cf             	mov    %rcx,%rdi
    5a60:	b8 00 00 00 00       	mov    $0x0,%eax
    5a65:	e8 26 b6 ff ff       	call   1090 <printf@plt>
    5a6a:	48 83 7d 18 00       	cmpq   $0x0,0x18(%rbp)
    5a6f:	74 1b                	je     5a8c <bError+0xc4>
    5a71:	48 8b 45 18          	mov    0x18(%rbp),%rax
    5a75:	48 8d 15 b9 48 00 00 	lea    0x48b9(%rip),%rdx        # a335 <_IO_stdin_used+0x335>
    5a7c:	48 89 c6             	mov    %rax,%rsi
    5a7f:	48 89 d7             	mov    %rdx,%rdi
    5a82:	b8 00 00 00 00       	mov    $0x0,%eax
    5a87:	e8 04 b6 ff ff       	call   1090 <printf@plt>
    5a8c:	90                   	nop
    5a8d:	c9                   	leave
    5a8e:	c3                   	ret

0000000000005a8f <bInit>:
    5a8f:	55                   	push   %rbp
    5a90:	48 89 e5             	mov    %rsp,%rbp
    5a93:	53                   	push   %rbx
    5a94:	48 83 ec 58          	sub    $0x58,%rsp
    5a98:	48 89 7d b8          	mov    %rdi,-0x48(%rbp)
    5a9c:	48 89 75 b0          	mov    %rsi,-0x50(%rbp)
    5aa0:	48 89 55 a8          	mov    %rdx,-0x58(%rbp)
    5aa4:	88 4d a7             	mov    %cl,-0x59(%rbp)
    5aa7:	44 88 45 a6          	mov    %r8b,-0x5a(%rbp)
    5aab:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5aaf:	48 8b 55 b0          	mov    -0x50(%rbp),%rdx
    5ab3:	48 89 10             	mov    %rdx,(%rax)
    5ab6:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5aba:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
    5abe:	48 89 50 08          	mov    %rdx,0x8(%rax)
    5ac2:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5ac6:	48 c7 40 10 00 00 00 	movq   $0x0,0x10(%rax)
    5acd:	00 
    5ace:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5ad2:	c7 80 b0 00 00 00 00 	movl   $0x0,0xb0(%rax)
    5ad9:	00 00 00 
    5adc:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5ae0:	0f b6 55 a7          	movzbl -0x59(%rbp),%edx
    5ae4:	88 90 b4 00 00 00    	mov    %dl,0xb4(%rax)
    5aea:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5aee:	0f b6 55 a6          	movzbl -0x5a(%rbp),%edx
    5af2:	88 90 b5 00 00 00    	mov    %dl,0xb5(%rax)
    5af8:	48 8b 5d b8          	mov    -0x48(%rbp),%rbx
    5afc:	48 8d 05 40 48 00 00 	lea    0x4840(%rip),%rax        # a343 <_IO_stdin_used+0x343>
    5b03:	be 00 00 00 00       	mov    $0x0,%esi
    5b08:	48 89 c7             	mov    %rax,%rdi
    5b0b:	e8 72 b9 ff ff       	call   1482 <Slice_from>
    5b10:	48 89 43 18          	mov    %rax,0x18(%rbx)
    5b14:	48 89 53 20          	mov    %rdx,0x20(%rbx)
    5b18:	48 8b 5d b8          	mov    -0x48(%rbp),%rbx
    5b1c:	be 00 00 00 00       	mov    $0x0,%esi
    5b21:	bf 00 00 00 00       	mov    $0x0,%edi
    5b26:	e8 57 b9 ff ff       	call   1482 <Slice_from>
    5b2b:	48 89 43 28          	mov    %rax,0x28(%rbx)
    5b2f:	48 89 53 30          	mov    %rdx,0x30(%rbx)
    5b33:	48 8b 5d b8          	mov    -0x48(%rbp),%rbx
    5b37:	be 00 00 00 00       	mov    $0x0,%esi
    5b3c:	bf 00 00 00 00       	mov    $0x0,%edi
    5b41:	e8 3c b9 ff ff       	call   1482 <Slice_from>
    5b46:	48 89 43 38          	mov    %rax,0x38(%rbx)
    5b4a:	48 89 53 40          	mov    %rdx,0x40(%rbx)
    5b4e:	48 8b 5d b8          	mov    -0x48(%rbp),%rbx
    5b52:	48 8d 05 eb 47 00 00 	lea    0x47eb(%rip),%rax        # a344 <_IO_stdin_used+0x344>
    5b59:	be 12 00 00 00       	mov    $0x12,%esi
    5b5e:	48 89 c7             	mov    %rax,%rdi
    5b61:	e8 1c b9 ff ff       	call   1482 <Slice_from>
    5b66:	48 89 43 48          	mov    %rax,0x48(%rbx)
    5b6a:	48 89 53 50          	mov    %rdx,0x50(%rbx)
    5b6e:	48 8b 5d b8          	mov    -0x48(%rbp),%rbx
    5b72:	48 8d 05 de 47 00 00 	lea    0x47de(%rip),%rax        # a357 <_IO_stdin_used+0x357>
    5b79:	be 0c 00 00 00       	mov    $0xc,%esi
    5b7e:	48 89 c7             	mov    %rax,%rdi
    5b81:	e8 fc b8 ff ff       	call   1482 <Slice_from>
    5b86:	48 89 43 58          	mov    %rax,0x58(%rbx)
    5b8a:	48 89 53 60          	mov    %rdx,0x60(%rbx)
    5b8e:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5b92:	48 c7 40 68 00 00 00 	movq   $0x0,0x68(%rax)
    5b99:	00 
    5b9a:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5b9e:	c7 40 70 00 00 00 00 	movl   $0x0,0x70(%rax)
    5ba5:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5ba9:	48 c7 40 78 00 00 00 	movq   $0x0,0x78(%rax)
    5bb0:	00 
    5bb1:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5bb5:	c7 80 80 00 00 00 00 	movl   $0x0,0x80(%rax)
    5bbc:	00 00 00 
    5bbf:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5bc3:	48 c7 80 88 00 00 00 	movq   $0x0,0x88(%rax)
    5bca:	00 00 00 00 
    5bce:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5bd2:	c7 80 90 00 00 00 00 	movl   $0x0,0x90(%rax)
    5bd9:	00 00 00 
    5bdc:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5be0:	48 c7 80 98 00 00 00 	movq   $0x0,0x98(%rax)
    5be7:	00 00 00 00 
    5beb:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5bef:	48 c7 80 a8 00 00 00 	movq   $0x0,0xa8(%rax)
    5bf6:	00 00 00 00 
    5bfa:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5bfe:	c7 80 a0 00 00 00 00 	movl   $0x0,0xa0(%rax)
    5c05:	00 00 00 
    5c08:	c7 45 c0 00 00 00 00 	movl   $0x0,-0x40(%rbp)
    5c0f:	eb 36                	jmp    5c47 <bInit+0x1b8>
    5c11:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    5c15:	48 8b 50 70          	mov    0x70(%rax),%rdx
    5c19:	8b 45 c0             	mov    -0x40(%rbp),%eax
    5c1c:	48 69 c0 98 00 00 00 	imul   $0x98,%rax,%rax
    5c23:	48 01 d0             	add    %rdx,%rax
    5c26:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
    5c2a:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    5c2e:	8b 00                	mov    (%rax),%eax
    5c30:	83 f8 03             	cmp    $0x3,%eax
    5c33:	75 0e                	jne    5c43 <bInit+0x1b4>
    5c35:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5c39:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    5c3d:	48 89 50 10          	mov    %rdx,0x10(%rax)
    5c41:	eb 14                	jmp    5c57 <bInit+0x1c8>
    5c43:	83 45 c0 01          	addl   $0x1,-0x40(%rbp)
    5c47:	8b 55 c0             	mov    -0x40(%rbp),%edx
    5c4a:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    5c4e:	48 8b 40 78          	mov    0x78(%rax),%rax
    5c52:	48 39 c2             	cmp    %rax,%rdx
    5c55:	72 ba                	jb     5c11 <bInit+0x182>
    5c57:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5c5b:	48 8b 40 10          	mov    0x10(%rax),%rax
    5c5f:	48 85 c0             	test   %rax,%rax
    5c62:	75 30                	jne    5c94 <bInit+0x205>
    5c64:	48 8d 05 f9 46 00 00 	lea    0x46f9(%rip),%rax        # a364 <_IO_stdin_used+0x364>
    5c6b:	48 89 c7             	mov    %rax,%rdi
    5c6e:	e8 dd b3 ff ff       	call   1050 <puts@plt>
    5c73:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5c77:	8b 80 b0 00 00 00    	mov    0xb0(%rax),%eax
    5c7d:	8d 50 01             	lea    0x1(%rax),%edx
    5c80:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5c84:	89 90 b0 00 00 00    	mov    %edx,0xb0(%rax)
    5c8a:	b8 00 00 00 00       	mov    $0x0,%eax
    5c8f:	e9 4a 05 00 00       	jmp    61de <bInit+0x74f>
    5c94:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5c98:	48 8d 58 18          	lea    0x18(%rax),%rbx
    5c9c:	48 8d 05 70 43 00 00 	lea    0x4370(%rip),%rax        # a013 <_IO_stdin_used+0x13>
    5ca3:	be 04 00 00 00       	mov    $0x4,%esi
    5ca8:	48 89 c7             	mov    %rax,%rdi
    5cab:	e8 d2 b7 ff ff       	call   1482 <Slice_from>
    5cb0:	48 8b 4d b8          	mov    -0x48(%rbp),%rcx
    5cb4:	48 8b 79 10          	mov    0x10(%rcx),%rdi
    5cb8:	48 89 c6             	mov    %rax,%rsi
    5cbb:	48 89 d0             	mov    %rdx,%rax
    5cbe:	48 89 d9             	mov    %rbx,%rcx
    5cc1:	48 89 c2             	mov    %rax,%rdx
    5cc4:	e8 fe fa ff ff       	call   57c7 <bFieldStr>
    5cc9:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5ccd:	48 8d 58 28          	lea    0x28(%rax),%rbx
    5cd1:	48 8d 05 a8 46 00 00 	lea    0x46a8(%rip),%rax        # a380 <_IO_stdin_used+0x380>
    5cd8:	be 05 00 00 00       	mov    $0x5,%esi
    5cdd:	48 89 c7             	mov    %rax,%rdi
    5ce0:	e8 9d b7 ff ff       	call   1482 <Slice_from>
    5ce5:	48 8b 4d b8          	mov    -0x48(%rbp),%rcx
    5ce9:	48 8b 79 10          	mov    0x10(%rcx),%rdi
    5ced:	48 89 c6             	mov    %rax,%rsi
    5cf0:	48 89 d0             	mov    %rdx,%rax
    5cf3:	48 89 d9             	mov    %rbx,%rcx
    5cf6:	48 89 c2             	mov    %rax,%rdx
    5cf9:	e8 c9 fa ff ff       	call   57c7 <bFieldStr>
    5cfe:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5d02:	48 8d 58 38          	lea    0x38(%rax),%rbx
    5d06:	48 8d 05 79 46 00 00 	lea    0x4679(%rip),%rax        # a386 <_IO_stdin_used+0x386>
    5d0d:	be 06 00 00 00       	mov    $0x6,%esi
    5d12:	48 89 c7             	mov    %rax,%rdi
    5d15:	e8 68 b7 ff ff       	call   1482 <Slice_from>
    5d1a:	48 8b 4d b8          	mov    -0x48(%rbp),%rcx
    5d1e:	48 8b 79 10          	mov    0x10(%rcx),%rdi
    5d22:	48 89 c6             	mov    %rax,%rsi
    5d25:	48 89 d0             	mov    %rdx,%rax
    5d28:	48 89 d9             	mov    %rbx,%rcx
    5d2b:	48 89 c2             	mov    %rax,%rdx
    5d2e:	e8 94 fa ff ff       	call   57c7 <bFieldStr>
    5d33:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5d37:	48 8d 58 48          	lea    0x48(%rax),%rbx
    5d3b:	48 8d 05 4b 46 00 00 	lea    0x464b(%rip),%rax        # a38d <_IO_stdin_used+0x38d>
    5d42:	be 0a 00 00 00       	mov    $0xa,%esi
    5d47:	48 89 c7             	mov    %rax,%rdi
    5d4a:	e8 33 b7 ff ff       	call   1482 <Slice_from>
    5d4f:	48 8b 4d b8          	mov    -0x48(%rbp),%rcx
    5d53:	48 8b 79 10          	mov    0x10(%rcx),%rdi
    5d57:	48 89 c6             	mov    %rax,%rsi
    5d5a:	48 89 d0             	mov    %rdx,%rax
    5d5d:	48 89 d9             	mov    %rbx,%rcx
    5d60:	48 89 c2             	mov    %rax,%rdx
    5d63:	e8 5f fa ff ff       	call   57c7 <bFieldStr>
    5d68:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5d6c:	48 8d 58 58          	lea    0x58(%rax),%rbx
    5d70:	48 8d 05 21 46 00 00 	lea    0x4621(%rip),%rax        # a398 <_IO_stdin_used+0x398>
    5d77:	be 09 00 00 00       	mov    $0x9,%esi
    5d7c:	48 89 c7             	mov    %rax,%rdi
    5d7f:	e8 fe b6 ff ff       	call   1482 <Slice_from>
    5d84:	48 8b 4d b8          	mov    -0x48(%rbp),%rcx
    5d88:	48 8b 79 10          	mov    0x10(%rcx),%rdi
    5d8c:	48 89 c6             	mov    %rax,%rsi
    5d8f:	48 89 d0             	mov    %rdx,%rax
    5d92:	48 89 d9             	mov    %rbx,%rcx
    5d95:	48 89 c2             	mov    %rax,%rdx
    5d98:	e8 2a fa ff ff       	call   57c7 <bFieldStr>
    5d9d:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    5da1:	ba 08 00 00 00       	mov    $0x8,%edx
    5da6:	be 00 20 00 00       	mov    $0x2000,%esi
    5dab:	48 89 c7             	mov    %rax,%rdi
    5dae:	e8 1e b5 ff ff       	call   12d1 <Arena_alloc>
    5db3:	48 8b 55 b8          	mov    -0x48(%rbp),%rdx
    5db7:	48 89 42 68          	mov    %rax,0x68(%rdx)
    5dbb:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5dbf:	48 8b 58 68          	mov    0x68(%rax),%rbx
    5dc3:	48 8d 05 d8 45 00 00 	lea    0x45d8(%rip),%rax        # a3a2 <_IO_stdin_used+0x3a2>
    5dca:	be 07 00 00 00       	mov    $0x7,%esi
    5dcf:	48 89 c7             	mov    %rax,%rdi
    5dd2:	e8 ab b6 ff ff       	call   1482 <Slice_from>
    5dd7:	48 8b 4d b8          	mov    -0x48(%rbp),%rcx
    5ddb:	48 8b 79 10          	mov    0x10(%rcx),%rdi
    5ddf:	48 8b 4d b0          	mov    -0x50(%rbp),%rcx
    5de3:	48 89 c6             	mov    %rax,%rsi
    5de6:	48 89 d0             	mov    %rdx,%rax
    5de9:	41 b9 00 02 00 00    	mov    $0x200,%r9d
    5def:	49 89 d8             	mov    %rbx,%r8
    5df2:	48 89 c2             	mov    %rax,%rdx
    5df5:	e8 63 fa ff ff       	call   585d <bFieldList>
    5dfa:	48 8b 55 b8          	mov    -0x48(%rbp),%rdx
    5dfe:	89 42 70             	mov    %eax,0x70(%rdx)
    5e01:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    5e05:	ba 08 00 00 00       	mov    $0x8,%edx
    5e0a:	be 00 20 00 00       	mov    $0x2000,%esi
    5e0f:	48 89 c7             	mov    %rax,%rdi
    5e12:	e8 ba b4 ff ff       	call   12d1 <Arena_alloc>
    5e17:	48 8b 55 b8          	mov    -0x48(%rbp),%rdx
    5e1b:	48 89 42 78          	mov    %rax,0x78(%rdx)
    5e1f:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5e23:	48 8b 58 78          	mov    0x78(%rax),%rbx
    5e27:	48 8d 05 7c 45 00 00 	lea    0x457c(%rip),%rax        # a3aa <_IO_stdin_used+0x3aa>
    5e2e:	be 04 00 00 00       	mov    $0x4,%esi
    5e33:	48 89 c7             	mov    %rax,%rdi
    5e36:	e8 47 b6 ff ff       	call   1482 <Slice_from>
    5e3b:	48 8b 4d b8          	mov    -0x48(%rbp),%rcx
    5e3f:	48 8b 79 10          	mov    0x10(%rcx),%rdi
    5e43:	48 8b 4d b0          	mov    -0x50(%rbp),%rcx
    5e47:	48 89 c6             	mov    %rax,%rsi
    5e4a:	48 89 d0             	mov    %rdx,%rax
    5e4d:	41 b9 00 02 00 00    	mov    $0x200,%r9d
    5e53:	49 89 d8             	mov    %rbx,%r8
    5e56:	48 89 c2             	mov    %rax,%rdx
    5e59:	e8 ff f9 ff ff       	call   585d <bFieldList>
    5e5e:	48 8b 55 b8          	mov    -0x48(%rbp),%rdx
    5e62:	89 82 80 00 00 00    	mov    %eax,0x80(%rdx)
    5e68:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5e6c:	8b 40 70             	mov    0x70(%rax),%eax
    5e6f:	85 c0                	test   %eax,%eax
    5e71:	75 30                	jne    5ea3 <bInit+0x414>
    5e73:	48 8d 05 36 45 00 00 	lea    0x4536(%rip),%rax        # a3b0 <_IO_stdin_used+0x3b0>
    5e7a:	48 89 c7             	mov    %rax,%rdi
    5e7d:	e8 ce b1 ff ff       	call   1050 <puts@plt>
    5e82:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5e86:	8b 80 b0 00 00 00    	mov    0xb0(%rax),%eax
    5e8c:	8d 50 01             	lea    0x1(%rax),%edx
    5e8f:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5e93:	89 90 b0 00 00 00    	mov    %edx,0xb0(%rax)
    5e99:	b8 00 00 00 00       	mov    $0x0,%eax
    5e9e:	e9 3b 03 00 00       	jmp    61de <bInit+0x74f>
    5ea3:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5ea7:	8b 40 70             	mov    0x70(%rax),%eax
    5eaa:	89 c0                	mov    %eax,%eax
    5eac:	48 c1 e0 06          	shl    $0x6,%rax
    5eb0:	48 89 c1             	mov    %rax,%rcx
    5eb3:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    5eb7:	ba 08 00 00 00       	mov    $0x8,%edx
    5ebc:	48 89 ce             	mov    %rcx,%rsi
    5ebf:	48 89 c7             	mov    %rax,%rdi
    5ec2:	e8 0a b4 ff ff       	call   12d1 <Arena_alloc>
    5ec7:	48 8b 55 b8          	mov    -0x48(%rbp),%rdx
    5ecb:	48 89 82 98 00 00 00 	mov    %rax,0x98(%rdx)
    5ed2:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5ed6:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    5edd:	48 85 c0             	test   %rax,%rax
    5ee0:	75 0a                	jne    5eec <bInit+0x45d>
    5ee2:	b8 00 00 00 00       	mov    $0x0,%eax
    5ee7:	e9 f2 02 00 00       	jmp    61de <bInit+0x74f>
    5eec:	c7 45 c4 00 00 00 00 	movl   $0x0,-0x3c(%rbp)
    5ef3:	e9 03 01 00 00       	jmp    5ffb <bInit+0x56c>
    5ef8:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5efc:	48 8b 40 68          	mov    0x68(%rax),%rax
    5f00:	8b 55 c4             	mov    -0x3c(%rbp),%edx
    5f03:	48 c1 e2 04          	shl    $0x4,%rdx
    5f07:	48 01 c2             	add    %rax,%rdx
    5f0a:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5f0e:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    5f15:	8b 4d c4             	mov    -0x3c(%rbp),%ecx
    5f18:	48 c1 e1 06          	shl    $0x6,%rcx
    5f1c:	48 01 c1             	add    %rax,%rcx
    5f1f:	48 8b 02             	mov    (%rdx),%rax
    5f22:	48 8b 52 08          	mov    0x8(%rdx),%rdx
    5f26:	48 89 01             	mov    %rax,(%rcx)
    5f29:	48 89 51 08          	mov    %rdx,0x8(%rcx)
    5f2d:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5f31:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    5f38:	8b 55 c4             	mov    -0x3c(%rbp),%edx
    5f3b:	48 c1 e2 06          	shl    $0x6,%rdx
    5f3f:	48 01 d0             	add    %rdx,%rax
    5f42:	48 c7 40 10 00 00 00 	movq   $0x0,0x10(%rax)
    5f49:	00 
    5f4a:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5f4e:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    5f55:	8b 55 c4             	mov    -0x3c(%rbp),%edx
    5f58:	48 c1 e2 06          	shl    $0x6,%rdx
    5f5c:	48 01 d0             	add    %rdx,%rax
    5f5f:	c7 40 18 00 00 00 00 	movl   $0x0,0x18(%rax)
    5f66:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5f6a:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    5f71:	8b 55 c4             	mov    -0x3c(%rbp),%edx
    5f74:	48 c1 e2 06          	shl    $0x6,%rdx
    5f78:	48 01 d0             	add    %rdx,%rax
    5f7b:	c7 40 1c 00 00 00 00 	movl   $0x0,0x1c(%rax)
    5f82:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5f86:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    5f8d:	8b 55 c4             	mov    -0x3c(%rbp),%edx
    5f90:	48 c1 e2 06          	shl    $0x6,%rdx
    5f94:	48 01 d0             	add    %rdx,%rax
    5f97:	48 c7 40 20 00 00 00 	movq   $0x0,0x20(%rax)
    5f9e:	00 
    5f9f:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5fa3:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    5faa:	8b 55 c4             	mov    -0x3c(%rbp),%edx
    5fad:	48 c1 e2 06          	shl    $0x6,%rdx
    5fb1:	48 01 d0             	add    %rdx,%rax
    5fb4:	c7 40 28 00 00 00 00 	movl   $0x0,0x28(%rax)
    5fbb:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5fbf:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    5fc6:	8b 55 c4             	mov    -0x3c(%rbp),%edx
    5fc9:	48 c1 e2 06          	shl    $0x6,%rdx
    5fcd:	48 01 d0             	add    %rdx,%rax
    5fd0:	48 bb 25 23 22 84 e4 	movabs $0xcbf29ce484222325,%rbx
    5fd7:	9c f2 cb 
    5fda:	48 89 58 30          	mov    %rbx,0x30(%rax)
    5fde:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5fe2:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    5fe9:	8b 55 c4             	mov    -0x3c(%rbp),%edx
    5fec:	48 c1 e2 06          	shl    $0x6,%rdx
    5ff0:	48 01 d0             	add    %rdx,%rax
    5ff3:	c6 40 38 01          	movb   $0x1,0x38(%rax)
    5ff7:	83 45 c4 01          	addl   $0x1,-0x3c(%rbp)
    5ffb:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    5fff:	8b 40 70             	mov    0x70(%rax),%eax
    6002:	39 45 c4             	cmp    %eax,-0x3c(%rbp)
    6005:	0f 82 ed fe ff ff    	jb     5ef8 <bInit+0x469>
    600b:	c7 45 c8 00 00 00 00 	movl   $0x0,-0x38(%rbp)
    6012:	c7 45 c0 00 00 00 00 	movl   $0x0,-0x40(%rbp)
    6019:	eb 24                	jmp    603f <bInit+0x5b0>
    601b:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    601f:	48 8b 50 70          	mov    0x70(%rax),%rdx
    6023:	8b 45 c0             	mov    -0x40(%rbp),%eax
    6026:	48 69 c0 98 00 00 00 	imul   $0x98,%rax,%rax
    602d:	48 01 d0             	add    %rdx,%rax
    6030:	8b 00                	mov    (%rax),%eax
    6032:	83 f8 06             	cmp    $0x6,%eax
    6035:	75 04                	jne    603b <bInit+0x5ac>
    6037:	83 45 c8 01          	addl   $0x1,-0x38(%rbp)
    603b:	83 45 c0 01          	addl   $0x1,-0x40(%rbp)
    603f:	8b 55 c0             	mov    -0x40(%rbp),%edx
    6042:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    6046:	48 8b 40 78          	mov    0x78(%rax),%rax
    604a:	48 39 c2             	cmp    %rax,%rdx
    604d:	72 cc                	jb     601b <bInit+0x58c>
    604f:	83 7d c8 00          	cmpl   $0x0,-0x38(%rbp)
    6053:	74 43                	je     6098 <bInit+0x609>
    6055:	8b 45 c8             	mov    -0x38(%rbp),%eax
    6058:	48 c1 e0 05          	shl    $0x5,%rax
    605c:	48 89 c1             	mov    %rax,%rcx
    605f:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    6063:	ba 08 00 00 00       	mov    $0x8,%edx
    6068:	48 89 ce             	mov    %rcx,%rsi
    606b:	48 89 c7             	mov    %rax,%rdi
    606e:	e8 5e b2 ff ff       	call   12d1 <Arena_alloc>
    6073:	48 8b 55 b8          	mov    -0x48(%rbp),%rdx
    6077:	48 89 82 88 00 00 00 	mov    %rax,0x88(%rdx)
    607e:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    6082:	48 8b 80 88 00 00 00 	mov    0x88(%rax),%rax
    6089:	48 85 c0             	test   %rax,%rax
    608c:	75 0a                	jne    6098 <bInit+0x609>
    608e:	b8 00 00 00 00       	mov    $0x0,%eax
    6093:	e9 46 01 00 00       	jmp    61de <bInit+0x74f>
    6098:	c7 45 c0 00 00 00 00 	movl   $0x0,-0x40(%rbp)
    609f:	e9 17 01 00 00       	jmp    61bb <bInit+0x72c>
    60a4:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    60a8:	48 8b 50 70          	mov    0x70(%rax),%rdx
    60ac:	8b 45 c0             	mov    -0x40(%rbp),%eax
    60af:	48 69 c0 98 00 00 00 	imul   $0x98,%rax,%rax
    60b6:	48 01 d0             	add    %rdx,%rax
    60b9:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    60bd:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    60c1:	8b 00                	mov    (%rax),%eax
    60c3:	83 f8 06             	cmp    $0x6,%eax
    60c6:	0f 85 eb 00 00 00    	jne    61b7 <bInit+0x728>
    60cc:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    60d0:	0f b6 40 18          	movzbl 0x18(%rax),%eax
    60d4:	84 c0                	test   %al,%al
    60d6:	0f 84 db 00 00 00    	je     61b7 <bInit+0x728>
    60dc:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    60e0:	0f b6 40 48          	movzbl 0x48(%rax),%eax
    60e4:	84 c0                	test   %al,%al
    60e6:	0f 84 cb 00 00 00    	je     61b7 <bInit+0x728>
    60ec:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    60f0:	48 8b 40 38          	mov    0x38(%rax),%rax
    60f4:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    60f8:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    60fc:	48 8b 40 40          	mov    0x40(%rax),%rax
    6100:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
    6104:	c7 45 cc 00 00 00 00 	movl   $0x0,-0x34(%rbp)
    610b:	eb 1e                	jmp    612b <bInit+0x69c>
    610d:	8b 55 cc             	mov    -0x34(%rbp),%edx
    6110:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    6114:	48 01 d0             	add    %rdx,%rax
    6117:	0f b6 00             	movzbl (%rax),%eax
    611a:	3c 2f                	cmp    $0x2f,%al
    611c:	75 09                	jne    6127 <bInit+0x698>
    611e:	8b 45 cc             	mov    -0x34(%rbp),%eax
    6121:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
    6125:	eb 0d                	jmp    6134 <bInit+0x6a5>
    6127:	83 45 cc 01          	addl   $0x1,-0x34(%rbp)
    612b:	8b 45 cc             	mov    -0x34(%rbp),%eax
    612e:	48 3b 45 d0          	cmp    -0x30(%rbp),%rax
    6132:	72 d9                	jb     610d <bInit+0x67e>
    6134:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    6138:	48 8b 90 88 00 00 00 	mov    0x88(%rax),%rdx
    613f:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    6143:	8b 80 90 00 00 00    	mov    0x90(%rax),%eax
    6149:	89 c0                	mov    %eax,%eax
    614b:	48 c1 e0 05          	shl    $0x5,%rax
    614f:	48 8d 0c 02          	lea    (%rdx,%rax,1),%rcx
    6153:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    6157:	48 8b 50 10          	mov    0x10(%rax),%rdx
    615b:	48 8b 40 08          	mov    0x8(%rax),%rax
    615f:	48 89 01             	mov    %rax,(%rcx)
    6162:	48 89 51 08          	mov    %rdx,0x8(%rcx)
    6166:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    616a:	48 8b 90 88 00 00 00 	mov    0x88(%rax),%rdx
    6171:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    6175:	8b 80 90 00 00 00    	mov    0x90(%rax),%eax
    617b:	89 c0                	mov    %eax,%eax
    617d:	48 c1 e0 05          	shl    $0x5,%rax
    6181:	48 8d 1c 02          	lea    (%rdx,%rax,1),%rbx
    6185:	48 8b 55 d0          	mov    -0x30(%rbp),%rdx
    6189:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    618d:	48 89 d6             	mov    %rdx,%rsi
    6190:	48 89 c7             	mov    %rax,%rdi
    6193:	e8 ea b2 ff ff       	call   1482 <Slice_from>
    6198:	48 89 43 10          	mov    %rax,0x10(%rbx)
    619c:	48 89 53 18          	mov    %rdx,0x18(%rbx)
    61a0:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    61a4:	8b 80 90 00 00 00    	mov    0x90(%rax),%eax
    61aa:	8d 50 01             	lea    0x1(%rax),%edx
    61ad:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    61b1:	89 90 90 00 00 00    	mov    %edx,0x90(%rax)
    61b7:	83 45 c0 01          	addl   $0x1,-0x40(%rbp)
    61bb:	8b 55 c0             	mov    -0x40(%rbp),%edx
    61be:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    61c2:	48 8b 40 78          	mov    0x78(%rax),%rax
    61c6:	48 39 c2             	cmp    %rax,%rdx
    61c9:	0f 82 d5 fe ff ff    	jb     60a4 <bInit+0x615>
    61cf:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    61d3:	8b 80 b0 00 00 00    	mov    0xb0(%rax),%eax
    61d9:	85 c0                	test   %eax,%eax
    61db:	0f 94 c0             	sete   %al
    61de:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
    61e2:	c9                   	leave
    61e3:	c3                   	ret

00000000000061e4 <bResolvePrefix>:
    61e4:	55                   	push   %rbp
    61e5:	48 89 e5             	mov    %rsp,%rbp
    61e8:	48 83 ec 30          	sub    $0x30,%rsp
    61ec:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    61f0:	48 89 f0             	mov    %rsi,%rax
    61f3:	48 89 d6             	mov    %rdx,%rsi
    61f6:	48 89 c0             	mov    %rax,%rax
    61f9:	ba 00 00 00 00       	mov    $0x0,%edx
    61fe:	48 89 f2             	mov    %rsi,%rdx
    6201:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
    6205:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    6209:	48 89 4d e0          	mov    %rcx,-0x20(%rbp)
    620d:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
    6214:	eb 69                	jmp    627f <bResolvePrefix+0x9b>
    6216:	48 8b 4d d8          	mov    -0x28(%rbp),%rcx
    621a:	48 8b 55 d0          	mov    -0x30(%rbp),%rdx
    621e:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    6222:	48 8b 80 88 00 00 00 	mov    0x88(%rax),%rax
    6229:	8b 75 fc             	mov    -0x4(%rbp),%esi
    622c:	48 c1 e6 05          	shl    $0x5,%rsi
    6230:	48 01 f0             	add    %rsi,%rax
    6233:	48 8b 30             	mov    (%rax),%rsi
    6236:	48 8b 40 08          	mov    0x8(%rax),%rax
    623a:	48 89 f7             	mov    %rsi,%rdi
    623d:	48 89 c6             	mov    %rax,%rsi
    6240:	e8 9c e6 ff ff       	call   48e1 <bEq>
    6245:	84 c0                	test   %al,%al
    6247:	74 32                	je     627b <bResolvePrefix+0x97>
    6249:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    624d:	48 8b 80 88 00 00 00 	mov    0x88(%rax),%rax
    6254:	8b 55 fc             	mov    -0x4(%rbp),%edx
    6257:	48 c1 e2 05          	shl    $0x5,%rdx
    625b:	48 01 d0             	add    %rdx,%rax
    625e:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
    6262:	48 8b 50 18          	mov    0x18(%rax),%rdx
    6266:	48 8b 40 10          	mov    0x10(%rax),%rax
    626a:	48 89 01             	mov    %rax,(%rcx)
    626d:	48 89 51 08          	mov    %rdx,0x8(%rcx)
    6271:	b8 01 00 00 00       	mov    $0x1,%eax
    6276:	e9 8c 00 00 00       	jmp    6307 <bResolvePrefix+0x123>
    627b:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
    627f:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    6283:	8b 80 90 00 00 00    	mov    0x90(%rax),%eax
    6289:	39 45 fc             	cmp    %eax,-0x4(%rbp)
    628c:	72 88                	jb     6216 <bResolvePrefix+0x32>
    628e:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
    6295:	eb 5f                	jmp    62f6 <bResolvePrefix+0x112>
    6297:	48 8b 4d d8          	mov    -0x28(%rbp),%rcx
    629b:	48 8b 55 d0          	mov    -0x30(%rbp),%rdx
    629f:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    62a3:	48 8b 40 68          	mov    0x68(%rax),%rax
    62a7:	8b 75 fc             	mov    -0x4(%rbp),%esi
    62aa:	48 c1 e6 04          	shl    $0x4,%rsi
    62ae:	48 01 f0             	add    %rsi,%rax
    62b1:	48 8b 30             	mov    (%rax),%rsi
    62b4:	48 8b 40 08          	mov    0x8(%rax),%rax
    62b8:	48 89 f7             	mov    %rsi,%rdi
    62bb:	48 89 c6             	mov    %rax,%rsi
    62be:	e8 1e e6 ff ff       	call   48e1 <bEq>
    62c3:	84 c0                	test   %al,%al
    62c5:	74 2b                	je     62f2 <bResolvePrefix+0x10e>
    62c7:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    62cb:	48 8b 40 68          	mov    0x68(%rax),%rax
    62cf:	8b 55 fc             	mov    -0x4(%rbp),%edx
    62d2:	48 c1 e2 04          	shl    $0x4,%rdx
    62d6:	48 01 d0             	add    %rdx,%rax
    62d9:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
    62dd:	48 8b 50 08          	mov    0x8(%rax),%rdx
    62e1:	48 8b 00             	mov    (%rax),%rax
    62e4:	48 89 01             	mov    %rax,(%rcx)
    62e7:	48 89 51 08          	mov    %rdx,0x8(%rcx)
    62eb:	b8 01 00 00 00       	mov    $0x1,%eax
    62f0:	eb 15                	jmp    6307 <bResolvePrefix+0x123>
    62f2:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
    62f6:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    62fa:	8b 40 70             	mov    0x70(%rax),%eax
    62fd:	39 45 fc             	cmp    %eax,-0x4(%rbp)
    6300:	72 95                	jb     6297 <bResolvePrefix+0xb3>
    6302:	b8 00 00 00 00       	mov    $0x0,%eax
    6307:	c9                   	leave
    6308:	c3                   	ret

0000000000006309 <bModuleIdx>:
    6309:	55                   	push   %rbp
    630a:	48 89 e5             	mov    %rsp,%rbp
    630d:	48 83 ec 30          	sub    $0x30,%rsp
    6311:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    6315:	48 89 f0             	mov    %rsi,%rax
    6318:	48 89 d1             	mov    %rdx,%rcx
    631b:	48 89 c0             	mov    %rax,%rax
    631e:	ba 00 00 00 00       	mov    $0x0,%edx
    6323:	48 89 ca             	mov    %rcx,%rdx
    6326:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
    632a:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    632e:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
    6335:	eb 39                	jmp    6370 <bModuleIdx+0x67>
    6337:	48 8b 4d d8          	mov    -0x28(%rbp),%rcx
    633b:	48 8b 55 d0          	mov    -0x30(%rbp),%rdx
    633f:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    6343:	48 8b 40 68          	mov    0x68(%rax),%rax
    6347:	8b 75 fc             	mov    -0x4(%rbp),%esi
    634a:	48 c1 e6 04          	shl    $0x4,%rsi
    634e:	48 01 f0             	add    %rsi,%rax
    6351:	48 8b 30             	mov    (%rax),%rsi
    6354:	48 8b 40 08          	mov    0x8(%rax),%rax
    6358:	48 89 f7             	mov    %rsi,%rdi
    635b:	48 89 c6             	mov    %rax,%rsi
    635e:	e8 7e e5 ff ff       	call   48e1 <bEq>
    6363:	84 c0                	test   %al,%al
    6365:	74 05                	je     636c <bModuleIdx+0x63>
    6367:	8b 45 fc             	mov    -0x4(%rbp),%eax
    636a:	eb 15                	jmp    6381 <bModuleIdx+0x78>
    636c:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
    6370:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    6374:	8b 40 70             	mov    0x70(%rax),%eax
    6377:	39 45 fc             	cmp    %eax,-0x4(%rbp)
    637a:	72 bb                	jb     6337 <bModuleIdx+0x2e>
    637c:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
    6381:	c9                   	leave
    6382:	c3                   	ret

0000000000006383 <bScanLib>:
    6383:	55                   	push   %rbp
    6384:	48 89 e5             	mov    %rsp,%rbp
    6387:	53                   	push   %rbx
    6388:	48 83 ec 58          	sub    $0x58,%rsp
    638c:	48 89 7d b8          	mov    %rdi,-0x48(%rbp)
    6390:	48 89 f0             	mov    %rsi,%rax
    6393:	48 89 d1             	mov    %rdx,%rcx
    6396:	48 89 c0             	mov    %rax,%rax
    6399:	ba 00 00 00 00       	mov    $0x0,%edx
    639e:	48 89 ca             	mov    %rcx,%rdx
    63a1:	48 89 45 a0          	mov    %rax,-0x60(%rbp)
    63a5:	48 89 55 a8          	mov    %rdx,-0x58(%rbp)
    63a9:	bf 00 10 00 00       	mov    $0x1000,%edi
    63ae:	e8 2d ad ff ff       	call   10e0 <malloc@plt>
    63b3:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
    63b7:	48 8b 4d a0          	mov    -0x60(%rbp),%rcx
    63bb:	48 8b 5d a8          	mov    -0x58(%rbp),%rbx
    63bf:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    63c3:	48 8b 50 20          	mov    0x20(%rax),%rdx
    63c7:	48 8b 40 18          	mov    0x18(%rax),%rax
    63cb:	48 8b 7d d0          	mov    -0x30(%rbp),%rdi
    63cf:	49 89 c8             	mov    %rcx,%r8
    63d2:	49 89 d9             	mov    %rbx,%r9
    63d5:	48 89 d1             	mov    %rdx,%rcx
    63d8:	48 89 c2             	mov    %rax,%rdx
    63db:	be 00 10 00 00       	mov    $0x1000,%esi
    63e0:	e8 4a e7 ff ff       	call   4b2f <bJoin>
    63e5:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
    63e9:	48 8d 05 f2 3f 00 00 	lea    0x3ff2(%rip),%rax        # a3e2 <_IO_stdin_used+0x3e2>
    63f0:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    63f4:	48 c7 45 c0 00 00 00 	movq   $0x0,-0x40(%rbp)
    63fb:	00 
    63fc:	eb 27                	jmp    6425 <bScanLib+0xa2>
    63fe:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    6402:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
    6406:	48 01 d0             	add    %rdx,%rax
    6409:	48 8b 4d d8          	mov    -0x28(%rbp),%rcx
    640d:	48 8b 55 c0          	mov    -0x40(%rbp),%rdx
    6411:	48 01 d1             	add    %rdx,%rcx
    6414:	48 8b 55 d0          	mov    -0x30(%rbp),%rdx
    6418:	48 01 ca             	add    %rcx,%rdx
    641b:	0f b6 00             	movzbl (%rax),%eax
    641e:	88 02                	mov    %al,(%rdx)
    6420:	48 83 45 c0 01       	addq   $0x1,-0x40(%rbp)
    6425:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    6429:	48 83 c0 08          	add    $0x8,%rax
    642d:	48 3d ff 0f 00 00    	cmp    $0xfff,%rax
    6433:	77 07                	ja     643c <bScanLib+0xb9>
    6435:	48 83 7d c0 07       	cmpq   $0x7,-0x40(%rbp)
    643a:	76 c2                	jbe    63fe <bScanLib+0x7b>
    643c:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    6440:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
    6444:	48 01 c2             	add    %rax,%rdx
    6447:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    644b:	48 01 d0             	add    %rdx,%rax
    644e:	c6 00 00             	movb   $0x0,(%rax)
    6451:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    6455:	48 89 c7             	mov    %rax,%rdi
    6458:	e8 a8 e8 ff ff       	call   4d05 <bFileExists>
    645d:	83 f0 01             	xor    $0x1,%eax
    6460:	84 c0                	test   %al,%al
    6462:	0f 84 9c 00 00 00    	je     6504 <bScanLib+0x181>
    6468:	bf 00 01 00 00       	mov    $0x100,%edi
    646d:	e8 6e ac ff ff       	call   10e0 <malloc@plt>
    6472:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    6476:	48 c7 45 c8 00 00 00 	movq   $0x0,-0x38(%rbp)
    647d:	00 
    647e:	eb 20                	jmp    64a0 <bScanLib+0x11d>
    6480:	48 8b 55 a0          	mov    -0x60(%rbp),%rdx
    6484:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    6488:	48 01 d0             	add    %rdx,%rax
    648b:	48 8b 4d e8          	mov    -0x18(%rbp),%rcx
    648f:	48 8b 55 c8          	mov    -0x38(%rbp),%rdx
    6493:	48 01 ca             	add    %rcx,%rdx
    6496:	0f b6 00             	movzbl (%rax),%eax
    6499:	88 02                	mov    %al,(%rdx)
    649b:	48 83 45 c8 01       	addq   $0x1,-0x38(%rbp)
    64a0:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    64a4:	48 39 45 c8          	cmp    %rax,-0x38(%rbp)
    64a8:	73 0a                	jae    64b4 <bScanLib+0x131>
    64aa:	48 81 7d c8 fe 00 00 	cmpq   $0xfe,-0x38(%rbp)
    64b1:	00 
    64b2:	76 cc                	jbe    6480 <bScanLib+0xfd>
    64b4:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    64b8:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    64bc:	48 01 d0             	add    %rdx,%rax
    64bf:	c6 00 00             	movb   $0x0,(%rax)
    64c2:	4c 8d 0d 22 3f 00 00 	lea    0x3f22(%rip),%r9        # a3eb <_IO_stdin_used+0x3eb>
    64c9:	4c 8b 45 e8          	mov    -0x18(%rbp),%r8
    64cd:	48 8d 0d 1c 3f 00 00 	lea    0x3f1c(%rip),%rcx        # a3f0 <_IO_stdin_used+0x3f0>
    64d4:	48 8d 15 1c 3f 00 00 	lea    0x3f1c(%rip),%rdx        # a3f7 <_IO_stdin_used+0x3f7>
    64db:	48 8d 35 25 3f 00 00 	lea    0x3f25(%rip),%rsi        # a407 <_IO_stdin_used+0x407>
    64e2:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    64e6:	48 8d 3d 23 3f 00 00 	lea    0x3f23(%rip),%rdi        # a410 <_IO_stdin_used+0x410>
    64ed:	57                   	push   %rdi
    64ee:	ff 75 d0             	push   -0x30(%rbp)
    64f1:	48 89 c7             	mov    %rax,%rdi
    64f4:	e8 cf f4 ff ff       	call   59c8 <bError>
    64f9:	48 83 c4 10          	add    $0x10,%rsp
    64fd:	b8 00 00 00 00       	mov    $0x0,%eax
    6502:	eb 05                	jmp    6509 <bScanLib+0x186>
    6504:	b8 01 00 00 00       	mov    $0x1,%eax
    6509:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
    650d:	c9                   	leave
    650e:	c3                   	ret

000000000000650f <bValidateAliases>:
    650f:	55                   	push   %rbp
    6510:	48 89 e5             	mov    %rsp,%rbp
    6513:	48 83 ec 40          	sub    $0x40,%rsp
    6517:	48 89 7d c8          	mov    %rdi,-0x38(%rbp)
    651b:	c7 45 d8 00 00 00 00 	movl   $0x0,-0x28(%rbp)
    6522:	e9 86 01 00 00       	jmp    66ad <bValidateAliases+0x19e>
    6527:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    652b:	48 8b 80 88 00 00 00 	mov    0x88(%rax),%rax
    6532:	8b 55 d8             	mov    -0x28(%rbp),%edx
    6535:	48 c1 e2 05          	shl    $0x5,%rdx
    6539:	48 01 d0             	add    %rdx,%rax
    653c:	48 8b 48 10          	mov    0x10(%rax),%rcx
    6540:	48 8b 50 18          	mov    0x18(%rax),%rdx
    6544:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    6548:	48 89 ce             	mov    %rcx,%rsi
    654b:	48 89 c7             	mov    %rax,%rdi
    654e:	e8 b6 fd ff ff       	call   6309 <bModuleIdx>
    6553:	89 45 dc             	mov    %eax,-0x24(%rbp)
    6556:	83 7d dc 00          	cmpl   $0x0,-0x24(%rbp)
    655a:	0f 89 49 01 00 00    	jns    66a9 <bValidateAliases+0x19a>
    6560:	bf 00 01 00 00       	mov    $0x100,%edi
    6565:	e8 76 ab ff ff       	call   10e0 <malloc@plt>
    656a:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    656e:	48 c7 45 e0 00 00 00 	movq   $0x0,-0x20(%rbp)
    6575:	00 
    6576:	eb 34                	jmp    65ac <bValidateAliases+0x9d>
    6578:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    657c:	48 8b 80 88 00 00 00 	mov    0x88(%rax),%rax
    6583:	8b 55 d8             	mov    -0x28(%rbp),%edx
    6586:	48 c1 e2 05          	shl    $0x5,%rdx
    658a:	48 01 d0             	add    %rdx,%rax
    658d:	48 8b 10             	mov    (%rax),%rdx
    6590:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    6594:	48 01 d0             	add    %rdx,%rax
    6597:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
    659b:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    659f:	48 01 ca             	add    %rcx,%rdx
    65a2:	0f b6 00             	movzbl (%rax),%eax
    65a5:	88 02                	mov    %al,(%rdx)
    65a7:	48 83 45 e0 01       	addq   $0x1,-0x20(%rbp)
    65ac:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    65b0:	48 8b 80 88 00 00 00 	mov    0x88(%rax),%rax
    65b7:	8b 55 d8             	mov    -0x28(%rbp),%edx
    65ba:	48 c1 e2 05          	shl    $0x5,%rdx
    65be:	48 01 d0             	add    %rdx,%rax
    65c1:	48 8b 40 08          	mov    0x8(%rax),%rax
    65c5:	48 39 45 e0          	cmp    %rax,-0x20(%rbp)
    65c9:	73 0a                	jae    65d5 <bValidateAliases+0xc6>
    65cb:	48 81 7d e0 fe 00 00 	cmpq   $0xfe,-0x20(%rbp)
    65d2:	00 
    65d3:	76 a3                	jbe    6578 <bValidateAliases+0x69>
    65d5:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
    65d9:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    65dd:	48 01 d0             	add    %rdx,%rax
    65e0:	c6 00 00             	movb   $0x0,(%rax)
    65e3:	bf 00 01 00 00       	mov    $0x100,%edi
    65e8:	e8 f3 aa ff ff       	call   10e0 <malloc@plt>
    65ed:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    65f1:	48 c7 45 e8 00 00 00 	movq   $0x0,-0x18(%rbp)
    65f8:	00 
    65f9:	eb 35                	jmp    6630 <bValidateAliases+0x121>
    65fb:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    65ff:	48 8b 80 88 00 00 00 	mov    0x88(%rax),%rax
    6606:	8b 55 d8             	mov    -0x28(%rbp),%edx
    6609:	48 c1 e2 05          	shl    $0x5,%rdx
    660d:	48 01 d0             	add    %rdx,%rax
    6610:	48 8b 50 10          	mov    0x10(%rax),%rdx
    6614:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    6618:	48 01 d0             	add    %rdx,%rax
    661b:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
    661f:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    6623:	48 01 ca             	add    %rcx,%rdx
    6626:	0f b6 00             	movzbl (%rax),%eax
    6629:	88 02                	mov    %al,(%rdx)
    662b:	48 83 45 e8 01       	addq   $0x1,-0x18(%rbp)
    6630:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    6634:	48 8b 80 88 00 00 00 	mov    0x88(%rax),%rax
    663b:	8b 55 d8             	mov    -0x28(%rbp),%edx
    663e:	48 c1 e2 05          	shl    $0x5,%rdx
    6642:	48 01 d0             	add    %rdx,%rax
    6645:	48 8b 40 18          	mov    0x18(%rax),%rax
    6649:	48 39 45 e8          	cmp    %rax,-0x18(%rbp)
    664d:	73 0a                	jae    6659 <bValidateAliases+0x14a>
    664f:	48 81 7d e8 fe 00 00 	cmpq   $0xfe,-0x18(%rbp)
    6656:	00 
    6657:	76 a2                	jbe    65fb <bValidateAliases+0xec>
    6659:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
    665d:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    6661:	48 01 d0             	add    %rdx,%rax
    6664:	c6 00 00             	movb   $0x0,(%rax)
    6667:	4c 8d 0d f1 39 00 00 	lea    0x39f1(%rip),%r9        # a05f <_IO_stdin_used+0x5f>
    666e:	4c 8b 45 f0          	mov    -0x10(%rbp),%r8
    6672:	48 8d 0d c5 39 00 00 	lea    0x39c5(%rip),%rcx        # a03e <_IO_stdin_used+0x3e>
    6679:	48 8d 15 c0 3d 00 00 	lea    0x3dc0(%rip),%rdx        # a440 <_IO_stdin_used+0x440>
    6680:	48 8d 35 d8 3d 00 00 	lea    0x3dd8(%rip),%rsi        # a45f <_IO_stdin_used+0x45f>
    6687:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    668b:	48 8d 3d d3 3d 00 00 	lea    0x3dd3(%rip),%rdi        # a465 <_IO_stdin_used+0x465>
    6692:	57                   	push   %rdi
    6693:	ff 75 f8             	push   -0x8(%rbp)
    6696:	48 89 c7             	mov    %rax,%rdi
    6699:	e8 2a f3 ff ff       	call   59c8 <bError>
    669e:	48 83 c4 10          	add    $0x10,%rsp
    66a2:	b8 00 00 00 00       	mov    $0x0,%eax
    66a7:	eb 1c                	jmp    66c5 <bValidateAliases+0x1b6>
    66a9:	83 45 d8 01          	addl   $0x1,-0x28(%rbp)
    66ad:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    66b1:	8b 80 90 00 00 00    	mov    0x90(%rax),%eax
    66b7:	39 45 d8             	cmp    %eax,-0x28(%rbp)
    66ba:	0f 82 67 fe ff ff    	jb     6527 <bValidateAliases+0x18>
    66c0:	b8 01 00 00 00       	mov    $0x1,%eax
    66c5:	c9                   	leave
    66c6:	c3                   	ret

00000000000066c7 <bWriteFile>:
    66c7:	55                   	push   %rbp
    66c8:	48 89 e5             	mov    %rsp,%rbp
    66cb:	48 83 ec 30          	sub    $0x30,%rsp
    66cf:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    66d3:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    66d7:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    66db:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    66df:	ba a4 01 00 00       	mov    $0x1a4,%edx
    66e4:	be 41 02 00 00       	mov    $0x241,%esi
    66e9:	48 89 c7             	mov    %rax,%rdi
    66ec:	e8 0f aa ff ff       	call   1100 <open@plt>
    66f1:	89 45 f8             	mov    %eax,-0x8(%rbp)
    66f4:	83 7d f8 00          	cmpl   $0x0,-0x8(%rbp)
    66f8:	79 07                	jns    6701 <bWriteFile+0x3a>
    66fa:	b8 00 00 00 00       	mov    $0x0,%eax
    66ff:	eb 2a                	jmp    672b <bWriteFile+0x64>
    6701:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    6705:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
    6709:	8b 45 f8             	mov    -0x8(%rbp),%eax
    670c:	48 89 ce             	mov    %rcx,%rsi
    670f:	89 c7                	mov    %eax,%edi
    6711:	e8 4a a9 ff ff       	call   1060 <write@plt>
    6716:	89 45 fc             	mov    %eax,-0x4(%rbp)
    6719:	8b 45 f8             	mov    -0x8(%rbp),%eax
    671c:	89 c7                	mov    %eax,%edi
    671e:	e8 7d a9 ff ff       	call   10a0 <close@plt>
    6723:	8b 45 fc             	mov    -0x4(%rbp),%eax
    6726:	f7 d0                	not    %eax
    6728:	c1 e8 1f             	shr    $0x1f,%eax
    672b:	c9                   	leave
    672c:	c3                   	ret

000000000000672d <bWriteMap>:
    672d:	55                   	push   %rbp
    672e:	48 89 e5             	mov    %rsp,%rbp
    6731:	53                   	push   %rbx
    6732:	48 81 ec 88 00 00 00 	sub    $0x88,%rsp
    6739:	48 89 bd 78 ff ff ff 	mov    %rdi,-0x88(%rbp)
    6740:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    6747:	00 00 
    6749:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    674d:	31 c0                	xor    %eax,%eax
    674f:	48 8d 05 25 3d 00 00 	lea    0x3d25(%rip),%rax        # a47b <_IO_stdin_used+0x47b>
    6756:	ba ed 01 00 00       	mov    $0x1ed,%edx
    675b:	48 89 c6             	mov    %rax,%rsi
    675e:	bf 53 00 00 00       	mov    $0x53,%edi
    6763:	b8 00 00 00 00       	mov    $0x0,%eax
    6768:	e8 53 a9 ff ff       	call   10c0 <syscall@plt>
    676d:	48 c7 45 b0 00 00 04 	movq   $0x40000,-0x50(%rbp)
    6774:	00 
    6775:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    6779:	48 89 c7             	mov    %rax,%rdi
    677c:	e8 5f a9 ff ff       	call   10e0 <malloc@plt>
    6781:	48 89 45 b8          	mov    %rax,-0x48(%rbp)
    6785:	48 83 7d b8 00       	cmpq   $0x0,-0x48(%rbp)
    678a:	75 0a                	jne    6796 <bWriteMap+0x69>
    678c:	b8 00 00 00 00       	mov    $0x0,%eax
    6791:	e9 cd 04 00 00       	jmp    6c63 <bWriteMap+0x536>
    6796:	48 c7 45 90 00 00 00 	movq   $0x0,-0x70(%rbp)
    679d:	00 
    679e:	48 8d 05 e3 3c 00 00 	lea    0x3ce3(%rip),%rax        # a488 <_IO_stdin_used+0x488>
    67a5:	48 89 45 c0          	mov    %rax,-0x40(%rbp)
    67a9:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
    67ad:	48 89 c7             	mov    %rax,%rdi
    67b0:	e8 bb a8 ff ff       	call   1070 <strlen@plt>
    67b5:	48 89 c7             	mov    %rax,%rdi
    67b8:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
    67bc:	48 8d 55 90          	lea    -0x70(%rbp),%rdx
    67c0:	48 8b 75 b0          	mov    -0x50(%rbp),%rsi
    67c4:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    67c8:	49 89 f8             	mov    %rdi,%r8
    67cb:	48 89 c7             	mov    %rax,%rdi
    67ce:	e8 ba e4 ff ff       	call   4c8d <bApp>
    67d3:	c7 45 88 00 00 00 00 	movl   $0x0,-0x78(%rbp)
    67da:	e9 7f 01 00 00       	jmp    695e <bWriteMap+0x231>
    67df:	48 8d 0d e7 3c 00 00 	lea    0x3ce7(%rip),%rcx        # a4cd <_IO_stdin_used+0x4cd>
    67e6:	48 8d 55 90          	lea    -0x70(%rbp),%rdx
    67ea:	48 8b 75 b0          	mov    -0x50(%rbp),%rsi
    67ee:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    67f2:	41 b8 02 00 00 00    	mov    $0x2,%r8d
    67f8:	48 89 c7             	mov    %rax,%rdi
    67fb:	e8 8d e4 ff ff       	call   4c8d <bApp>
    6800:	48 8b 85 78 ff ff ff 	mov    -0x88(%rbp),%rax
    6807:	48 8b 40 68          	mov    0x68(%rax),%rax
    680b:	8b 55 88             	mov    -0x78(%rbp),%edx
    680e:	48 c1 e2 04          	shl    $0x4,%rdx
    6812:	48 01 d0             	add    %rdx,%rax
    6815:	48 8b 78 08          	mov    0x8(%rax),%rdi
    6819:	48 8b 85 78 ff ff ff 	mov    -0x88(%rbp),%rax
    6820:	48 8b 40 68          	mov    0x68(%rax),%rax
    6824:	8b 55 88             	mov    -0x78(%rbp),%edx
    6827:	48 c1 e2 04          	shl    $0x4,%rdx
    682b:	48 01 d0             	add    %rdx,%rax
    682e:	48 8b 08             	mov    (%rax),%rcx
    6831:	48 8d 55 90          	lea    -0x70(%rbp),%rdx
    6835:	48 8b 75 b0          	mov    -0x50(%rbp),%rsi
    6839:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    683d:	49 89 f8             	mov    %rdi,%r8
    6840:	48 89 c7             	mov    %rax,%rdi
    6843:	e8 45 e4 ff ff       	call   4c8d <bApp>
    6848:	48 8b 85 78 ff ff ff 	mov    -0x88(%rbp),%rax
    684f:	48 8b 40 68          	mov    0x68(%rax),%rax
    6853:	8b 55 88             	mov    -0x78(%rbp),%edx
    6856:	48 c1 e2 04          	shl    $0x4,%rdx
    685a:	48 01 d0             	add    %rdx,%rax
    685d:	48 8b 40 08          	mov    0x8(%rax),%rax
    6861:	48 83 c0 02          	add    $0x2,%rax
    6865:	48 89 45 98          	mov    %rax,-0x68(%rbp)
    6869:	eb 1f                	jmp    688a <bWriteMap+0x15d>
    686b:	48 8b 55 90          	mov    -0x70(%rbp),%rdx
    686f:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    6873:	48 01 d0             	add    %rdx,%rax
    6876:	c6 00 20             	movb   $0x20,(%rax)
    6879:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    687d:	48 83 c0 01          	add    $0x1,%rax
    6881:	48 89 45 90          	mov    %rax,-0x70(%rbp)
    6885:	48 83 45 98 01       	addq   $0x1,-0x68(%rbp)
    688a:	48 83 7d 98 17       	cmpq   $0x17,-0x68(%rbp)
    688f:	77 0a                	ja     689b <bWriteMap+0x16e>
    6891:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    6895:	48 3b 45 b0          	cmp    -0x50(%rbp),%rax
    6899:	72 d0                	jb     686b <bWriteMap+0x13e>
    689b:	48 8d 0d 2e 3c 00 00 	lea    0x3c2e(%rip),%rcx        # a4d0 <_IO_stdin_used+0x4d0>
    68a2:	48 8d 55 90          	lea    -0x70(%rbp),%rdx
    68a6:	48 8b 75 b0          	mov    -0x50(%rbp),%rsi
    68aa:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    68ae:	41 b8 06 00 00 00    	mov    $0x6,%r8d
    68b4:	48 89 c7             	mov    %rax,%rdi
    68b7:	e8 d1 e3 ff ff       	call   4c8d <bApp>
    68bc:	bf 00 10 00 00       	mov    $0x1000,%edi
    68c1:	e8 1a a8 ff ff       	call   10e0 <malloc@plt>
    68c6:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
    68ca:	48 8b 85 78 ff ff ff 	mov    -0x88(%rbp),%rax
    68d1:	48 8b 40 68          	mov    0x68(%rax),%rax
    68d5:	8b 55 88             	mov    -0x78(%rbp),%edx
    68d8:	48 c1 e2 04          	shl    $0x4,%rdx
    68dc:	48 01 d0             	add    %rdx,%rax
    68df:	48 8b 08             	mov    (%rax),%rcx
    68e2:	48 8b 58 08          	mov    0x8(%rax),%rbx
    68e6:	48 8b 85 78 ff ff ff 	mov    -0x88(%rbp),%rax
    68ed:	48 8b 50 20          	mov    0x20(%rax),%rdx
    68f1:	48 8b 40 18          	mov    0x18(%rax),%rax
    68f5:	48 8b 7d d8          	mov    -0x28(%rbp),%rdi
    68f9:	49 89 c8             	mov    %rcx,%r8
    68fc:	49 89 d9             	mov    %rbx,%r9
    68ff:	48 89 d1             	mov    %rdx,%rcx
    6902:	48 89 c2             	mov    %rax,%rdx
    6905:	be 00 10 00 00       	mov    $0x1000,%esi
    690a:	e8 20 e2 ff ff       	call   4b2f <bJoin>
    690f:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    6913:	48 8b 7d e0          	mov    -0x20(%rbp),%rdi
    6917:	48 8b 4d d8          	mov    -0x28(%rbp),%rcx
    691b:	48 8d 55 90          	lea    -0x70(%rbp),%rdx
    691f:	48 8b 75 b0          	mov    -0x50(%rbp),%rsi
    6923:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    6927:	49 89 f8             	mov    %rdi,%r8
    692a:	48 89 c7             	mov    %rax,%rdi
    692d:	e8 5b e3 ff ff       	call   4c8d <bApp>
    6932:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    6936:	48 83 c0 01          	add    $0x1,%rax
    693a:	48 3b 45 b0          	cmp    -0x50(%rbp),%rax
    693e:	73 1a                	jae    695a <bWriteMap+0x22d>
    6940:	48 8b 55 90          	mov    -0x70(%rbp),%rdx
    6944:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    6948:	48 01 d0             	add    %rdx,%rax
    694b:	c6 00 0a             	movb   $0xa,(%rax)
    694e:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    6952:	48 83 c0 01          	add    $0x1,%rax
    6956:	48 89 45 90          	mov    %rax,-0x70(%rbp)
    695a:	83 45 88 01          	addl   $0x1,-0x78(%rbp)
    695e:	48 8b 85 78 ff ff ff 	mov    -0x88(%rbp),%rax
    6965:	8b 40 70             	mov    0x70(%rax),%eax
    6968:	39 45 88             	cmp    %eax,-0x78(%rbp)
    696b:	0f 82 6e fe ff ff    	jb     67df <bWriteMap+0xb2>
    6971:	48 8b 85 78 ff ff ff 	mov    -0x88(%rbp),%rax
    6978:	8b 80 90 00 00 00    	mov    0x90(%rax),%eax
    697e:	85 c0                	test   %eax,%eax
    6980:	0f 84 08 02 00 00    	je     6b8e <bWriteMap+0x461>
    6986:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    698a:	48 83 c0 01          	add    $0x1,%rax
    698e:	48 3b 45 b0          	cmp    -0x50(%rbp),%rax
    6992:	73 1a                	jae    69ae <bWriteMap+0x281>
    6994:	48 8b 55 90          	mov    -0x70(%rbp),%rdx
    6998:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    699c:	48 01 d0             	add    %rdx,%rax
    699f:	c6 00 0a             	movb   $0xa,(%rax)
    69a2:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    69a6:	48 83 c0 01          	add    $0x1,%rax
    69aa:	48 89 45 90          	mov    %rax,-0x70(%rbp)
    69ae:	48 8d 05 22 3b 00 00 	lea    0x3b22(%rip),%rax        # a4d7 <_IO_stdin_used+0x4d7>
    69b5:	48 89 45 c8          	mov    %rax,-0x38(%rbp)
    69b9:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    69bd:	48 89 c7             	mov    %rax,%rdi
    69c0:	e8 ab a6 ff ff       	call   1070 <strlen@plt>
    69c5:	48 89 c7             	mov    %rax,%rdi
    69c8:	48 8b 4d c8          	mov    -0x38(%rbp),%rcx
    69cc:	48 8d 55 90          	lea    -0x70(%rbp),%rdx
    69d0:	48 8b 75 b0          	mov    -0x50(%rbp),%rsi
    69d4:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    69d8:	49 89 f8             	mov    %rdi,%r8
    69db:	48 89 c7             	mov    %rax,%rdi
    69de:	e8 aa e2 ff ff       	call   4c8d <bApp>
    69e3:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    69e7:	48 83 c0 01          	add    $0x1,%rax
    69eb:	48 3b 45 b0          	cmp    -0x50(%rbp),%rax
    69ef:	73 1a                	jae    6a0b <bWriteMap+0x2de>
    69f1:	48 8b 55 90          	mov    -0x70(%rbp),%rdx
    69f5:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    69f9:	48 01 d0             	add    %rdx,%rax
    69fc:	c6 00 0a             	movb   $0xa,(%rax)
    69ff:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    6a03:	48 83 c0 01          	add    $0x1,%rax
    6a07:	48 89 45 90          	mov    %rax,-0x70(%rbp)
    6a0b:	c7 45 8c 00 00 00 00 	movl   $0x0,-0x74(%rbp)
    6a12:	e9 61 01 00 00       	jmp    6b78 <bWriteMap+0x44b>
    6a17:	48 8d 0d d5 3a 00 00 	lea    0x3ad5(%rip),%rcx        # a4f3 <_IO_stdin_used+0x4f3>
    6a1e:	48 8d 55 90          	lea    -0x70(%rbp),%rdx
    6a22:	48 8b 75 b0          	mov    -0x50(%rbp),%rsi
    6a26:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    6a2a:	41 b8 02 00 00 00    	mov    $0x2,%r8d
    6a30:	48 89 c7             	mov    %rax,%rdi
    6a33:	e8 55 e2 ff ff       	call   4c8d <bApp>
    6a38:	48 8b 85 78 ff ff ff 	mov    -0x88(%rbp),%rax
    6a3f:	48 8b 80 88 00 00 00 	mov    0x88(%rax),%rax
    6a46:	8b 55 8c             	mov    -0x74(%rbp),%edx
    6a49:	48 c1 e2 05          	shl    $0x5,%rdx
    6a4d:	48 01 d0             	add    %rdx,%rax
    6a50:	48 8b 78 08          	mov    0x8(%rax),%rdi
    6a54:	48 8b 85 78 ff ff ff 	mov    -0x88(%rbp),%rax
    6a5b:	48 8b 80 88 00 00 00 	mov    0x88(%rax),%rax
    6a62:	8b 55 8c             	mov    -0x74(%rbp),%edx
    6a65:	48 c1 e2 05          	shl    $0x5,%rdx
    6a69:	48 01 d0             	add    %rdx,%rax
    6a6c:	48 8b 08             	mov    (%rax),%rcx
    6a6f:	48 8d 55 90          	lea    -0x70(%rbp),%rdx
    6a73:	48 8b 75 b0          	mov    -0x50(%rbp),%rsi
    6a77:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    6a7b:	49 89 f8             	mov    %rdi,%r8
    6a7e:	48 89 c7             	mov    %rax,%rdi
    6a81:	e8 07 e2 ff ff       	call   4c8d <bApp>
    6a86:	48 8b 85 78 ff ff ff 	mov    -0x88(%rbp),%rax
    6a8d:	48 8b 80 88 00 00 00 	mov    0x88(%rax),%rax
    6a94:	8b 55 8c             	mov    -0x74(%rbp),%edx
    6a97:	48 c1 e2 05          	shl    $0x5,%rdx
    6a9b:	48 01 d0             	add    %rdx,%rax
    6a9e:	48 8b 40 08          	mov    0x8(%rax),%rax
    6aa2:	48 83 c0 02          	add    $0x2,%rax
    6aa6:	48 89 45 a0          	mov    %rax,-0x60(%rbp)
    6aaa:	eb 1f                	jmp    6acb <bWriteMap+0x39e>
    6aac:	48 8b 55 90          	mov    -0x70(%rbp),%rdx
    6ab0:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    6ab4:	48 01 d0             	add    %rdx,%rax
    6ab7:	c6 00 20             	movb   $0x20,(%rax)
    6aba:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    6abe:	48 83 c0 01          	add    $0x1,%rax
    6ac2:	48 89 45 90          	mov    %rax,-0x70(%rbp)
    6ac6:	48 83 45 a0 01       	addq   $0x1,-0x60(%rbp)
    6acb:	48 83 7d a0 17       	cmpq   $0x17,-0x60(%rbp)
    6ad0:	77 0a                	ja     6adc <bWriteMap+0x3af>
    6ad2:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    6ad6:	48 3b 45 b0          	cmp    -0x50(%rbp),%rax
    6ada:	72 d0                	jb     6aac <bWriteMap+0x37f>
    6adc:	48 8d 0d ed 39 00 00 	lea    0x39ed(%rip),%rcx        # a4d0 <_IO_stdin_used+0x4d0>
    6ae3:	48 8d 55 90          	lea    -0x70(%rbp),%rdx
    6ae7:	48 8b 75 b0          	mov    -0x50(%rbp),%rsi
    6aeb:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    6aef:	41 b8 06 00 00 00    	mov    $0x6,%r8d
    6af5:	48 89 c7             	mov    %rax,%rdi
    6af8:	e8 90 e1 ff ff       	call   4c8d <bApp>
    6afd:	48 8b 85 78 ff ff ff 	mov    -0x88(%rbp),%rax
    6b04:	48 8b 80 88 00 00 00 	mov    0x88(%rax),%rax
    6b0b:	8b 55 8c             	mov    -0x74(%rbp),%edx
    6b0e:	48 c1 e2 05          	shl    $0x5,%rdx
    6b12:	48 01 d0             	add    %rdx,%rax
    6b15:	48 8b 78 18          	mov    0x18(%rax),%rdi
    6b19:	48 8b 85 78 ff ff ff 	mov    -0x88(%rbp),%rax
    6b20:	48 8b 80 88 00 00 00 	mov    0x88(%rax),%rax
    6b27:	8b 55 8c             	mov    -0x74(%rbp),%edx
    6b2a:	48 c1 e2 05          	shl    $0x5,%rdx
    6b2e:	48 01 d0             	add    %rdx,%rax
    6b31:	48 8b 48 10          	mov    0x10(%rax),%rcx
    6b35:	48 8d 55 90          	lea    -0x70(%rbp),%rdx
    6b39:	48 8b 75 b0          	mov    -0x50(%rbp),%rsi
    6b3d:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    6b41:	49 89 f8             	mov    %rdi,%r8
    6b44:	48 89 c7             	mov    %rax,%rdi
    6b47:	e8 41 e1 ff ff       	call   4c8d <bApp>
    6b4c:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    6b50:	48 83 c0 01          	add    $0x1,%rax
    6b54:	48 3b 45 b0          	cmp    -0x50(%rbp),%rax
    6b58:	73 1a                	jae    6b74 <bWriteMap+0x447>
    6b5a:	48 8b 55 90          	mov    -0x70(%rbp),%rdx
    6b5e:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    6b62:	48 01 d0             	add    %rdx,%rax
    6b65:	c6 00 0a             	movb   $0xa,(%rax)
    6b68:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    6b6c:	48 83 c0 01          	add    $0x1,%rax
    6b70:	48 89 45 90          	mov    %rax,-0x70(%rbp)
    6b74:	83 45 8c 01          	addl   $0x1,-0x74(%rbp)
    6b78:	48 8b 85 78 ff ff ff 	mov    -0x88(%rbp),%rax
    6b7f:	8b 80 90 00 00 00    	mov    0x90(%rax),%eax
    6b85:	39 45 8c             	cmp    %eax,-0x74(%rbp)
    6b88:	0f 82 89 fe ff ff    	jb     6a17 <bWriteMap+0x2ea>
    6b8e:	bf 00 10 00 00       	mov    $0x1000,%edi
    6b93:	e8 48 a5 ff ff       	call   10e0 <malloc@plt>
    6b98:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
    6b9c:	48 c7 45 a8 00 00 00 	movq   $0x0,-0x58(%rbp)
    6ba3:	00 
    6ba4:	eb 27                	jmp    6bcd <bWriteMap+0x4a0>
    6ba6:	48 8b 85 78 ff ff ff 	mov    -0x88(%rbp),%rax
    6bad:	48 8b 50 48          	mov    0x48(%rax),%rdx
    6bb1:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    6bb5:	48 01 d0             	add    %rdx,%rax
    6bb8:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    6bbc:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
    6bc0:	48 01 ca             	add    %rcx,%rdx
    6bc3:	0f b6 00             	movzbl (%rax),%eax
    6bc6:	88 02                	mov    %al,(%rdx)
    6bc8:	48 83 45 a8 01       	addq   $0x1,-0x58(%rbp)
    6bcd:	48 8b 85 78 ff ff ff 	mov    -0x88(%rbp),%rax
    6bd4:	48 8b 40 50          	mov    0x50(%rax),%rax
    6bd8:	48 39 45 a8          	cmp    %rax,-0x58(%rbp)
    6bdc:	73 0a                	jae    6be8 <bWriteMap+0x4bb>
    6bde:	48 81 7d a8 fe 0f 00 	cmpq   $0xffe,-0x58(%rbp)
    6be5:	00 
    6be6:	76 be                	jbe    6ba6 <bWriteMap+0x479>
    6be8:	48 8b 55 d0          	mov    -0x30(%rbp),%rdx
    6bec:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    6bf0:	48 01 d0             	add    %rdx,%rax
    6bf3:	c6 00 00             	movb   $0x0,(%rax)
    6bf6:	48 8b 55 90          	mov    -0x70(%rbp),%rdx
    6bfa:	48 8b 4d b8          	mov    -0x48(%rbp),%rcx
    6bfe:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    6c02:	48 89 ce             	mov    %rcx,%rsi
    6c05:	48 89 c7             	mov    %rax,%rdi
    6c08:	e8 ba fa ff ff       	call   66c7 <bWriteFile>
    6c0d:	88 45 87             	mov    %al,-0x79(%rbp)
    6c10:	0f b6 45 87          	movzbl -0x79(%rbp),%eax
    6c14:	83 f0 01             	xor    $0x1,%eax
    6c17:	84 c0                	test   %al,%al
    6c19:	74 38                	je     6c53 <bWriteMap+0x526>
    6c1b:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    6c1f:	48 8d 15 d0 38 00 00 	lea    0x38d0(%rip),%rdx        # a4f6 <_IO_stdin_used+0x4f6>
    6c26:	48 89 c6             	mov    %rax,%rsi
    6c29:	48 89 d7             	mov    %rdx,%rdi
    6c2c:	b8 00 00 00 00       	mov    $0x0,%eax
    6c31:	e8 5a a4 ff ff       	call   1090 <printf@plt>
    6c36:	48 8b 85 78 ff ff ff 	mov    -0x88(%rbp),%rax
    6c3d:	8b 80 b0 00 00 00    	mov    0xb0(%rax),%eax
    6c43:	8d 50 01             	lea    0x1(%rax),%edx
    6c46:	48 8b 85 78 ff ff ff 	mov    -0x88(%rbp),%rax
    6c4d:	89 90 b0 00 00 00    	mov    %edx,0xb0(%rax)
    6c53:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    6c57:	48 89 c7             	mov    %rax,%rdi
    6c5a:	e8 d1 a3 ff ff       	call   1030 <free@plt>
    6c5f:	0f b6 45 87          	movzbl -0x79(%rbp),%eax
    6c63:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    6c67:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
    6c6e:	00 00 
    6c70:	74 05                	je     6c77 <bWriteMap+0x54a>
    6c72:	e8 09 a4 ff ff       	call   1080 <__stack_chk_fail@plt>
    6c77:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
    6c7b:	c9                   	leave
    6c7c:	c3                   	ret

0000000000006c7d <bFingerprint>:
    6c7d:	55                   	push   %rbp
    6c7e:	48 89 e5             	mov    %rsp,%rbp
    6c81:	41 54                	push   %r12
    6c83:	53                   	push   %rbx
    6c84:	48 83 ec 60          	sub    $0x60,%rsp
    6c88:	48 89 7d 98          	mov    %rdi,-0x68(%rbp)
    6c8c:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    6c93:	00 00 
    6c95:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    6c99:	31 c0                	xor    %eax,%eax
    6c9b:	c7 45 a8 00 00 00 00 	movl   $0x0,-0x58(%rbp)
    6ca2:	e9 67 02 00 00       	jmp    6f0e <bFingerprint+0x291>
    6ca7:	bf 00 10 00 00       	mov    $0x1000,%edi
    6cac:	e8 2f a4 ff ff       	call   10e0 <malloc@plt>
    6cb1:	48 89 45 b8          	mov    %rax,-0x48(%rbp)
    6cb5:	48 83 7d b8 00       	cmpq   $0x0,-0x48(%rbp)
    6cba:	75 0a                	jne    6cc6 <bFingerprint+0x49>
    6cbc:	b8 00 00 00 00       	mov    $0x0,%eax
    6cc1:	e9 5d 02 00 00       	jmp    6f23 <bFingerprint+0x2a6>
    6cc6:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    6cca:	48 8b 40 68          	mov    0x68(%rax),%rax
    6cce:	8b 55 a8             	mov    -0x58(%rbp),%edx
    6cd1:	48 c1 e2 04          	shl    $0x4,%rdx
    6cd5:	48 01 d0             	add    %rdx,%rax
    6cd8:	48 8b 08             	mov    (%rax),%rcx
    6cdb:	48 8b 58 08          	mov    0x8(%rax),%rbx
    6cdf:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    6ce3:	48 8b 50 20          	mov    0x20(%rax),%rdx
    6ce7:	48 8b 40 18          	mov    0x18(%rax),%rax
    6ceb:	48 8b 7d b8          	mov    -0x48(%rbp),%rdi
    6cef:	49 89 c8             	mov    %rcx,%r8
    6cf2:	49 89 d9             	mov    %rbx,%r9
    6cf5:	48 89 d1             	mov    %rdx,%rcx
    6cf8:	48 89 c2             	mov    %rax,%rdx
    6cfb:	be 00 10 00 00       	mov    $0x1000,%esi
    6d00:	e8 2a de ff ff       	call   4b2f <bJoin>
    6d05:	48 89 45 c0          	mov    %rax,-0x40(%rbp)
    6d09:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    6d0d:	48 8b 00             	mov    (%rax),%rax
    6d10:	ba 08 00 00 00       	mov    $0x8,%edx
    6d15:	be 00 20 00 00       	mov    $0x2000,%esi
    6d1a:	48 89 c7             	mov    %rax,%rdi
    6d1d:	e8 af a5 ff ff       	call   12d1 <Arena_alloc>
    6d22:	48 89 45 c8          	mov    %rax,-0x38(%rbp)
    6d26:	48 83 7d c8 00       	cmpq   $0x0,-0x38(%rbp)
    6d2b:	75 0a                	jne    6d37 <bFingerprint+0xba>
    6d2d:	b8 00 00 00 00       	mov    $0x0,%eax
    6d32:	e9 ec 01 00 00       	jmp    6f23 <bFingerprint+0x2a6>
    6d37:	c7 45 a4 00 00 00 00 	movl   $0x0,-0x5c(%rbp)
    6d3e:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    6d42:	44 8b a0 80 00 00 00 	mov    0x80(%rax),%r12d
    6d49:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    6d4d:	48 8b 58 78          	mov    0x78(%rax),%rbx
    6d51:	48 8b 55 c0          	mov    -0x40(%rbp),%rdx
    6d55:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    6d59:	48 89 d6             	mov    %rdx,%rsi
    6d5c:	48 89 c7             	mov    %rax,%rdi
    6d5f:	e8 1e a7 ff ff       	call   1482 <Slice_from>
    6d64:	48 8b 4d 98          	mov    -0x68(%rbp),%rcx
    6d68:	48 8b 39             	mov    (%rcx),%rdi
    6d6b:	48 8b 75 b8          	mov    -0x48(%rbp),%rsi
    6d6f:	48 83 ec 08          	sub    $0x8,%rsp
    6d73:	48 8d 4d a4          	lea    -0x5c(%rbp),%rcx
    6d77:	51                   	push   %rcx
    6d78:	68 00 02 00 00       	push   $0x200
    6d7d:	ff 75 c8             	push   -0x38(%rbp)
    6d80:	45 89 e1             	mov    %r12d,%r9d
    6d83:	49 89 d8             	mov    %rbx,%r8
    6d86:	48 89 d1             	mov    %rdx,%rcx
    6d89:	48 89 c2             	mov    %rax,%rdx
    6d8c:	e8 cf e4 ff ff       	call   5260 <bCollectCrl>
    6d91:	48 83 c4 20          	add    $0x20,%rsp
    6d95:	8b 55 a4             	mov    -0x5c(%rbp),%edx
    6d98:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    6d9c:	89 d6                	mov    %edx,%esi
    6d9e:	48 89 c7             	mov    %rax,%rdi
    6da1:	e8 e8 e7 ff ff       	call   558e <bSortFiles>
    6da6:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    6daa:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    6db1:	8b 55 a8             	mov    -0x58(%rbp),%edx
    6db4:	48 c1 e2 06          	shl    $0x6,%rdx
    6db8:	48 01 c2             	add    %rax,%rdx
    6dbb:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    6dbf:	48 89 42 20          	mov    %rax,0x20(%rdx)
    6dc3:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    6dc7:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    6dce:	8b 55 a8             	mov    -0x58(%rbp),%edx
    6dd1:	48 c1 e2 06          	shl    $0x6,%rdx
    6dd5:	48 01 c2             	add    %rax,%rdx
    6dd8:	8b 45 a4             	mov    -0x5c(%rbp),%eax
    6ddb:	89 42 28             	mov    %eax,0x28(%rdx)
    6dde:	c7 45 ac 00 00 00 00 	movl   $0x0,-0x54(%rbp)
    6de5:	e9 14 01 00 00       	jmp    6efe <bFingerprint+0x281>
    6dea:	48 c7 45 b0 00 00 00 	movq   $0x0,-0x50(%rbp)
    6df1:	00 
    6df2:	8b 45 ac             	mov    -0x54(%rbp),%eax
    6df5:	48 c1 e0 04          	shl    $0x4,%rax
    6df9:	48 89 c2             	mov    %rax,%rdx
    6dfc:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    6e00:	48 01 d0             	add    %rdx,%rax
    6e03:	48 8b 55 98          	mov    -0x68(%rbp),%rdx
    6e07:	48 8b 0a             	mov    (%rdx),%rcx
    6e0a:	48 8b 10             	mov    (%rax),%rdx
    6e0d:	48 8b 40 08          	mov    0x8(%rax),%rax
    6e11:	48 89 d6             	mov    %rdx,%rsi
    6e14:	48 89 c2             	mov    %rax,%rdx
    6e17:	48 89 cf             	mov    %rcx,%rdi
    6e1a:	e8 b2 db ff ff       	call   49d1 <bCStr>
    6e1f:	48 89 c1             	mov    %rax,%rcx
    6e22:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    6e26:	48 8b 00             	mov    (%rax),%rax
    6e29:	48 8d 55 b0          	lea    -0x50(%rbp),%rdx
    6e2d:	48 89 ce             	mov    %rcx,%rsi
    6e30:	48 89 c7             	mov    %rax,%rdi
    6e33:	e8 10 df ff ff       	call   4d48 <bReadFile>
    6e38:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
    6e3c:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    6e40:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    6e44:	48 85 c0             	test   %rax,%rax
    6e47:	0f 84 ad 00 00 00    	je     6efa <bFingerprint+0x27d>
    6e4d:	8b 45 ac             	mov    -0x54(%rbp),%eax
    6e50:	48 c1 e0 04          	shl    $0x4,%rax
    6e54:	48 89 c2             	mov    %rax,%rdx
    6e57:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    6e5b:	48 01 d0             	add    %rdx,%rax
    6e5e:	48 8b 50 08          	mov    0x8(%rax),%rdx
    6e62:	8b 45 ac             	mov    -0x54(%rbp),%eax
    6e65:	48 c1 e0 04          	shl    $0x4,%rax
    6e69:	48 89 c1             	mov    %rax,%rcx
    6e6c:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    6e70:	48 01 c8             	add    %rcx,%rax
    6e73:	48 8b 08             	mov    (%rax),%rcx
    6e76:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    6e7a:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    6e81:	8b 75 a8             	mov    -0x58(%rbp),%esi
    6e84:	48 c1 e6 06          	shl    $0x6,%rsi
    6e88:	48 01 f0             	add    %rsi,%rax
    6e8b:	48 8b 40 30          	mov    0x30(%rax),%rax
    6e8f:	48 8b 75 98          	mov    -0x68(%rbp),%rsi
    6e93:	48 8b b6 98 00 00 00 	mov    0x98(%rsi),%rsi
    6e9a:	8b 7d a8             	mov    -0x58(%rbp),%edi
    6e9d:	48 c1 e7 06          	shl    $0x6,%rdi
    6ea1:	48 8d 1c 3e          	lea    (%rsi,%rdi,1),%rbx
    6ea5:	48 89 ce             	mov    %rcx,%rsi
    6ea8:	48 89 c7             	mov    %rax,%rdi
    6eab:	e8 83 dd ff ff       	call   4c33 <bFnv>
    6eb0:	48 89 43 30          	mov    %rax,0x30(%rbx)
    6eb4:	48 8b 55 b0          	mov    -0x50(%rbp),%rdx
    6eb8:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    6ebc:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    6ec0:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    6ec7:	8b 75 a8             	mov    -0x58(%rbp),%esi
    6eca:	48 c1 e6 06          	shl    $0x6,%rsi
    6ece:	48 01 f0             	add    %rsi,%rax
    6ed1:	48 8b 40 30          	mov    0x30(%rax),%rax
    6ed5:	48 8b 75 98          	mov    -0x68(%rbp),%rsi
    6ed9:	48 8b b6 98 00 00 00 	mov    0x98(%rsi),%rsi
    6ee0:	8b 7d a8             	mov    -0x58(%rbp),%edi
    6ee3:	48 c1 e7 06          	shl    $0x6,%rdi
    6ee7:	48 8d 1c 3e          	lea    (%rsi,%rdi,1),%rbx
    6eeb:	48 89 ce             	mov    %rcx,%rsi
    6eee:	48 89 c7             	mov    %rax,%rdi
    6ef1:	e8 3d dd ff ff       	call   4c33 <bFnv>
    6ef6:	48 89 43 30          	mov    %rax,0x30(%rbx)
    6efa:	83 45 ac 01          	addl   $0x1,-0x54(%rbp)
    6efe:	8b 45 a4             	mov    -0x5c(%rbp),%eax
    6f01:	39 45 ac             	cmp    %eax,-0x54(%rbp)
    6f04:	0f 82 e0 fe ff ff    	jb     6dea <bFingerprint+0x16d>
    6f0a:	83 45 a8 01          	addl   $0x1,-0x58(%rbp)
    6f0e:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    6f12:	8b 40 70             	mov    0x70(%rax),%eax
    6f15:	39 45 a8             	cmp    %eax,-0x58(%rbp)
    6f18:	0f 82 89 fd ff ff    	jb     6ca7 <bFingerprint+0x2a>
    6f1e:	b8 01 00 00 00       	mov    $0x1,%eax
    6f23:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    6f27:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
    6f2e:	00 00 
    6f30:	74 05                	je     6f37 <bFingerprint+0x2ba>
    6f32:	e8 49 a1 ff ff       	call   1080 <__stack_chk_fail@plt>
    6f37:	48 8d 65 f0          	lea    -0x10(%rbp),%rsp
    6f3b:	5b                   	pop    %rbx
    6f3c:	41 5c                	pop    %r12
    6f3e:	5d                   	pop    %rbp
    6f3f:	c3                   	ret

0000000000006f40 <bDfs>:
    6f40:	55                   	push   %rbp
    6f41:	48 89 e5             	mov    %rsp,%rbp
    6f44:	48 83 ec 50          	sub    $0x50,%rsp
    6f48:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
    6f4c:	89 75 d4             	mov    %esi,-0x2c(%rbp)
    6f4f:	48 89 55 c8          	mov    %rdx,-0x38(%rbp)
    6f53:	48 89 4d c0          	mov    %rcx,-0x40(%rbp)
    6f57:	4c 89 45 b8          	mov    %r8,-0x48(%rbp)
    6f5b:	4c 89 4d b0          	mov    %r9,-0x50(%rbp)
    6f5f:	8b 55 d4             	mov    -0x2c(%rbp),%edx
    6f62:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    6f66:	48 01 d0             	add    %rdx,%rax
    6f69:	c6 00 01             	movb   $0x1,(%rax)
    6f6c:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    6f70:	8b 00                	mov    (%rax),%eax
    6f72:	89 c0                	mov    %eax,%eax
    6f74:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
    6f7b:	00 
    6f7c:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
    6f80:	48 01 c2             	add    %rax,%rdx
    6f83:	8b 45 d4             	mov    -0x2c(%rbp),%eax
    6f86:	89 02                	mov    %eax,(%rdx)
    6f88:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    6f8c:	8b 00                	mov    (%rax),%eax
    6f8e:	8d 50 01             	lea    0x1(%rax),%edx
    6f91:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    6f95:	89 10                	mov    %edx,(%rax)
    6f97:	c7 45 e0 00 00 00 00 	movl   $0x0,-0x20(%rbp)
    6f9e:	e9 cd 01 00 00       	jmp    7170 <bDfs+0x230>
    6fa3:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    6fa7:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    6fae:	8b 55 d4             	mov    -0x2c(%rbp),%edx
    6fb1:	48 c1 e2 06          	shl    $0x6,%rdx
    6fb5:	48 01 d0             	add    %rdx,%rax
    6fb8:	48 8b 40 10          	mov    0x10(%rax),%rax
    6fbc:	8b 55 e0             	mov    -0x20(%rbp),%edx
    6fbf:	48 c1 e2 02          	shl    $0x2,%rdx
    6fc3:	48 01 d0             	add    %rdx,%rax
    6fc6:	8b 00                	mov    (%rax),%eax
    6fc8:	89 45 e8             	mov    %eax,-0x18(%rbp)
    6fcb:	8b 55 e8             	mov    -0x18(%rbp),%edx
    6fce:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    6fd2:	48 01 d0             	add    %rdx,%rax
    6fd5:	0f b6 00             	movzbl (%rax),%eax
    6fd8:	3c 01                	cmp    $0x1,%al
    6fda:	0f 85 3d 01 00 00    	jne    711d <bDfs+0x1dd>
    6fe0:	48 8d 05 29 35 00 00 	lea    0x3529(%rip),%rax        # a510 <_IO_stdin_used+0x510>
    6fe7:	48 89 c7             	mov    %rax,%rdi
    6fea:	b8 00 00 00 00       	mov    $0x0,%eax
    6fef:	e8 9c a0 ff ff       	call   1090 <printf@plt>
    6ff4:	c7 45 e4 00 00 00 00 	movl   $0x0,-0x1c(%rbp)
    6ffb:	e9 89 00 00 00       	jmp    7089 <bDfs+0x149>
    7000:	48 c7 45 f0 00 00 00 	movq   $0x0,-0x10(%rbp)
    7007:	00 
    7008:	8b 45 e4             	mov    -0x1c(%rbp),%eax
    700b:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
    7012:	00 
    7013:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
    7017:	48 01 d0             	add    %rdx,%rax
    701a:	8b 00                	mov    (%rax),%eax
    701c:	89 45 ec             	mov    %eax,-0x14(%rbp)
    701f:	eb 31                	jmp    7052 <bDfs+0x112>
    7021:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    7025:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    702c:	8b 55 ec             	mov    -0x14(%rbp),%edx
    702f:	48 c1 e2 06          	shl    $0x6,%rdx
    7033:	48 01 d0             	add    %rdx,%rax
    7036:	48 8b 10             	mov    (%rax),%rdx
    7039:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    703d:	48 01 d0             	add    %rdx,%rax
    7040:	0f b6 00             	movzbl (%rax),%eax
    7043:	0f b6 c0             	movzbl %al,%eax
    7046:	89 c7                	mov    %eax,%edi
    7048:	e8 f3 9f ff ff       	call   1040 <putchar@plt>
    704d:	48 83 45 f0 01       	addq   $0x1,-0x10(%rbp)
    7052:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    7056:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    705d:	8b 55 ec             	mov    -0x14(%rbp),%edx
    7060:	48 c1 e2 06          	shl    $0x6,%rdx
    7064:	48 01 d0             	add    %rdx,%rax
    7067:	48 8b 40 08          	mov    0x8(%rax),%rax
    706b:	48 39 45 f0          	cmp    %rax,-0x10(%rbp)
    706f:	72 b0                	jb     7021 <bDfs+0xe1>
    7071:	48 8d 05 bb 34 00 00 	lea    0x34bb(%rip),%rax        # a533 <_IO_stdin_used+0x533>
    7078:	48 89 c7             	mov    %rax,%rdi
    707b:	b8 00 00 00 00       	mov    $0x0,%eax
    7080:	e8 0b a0 ff ff       	call   1090 <printf@plt>
    7085:	83 45 e4 01          	addl   $0x1,-0x1c(%rbp)
    7089:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    708d:	8b 00                	mov    (%rax),%eax
    708f:	39 45 e4             	cmp    %eax,-0x1c(%rbp)
    7092:	0f 82 68 ff ff ff    	jb     7000 <bDfs+0xc0>
    7098:	48 c7 45 f8 00 00 00 	movq   $0x0,-0x8(%rbp)
    709f:	00 
    70a0:	eb 31                	jmp    70d3 <bDfs+0x193>
    70a2:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    70a6:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    70ad:	8b 55 e8             	mov    -0x18(%rbp),%edx
    70b0:	48 c1 e2 06          	shl    $0x6,%rdx
    70b4:	48 01 d0             	add    %rdx,%rax
    70b7:	48 8b 10             	mov    (%rax),%rdx
    70ba:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    70be:	48 01 d0             	add    %rdx,%rax
    70c1:	0f b6 00             	movzbl (%rax),%eax
    70c4:	0f b6 c0             	movzbl %al,%eax
    70c7:	89 c7                	mov    %eax,%edi
    70c9:	e8 72 9f ff ff       	call   1040 <putchar@plt>
    70ce:	48 83 45 f8 01       	addq   $0x1,-0x8(%rbp)
    70d3:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    70d7:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    70de:	8b 55 e8             	mov    -0x18(%rbp),%edx
    70e1:	48 c1 e2 06          	shl    $0x6,%rdx
    70e5:	48 01 d0             	add    %rdx,%rax
    70e8:	48 8b 40 08          	mov    0x8(%rax),%rax
    70ec:	48 39 45 f8          	cmp    %rax,-0x8(%rbp)
    70f0:	72 b0                	jb     70a2 <bDfs+0x162>
    70f2:	bf 0a 00 00 00       	mov    $0xa,%edi
    70f7:	e8 44 9f ff ff       	call   1040 <putchar@plt>
    70fc:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    7100:	8b 80 b0 00 00 00    	mov    0xb0(%rax),%eax
    7106:	8d 50 01             	lea    0x1(%rax),%edx
    7109:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    710d:	89 90 b0 00 00 00    	mov    %edx,0xb0(%rax)
    7113:	b8 00 00 00 00       	mov    $0x0,%eax
    7118:	e9 c0 00 00 00       	jmp    71dd <bDfs+0x29d>
    711d:	8b 55 e8             	mov    -0x18(%rbp),%edx
    7120:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    7124:	48 01 d0             	add    %rdx,%rax
    7127:	0f b6 00             	movzbl (%rax),%eax
    712a:	84 c0                	test   %al,%al
    712c:	75 3e                	jne    716c <bDfs+0x22c>
    712e:	4c 8b 45 b0          	mov    -0x50(%rbp),%r8
    7132:	48 8b 7d b8          	mov    -0x48(%rbp),%rdi
    7136:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
    713a:	48 8b 55 c8          	mov    -0x38(%rbp),%rdx
    713e:	8b 75 e8             	mov    -0x18(%rbp),%esi
    7141:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    7145:	48 83 ec 08          	sub    $0x8,%rsp
    7149:	ff 75 10             	push   0x10(%rbp)
    714c:	4d 89 c1             	mov    %r8,%r9
    714f:	49 89 f8             	mov    %rdi,%r8
    7152:	48 89 c7             	mov    %rax,%rdi
    7155:	e8 e6 fd ff ff       	call   6f40 <bDfs>
    715a:	48 83 c4 10          	add    $0x10,%rsp
    715e:	83 f0 01             	xor    $0x1,%eax
    7161:	84 c0                	test   %al,%al
    7163:	74 07                	je     716c <bDfs+0x22c>
    7165:	b8 00 00 00 00       	mov    $0x0,%eax
    716a:	eb 71                	jmp    71dd <bDfs+0x29d>
    716c:	83 45 e0 01          	addl   $0x1,-0x20(%rbp)
    7170:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    7174:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    717b:	8b 55 d4             	mov    -0x2c(%rbp),%edx
    717e:	48 c1 e2 06          	shl    $0x6,%rdx
    7182:	48 01 d0             	add    %rdx,%rax
    7185:	8b 40 18             	mov    0x18(%rax),%eax
    7188:	39 45 e0             	cmp    %eax,-0x20(%rbp)
    718b:	0f 82 12 fe ff ff    	jb     6fa3 <bDfs+0x63>
    7191:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    7195:	8b 00                	mov    (%rax),%eax
    7197:	8d 50 ff             	lea    -0x1(%rax),%edx
    719a:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    719e:	89 10                	mov    %edx,(%rax)
    71a0:	8b 55 d4             	mov    -0x2c(%rbp),%edx
    71a3:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    71a7:	48 01 d0             	add    %rdx,%rax
    71aa:	c6 00 02             	movb   $0x2,(%rax)
    71ad:	48 8b 45 10          	mov    0x10(%rbp),%rax
    71b1:	8b 00                	mov    (%rax),%eax
    71b3:	89 c0                	mov    %eax,%eax
    71b5:	48 8d 14 85 00 00 00 	lea    0x0(,%rax,4),%rdx
    71bc:	00 
    71bd:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    71c1:	48 01 c2             	add    %rax,%rdx
    71c4:	8b 45 d4             	mov    -0x2c(%rbp),%eax
    71c7:	89 02                	mov    %eax,(%rdx)
    71c9:	48 8b 45 10          	mov    0x10(%rbp),%rax
    71cd:	8b 00                	mov    (%rax),%eax
    71cf:	8d 50 01             	lea    0x1(%rax),%edx
    71d2:	48 8b 45 10          	mov    0x10(%rbp),%rax
    71d6:	89 10                	mov    %edx,(%rax)
    71d8:	b8 01 00 00 00       	mov    $0x1,%eax
    71dd:	c9                   	leave
    71de:	c3                   	ret

00000000000071df <bTopo>:
    71df:	55                   	push   %rbp
    71e0:	48 89 e5             	mov    %rsp,%rbp
    71e3:	48 83 ec 40          	sub    $0x40,%rsp
    71e7:	48 89 7d c8          	mov    %rdi,-0x38(%rbp)
    71eb:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    71f2:	00 00 
    71f4:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    71f8:	31 c0                	xor    %eax,%eax
    71fa:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    71fe:	8b 40 70             	mov    0x70(%rax),%eax
    7201:	89 c1                	mov    %eax,%ecx
    7203:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    7207:	48 8b 00             	mov    (%rax),%rax
    720a:	ba 01 00 00 00       	mov    $0x1,%edx
    720f:	48 89 ce             	mov    %rcx,%rsi
    7212:	48 89 c7             	mov    %rax,%rdi
    7215:	e8 b7 a0 ff ff       	call   12d1 <Arena_alloc>
    721a:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    721e:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    7222:	8b 40 70             	mov    0x70(%rax),%eax
    7225:	89 c0                	mov    %eax,%eax
    7227:	48 8d 0c 85 00 00 00 	lea    0x0(,%rax,4),%rcx
    722e:	00 
    722f:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    7233:	48 8b 00             	mov    (%rax),%rax
    7236:	ba 04 00 00 00       	mov    $0x4,%edx
    723b:	48 89 ce             	mov    %rcx,%rsi
    723e:	48 89 c7             	mov    %rax,%rdi
    7241:	e8 8b a0 ff ff       	call   12d1 <Arena_alloc>
    7246:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    724a:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    724e:	8b 40 70             	mov    0x70(%rax),%eax
    7251:	89 c0                	mov    %eax,%eax
    7253:	48 8d 0c 85 00 00 00 	lea    0x0(,%rax,4),%rcx
    725a:	00 
    725b:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    725f:	48 8b 00             	mov    (%rax),%rax
    7262:	ba 04 00 00 00       	mov    $0x4,%edx
    7267:	48 89 ce             	mov    %rcx,%rsi
    726a:	48 89 c7             	mov    %rax,%rdi
    726d:	e8 5f a0 ff ff       	call   12d1 <Arena_alloc>
    7272:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    7276:	48 83 7d e0 00       	cmpq   $0x0,-0x20(%rbp)
    727b:	74 0e                	je     728b <bTopo+0xac>
    727d:	48 83 7d e8 00       	cmpq   $0x0,-0x18(%rbp)
    7282:	74 07                	je     728b <bTopo+0xac>
    7284:	48 83 7d f0 00       	cmpq   $0x0,-0x10(%rbp)
    7289:	75 0a                	jne    7295 <bTopo+0xb6>
    728b:	b8 00 00 00 00       	mov    $0x0,%eax
    7290:	e9 ba 00 00 00       	jmp    734f <bTopo+0x170>
    7295:	c7 45 dc 00 00 00 00 	movl   $0x0,-0x24(%rbp)
    729c:	eb 11                	jmp    72af <bTopo+0xd0>
    729e:	8b 55 dc             	mov    -0x24(%rbp),%edx
    72a1:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    72a5:	48 01 d0             	add    %rdx,%rax
    72a8:	c6 00 00             	movb   $0x0,(%rax)
    72ab:	83 45 dc 01          	addl   $0x1,-0x24(%rbp)
    72af:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    72b3:	8b 40 70             	mov    0x70(%rax),%eax
    72b6:	39 45 dc             	cmp    %eax,-0x24(%rbp)
    72b9:	72 e3                	jb     729e <bTopo+0xbf>
    72bb:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    72bf:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
    72c3:	48 89 90 a8 00 00 00 	mov    %rdx,0xa8(%rax)
    72ca:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    72ce:	c7 80 a0 00 00 00 00 	movl   $0x0,0xa0(%rax)
    72d5:	00 00 00 
    72d8:	c7 45 d8 00 00 00 00 	movl   $0x0,-0x28(%rbp)
    72df:	c7 45 dc 00 00 00 00 	movl   $0x0,-0x24(%rbp)
    72e6:	eb 56                	jmp    733e <bTopo+0x15f>
    72e8:	8b 55 dc             	mov    -0x24(%rbp),%edx
    72eb:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    72ef:	48 01 d0             	add    %rdx,%rax
    72f2:	0f b6 00             	movzbl (%rax),%eax
    72f5:	84 c0                	test   %al,%al
    72f7:	75 41                	jne    733a <bTopo+0x15b>
    72f9:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    72fd:	48 8d b8 a0 00 00 00 	lea    0xa0(%rax),%rdi
    7304:	4c 8b 4d f0          	mov    -0x10(%rbp),%r9
    7308:	4c 8d 45 d8          	lea    -0x28(%rbp),%r8
    730c:	48 8b 4d e8          	mov    -0x18(%rbp),%rcx
    7310:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    7314:	8b 75 dc             	mov    -0x24(%rbp),%esi
    7317:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    731b:	48 83 ec 08          	sub    $0x8,%rsp
    731f:	57                   	push   %rdi
    7320:	48 89 c7             	mov    %rax,%rdi
    7323:	e8 18 fc ff ff       	call   6f40 <bDfs>
    7328:	48 83 c4 10          	add    $0x10,%rsp
    732c:	83 f0 01             	xor    $0x1,%eax
    732f:	84 c0                	test   %al,%al
    7331:	74 07                	je     733a <bTopo+0x15b>
    7333:	b8 00 00 00 00       	mov    $0x0,%eax
    7338:	eb 15                	jmp    734f <bTopo+0x170>
    733a:	83 45 dc 01          	addl   $0x1,-0x24(%rbp)
    733e:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    7342:	8b 40 70             	mov    0x70(%rax),%eax
    7345:	39 45 dc             	cmp    %eax,-0x24(%rbp)
    7348:	72 9e                	jb     72e8 <bTopo+0x109>
    734a:	b8 01 00 00 00       	mov    $0x1,%eax
    734f:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
    7353:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
    735a:	00 00 
    735c:	74 05                	je     7363 <bTopo+0x184>
    735e:	e8 1d 9d ff ff       	call   1080 <__stack_chk_fail@plt>
    7363:	c9                   	leave
    7364:	c3                   	ret

0000000000007365 <bAddEdge>:
    7365:	55                   	push   %rbp
    7366:	48 89 e5             	mov    %rsp,%rbp
    7369:	48 83 ec 40          	sub    $0x40,%rsp
    736d:	48 89 7d c8          	mov    %rdi,-0x38(%rbp)
    7371:	89 75 c4             	mov    %esi,-0x3c(%rbp)
    7374:	89 55 c0             	mov    %edx,-0x40(%rbp)
    7377:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    737b:	8b 40 70             	mov    0x70(%rax),%eax
    737e:	39 45 c4             	cmp    %eax,-0x3c(%rbp)
    7381:	73 0c                	jae    738f <bAddEdge+0x2a>
    7383:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    7387:	8b 40 70             	mov    0x70(%rax),%eax
    738a:	39 45 c0             	cmp    %eax,-0x40(%rbp)
    738d:	72 0a                	jb     7399 <bAddEdge+0x34>
    738f:	b8 00 00 00 00       	mov    $0x0,%eax
    7394:	e9 64 01 00 00       	jmp    74fd <bAddEdge+0x198>
    7399:	8b 45 c4             	mov    -0x3c(%rbp),%eax
    739c:	3b 45 c0             	cmp    -0x40(%rbp),%eax
    739f:	75 0a                	jne    73ab <bAddEdge+0x46>
    73a1:	b8 01 00 00 00       	mov    $0x1,%eax
    73a6:	e9 52 01 00 00       	jmp    74fd <bAddEdge+0x198>
    73ab:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    73af:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    73b6:	8b 55 c4             	mov    -0x3c(%rbp),%edx
    73b9:	48 c1 e2 06          	shl    $0x6,%rdx
    73bd:	48 01 d0             	add    %rdx,%rax
    73c0:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    73c4:	c7 45 dc 00 00 00 00 	movl   $0x0,-0x24(%rbp)
    73cb:	eb 27                	jmp    73f4 <bAddEdge+0x8f>
    73cd:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    73d1:	48 8b 40 10          	mov    0x10(%rax),%rax
    73d5:	8b 55 dc             	mov    -0x24(%rbp),%edx
    73d8:	48 c1 e2 02          	shl    $0x2,%rdx
    73dc:	48 01 d0             	add    %rdx,%rax
    73df:	8b 00                	mov    (%rax),%eax
    73e1:	39 45 c0             	cmp    %eax,-0x40(%rbp)
    73e4:	75 0a                	jne    73f0 <bAddEdge+0x8b>
    73e6:	b8 01 00 00 00       	mov    $0x1,%eax
    73eb:	e9 0d 01 00 00       	jmp    74fd <bAddEdge+0x198>
    73f0:	83 45 dc 01          	addl   $0x1,-0x24(%rbp)
    73f4:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    73f8:	8b 40 18             	mov    0x18(%rax),%eax
    73fb:	39 45 dc             	cmp    %eax,-0x24(%rbp)
    73fe:	72 cd                	jb     73cd <bAddEdge+0x68>
    7400:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    7404:	8b 50 18             	mov    0x18(%rax),%edx
    7407:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    740b:	8b 40 1c             	mov    0x1c(%rax),%eax
    740e:	39 c2                	cmp    %eax,%edx
    7410:	0f 82 b4 00 00 00    	jb     74ca <bAddEdge+0x165>
    7416:	c7 45 e0 08 00 00 00 	movl   $0x8,-0x20(%rbp)
    741d:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    7421:	8b 40 1c             	mov    0x1c(%rax),%eax
    7424:	85 c0                	test   %eax,%eax
    7426:	74 0c                	je     7434 <bAddEdge+0xcf>
    7428:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    742c:	8b 40 1c             	mov    0x1c(%rax),%eax
    742f:	01 c0                	add    %eax,%eax
    7431:	89 45 e0             	mov    %eax,-0x20(%rbp)
    7434:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    7438:	48 8b 00             	mov    (%rax),%rax
    743b:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    743f:	8b 45 e0             	mov    -0x20(%rbp),%eax
    7442:	48 8d 0c 85 00 00 00 	lea    0x0(,%rax,4),%rcx
    7449:	00 
    744a:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    744e:	ba 04 00 00 00       	mov    $0x4,%edx
    7453:	48 89 ce             	mov    %rcx,%rsi
    7456:	48 89 c7             	mov    %rax,%rdi
    7459:	e8 73 9e ff ff       	call   12d1 <Arena_alloc>
    745e:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    7462:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    7467:	75 0a                	jne    7473 <bAddEdge+0x10e>
    7469:	b8 00 00 00 00       	mov    $0x0,%eax
    746e:	e9 8a 00 00 00       	jmp    74fd <bAddEdge+0x198>
    7473:	c7 45 e4 00 00 00 00 	movl   $0x0,-0x1c(%rbp)
    747a:	eb 2c                	jmp    74a8 <bAddEdge+0x143>
    747c:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    7480:	48 8b 40 10          	mov    0x10(%rax),%rax
    7484:	8b 55 e4             	mov    -0x1c(%rbp),%edx
    7487:	48 c1 e2 02          	shl    $0x2,%rdx
    748b:	48 01 d0             	add    %rdx,%rax
    748e:	8b 55 e4             	mov    -0x1c(%rbp),%edx
    7491:	48 8d 0c 95 00 00 00 	lea    0x0(,%rdx,4),%rcx
    7498:	00 
    7499:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
    749d:	48 01 ca             	add    %rcx,%rdx
    74a0:	8b 00                	mov    (%rax),%eax
    74a2:	89 02                	mov    %eax,(%rdx)
    74a4:	83 45 e4 01          	addl   $0x1,-0x1c(%rbp)
    74a8:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    74ac:	8b 40 18             	mov    0x18(%rax),%eax
    74af:	39 45 e4             	cmp    %eax,-0x1c(%rbp)
    74b2:	72 c8                	jb     747c <bAddEdge+0x117>
    74b4:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    74b8:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
    74bc:	48 89 50 10          	mov    %rdx,0x10(%rax)
    74c0:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    74c4:	8b 55 e0             	mov    -0x20(%rbp),%edx
    74c7:	89 50 1c             	mov    %edx,0x1c(%rax)
    74ca:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    74ce:	48 8b 50 10          	mov    0x10(%rax),%rdx
    74d2:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    74d6:	8b 40 18             	mov    0x18(%rax),%eax
    74d9:	89 c0                	mov    %eax,%eax
    74db:	48 c1 e0 02          	shl    $0x2,%rax
    74df:	48 01 c2             	add    %rax,%rdx
    74e2:	8b 45 c0             	mov    -0x40(%rbp),%eax
    74e5:	89 02                	mov    %eax,(%rdx)
    74e7:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    74eb:	8b 40 18             	mov    0x18(%rax),%eax
    74ee:	8d 50 01             	lea    0x1(%rax),%edx
    74f1:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    74f5:	89 50 18             	mov    %edx,0x18(%rax)
    74f8:	b8 01 00 00 00       	mov    $0x1,%eax
    74fd:	c9                   	leave
    74fe:	c3                   	ret

00000000000074ff <bLoadGraph>:
    74ff:	55                   	push   %rbp
    7500:	48 89 e5             	mov    %rsp,%rbp
    7503:	48 81 ec 90 00 00 00 	sub    $0x90,%rsp
    750a:	48 89 bd 78 ff ff ff 	mov    %rdi,-0x88(%rbp)
    7511:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    7518:	00 00 
    751a:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    751e:	31 c0                	xor    %eax,%eax
    7520:	48 c7 45 88 00 00 00 	movq   $0x0,-0x78(%rbp)
    7527:	00 
    7528:	48 8b 85 78 ff ff ff 	mov    -0x88(%rbp),%rax
    752f:	48 8b 00             	mov    (%rax),%rax
    7532:	48 8d 55 88          	lea    -0x78(%rbp),%rdx
    7536:	48 8d 0d fb 2f 00 00 	lea    0x2ffb(%rip),%rcx        # a538 <_IO_stdin_used+0x538>
    753d:	48 89 ce             	mov    %rcx,%rsi
    7540:	48 89 c7             	mov    %rax,%rdi
    7543:	e8 00 d8 ff ff       	call   4d48 <bReadFile>
    7548:	48 89 45 c0          	mov    %rax,-0x40(%rbp)
    754c:	48 89 55 c8          	mov    %rdx,-0x38(%rbp)
    7550:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
    7554:	48 85 c0             	test   %rax,%rax
    7557:	75 0a                	jne    7563 <bLoadGraph+0x64>
    7559:	b8 01 00 00 00       	mov    $0x1,%eax
    755e:	e9 94 02 00 00       	jmp    77f7 <bLoadGraph+0x2f8>
    7563:	48 c7 45 90 00 00 00 	movq   $0x0,-0x70(%rbp)
    756a:	00 
    756b:	e9 74 02 00 00       	jmp    77e4 <bLoadGraph+0x2e5>
    7570:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    7574:	48 89 45 a0          	mov    %rax,-0x60(%rbp)
    7578:	eb 05                	jmp    757f <bLoadGraph+0x80>
    757a:	48 83 45 90 01       	addq   $0x1,-0x70(%rbp)
    757f:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    7583:	48 39 45 90          	cmp    %rax,-0x70(%rbp)
    7587:	73 12                	jae    759b <bLoadGraph+0x9c>
    7589:	48 8b 55 c0          	mov    -0x40(%rbp),%rdx
    758d:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    7591:	48 01 d0             	add    %rdx,%rax
    7594:	0f b6 00             	movzbl (%rax),%eax
    7597:	3c 0a                	cmp    $0xa,%al
    7599:	75 df                	jne    757a <bLoadGraph+0x7b>
    759b:	48 8b 45 90          	mov    -0x70(%rbp),%rax
    759f:	48 89 45 a8          	mov    %rax,-0x58(%rbp)
    75a3:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    75a7:	48 39 45 90          	cmp    %rax,-0x70(%rbp)
    75ab:	73 05                	jae    75b2 <bLoadGraph+0xb3>
    75ad:	48 83 45 90 01       	addq   $0x1,-0x70(%rbp)
    75b2:	48 8b 45 a0          	mov    -0x60(%rbp),%rax
    75b6:	48 89 45 98          	mov    %rax,-0x68(%rbp)
    75ba:	eb 05                	jmp    75c1 <bLoadGraph+0xc2>
    75bc:	48 83 45 98 01       	addq   $0x1,-0x68(%rbp)
    75c1:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    75c5:	48 3b 45 a8          	cmp    -0x58(%rbp),%rax
    75c9:	73 36                	jae    7601 <bLoadGraph+0x102>
    75cb:	48 8b 55 c0          	mov    -0x40(%rbp),%rdx
    75cf:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    75d3:	48 01 d0             	add    %rdx,%rax
    75d6:	0f b6 00             	movzbl (%rax),%eax
    75d9:	3c 20                	cmp    $0x20,%al
    75db:	74 df                	je     75bc <bLoadGraph+0xbd>
    75dd:	48 8b 55 c0          	mov    -0x40(%rbp),%rdx
    75e1:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    75e5:	48 01 d0             	add    %rdx,%rax
    75e8:	0f b6 00             	movzbl (%rax),%eax
    75eb:	3c 09                	cmp    $0x9,%al
    75ed:	74 cd                	je     75bc <bLoadGraph+0xbd>
    75ef:	48 8b 55 c0          	mov    -0x40(%rbp),%rdx
    75f3:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    75f7:	48 01 d0             	add    %rdx,%rax
    75fa:	0f b6 00             	movzbl (%rax),%eax
    75fd:	3c 0d                	cmp    $0xd,%al
    75ff:	74 bb                	je     75bc <bLoadGraph+0xbd>
    7601:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    7605:	48 3b 45 a8          	cmp    -0x58(%rbp),%rax
    7609:	0f 83 c8 01 00 00    	jae    77d7 <bLoadGraph+0x2d8>
    760f:	48 8b 55 c0          	mov    -0x40(%rbp),%rdx
    7613:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    7617:	48 01 d0             	add    %rdx,%rax
    761a:	0f b6 00             	movzbl (%rax),%eax
    761d:	3c 23                	cmp    $0x23,%al
    761f:	0f 84 b5 01 00 00    	je     77da <bLoadGraph+0x2db>
    7625:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    7629:	48 89 45 b0          	mov    %rax,-0x50(%rbp)
    762d:	eb 05                	jmp    7634 <bLoadGraph+0x135>
    762f:	48 83 45 98 01       	addq   $0x1,-0x68(%rbp)
    7634:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    7638:	48 3b 45 a8          	cmp    -0x58(%rbp),%rax
    763c:	73 12                	jae    7650 <bLoadGraph+0x151>
    763e:	48 8b 55 c0          	mov    -0x40(%rbp),%rdx
    7642:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    7646:	48 01 d0             	add    %rdx,%rax
    7649:	0f b6 00             	movzbl (%rax),%eax
    764c:	3c 20                	cmp    $0x20,%al
    764e:	75 df                	jne    762f <bLoadGraph+0x130>
    7650:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    7654:	48 2b 45 b0          	sub    -0x50(%rbp),%rax
    7658:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
    765c:	48 8b 55 b0          	mov    -0x50(%rbp),%rdx
    7660:	48 01 ca             	add    %rcx,%rdx
    7663:	48 89 c6             	mov    %rax,%rsi
    7666:	48 89 d7             	mov    %rdx,%rdi
    7669:	e8 14 9e ff ff       	call   1482 <Slice_from>
    766e:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
    7672:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    7676:	eb 05                	jmp    767d <bLoadGraph+0x17e>
    7678:	48 83 45 98 01       	addq   $0x1,-0x68(%rbp)
    767d:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    7681:	48 3b 45 a8          	cmp    -0x58(%rbp),%rax
    7685:	73 12                	jae    7699 <bLoadGraph+0x19a>
    7687:	48 8b 55 c0          	mov    -0x40(%rbp),%rdx
    768b:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    768f:	48 01 d0             	add    %rdx,%rax
    7692:	0f b6 00             	movzbl (%rax),%eax
    7695:	3c 20                	cmp    $0x20,%al
    7697:	74 df                	je     7678 <bLoadGraph+0x179>
    7699:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    769d:	48 83 c0 01          	add    $0x1,%rax
    76a1:	48 3b 45 a8          	cmp    -0x58(%rbp),%rax
    76a5:	0f 83 32 01 00 00    	jae    77dd <bLoadGraph+0x2de>
    76ab:	48 8b 55 c0          	mov    -0x40(%rbp),%rdx
    76af:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    76b3:	48 01 d0             	add    %rdx,%rax
    76b6:	0f b6 00             	movzbl (%rax),%eax
    76b9:	3c 2d                	cmp    $0x2d,%al
    76bb:	0f 85 1f 01 00 00    	jne    77e0 <bLoadGraph+0x2e1>
    76c1:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
    76c5:	48 8b 55 98          	mov    -0x68(%rbp),%rdx
    76c9:	48 83 c2 01          	add    $0x1,%rdx
    76cd:	48 01 d0             	add    %rdx,%rax
    76d0:	0f b6 00             	movzbl (%rax),%eax
    76d3:	3c 3e                	cmp    $0x3e,%al
    76d5:	0f 85 05 01 00 00    	jne    77e0 <bLoadGraph+0x2e1>
    76db:	48 83 45 98 02       	addq   $0x2,-0x68(%rbp)
    76e0:	eb 05                	jmp    76e7 <bLoadGraph+0x1e8>
    76e2:	48 83 45 98 01       	addq   $0x1,-0x68(%rbp)
    76e7:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    76eb:	48 3b 45 a8          	cmp    -0x58(%rbp),%rax
    76ef:	73 12                	jae    7703 <bLoadGraph+0x204>
    76f1:	48 8b 55 c0          	mov    -0x40(%rbp),%rdx
    76f5:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    76f9:	48 01 d0             	add    %rdx,%rax
    76fc:	0f b6 00             	movzbl (%rax),%eax
    76ff:	3c 20                	cmp    $0x20,%al
    7701:	74 df                	je     76e2 <bLoadGraph+0x1e3>
    7703:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    7707:	48 89 45 b8          	mov    %rax,-0x48(%rbp)
    770b:	eb 05                	jmp    7712 <bLoadGraph+0x213>
    770d:	48 83 45 98 01       	addq   $0x1,-0x68(%rbp)
    7712:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    7716:	48 3b 45 a8          	cmp    -0x58(%rbp),%rax
    771a:	73 24                	jae    7740 <bLoadGraph+0x241>
    771c:	48 8b 55 c0          	mov    -0x40(%rbp),%rdx
    7720:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    7724:	48 01 d0             	add    %rdx,%rax
    7727:	0f b6 00             	movzbl (%rax),%eax
    772a:	3c 20                	cmp    $0x20,%al
    772c:	74 12                	je     7740 <bLoadGraph+0x241>
    772e:	48 8b 55 c0          	mov    -0x40(%rbp),%rdx
    7732:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    7736:	48 01 d0             	add    %rdx,%rax
    7739:	0f b6 00             	movzbl (%rax),%eax
    773c:	3c 0d                	cmp    $0xd,%al
    773e:	75 cd                	jne    770d <bLoadGraph+0x20e>
    7740:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    7744:	48 2b 45 b8          	sub    -0x48(%rbp),%rax
    7748:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
    774c:	48 8b 55 b8          	mov    -0x48(%rbp),%rdx
    7750:	48 01 ca             	add    %rcx,%rdx
    7753:	48 89 c6             	mov    %rax,%rsi
    7756:	48 89 d7             	mov    %rdx,%rdi
    7759:	e8 24 9d ff ff       	call   1482 <Slice_from>
    775e:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    7762:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
    7766:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    776a:	48 85 c0             	test   %rax,%rax
    776d:	74 74                	je     77e3 <bLoadGraph+0x2e4>
    776f:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    7773:	48 85 c0             	test   %rax,%rax
    7776:	74 6b                	je     77e3 <bLoadGraph+0x2e4>
    7778:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    777c:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    7780:	48 8b 85 78 ff ff ff 	mov    -0x88(%rbp),%rax
    7787:	48 89 ce             	mov    %rcx,%rsi
    778a:	48 89 c7             	mov    %rax,%rdi
    778d:	e8 77 eb ff ff       	call   6309 <bModuleIdx>
    7792:	89 45 80             	mov    %eax,-0x80(%rbp)
    7795:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
    7799:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    779d:	48 8b 85 78 ff ff ff 	mov    -0x88(%rbp),%rax
    77a4:	48 89 ce             	mov    %rcx,%rsi
    77a7:	48 89 c7             	mov    %rax,%rdi
    77aa:	e8 5a eb ff ff       	call   6309 <bModuleIdx>
    77af:	89 45 84             	mov    %eax,-0x7c(%rbp)
    77b2:	83 7d 80 00          	cmpl   $0x0,-0x80(%rbp)
    77b6:	78 2c                	js     77e4 <bLoadGraph+0x2e5>
    77b8:	83 7d 84 00          	cmpl   $0x0,-0x7c(%rbp)
    77bc:	78 26                	js     77e4 <bLoadGraph+0x2e5>
    77be:	8b 55 84             	mov    -0x7c(%rbp),%edx
    77c1:	8b 4d 80             	mov    -0x80(%rbp),%ecx
    77c4:	48 8b 85 78 ff ff ff 	mov    -0x88(%rbp),%rax
    77cb:	89 ce                	mov    %ecx,%esi
    77cd:	48 89 c7             	mov    %rax,%rdi
    77d0:	e8 90 fb ff ff       	call   7365 <bAddEdge>
    77d5:	eb 0d                	jmp    77e4 <bLoadGraph+0x2e5>
    77d7:	90                   	nop
    77d8:	eb 0a                	jmp    77e4 <bLoadGraph+0x2e5>
    77da:	90                   	nop
    77db:	eb 07                	jmp    77e4 <bLoadGraph+0x2e5>
    77dd:	90                   	nop
    77de:	eb 04                	jmp    77e4 <bLoadGraph+0x2e5>
    77e0:	90                   	nop
    77e1:	eb 01                	jmp    77e4 <bLoadGraph+0x2e5>
    77e3:	90                   	nop
    77e4:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    77e8:	48 39 45 90          	cmp    %rax,-0x70(%rbp)
    77ec:	0f 82 7e fd ff ff    	jb     7570 <bLoadGraph+0x71>
    77f2:	b8 01 00 00 00       	mov    $0x1,%eax
    77f7:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
    77fb:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
    7802:	00 00 
    7804:	74 05                	je     780b <bLoadGraph+0x30c>
    7806:	e8 75 98 ff ff       	call   1080 <__stack_chk_fail@plt>
    780b:	c9                   	leave
    780c:	c3                   	ret

000000000000780d <bWriteGraph>:
    780d:	55                   	push   %rbp
    780e:	48 89 e5             	mov    %rsp,%rbp
    7811:	48 83 c4 80          	add    $0xffffffffffffff80,%rsp
    7815:	48 89 7d 88          	mov    %rdi,-0x78(%rbp)
    7819:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    7820:	00 00 
    7822:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    7826:	31 c0                	xor    %eax,%eax
    7828:	48 8d 05 4c 2c 00 00 	lea    0x2c4c(%rip),%rax        # a47b <_IO_stdin_used+0x47b>
    782f:	ba ed 01 00 00       	mov    $0x1ed,%edx
    7834:	48 89 c6             	mov    %rax,%rsi
    7837:	bf 53 00 00 00       	mov    $0x53,%edi
    783c:	b8 00 00 00 00       	mov    $0x0,%eax
    7841:	e8 7a 98 ff ff       	call   10c0 <syscall@plt>
    7846:	48 c7 45 c8 00 00 01 	movq   $0x10000,-0x38(%rbp)
    784d:	00 
    784e:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    7852:	48 89 c7             	mov    %rax,%rdi
    7855:	e8 86 98 ff ff       	call   10e0 <malloc@plt>
    785a:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
    785e:	48 83 7d d0 00       	cmpq   $0x0,-0x30(%rbp)
    7863:	75 0a                	jne    786f <bWriteGraph+0x62>
    7865:	b8 00 00 00 00       	mov    $0x0,%eax
    786a:	e9 4a 04 00 00       	jmp    7cb9 <bWriteGraph+0x4ac>
    786f:	48 c7 45 b8 00 00 00 	movq   $0x0,-0x48(%rbp)
    7876:	00 
    7877:	48 8d 05 ca 2c 00 00 	lea    0x2cca(%rip),%rax        # a548 <_IO_stdin_used+0x548>
    787e:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
    7882:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    7886:	48 89 c7             	mov    %rax,%rdi
    7889:	e8 e2 97 ff ff       	call   1070 <strlen@plt>
    788e:	48 89 c7             	mov    %rax,%rdi
    7891:	48 8b 4d d8          	mov    -0x28(%rbp),%rcx
    7895:	48 8d 55 b8          	lea    -0x48(%rbp),%rdx
    7899:	48 8b 75 c8          	mov    -0x38(%rbp),%rsi
    789d:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    78a1:	49 89 f8             	mov    %rdi,%r8
    78a4:	48 89 c7             	mov    %rax,%rdi
    78a7:	e8 e1 d3 ff ff       	call   4c8d <bApp>
    78ac:	c7 45 a0 00 00 00 00 	movl   $0x0,-0x60(%rbp)
    78b3:	e9 50 01 00 00       	jmp    7a08 <bWriteGraph+0x1fb>
    78b8:	c7 45 a4 00 00 00 00 	movl   $0x0,-0x5c(%rbp)
    78bf:	e9 1f 01 00 00       	jmp    79e3 <bWriteGraph+0x1d6>
    78c4:	48 8d 0d 9c 2c 00 00 	lea    0x2c9c(%rip),%rcx        # a567 <_IO_stdin_used+0x567>
    78cb:	48 8d 55 b8          	lea    -0x48(%rbp),%rdx
    78cf:	48 8b 75 c8          	mov    -0x38(%rbp),%rsi
    78d3:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    78d7:	41 b8 03 00 00 00    	mov    $0x3,%r8d
    78dd:	48 89 c7             	mov    %rax,%rdi
    78e0:	e8 a8 d3 ff ff       	call   4c8d <bApp>
    78e5:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    78e9:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    78f0:	8b 55 a0             	mov    -0x60(%rbp),%edx
    78f3:	48 c1 e2 06          	shl    $0x6,%rdx
    78f7:	48 01 d0             	add    %rdx,%rax
    78fa:	48 8b 78 08          	mov    0x8(%rax),%rdi
    78fe:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    7902:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    7909:	8b 55 a0             	mov    -0x60(%rbp),%edx
    790c:	48 c1 e2 06          	shl    $0x6,%rdx
    7910:	48 01 d0             	add    %rdx,%rax
    7913:	48 8b 08             	mov    (%rax),%rcx
    7916:	48 8d 55 b8          	lea    -0x48(%rbp),%rdx
    791a:	48 8b 75 c8          	mov    -0x38(%rbp),%rsi
    791e:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    7922:	49 89 f8             	mov    %rdi,%r8
    7925:	48 89 c7             	mov    %rax,%rdi
    7928:	e8 60 d3 ff ff       	call   4c8d <bApp>
    792d:	48 8d 0d 37 2c 00 00 	lea    0x2c37(%rip),%rcx        # a56b <_IO_stdin_used+0x56b>
    7934:	48 8d 55 b8          	lea    -0x48(%rbp),%rdx
    7938:	48 8b 75 c8          	mov    -0x38(%rbp),%rsi
    793c:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    7940:	41 b8 06 00 00 00    	mov    $0x6,%r8d
    7946:	48 89 c7             	mov    %rax,%rdi
    7949:	e8 3f d3 ff ff       	call   4c8d <bApp>
    794e:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    7952:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    7959:	8b 55 a0             	mov    -0x60(%rbp),%edx
    795c:	48 c1 e2 06          	shl    $0x6,%rdx
    7960:	48 01 d0             	add    %rdx,%rax
    7963:	48 8b 40 10          	mov    0x10(%rax),%rax
    7967:	8b 55 a4             	mov    -0x5c(%rbp),%edx
    796a:	48 c1 e2 02          	shl    $0x2,%rdx
    796e:	48 01 d0             	add    %rdx,%rax
    7971:	8b 00                	mov    (%rax),%eax
    7973:	89 45 b4             	mov    %eax,-0x4c(%rbp)
    7976:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    797a:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    7981:	8b 55 b4             	mov    -0x4c(%rbp),%edx
    7984:	48 c1 e2 06          	shl    $0x6,%rdx
    7988:	48 01 d0             	add    %rdx,%rax
    798b:	48 8b 78 08          	mov    0x8(%rax),%rdi
    798f:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    7993:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    799a:	8b 55 b4             	mov    -0x4c(%rbp),%edx
    799d:	48 c1 e2 06          	shl    $0x6,%rdx
    79a1:	48 01 d0             	add    %rdx,%rax
    79a4:	48 8b 08             	mov    (%rax),%rcx
    79a7:	48 8d 55 b8          	lea    -0x48(%rbp),%rdx
    79ab:	48 8b 75 c8          	mov    -0x38(%rbp),%rsi
    79af:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    79b3:	49 89 f8             	mov    %rdi,%r8
    79b6:	48 89 c7             	mov    %rax,%rdi
    79b9:	e8 cf d2 ff ff       	call   4c8d <bApp>
    79be:	48 8d 0d ad 2b 00 00 	lea    0x2bad(%rip),%rcx        # a572 <_IO_stdin_used+0x572>
    79c5:	48 8d 55 b8          	lea    -0x48(%rbp),%rdx
    79c9:	48 8b 75 c8          	mov    -0x38(%rbp),%rsi
    79cd:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    79d1:	41 b8 03 00 00 00    	mov    $0x3,%r8d
    79d7:	48 89 c7             	mov    %rax,%rdi
    79da:	e8 ae d2 ff ff       	call   4c8d <bApp>
    79df:	83 45 a4 01          	addl   $0x1,-0x5c(%rbp)
    79e3:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    79e7:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    79ee:	8b 55 a0             	mov    -0x60(%rbp),%edx
    79f1:	48 c1 e2 06          	shl    $0x6,%rdx
    79f5:	48 01 d0             	add    %rdx,%rax
    79f8:	8b 40 18             	mov    0x18(%rax),%eax
    79fb:	39 45 a4             	cmp    %eax,-0x5c(%rbp)
    79fe:	0f 82 c0 fe ff ff    	jb     78c4 <bWriteGraph+0xb7>
    7a04:	83 45 a0 01          	addl   $0x1,-0x60(%rbp)
    7a08:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    7a0c:	8b 40 70             	mov    0x70(%rax),%eax
    7a0f:	39 45 a0             	cmp    %eax,-0x60(%rbp)
    7a12:	0f 82 a0 fe ff ff    	jb     78b8 <bWriteGraph+0xab>
    7a18:	48 8d 0d 57 2b 00 00 	lea    0x2b57(%rip),%rcx        # a576 <_IO_stdin_used+0x576>
    7a1f:	48 8d 55 b8          	lea    -0x48(%rbp),%rdx
    7a23:	48 8b 75 c8          	mov    -0x38(%rbp),%rsi
    7a27:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    7a2b:	41 b8 02 00 00 00    	mov    $0x2,%r8d
    7a31:	48 89 c7             	mov    %rax,%rdi
    7a34:	e8 54 d2 ff ff       	call   4c8d <bApp>
    7a39:	48 8b 55 b8          	mov    -0x48(%rbp),%rdx
    7a3d:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    7a41:	48 8d 0d 31 2b 00 00 	lea    0x2b31(%rip),%rcx        # a579 <_IO_stdin_used+0x579>
    7a48:	48 89 c6             	mov    %rax,%rsi
    7a4b:	48 89 cf             	mov    %rcx,%rdi
    7a4e:	e8 74 ec ff ff       	call   66c7 <bWriteFile>
    7a53:	88 45 9e             	mov    %al,-0x62(%rbp)
    7a56:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    7a5a:	48 89 c7             	mov    %rax,%rdi
    7a5d:	e8 ce 95 ff ff       	call   1030 <free@plt>
    7a62:	0f b6 45 9e          	movzbl -0x62(%rbp),%eax
    7a66:	83 f0 01             	xor    $0x1,%eax
    7a69:	84 c0                	test   %al,%al
    7a6b:	74 26                	je     7a93 <bWriteGraph+0x286>
    7a6d:	48 8d 05 1c 2b 00 00 	lea    0x2b1c(%rip),%rax        # a590 <_IO_stdin_used+0x590>
    7a74:	48 89 c7             	mov    %rax,%rdi
    7a77:	e8 d4 95 ff ff       	call   1050 <puts@plt>
    7a7c:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    7a80:	8b 80 b0 00 00 00    	mov    0xb0(%rax),%eax
    7a86:	8d 50 01             	lea    0x1(%rax),%edx
    7a89:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    7a8d:	89 90 b0 00 00 00    	mov    %edx,0xb0(%rax)
    7a93:	48 c7 45 e0 00 00 01 	movq   $0x10000,-0x20(%rbp)
    7a9a:	00 
    7a9b:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    7a9f:	48 89 c7             	mov    %rax,%rdi
    7aa2:	e8 39 96 ff ff       	call   10e0 <malloc@plt>
    7aa7:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    7aab:	48 83 7d e8 00       	cmpq   $0x0,-0x18(%rbp)
    7ab0:	75 0a                	jne    7abc <bWriteGraph+0x2af>
    7ab2:	b8 00 00 00 00       	mov    $0x0,%eax
    7ab7:	e9 fd 01 00 00       	jmp    7cb9 <bWriteGraph+0x4ac>
    7abc:	48 c7 45 c0 00 00 00 	movq   $0x0,-0x40(%rbp)
    7ac3:	00 
    7ac4:	48 8d 05 ed 2a 00 00 	lea    0x2aed(%rip),%rax        # a5b8 <_IO_stdin_used+0x5b8>
    7acb:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    7acf:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    7ad3:	48 89 c7             	mov    %rax,%rdi
    7ad6:	e8 95 95 ff ff       	call   1070 <strlen@plt>
    7adb:	48 89 c7             	mov    %rax,%rdi
    7ade:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
    7ae2:	48 8d 55 c0          	lea    -0x40(%rbp),%rdx
    7ae6:	48 8b 75 e0          	mov    -0x20(%rbp),%rsi
    7aea:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    7aee:	49 89 f8             	mov    %rdi,%r8
    7af1:	48 89 c7             	mov    %rax,%rdi
    7af4:	e8 94 d1 ff ff       	call   4c8d <bApp>
    7af9:	c7 45 a8 00 00 00 00 	movl   $0x0,-0x58(%rbp)
    7b00:	e9 2f 01 00 00       	jmp    7c34 <bWriteGraph+0x427>
    7b05:	c7 45 ac 00 00 00 00 	movl   $0x0,-0x54(%rbp)
    7b0c:	e9 fe 00 00 00       	jmp    7c0f <bWriteGraph+0x402>
    7b11:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    7b15:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    7b1c:	8b 55 a8             	mov    -0x58(%rbp),%edx
    7b1f:	48 c1 e2 06          	shl    $0x6,%rdx
    7b23:	48 01 d0             	add    %rdx,%rax
    7b26:	48 8b 78 08          	mov    0x8(%rax),%rdi
    7b2a:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    7b2e:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    7b35:	8b 55 a8             	mov    -0x58(%rbp),%edx
    7b38:	48 c1 e2 06          	shl    $0x6,%rdx
    7b3c:	48 01 d0             	add    %rdx,%rax
    7b3f:	48 8b 08             	mov    (%rax),%rcx
    7b42:	48 8d 55 c0          	lea    -0x40(%rbp),%rdx
    7b46:	48 8b 75 e0          	mov    -0x20(%rbp),%rsi
    7b4a:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    7b4e:	49 89 f8             	mov    %rdi,%r8
    7b51:	48 89 c7             	mov    %rax,%rdi
    7b54:	e8 34 d1 ff ff       	call   4c8d <bApp>
    7b59:	48 8d 0d d3 29 00 00 	lea    0x29d3(%rip),%rcx        # a533 <_IO_stdin_used+0x533>
    7b60:	48 8d 55 c0          	lea    -0x40(%rbp),%rdx
    7b64:	48 8b 75 e0          	mov    -0x20(%rbp),%rsi
    7b68:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    7b6c:	41 b8 04 00 00 00    	mov    $0x4,%r8d
    7b72:	48 89 c7             	mov    %rax,%rdi
    7b75:	e8 13 d1 ff ff       	call   4c8d <bApp>
    7b7a:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    7b7e:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    7b85:	8b 55 a8             	mov    -0x58(%rbp),%edx
    7b88:	48 c1 e2 06          	shl    $0x6,%rdx
    7b8c:	48 01 d0             	add    %rdx,%rax
    7b8f:	48 8b 40 10          	mov    0x10(%rax),%rax
    7b93:	8b 55 ac             	mov    -0x54(%rbp),%edx
    7b96:	48 c1 e2 02          	shl    $0x2,%rdx
    7b9a:	48 01 d0             	add    %rdx,%rax
    7b9d:	8b 00                	mov    (%rax),%eax
    7b9f:	89 45 b0             	mov    %eax,-0x50(%rbp)
    7ba2:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    7ba6:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    7bad:	8b 55 b0             	mov    -0x50(%rbp),%edx
    7bb0:	48 c1 e2 06          	shl    $0x6,%rdx
    7bb4:	48 01 d0             	add    %rdx,%rax
    7bb7:	48 8b 78 08          	mov    0x8(%rax),%rdi
    7bbb:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    7bbf:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    7bc6:	8b 55 b0             	mov    -0x50(%rbp),%edx
    7bc9:	48 c1 e2 06          	shl    $0x6,%rdx
    7bcd:	48 01 d0             	add    %rdx,%rax
    7bd0:	48 8b 08             	mov    (%rax),%rcx
    7bd3:	48 8d 55 c0          	lea    -0x40(%rbp),%rdx
    7bd7:	48 8b 75 e0          	mov    -0x20(%rbp),%rsi
    7bdb:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    7bdf:	49 89 f8             	mov    %rdi,%r8
    7be2:	48 89 c7             	mov    %rax,%rdi
    7be5:	e8 a3 d0 ff ff       	call   4c8d <bApp>
    7bea:	48 8d 0d 01 2a 00 00 	lea    0x2a01(%rip),%rcx        # a5f2 <_IO_stdin_used+0x5f2>
    7bf1:	48 8d 55 c0          	lea    -0x40(%rbp),%rdx
    7bf5:	48 8b 75 e0          	mov    -0x20(%rbp),%rsi
    7bf9:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    7bfd:	41 b8 01 00 00 00    	mov    $0x1,%r8d
    7c03:	48 89 c7             	mov    %rax,%rdi
    7c06:	e8 82 d0 ff ff       	call   4c8d <bApp>
    7c0b:	83 45 ac 01          	addl   $0x1,-0x54(%rbp)
    7c0f:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    7c13:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    7c1a:	8b 55 a8             	mov    -0x58(%rbp),%edx
    7c1d:	48 c1 e2 06          	shl    $0x6,%rdx
    7c21:	48 01 d0             	add    %rdx,%rax
    7c24:	8b 40 18             	mov    0x18(%rax),%eax
    7c27:	39 45 ac             	cmp    %eax,-0x54(%rbp)
    7c2a:	0f 82 e1 fe ff ff    	jb     7b11 <bWriteGraph+0x304>
    7c30:	83 45 a8 01          	addl   $0x1,-0x58(%rbp)
    7c34:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    7c38:	8b 40 70             	mov    0x70(%rax),%eax
    7c3b:	39 45 a8             	cmp    %eax,-0x58(%rbp)
    7c3e:	0f 82 c1 fe ff ff    	jb     7b05 <bWriteGraph+0x2f8>
    7c44:	48 8b 55 c0          	mov    -0x40(%rbp),%rdx
    7c48:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    7c4c:	48 8d 0d e5 28 00 00 	lea    0x28e5(%rip),%rcx        # a538 <_IO_stdin_used+0x538>
    7c53:	48 89 c6             	mov    %rax,%rsi
    7c56:	48 89 cf             	mov    %rcx,%rdi
    7c59:	e8 69 ea ff ff       	call   66c7 <bWriteFile>
    7c5e:	88 45 9f             	mov    %al,-0x61(%rbp)
    7c61:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    7c65:	48 89 c7             	mov    %rax,%rdi
    7c68:	e8 c3 93 ff ff       	call   1030 <free@plt>
    7c6d:	0f b6 45 9f          	movzbl -0x61(%rbp),%eax
    7c71:	83 f0 01             	xor    $0x1,%eax
    7c74:	84 c0                	test   %al,%al
    7c76:	74 26                	je     7c9e <bWriteGraph+0x491>
    7c78:	48 8d 05 79 29 00 00 	lea    0x2979(%rip),%rax        # a5f8 <_IO_stdin_used+0x5f8>
    7c7f:	48 89 c7             	mov    %rax,%rdi
    7c82:	e8 c9 93 ff ff       	call   1050 <puts@plt>
    7c87:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    7c8b:	8b 80 b0 00 00 00    	mov    0xb0(%rax),%eax
    7c91:	8d 50 01             	lea    0x1(%rax),%edx
    7c94:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    7c98:	89 90 b0 00 00 00    	mov    %edx,0xb0(%rax)
    7c9e:	80 7d 9e 00          	cmpb   $0x0,-0x62(%rbp)
    7ca2:	74 0d                	je     7cb1 <bWriteGraph+0x4a4>
    7ca4:	80 7d 9f 00          	cmpb   $0x0,-0x61(%rbp)
    7ca8:	74 07                	je     7cb1 <bWriteGraph+0x4a4>
    7caa:	b8 01 00 00 00       	mov    $0x1,%eax
    7caf:	eb 05                	jmp    7cb6 <bWriteGraph+0x4a9>
    7cb1:	b8 00 00 00 00       	mov    $0x0,%eax
    7cb6:	83 e0 01             	and    $0x1,%eax
    7cb9:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
    7cbd:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
    7cc4:	00 00 
    7cc6:	74 05                	je     7ccd <bWriteGraph+0x4c0>
    7cc8:	e8 b3 93 ff ff       	call   1080 <__stack_chk_fail@plt>
    7ccd:	c9                   	leave
    7cce:	c3                   	ret

0000000000007ccf <bWriteFp>:
    7ccf:	55                   	push   %rbp
    7cd0:	48 89 e5             	mov    %rsp,%rbp
    7cd3:	48 83 ec 50          	sub    $0x50,%rsp
    7cd7:	48 89 7d b8          	mov    %rdi,-0x48(%rbp)
    7cdb:	89 75 b4             	mov    %esi,-0x4c(%rbp)
    7cde:	48 8d 05 96 27 00 00 	lea    0x2796(%rip),%rax        # a47b <_IO_stdin_used+0x47b>
    7ce5:	ba ed 01 00 00       	mov    $0x1ed,%edx
    7cea:	48 89 c6             	mov    %rax,%rsi
    7ced:	bf 53 00 00 00       	mov    $0x53,%edi
    7cf2:	b8 00 00 00 00       	mov    $0x0,%eax
    7cf7:	e8 c4 93 ff ff       	call   10c0 <syscall@plt>
    7cfc:	48 8d 05 54 26 00 00 	lea    0x2654(%rip),%rax        # a357 <_IO_stdin_used+0x357>
    7d03:	ba ed 01 00 00       	mov    $0x1ed,%edx
    7d08:	48 89 c6             	mov    %rax,%rsi
    7d0b:	bf 53 00 00 00       	mov    $0x53,%edi
    7d10:	b8 00 00 00 00       	mov    $0x0,%eax
    7d15:	e8 a6 93 ff ff       	call   10c0 <syscall@plt>
    7d1a:	bf 00 02 00 00       	mov    $0x200,%edi
    7d1f:	e8 bc 93 ff ff       	call   10e0 <malloc@plt>
    7d24:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
    7d28:	48 c7 45 c8 00 00 00 	movq   $0x0,-0x38(%rbp)
    7d2f:	00 
    7d30:	48 8d 05 e2 28 00 00 	lea    0x28e2(%rip),%rax        # a619 <_IO_stdin_used+0x619>
    7d37:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    7d3b:	eb 20                	jmp    7d5d <bWriteFp+0x8e>
    7d3d:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    7d41:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    7d45:	48 01 d0             	add    %rdx,%rax
    7d48:	48 8b 4d d8          	mov    -0x28(%rbp),%rcx
    7d4c:	48 8b 55 c8          	mov    -0x38(%rbp),%rdx
    7d50:	48 01 ca             	add    %rcx,%rdx
    7d53:	0f b6 00             	movzbl (%rax),%eax
    7d56:	88 02                	mov    %al,(%rdx)
    7d58:	48 83 45 c8 01       	addq   $0x1,-0x38(%rbp)
    7d5d:	48 83 7d c8 0c       	cmpq   $0xc,-0x38(%rbp)
    7d62:	76 d9                	jbe    7d3d <bWriteFp+0x6e>
    7d64:	48 c7 45 d0 00 00 00 	movq   $0x0,-0x30(%rbp)
    7d6b:	00 
    7d6c:	eb 39                	jmp    7da7 <bWriteFp+0xd8>
    7d6e:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    7d72:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    7d79:	8b 55 b4             	mov    -0x4c(%rbp),%edx
    7d7c:	48 c1 e2 06          	shl    $0x6,%rdx
    7d80:	48 01 d0             	add    %rdx,%rax
    7d83:	48 8b 10             	mov    (%rax),%rdx
    7d86:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    7d8a:	48 01 d0             	add    %rdx,%rax
    7d8d:	48 8b 4d d8          	mov    -0x28(%rbp),%rcx
    7d91:	48 8b 55 c8          	mov    -0x38(%rbp),%rdx
    7d95:	48 01 ca             	add    %rcx,%rdx
    7d98:	0f b6 00             	movzbl (%rax),%eax
    7d9b:	88 02                	mov    %al,(%rdx)
    7d9d:	48 83 45 c8 01       	addq   $0x1,-0x38(%rbp)
    7da2:	48 83 45 d0 01       	addq   $0x1,-0x30(%rbp)
    7da7:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    7dab:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    7db2:	8b 55 b4             	mov    -0x4c(%rbp),%edx
    7db5:	48 c1 e2 06          	shl    $0x6,%rdx
    7db9:	48 01 d0             	add    %rdx,%rax
    7dbc:	48 8b 40 08          	mov    0x8(%rax),%rax
    7dc0:	48 39 45 d0          	cmp    %rax,-0x30(%rbp)
    7dc4:	73 0a                	jae    7dd0 <bWriteFp+0x101>
    7dc6:	48 81 7d c8 f3 01 00 	cmpq   $0x1f3,-0x38(%rbp)
    7dcd:	00 
    7dce:	76 9e                	jbe    7d6e <bWriteFp+0x9f>
    7dd0:	48 8d 05 50 28 00 00 	lea    0x2850(%rip),%rax        # a627 <_IO_stdin_used+0x627>
    7dd7:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    7ddb:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    7ddf:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    7de3:	48 01 c2             	add    %rax,%rdx
    7de6:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    7dea:	0f b6 00             	movzbl (%rax),%eax
    7ded:	88 02                	mov    %al,(%rdx)
    7def:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    7df3:	48 8d 50 01          	lea    0x1(%rax),%rdx
    7df7:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    7dfb:	48 01 c2             	add    %rax,%rdx
    7dfe:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    7e02:	0f b6 40 01          	movzbl 0x1(%rax),%eax
    7e06:	88 02                	mov    %al,(%rdx)
    7e08:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    7e0c:	48 8d 50 02          	lea    0x2(%rax),%rdx
    7e10:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    7e14:	48 01 c2             	add    %rax,%rdx
    7e17:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    7e1b:	0f b6 40 02          	movzbl 0x2(%rax),%eax
    7e1f:	88 02                	mov    %al,(%rdx)
    7e21:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    7e25:	48 8d 50 03          	lea    0x3(%rax),%rdx
    7e29:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    7e2d:	48 01 d0             	add    %rdx,%rax
    7e30:	c6 00 00             	movb   $0x0,(%rax)
    7e33:	bf 11 00 00 00       	mov    $0x11,%edi
    7e38:	e8 a3 92 ff ff       	call   10e0 <malloc@plt>
    7e3d:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    7e41:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    7e45:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    7e4c:	8b 55 b4             	mov    -0x4c(%rbp),%edx
    7e4f:	48 c1 e2 06          	shl    $0x6,%rdx
    7e53:	48 01 d0             	add    %rdx,%rax
    7e56:	48 8b 40 30          	mov    0x30(%rax),%rax
    7e5a:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    7e5e:	c7 45 c0 00 00 00 00 	movl   $0x0,-0x40(%rbp)
    7e65:	eb 51                	jmp    7eb8 <bWriteFp+0x1e9>
    7e67:	b8 0f 00 00 00       	mov    $0xf,%eax
    7e6c:	2b 45 c0             	sub    -0x40(%rbp),%eax
    7e6f:	c1 e0 02             	shl    $0x2,%eax
    7e72:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
    7e76:	89 c1                	mov    %eax,%ecx
    7e78:	48 d3 ea             	shr    %cl,%rdx
    7e7b:	48 89 d0             	mov    %rdx,%rax
    7e7e:	83 e0 0f             	and    $0xf,%eax
    7e81:	89 45 c4             	mov    %eax,-0x3c(%rbp)
    7e84:	83 7d c4 09          	cmpl   $0x9,-0x3c(%rbp)
    7e88:	77 16                	ja     7ea0 <bWriteFp+0x1d1>
    7e8a:	8b 45 c4             	mov    -0x3c(%rbp),%eax
    7e8d:	89 c1                	mov    %eax,%ecx
    7e8f:	8b 55 c0             	mov    -0x40(%rbp),%edx
    7e92:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    7e96:	48 01 d0             	add    %rdx,%rax
    7e99:	8d 51 30             	lea    0x30(%rcx),%edx
    7e9c:	88 10                	mov    %dl,(%rax)
    7e9e:	eb 14                	jmp    7eb4 <bWriteFp+0x1e5>
    7ea0:	8b 45 c4             	mov    -0x3c(%rbp),%eax
    7ea3:	89 c1                	mov    %eax,%ecx
    7ea5:	8b 55 c0             	mov    -0x40(%rbp),%edx
    7ea8:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    7eac:	48 01 d0             	add    %rdx,%rax
    7eaf:	8d 51 57             	lea    0x57(%rcx),%edx
    7eb2:	88 10                	mov    %dl,(%rax)
    7eb4:	83 45 c0 01          	addl   $0x1,-0x40(%rbp)
    7eb8:	83 7d c0 0f          	cmpl   $0xf,-0x40(%rbp)
    7ebc:	76 a9                	jbe    7e67 <bWriteFp+0x198>
    7ebe:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    7ec2:	48 83 c0 10          	add    $0x10,%rax
    7ec6:	c6 00 00             	movb   $0x0,(%rax)
    7ec9:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
    7ecd:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    7ed1:	ba 10 00 00 00       	mov    $0x10,%edx
    7ed6:	48 89 ce             	mov    %rcx,%rsi
    7ed9:	48 89 c7             	mov    %rax,%rdi
    7edc:	e8 e6 e7 ff ff       	call   66c7 <bWriteFile>
    7ee1:	c9                   	leave
    7ee2:	c3                   	ret

0000000000007ee3 <bCheckFp>:
    7ee3:	55                   	push   %rbp
    7ee4:	48 89 e5             	mov    %rsp,%rbp
    7ee7:	48 83 c4 80          	add    $0xffffffffffffff80,%rsp
    7eeb:	48 89 7d 88          	mov    %rdi,-0x78(%rbp)
    7eef:	89 75 84             	mov    %esi,-0x7c(%rbp)
    7ef2:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    7ef9:	00 00 
    7efb:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    7eff:	31 c0                	xor    %eax,%eax
    7f01:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    7f05:	0f b6 80 b4 00 00 00 	movzbl 0xb4(%rax),%eax
    7f0c:	84 c0                	test   %al,%al
    7f0e:	74 0a                	je     7f1a <bCheckFp+0x37>
    7f10:	b8 01 00 00 00       	mov    $0x1,%eax
    7f15:	e9 28 02 00 00       	jmp    8142 <bCheckFp+0x25f>
    7f1a:	bf 00 02 00 00       	mov    $0x200,%edi
    7f1f:	e8 bc 91 ff ff       	call   10e0 <malloc@plt>
    7f24:	48 89 45 b8          	mov    %rax,-0x48(%rbp)
    7f28:	48 c7 45 a8 00 00 00 	movq   $0x0,-0x58(%rbp)
    7f2f:	00 
    7f30:	48 8d 05 e2 26 00 00 	lea    0x26e2(%rip),%rax        # a619 <_IO_stdin_used+0x619>
    7f37:	48 89 45 c0          	mov    %rax,-0x40(%rbp)
    7f3b:	eb 20                	jmp    7f5d <bCheckFp+0x7a>
    7f3d:	48 8b 55 c0          	mov    -0x40(%rbp),%rdx
    7f41:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    7f45:	48 01 d0             	add    %rdx,%rax
    7f48:	48 8b 4d b8          	mov    -0x48(%rbp),%rcx
    7f4c:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
    7f50:	48 01 ca             	add    %rcx,%rdx
    7f53:	0f b6 00             	movzbl (%rax),%eax
    7f56:	88 02                	mov    %al,(%rdx)
    7f58:	48 83 45 a8 01       	addq   $0x1,-0x58(%rbp)
    7f5d:	48 83 7d a8 0c       	cmpq   $0xc,-0x58(%rbp)
    7f62:	76 d9                	jbe    7f3d <bCheckFp+0x5a>
    7f64:	48 c7 45 b0 00 00 00 	movq   $0x0,-0x50(%rbp)
    7f6b:	00 
    7f6c:	eb 39                	jmp    7fa7 <bCheckFp+0xc4>
    7f6e:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    7f72:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    7f79:	8b 55 84             	mov    -0x7c(%rbp),%edx
    7f7c:	48 c1 e2 06          	shl    $0x6,%rdx
    7f80:	48 01 d0             	add    %rdx,%rax
    7f83:	48 8b 10             	mov    (%rax),%rdx
    7f86:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    7f8a:	48 01 d0             	add    %rdx,%rax
    7f8d:	48 8b 4d b8          	mov    -0x48(%rbp),%rcx
    7f91:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
    7f95:	48 01 ca             	add    %rcx,%rdx
    7f98:	0f b6 00             	movzbl (%rax),%eax
    7f9b:	88 02                	mov    %al,(%rdx)
    7f9d:	48 83 45 a8 01       	addq   $0x1,-0x58(%rbp)
    7fa2:	48 83 45 b0 01       	addq   $0x1,-0x50(%rbp)
    7fa7:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    7fab:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    7fb2:	8b 55 84             	mov    -0x7c(%rbp),%edx
    7fb5:	48 c1 e2 06          	shl    $0x6,%rdx
    7fb9:	48 01 d0             	add    %rdx,%rax
    7fbc:	48 8b 40 08          	mov    0x8(%rax),%rax
    7fc0:	48 39 45 b0          	cmp    %rax,-0x50(%rbp)
    7fc4:	73 0a                	jae    7fd0 <bCheckFp+0xed>
    7fc6:	48 81 7d a8 f3 01 00 	cmpq   $0x1f3,-0x58(%rbp)
    7fcd:	00 
    7fce:	76 9e                	jbe    7f6e <bCheckFp+0x8b>
    7fd0:	48 8d 05 50 26 00 00 	lea    0x2650(%rip),%rax        # a627 <_IO_stdin_used+0x627>
    7fd7:	48 89 45 c8          	mov    %rax,-0x38(%rbp)
    7fdb:	48 8b 55 b8          	mov    -0x48(%rbp),%rdx
    7fdf:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    7fe3:	48 01 c2             	add    %rax,%rdx
    7fe6:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    7fea:	0f b6 00             	movzbl (%rax),%eax
    7fed:	88 02                	mov    %al,(%rdx)
    7fef:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    7ff3:	48 8d 50 01          	lea    0x1(%rax),%rdx
    7ff7:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    7ffb:	48 01 c2             	add    %rax,%rdx
    7ffe:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    8002:	0f b6 40 01          	movzbl 0x1(%rax),%eax
    8006:	88 02                	mov    %al,(%rdx)
    8008:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    800c:	48 8d 50 02          	lea    0x2(%rax),%rdx
    8010:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    8014:	48 01 c2             	add    %rax,%rdx
    8017:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    801b:	0f b6 40 02          	movzbl 0x2(%rax),%eax
    801f:	88 02                	mov    %al,(%rdx)
    8021:	48 8b 45 a8          	mov    -0x58(%rbp),%rax
    8025:	48 8d 50 03          	lea    0x3(%rax),%rdx
    8029:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    802d:	48 01 d0             	add    %rdx,%rax
    8030:	c6 00 00             	movb   $0x0,(%rax)
    8033:	48 c7 45 a0 00 00 00 	movq   $0x0,-0x60(%rbp)
    803a:	00 
    803b:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    803f:	48 8b 00             	mov    (%rax),%rax
    8042:	48 8d 55 a0          	lea    -0x60(%rbp),%rdx
    8046:	48 8b 4d b8          	mov    -0x48(%rbp),%rcx
    804a:	48 89 ce             	mov    %rcx,%rsi
    804d:	48 89 c7             	mov    %rax,%rdi
    8050:	e8 f3 cc ff ff       	call   4d48 <bReadFile>
    8055:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    8059:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
    805d:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
    8061:	48 85 c0             	test   %rax,%rax
    8064:	74 0a                	je     8070 <bCheckFp+0x18d>
    8066:	48 8b 45 a0          	mov    -0x60(%rbp),%rax
    806a:	48 83 f8 0f          	cmp    $0xf,%rax
    806e:	77 0a                	ja     807a <bCheckFp+0x197>
    8070:	b8 01 00 00 00       	mov    $0x1,%eax
    8075:	e9 c8 00 00 00       	jmp    8142 <bCheckFp+0x25f>
    807a:	bf 11 00 00 00       	mov    $0x11,%edi
    807f:	e8 5c 90 ff ff       	call   10e0 <malloc@plt>
    8084:	48 89 45 d0          	mov    %rax,-0x30(%rbp)
    8088:	48 8b 45 88          	mov    -0x78(%rbp),%rax
    808c:	48 8b 80 98 00 00 00 	mov    0x98(%rax),%rax
    8093:	8b 55 84             	mov    -0x7c(%rbp),%edx
    8096:	48 c1 e2 06          	shl    $0x6,%rdx
    809a:	48 01 d0             	add    %rdx,%rax
    809d:	48 8b 40 30          	mov    0x30(%rax),%rax
    80a1:	48 89 45 d8          	mov    %rax,-0x28(%rbp)
    80a5:	c7 45 94 00 00 00 00 	movl   $0x0,-0x6c(%rbp)
    80ac:	eb 51                	jmp    80ff <bCheckFp+0x21c>
    80ae:	b8 0f 00 00 00       	mov    $0xf,%eax
    80b3:	2b 45 94             	sub    -0x6c(%rbp),%eax
    80b6:	c1 e0 02             	shl    $0x2,%eax
    80b9:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    80bd:	89 c1                	mov    %eax,%ecx
    80bf:	48 d3 ea             	shr    %cl,%rdx
    80c2:	48 89 d0             	mov    %rdx,%rax
    80c5:	83 e0 0f             	and    $0xf,%eax
    80c8:	89 45 9c             	mov    %eax,-0x64(%rbp)
    80cb:	83 7d 9c 09          	cmpl   $0x9,-0x64(%rbp)
    80cf:	77 16                	ja     80e7 <bCheckFp+0x204>
    80d1:	8b 45 9c             	mov    -0x64(%rbp),%eax
    80d4:	89 c1                	mov    %eax,%ecx
    80d6:	8b 55 94             	mov    -0x6c(%rbp),%edx
    80d9:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    80dd:	48 01 d0             	add    %rdx,%rax
    80e0:	8d 51 30             	lea    0x30(%rcx),%edx
    80e3:	88 10                	mov    %dl,(%rax)
    80e5:	eb 14                	jmp    80fb <bCheckFp+0x218>
    80e7:	8b 45 9c             	mov    -0x64(%rbp),%eax
    80ea:	89 c1                	mov    %eax,%ecx
    80ec:	8b 55 94             	mov    -0x6c(%rbp),%edx
    80ef:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    80f3:	48 01 d0             	add    %rdx,%rax
    80f6:	8d 51 57             	lea    0x57(%rcx),%edx
    80f9:	88 10                	mov    %dl,(%rax)
    80fb:	83 45 94 01          	addl   $0x1,-0x6c(%rbp)
    80ff:	83 7d 94 0f          	cmpl   $0xf,-0x6c(%rbp)
    8103:	76 a9                	jbe    80ae <bCheckFp+0x1cb>
    8105:	c7 45 98 00 00 00 00 	movl   $0x0,-0x68(%rbp)
    810c:	eb 29                	jmp    8137 <bCheckFp+0x254>
    810e:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    8112:	8b 45 98             	mov    -0x68(%rbp),%eax
    8115:	48 01 d0             	add    %rdx,%rax
    8118:	0f b6 10             	movzbl (%rax),%edx
    811b:	8b 4d 98             	mov    -0x68(%rbp),%ecx
    811e:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    8122:	48 01 c8             	add    %rcx,%rax
    8125:	0f b6 00             	movzbl (%rax),%eax
    8128:	38 c2                	cmp    %al,%dl
    812a:	74 07                	je     8133 <bCheckFp+0x250>
    812c:	b8 01 00 00 00       	mov    $0x1,%eax
    8131:	eb 0f                	jmp    8142 <bCheckFp+0x25f>
    8133:	83 45 98 01          	addl   $0x1,-0x68(%rbp)
    8137:	83 7d 98 0f          	cmpl   $0xf,-0x68(%rbp)
    813b:	76 d1                	jbe    810e <bCheckFp+0x22b>
    813d:	b8 00 00 00 00       	mov    $0x0,%eax
    8142:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
    8146:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
    814d:	00 00 
    814f:	74 05                	je     8156 <bCheckFp+0x273>
    8151:	e8 2a 8f ff ff       	call   1080 <__stack_chk_fail@plt>
    8156:	c9                   	leave
    8157:	c3                   	ret

0000000000008158 <builderRun>:
    8158:	55                   	push   %rbp
    8159:	48 89 e5             	mov    %rsp,%rbp
    815c:	53                   	push   %rbx
    815d:	48 81 ec 08 01 00 00 	sub    $0x108,%rsp
    8164:	48 89 bd 08 ff ff ff 	mov    %rdi,-0xf8(%rbp)
    816b:	48 89 b5 00 ff ff ff 	mov    %rsi,-0x100(%rbp)
    8172:	88 95 ff fe ff ff    	mov    %dl,-0x101(%rbp)
    8178:	88 8d fe fe ff ff    	mov    %cl,-0x102(%rbp)
    817e:	4c 89 85 f0 fe ff ff 	mov    %r8,-0x110(%rbp)
    8185:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    818c:	00 00 
    818e:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    8192:	31 c0                	xor    %eax,%eax
    8194:	0f b6 bd fe fe ff ff 	movzbl -0x102(%rbp),%edi
    819b:	0f b6 8d ff fe ff ff 	movzbl -0x101(%rbp),%ecx
    81a2:	48 8b 95 08 ff ff ff 	mov    -0xf8(%rbp),%rdx
    81a9:	48 8b b5 00 ff ff ff 	mov    -0x100(%rbp),%rsi
    81b0:	48 8d 85 30 ff ff ff 	lea    -0xd0(%rbp),%rax
    81b7:	41 89 f8             	mov    %edi,%r8d
    81ba:	48 89 c7             	mov    %rax,%rdi
    81bd:	e8 cd d8 ff ff       	call   5a8f <bInit>
    81c2:	83 f0 01             	xor    $0x1,%eax
    81c5:	84 c0                	test   %al,%al
    81c7:	74 08                	je     81d1 <builderRun+0x79>
    81c9:	8b 45 e0             	mov    -0x20(%rbp),%eax
    81cc:	e9 3e 04 00 00       	jmp    860f <builderRun+0x4b7>
    81d1:	c7 85 10 ff ff ff 00 	movl   $0x0,-0xf0(%rbp)
    81d8:	00 00 00 
    81db:	eb 41                	jmp    821e <builderRun+0xc6>
    81dd:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    81e1:	8b 95 10 ff ff ff    	mov    -0xf0(%rbp),%edx
    81e7:	48 c1 e2 04          	shl    $0x4,%rdx
    81eb:	48 01 d0             	add    %rdx,%rax
    81ee:	48 8b 08             	mov    (%rax),%rcx
    81f1:	48 8b 50 08          	mov    0x8(%rax),%rdx
    81f5:	48 8d 85 30 ff ff ff 	lea    -0xd0(%rbp),%rax
    81fc:	48 89 ce             	mov    %rcx,%rsi
    81ff:	48 89 c7             	mov    %rax,%rdi
    8202:	e8 7c e1 ff ff       	call   6383 <bScanLib>
    8207:	83 f0 01             	xor    $0x1,%eax
    820a:	84 c0                	test   %al,%al
    820c:	74 09                	je     8217 <builderRun+0xbf>
    820e:	83 85 10 ff ff ff 01 	addl   $0x1,-0xf0(%rbp)
    8215:	eb 07                	jmp    821e <builderRun+0xc6>
    8217:	83 85 10 ff ff ff 01 	addl   $0x1,-0xf0(%rbp)
    821e:	8b 45 a0             	mov    -0x60(%rbp),%eax
    8221:	39 85 10 ff ff ff    	cmp    %eax,-0xf0(%rbp)
    8227:	72 b4                	jb     81dd <builderRun+0x85>
    8229:	8b 45 e0             	mov    -0x20(%rbp),%eax
    822c:	85 c0                	test   %eax,%eax
    822e:	74 08                	je     8238 <builderRun+0xe0>
    8230:	8b 45 e0             	mov    -0x20(%rbp),%eax
    8233:	e9 d7 03 00 00       	jmp    860f <builderRun+0x4b7>
    8238:	48 8d 85 30 ff ff ff 	lea    -0xd0(%rbp),%rax
    823f:	48 89 c7             	mov    %rax,%rdi
    8242:	e8 c8 e2 ff ff       	call   650f <bValidateAliases>
    8247:	83 f0 01             	xor    $0x1,%eax
    824a:	84 c0                	test   %al,%al
    824c:	74 08                	je     8256 <builderRun+0xfe>
    824e:	8b 45 e0             	mov    -0x20(%rbp),%eax
    8251:	e9 b9 03 00 00       	jmp    860f <builderRun+0x4b7>
    8256:	48 8d 85 30 ff ff ff 	lea    -0xd0(%rbp),%rax
    825d:	48 89 c7             	mov    %rax,%rdi
    8260:	e8 c8 e4 ff ff       	call   672d <bWriteMap>
    8265:	83 f0 01             	xor    $0x1,%eax
    8268:	84 c0                	test   %al,%al
    826a:	74 08                	je     8274 <builderRun+0x11c>
    826c:	8b 45 e0             	mov    -0x20(%rbp),%eax
    826f:	e9 9b 03 00 00       	jmp    860f <builderRun+0x4b7>
    8274:	48 8d 85 30 ff ff ff 	lea    -0xd0(%rbp),%rax
    827b:	48 89 c7             	mov    %rax,%rdi
    827e:	e8 fa e9 ff ff       	call   6c7d <bFingerprint>
    8283:	83 f0 01             	xor    $0x1,%eax
    8286:	84 c0                	test   %al,%al
    8288:	74 08                	je     8292 <builderRun+0x13a>
    828a:	8b 45 e0             	mov    -0x20(%rbp),%eax
    828d:	e9 7d 03 00 00       	jmp    860f <builderRun+0x4b7>
    8292:	48 8d 85 30 ff ff ff 	lea    -0xd0(%rbp),%rax
    8299:	48 89 c7             	mov    %rax,%rdi
    829c:	e8 5e f2 ff ff       	call   74ff <bLoadGraph>
    82a1:	83 f0 01             	xor    $0x1,%eax
    82a4:	84 c0                	test   %al,%al
    82a6:	74 08                	je     82b0 <builderRun+0x158>
    82a8:	8b 45 e0             	mov    -0x20(%rbp),%eax
    82ab:	e9 5f 03 00 00       	jmp    860f <builderRun+0x4b7>
    82b0:	48 8d 85 30 ff ff ff 	lea    -0xd0(%rbp),%rax
    82b7:	48 89 c7             	mov    %rax,%rdi
    82ba:	e8 20 ef ff ff       	call   71df <bTopo>
    82bf:	83 f0 01             	xor    $0x1,%eax
    82c2:	84 c0                	test   %al,%al
    82c4:	74 08                	je     82ce <builderRun+0x176>
    82c6:	8b 45 e0             	mov    -0x20(%rbp),%eax
    82c9:	e9 41 03 00 00       	jmp    860f <builderRun+0x4b7>
    82ce:	48 8d 85 30 ff ff ff 	lea    -0xd0(%rbp),%rax
    82d5:	48 89 c7             	mov    %rax,%rdi
    82d8:	e8 30 f5 ff ff       	call   780d <bWriteGraph>
    82dd:	83 f0 01             	xor    $0x1,%eax
    82e0:	84 c0                	test   %al,%al
    82e2:	74 08                	je     82ec <builderRun+0x194>
    82e4:	8b 45 e0             	mov    -0x20(%rbp),%eax
    82e7:	e9 23 03 00 00       	jmp    860f <builderRun+0x4b7>
    82ec:	c7 85 14 ff ff ff 00 	movl   $0x0,-0xec(%rbp)
    82f3:	00 00 00 
    82f6:	e9 fc 00 00 00       	jmp    83f7 <builderRun+0x29f>
    82fb:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    82ff:	8b 95 14 ff ff ff    	mov    -0xec(%rbp),%edx
    8305:	48 c1 e2 02          	shl    $0x2,%rdx
    8309:	48 01 d0             	add    %rdx,%rax
    830c:	8b 00                	mov    (%rax),%eax
    830e:	89 85 20 ff ff ff    	mov    %eax,-0xe0(%rbp)
    8314:	c7 85 18 ff ff ff 00 	movl   $0x0,-0xe8(%rbp)
    831b:	00 00 00 
    831e:	e9 81 00 00 00       	jmp    83a4 <builderRun+0x24c>
    8323:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    8327:	8b 95 20 ff ff ff    	mov    -0xe0(%rbp),%edx
    832d:	48 c1 e2 06          	shl    $0x6,%rdx
    8331:	48 01 d0             	add    %rdx,%rax
    8334:	48 8b 40 10          	mov    0x10(%rax),%rax
    8338:	8b 95 18 ff ff ff    	mov    -0xe8(%rbp),%edx
    833e:	48 c1 e2 02          	shl    $0x2,%rdx
    8342:	48 01 d0             	add    %rdx,%rax
    8345:	8b 00                	mov    (%rax),%eax
    8347:	89 85 24 ff ff ff    	mov    %eax,-0xdc(%rbp)
    834d:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    8351:	8b 95 24 ff ff ff    	mov    -0xdc(%rbp),%edx
    8357:	48 c1 e2 06          	shl    $0x6,%rdx
    835b:	48 01 d0             	add    %rdx,%rax
    835e:	48 8d 48 30          	lea    0x30(%rax),%rcx
    8362:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    8366:	8b 95 20 ff ff ff    	mov    -0xe0(%rbp),%edx
    836c:	48 c1 e2 06          	shl    $0x6,%rdx
    8370:	48 01 d0             	add    %rdx,%rax
    8373:	48 8b 40 30          	mov    0x30(%rax),%rax
    8377:	48 8b 55 c8          	mov    -0x38(%rbp),%rdx
    837b:	8b b5 20 ff ff ff    	mov    -0xe0(%rbp),%esi
    8381:	48 c1 e6 06          	shl    $0x6,%rsi
    8385:	48 8d 1c 32          	lea    (%rdx,%rsi,1),%rbx
    8389:	ba 08 00 00 00       	mov    $0x8,%edx
    838e:	48 89 ce             	mov    %rcx,%rsi
    8391:	48 89 c7             	mov    %rax,%rdi
    8394:	e8 9a c8 ff ff       	call   4c33 <bFnv>
    8399:	48 89 43 30          	mov    %rax,0x30(%rbx)
    839d:	83 85 18 ff ff ff 01 	addl   $0x1,-0xe8(%rbp)
    83a4:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    83a8:	8b 95 20 ff ff ff    	mov    -0xe0(%rbp),%edx
    83ae:	48 c1 e2 06          	shl    $0x6,%rdx
    83b2:	48 01 d0             	add    %rdx,%rax
    83b5:	8b 40 18             	mov    0x18(%rax),%eax
    83b8:	39 85 18 ff ff ff    	cmp    %eax,-0xe8(%rbp)
    83be:	0f 82 5f ff ff ff    	jb     8323 <builderRun+0x1cb>
    83c4:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    83c8:	8b 95 20 ff ff ff    	mov    -0xe0(%rbp),%edx
    83ce:	48 c1 e2 06          	shl    $0x6,%rdx
    83d2:	48 8d 1c 10          	lea    (%rax,%rdx,1),%rbx
    83d6:	8b 95 20 ff ff ff    	mov    -0xe0(%rbp),%edx
    83dc:	48 8d 85 30 ff ff ff 	lea    -0xd0(%rbp),%rax
    83e3:	89 d6                	mov    %edx,%esi
    83e5:	48 89 c7             	mov    %rax,%rdi
    83e8:	e8 f6 fa ff ff       	call   7ee3 <bCheckFp>
    83ed:	88 43 38             	mov    %al,0x38(%rbx)
    83f0:	83 85 14 ff ff ff 01 	addl   $0x1,-0xec(%rbp)
    83f7:	8b 45 d0             	mov    -0x30(%rbp),%eax
    83fa:	39 85 14 ff ff ff    	cmp    %eax,-0xec(%rbp)
    8400:	0f 82 f5 fe ff ff    	jb     82fb <builderRun+0x1a3>
    8406:	8b 45 c0             	mov    -0x40(%rbp),%eax
    8409:	89 c2                	mov    %eax,%edx
    840b:	8b 45 a0             	mov    -0x60(%rbp),%eax
    840e:	89 c1                	mov    %eax,%ecx
    8410:	48 8d 05 19 22 00 00 	lea    0x2219(%rip),%rax        # a630 <_IO_stdin_used+0x630>
    8417:	89 ce                	mov    %ecx,%esi
    8419:	48 89 c7             	mov    %rax,%rdi
    841c:	b8 00 00 00 00       	mov    $0x0,%eax
    8421:	e8 6a 8c ff ff       	call   1090 <printf@plt>
    8426:	0f b6 85 fe fe ff ff 	movzbl -0x102(%rbp),%eax
    842d:	83 f0 01             	xor    $0x1,%eax
    8430:	84 c0                	test   %al,%al
    8432:	0f 84 d5 00 00 00    	je     850d <builderRun+0x3b5>
    8438:	c7 85 14 ff ff ff 00 	movl   $0x0,-0xec(%rbp)
    843f:	00 00 00 
    8442:	e9 b7 00 00 00       	jmp    84fe <builderRun+0x3a6>
    8447:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    844b:	8b 95 14 ff ff ff    	mov    -0xec(%rbp),%edx
    8451:	48 c1 e2 02          	shl    $0x2,%rdx
    8455:	48 01 d0             	add    %rdx,%rax
    8458:	8b 00                	mov    (%rax),%eax
    845a:	89 85 1c ff ff ff    	mov    %eax,-0xe4(%rbp)
    8460:	48 c7 85 28 ff ff ff 	movq   $0x0,-0xd8(%rbp)
    8467:	00 00 00 00 
    846b:	eb 33                	jmp    84a0 <builderRun+0x348>
    846d:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    8471:	8b 95 1c ff ff ff    	mov    -0xe4(%rbp),%edx
    8477:	48 c1 e2 06          	shl    $0x6,%rdx
    847b:	48 01 d0             	add    %rdx,%rax
    847e:	48 8b 10             	mov    (%rax),%rdx
    8481:	48 8b 85 28 ff ff ff 	mov    -0xd8(%rbp),%rax
    8488:	48 01 d0             	add    %rdx,%rax
    848b:	0f b6 00             	movzbl (%rax),%eax
    848e:	0f b6 c0             	movzbl %al,%eax
    8491:	89 c7                	mov    %eax,%edi
    8493:	e8 a8 8b ff ff       	call   1040 <putchar@plt>
    8498:	48 83 85 28 ff ff ff 	addq   $0x1,-0xd8(%rbp)
    849f:	01 
    84a0:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    84a4:	8b 95 1c ff ff ff    	mov    -0xe4(%rbp),%edx
    84aa:	48 c1 e2 06          	shl    $0x6,%rdx
    84ae:	48 01 d0             	add    %rdx,%rax
    84b1:	48 8b 40 08          	mov    0x8(%rax),%rax
    84b5:	48 39 85 28 ff ff ff 	cmp    %rax,-0xd8(%rbp)
    84bc:	72 af                	jb     846d <builderRun+0x315>
    84be:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    84c2:	8b 95 1c ff ff ff    	mov    -0xe4(%rbp),%edx
    84c8:	48 c1 e2 06          	shl    $0x6,%rdx
    84cc:	48 01 d0             	add    %rdx,%rax
    84cf:	0f b6 40 38          	movzbl 0x38(%rax),%eax
    84d3:	84 c0                	test   %al,%al
    84d5:	74 11                	je     84e8 <builderRun+0x390>
    84d7:	48 8d 05 80 21 00 00 	lea    0x2180(%rip),%rax        # a65e <_IO_stdin_used+0x65e>
    84de:	48 89 c7             	mov    %rax,%rdi
    84e1:	e8 6a 8b ff ff       	call   1050 <puts@plt>
    84e6:	eb 0f                	jmp    84f7 <builderRun+0x39f>
    84e8:	48 8d 05 77 21 00 00 	lea    0x2177(%rip),%rax        # a666 <_IO_stdin_used+0x666>
    84ef:	48 89 c7             	mov    %rax,%rdi
    84f2:	e8 59 8b ff ff       	call   1050 <puts@plt>
    84f7:	83 85 14 ff ff ff 01 	addl   $0x1,-0xec(%rbp)
    84fe:	8b 45 d0             	mov    -0x30(%rbp),%eax
    8501:	39 85 14 ff ff ff    	cmp    %eax,-0xec(%rbp)
    8507:	0f 82 3a ff ff ff    	jb     8447 <builderRun+0x2ef>
    850d:	48 83 bd f0 fe ff ff 	cmpq   $0x0,-0x110(%rbp)
    8514:	00 
    8515:	0f 84 f1 00 00 00    	je     860c <builderRun+0x4b4>
    851b:	48 8b 85 f0 fe ff ff 	mov    -0x110(%rbp),%rax
    8522:	48 8b 8d 30 ff ff ff 	mov    -0xd0(%rbp),%rcx
    8529:	48 8b 9d 38 ff ff ff 	mov    -0xc8(%rbp),%rbx
    8530:	48 89 08             	mov    %rcx,(%rax)
    8533:	48 89 58 08          	mov    %rbx,0x8(%rax)
    8537:	48 8b 8d 40 ff ff ff 	mov    -0xc0(%rbp),%rcx
    853e:	48 8b 9d 48 ff ff ff 	mov    -0xb8(%rbp),%rbx
    8545:	48 89 48 10          	mov    %rcx,0x10(%rax)
    8549:	48 89 58 18          	mov    %rbx,0x18(%rax)
    854d:	48 8b 8d 50 ff ff ff 	mov    -0xb0(%rbp),%rcx
    8554:	48 8b 9d 58 ff ff ff 	mov    -0xa8(%rbp),%rbx
    855b:	48 89 48 20          	mov    %rcx,0x20(%rax)
    855f:	48 89 58 28          	mov    %rbx,0x28(%rax)
    8563:	48 8b 8d 60 ff ff ff 	mov    -0xa0(%rbp),%rcx
    856a:	48 8b 9d 68 ff ff ff 	mov    -0x98(%rbp),%rbx
    8571:	48 89 48 30          	mov    %rcx,0x30(%rax)
    8575:	48 89 58 38          	mov    %rbx,0x38(%rax)
    8579:	48 8b 8d 70 ff ff ff 	mov    -0x90(%rbp),%rcx
    8580:	48 8b 9d 78 ff ff ff 	mov    -0x88(%rbp),%rbx
    8587:	48 89 48 40          	mov    %rcx,0x40(%rax)
    858b:	48 89 58 48          	mov    %rbx,0x48(%rax)
    858f:	48 8b 4d 80          	mov    -0x80(%rbp),%rcx
    8593:	48 8b 5d 88          	mov    -0x78(%rbp),%rbx
    8597:	48 89 48 50          	mov    %rcx,0x50(%rax)
    859b:	48 89 58 58          	mov    %rbx,0x58(%rax)
    859f:	48 8b 4d 90          	mov    -0x70(%rbp),%rcx
    85a3:	48 8b 5d 98          	mov    -0x68(%rbp),%rbx
    85a7:	48 89 48 60          	mov    %rcx,0x60(%rax)
    85ab:	48 89 58 68          	mov    %rbx,0x68(%rax)
    85af:	48 8b 4d a0          	mov    -0x60(%rbp),%rcx
    85b3:	48 8b 5d a8          	mov    -0x58(%rbp),%rbx
    85b7:	48 89 48 70          	mov    %rcx,0x70(%rax)
    85bb:	48 89 58 78          	mov    %rbx,0x78(%rax)
    85bf:	48 8b 4d b0          	mov    -0x50(%rbp),%rcx
    85c3:	48 8b 5d b8          	mov    -0x48(%rbp),%rbx
    85c7:	48 89 88 80 00 00 00 	mov    %rcx,0x80(%rax)
    85ce:	48 89 98 88 00 00 00 	mov    %rbx,0x88(%rax)
    85d5:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
    85d9:	48 8b 5d c8          	mov    -0x38(%rbp),%rbx
    85dd:	48 89 88 90 00 00 00 	mov    %rcx,0x90(%rax)
    85e4:	48 89 98 98 00 00 00 	mov    %rbx,0x98(%rax)
    85eb:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    85ef:	48 8b 5d d8          	mov    -0x28(%rbp),%rbx
    85f3:	48 89 88 a0 00 00 00 	mov    %rcx,0xa0(%rax)
    85fa:	48 89 98 a8 00 00 00 	mov    %rbx,0xa8(%rax)
    8601:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    8605:	48 89 90 b0 00 00 00 	mov    %rdx,0xb0(%rax)
    860c:	8b 45 e0             	mov    -0x20(%rbp),%eax
    860f:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    8613:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
    861a:	00 00 
    861c:	74 05                	je     8623 <builderRun+0x4cb>
    861e:	e8 5d 8a ff ff       	call   1080 <__stack_chk_fail@plt>
    8623:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
    8627:	c9                   	leave
    8628:	c3                   	ret

0000000000008629 <readAll>:
    8629:	55                   	push   %rbp
    862a:	48 89 e5             	mov    %rsp,%rbp
    862d:	48 83 ec 30          	sub    $0x30,%rsp
    8631:	89 7d ec             	mov    %edi,-0x14(%rbp)
    8634:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    8638:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    863c:	48 c7 45 f8 00 00 00 	movq   $0x0,-0x8(%rbp)
    8643:	00 
    8644:	eb 36                	jmp    867c <readAll+0x53>
    8646:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    864a:	48 2b 45 f8          	sub    -0x8(%rbp),%rax
    864e:	48 8d 50 ff          	lea    -0x1(%rax),%rdx
    8652:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
    8656:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    865a:	48 01 c1             	add    %rax,%rcx
    865d:	8b 45 ec             	mov    -0x14(%rbp),%eax
    8660:	48 89 ce             	mov    %rcx,%rsi
    8663:	89 c7                	mov    %eax,%edi
    8665:	e8 46 8a ff ff       	call   10b0 <read@plt>
    866a:	89 45 f4             	mov    %eax,-0xc(%rbp)
    866d:	83 7d f4 00          	cmpl   $0x0,-0xc(%rbp)
    8671:	7e 19                	jle    868c <readAll+0x63>
    8673:	8b 45 f4             	mov    -0xc(%rbp),%eax
    8676:	48 98                	cltq
    8678:	48 01 45 f8          	add    %rax,-0x8(%rbp)
    867c:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    8680:	48 83 c0 01          	add    $0x1,%rax
    8684:	48 3b 45 d8          	cmp    -0x28(%rbp),%rax
    8688:	72 bc                	jb     8646 <readAll+0x1d>
    868a:	eb 01                	jmp    868d <readAll+0x64>
    868c:	90                   	nop
    868d:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    8691:	c9                   	leave
    8692:	c3                   	ret

0000000000008693 <readCmdline>:
    8693:	55                   	push   %rbp
    8694:	48 89 e5             	mov    %rsp,%rbp
    8697:	48 83 ec 20          	sub    $0x20,%rsp
    869b:	bf 00 20 00 00       	mov    $0x2000,%edi
    86a0:	e8 3b 8a ff ff       	call   10e0 <malloc@plt>
    86a5:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    86a9:	48 83 7d f0 00       	cmpq   $0x0,-0x10(%rbp)
    86ae:	75 11                	jne    86c1 <readCmdline+0x2e>
    86b0:	be 00 00 00 00       	mov    $0x0,%esi
    86b5:	bf 00 00 00 00       	mov    $0x0,%edi
    86ba:	e8 c3 8d ff ff       	call   1482 <Slice_from>
    86bf:	eb 6a                	jmp    872b <readCmdline+0x98>
    86c1:	48 8d 05 a6 1f 00 00 	lea    0x1fa6(%rip),%rax        # a66e <_IO_stdin_used+0x66e>
    86c8:	ba 00 00 00 00       	mov    $0x0,%edx
    86cd:	be 00 00 00 00       	mov    $0x0,%esi
    86d2:	48 89 c7             	mov    %rax,%rdi
    86d5:	e8 26 8a ff ff       	call   1100 <open@plt>
    86da:	89 45 ec             	mov    %eax,-0x14(%rbp)
    86dd:	83 7d ec 00          	cmpl   $0x0,-0x14(%rbp)
    86e1:	79 11                	jns    86f4 <readCmdline+0x61>
    86e3:	be 00 00 00 00       	mov    $0x0,%esi
    86e8:	bf 00 00 00 00       	mov    $0x0,%edi
    86ed:	e8 90 8d ff ff       	call   1482 <Slice_from>
    86f2:	eb 37                	jmp    872b <readCmdline+0x98>
    86f4:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
    86f8:	8b 45 ec             	mov    -0x14(%rbp),%eax
    86fb:	ba 00 20 00 00       	mov    $0x2000,%edx
    8700:	48 89 ce             	mov    %rcx,%rsi
    8703:	89 c7                	mov    %eax,%edi
    8705:	e8 1f ff ff ff       	call   8629 <readAll>
    870a:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    870e:	8b 45 ec             	mov    -0x14(%rbp),%eax
    8711:	89 c7                	mov    %eax,%edi
    8713:	e8 88 89 ff ff       	call   10a0 <close@plt>
    8718:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
    871c:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    8720:	48 89 d6             	mov    %rdx,%rsi
    8723:	48 89 c7             	mov    %rax,%rdi
    8726:	e8 57 8d ff ff       	call   1482 <Slice_from>
    872b:	c9                   	leave
    872c:	c3                   	ret

000000000000872d <readFile>:
    872d:	55                   	push   %rbp
    872e:	48 89 e5             	mov    %rsp,%rbp
    8731:	48 83 ec 30          	sub    $0x30,%rsp
    8735:	48 89 7d d8          	mov    %rdi,-0x28(%rbp)
    8739:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
    873d:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    8741:	48 c7 00 00 00 00 00 	movq   $0x0,(%rax)
    8748:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    874c:	ba 00 00 00 00       	mov    $0x0,%edx
    8751:	be 00 00 00 00       	mov    $0x0,%esi
    8756:	48 89 c7             	mov    %rax,%rdi
    8759:	e8 a2 89 ff ff       	call   1100 <open@plt>
    875e:	89 45 e0             	mov    %eax,-0x20(%rbp)
    8761:	83 7d e0 00          	cmpl   $0x0,-0x20(%rbp)
    8765:	79 14                	jns    877b <readFile+0x4e>
    8767:	be 00 00 00 00       	mov    $0x0,%esi
    876c:	bf 00 00 00 00       	mov    $0x0,%edi
    8771:	e8 0c 8d ff ff       	call   1482 <Slice_from>
    8776:	e9 c5 00 00 00       	jmp    8840 <readFile+0x113>
    877b:	48 c7 45 f0 00 00 01 	movq   $0x10000,-0x10(%rbp)
    8782:	00 
    8783:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    8787:	48 89 c7             	mov    %rax,%rdi
    878a:	e8 51 89 ff ff       	call   10e0 <malloc@plt>
    878f:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    8793:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    8798:	75 1e                	jne    87b8 <readFile+0x8b>
    879a:	8b 45 e0             	mov    -0x20(%rbp),%eax
    879d:	89 c7                	mov    %eax,%edi
    879f:	e8 fc 88 ff ff       	call   10a0 <close@plt>
    87a4:	be 00 00 00 00       	mov    $0x0,%esi
    87a9:	bf 00 00 00 00       	mov    $0x0,%edi
    87ae:	e8 cf 8c ff ff       	call   1482 <Slice_from>
    87b3:	e9 88 00 00 00       	jmp    8840 <readFile+0x113>
    87b8:	48 c7 45 e8 00 00 00 	movq   $0x0,-0x18(%rbp)
    87bf:	00 
    87c0:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    87c4:	48 83 c0 01          	add    $0x1,%rax
    87c8:	48 3b 45 f0          	cmp    -0x10(%rbp),%rax
    87cc:	73 38                	jae    8806 <readFile+0xd9>
    87ce:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    87d2:	48 2b 45 e8          	sub    -0x18(%rbp),%rax
    87d6:	48 8d 50 ff          	lea    -0x1(%rax),%rdx
    87da:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
    87de:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    87e2:	48 01 c1             	add    %rax,%rcx
    87e5:	8b 45 e0             	mov    -0x20(%rbp),%eax
    87e8:	48 89 ce             	mov    %rcx,%rsi
    87eb:	89 c7                	mov    %eax,%edi
    87ed:	e8 be 88 ff ff       	call   10b0 <read@plt>
    87f2:	89 45 e4             	mov    %eax,-0x1c(%rbp)
    87f5:	83 7d e4 00          	cmpl   $0x0,-0x1c(%rbp)
    87f9:	7e 0e                	jle    8809 <readFile+0xdc>
    87fb:	8b 45 e4             	mov    -0x1c(%rbp),%eax
    87fe:	48 98                	cltq
    8800:	48 01 45 e8          	add    %rax,-0x18(%rbp)
    8804:	eb ba                	jmp    87c0 <readFile+0x93>
    8806:	90                   	nop
    8807:	eb 01                	jmp    880a <readFile+0xdd>
    8809:	90                   	nop
    880a:	8b 45 e0             	mov    -0x20(%rbp),%eax
    880d:	89 c7                	mov    %eax,%edi
    880f:	e8 8c 88 ff ff       	call   10a0 <close@plt>
    8814:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
    8818:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    881c:	48 01 d0             	add    %rdx,%rax
    881f:	c6 00 00             	movb   $0x0,(%rax)
    8822:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    8826:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    882a:	48 89 10             	mov    %rdx,(%rax)
    882d:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    8831:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    8835:	48 89 d6             	mov    %rdx,%rsi
    8838:	48 89 c7             	mov    %rax,%rdi
    883b:	e8 42 8c ff ff       	call   1482 <Slice_from>
    8840:	c9                   	leave
    8841:	c3                   	ret

0000000000008842 <sliceCStr>:
    8842:	55                   	push   %rbp
    8843:	48 89 e5             	mov    %rsp,%rbp
    8846:	48 83 ec 20          	sub    $0x20,%rsp
    884a:	48 89 f8             	mov    %rdi,%rax
    884d:	48 89 f1             	mov    %rsi,%rcx
    8850:	48 89 c0             	mov    %rax,%rax
    8853:	ba 00 00 00 00       	mov    $0x0,%edx
    8858:	48 89 ca             	mov    %rcx,%rdx
    885b:	48 89 45 e0          	mov    %rax,-0x20(%rbp)
    885f:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
    8863:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    8867:	48 83 c0 01          	add    $0x1,%rax
    886b:	48 89 c7             	mov    %rax,%rdi
    886e:	e8 6d 88 ff ff       	call   10e0 <malloc@plt>
    8873:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    8877:	48 83 7d f8 00       	cmpq   $0x0,-0x8(%rbp)
    887c:	75 07                	jne    8885 <sliceCStr+0x43>
    887e:	b8 00 00 00 00       	mov    $0x0,%eax
    8883:	eb 46                	jmp    88cb <sliceCStr+0x89>
    8885:	48 c7 45 f0 00 00 00 	movq   $0x0,-0x10(%rbp)
    888c:	00 
    888d:	eb 20                	jmp    88af <sliceCStr+0x6d>
    888f:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    8893:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    8897:	48 01 d0             	add    %rdx,%rax
    889a:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
    889e:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
    88a2:	48 01 ca             	add    %rcx,%rdx
    88a5:	0f b6 00             	movzbl (%rax),%eax
    88a8:	88 02                	mov    %al,(%rdx)
    88aa:	48 83 45 f0 01       	addq   $0x1,-0x10(%rbp)
    88af:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    88b3:	48 39 45 f0          	cmp    %rax,-0x10(%rbp)
    88b7:	72 d6                	jb     888f <sliceCStr+0x4d>
    88b9:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    88bd:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    88c1:	48 01 d0             	add    %rdx,%rax
    88c4:	c6 00 00             	movb   $0x0,(%rax)
    88c7:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    88cb:	c9                   	leave
    88cc:	c3                   	ret

00000000000088cd <aEq>:
    88cd:	55                   	push   %rbp
    88ce:	48 89 e5             	mov    %rsp,%rbp
    88d1:	48 89 f8             	mov    %rdi,%rax
    88d4:	49 89 f0             	mov    %rsi,%r8
    88d7:	48 89 c6             	mov    %rax,%rsi
    88da:	bf 00 00 00 00       	mov    $0x0,%edi
    88df:	4c 89 c7             	mov    %r8,%rdi
    88e2:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    88e6:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    88ea:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    88ee:	48 89 4d d0          	mov    %rcx,-0x30(%rbp)
    88f2:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    88f6:	48 39 45 d0          	cmp    %rax,-0x30(%rbp)
    88fa:	74 07                	je     8903 <aEq+0x36>
    88fc:	b8 00 00 00 00       	mov    $0x0,%eax
    8901:	eb 45                	jmp    8948 <aEq+0x7b>
    8903:	48 c7 45 f8 00 00 00 	movq   $0x0,-0x8(%rbp)
    890a:	00 
    890b:	eb 2c                	jmp    8939 <aEq+0x6c>
    890d:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    8911:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    8915:	48 01 d0             	add    %rdx,%rax
    8918:	0f b6 10             	movzbl (%rax),%edx
    891b:	48 8b 4d d8          	mov    -0x28(%rbp),%rcx
    891f:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    8923:	48 01 c8             	add    %rcx,%rax
    8926:	0f b6 00             	movzbl (%rax),%eax
    8929:	38 c2                	cmp    %al,%dl
    892b:	74 07                	je     8934 <aEq+0x67>
    892d:	b8 00 00 00 00       	mov    $0x0,%eax
    8932:	eb 14                	jmp    8948 <aEq+0x7b>
    8934:	48 83 45 f8 01       	addq   $0x1,-0x8(%rbp)
    8939:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    893d:	48 3b 45 d0          	cmp    -0x30(%rbp),%rax
    8941:	72 ca                	jb     890d <aEq+0x40>
    8943:	b8 01 00 00 00       	mov    $0x1,%eax
    8948:	5d                   	pop    %rbp
    8949:	c3                   	ret

000000000000894a <nextArg>:
    894a:	55                   	push   %rbp
    894b:	48 89 e5             	mov    %rsp,%rbp
    894e:	48 83 ec 30          	sub    $0x30,%rsp
    8952:	48 89 f8             	mov    %rdi,%rax
    8955:	49 89 f0             	mov    %rsi,%r8
    8958:	48 89 c6             	mov    %rax,%rsi
    895b:	bf 00 00 00 00       	mov    $0x0,%edi
    8960:	4c 89 c7             	mov    %r8,%rdi
    8963:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
    8967:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
    896b:	48 89 55 d8          	mov    %rdx,-0x28(%rbp)
    896f:	48 89 4d d0          	mov    %rcx,-0x30(%rbp)
    8973:	eb 05                	jmp    897a <nextArg+0x30>
    8975:	48 83 45 d8 01       	addq   $0x1,-0x28(%rbp)
    897a:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    897e:	48 39 45 d8          	cmp    %rax,-0x28(%rbp)
    8982:	73 12                	jae    8996 <nextArg+0x4c>
    8984:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    8988:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    898c:	48 01 d0             	add    %rdx,%rax
    898f:	0f b6 00             	movzbl (%rax),%eax
    8992:	84 c0                	test   %al,%al
    8994:	74 df                	je     8975 <nextArg+0x2b>
    8996:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    899a:	48 39 45 d8          	cmp    %rax,-0x28(%rbp)
    899e:	72 20                	jb     89c0 <nextArg+0x76>
    89a0:	be 00 00 00 00       	mov    $0x0,%esi
    89a5:	bf 00 00 00 00       	mov    $0x0,%edi
    89aa:	e8 d3 8a ff ff       	call   1482 <Slice_from>
    89af:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    89b3:	48 89 01             	mov    %rax,(%rcx)
    89b6:	48 89 51 08          	mov    %rdx,0x8(%rcx)
    89ba:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    89be:	eb 58                	jmp    8a18 <nextArg+0xce>
    89c0:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    89c4:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    89c8:	eb 05                	jmp    89cf <nextArg+0x85>
    89ca:	48 83 45 d8 01       	addq   $0x1,-0x28(%rbp)
    89cf:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    89d3:	48 39 45 d8          	cmp    %rax,-0x28(%rbp)
    89d7:	73 12                	jae    89eb <nextArg+0xa1>
    89d9:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
    89dd:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    89e1:	48 01 d0             	add    %rdx,%rax
    89e4:	0f b6 00             	movzbl (%rax),%eax
    89e7:	84 c0                	test   %al,%al
    89e9:	75 df                	jne    89ca <nextArg+0x80>
    89eb:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    89ef:	48 2b 45 f8          	sub    -0x8(%rbp),%rax
    89f3:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
    89f7:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
    89fb:	48 01 ca             	add    %rcx,%rdx
    89fe:	48 89 c6             	mov    %rax,%rsi
    8a01:	48 89 d7             	mov    %rdx,%rdi
    8a04:	e8 79 8a ff ff       	call   1482 <Slice_from>
    8a09:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
    8a0d:	48 89 01             	mov    %rax,(%rcx)
    8a10:	48 89 51 08          	mov    %rdx,0x8(%rcx)
    8a14:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    8a18:	c9                   	leave
    8a19:	c3                   	ret

0000000000008a1a <classifyFlag>:
    8a1a:	55                   	push   %rbp
    8a1b:	48 89 e5             	mov    %rsp,%rbp
    8a1e:	48 83 ec 10          	sub    $0x10,%rsp
    8a22:	48 89 f8             	mov    %rdi,%rax
    8a25:	48 89 f1             	mov    %rsi,%rcx
    8a28:	48 89 c0             	mov    %rax,%rax
    8a2b:	ba 00 00 00 00       	mov    $0x0,%edx
    8a30:	48 89 ca             	mov    %rcx,%rdx
    8a33:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    8a37:	48 89 55 f8          	mov    %rdx,-0x8(%rbp)
    8a3b:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    8a3f:	48 83 f8 0a          	cmp    $0xa,%rax
    8a43:	0f 84 6b 01 00 00    	je     8bb4 <classifyFlag+0x19a>
    8a49:	48 83 f8 0a          	cmp    $0xa,%rax
    8a4d:	0f 87 8b 01 00 00    	ja     8bde <classifyFlag+0x1c4>
    8a53:	48 83 f8 09          	cmp    $0x9,%rax
    8a57:	0f 84 2d 01 00 00    	je     8b8a <classifyFlag+0x170>
    8a5d:	48 83 f8 09          	cmp    $0x9,%rax
    8a61:	0f 87 77 01 00 00    	ja     8bde <classifyFlag+0x1c4>
    8a67:	48 83 f8 08          	cmp    $0x8,%rax
    8a6b:	0f 84 ef 00 00 00    	je     8b60 <classifyFlag+0x146>
    8a71:	48 83 f8 08          	cmp    $0x8,%rax
    8a75:	0f 87 63 01 00 00    	ja     8bde <classifyFlag+0x1c4>
    8a7b:	48 83 f8 07          	cmp    $0x7,%rax
    8a7f:	0f 84 aa 00 00 00    	je     8b2f <classifyFlag+0x115>
    8a85:	48 83 f8 07          	cmp    $0x7,%rax
    8a89:	0f 87 4f 01 00 00    	ja     8bde <classifyFlag+0x1c4>
    8a8f:	48 83 f8 02          	cmp    $0x2,%rax
    8a93:	74 0b                	je     8aa0 <classifyFlag+0x86>
    8a95:	48 83 f8 06          	cmp    $0x6,%rax
    8a99:	74 63                	je     8afe <classifyFlag+0xe4>
    8a9b:	e9 3e 01 00 00       	jmp    8bde <classifyFlag+0x1c4>
    8aa0:	48 8d 15 da 1b 00 00 	lea    0x1bda(%rip),%rdx        # a681 <_IO_stdin_used+0x681>
    8aa7:	48 8b 75 f0          	mov    -0x10(%rbp),%rsi
    8aab:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    8aaf:	b9 02 00 00 00       	mov    $0x2,%ecx
    8ab4:	48 89 f7             	mov    %rsi,%rdi
    8ab7:	48 89 c6             	mov    %rax,%rsi
    8aba:	e8 0e fe ff ff       	call   88cd <aEq>
    8abf:	84 c0                	test   %al,%al
    8ac1:	74 0a                	je     8acd <classifyFlag+0xb3>
    8ac3:	b8 00 00 00 00       	mov    $0x0,%eax
    8ac8:	e9 29 01 00 00       	jmp    8bf6 <classifyFlag+0x1dc>
    8acd:	48 8d 15 b0 1b 00 00 	lea    0x1bb0(%rip),%rdx        # a684 <_IO_stdin_used+0x684>
    8ad4:	48 8b 75 f0          	mov    -0x10(%rbp),%rsi
    8ad8:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    8adc:	b9 02 00 00 00       	mov    $0x2,%ecx
    8ae1:	48 89 f7             	mov    %rsi,%rdi
    8ae4:	48 89 c6             	mov    %rax,%rsi
    8ae7:	e8 e1 fd ff ff       	call   88cd <aEq>
    8aec:	84 c0                	test   %al,%al
    8aee:	0f 84 ed 00 00 00    	je     8be1 <classifyFlag+0x1c7>
    8af4:	b8 05 00 00 00       	mov    $0x5,%eax
    8af9:	e9 f8 00 00 00       	jmp    8bf6 <classifyFlag+0x1dc>
    8afe:	48 8d 15 82 1b 00 00 	lea    0x1b82(%rip),%rdx        # a687 <_IO_stdin_used+0x687>
    8b05:	48 8b 75 f0          	mov    -0x10(%rbp),%rsi
    8b09:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    8b0d:	b9 06 00 00 00       	mov    $0x6,%ecx
    8b12:	48 89 f7             	mov    %rsi,%rdi
    8b15:	48 89 c6             	mov    %rax,%rsi
    8b18:	e8 b0 fd ff ff       	call   88cd <aEq>
    8b1d:	84 c0                	test   %al,%al
    8b1f:	0f 84 bf 00 00 00    	je     8be4 <classifyFlag+0x1ca>
    8b25:	b8 00 00 00 00       	mov    $0x0,%eax
    8b2a:	e9 c7 00 00 00       	jmp    8bf6 <classifyFlag+0x1dc>
    8b2f:	48 8d 15 58 1b 00 00 	lea    0x1b58(%rip),%rdx        # a68e <_IO_stdin_used+0x68e>
    8b36:	48 8b 75 f0          	mov    -0x10(%rbp),%rsi
    8b3a:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    8b3e:	b9 07 00 00 00       	mov    $0x7,%ecx
    8b43:	48 89 f7             	mov    %rsi,%rdi
    8b46:	48 89 c6             	mov    %rax,%rsi
    8b49:	e8 7f fd ff ff       	call   88cd <aEq>
    8b4e:	84 c0                	test   %al,%al
    8b50:	0f 84 91 00 00 00    	je     8be7 <classifyFlag+0x1cd>
    8b56:	b8 01 00 00 00       	mov    $0x1,%eax
    8b5b:	e9 96 00 00 00       	jmp    8bf6 <classifyFlag+0x1dc>
    8b60:	48 8d 15 2f 1b 00 00 	lea    0x1b2f(%rip),%rdx        # a696 <_IO_stdin_used+0x696>
    8b67:	48 8b 75 f0          	mov    -0x10(%rbp),%rsi
    8b6b:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    8b6f:	b9 08 00 00 00       	mov    $0x8,%ecx
    8b74:	48 89 f7             	mov    %rsi,%rdi
    8b77:	48 89 c6             	mov    %rax,%rsi
    8b7a:	e8 4e fd ff ff       	call   88cd <aEq>
    8b7f:	84 c0                	test   %al,%al
    8b81:	74 67                	je     8bea <classifyFlag+0x1d0>
    8b83:	b8 04 00 00 00       	mov    $0x4,%eax
    8b88:	eb 6c                	jmp    8bf6 <classifyFlag+0x1dc>
    8b8a:	48 8d 15 0e 1b 00 00 	lea    0x1b0e(%rip),%rdx        # a69f <_IO_stdin_used+0x69f>
    8b91:	48 8b 75 f0          	mov    -0x10(%rbp),%rsi
    8b95:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    8b99:	b9 09 00 00 00       	mov    $0x9,%ecx
    8b9e:	48 89 f7             	mov    %rsi,%rdi
    8ba1:	48 89 c6             	mov    %rax,%rsi
    8ba4:	e8 24 fd ff ff       	call   88cd <aEq>
    8ba9:	84 c0                	test   %al,%al
    8bab:	74 40                	je     8bed <classifyFlag+0x1d3>
    8bad:	b8 02 00 00 00       	mov    $0x2,%eax
    8bb2:	eb 42                	jmp    8bf6 <classifyFlag+0x1dc>
    8bb4:	48 8d 15 ee 1a 00 00 	lea    0x1aee(%rip),%rdx        # a6a9 <_IO_stdin_used+0x6a9>
    8bbb:	48 8b 75 f0          	mov    -0x10(%rbp),%rsi
    8bbf:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    8bc3:	b9 0a 00 00 00       	mov    $0xa,%ecx
    8bc8:	48 89 f7             	mov    %rsi,%rdi
    8bcb:	48 89 c6             	mov    %rax,%rsi
    8bce:	e8 fa fc ff ff       	call   88cd <aEq>
    8bd3:	84 c0                	test   %al,%al
    8bd5:	74 19                	je     8bf0 <classifyFlag+0x1d6>
    8bd7:	b8 03 00 00 00       	mov    $0x3,%eax
    8bdc:	eb 18                	jmp    8bf6 <classifyFlag+0x1dc>
    8bde:	90                   	nop
    8bdf:	eb 10                	jmp    8bf1 <classifyFlag+0x1d7>
    8be1:	90                   	nop
    8be2:	eb 0d                	jmp    8bf1 <classifyFlag+0x1d7>
    8be4:	90                   	nop
    8be5:	eb 0a                	jmp    8bf1 <classifyFlag+0x1d7>
    8be7:	90                   	nop
    8be8:	eb 07                	jmp    8bf1 <classifyFlag+0x1d7>
    8bea:	90                   	nop
    8beb:	eb 04                	jmp    8bf1 <classifyFlag+0x1d7>
    8bed:	90                   	nop
    8bee:	eb 01                	jmp    8bf1 <classifyFlag+0x1d7>
    8bf0:	90                   	nop
    8bf1:	b8 06 00 00 00       	mov    $0x6,%eax
    8bf6:	c9                   	leave
    8bf7:	c3                   	ret

0000000000008bf8 <usage>:
    8bf8:	55                   	push   %rbp
    8bf9:	48 89 e5             	mov    %rsp,%rbp
    8bfc:	48 8d 05 b1 1a 00 00 	lea    0x1ab1(%rip),%rax        # a6b4 <_IO_stdin_used+0x6b4>
    8c03:	48 89 c7             	mov    %rax,%rdi
    8c06:	e8 45 84 ff ff       	call   1050 <puts@plt>
    8c0b:	48 8d 05 bc 1a 00 00 	lea    0x1abc(%rip),%rax        # a6ce <_IO_stdin_used+0x6ce>
    8c12:	48 89 c7             	mov    %rax,%rdi
    8c15:	e8 36 84 ff ff       	call   1050 <puts@plt>
    8c1a:	48 8d 05 b7 1a 00 00 	lea    0x1ab7(%rip),%rax        # a6d8 <_IO_stdin_used+0x6d8>
    8c21:	48 89 c7             	mov    %rax,%rdi
    8c24:	e8 27 84 ff ff       	call   1050 <puts@plt>
    8c29:	48 8d 05 d0 1a 00 00 	lea    0x1ad0(%rip),%rax        # a700 <_IO_stdin_used+0x700>
    8c30:	48 89 c7             	mov    %rax,%rdi
    8c33:	e8 18 84 ff ff       	call   1050 <puts@plt>
    8c38:	48 8d 05 01 1b 00 00 	lea    0x1b01(%rip),%rax        # a740 <_IO_stdin_used+0x740>
    8c3f:	48 89 c7             	mov    %rax,%rdi
    8c42:	e8 09 84 ff ff       	call   1050 <puts@plt>
    8c47:	48 8d 05 1a 1b 00 00 	lea    0x1b1a(%rip),%rax        # a768 <_IO_stdin_used+0x768>
    8c4e:	48 89 c7             	mov    %rax,%rdi
    8c51:	e8 fa 83 ff ff       	call   1050 <puts@plt>
    8c56:	48 8d 05 30 1b 00 00 	lea    0x1b30(%rip),%rax        # a78d <_IO_stdin_used+0x78d>
    8c5d:	48 89 c7             	mov    %rax,%rdi
    8c60:	e8 eb 83 ff ff       	call   1050 <puts@plt>
    8c65:	48 8d 05 2c 1b 00 00 	lea    0x1b2c(%rip),%rax        # a798 <_IO_stdin_used+0x798>
    8c6c:	48 89 c7             	mov    %rax,%rdi
    8c6f:	e8 dc 83 ff ff       	call   1050 <puts@plt>
    8c74:	48 8d 05 4d 1b 00 00 	lea    0x1b4d(%rip),%rax        # a7c8 <_IO_stdin_used+0x7c8>
    8c7b:	48 89 c7             	mov    %rax,%rdi
    8c7e:	e8 cd 83 ff ff       	call   1050 <puts@plt>
    8c83:	48 8d 05 66 1b 00 00 	lea    0x1b66(%rip),%rax        # a7f0 <_IO_stdin_used+0x7f0>
    8c8a:	48 89 c7             	mov    %rax,%rdi
    8c8d:	e8 be 83 ff ff       	call   1050 <puts@plt>
    8c92:	48 8d 05 7f 1b 00 00 	lea    0x1b7f(%rip),%rax        # a818 <_IO_stdin_used+0x818>
    8c99:	48 89 c7             	mov    %rax,%rdi
    8c9c:	e8 af 83 ff ff       	call   1050 <puts@plt>
    8ca1:	48 8d 05 a8 1b 00 00 	lea    0x1ba8(%rip),%rax        # a850 <_IO_stdin_used+0x850>
    8ca8:	48 89 c7             	mov    %rax,%rdi
    8cab:	e8 a0 83 ff ff       	call   1050 <puts@plt>
    8cb0:	48 8d 05 d1 1b 00 00 	lea    0x1bd1(%rip),%rax        # a888 <_IO_stdin_used+0x888>
    8cb7:	48 89 c7             	mov    %rax,%rdi
    8cba:	e8 91 83 ff ff       	call   1050 <puts@plt>
    8cbf:	90                   	nop
    8cc0:	5d                   	pop    %rbp
    8cc1:	c3                   	ret

0000000000008cc2 <parseArgs>:
    8cc2:	55                   	push   %rbp
    8cc3:	48 89 e5             	mov    %rsp,%rbp
    8cc6:	53                   	push   %rbx
    8cc7:	48 83 ec 68          	sub    $0x68,%rsp
    8ccb:	48 89 7d 98          	mov    %rdi,-0x68(%rbp)
    8ccf:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    8cd6:	00 00 
    8cd8:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    8cdc:	31 c0                	xor    %eax,%eax
    8cde:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    8ce2:	c7 00 00 00 00 00    	movl   $0x0,(%rax)
    8ce8:	48 8b 5d 98          	mov    -0x68(%rbp),%rbx
    8cec:	48 8d 05 b4 1b 00 00 	lea    0x1bb4(%rip),%rax        # a8a7 <_IO_stdin_used+0x8a7>
    8cf3:	be 0a 00 00 00       	mov    $0xa,%esi
    8cf8:	48 89 c7             	mov    %rax,%rdi
    8cfb:	e8 82 87 ff ff       	call   1482 <Slice_from>
    8d00:	48 89 43 08          	mov    %rax,0x8(%rbx)
    8d04:	48 89 53 10          	mov    %rdx,0x10(%rbx)
    8d08:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    8d0c:	c6 40 18 00          	movb   $0x0,0x18(%rax)
    8d10:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    8d14:	c6 40 19 00          	movb   $0x0,0x19(%rax)
    8d18:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    8d1c:	c6 40 1a 00          	movb   $0x0,0x1a(%rax)
    8d20:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    8d24:	c6 40 1b 00          	movb   $0x0,0x1b(%rax)
    8d28:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    8d2c:	c6 40 1c 00          	movb   $0x0,0x1c(%rax)
    8d30:	e8 5e f9 ff ff       	call   8693 <readCmdline>
    8d35:	48 89 45 b0          	mov    %rax,-0x50(%rbp)
    8d39:	48 89 55 b8          	mov    %rdx,-0x48(%rbp)
    8d3d:	48 8b 45 b0          	mov    -0x50(%rbp),%rax
    8d41:	48 85 c0             	test   %rax,%rax
    8d44:	75 0a                	jne    8d50 <parseArgs+0x8e>
    8d46:	b8 00 00 00 00       	mov    $0x0,%eax
    8d4b:	e9 66 03 00 00       	jmp    90b6 <parseArgs+0x3f4>
    8d50:	48 c7 45 a8 00 00 00 	movq   $0x0,-0x58(%rbp)
    8d57:	00 
    8d58:	48 8d 4d c0          	lea    -0x40(%rbp),%rcx
    8d5c:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
    8d60:	48 8b 75 b0          	mov    -0x50(%rbp),%rsi
    8d64:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    8d68:	48 89 f7             	mov    %rsi,%rdi
    8d6b:	48 89 c6             	mov    %rax,%rsi
    8d6e:	e8 d7 fb ff ff       	call   894a <nextArg>
    8d73:	48 89 45 a8          	mov    %rax,-0x58(%rbp)
    8d77:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    8d7b:	48 85 c0             	test   %rax,%rax
    8d7e:	75 0a                	jne    8d8a <parseArgs+0xc8>
    8d80:	b8 00 00 00 00       	mov    $0x0,%eax
    8d85:	e9 2c 03 00 00       	jmp    90b6 <parseArgs+0x3f4>
    8d8a:	c6 45 a2 00          	movb   $0x0,-0x5e(%rbp)
    8d8e:	48 8d 4d c0          	lea    -0x40(%rbp),%rcx
    8d92:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
    8d96:	48 8b 75 b0          	mov    -0x50(%rbp),%rsi
    8d9a:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    8d9e:	48 89 f7             	mov    %rsi,%rdi
    8da1:	48 89 c6             	mov    %rax,%rsi
    8da4:	e8 a1 fb ff ff       	call   894a <nextArg>
    8da9:	48 89 45 a8          	mov    %rax,-0x58(%rbp)
    8dad:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    8db1:	48 85 c0             	test   %rax,%rax
    8db4:	0f 84 f6 02 00 00    	je     90b0 <parseArgs+0x3ee>
    8dba:	48 8b 55 c0          	mov    -0x40(%rbp),%rdx
    8dbe:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    8dc2:	48 89 d7             	mov    %rdx,%rdi
    8dc5:	48 89 c6             	mov    %rax,%rsi
    8dc8:	e8 4d fc ff ff       	call   8a1a <classifyFlag>
    8dcd:	89 45 a4             	mov    %eax,-0x5c(%rbp)
    8dd0:	83 7d a4 06          	cmpl   $0x6,-0x5c(%rbp)
    8dd4:	0f 84 09 01 00 00    	je     8ee3 <parseArgs+0x221>
    8dda:	83 7d a4 06          	cmpl   $0x6,-0x5c(%rbp)
    8dde:	0f 87 f5 00 00 00    	ja     8ed9 <parseArgs+0x217>
    8de4:	83 7d a4 05          	cmpl   $0x5,-0x5c(%rbp)
    8de8:	0f 84 91 00 00 00    	je     8e7f <parseArgs+0x1bd>
    8dee:	83 7d a4 05          	cmpl   $0x5,-0x5c(%rbp)
    8df2:	0f 87 e1 00 00 00    	ja     8ed9 <parseArgs+0x217>
    8df8:	83 7d a4 04          	cmpl   $0x4,-0x5c(%rbp)
    8dfc:	74 74                	je     8e72 <parseArgs+0x1b0>
    8dfe:	83 7d a4 04          	cmpl   $0x4,-0x5c(%rbp)
    8e02:	0f 87 d1 00 00 00    	ja     8ed9 <parseArgs+0x217>
    8e08:	83 7d a4 03          	cmpl   $0x3,-0x5c(%rbp)
    8e0c:	74 57                	je     8e65 <parseArgs+0x1a3>
    8e0e:	83 7d a4 03          	cmpl   $0x3,-0x5c(%rbp)
    8e12:	0f 87 c1 00 00 00    	ja     8ed9 <parseArgs+0x217>
    8e18:	83 7d a4 02          	cmpl   $0x2,-0x5c(%rbp)
    8e1c:	74 3a                	je     8e58 <parseArgs+0x196>
    8e1e:	83 7d a4 02          	cmpl   $0x2,-0x5c(%rbp)
    8e22:	0f 87 b1 00 00 00    	ja     8ed9 <parseArgs+0x217>
    8e28:	83 7d a4 00          	cmpl   $0x0,-0x5c(%rbp)
    8e2c:	74 0b                	je     8e39 <parseArgs+0x177>
    8e2e:	83 7d a4 01          	cmpl   $0x1,-0x5c(%rbp)
    8e32:	74 17                	je     8e4b <parseArgs+0x189>
    8e34:	e9 a0 00 00 00       	jmp    8ed9 <parseArgs+0x217>
    8e39:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    8e3d:	c6 40 18 01          	movb   $0x1,0x18(%rax)
    8e41:	b8 01 00 00 00       	mov    $0x1,%eax
    8e46:	e9 6b 02 00 00       	jmp    90b6 <parseArgs+0x3f4>
    8e4b:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    8e4f:	c6 40 19 01          	movb   $0x1,0x19(%rax)
    8e53:	e9 53 02 00 00       	jmp    90ab <parseArgs+0x3e9>
    8e58:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    8e5c:	c6 40 1a 01          	movb   $0x1,0x1a(%rax)
    8e60:	e9 46 02 00 00       	jmp    90ab <parseArgs+0x3e9>
    8e65:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    8e69:	c6 40 1b 01          	movb   $0x1,0x1b(%rax)
    8e6d:	e9 39 02 00 00       	jmp    90ab <parseArgs+0x3e9>
    8e72:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    8e76:	c6 40 1c 01          	movb   $0x1,0x1c(%rax)
    8e7a:	e9 2c 02 00 00       	jmp    90ab <parseArgs+0x3e9>
    8e7f:	48 8d 4d d0          	lea    -0x30(%rbp),%rcx
    8e83:	48 8b 55 a8          	mov    -0x58(%rbp),%rdx
    8e87:	48 8b 75 b0          	mov    -0x50(%rbp),%rsi
    8e8b:	48 8b 45 b8          	mov    -0x48(%rbp),%rax
    8e8f:	48 89 f7             	mov    %rsi,%rdi
    8e92:	48 89 c6             	mov    %rax,%rsi
    8e95:	e8 b0 fa ff ff       	call   894a <nextArg>
    8e9a:	48 89 45 a8          	mov    %rax,-0x58(%rbp)
    8e9e:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
    8ea2:	48 85 c0             	test   %rax,%rax
    8ea5:	75 19                	jne    8ec0 <parseArgs+0x1fe>
    8ea7:	48 8d 05 04 1a 00 00 	lea    0x1a04(%rip),%rax        # a8b2 <_IO_stdin_used+0x8b2>
    8eae:	48 89 c7             	mov    %rax,%rdi
    8eb1:	e8 9a 81 ff ff       	call   1050 <puts@plt>
    8eb6:	b8 00 00 00 00       	mov    $0x0,%eax
    8ebb:	e9 f6 01 00 00       	jmp    90b6 <parseArgs+0x3f4>
    8ec0:	48 8b 4d 98          	mov    -0x68(%rbp),%rcx
    8ec4:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    8ec8:	48 8b 55 d8          	mov    -0x28(%rbp),%rdx
    8ecc:	48 89 41 08          	mov    %rax,0x8(%rcx)
    8ed0:	48 89 51 10          	mov    %rdx,0x10(%rcx)
    8ed4:	e9 d2 01 00 00       	jmp    90ab <parseArgs+0x3e9>
    8ed9:	b8 00 00 00 00       	mov    $0x0,%eax
    8ede:	e9 d3 01 00 00       	jmp    90b6 <parseArgs+0x3f4>
    8ee3:	90                   	nop
    8ee4:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
    8ee8:	0f b6 00             	movzbl (%rax),%eax
    8eeb:	3c 2d                	cmp    $0x2d,%al
    8eed:	75 37                	jne    8f26 <parseArgs+0x264>
    8eef:	48 8b 55 c0          	mov    -0x40(%rbp),%rdx
    8ef3:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    8ef7:	48 89 d7             	mov    %rdx,%rdi
    8efa:	48 89 c6             	mov    %rax,%rsi
    8efd:	e8 40 f9 ff ff       	call   8842 <sliceCStr>
    8f02:	48 89 c2             	mov    %rax,%rdx
    8f05:	48 8d 05 c2 19 00 00 	lea    0x19c2(%rip),%rax        # a8ce <_IO_stdin_used+0x8ce>
    8f0c:	48 89 d6             	mov    %rdx,%rsi
    8f0f:	48 89 c7             	mov    %rax,%rdi
    8f12:	b8 00 00 00 00       	mov    $0x0,%eax
    8f17:	e8 74 81 ff ff       	call   1090 <printf@plt>
    8f1c:	b8 00 00 00 00       	mov    $0x0,%eax
    8f21:	e9 90 01 00 00       	jmp    90b6 <parseArgs+0x3f4>
    8f26:	80 7d a2 00          	cmpb   $0x0,-0x5e(%rbp)
    8f2a:	74 37                	je     8f63 <parseArgs+0x2a1>
    8f2c:	48 8b 55 c0          	mov    -0x40(%rbp),%rdx
    8f30:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    8f34:	48 89 d7             	mov    %rdx,%rdi
    8f37:	48 89 c6             	mov    %rax,%rsi
    8f3a:	e8 03 f9 ff ff       	call   8842 <sliceCStr>
    8f3f:	48 89 c2             	mov    %rax,%rdx
    8f42:	48 8d 05 9f 19 00 00 	lea    0x199f(%rip),%rax        # a8e8 <_IO_stdin_used+0x8e8>
    8f49:	48 89 d6             	mov    %rdx,%rsi
    8f4c:	48 89 c7             	mov    %rax,%rdi
    8f4f:	b8 00 00 00 00       	mov    $0x0,%eax
    8f54:	e8 37 81 ff ff       	call   1090 <printf@plt>
    8f59:	b8 00 00 00 00       	mov    $0x0,%eax
    8f5e:	e9 53 01 00 00       	jmp    90b6 <parseArgs+0x3f4>
    8f63:	c6 45 a2 01          	movb   $0x1,-0x5e(%rbp)
    8f67:	c6 45 a3 00          	movb   $0x0,-0x5d(%rbp)
    8f6b:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    8f6f:	48 83 f8 05          	cmp    $0x5,%rax
    8f73:	0f 84 b2 00 00 00    	je     902b <parseArgs+0x369>
    8f79:	48 83 f8 05          	cmp    $0x5,%rax
    8f7d:	0f 87 db 00 00 00    	ja     905e <parseArgs+0x39c>
    8f83:	48 83 f8 03          	cmp    $0x3,%rax
    8f87:	74 0b                	je     8f94 <parseArgs+0x2d2>
    8f89:	48 83 f8 04          	cmp    $0x4,%rax
    8f8d:	74 69                	je     8ff8 <parseArgs+0x336>
    8f8f:	e9 ca 00 00 00       	jmp    905e <parseArgs+0x39c>
    8f94:	48 8d 15 6d 19 00 00 	lea    0x196d(%rip),%rdx        # a908 <_IO_stdin_used+0x908>
    8f9b:	48 8b 75 c0          	mov    -0x40(%rbp),%rsi
    8f9f:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    8fa3:	b9 03 00 00 00       	mov    $0x3,%ecx
    8fa8:	48 89 f7             	mov    %rsi,%rdi
    8fab:	48 89 c6             	mov    %rax,%rsi
    8fae:	e8 1a f9 ff ff       	call   88cd <aEq>
    8fb3:	84 c0                	test   %al,%al
    8fb5:	74 0e                	je     8fc5 <parseArgs+0x303>
    8fb7:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    8fbb:	c7 00 01 00 00 00    	movl   $0x1,(%rax)
    8fc1:	c6 45 a3 01          	movb   $0x1,-0x5d(%rbp)
    8fc5:	48 8d 15 40 19 00 00 	lea    0x1940(%rip),%rdx        # a90c <_IO_stdin_used+0x90c>
    8fcc:	48 8b 75 c0          	mov    -0x40(%rbp),%rsi
    8fd0:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    8fd4:	b9 03 00 00 00       	mov    $0x3,%ecx
    8fd9:	48 89 f7             	mov    %rsi,%rdi
    8fdc:	48 89 c6             	mov    %rax,%rsi
    8fdf:	e8 e9 f8 ff ff       	call   88cd <aEq>
    8fe4:	84 c0                	test   %al,%al
    8fe6:	74 79                	je     9061 <parseArgs+0x39f>
    8fe8:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    8fec:	c7 00 03 00 00 00    	movl   $0x3,(%rax)
    8ff2:	c6 45 a3 01          	movb   $0x1,-0x5d(%rbp)
    8ff6:	eb 69                	jmp    9061 <parseArgs+0x39f>
    8ff8:	48 8d 15 11 19 00 00 	lea    0x1911(%rip),%rdx        # a910 <_IO_stdin_used+0x910>
    8fff:	48 8b 75 c0          	mov    -0x40(%rbp),%rsi
    9003:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    9007:	b9 04 00 00 00       	mov    $0x4,%ecx
    900c:	48 89 f7             	mov    %rsi,%rdi
    900f:	48 89 c6             	mov    %rax,%rsi
    9012:	e8 b6 f8 ff ff       	call   88cd <aEq>
    9017:	84 c0                	test   %al,%al
    9019:	74 49                	je     9064 <parseArgs+0x3a2>
    901b:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    901f:	c7 00 02 00 00 00    	movl   $0x2,(%rax)
    9025:	c6 45 a3 01          	movb   $0x1,-0x5d(%rbp)
    9029:	eb 39                	jmp    9064 <parseArgs+0x3a2>
    902b:	48 8d 15 f4 0f 00 00 	lea    0xff4(%rip),%rdx        # a026 <_IO_stdin_used+0x26>
    9032:	48 8b 75 c0          	mov    -0x40(%rbp),%rsi
    9036:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    903a:	b9 05 00 00 00       	mov    $0x5,%ecx
    903f:	48 89 f7             	mov    %rsi,%rdi
    9042:	48 89 c6             	mov    %rax,%rsi
    9045:	e8 83 f8 ff ff       	call   88cd <aEq>
    904a:	84 c0                	test   %al,%al
    904c:	74 19                	je     9067 <parseArgs+0x3a5>
    904e:	48 8b 45 98          	mov    -0x68(%rbp),%rax
    9052:	c7 00 00 00 00 00    	movl   $0x0,(%rax)
    9058:	c6 45 a3 01          	movb   $0x1,-0x5d(%rbp)
    905c:	eb 09                	jmp    9067 <parseArgs+0x3a5>
    905e:	90                   	nop
    905f:	eb 07                	jmp    9068 <parseArgs+0x3a6>
    9061:	90                   	nop
    9062:	eb 04                	jmp    9068 <parseArgs+0x3a6>
    9064:	90                   	nop
    9065:	eb 01                	jmp    9068 <parseArgs+0x3a6>
    9067:	90                   	nop
    9068:	0f b6 45 a3          	movzbl -0x5d(%rbp),%eax
    906c:	83 f0 01             	xor    $0x1,%eax
    906f:	84 c0                	test   %al,%al
    9071:	0f 84 17 fd ff ff    	je     8d8e <parseArgs+0xcc>
    9077:	48 8b 55 c0          	mov    -0x40(%rbp),%rdx
    907b:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
    907f:	48 89 d7             	mov    %rdx,%rdi
    9082:	48 89 c6             	mov    %rax,%rsi
    9085:	e8 b8 f7 ff ff       	call   8842 <sliceCStr>
    908a:	48 89 c2             	mov    %rax,%rdx
    908d:	48 8d 05 81 18 00 00 	lea    0x1881(%rip),%rax        # a915 <_IO_stdin_used+0x915>
    9094:	48 89 d6             	mov    %rdx,%rsi
    9097:	48 89 c7             	mov    %rax,%rdi
    909a:	b8 00 00 00 00       	mov    $0x0,%eax
    909f:	e8 ec 7f ff ff       	call   1090 <printf@plt>
    90a4:	b8 00 00 00 00       	mov    $0x0,%eax
    90a9:	eb 0b                	jmp    90b6 <parseArgs+0x3f4>
    90ab:	e9 de fc ff ff       	jmp    8d8e <parseArgs+0xcc>
    90b0:	90                   	nop
    90b1:	b8 01 00 00 00       	mov    $0x1,%eax
    90b6:	48 8b 55 e8          	mov    -0x18(%rbp),%rdx
    90ba:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
    90c1:	00 00 
    90c3:	74 05                	je     90ca <parseArgs+0x408>
    90c5:	e8 b6 7f ff ff       	call   1080 <__stack_chk_fail@plt>
    90ca:	48 8b 5d f8          	mov    -0x8(%rbp),%rbx
    90ce:	c9                   	leave
    90cf:	c3                   	ret

00000000000090d0 <main>:
    90d0:	55                   	push   %rbp
    90d1:	48 89 e5             	mov    %rsp,%rbp
    90d4:	48 81 ec f0 01 00 00 	sub    $0x1f0,%rsp
    90db:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    90e2:	00 00 
    90e4:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
    90e8:	31 c0                	xor    %eax,%eax
    90ea:	48 8d 85 50 fe ff ff 	lea    -0x1b0(%rbp),%rax
    90f1:	48 89 c7             	mov    %rax,%rdi
    90f4:	e8 c9 fb ff ff       	call   8cc2 <parseArgs>
    90f9:	83 f0 01             	xor    $0x1,%eax
    90fc:	84 c0                	test   %al,%al
    90fe:	74 0f                	je     910f <main+0x3f>
    9100:	e8 f3 fa ff ff       	call   8bf8 <usage>
    9105:	b8 02 00 00 00       	mov    $0x2,%eax
    910a:	e9 00 02 00 00       	jmp    930f <main+0x23f>
    910f:	0f b6 85 68 fe ff ff 	movzbl -0x198(%rbp),%eax
    9116:	84 c0                	test   %al,%al
    9118:	74 0f                	je     9129 <main+0x59>
    911a:	e8 d9 fa ff ff       	call   8bf8 <usage>
    911f:	b8 00 00 00 00       	mov    $0x0,%eax
    9124:	e9 e6 01 00 00       	jmp    930f <main+0x23f>
    9129:	8b 85 50 fe ff ff    	mov    -0x1b0(%rbp),%eax
    912f:	83 f8 03             	cmp    $0x3,%eax
    9132:	74 4a                	je     917e <main+0xae>
    9134:	83 f8 03             	cmp    $0x3,%eax
    9137:	77 5e                	ja     9197 <main+0xc7>
    9139:	83 f8 02             	cmp    $0x2,%eax
    913c:	74 27                	je     9165 <main+0x95>
    913e:	83 f8 02             	cmp    $0x2,%eax
    9141:	77 54                	ja     9197 <main+0xc7>
    9143:	85 c0                	test   %eax,%eax
    9145:	74 5a                	je     91a1 <main+0xd1>
    9147:	83 f8 01             	cmp    $0x1,%eax
    914a:	75 4b                	jne    9197 <main+0xc7>
    914c:	48 8d 05 e5 17 00 00 	lea    0x17e5(%rip),%rax        # a938 <_IO_stdin_used+0x938>
    9153:	48 89 c7             	mov    %rax,%rdi
    9156:	e8 f5 7e ff ff       	call   1050 <puts@plt>
    915b:	b8 04 00 00 00       	mov    $0x4,%eax
    9160:	e9 aa 01 00 00       	jmp    930f <main+0x23f>
    9165:	48 8d 05 f4 17 00 00 	lea    0x17f4(%rip),%rax        # a960 <_IO_stdin_used+0x960>
    916c:	48 89 c7             	mov    %rax,%rdi
    916f:	e8 dc 7e ff ff       	call   1050 <puts@plt>
    9174:	b8 04 00 00 00       	mov    $0x4,%eax
    9179:	e9 91 01 00 00       	jmp    930f <main+0x23f>
    917e:	48 8d 05 03 18 00 00 	lea    0x1803(%rip),%rax        # a988 <_IO_stdin_used+0x988>
    9185:	48 89 c7             	mov    %rax,%rdi
    9188:	e8 c3 7e ff ff       	call   1050 <puts@plt>
    918d:	b8 04 00 00 00       	mov    $0x4,%eax
    9192:	e9 78 01 00 00       	jmp    930f <main+0x23f>
    9197:	b8 02 00 00 00       	mov    $0x2,%eax
    919c:	e9 6e 01 00 00       	jmp    930f <main+0x23f>
    91a1:	90                   	nop
    91a2:	48 8b 95 58 fe ff ff 	mov    -0x1a8(%rbp),%rdx
    91a9:	48 8b 85 60 fe ff ff 	mov    -0x1a0(%rbp),%rax
    91b0:	48 89 d7             	mov    %rdx,%rdi
    91b3:	48 89 c6             	mov    %rax,%rsi
    91b6:	e8 87 f6 ff ff       	call   8842 <sliceCStr>
    91bb:	48 89 85 20 fe ff ff 	mov    %rax,-0x1e0(%rbp)
    91c2:	48 83 bd 20 fe ff ff 	cmpq   $0x0,-0x1e0(%rbp)
    91c9:	00 
    91ca:	75 0a                	jne    91d6 <main+0x106>
    91cc:	b8 01 00 00 00       	mov    $0x1,%eax
    91d1:	e9 39 01 00 00       	jmp    930f <main+0x23f>
    91d6:	48 c7 85 18 fe ff ff 	movq   $0x0,-0x1e8(%rbp)
    91dd:	00 00 00 00 
    91e1:	48 8d 95 18 fe ff ff 	lea    -0x1e8(%rbp),%rdx
    91e8:	48 8b 85 20 fe ff ff 	mov    -0x1e0(%rbp),%rax
    91ef:	48 89 d6             	mov    %rdx,%rsi
    91f2:	48 89 c7             	mov    %rax,%rdi
    91f5:	e8 33 f5 ff ff       	call   872d <readFile>
    91fa:	48 89 85 30 fe ff ff 	mov    %rax,-0x1d0(%rbp)
    9201:	48 89 95 38 fe ff ff 	mov    %rdx,-0x1c8(%rbp)
    9208:	48 8b 85 30 fe ff ff 	mov    -0x1d0(%rbp),%rax
    920f:	48 85 c0             	test   %rax,%rax
    9212:	75 28                	jne    923c <main+0x16c>
    9214:	48 8b 85 20 fe ff ff 	mov    -0x1e0(%rbp),%rax
    921b:	48 8d 15 88 17 00 00 	lea    0x1788(%rip),%rdx        # a9aa <_IO_stdin_used+0x9aa>
    9222:	48 89 c6             	mov    %rax,%rsi
    9225:	48 89 d7             	mov    %rdx,%rdi
    9228:	b8 00 00 00 00       	mov    $0x0,%eax
    922d:	e8 5e 7e ff ff       	call   1090 <printf@plt>
    9232:	b8 01 00 00 00       	mov    $0x1,%eax
    9237:	e9 d3 00 00 00       	jmp    930f <main+0x23f>
    923c:	48 8d 85 40 fe ff ff 	lea    -0x1c0(%rbp),%rax
    9243:	be 00 00 40 00       	mov    $0x400000,%esi
    9248:	48 89 c7             	mov    %rax,%rdi
    924b:	e8 40 80 ff ff       	call   1290 <Arena_init>
    9250:	48 8b 85 30 fe ff ff 	mov    -0x1d0(%rbp),%rax
    9257:	48 8b 95 38 fe ff ff 	mov    -0x1c8(%rbp),%rdx
    925e:	48 8d b5 40 fe ff ff 	lea    -0x1c0(%rbp),%rsi
    9265:	48 8d bd 30 ff ff ff 	lea    -0xd0(%rbp),%rdi
    926c:	48 89 d1             	mov    %rdx,%rcx
    926f:	48 89 c2             	mov    %rax,%rdx
    9272:	e8 1a 99 ff ff       	call   2b91 <Parser_init>
    9277:	48 8d 85 30 ff ff ff 	lea    -0xd0(%rbp),%rax
    927e:	48 89 c7             	mov    %rax,%rdi
    9281:	e8 7f b5 ff ff       	call   4805 <Parser_parseFile>
    9286:	48 89 85 28 fe ff ff 	mov    %rax,-0x1d8(%rbp)
    928d:	48 83 bd 28 fe ff ff 	cmpq   $0x0,-0x1d8(%rbp)
    9294:	00 
    9295:	74 07                	je     929e <main+0x1ce>
    9297:	8b 45 e8             	mov    -0x18(%rbp),%eax
    929a:	85 c0                	test   %eax,%eax
    929c:	74 22                	je     92c0 <main+0x1f0>
    929e:	8b 45 e8             	mov    -0x18(%rbp),%eax
    92a1:	89 c2                	mov    %eax,%edx
    92a3:	48 8d 05 1e 17 00 00 	lea    0x171e(%rip),%rax        # a9c8 <_IO_stdin_used+0x9c8>
    92aa:	89 d6                	mov    %edx,%esi
    92ac:	48 89 c7             	mov    %rax,%rdi
    92af:	b8 00 00 00 00       	mov    $0x0,%eax
    92b4:	e8 d7 7d ff ff       	call   1090 <printf@plt>
    92b9:	b8 02 00 00 00       	mov    $0x2,%eax
    92be:	eb 4f                	jmp    930f <main+0x23f>
    92c0:	0f b6 95 6b fe ff ff 	movzbl -0x195(%rbp),%edx
    92c7:	0f b6 85 69 fe ff ff 	movzbl -0x197(%rbp),%eax
    92ce:	48 8d bd 70 fe ff ff 	lea    -0x190(%rbp),%rdi
    92d5:	0f b6 ca             	movzbl %dl,%ecx
    92d8:	0f b6 d0             	movzbl %al,%edx
    92db:	48 8d b5 40 fe ff ff 	lea    -0x1c0(%rbp),%rsi
    92e2:	48 8b 85 28 fe ff ff 	mov    -0x1d8(%rbp),%rax
    92e9:	49 89 f8             	mov    %rdi,%r8
    92ec:	48 89 c7             	mov    %rax,%rdi
    92ef:	e8 64 ee ff ff       	call   8158 <builderRun>
    92f4:	89 85 14 fe ff ff    	mov    %eax,-0x1ec(%rbp)
    92fa:	83 bd 14 fe ff ff 00 	cmpl   $0x0,-0x1ec(%rbp)
    9301:	75 07                	jne    930a <main+0x23a>
    9303:	b8 00 00 00 00       	mov    $0x0,%eax
    9308:	eb 05                	jmp    930f <main+0x23f>
    930a:	b8 03 00 00 00       	mov    $0x3,%eax
    930f:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
    9313:	64 48 2b 14 25 28 00 	sub    %fs:0x28,%rdx
    931a:	00 00 
    931c:	74 05                	je     9323 <main+0x253>
    931e:	e8 5d 7d ff ff       	call   1080 <__stack_chk_fail@plt>
    9323:	c9                   	leave
    9324:	c3                   	ret

Disassembly of section .fini:

0000000000009328 <_fini>:
    9328:	f3 0f 1e fa          	endbr64
    932c:	48 83 ec 08          	sub    $0x8,%rsp
    9330:	48 83 c4 08          	add    $0x8,%rsp
    9334:	c3                   	ret
