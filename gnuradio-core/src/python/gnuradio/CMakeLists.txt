# Copyright 2010-2011 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# GNU Radio is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# GNU Radio is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU Radio; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.

include(GrPython)

add_subdirectory(gr)
add_subdirectory(gru)
add_subdirectory(gruimpl)
add_subdirectory(blks2)
add_subdirectory(blks2impl)

GR_PYTHON_INSTALL(FILES
    __init__.py
    eng_notation.py
    eng_option.py
    gr_unittest.py
    gr_xmlrunner.py
    optfir.py
    window.py
    DESTINATION ${GR_PYTHON_DIR}/gnuradio
    COMPONENT "core_python"
)
