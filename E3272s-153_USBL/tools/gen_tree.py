# -*- coding: utf-8 -*-
# Генератор читаемого дерева исходников из decompiled_all.c
import re, os, csv, collections

t = open('decompiled_all.c', encoding='utf-8', errors='replace').read()
marks = [(m.group(1), int(m.group(2), 16), m.start())
         for m in re.finditer(r'/\* ==== (.+?) @ 0x([0-9A-F]{8}) ==== \*/', t)]
funcs = []
for i, (name, addr, st) in enumerate(marks):
    end = marks[i + 1][2] if i + 1 < len(marks) else len(t)
    funcs.append({'name': name, 'addr': addr, 'code': t[st:end]})
knames = set(f['name'] for f in funcs)
KW = set('if for while switch sizeof return do else case'.split())

# approximate size by address delta
funcs.sort(key=lambda f: f['addr'])
for i, f in enumerate(funcs):
    f['size'] = (funcs[i + 1]['addr'] - f['addr']) if i + 1 < len(funcs) else 0

callers = collections.defaultdict(set)
for f in funcs:
    found = set()
    for m in re.finditer(r'\b([A-Za-z_][A-Za-z0-9_]*)\s*\(', f['code']):
        n = m.group(1)
        if n not in KW and n in knames and n != f['name']:
            found.add(n)
    f['callees'] = found
    for c in found:
        callers[c].add(f['name'])
    f['callers'] = callers[f['name']]
    f['strings'] = sorted(set(re.findall(r'"((?:\\.|[^"\\]){2,90})"', f['code'])))
    cnt = collections.Counter(int(c, 16) for c in re.findall(r'\b0x([0-9a-fA-F]{6,8})\b', f['code']))
    f['consts'] = [c for c, n in cnt.most_common(10)]
    f['globals'] = sorted(set(re.findall(r'\b(?:_?DAT_[0-9a-f]{8}|[su]_[A-Za-z0-9_]{4,})\b', f['code'])))[:12]

RULES = [
    ('boot',  r'^(sysInit|usrInit|usrRoot|kernelInit|usrKernelInit|sysHwInit|sysClk|sysAuxClk|sysTimestamp|sysModel|sysBspRev|sysNvRam|intVBRSet|archPwrDown|romStart|sysStart)$'),
    ('bsp',   r'^(BSP_|HKADC|hkadc|WDT_|wdt|PWRCTRL|ABB_|PMU_|pmu|HI6451|SSI_|spi_|SPI_|LED_|led|timer_|TIMER_|softTimer|softtimer|uart|UART|serial)'),
    ('usb',   r'^(jos|jslave|jusb|j_|cdc|acm|uwd|dcd|USB|usb|USBD|usbl)'),
    ('dload', r'^(at[A-Z]|AT_|Dload|DLOAD|dload|TFUP|tfup|Upg|upgrade|burn|Burn)'),
    ('flash', r'^(nandc|nand|Nand|ptable|yaffs|Yaffs|NVM|nvim|Lnv|Lnvm|nvm|flash|Flash|NAND)'),
    ('shell', r'^(shell|Shell|cmd[A-Z]|shellInterp)'),
    ('kernel', r'^(task|Task|sem|Sem|msgQ|kernel|int[A-Z]|exc|Exc|memPart|mem|rng|sll|avl|q[A-Z]|vx|env|sym|Sym|module|cplus|fio|io[A-Z]|ios|ty[A-Z]|pipe|select|watchdog|clock|Clock|qPri|qFifo|mq|evt|err|errno|hook|Wdb|wdb|dbg|edr|spr|usr|pool|Pool|cache|Cache|mmu|MMU)'),
    ('lib',   r'^(crypto|aes|AES|sha|SHA|md5|MD5|des|DES|rsa|RSA|crc|CRC|adler|inflate|deflate|zlib|QC_|__|_ffi|_ffix|strcmp|memcmp|memcpy|memset|memmove|malloc|calloc|realloc|free|printf|sprintf|snprintf|fprintf|vprintf|puts|putchar|gets|fgets|fputs|fread|fwrite|fopen|fclose|atoi|atol|strtol|strtoul|strtod|qsort|bsearch|rand|srand|abs|labs|div|ldiv|asctime|ctime|gmtime|localtime|mktime|strftime|tzset|ceil|floor|fabs|fmod|modf|exp|log|pow|sqrt|sin|cos|tan|atan|asin|acos|sinh|cosh|tanh|bcopy|bfill|bzero|strcpy|strlen|strcat|strncmp|strstr|strchr|strrchr|strpbrk|strspn|strcspn|strtok|strerror|tolower|toupper|isalpha|isdigit|isspace|isupper|islower|isdigit|isxdigit|isalnum|ispunct|iscntrl|isprint|isgraph|atof)'),
]
def module_of(name):
    for mid, rx in RULES:
        if re.match(rx, name):
            return mid
    return 'data'
