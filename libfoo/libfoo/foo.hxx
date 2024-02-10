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

#include <iosfwd>
#include <string>

#include <libfoo/export.hxx>

namespace foo
{
  // Print a greeting for the specified name into the specified
  // stream. Throw std::invalid_argument if the name is empty.
  //
  LIBFOO_SYMEXPORT void
  say_hello (std::ostream&, const std::string& name);
}
