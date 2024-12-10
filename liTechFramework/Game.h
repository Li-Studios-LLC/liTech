#ifndef LITECHFRAMEWORK_GAME_H
#define LITECHFRAMEWORK_GAME_H
#include "Typedefs.h"

class LITECH_EXPORT liGame {
public:
	liGame();
	virtual ~liGame() { }

	void Quit();

	virtual void Initialize() = 0;
	virtual void Render() = 0;
	virtual void Update() = 0;

	LITECH_INLINE bool IsRunning() const { return running; }
private:
	bool running;
};

#endif