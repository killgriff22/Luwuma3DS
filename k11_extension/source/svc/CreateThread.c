/*
*   This file is part of Luma3DS
*   Copyright (C) 2016-2023 Aurora Wright, TuxSH
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*   Additional Terms 7.b and 7.c of GPLv3 apply to this file:
*       * Requiring preservation of specified reasonable legal notices or
*         author attributions in that material or in the Appropriate Legal
*         Notices displayed by works containing it.
*       * Prohibiting misrepresentation of the origin of that material,
*         or requiring that modified versions of such material be marked in
*         reasonable ways as different from the original version.
*/

#include "svc/CreateThread.h"

Result CreateThreadHook(Handle *outThreadHandle, u32 ep, u32 arg, u32 stackTop, s32 priority, s32 processorId)
{
    u32 flags = flagsOfProcess(currentCoreContext->objectContext.currentProcess);
    if (isN3DS && CONFIG(REDIRECTAPPTHREADS) && !disableThreadRedirection && processorId == 1 && (flags & 0xF00) == 0x100)
        processorId = 2;

    return CreateThread(outThreadHandle, ep, arg, stackTop, priority, processorId);
}

