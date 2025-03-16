/*	@(#)setjmp.h  8.12 (2.11BSD) 2025/3/11 */

/*
 * this is a "struct sigcontext" by another name.  See signal.h
*/
typedef int jmp_buf[10];

int setjmp(jmp_buf env);
int _setjmp(jmp_buf env);

void longjmp(jmp_buf env, int val);
void _longjmp(jmp_buf env, int val);
