// vim: set sts=2 ts=8 sw=2 tw=99 et:
// =============================================================================
// SourcePawn
// Copyright (C) 2004-2014 AlliedModders LLC.  All rights reserved.
// =============================================================================
//
// This program is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License, version 3.0, as published by the
// Free Software Foundation.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
// details.
//
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see <http://www.gnu.org/licenses/>.
//
// As a special exception, AlliedModders LLC gives you permission to link the
// code of this program (as well as its derivative works) to "Half-Life 2," the
// "Source Engine," the "SourcePawn JIT," and any Game MODs that run on software
// by the Valve Corporation.  You must obey the GNU General Public License in
// all respects for all other code used.  Additionally, AlliedModders LLC grants
// this exception to all derivative works.  AlliedModders LLC defines further
// exceptions, found in LICENSE.txt (as of this writing, version JULY-31-2007),
// or <http://www.sourcemod.net/license.php>.

#ifndef _INCLUDE_SPFILE_HEADERS_v1_opcodes_H
#define _INCLUDE_SPFILE_HEADERS_v1_opcodes_H

#include <stddef.h>
#include <stdint.h>

namespace sp {

// Opcodes labelled "UNGEN" cannot be generated by the compiler. Quite a few,
// if they could, make little sense in the context of a JIT and could not
// work anyway. Opcodes technically present in sc4.c/sc7.c (respectively,
// the code emitter and peephole optimizer) are not necessarily ever generated.
// For example, lref.pri and lref.alt would be used if a reference could be
// stored in the global scope; but they can't, so they are unreachable.
//
// Most opcodes have been manually verified. A few have not, as they are only
// produced by the peephole optimizer, or not produced at all, or eliminated
// during optimization. We generate them anyway, just in case, but they have
// not been tested.
//    lref.s.alt (phopt only)
//    stor.alt (never)
//    stor.s.alt (never)
//    sref.s.alt (never)
//    lidx.b (phopt only, probably impossible)
//    idxaddr.b (phopt only, looks difficult)
//    move.pri (eliminated in phopt)
//    shl.c.pri (eliminated in phopt)
//    shl.c.alt (eliminated in phopt)
//    shr.c.pri (eliminated in phopt)
//    shr.c.alt (eliminated in phopt)
//    eq.c.alt (never)
//    inc.alt (never)
//    dec.alt (never)
//    sdiv (never)
//    nop (never in function bodies)
//
// Additionally, some opcodes which were supported in the earlier JIT are no
// longer supported because of the above:
//    lref.pri/alt
//    sref.pri/alt
//    sign.pri/alt
//
// _G - generated, _U - ungenerated
#define OPCODE_LIST(_G, _U)                                                 \
    _G(NONE, "none", 1)                                                     \
    _G(LOAD_PRI, "load.pri", 2)                                             \
    _G(LOAD_ALT, "load.alt", 2)                                             \
    _G(LOAD_S_PRI, "load.s.pri", 2)                                         \
    _G(LOAD_S_ALT, "load.s.alt", 2)                                         \
    _U(LREF_PRI, "lref.pri")                                                \
    _U(LREF_ALT, "lref.alt")                                                \
    _G(LREF_S_PRI, "lref.s.pri", 2)                                         \
    _G(LREF_S_ALT, "lref.s.alt", 2)                                         \
    _G(LOAD_I, "load.i", 1)                                                 \
    _G(LODB_I, "lodb.i", 2)                                                 \
    _G(CONST_PRI, "const.pri", 2)                                           \
    _G(CONST_ALT, "const.alt", 2)                                           \
    _G(ADDR_PRI, "addr.pri", 2)                                             \
    _G(ADDR_ALT, "addr.alt", 2)                                             \
    _G(STOR_PRI, "stor.pri", 2)                                             \
    _G(STOR_ALT, "stor.alt", 2)                                             \
    _G(STOR_S_PRI, "stor.s.pri", 2)                                         \
    _G(STOR_S_ALT, "stor.s.alt", 2)                                         \
    _U(SREF_PRI, "sref.pri")                                                \
    _U(SREF_ALT, "sref.alt")                                                \
    _G(SREF_S_PRI, "sref.s.pri", 2)                                         \
    _G(SREF_S_ALT, "sref.s.alt", 2)                                         \
    _G(STOR_I, "stor.i", 1)                                                 \
    _G(STRB_I, "strb.i", 2)                                                 \
    _G(LIDX, "lidx", 1)                                                     \
    _U(LIDX_B, "lidx.b")                                                    \
    _G(IDXADDR, "idxaddr", 1)                                               \
    _U(IDXADDR_B, "idxaddr.b")                                              \
    _U(ALIGN_PRI, "align.pri")                                              \
    _U(ALIGN_ALT, "align.alt")                                              \
    _U(LCTRL, "lctrl")                                                      \
    _U(SCTRL, "sctrl")                                                      \
    _G(MOVE_PRI, "move.pri", 1)                                             \
    _G(MOVE_ALT, "move.alt", 1)                                             \
    _G(XCHG, "xchg", 1)                                                     \
    _G(PUSH_PRI, "push.pri", 1)                                             \
    _G(PUSH_ALT, "push.alt", 1)                                             \
    _U(PUSH_R, "push.r")                                                    \
    _G(PUSH_C, "push.c", 2)                                                 \
    _G(PUSH, "push", 2)                                                     \
    _G(PUSH_S, "push.s", 2)                                                 \
    _G(POP_PRI, "pop.pri", 1)                                               \
    _G(POP_ALT, "pop.alt", 1)                                               \
    _G(STACK, "stack", 2)                                                   \
    _G(HEAP, "heap", 2)                                                     \
    _G(PROC, "proc", 1)                                                     \
    _U(RET, "ret")                                                          \
    _G(RETN, "retn", 1)                                                     \
    _G(CALL, "call", 2)                                                     \
    _U(CALL_PRI, "call.pri")                                                \
    _G(JUMP, "jump", 2)                                                     \
    _U(JREL, "jrel")                                                        \
    _G(JZER, "jzer", 2)                                                     \
    _G(JNZ, "jnz", 2)                                                       \
    _G(JEQ, "jeq", 2)                                                       \
    _G(JNEQ, "jneq", 2)                                                     \
    _U(JLESS, "jless")                                                      \
    _U(JLEQ, "jleq")                                                        \
    _U(JGRTR, "jgrtr")                                                      \
    _U(JGEQ, "jgeq")                                                        \
    _G(JSLESS, "jsless", 2)                                                 \
    _G(JSLEQ, "jsleq", 2)                                                   \
    _G(JSGRTR, "jsgrtr", 2)                                                 \
    _G(JSGEQ, "jsgeq", 2)                                                   \
    _G(SHL, "shl", 1)                                                       \
    _G(SHR, "shr", 1)                                                       \
    _G(SSHR, "sshr", 1)                                                     \
    _G(SHL_C_PRI, "shl.c.pri", 2)                                           \
    _G(SHL_C_ALT, "shl.c.alt", 2)                                           \
    _U(SHR_C_PRI, "shr.c.pri")                                              \
    _U(SHR_C_ALT, "shr.c.alt")                                              \
    _G(SMUL, "smul", 1)                                                     \
    _G(SDIV, "sdiv", 1)                                                     \
    _G(SDIV_ALT, "sdiv.alt", 1)                                             \
    _U(UMUL, "umul")                                                        \
    _U(UDIV, "udiv")                                                        \
    _U(UDIV_ALT, "udiv.alt")                                                \
    _G(ADD, "add", 1)                                                       \
    _G(SUB, "sub", 1)                                                       \
    _G(SUB_ALT, "sub.alt", 1)                                               \
    _G(AND, "and", 1)                                                       \
    _G(OR, "or", 1)                                                         \
    _G(XOR, "xor", 1)                                                       \
    _G(NOT, "not", 1)                                                       \
    _G(NEG, "neg", 1)                                                       \
    _G(INVERT, "invert", 1)                                                 \
    _G(ADD_C, "add.c", 2)                                                   \
    _G(SMUL_C, "smul.c", 2)                                                 \
    _G(ZERO_PRI, "zero.pri", 1)                                             \
    _G(ZERO_ALT, "zero.alt", 1)                                             \
    _G(ZERO, "zero", 2)                                                     \
    _G(ZERO_S, "zero.s", 2)                                                 \
    _U(SIGN_PRI, "sign.pri")                                                \
    _U(SIGN_ALT, "sign.alt")                                                \
    _G(EQ, "eq", 1)                                                         \
    _G(NEQ, "neq", 1)                                                       \
    _U(LESS, "less")                                                        \
    _U(LEQ, "leq")                                                          \
    _U(GRTR, "grtr")                                                        \
    _U(GEQ, "geq")                                                          \
    _G(SLESS, "sless", 1)                                                   \
    _G(SLEQ, "sleq", 1)                                                     \
    _G(SGRTR, "sgrtr", 1)                                                   \
    _G(SGEQ, "sgeq", 1)                                                     \
    _G(EQ_C_PRI, "eq.c.pri", 2)                                             \
    _G(EQ_C_ALT, "eq.c.alt", 2)                                             \
    _G(INC_PRI, "inc.pri", 1)                                               \
    _G(INC_ALT, "inc.alt", 1)                                               \
    _G(INC, "inc", 2)                                                       \
    _G(INC_S, "inc.s", 2)                                                   \
    _G(INC_I, "inc.i", 1)                                                   \
    _G(DEC_PRI, "dec.pri", 1)                                               \
    _G(DEC_ALT, "dec.alt", 1)                                               \
    _G(DEC, "dec", 2)                                                       \
    _G(DEC_S, "dec.s", 2)                                                   \
    _G(DEC_I, "dec.i", 1)                                                   \
    _G(MOVS, "movs", 2)                                                     \
    _U(CMPS, "cmps")                                                        \
    _G(FILL, "fill", 2)                                                     \
    _G(HALT, "halt", 2)                                                     \
    _G(BOUNDS, "bounds", 2)                                                 \
    _U(SYSREQ_PRI, "sysreq.pri")                                            \
    _G(SYSREQ_C, "sysreq.c", 2)                                             \
    _U(FILE, "file")                                                        \
    _U(LINE, "line")                                                        \
    _U(SYMBOL, "symbol")                                                    \
    _U(SRANGE, "srange")                                                    \
    _U(JUMP_PRI, "jump.pri")                                                \
    _G(SWITCH, "switch", 2)                                                 \
    _G(CASETBL, "casetbl", -1)                                              \
    _G(SWAP_PRI, "swap.pri", 1)                                             \
    _G(SWAP_ALT, "swap.alt", 1)                                             \
    _G(PUSH_ADR, "push.adr", 2)                                             \
    _G(NOP, "nop", 1)                                                       \
    _G(SYSREQ_N, "sysreq.n", 3)                                             \
    _U(SYMTAG, "symtag")                                                    \
    _G(BREAK, "break", 1)                                                   \
    _G(PUSH2_C, "push2.c", 3)                                               \
    _G(PUSH2, "push2", 3)                                                   \
    _G(PUSH2_S, "push2.s", 3)                                               \
    _G(PUSH2_ADR, "push2.adr", 3)                                           \
    _G(PUSH3_C, "push3.c", 4)                                               \
    _G(PUSH3, "push3", 4)                                                   \
    _G(PUSH3_S, "push3.s", 4)                                               \
    _G(PUSH3_ADR, "push3.adr", 4)                                           \
    _G(PUSH4_C, "push4.c", 5)                                               \
    _G(PUSH4, "push4", 5)                                                   \
    _G(PUSH4_S, "push4.s", 5)                                               \
    _G(PUSH4_ADR, "push4.adr", 5)                                           \
    _G(PUSH5_C, "push5.c", 6)                                               \
    _G(PUSH5, "push5", 6)                                                   \
    _G(PUSH5_S, "push5.s", 6)                                               \
    _G(PUSH5_ADR, "push5.adr", 6)                                           \
    _G(LOAD_BOTH, "load.both", 3)                                           \
    _G(LOAD_S_BOTH, "load.s.both", 3)                                       \
    _G(CONST, "const", 3)                                                   \
    _G(CONST_S, "const.s", 3)                                               \
    _U(SYSREQ_D, "sysreq.d")                                                \
    _U(SYSREQ_ND, "sysreq.nd")                                              \
    _G(TRACKER_PUSH_C, "trk.push.c", 2)                                     \
    _G(TRACKER_POP_SETHEAP, "trk.pop", 1)                                   \
    _G(GENARRAY, "genarray", 2)                                             \
    _G(GENARRAY_Z, "genarray.z", 2)                                         \
    _G(STRADJUST_PRI, "stradjust.pri", 1)                                   \
    _U(STKADJUST, "stackadjust")                                            \
    _G(ENDPROC, "endproc", 1)                                               \
    _U(LDGFN_PRI, "ldgfn.pri")                                              \
    _U(REBASE, "rebase")                                                    \
    _G(INITARRAY_PRI, "initarray.pri", 6)                                   \
    _G(INITARRAY_ALT, "initarray.alt", 6)                                   \
    _G(HEAP_SAVE, "heap.save", 1)                                           \
    _G(HEAP_RESTORE, "heap.restore", 1)                                     \
    /* Opcodes below this are pseudo-opcodes and are not part of the ABI */ \
    _U(FIRST_FAKE, "firstfake")                                             \
    _G(FABS, "fabs", 1)                                                     \
    _G(FLOAT, "float", 1)                                                   \
    _G(DOUBLE_TO_FLOAT, "floatdb", 1)                                       \
    _G(FLOATADD, "float.add", 1)                                            \
    _G(FLOATSUB, "float.sub", 1)                                            \
    _G(FLOATMUL, "float.mul", 1)                                            \
    _G(FLOATDIV, "float.div", 1)                                            \
    _G(RND_TO_NEAREST, "round", 1)                                          \
    _G(RND_TO_FLOOR, "floor", 1)                                            \
    _G(RND_TO_CEIL, "ceil", 1)                                              \
    _G(RND_TO_ZERO, "rndtozero", 1)                                         \
    _G(FLOATCMP, "float.cmp", 1)                                            \
    _G(FLOAT_GT, "float.gt", 1)                                             \
    _G(FLOAT_GE, "float.ge", 1)                                             \
    _G(FLOAT_LT, "float.lt", 1)                                             \
    _G(FLOAT_LE, "float.le", 1)                                             \
    _G(FLOAT_NE, "float.ne", 1)                                             \
    _G(FLOAT_EQ, "float.eq", 1)                                             \
    _G(FLOAT_NOT, "float.not", 1)                                           \
    _G(DBABS, "dbabs", 1)                                                   \
    _G(DOUBLE, "double", 1)                                                 \
    _G(FLOAT_TO_DOUBLE, "doublef", 1)                                       \
    _G(DOUBLEADD, "double.add", 1)                                          \
    _G(DOUBLESUB, "double.sub", 1)                                          \
    _G(DOUBLEMUL, "double.mul", 1)                                          \
    _G(DOUBLEDIV, "double.div", 1)                                          \
    _G(RND_TO_NEAREST_DOUBLE, "double.round", 1)                            \
    _G(RND_TO_FLOOR_DOUBLE, "double.floor", 1)                              \
    _G(RND_TO_CEIL_DOUBLE, "double.ceil", 1)                                \
    _G(RND_TO_ZERO_DOUBLE, "double.rndtozero", 1)                           \
    _G(DOUBLECMP, "double.cmp", 1)                                          \
    _G(DOUBLE_GT, "double.gt", 1)                                           \
    _G(DOUBLE_GE, "double.ge", 1)                                           \
    _G(DOUBLE_LT, "double.lt", 1)                                           \
    _G(DOUBLE_LE, "double.le", 1)                                           \
    _G(DOUBLE_NE, "double.ne", 1)                                           \
    _G(DOUBLE_EQ, "double.eq", 1)                                           \
    _G(DOUBLE_NOT, "double.not", 1)

enum OPCODE {
#define _G(op, text, cells) OP_##op,
#define _U(op, text) OP_UNGEN_##op,
    OPCODE_LIST(_G, _U)
#undef _G
#undef _U
        OPCODES_LAST
};

#define OPCODES_TOTAL (ucell_t) OPCODES_LAST

} // namespace sp

#endif // _INCLUDE_SPFILE_HEADERS_v1_opcodes_H
