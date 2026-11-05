/* T32 OEM 0x9d0: private_dma_cache_sync; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_dma_cache_sync(struct device *dev, void *t32_data_e3f30, size_t size, enum dma_data_direction direction);
void private_dma_cache_sync(struct device *dev, void *t32_data_e3f30, size_t size, enum dma_data_direction direction)
{
    dma_cache_sync(dev, t32_data_e3f30, size, direction);
}