prev = 'data'
for f in funcs:
    if f['name'].startswith(('FUN_', 'thunk', '_FUN_')):
        f['module'] = prev
    else:
        f['module'] = module_of(f['name'])
        prev = f['module']
name2mod = {f['name']: f['module'] for f in funcs}

MODDESC = {
    'boot':   'стартовая цепочка VxWorks (sysInit -> usrRoot), инициализация CPU/кэшей',
    'kernel': 'ядро VxWorks 6.8: задачи, семафоры, очереди, прерывания, память, планировщик',
    'shell':  'командный интерпретатор VxWorks shell (C-интерпретатор, таблицы команд)',
    'bsp':    'BSP Huawei: GPIO, HKADC, PMU HI6451, WDT, LED, SPI/SSI, таймеры, питание',
    'usb':    'USB device-стек: jos/jslave, DWC dcd_syn_hs, CDC/ACM, uwd, порты',
    'dload':  'протоколы заливки: AT-команды загрузчика, DLOAD, TFUP, обновление',
    'flash':  'флеш-подсистема: NAND-контроллер, ptable, YAFFS/YAFFS2, NV-память (NVM/nvim)',
    'lib':    'libc/математика/криптография/компрессия (AES, zlib-подобный QC_*)',
    'data':   'прочее: обработчики данных, product-таблицы, служебные функции',
}

os.makedirs('usbl_src/src', exist_ok=True)
os.makedirs('usbl_src/index', exist_ok=True)
os.makedirs('usbl_src/docs', exist_ok=True)

CHUNK = 150
func2file = {}
for mid in sorted(set(f['module'] for f in funcs)):
    fl = [f for f in funcs if f['module'] == mid]
    fl.sort(key=lambda f: f['addr'])
    for p in range(0, len(fl), CHUNK):
        chunk = fl[p:p + CHUNK]
        base = mid.split('_', 1)[-1]
        rel = f"src/{mid}/{base}_{p // CHUNK + 1:02d}.c"
        os.makedirs(os.path.join('usbl_src', 'src', mid), exist_ok=True)
        func2file.update((f['name'], rel) for f in chunk)
        with open(os.path.join('usbl_src', rel), 'w', encoding='utf-8') as w:
            w.write("/* ============================================================\n")
            w.write(" * Huawei Balong V7R1 USBL (usblsafe-327x.bin) — реконструкция\n")
            w.write(f" * Модуль : {mid} — {MODDESC.get(mid, '')}\n")
            w.write(f" * Часть  : {p // CHUNK + 1} (функций: {len(chunk)}, адреса 0x{chunk[0]['addr']:08X}..0x{chunk[-1]['addr']:08X})\n")
            w.write(" * Источник: Ghidra-декомпиляция (см. usbl_src/README.md)\n")
            w.write(" * ============================================================ */\n\n")
            for f in chunk:
                body = f['code']
                body = re.sub(r'^/\* ==== .*? ==== \*/\s*', '', body, count=1)
                w.write("/* ----------------------------------------------------------------\n")
                w.write(f" * {f['name']} @ 0x{f['addr']:08X}  (примерный размер ~{f['size']} байт)\n")
                w.write(f" * Модуль: {f['module']} | Вызывают: {len(f['callers'])} | Вызывает: {len(f['callees'])}\n")
                if f['callees']:
                    w.write(" * Вызывает: " + ", ".join(sorted(f['callees'])[:14]) + ("\n *           ..." if len(f['callees']) > 14 else "") + "\n")
                if f['callers']:
                    w.write(" * Вызывают: " + ", ".join(sorted(f['callers'])[:10]) + ("\n *           ..." if len(f['callers']) > 10 else "") + "\n")
                if f['strings']:
                    w.write(" * Строки: " + " | ".join('"' + s.replace('\n', '\\n')[:60] + '"' for s in f['strings'][:4]) + "\n")
                if f['consts']:
                    w.write(" * Константы: " + ", ".join(f"0x{c:08X}" for c in f['consts'][:8]) + "\n")
                if f['globals']:
                    w.write(" * Данные: " + ", ".join(f['globals'][:8]) + "\n")
                w.write(" * ---------------------------------------------------------------- */\n")
                w.write(body.rstrip() + "\n\n")

