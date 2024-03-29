/* *************************************************************************************** */
/*                       ORION GRAPHICS LIBRARY AND RENDERING ENGINE                       */
/* *************************************************************************************** */
/* Copyright (c) 2022 Jack Bennett                                                         */
/* --------------------------------------------------------------------------------------- */
/* THE  SOFTWARE IS  PROVIDED "AS IS",  WITHOUT WARRANTY OF ANY KIND, EXPRESS  OR IMPLIED, */
/* INCLUDING  BUT  NOT  LIMITED  TO  THE  WARRANTIES  OF  MERCHANTABILITY,  FITNESS FOR  A */
/* PARTICULAR PURPOSE AND  NONINFRINGEMENT. IN  NO EVENT SHALL  THE  AUTHORS  OR COPYRIGHT */
/* HOLDERS  BE  LIABLE  FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF */
/* CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR */
/* THE USE OR OTHER DEALINGS IN THE SOFTWARE.                                              */
/* *************************************************************************************** */


// ============================================================================ //
// *****                     Doxygen file information                     ***** //
// ============================================================================ //

/**
 * @file orion_funcs.h
 * @author jack bennett
 * @brief Internal header file declaring internal functions and callbacks.
 *
 * @copyright Copyright (c) 2022 jack bennett
 *
 * This is an internal header.
 * It is NOT to be included by the user, and is certainly not included as
 * part of the interface orion.h header.
 *
 * This file declares all internal functions - not specifically 'helper' functions,
 * as those are declared in orion_helpers.h.
 *
 * Callbacks are also declared here, and are all defined in lib/callback.c.
 *
 */

#pragma once
#ifndef __ORION_FUNCS_H
#define __ORION_FUNCS_H

#ifdef __cplusplus
    extern "C" {
#endif // __cplusplus

#include "orion.h"
#include "orion_errors.h"
#include "orion_structs.h"


// ============================================================================ //
// *****                     Private/internal systems                     ***** //
// ============================================================================ //


// ----[Private/internal systems]---------------------------------------------- //
//                              Default callbacks                               //

// Default debug callback (signature of oriDebugCallbackfun pfn)
//
void _oriDefaultDebugCallback(
    const char *name,
    const unsigned int code,
    const char *message,
    const oriSeverityBit_t severity,
    void *pointer
);


// ----[Private/internal systems]---------------------------------------------- //
//                        Error-throwing helper functions                       //

// Send a debug log to console (severity of ORION_DEBUG_SEVERITY_VERBOSE_BIT)
//
void _oriLog(
    const char *format,
    ...
);

// Send a notification to console (severity of ORION_DEBUG_SEVERITY_NOTIF_BIT)
// Same format as log messages, but treated with higher severity.
//
void _oriNotification(
    const char *format,
    ...
);

// Send a warning to console (severity of ORION_DEBUG_SEVERITY_WARNING_BIT)
// Same format as notifications, but treated with higher severity.
//
void _oriWarning(
    const char *format,
    ...
);

// Send an error to console (severity of ORION_DEBUG_SEVERITY_ERROR_BIT)
// 'extra' can be used to provide extra information to be concatenated onto the error description. NULL if n/a.
//
void _oriError(
    const _oriErrorCode_t id,
    const char *extra
);

// Send an fatal error to console (severity of ORION_DEBUG_SEVERITY_FATAL_BIT)
// Same format as errors, but treated with higher severity.
// Will terminate the program after throwing!
//
void _oriFatalError(
    const _oriErrorCode_t id,
    const char *extra
);

#ifdef __cplusplus
    }
#endif // __cplusplus

#endif // __ORION_FUNCS_H
