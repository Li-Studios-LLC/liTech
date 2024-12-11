#ifndef LITECHFRAMEWORK_IMANAGER_H
#define LITECHFRAMEWORK_IMANAGER_H

struct IManager {
	virtual ~IManager() {}

	virtual void Initialize() = 0;
	virtual void Shutdown() = 0;
	virtual void Update() = 0;
};

#endif