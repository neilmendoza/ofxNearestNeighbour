/*
 *  NearestNeighbour.h
 *
 *  Copyright (c) 2013, Neil Mendoza, http://www.neilmendoza.com
 *  All rights reserved. 
 *  
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions are met: 
 *  
 *  * Redistributions of source code must retain the above copyright notice, 
 *    this list of conditions and the following disclaimer. 
 *  * Redistributions in binary form must reproduce the above copyright 
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the distribution. 
 *  * Neither the name of Neil Mendoza nor the names of its contributors may be used 
 *    to endorse or promote products derived from this software without 
 *    specific prior written permission. 
 *  
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 *  POSSIBILITY OF SUCH DAMAGE. 
 *
 */
#pragma once

#include "nanoflann.hpp"
#include "PointCloud.h"

namespace itg
{
    using namespace nanoflann;
    
    // T is type of nn point
    template<class T, unsigned U>
    class NearestNeighbour
    {
    public:
        typedef KDTreeSingleIndexAdaptor<
                L2_Simple_Adaptor<float, PointCloud<T>>,
                PointCloud<T>,
                U> KdTree;
        
        NearestNeighbour() : kdTree(U, cloud, KDTreeSingleIndexAdaptorParams(10 /* max leaf */))
        {
        }
        
        void buildIndex(const vector<T>& points)
        {
            cloud.points = points;
            if (points.empty()) ofLogError() << "Cannot build index with no points.";
            else kdTree.buildIndex();
        }
        
        void findNClosestPoints(const T& point, unsigned n, vector<size_t>& indices, vector<float>& distsSquared)
        {
            indices.resize(n);
            distsSquared.resize(n);
            kdTree.knnSearch(glm::value_ptr(point), n, &indices[0], &distsSquared[0]);
        }
        
        unsigned findPointsWithinRadius(const T& point, float radius, vector<pair<size_t, float> >& matches)
        {
            nanoflann::SearchParams params;
            return kdTree.radiusSearch(glm::value_ptr(point), radius * radius, matches, params);
        }
        
    private:
        KdTree kdTree;
        PointCloud<T> cloud;
    };
}
