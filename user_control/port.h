///////////////////////////////////////////////////////////////////////
//
// File: nhill/user_control/port.h
// Date: 5 Sep 2019 nhill
//
// Definitions for exporting/importing library elements.
// Define NHILL_USERCTRL_STATIC if the module is a static library, 
// or if you want to use the code directly.
// Define NHILL_USERCTRL_EXPORT if the module is dynamic (shared) library.
//
// NHILL_USERCTRL_PORT_CLASS      export/import a class
// NHILL_USERCTRL_PORT_CFUNCTION  export/import a "C" function
// NHILL_USERCTRL_PORT_FUNCTION   export/import a function( which is not a "C" function )
// NHILL_USERCTRL_PORT_OPTION     export/import a option instantiation
// NHILL_USERCTRL_PORT_FIELD      export/import a field 
// 
// Copyright (c) 2019 Bemühen.  All rights reserved.
//
// NONDISCLOSURE
//   This is proprietary software of Bemühen.
//   This software is considered to contain trade secret information,
//   the exclusive rights to whom belong to Bemühen.
//   Source code may NOT be disclosed to any person without prior
//   written permission of Bemühen. Object code may be
//   disclosed or transmitted upon proper licensing.
//
///////////////////////////////////////////////////////////////////////
#pragma once

#if defined(NHILL_USERCTRL_STATIC)
#   ifndef NHILL_USERCTRL_PORT_CLASS
#       define NHILL_USERCTRL_PORT_CLASS
#   endif
#   ifndef NHILL_USERCTRL_PORT_CFUNCTION
#       define NHILL_USERCTRL_PORT_CFUNCTION
#   endif
#   ifndef NHILL_USERCTRL_PORT_FUNCTION
#       define NHILL_USERCTRL_PORT_FUNCTION
#   endif
#   ifndef NHILL_USERCTRL_PORT_OPTION
#       define NHILL_USERCTRL_PORT_OPTION
#   endif
#   ifndef NHILL_USERCTRL_PORT_FIELD
#       define NHILL_USERCTRL_PORT_FIELD
#   endif
#elif defined(NHILL_USERCTRL_EXPORT)
#    ifndef NHILL_USERCTRL_PORT_CLASS
#        define NHILL_USERCTRL_PORT_CLASS __declspec(dllexport)
#    endif
#    ifndef NHILL_USERCTRL_PORT_CFUNCTION
#        define NHILL_USERCTRL_PORT_CFUNCTION extern "C" __declspec(dllexport)
#    endif
#    ifndef NHILL_USERCTRL_PORT_FUNCTION
#        define NHILL_USERCTRL_PORT_FUNCTION __declspec(dllexport)
#    endif
#    ifndef NHILL_USERCTRL_PORT_OPTION
#        define NHILL_USERCTRL_PORT_OPTION
#    endif
#    ifndef NHILL_USERCTRL_PORT_FIELD
#        define NHILL_USERCTRL_PORT_FIELD __declspec(dllexport)
#    endif
#else
#    ifndef NHILL_USERCTRL_PORT_CLASS
#        define NHILL_USERCTRL_PORT_CLASS __declspec(dllimport)
#    endif
#    ifndef NHILL_USERCTRL_PORT_CFUNCTION
#        define NHILL_USERCTRL_PORT_CFUNCTION extern "C" __declspec(dllimport)
#    endif
#    ifndef NHILL_USERCTRL_PORT_FUNCTION
#        define NHILL_USERCTRL_PORT_FUNCTION __declspec(dllimport)
#    endif
#    ifndef NHILL_USERCTRL_PORT_OPTION
#        define NHILL_USERCTRL_PORT_OPTION extern
#    endif
#    ifndef NHILL_USERCTRL_PORT_FIELD
#        define NHILL_USERCTRL_PORT_FIELD __declspec(dllimport)
#    endif
#endif
