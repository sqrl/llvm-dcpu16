//==-- DCPU16.h - Top-level interface for DCPU16 representation --*- C++ -*-==//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the entry points for global functions defined in
// the LLVM DCPU16 backend.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_TARGET_DCPU16_H
#define LLVM_TARGET_DCPU16_H

#include "MCTargetDesc/DCPU16MCTargetDesc.h"
#include "llvm/Target/TargetMachine.h"

namespace DCPU16CC {
  // DCPU16 specific condition code.
  enum CondCodes {
    COND_E  = 0,  // aka COND_Z
    COND_NE = 1,  // aka COND_NZ
    COND_HS = 2,  // aka COND_C
    COND_LO = 3,  // aka COND_NC
    COND_GE = 4,
    COND_L  = 5,

    COND_INVALID = -1
  };
}

namespace llvm {
  class DCPU16TargetMachine;
  class FunctionPass;
  class formatted_raw_ostream;

  FunctionPass *createDCPU16ISelDag(DCPU16TargetMachine &TM,
                                    CodeGenOpt::Level OptLevel);

  FunctionPass *createDCPU16BranchSelectionPass();

} // end namespace llvm;

#endif
