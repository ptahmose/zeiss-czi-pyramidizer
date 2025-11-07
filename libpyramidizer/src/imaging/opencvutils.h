#pragma once

#include <libCZI.h>

namespace libpyramidizer
{
    class OpenCVUtils
    {
    public:
        static int libCZIPixelTypeToOpenCv(libCZI::PixelType pixelType);

        static void OneTimeInitializationOpenCv();
    };
} // namespace libpyramidizer
