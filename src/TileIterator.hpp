#ifndef TILEITERATOR_HPP
#define TILEITERATOR_HPP

/*******************************************************************************
 * Copyright 2014 GeoData <geodata@soton.ac.uk>
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License.  You may obtain a copy
 * of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *******************************************************************************/

/**
 * @file TileIterator.hpp
 * @brief This declares and defines the `TileIterator` class
 */

#include "GridIterator.hpp"

namespace terrain {
  template <class T1, class T2> class TileIterator;
}

/**
 * @brief Forward iterate over tiles in a `GDALTiler`
 *
 * Instances of this class take a `GDALTiler` (or derived class) in the
 * constructor and are used to forward iterate over all tiles in the tiler.
 */
template <class T1, class T2>
class terrain::TileIterator :
  public GridIterator<T1>
{
public:

  /// Instantiate an iterator with a tiler
  TileIterator(const T2 &tiler) :
    GridIterator<T1>(tiler.grid(), tiler.bounds(), tiler.maxZoomLevel(), 0),
    tiler(tiler)
  {}

  TileIterator(const T2 &tiler, i_zoom startZoom, i_zoom endZoom = 0) :
    GridIterator<T1>(tiler.grid(), tiler.bounds(), startZoom, endZoom),
    tiler(tiler)
  {}

protected:

  const T2 &tiler;              ///< The tiler we are iterating over
};

#endif /* TILEITERATOR_HPP */
