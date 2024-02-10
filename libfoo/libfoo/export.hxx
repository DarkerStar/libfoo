/***********************************************************************
 *                                                                     *
 * This file is part of libfoo.                                        *
 *                                                                     *
 * libfoo is free software: you can redistribute it and/or modify it   *
 * under the terms of the GNU General Public License as published by   *
 * the Free Software Foundation, either version 3 of the License, or   *
 * (at your option) any later version.                                 *
 *                                                                     *
 * libfoo is distributed in the hope that it will be useful, but       *
 * WITHOUT ANY WARRANTY; without even the implied warranty of          *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the        *
 * GNU General Public License for more details.                        *
 *                                                                     *
 * You should have received a copy of the GNU General Public License   *
 * along with libfoo.                                                  *
 * If not, see <https://www.gnu.org/licenses/>.                        *
 *                                                                     *
 **********************************************************************/

#pragma once

// Normally we don't export class templates (but do complete specializations),
// inline functions, and classes with only inline member functions. Exporting
// classes that inherit from non-exported/imported bases (e.g., std::string)
// will end up badly. The only known workarounds are to not inherit or to not
// export. Also, MinGW GCC doesn't like seeing non-exported functions being
// used before their inline definition. The workaround is to reorder code. In
// the end it's all trial and error.

#if defined(LIBFOO_STATIC)         // Using static.
#  define LIBFOO_SYMEXPORT
#elif defined(LIBFOO_STATIC_BUILD) // Building static.
#  define LIBFOO_SYMEXPORT
#elif defined(LIBFOO_SHARED)       // Using shared.
#  ifdef _WIN32
#    define LIBFOO_SYMEXPORT __declspec(dllimport)
#  else
#    define LIBFOO_SYMEXPORT
#  endif
#elif defined(LIBFOO_SHARED_BUILD) // Building shared.
#  ifdef _WIN32
#    define LIBFOO_SYMEXPORT __declspec(dllexport)
#  else
#    define LIBFOO_SYMEXPORT
#  endif
#else
// If none of the above macros are defined, then we assume we are being used
// by some third-party build system that cannot/doesn't signal the library
// type. Note that this fallback works for both static and shared libraries
// provided the library only exports functions (in other words, no global
// exported data) and for the shared case the result will be sub-optimal
// compared to having dllimport. If, however, your library does export data,
// then you will probably want to replace the fallback with the (commented
// out) error since it won't work for the shared case.
//
#  define LIBFOO_SYMEXPORT         // Using static or shared.
//#  error define LIBFOO_STATIC or LIBFOO_SHARED preprocessor macro to signal libfoo library type being linked
#endif
