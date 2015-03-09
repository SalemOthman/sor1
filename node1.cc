#include "node1.h"

namespace sor1
{
Define_Module (node1);
void node1::initialize()
{
    // print information about each link (in, out, who is the node at this end)
    if (getIndex() == 0)
    {
        cMessage *msg = new cMessage("fwd");
        send(msg, "gate$o",0);
    }

}
void node1::handleMessage(cMessage *msg)
{
    bool go =true;

    cGate *arrivalGate = msg->getArrivalGate();
    //cGate *depGate = msg->getSenderGate();

    //int nOfGates = gateSize("gate");
    //ev<<"nOfGates = "<<nOfGates<<'\n';

    if (getIndex()==3 && strcmp("fwd", msg->getName()) == 0)
    {
        msg->setName("bwd");
        ev<<"msg name set to bwd"<<'\n';
        send(msg, "gate$o",0);
        go=false;
    }
    else if (getIndex()==3 && strcmp("bwd", msg->getName()) == 0)
    {
        msg->setName("fwd");
        ev<<"msg name set to fwd"<<'\n';
        send(msg, "gate$o",1);
        go=false;
    }
    if (go)
    {
        if (arrivalGate->getIndex()==0)
            {
            send(msg, "gate$o",1);
            }
        else
        {
            send(msg, "gate$o",0);
        }
    }
}
}

















/*
 *     int nOfGates = gateSize("gate");
    ev<<nOfGates<<'\n';
    if (getIndex()==0)
    {
        msg->setName("fwd");
        ev<<"msg name set to fwd"<<'\n';
    }
    if (getIndex()==5)
    {
        msg->setName("bwd");
        ev<<"msg name set to bwd"<<'\n';
    }
    if (nOfGates==2)
    {
        ev<<msg->getName();
        if (strcmp("bwd", msg->getName()) == 0)
        {
            send(msg, "gate$o",0);
        }
        else
        {
            send(msg, "gate$o",1);
        }
    }
    else
        send(msg, "gate$o",0);
 */
