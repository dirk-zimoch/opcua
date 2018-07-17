/*************************************************************************\
* Copyright (c) 2018 ITER Organization.
* This module is distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution.
\*************************************************************************/

/*
 *  Author: Ralph Lange <ralph.lange@gmx.de>
 *
 *  based on prototype work by Bernhard Kuner <bernhard.kuner@helmholtz-berlin.de>
 *  and example code from the Unified Automation C++ Based OPC UA Client SDK
 */

#ifndef DEVOPCUA_ITEMUASDK_H
#define DEVOPCUA_ITEMUASDK_H

#include <memory>

#include <uaclientsdk.h>

#include "Item.h"
#include "SessionUaSdk.h"
#include "DataElementUaSdk.h"

namespace DevOpcua {

using namespace UaClientSdk;

class SubscriptionUaSdk;
struct linkInfo;

class ItemUaSdk : public Item, public DataElementUaSdk
{
public:
    ItemUaSdk(const linkInfo &info);
    ~ItemUaSdk();

    void requestRead() { session->requestRead((*this)); }
    void requestWrite() {}

    void show(int level) const;
    bool monitored() const;
    UaNodeId &nodeId() const { return (*nodeid); }

private:
    SubscriptionUaSdk *subscription;
    SessionUaSdk *session;
    std::unique_ptr<UaNodeId> nodeid;
};

} // namespace DevOpcua

#endif // DEVOPCUA_ITEMUASDK_H
