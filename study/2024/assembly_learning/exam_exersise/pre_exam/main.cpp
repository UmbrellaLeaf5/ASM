#define debug_q "%r15"
#define debug_l "%r15d"
#define debug_w "%r15w"
#define debug_b "%r15b"

#define debug_reg_q r15
#define debug_reg_l r15d
#define debug_reg_w r15w
#define debug_reg_b r15b

#define _debug_init_ "xorq " debug_q ", " debug_q "\n"
#define _debug_reinit_ "andq $0, " debug_q "\n"

#define _debug_q_inc_ "incq " debug_q "\n"
#define _debug_q_dec_ "decq " debug_q "\n"

#define _debug_copy_q(reg) "movq " reg ", " debug_q "\n"
#define _debug_copy_l(reg) "movl " reg ", " debug_l "\n"
#define _debug_copy_w(reg) "movw " reg ", " debug_w "\n"
#define _debug_copy_b(reg) "movb " reg ", " debug_b "\n"

extern "C" __attribute__((sysv_abi)) char FirstOf(const char* str);

asm(_debug_init_
    "\t.globl FirstOf     \n  "
    "FirstOf:             \n\t" 
    "testq %rdi, %rdi     \n\t" 
    "je .FONullptr        \n\t"
    "movzbl	(%rdi), %eax  \n\t" _debug_copy_b("(%rdi)")
    "ret                  \n\n"

    ".FONullptr:          \n\t" _debug_q_inc_
    "movb $0, %al         \n\t" _debug_reinit_
    "ret                  \n\t" 
    );

#include <iomanip>
#include <iostream>
#include <string>

static void PrintDebug(const char message[SHRT_MAX] = "") {
  unsigned long long debug_reg_q;

  asm("movq %" debug_q ", %0" : "=r"(debug_reg_q));

  std::cout << "debug_reg_q (" debug_q " " << message << ") = 0x"
            << std::setw(16) << std::setfill('0') << std::hex << debug_reg_q
            << std::endl;
}

static void CallFuncWithDebug(char* case_str) {
  std::cout << "! DEBUG ! " << std::endl
            << "case: '" << case_str << "'" << std::endl;

  // before
  PrintDebug("before");

  std::cout << "res:  '" << FirstOf(case_str) << "'" << std::endl;

  // after
  PrintDebug("after");

  std::cout << std::endl;
}

int main() {
  {
    char s[] = "abcd";
    CallFuncWithDebug(s);
  }

  {
    char s[] = "1b2b1";
    CallFuncWithDebug(s);
  }

  {
    char s[] = "Hello World!";
    CallFuncWithDebug(s);
  }

  {
    char s[] = "!!!!!_3";
    CallFuncWithDebug(s);
  }

  return 0;
}
