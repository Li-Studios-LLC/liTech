#include "Allocator.h"

liAllocator::liAllocator() {
    _ResetStats();
}

void liAllocator::_ResetStats() {
    memset(&stats, 0, sizeof(allocatorStats_t));
}