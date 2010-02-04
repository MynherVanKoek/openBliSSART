//
// This file is part of openBliSSART.
//
// Copyright (c) 2007-2009, Alexander Lehmann <lehmanna@in.tum.de>
//                          Felix Weninger <felix@weninger.de>
//                          Bjoern Schuller <schuller@tum.de>
//
// Institute for Human-Machine Communication
// Technische Universitaet Muenchen (TUM), D-80333 Munich, Germany
//
// openBliSSART is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free Software
// Foundation, either version 2 of the License, or (at your option) any later
// version.
//
// openBliSSART is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
// details.
//
// You should have received a copy of the GNU General Public License along with
// openBliSSART.  If not, see <http://www.gnu.org/licenses/>.
//


#ifndef __BLISSART_MATRIX_TRANSFORM_H__
#define __BLISSART_MATRIX_TRANSFORM_H__


#include <common.h>
#include <string>


namespace blissart {


// Forward declaration
class FTTask;
namespace linalg { class Matrix; }


/**
 * An interface for (in-place or out-of-place) 
 * matrix transformations, e.g. calculation of the power spectrum.
 */
class LibFramework_API MatrixTransform
{
public:
    /**
     * Returns a textual description of this MatrixTransform.
     * Must be implemented by subclasses.
     */
    virtual const char * name() = 0;

    /**
     * Does the actual transformation. If this is an in-place transform,
     * it may return its argument, otherwise a pointer to the new matrix.
     * Must be implemented by subclasses.
     */
    virtual linalg::Matrix * transform(linalg::Matrix* m) = 0;


private:
    FTTask* _task;
};


} // namespace blissart


#endif // __BLISSART_MATRIX_TRANSFORM_H__

