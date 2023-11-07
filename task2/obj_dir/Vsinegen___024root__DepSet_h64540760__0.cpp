// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsinegen.h for the primary calling header

#include "verilated.h"

#include "Vsinegen__Syms.h"
#include "Vsinegen___024root.h"

void Vsinegen___024root___eval_act(Vsinegen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vsinegen___024root___nba_sequent__TOP__0(Vsinegen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ __Vdly__sinegen__DOT__addr1;
    __Vdly__sinegen__DOT__addr1 = 0;
    CData/*7:0*/ __Vdly__sinegen__DOT__addr2;
    __Vdly__sinegen__DOT__addr2 = 0;
    // Body
    __Vdly__sinegen__DOT__addr2 = vlSelf->sinegen__DOT__addr2;
    __Vdly__sinegen__DOT__addr1 = vlSelf->sinegen__DOT__addr1;
    if (vlSelf->rst) {
        __Vdly__sinegen__DOT__addr2 = 0U;
        __Vdly__sinegen__DOT__addr1 = 0U;
    } else if (vlSelf->en) {
        __Vdly__sinegen__DOT__addr2 = (0xffU & ((IData)(1U) 
                                                + (IData)(vlSelf->sinegen__DOT__addr2)));
        __Vdly__sinegen__DOT__addr1 = (0xffU & ((IData)(1U) 
                                                + (IData)(vlSelf->sinegen__DOT__addr1)));
    } else {
        __Vdly__sinegen__DOT__addr2 = (0xffU & (IData)(vlSelf->sinegen__DOT__addr2));
        __Vdly__sinegen__DOT__addr1 = (0xffU & (IData)(vlSelf->sinegen__DOT__addr1));
    }
    vlSelf->data1 = vlSelf->sinegen__DOT__rom2ports__DOT__rom_array
        [vlSelf->sinegen__DOT__addr1];
    vlSelf->data2 = vlSelf->sinegen__DOT__rom2ports__DOT__rom_array
        [(0xffU & ((IData)(vlSelf->incr) + (IData)(vlSelf->sinegen__DOT__addr2)))];
    vlSelf->sinegen__DOT__addr1 = __Vdly__sinegen__DOT__addr1;
    vlSelf->sinegen__DOT__addr2 = __Vdly__sinegen__DOT__addr2;
}

void Vsinegen___024root___eval_nba(Vsinegen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsinegen___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vsinegen___024root___eval_triggers__act(Vsinegen___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsinegen___024root___dump_triggers__act(Vsinegen___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsinegen___024root___dump_triggers__nba(Vsinegen___024root* vlSelf);
#endif  // VL_DEBUG

void Vsinegen___024root___eval(Vsinegen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen___024root___eval\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vsinegen___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vsinegen___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("sinegen.sv", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
                Vsinegen___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vsinegen___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("sinegen.sv", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vsinegen___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vsinegen___024root___eval_debug_assertions(Vsinegen___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsinegen__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsinegen___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->en & 0xfeU))) {
        Verilated::overWidthError("en");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
