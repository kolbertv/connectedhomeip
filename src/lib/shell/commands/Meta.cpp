/*
 *
 *    Copyright (c) 2020 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/**
 *    @file
 *      Source implementation of meta shell commands for CHIP examples.
 */

#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <CHIPVersion.h>
#include <lib/shell/Commands.h>
#include <lib/shell/Engine.h>
#include <lib/shell/commands/Help.h>
#include <support/CodeUtils.h>

namespace chip {
namespace Shell {

static int ExitHandler(int argc, char ** argv)
{
    streamer_printf(streamer_get(), "Goodbye\r\n");
    exit(0);
    return 0;
}

static int HelpHandler(int argc, char ** argv)
{
    shell_command_foreach(PrintCommandHelp, nullptr);
    return 0;
}

static int VersionHandler(int argc, char ** argv)
{
    streamer_printf(streamer_get(), "CHIP %s\r\n", CHIP_VERSION_STRING);
    return 0;
}

void RegisterMetaCommands()
{
    static shell_command_t sCmds[] = {
        { &ExitHandler, "exit", "Exit the shell application" },
        { &HelpHandler, "help", "List out all top level commands" },
        { &VersionHandler, "version", "Output the software version" },
    };

    shell_register(sCmds, ArraySize(sCmds));
}

} // namespace Shell
} // namespace chip
