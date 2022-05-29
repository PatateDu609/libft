#include "random.h"

static uint64_t state = 0;
static uint64_t multiplier = 6364136223846793005u;
static uint64_t increment = 1442695040888963407u;

void init_pcg_state()
{
	struct timeval tv;
	struct timezone tz;

	gettimeofday(&tv, &tz);
	increment += tv.tv_usec * tz.tz_minuteswest + tz.tz_dsttime;
	state = (tv.tv_sec ^ tv.tv_usec) + increment + getpid();
}

uint32_t pcg()
{
	uint64_t oldstate = state;
	uint32_t counter = (uint32_t)(oldstate >> 59);

	state = oldstate * multiplier + increment;
	oldstate ^= (oldstate >> 18);
	return ROTR32((uint32_t)(oldstate >> 27), counter);
}

uint64_t pcg_64()
{
	uint64_t result;
	uint32_t a = pcg();
	uint32_t b = pcg();
	result = ((uint64_t)a << 32) | b;
	return result;
}

uint64_t pcg64_range(uint64_t min, uint64_t max)
{
	uint64_t range = max - min;
	uint64_t result = pcg_64() % range;
	return result + min;
}
