// $Id$
//
// (C) Copyright Mateusz Loskot 2008, mateusz@loskot.net
// Distributed under the BSD License
// (See accompanying file LICENSE.txt or copy at
// http://www.opensource.org/licenses/bsd-license.php)
//
#ifndef LIBLAS_DETAIL_READER10_HPP_INCLUDED
#define LIBLAS_DETAIL_READER10_HPP_INCLUDED

#include <liblas/detail/reader.hpp>
#include <liblas/detail/fwd.hpp>
// std
#include <iosfwd>

namespace liblas { namespace detail { namespace v10 {

class ReaderImpl : public Reader
{
public:

    typedef Reader Base;
    
    ReaderImpl(std::istream& ifs);
    std::size_t GetVersion() const;
    bool ReadHeader(LASHeader& header);
    bool ReadGeoreference(LASHeader const& header); // TODO: Under construction
    bool ReadNextPoint(PointRecord& record);
    bool ReadNextPoint(PointRecord& record, double& time);
    bool ReadPointAt(std::size_t n, PointRecord& record);
    bool ReadPointAt(std::size_t n, PointRecord& record, double& time);

    std::istream& GetStream();
private:

    std::istream& m_ifs;
};

}}} // namespace liblas::detail::v10

#endif // LIBLAS_DETAIL_READER10_HPP_INCLUDED
