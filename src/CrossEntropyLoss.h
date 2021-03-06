// Copyright Hugh Perkins 2014 hughperkins at gmail
//
// This Source Code Form is subject to the terms of the Mozilla Public License, 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include "Layer.h"
#include "LossLayer.h"
#include "ActivationFunction.h"

#define VIRTUAL virtual
#define STATIC static

class CrossEntropyLoss : public LossLayer {
public:

    float *errors;
    int allocatedSize;
    int batchSize;
//    ActivationFunction const*const activationFunction;

    // [[[cog
    // import cog_addheaders
    // cog_addheaders.add()
    // ]]]
    // generated, using cog:
    CrossEntropyLoss( Layer *previousLayer, CrossEntropyLossMaker *maker );
    VIRTUAL ~CrossEntropyLoss();
    VIRTUAL float*getErrorsForUpstream();
    VIRTUAL int getPersistSize() const;
    VIRTUAL float calcLoss( float const *expected );
    VIRTUAL void setBatchSize( int batchSize );
    VIRTUAL void calcErrors( float const*expectedResults );

    // [[[end]]]
};

