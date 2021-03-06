/***************************************************************************
 *
 * $Id: cmdparse.h 203 2015-01-24 18:27:48Z Michael.McTernan $
 *
 * This file is part of mscgen, a message sequence chart renderer.
 * Copyright (C) 2005 Michael C McTernan, Michael.McTernan.2001@cs.bris.ac.uk
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 **************************************************************************/

#ifndef CMDPARSE_HEADER
#define CMDPARSE_HEADER

/***************************************************************************
 * Include Files
 **************************************************************************/

#include <stdbool.h>

/***************************************************************************
 * Type Definitions
 **************************************************************************/

/** Command switch description
 * This structure defines a single switch that maybe present on the command
 * line, as well as how the switch should be handled.
 */
typedef struct CmdSwitchTag
{
    char  *switchString;  /**< String that identifies the switch */
    bool  *presentFlag;   /**< If the switch is found, this is set \a true */
    char  *parseString;   /**< If non-NULL, used to parse switch option */
    void  *parseResult;   /**< Destination of parse result */
}
CmdSwitch;

/***************************************************************************
 * Global Functions
 **************************************************************************/

/** Parse command line options.
 * When supplied with command line options and a suitable array of
 * \a CmdSwitch instructions, this will attempt to parse the command line
 * and return \a true if no errors were found.
 * \param opts   Array of \a CmdSwitch types describing possible options
 *                and how to parse them.
 * \param nOpts  The number of elements in \a opts.
 * \param argc   The number of elements in \a argv.
 * \param argv   The array of command options.
 * \param inputSwitch  Special switch to assume incase the last input
 *                      option is unmatched.  In such a case, the
 *                      switch table for this option is used.
 * \returns \a true if all options were successfully parsed.
 */
bool CmdParse(const CmdSwitch opts[],
              const int       nOpts,
              const int       argc,
              const char      *argv[],
              const char      *inputSwitch);

#endif

/* END OF FILE */
