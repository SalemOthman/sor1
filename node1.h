/*
 * node1.h
 *
 *  Created on: Mar 5, 2015
 *      Author: Owner
 */

#ifndef NODE1_H_
#define NODE1_H_

#include <omnetpp.h>

namespace sor1{

class node1: public cSimpleModule
{
protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};
}


#endif /* NODE1_H_ */
