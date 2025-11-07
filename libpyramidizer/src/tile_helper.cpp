#include "../inc/tile_helper.h"

using namespace std;
using namespace libCZI;
using namespace libpyramidizer;

namespace
{
    IntRect Union(const IntRect& a, const IntRect& b)
    {
        if (a.IsNonEmpty() && b.IsNonEmpty())
        {
            return IntRect{ min(a.x, b.x), min(a.y, b.y), max(a.x + a.w, b.x + b.w) - min(a.x, b.x), max(a.y + a.h, b.y + b.h) - min(a.y, b.y) };
        }
        else if (a.IsNonEmpty())
        {
            return a;
        }
        else if (b.IsNonEmpty())
        {
            return b;
        }
        else
        {
            IntRect r;
            r.Invalidate();
            return r;
        }
    }
}

void TileHelper::InitializeFromFunctor(const std::function<bool(libCZI::IntRect&)>& enumeration_function)
{
    this->tiles_.clear();
    IntRect tile;
    while (enumeration_function(tile))
    {
        this->tiles_.push_back(tile);
    }
}

libCZI::IntRect TileHelper::GetMinimalRectForRoi(const libCZI::IntRect& rect) const
{
    IntRect union_rect { 0, 0, 0, 0 };
    for (const auto& tile : this->tiles_)
    {
        const auto intersection = tile.Intersect(rect);
        union_rect = Union(union_rect, intersection);
    }

    return union_rect;
}
