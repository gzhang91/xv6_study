// Format of an ELF executable file

#define ELF_MAGIC 0x464C457FU  // "\x7FELF" in little endian

// File header
struct elfhdr {
  uint magic;                        // must equal ELF_MAGIC  ELF魔数
  uchar elf[12];                     // 
  ushort type;                       // 
  ushort machine;                    // 硬件平台
  uint version;                      // 版本
  uint entry;                        // 入口代码的地址
  uint phoff;                        // 程序头表的偏移
  uint shoff;                        // 
  uint flags;                        //
  ushort ehsize;                     // 文件头大小
  ushort phentsize;                  // 程序头表项的大小
  ushort phnum;                      // 程序头表项的个数
  ushort shentsize;
  ushort shnum;
  ushort shstrndx;
};

// Program section header            // 程序头表项
struct proghdr {
  uint type;                         // 段类型，例如LOAD表示需要装入内存
  uint off;                          // 本段在文件中的偏移
  uint vaddr;                        // 本段应该装入到内存的虚地址
  uint paddr;                        // 本段应该装入到内存的物理地址
  uint filesz;                       // 本段在文件中所占空间大小
  uint memsz;                        // 本段装入内存后所占空间(>=filesz)
  uint flags;                        // 本段的属性(读写执行等)
  uint align;                        // 本段在内存中的对齐属性
};

// Values for Proghdr type
#define ELF_PROG_LOAD           1

// Flag bits for Proghdr flags
#define ELF_PROG_FLAG_EXEC      1
#define ELF_PROG_FLAG_WRITE     2
#define ELF_PROG_FLAG_READ      4

//PAGEBREAK!
// Blank page.
