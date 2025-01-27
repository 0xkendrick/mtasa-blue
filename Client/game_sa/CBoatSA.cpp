/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        game_sa/CBoatSA.cpp
 *  PURPOSE:     Boat vehicle entity
 *
 *  Multi Theft Auto is available from http://www.multitheftauto.com/
 *
 *****************************************************************************/

#include "StdInc.h"
#include "CBoatSA.h"

CBoatSA::CBoatSA(CBoatSAInterface* boat)
{
    this->m_pInterface = boat;
}

CBoatSA::CBoatSA(eVehicleTypes dwModelID, unsigned char ucVariation, unsigned char ucVariation2) : CVehicleSA(dwModelID, ucVariation, ucVariation2)
{
    /*if(this->internalInterface)
    {
        // create the actual vehicle
        DWORD dwFunc = FUNC_CBoatContructor;
        DWORD dwThis = (DWORD)this->internalInterface;
        _asm
        {
            mov     ecx, dwThis
            push    MISSION_VEHICLE
            push    dwModelID
            call    dwFunc
        }

        this->SetEntityStatus(STATUS_ABANDONED); // so it actually shows up in the world

        pGame->GetWorld()->Add((CEntitySA *)this);
    }   */
}

CBoatHandlingEntry* CBoatSA::GetBoatHandlingData()
{
    return m_pBoatHandlingData;
}

void CBoatSA::SetBoatHandlingData(CBoatHandlingEntry* pBoatHandling)
{
    if (!pBoatHandling)
        return;
    m_pBoatHandlingData = static_cast<CBoatHandlingEntrySA*>(pBoatHandling);
    GetBoatInterface()->pBoatHandlingData = m_pBoatHandlingData->GetInterface();
}
