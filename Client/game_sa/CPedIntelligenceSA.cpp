/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        game_sa/CPedIntelligenceSA.cpp
 *  PURPOSE:     Ped entity AI logic
 *
 *  Multi Theft Auto is available from http://www.multitheftauto.com/
 *
 *****************************************************************************/

#include "StdInc.h"
#include "CPedIntelligenceSA.h"
#include "CPedSA.h"
#include "CTaskManagementSystemSA.h"
#include "CTaskManagerSA.h"

CPedIntelligenceSA::CPedIntelligenceSA(CPedIntelligenceSAInterface* pedIntelligenceSAInterface, CPed* ped)
{
    this->internalInterface = pedIntelligenceSAInterface;
    this->ped = ped;
    CTaskManagerSAInterface* pTaskManagerInterface = (CTaskManagerSAInterface*)&(pedIntelligenceSAInterface->taskManager);
    this->TaskManager = new CTaskManagerSA(pTaskManagerInterface, this->ped);
}

CPedIntelligenceSA::~CPedIntelligenceSA()
{
    delete this->TaskManager;
}

CTaskManager* CPedIntelligenceSA::GetTaskManager()
{
    return this->TaskManager;
}

bool CPedIntelligenceSA::TestForStealthKill(CPed* pPed, bool bUnk)
{
    bool  bReturn;
    DWORD dwThis = (DWORD)internalInterface;
    DWORD dwPed = (DWORD)pPed->GetInterface();
    DWORD dwFunc = FUNC_CPedIntelligence_TestForStealthKill;
    _asm
    {
        mov     ecx, dwThis
        push    bUnk
        push    dwPed
        call    dwFunc
        mov     bReturn, al
    }
    return bReturn;
}

CTaskSAInterface* CPedIntelligenceSA::SetTaskDuckSecondary(unsigned short nLengthOfDuck)
{
    auto SetTaskDuckSecondary = (CTaskSAInterface * (__thiscall*)(CPedIntelligenceSAInterface*, unsigned short))0x601230;
    return SetTaskDuckSecondary(internalInterface, nLengthOfDuck);
}
