/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        sdk/game/CTrainTrack.h
*  PURPOSE:     Train Track Interface
*  DEVELOPERS:  Cazomino05 < Cazomino05@gmail.com >
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/
#pragma once

struct STrackNode
{
    std::int16_t x, y, z; // coordinate times 8
    std::uint16_t railDistance; // on-rail distance times

    STrackNode(std::int16_t x_, std::int16_t y_, std::int16_t z_, std::uint16_t distance_) : x(x_), y(y_), z(z_), railDistance(distance_)
    {
    }

    STrackNode() {}

    inline void SetPosition(const CVector& position)
    {
        x = static_cast<std::int16_t>(position.fX * 8);
        y = static_cast<std::int16_t>(position.fY * 8);
        z = static_cast<std::int16_t>(position.fZ * 8);
    }

    inline CVector GetPosition() const
    {
        return CVector(x / 8.0f, y / 8.0f, z / 8.0f);
    }

    inline void SetDistance(float distance)
    {
        railDistance = static_cast<std::uint16_t>(distance * 3);
    }

    inline float GetDistance() const
    {
        return static_cast<float>(railDistance) / 3;
    }

private:
    // Collision information used for lighting
    std::uint8_t collisionFlags = 0;
    std::uint8_t useStoredCollision = 0;
};
static_assert(sizeof(STrackNode) == 10, "Size mismatch");


class CTrainTrack
{
public:
    virtual unsigned int GetIndex() = 0;

    virtual float GetLength() = 0;

    virtual void SetLastNodesLinked(bool linked) = 0;

    virtual STrackNode* AddNode(const CVector& position) = 0;

    virtual const std::vector<STrackNode>& GetNodes() const = 0;

    virtual bool SetNodePosition(unsigned int nodeIndex, const CVector& position) = 0;
    virtual bool GetNodePosition(unsigned int nodeIndex, CVector& position) = 0;
};
