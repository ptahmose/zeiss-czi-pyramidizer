#pragma once

#include <libCZI.h>
#include <memory>

namespace libpyramidizer
{
    /// In this interface image-processing operations" related to the pyramid-generation are gathered.
    class IDecimationProcessing
    {
    public:
        virtual std::shared_ptr<libCZI::IBitmapData> Decimate(const std::shared_ptr<libCZI::IBitmapData>& bitmap) = 0;

        virtual ~IDecimationProcessing() = default;
    };

    // TODO(JBL): just a temporary solution...
    IDecimationProcessing* GetDecimationProcessing();
} // namespace libpyramidizer
