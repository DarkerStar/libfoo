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

#include <sstream>
#include <stdexcept>

#include <libfoo/version.hxx>
#include <libfoo/foo.hxx>

#undef NDEBUG
#include <cassert>

int main ()
{
  using namespace std;
  using namespace foo;

  // Basics.
  //
  {
    ostringstream o;
    say_hello (o, "World");
    assert (o.str () == "Hello, World!\n");
  }

  // Empty name.
  //
  try
  {
    ostringstream o;
    say_hello (o, "");
    assert (false);
  }
  catch (const invalid_argument& e)
  {
    assert (e.what () == string ("empty name"));
  }
}