# индекс всех функций
with open('usbl_src/index/ALL_FUNCTIONS.tsv', 'w', encoding='utf-8', newline='') as w:
    w.write("va\tname\tmodule\tfile\tcallers\tcallees\tsize\n")
    for f in funcs:
        w.write(f"0x{f['addr']:08X}\t{f['name']}\t{f['module']}\t{func2file.get(f['name'],'')}\t{len(f['callers'])}\t{len(f['callees'])}\t{f['size']}\n")

# модули и межмодульные связи
edges = collections.Counter()
for f in funcs:
    for c in f['callees']:
        m2 = name2mod.get(c)
        if m2 and m2 != f['module']:
            edges[(f['module'], m2)] += 1
with open('usbl_src/index/MODULES.md', 'w', encoding='utf-8') as w:
    w.write("# Модули реконструированного дерева\n\n")
    w.write("| Модуль | Описание | Функций | Файлы |\n|---|---|---|---|\n")
    for mid in sorted(set(f['module'] for f in funcs)):
        fl = [f for f in funcs if f['module'] == mid]
        nfiles = len(set(func2file[f['name']] for f in fl))
        w.write(f"| {mid} | {MODDESC.get(mid,'')} | {len(fl)} | {nfiles} |\n")
    w.write("\n## Межмодульные вызовы (топ)\n\n| Из | В | Вызовов |\n|---|---|---|\n")
    for (m1, m2), n in edges.most_common(40):
        w.write(f"| {m1} | {m2} | {n} |\n")

# константы
cc = collections.Counter(); cex = collections.defaultdict(list)
for f in funcs:
    for c in f['consts']:
        cc[c] += 1
        if len(cex[c]) < 3: cex[c].append(f['name'])
with open('usbl_src/index/CONSTANTS.md', 'w', encoding='utf-8') as w:
    w.write("# Часто повторяющиеся 32-битные константы (кандидаты на MMIO/магию)\n\n")
    w.write("| Константа | Сколько функций | Примеры функций |\n|---|---|---|\n")
    for c, n in cc.most_common(200):
        w.write(f"| 0x{c:08X} | {n} | {', '.join(cex[c])} |\n")

# строки по модулям
sm = collections.defaultdict(collections.Counter)
for f in funcs:
    for s in f['strings']:
        sm[f['module']][s] += 1
with open('usbl_src/index/STRINGS_BY_MODULE.md', 'w', encoding='utf-8') as w:
    w.write("# Строки по модулям (декомпилятор, до 90 симв.)\n\n")
    for mid in sorted(sm):
        w.write(f"## {mid}\n\n")
        for s, n in sm[mid].most_common(80):
            w.write(f"- `{s[:90]}` (x{n})\n")
        w.write("\n")

print("functions:", len(funcs))
print("modules:", {m: len([f for f in funcs if f['module'] == m]) for m in sorted(set(f['module'] for f in funcs))})
print("src files:", sum(len(os.listdir(os.path.join('usbl_src/src', d))) for d in os.listdir('usbl_src/src')))
print("index files:", os.listdir('usbl_src/index'))
