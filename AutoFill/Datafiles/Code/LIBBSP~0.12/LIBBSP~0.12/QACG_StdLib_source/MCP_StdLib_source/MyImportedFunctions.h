#ifndef _MYIMPORTEDFUNCTIONS_H_
#define _MYIMPORTEDFUNCTIONS_H_

/*-------------------------------------------------------------------------------------------------------------------*/
/* PROJECT : Unified Standard Library                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/
/* COMPANY : Safran                                                                                                  */
/*-------------------------------------------------------------------------------------------------------------------*/
/* CSU NAME : MyImportedFunctions                                                                                    */
/* FILENAME : MyImportedFunctions.h                                                                                  */
/*-------------------------------------------------------------------------------------------------------------------*/
/* The CSU MyImportedFunctions ensures the good integration of high level imported function                          */
/* (use in SCADE imported operator) in KCG generated code.                                                           */
/* KCG generates the file kcg_imported_functions.h amongst others.                                                   */
/* It contains a prototype of called function for each SCADE imported operator.                                      */
/* As SCADE imported operators share the same name with their external/called functions, MyImportedFunctions CSU     */
/* disables all the function prototypes of kcg_imported_functions.h files to avoid definitions conflict.             */
/*-------------------------------------------------------------------------------------------------------------------*/

#ifndef ACos
#define ACos ACos
#include "ACos.h"
#endif

#ifndef ASin
#define ASin ASin
#include "ASin.h"
#endif

#ifndef ATan
#define ATan ATan
#include "ATan.h"
#endif

#ifndef ATan2
#define ATan2 ATan2
#include "ATan2.h"
#endif

#ifndef CopySign
#define CopySign CopySign
#include "CopySign.h"
#endif

#ifndef Cos
#define Cos Cos
#include "Cos.h"
#endif

#ifndef CubeRoot
#define CubeRoot CubeRoot
#include "CubeRoot.h"
#endif

#ifndef Expo
#define Expo Expo
#include "Expo.h"
#endif

#ifndef Floor
#define Floor Floor
#include "Floor.h"
#endif

#ifndef IsInf
#define IsInf IsInf
#include "IsInf.h"
#endif

#ifndef IsNan
#define IsNan IsNan
#include "IsNan.h"
#endif

#ifndef IsSubnormal
#define IsSubnormal IsSubnormal
#include "IsSubnormal.h"
#endif

#ifndef IsZero
#define IsZero IsZero
#include "IsZero.h"
#endif

#ifndef Log2
#define Log2 Log2
#include "Log2.h"
#endif

#ifndef Memcpy
#define Memcpy Memcpy
#include "Memcpy.h"
#endif

#ifndef RestrictedPow
#define RestrictedPow RestrictedPow
#include "RestrictedPow.h"
#endif

#ifndef Sin
#define Sin Sin
#include "Sin.h"
#endif

#ifndef SinCos
#define SinCos SinCos
#include "SinCos.h"
#endif

#ifndef Sqrt
#define Sqrt Sqrt
#include "Sqrt.h"
#endif

#ifndef Tan
#define Tan Tan
#include "Tan.h"
#endif

#ifndef LibIEEE
#define LibIEEE LibIEEE
#include "LibIEEE.h"
#endif

#ifndef LibTrig
#define LibTrig LibTrig
#include "LibTrig.h"
#endif

#endif /* _MYIMPORTEDFUNCTIONS_H_ */
