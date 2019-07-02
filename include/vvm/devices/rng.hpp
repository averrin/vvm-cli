#ifndef __RNG_H_
#define __RNG_H_

#include "vvm/device.hpp"

class RngDevice : public Device {
public:
    RngDevice(std::shared_ptr<MemoryContainer> m) : Device(m) {}
	void tickHandler();
};


#endif // __RNG_H_
