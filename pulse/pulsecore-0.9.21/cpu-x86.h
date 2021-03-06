#ifndef foocpux86hfoo
#define foocpux86hfoo

/***
  This file is part of PulseAudio.

  Copyright 2004-2006 Lennart Poettering
  Copyright 2009 Wim Taymans <wim.taymans@collabora.co.uk> 

  PulseAudio is free software; you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published
  by the Free Software Foundation; either version 2.1 of the License,
  or (at your option) any later version.

  PulseAudio is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with PulseAudio; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
  USA.
***/

#include <stdint.h>

typedef enum pa_cpu_x86_flag {
    PA_CPU_X86_MMX       = (1 << 0),
    PA_CPU_X86_MMXEXT    = (1 << 1),
    PA_CPU_X86_SSE       = (1 << 2),
    PA_CPU_X86_SSE2      = (1 << 3),
    PA_CPU_X86_SSE3      = (1 << 4),
    PA_CPU_X86_SSSE3     = (1 << 5),
    PA_CPU_X86_SSE4_1    = (1 << 6),
    PA_CPU_X86_SSE4_2    = (1 << 7),
    PA_CPU_X86_3DNOW     = (1 << 8),
    PA_CPU_X86_3DNOWEXT  = (1 << 9)
} pa_cpu_x86_flag_t;

void pa_cpu_init_x86 (void);


#if defined (__i386__)
typedef int32_t pa_reg_x86;
#define PA_REG_a "eax"
#define PA_REG_b "ebx"
#define PA_REG_c "ecx"
#define PA_REG_d "edx"
#define PA_REG_D "edi"
#define PA_REG_S "esi"
#elif defined (__amd64__)
typedef int64_t pa_reg_x86;
#define PA_REG_a "rax"
#define PA_REG_b "rbx"
#define PA_REG_c "rcx"
#define PA_REG_d "rdx"
#define PA_REG_D "rdi"
#define PA_REG_S "rsi"
#endif

/* some optimized functions */
void pa_volume_func_init_mmx(pa_cpu_x86_flag_t flags);
void pa_volume_func_init_sse(pa_cpu_x86_flag_t flags);

void pa_remap_func_init_mmx(pa_cpu_x86_flag_t flags);
void pa_remap_func_init_sse(pa_cpu_x86_flag_t flags);

void pa_convert_func_init_sse (pa_cpu_x86_flag_t flags);

#endif /* foocpux86hfoo */
