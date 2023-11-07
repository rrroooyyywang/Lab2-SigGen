// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsigdelay.h for the primary calling header

#include "verilated.h"

#include "Vsigdelay__Syms.h"
#include "Vsigdelay___024root.h"

void Vsigdelay___024root___eval_act(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vsigdelay___024root___nba_sequent__TOP__0(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*8:0*/ __Vdly__sigdelay__DOT__wr_addr;
    __Vdly__sigdelay__DOT__wr_addr = 0;
    SData/*8:0*/ __Vdlyvdim0__sigdelay__DOT__ram2ports__DOT__ram_array__v0;
    __Vdlyvdim0__sigdelay__DOT__ram2ports__DOT__ram_array__v0 = 0;
    CData/*7:0*/ __Vdlyvval__sigdelay__DOT__ram2ports__DOT__ram_array__v0;
    __Vdlyvval__sigdelay__DOT__ram2ports__DOT__ram_array__v0 = 0;
    CData/*0:0*/ __Vdlyvset__sigdelay__DOT__ram2ports__DOT__ram_array__v0;
    __Vdlyvset__sigdelay__DOT__ram2ports__DOT__ram_array__v0 = 0;
    // Body
    __Vdly__sigdelay__DOT__wr_addr = vlSelf->sigdelay__DOT__wr_addr;
    __Vdlyvset__sigdelay__DOT__ram2ports__DOT__ram_array__v0 = 0U;
    __Vdly__sigdelay__DOT__wr_addr = ((IData)(vlSelf->rst)
                                       ? 0U : (0x1ffU 
                                               & ((IData)(1U) 
                                                  + (IData)(vlSelf->sigdelay__DOT__wr_addr))));
    if (((IData)(vlSelf->wr) & (IData)(vlSelf->rd))) {
        __Vdlyvval__sigdelay__DOT__ram2ports__DOT__ram_array__v0 
            = vlSelf->mic_signal;
        __Vdlyvset__sigdelay__DOT__ram2ports__DOT__ram_array__v0 = 1U;
        __Vdlyvdim0__sigdelay__DOT__ram2ports__DOT__ram_array__v0 
            = (0x1ffU & ((IData)(vlSelf->sigdelay__DOT__wr_addr) 
                         + (IData)(vlSelf->offset)));
        vlSelf->delayed_signal = vlSelf->sigdelay__DOT__ram2ports__DOT__ram_array
            [vlSelf->sigdelay__DOT__wr_addr];
    }
    if (__Vdlyvset__sigdelay__DOT__ram2ports__DOT__ram_array__v0) {
        vlSelf->sigdelay__DOT__ram2ports__DOT__ram_array[__Vdlyvdim0__sigdelay__DOT__ram2ports__DOT__ram_array__v0] 
            = __Vdlyvval__sigdelay__DOT__ram2ports__DOT__ram_array__v0;
    }
    vlSelf->sigdelay__DOT__wr_addr = __Vdly__sigdelay__DOT__wr_addr;
}

void Vsigdelay___024root___eval_nba(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vsigdelay___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vsigdelay___024root___eval_triggers__act(Vsigdelay___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsigdelay___024root___dump_triggers__act(Vsigdelay___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vsigdelay___024root___dump_triggers__nba(Vsigdelay___024root* vlSelf);
#endif  // VL_DEBUG

void Vsigdelay___024root___eval(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval\n"); );
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
            Vsigdelay___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vsigdelay___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("sigdelay.sv", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
                Vsigdelay___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vsigdelay___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("sigdelay.sv", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vsigdelay___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vsigdelay___024root___eval_debug_assertions(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->offset & 0xfe00U))) {
        Verilated::overWidthError("offset");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->wr & 0xfeU))) {
        Verilated::overWidthError("wr");}
    if (VL_UNLIKELY((vlSelf->rd & 0xfeU))) {
        Verilated::overWidthError("rd");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
